using System;
using CoreAnimation;
using CoreGraphics;
using Foundation;
using UIKit;
using Firebase.Auth;
using Firebase.Core;
using CloudMessagingSample.Cells;
using System.Collections.Generic;
using Firebase.Database;

namespace Circle
{
    public partial class NearbyViewController : UIViewController
    {
        private NSObject authStateDidChangeListenerHandler;
        private Firebase.Auth.User currentUser;
        private float rowHeight = 50;
        private Manager manager;

        private string _username;
        public string Username
        {
            get { return _username; }
            set 
            {
                _username = value;
            }
        }


        public NearbyViewController() : base("NearbyViewController", null)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

            Title = "Nearby";
            NavigationItem.SetLeftBarButtonItem(new UIBarButtonItem("Done", UIBarButtonItemStyle.Done, GoBack), true);

            Initialize();
            // Perform any additional setup after loading the view, typically from a nib.
        }

        private void Initialize()
        {
            manager = new Manager();
            manager.setupPeerAndSession((NSString)"Jordan");
            manager.setupBrowser();
            manager.advertiseSelf(true);
            LoadUsers();

        }

        void GoBack(object sender, EventArgs e)
        {
            DismissViewController(true, null);
        }

        public override void ViewWillAppear(bool animated)
        {
            base.ViewWillAppear(animated);
            this.authStateDidChangeListenerHandler = Auth.DefaultInstance.AddAuthStateDidChangeListener(HandleAuthStateDidChangeListenerHandler);
        }

        public override void ViewWillDisappear(bool animated)
        {
            base.ViewWillDisappear(animated);
            Auth.DefaultInstance.RemoveAuthStateDidChangeListener(authStateDidChangeListenerHandler);
        }


        void HandleAuthStateDidChangeListenerHandler(Auth auth, Firebase.Auth.User user)
        {
            if (auth.CurrentUser != null)
            {
                currentUser = auth.CurrentUser;
                GetCurrentUser();
            }
        }

        private void LoadUsers()
        {
     
            var width = 0.30 * View.Frame.Size.Width;
            var height = 150;
            var y = 15;
            float lastY = 0;
            float contentHeight = (float)ScrollView.Frame.Height;

            for (int i = 0; i < manager.peers.Count; i++)
            {
                if (i % 2 == 0)
                {
                    var frame = new CGRect(20, lastY, width, height);
                    var cell = new NearbyCell(frame);
                    cell.ItemClicked += UserClicked;
                    cell.Frame = frame;
                    ScrollView.AddSubview(cell);
                    contentHeight += height + 20 ;
                } 
                else
                {
                    var x = UIScreen.MainScreen.Bounds.Width - (width + 20);
                    var frame = new CGRect(x, lastY, width, height);
                    var cell = new NearbyCell(frame);
                    cell.ItemClicked += UserClicked;
                    cell.Frame = frame;
                    ScrollView.AddSubview(cell);
                    lastY = (float)cell.Frame.GetMaxY() + 10;
                }
            }
            ScrollView.ContentSize = new CGSize(UIScreen.MainScreen.Bounds.Width, contentHeight);        
        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }
        
        public void SetBackground()
        {
            var gradientLayer = new CAGradientLayer();
            gradientLayer.Colors = new[] { UIColor.FromRGB(255,255,255).CGColor, UIColor.FromRGB(241,245,250).CGColor };
            gradientLayer.Locations = new NSNumber[] { 0, 1 };
            gradientLayer.Frame = UIScreen.MainScreen.Bounds;

            View.BackgroundColor = UIColor.Clear;
            View.Layer.AddSublayer(gradientLayer);
        }

        public void UserClicked(object sender, EventArgs e)
        {
            var userProfile = new UserViewController();
            userProfile.HidesBottomBarWhenPushed = true;
            NavigationController.PushViewController(userProfile, true);
        }

        private void GetCurrentUser()
        {
            var id = currentUser.Uid;
            Database.DefaultInstance.GetReferenceFromPath("users").GetChild(id).ObserveSingleEvent(DataEventType.Value, (snapshot) =>
            {
                var data = snapshot.GetValue<NSDictionary>();
            

            }, null);
        }


    }
}

