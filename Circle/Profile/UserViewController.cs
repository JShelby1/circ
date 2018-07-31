using System;

using UIKit;

namespace Circle
{
    public partial class UserViewController : UIViewController
    {
        public UserViewController() : base("UserViewController", null)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

            Initialize();
            // Perform any additional setup after loading the view, typically from a nib.
        }

        void Initialize()
        {
            
            ProfileImageView.Layer.CornerRadius = ProfileImageView.Frame.Width / 2;

            ChatButton.Layer.MasksToBounds = false;
            ChatButton.Layer.ShadowOffset = new CoreGraphics.CGSize(0, 3);
            ChatButton.Layer.ShadowRadius = 5;
            ChatButton.Layer.ShadowOpacity = 0.2f;

        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

        public override bool HidesBottomBarWhenPushed 
        { 
            get => base.HidesBottomBarWhenPushed; set => base.HidesBottomBarWhenPushed = value; 
        }


    }
}

