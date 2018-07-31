using System;
using System.Drawing;
using CoreGraphics;
using Foundation;
using UIKit;

namespace Circle
{
    public partial class HomeViewController : UIViewController, IUIViewControllerTransitioningDelegate
    {
        public UIButton nearbyButton, chatButton, groupsButton;

        public HomeViewController() : base("HomeViewController", null)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();
            // Perform any additional setup after loading the view, typically from a nib.

            Title = "Circle";
            Initialize();
        }
    

        private void Initialize()
        {
            var profileRightBarButton = new UIButton();

            var newImage = MaxResizeImage(UIImage.FromFile("profile.jpg"), 40, 40);
            profileRightBarButton.Frame = new CGRect(View.Frame.Size.Width - 66f, 16,40, 40);
            profileRightBarButton.ImageView.ContentMode = UIViewContentMode.ScaleAspectFill;
            profileRightBarButton.SetImage(newImage, UIControlState.Normal);
            profileRightBarButton.Layer.MasksToBounds = true;
            profileRightBarButton.BackgroundColor = Colors.AppGreen;
            profileRightBarButton.Layer.CornerRadius = profileRightBarButton.Frame.Width/2;;
            profileRightBarButton.Layer.BorderWidth = 2;
            profileRightBarButton.Layer.BorderColor = UIColor.White.CGColor;
            profileRightBarButton.Layer.ShadowOffset = new CoreGraphics.CGSize(0, 3);
            profileRightBarButton.Layer.ShadowRadius = 5;
            profileRightBarButton.Layer.ShadowOpacity = 0.2f;
            profileRightBarButton.TouchUpInside += showMessage;

            UIBarButtonItem rightItem = new UIBarButtonItem(profileRightBarButton);
            NavigationItem.SetRightBarButtonItem(rightItem, true);

        }

        // resize the image to be contained within a maximum width and height, keeping aspect ratio
        public UIImage MaxResizeImage(UIImage sourceImage, float maxWidth, float maxHeight)
        {
            var sourceSize = sourceImage.Size;
            var maxResizeFactor = Math.Max(maxWidth / sourceSize.Width, maxHeight / sourceSize.Height);
            if (maxResizeFactor > 1) return sourceImage;
            float width = (float)maxResizeFactor * (float)sourceSize.Width;
            float height = (float)maxResizeFactor * (float)sourceSize.Height;
            UIGraphics.BeginImageContext(new SizeF(width, height));
            sourceImage.Draw(new RectangleF(0, 0, width, height));
            var resultImage = UIGraphics.GetImageFromCurrentImageContext();
            UIGraphics.EndImageContext();
            return resultImage;
        }


        public override void ViewWillLayoutSubviews()
        {
            base.ViewWillLayoutSubviews();

            SetupComponents();
        }

        void showMessage(object sender, EventArgs e)
        {
            var view = new SLabzBannerAlert("Title", "Message", 2);
            view.Display();
        }

        private void SetupComponents()
        {
            CreateButtons();

            Chat.TouchUpInside += GoToChat;
            Chat.Layer.ShadowOffset = new CoreGraphics.CGSize(0, 3);
            Chat.Layer.ShadowRadius = 5;
            Chat.Layer.ShadowOpacity = 0.2f;

            Groups.TouchUpInside += GoToGroups;
            Groups.Layer.ShadowOffset = new CoreGraphics.CGSize(0, 3);
            Groups.Layer.ShadowRadius = 5;
            Groups.Layer.ShadowOpacity = 0.2f;

            Nearby.TouchUpInside += GoToNearby;
            Nearby.Layer.ShadowOffset = new CoreGraphics.CGSize(0, 3);
            Nearby.Layer.ShadowRadius = 5;
            Nearby.Layer.ShadowOpacity = 0.2f;
        }

        private void CreateButtons()
        {
            var smallWidth = 0;
            var largeWidth = 0;

            UIButton[] buttons = { Chat, Nearby, Groups };
            foreach (var button in buttons)
            {
                var intToString = button.Frame.Width.ToString();
                if (intToString[intToString.Length - 1] <= 4)
                {
                    smallWidth = ExtensionMethods.RoundOff((int)button.Frame.Width);
                    button.Frame = new CGRect(button.Frame.X, button.Frame.Y, smallWidth, smallWidth);
                    if (button.Tag == 2)
                        button.Frame = new CGRect(button.Frame.X, button.Frame.Y, largeWidth, largeWidth);
                }
                else
                {
                    largeWidth = smallWidth = ExtensionMethods.RoundOff((int)button.Frame.Width);
                    button.Frame = new CGRect(button.Frame.X, button.Frame.Y, largeWidth, largeWidth);
                    if (button.Tag == 1)
                        button.Frame = new CGRect(button.Frame.X, button.Frame.Y, smallWidth, smallWidth);
                }

            }

            Chat.Layer.CornerRadius = (float)Math.Round(Chat.Frame.Width / 2, 0);
            Nearby.Layer.CornerRadius = (float)Math.Round(Nearby.Frame.Width / 2, 0);
            Groups.Layer.CornerRadius = (float)Math.Round(Groups.Frame.Width / 2, 0);

            chatButton = Chat;
            groupsButton = Groups;
            nearbyButton = Nearby;

            Nearby.TouchUpInside += GoToNearby;
        }

        private void GoToNearby(object sender, EventArgs e)
        {
            var nearby = new UINavigationController(new NearbyViewController());
            nearby.ModalPresentationStyle = UIModalPresentationStyle.FullScreen;
            nearby.TransitioningDelegate = this;
            PresentViewController(nearby, true, null);

        }

        private void GoToChat(object sender, EventArgs e)
        {
            var chat = new UINavigationController( new ChatViewController());
            chat.ModalPresentationStyle = UIModalPresentationStyle.FullScreen;
            chat.TransitioningDelegate = this;
            PresentViewController(chat, true, null);

        }

        private void GoToGroups(object sender, EventArgs e)
        {
            var groups = new UINavigationController(new GroupsViewController());
            groups.ModalPresentationStyle = UIModalPresentationStyle.FullScreen;
            groups.TransitioningDelegate = this;
            PresentViewController(groups, true, null);

        }

        private void GoToProfile(object sender, EventArgs e)
        {
            var profile = new ProfileViewController();
            profile.ModalPresentationStyle = UIModalPresentationStyle.FullScreen;
            profile.TransitioningDelegate = this;
            PresentViewController(profile, true, null);

        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

        [Export("animationControllerForPresentedController:presentingController:sourceController:")]
        public IUIViewControllerAnimatedTransitioning GetAnimationControllerForPresentedController(UIViewController presented, UIViewController presenting, UIViewController source)
        {
            return new CrossDissolveTransitionAnimator();
        }

        [Export("animationControllerForDismissedController:")]
        public IUIViewControllerAnimatedTransitioning GetAnimationControllerForDismissedController(UIViewController dismissed)
        {
            return new CrossDissolveTransitionAnimator();
        }
    }
}

