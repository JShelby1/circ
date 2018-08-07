using Foundation;
using UIKit;
using UserNotifications;
using Firebase.Core;
using Firebase.CloudMessaging;
using System;
using System.Threading.Tasks;
using Firebase.Auth;
using System.Collections.Generic;
using Firebase.Database;
using Plugin.Geolocator;


namespace Circle
{
	// The UIApplicationDelegate for the application. This class is responsible for launching the
	// User Interface of the application, as well as listening (and optionally responding) to application events from iOS.
	[Register ("AppDelegate")]
	public class AppDelegate : UIApplicationDelegate, IUNUserNotificationCenterDelegate, IMessagingDelegate
	{

        NSData DeviceToken { get; set; }
        public static DatabaseReference RootNode { get; set; }
		public event EventHandler<UserInfoEventArgs> MessageReceived;
        private List<string> readPermissions = new List<string> { "public_profile" };
        public static Manager manager { get; set; }
     


		// class-level declarations

		public override UIWindow Window {
			get;
			set;
		}

        public override bool FinishedLaunching (UIApplication application, NSDictionary launchOptions)
		{
            // Override point for customization after application launch.

            var locator = CrossGeolocator.Current;
            var position = locator.GetPositionAsync(TimeSpan.FromSeconds(10));
            // If not required for your application you can safely delete this method
            Window = new UIWindow(UIScreen.MainScreen.Bounds);
			//(Window.RootViewController as UINavigationController).PushViewController (new WelcomeViewController(), true);
			UIApplication.SharedApplication.StatusBarStyle = UIStatusBarStyle.LightContent;

       
			App.Configure ();
            Firebase.Database.Database.DefaultInstance.PersistenceEnabled = true;
            RootNode = Firebase.Database.Database.DefaultInstance.GetRootReference();
       

			// Register your app for remote notifications.
			if (UIDevice.CurrentDevice.CheckSystemVersion (10, 0)) {
				// For iOS 10 display notification (sent via APNS)
				UNUserNotificationCenter.Current.Delegate = this;

				var authOptions = UNAuthorizationOptions.Alert | UNAuthorizationOptions.Badge | UNAuthorizationOptions.Sound;
				UNUserNotificationCenter.Current.RequestAuthorization (authOptions, (granted, error) => {
					Console.WriteLine (granted);
				});
			} else {
				// iOS 9 or before
				var allNotificationTypes = UIUserNotificationType.Alert | UIUserNotificationType.Badge | UIUserNotificationType.Sound;
				var settings = UIUserNotificationSettings.GetSettingsForTypes (allNotificationTypes, null);
				UIApplication.SharedApplication.RegisterUserNotificationSettings (settings);
			}
            
			UIApplication.SharedApplication.RegisterForRemoteNotifications ();

			Messaging.SharedInstance.Delegate = this;

			// To connect with FCM. FCM manages the connection, closing it
			// when your app goes into the background and reopening it 
			// whenever the app is foregrounded.
			Messaging.SharedInstance.ShouldEstablishDirectChannel = true;

            Window.RootViewController = new UINavigationController(new RegisterViewController());
            Window.MakeKeyAndVisible();

			return true;
		}

        [Export("applicationDidEnterBackground:")]
        public void DidEnterBackground(UIApplication application)
        {
            if (manager != null)
                manager.disconnect();
        }

        public static void SetUpManager(string userCode)
        {
            manager = new Manager();
            manager.setupPeerAndSession((NSString)userCode);
            manager.setupBrowser();
            manager.advertiseSelf(true);
        }


        void HandleAuthStateDidChangeListener(Auth auth, User user)
        {
           
        }

        UIView ViewWithColor(UIColor color)
        {
            var view = new UIView();
            view.BackgroundColor = color;
            return view;
        }

