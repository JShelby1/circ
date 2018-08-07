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
    public partial class NearbyViewController : BaseViewController
    {
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


        public NearbyViewController() : base("NearbyViewController", NSBundle.MainBundle)
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
            LoadUsers();
        }

        void GoBack(object sender, EventArgs e)
        {
            DismissViewController(true, null);
        }

        private void LoadUsers()
        {
            if (AppDelegate.manager.peers.Count > 0)
            {
                var width = 0.30 * View.Frame.Size.Width;
                var height = 150;
                var y = 15;
                float lastY = 0;
                float contentHeight = (float)ScrollView.Frame.Height;

                for (int i = 0; i < AppDelegate.manager.peers.Count; i++)
                {
                    if (i % 2 == 0)
                    {
                        var frame = new CGRect(20, lastY, width, height);
                        var cell = new NearbyCell(frame);
                        cell.ItemClicked += UserClicked;
                        cell.Frame = frame;
                        ScrollView.AddSubview(cell);
                        contentHeight += height + 20;
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
            else
            {
                
            }
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

    }
}

