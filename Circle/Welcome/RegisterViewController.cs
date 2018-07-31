using System;
using FloatLabeledEntry;
using CoreGraphics;
using UIKit;
using System.Collections.Generic;
using Firebase.Auth;
using Foundation;
using Facebook.LoginKit;
using Facebook.CoreKit;
using Firebase.Database;
using Plugin.Geolocator;
using System.Threading.Tasks;

namespace Circle
{
    public partial class RegisterViewController : UIViewController
    {

        private NSObject authStateDidChangeListenerHandle;
        private List<string> readPermissions = new List<string> { "public_profile" };
        private FloatLabeledTextField nameField;
        private FloatLabeledTextField emailField;
        private FloatLabeledTextField passwordField;
         public DatabaseReference userNode;
        public Firebase.Auth.User currentUser;

        public RegisterViewController() : base("RegisterViewController", null)
        {
        }

        public override async void ViewDidLoad()
        {
            base.ViewDidLoad();

        //    await GetLocation();
            Initialize();


            if (AccessToken.CurrentAccessToken != null)
            {
                var credential = FacebookAuthProvider.GetCredential(AccessToken.CurrentAccessToken.TokenString);
               // Auth.DefaultInstance.SignIn(credential, SignInOnCompletion);
            }

        }

        private async Task<Plugin.Geolocator.Abstractions.Position> GetLocation()
        {
            var locator = CrossGeolocator.Current;

            var position = await locator.GetPositionAsync(TimeSpan.FromSeconds(10));

            return position;
        }


        public override void ViewWillAppear(bool animated)
        {
            base.ViewWillAppear(animated);

            this.authStateDidChangeListenerHandle = Auth.DefaultInstance.AddAuthStateDidChangeListener(HandleAuthStateDidChangeListenerHandler);
           

        }

        public override void ViewWillDisappear(bool animated)
        {
            base.ViewWillDisappear(animated);
            var handle = this.authStateDidChangeListenerHandle;
            Auth.DefaultInstance.RemoveAuthStateDidChangeListener(handle);
            userNode.RemoveAllObservers();
        }


        void HandleAuthStateDidChangeListenerHandler(Auth auth, Firebase.Auth.User user)
        {
            if (auth.CurrentUser != null)
            {
                currentUser = auth.CurrentUser;
                CreateUserNode(currentUser.Uid);
                MoveToNext();
            }
        }



        private void CreateUserNode(string uid)
        {
            userNode = AppDelegate.RootNode.GetChild("users").GetChild(uid);
        }



        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

        public void Initialize()
        {
            var space = 50;
            var betweenSpace = 20;

            nameField = new FloatLabeledTextField(new CGRect(RegisterLabel.Frame.X,
                                                                 RegisterLabel.Frame.GetMaxY() + space,
                                                                 0.9 * (View.Frame.Width),
                                                                 space))
            {
                Placeholder = "Your name",
                FloatingLabelFont = UIFont.BoldSystemFontOfSize(12),
                FloatingLabelTextColor = UIColor.Gray,
                FloatingLabelActiveTextColor = UIColor.Gray
            };

            emailField = new FloatLabeledTextField(new CGRect(RegisterLabel.Frame.X,
                                                                  nameField.Frame.GetMaxY() + betweenSpace,
                                                                 0.9 * (View.Frame.Width),
                                                                 space))
            {
                Placeholder = "Your email",
                FloatingLabelFont = UIFont.BoldSystemFontOfSize(12),
                FloatingLabelTextColor = UIColor.Gray,
                FloatingLabelActiveTextColor = UIColor.Gray
            };

            passwordField = new FloatLabeledTextField(new CGRect(RegisterLabel.Frame.X,
                                                                     emailField.Frame.GetMaxY() + betweenSpace,
                                                                 0.9 * (View.Frame.Width),
                                                                 space))
            {
                Placeholder = "Your password",
                FloatingLabelFont = UIFont.BoldSystemFontOfSize(12),
                FloatingLabelTextColor = UIColor.Gray,
                FloatingLabelActiveTextColor = UIColor.Gray
            };

            View.AddSubviews(new UIView[] { nameField, emailField, passwordField });
            View.AddSubview(BottomBorder(nameField.Frame));
            View.AddSubview(BottomBorder(emailField.Frame));
            View.AddSubview(BottomBorder(passwordField.Frame));

            FacebookButton.TouchUpInside += LoginButtonTapped;

            var tap = new UITapGestureRecognizer(() => View.EndEditing(true));
            View.AddGestureRecognizer(tap);
        }