        UIColor CreateGradient(double percent, double topX, double bottomX, UIColor init, UIColor goal)
        {
            double t = (percent - bottomX) / (topX - bottomX);

            t = Math.Max(0.0, Math.Min(t, 1.0));

            nfloat[] cgInit = init.CGColor.Components;
            nfloat[] cgGoal = goal.CGColor.Components;

            nfloat r = (nfloat)(cgInit[0] + t * (cgGoal[0] - cgInit[0]));
            nfloat g = (nfloat)(cgInit[1] + t * (cgGoal[1] - cgInit[1]));
            nfloat b = (nfloat)(cgInit[2] + t * (cgGoal[2] - cgInit[2]));

            return UIColor.FromRGBA(r, g, b, 1.0f);
        }

		[Export ("messaging:didReceiveRegistrationToken:")]
		public void DidReceiveRegistrationToken (Messaging messaging, string fcmToken)
		{
			// Monitor token generation: To be notified whenever the token is updated.

			LogInformation (nameof (DidReceiveRegistrationToken), $"Firebase registration token: {fcmToken}");

			// TODO: If necessary send token to application server.
			// Note: This callback is fired at each app startup and whenever a new token is generated.
		}

		// You'll need this method if you set "FirebaseAppDelegateProxyEnabled": NO in GoogleService-Info.plist
		public override void RegisteredForRemoteNotifications (UIApplication application, NSData deviceToken)
		{
			Messaging.SharedInstance.ApnsToken = deviceToken;
		}

		public override void DidReceiveRemoteNotification (UIApplication application, NSDictionary userInfo, Action<UIBackgroundFetchResult> completionHandler)
		{
			// Handle Notification messages in the background and foreground.
			// Handle Data messages for iOS 9 and below.

			// If you are receiving a notification message while your app is in the background,
			// this callback will not be fired till the user taps on the notification launching the application.
			// TODO: Handle data of notification

			// With swizzling disabled you must let Messaging know about the message, for Analytics
			Messaging.SharedInstance.AppDidReceiveMessage (userInfo);

			HandleMessage (userInfo);

			// Print full message.
			LogInformation (nameof (DidReceiveRemoteNotification), userInfo);

			completionHandler (UIBackgroundFetchResult.NewData);
		}

		[Export ("messaging:didReceiveMessage:")]
		public void DidReceiveMessage (Messaging messaging, RemoteMessage remoteMessage)
		{
			// Handle Data messages for iOS 10 and above.
			HandleMessage (remoteMessage.AppData);

			LogInformation (nameof (DidReceiveMessage), remoteMessage.AppData);
		}


		void HandleMessage (NSDictionary message)
		{
			if (MessageReceived == null)
				return;

			MessageType messageType;
			if (message.ContainsKey (new NSString ("aps")))
				messageType = MessageType.Notification;
			else
				messageType = MessageType.Data;

			var e = new UserInfoEventArgs (message, messageType);
			MessageReceived (this, e);
		}

		public static void ShowMessage (string title, string message, UIViewController fromViewController, Action actionForOk = null)
		{
			if (UIDevice.CurrentDevice.CheckSystemVersion (8, 0)) {
				var alert = UIAlertController.Create (title, message, UIAlertControllerStyle.Alert);
				alert.AddAction (UIAlertAction.Create ("Ok", UIAlertActionStyle.Default, (obj) => actionForOk?.Invoke ()));
				fromViewController.PresentViewController (alert, true, null);
			} else {
				var alert = new UIAlertView (title, message, null, "Ok", null);
				alert.Clicked += (sender, e) => actionForOk?.Invoke ();
				alert.Show ();
			}
		}

		void LogInformation (string methodName, object information) => Console.WriteLine ($"\nMethod name: {methodName}\nInformation: {information}");

        public static double GetUtcTimestamp()
        {
            return double.Parse(DateTime.UtcNow.ToString("yyyyMMddHHmmss"));
        }

        public static DateTime GetDateTime()
        {
            return DateTime.Now;
        }

        public static string ConvertUnformattedUtcDateToCurrentDate(string utcDate)
        {
            var date = DateTime.ParseExact(utcDate, "yyyyMMddHHmmss", System.Globalization.CultureInfo.GetCultureInfo("en-Us"));
            return date.ToString("MM/dd/yy");
        }
	}
}