        private UIView BottomBorder(CGRect frame)
        {
            var space = 2;
            var height = 1;
            var view = new UIView(new CGRect(View.Frame.Width / 2 - 0.5 * ((0.9) * View.Frame.Width),
                                             frame.GetMaxY() + space, 0.9 * View.Frame.Width, height))
            {
                BackgroundColor = UIColor.FromRGB(160, 160, 164)
            };

            return view;
        }

        async void LoginButtonTapped(object sender, EventArgs e)
        {
            var email = emailField.Text;
            var password = passwordField.Text;
            var name =nameField.Text;

            await Auth.DefaultInstance.CreateUserAsync(email, password);
            AddUserToDatabase();
            MoveToNext();
      
        }

        private void AddUserToDatabase()
        {
            object[] keys = { "id", "username", "email", "password" };
            object[] values = {currentUser.Uid, nameField.Text, emailField.Text, passwordField.Text };
            var data = NSDictionary.FromObjectsAndKeys(values, keys, keys.Length);

            userNode.KeepSynced(true);
            userNode.SetValue(data);

        }

        private void MoveToNext()
        {
            var home = new HomeViewController();
            var homeNav = new UINavigationController(home);

            homeNav.NavigationBar.SetBackgroundImage(new UIImage(), UIBarMetrics.Default);
            homeNav.NavigationBar.ShadowImage = new UIImage();
            homeNav.NavigationBar.Translucent = true;
            homeNav.View.BackgroundColor = UIColor.Clear;
            homeNav.NavigationBar.BarTintColor = UIColor.White;
            homeNav.NavigationBar.BackgroundColor = UIColor.Clear;

            this.PresentViewController(homeNav, true, null);
        }
    
        void BtnLogin_Completed(object sender, LoginButtonCompletedEventArgs e)
        {
            if (e.Error != null)
            {
                // Handle if there was an error
                AppDelegate.ShowMessage("Could not login!", e.Error.Description, NavigationController);
                return;
            }

            if (e.Result.IsCancelled)
            {
                // Handle if the user cancelled the login request
                AppDelegate.ShowMessage("Could not login!", "The user cancelled the login", NavigationController);
                return;
            }

            // Get access token for the signed-in user and exchange it for a Firebase credential
            var credential = FacebookAuthProvider.GetCredential(AccessToken.CurrentAccessToken.TokenString);

            // Authenticate with Firebase using the credential
            Auth.DefaultInstance.SignIn(credential, SignInOnCompletion);
        }



        void SignInOnCompletion(Firebase.Auth.User user, NSError error)
        {
            if (error != null)
            {
                AuthErrorCode errorCode;
                if (IntPtr.Size == 8) // 64 bits devices
                    errorCode = (AuthErrorCode)((long)error.Code);
                else // 32 bits devices
                    errorCode = (AuthErrorCode)((int)error.Code);

                // Posible error codes that SignIn method with credentials could throw
                // Visit https://firebase.google.com/docs/auth/ios/errors for more information
                switch (errorCode)
                {
                    case AuthErrorCode.InvalidCredential:
                    case AuthErrorCode.InvalidEmail:
                    case AuthErrorCode.OperationNotAllowed:
                    case AuthErrorCode.EmailAlreadyInUse:
                    case AuthErrorCode.UserDisabled:
                    case AuthErrorCode.WrongPassword:
                    default:
                        AppDelegate.ShowMessage("Could not login!", error.LocalizedDescription, NavigationController);
                        break;
                }

                return;
            }
            var login = new Facebook.LoginKit.LoginManager();
            login.LoginBehavior = Facebook.LoginKit.LoginBehavior.SystemAccount;
        }
    }
}

