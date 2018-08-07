using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using CoreGraphics;
using Foundation;
using MultipeerConnectivity;
using Plugin.Geolocator;
using UIKit;
using Firebase.Database;
using Firebase.Auth;

namespace Circle
{
    public partial class HomeViewController : BaseViewController, IUIViewControllerTransitioningDelegate
    {
        public UIButton nearbyButton, chatButton, groupsButton;
        private List<CircleUser> users = new List<CircleUser>();
       // public List<string> values = new List<string>();

        public HomeViewController() : base("HomeViewController", NSBundle.MainBundle)
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
            profileRightBarButton.Layer.CornerRadius = 20;
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

        public override void ViewWillDisappear(bool animated)
        {
            base.ViewWillDisappear(animated);

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

        private void GetCurrentUserNode(string mcPeers)
        {
            var id = users[0].Id;
            var name = users[0].Name;
            var email = users[0].Email;
            var password = users[0].Password;
            var group = mcPeers;
            var photoUrl = users[0].PhotoUrl;

            var uid = currentUser.Uid;
            if (uid != null)
            {
                try
                {
                    currentUserNode = Database.DefaultInstance.GetReferenceFromPath("users").GetChild(uid);
                    if (AppDelegate.manager.MCPeers.Count == 0)
                    {
                        object[] keys = { "id", "username", "email", "password", "group", "photoUrl" };
                        object[] values = { id, name, "email", "password", "group", photoUrl };
                        var data = NSDictionary.FromObjectsAndKeys(values, keys, keys.Length);
                        currentUserNode.KeepSynced(true);
                        currentUserNode.UpdateChildValues(data);
                    }
                    else
                    {
                        currentUserNode.KeepSynced(true);
                        currentUserNode.SetValueForKey((NSString)group, (NSString)"groupId");
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine($"Get current user error: {e.Message}");
                }
            }
        }

        private void GetValues()
        {
            var id = currentUser.Uid;
            if (id != null)
            {
                try
                {
                    currentUserNode = Database.DefaultInstance.GetReferenceFromPath("users").GetChild(id);
                    currentUserNode.ObserveSingleEvent(DataEventType.Value, (snapshot) =>
                    {
                        var data = snapshot.GetValue<NSDictionary>();
                        var name = data["username"].ToString();
                        var email = data["email"].ToString();
                        var password = data["password"].ToString();
                        var groupNodeKey = data["groupId"].ToString();
                        var photoUrl = "photo.jpg";

                        users.Add(new CircleUser()
                        {
                            Id = snapshot.Key,
                            Name = name,
                            Email = email,
                            Password = password,
                            PhotoUrl = photoUrl,
                            Group = groupNodeKey
                        });

                       // GetCurrentUserNode();
                    });

                }
                catch (Exception e)
                {
                    Console.WriteLine($"Get values error: {e.Message}");
                }
            }
        }

        private void CreateGroupNode()
        {
            string groupNodeKey = "";
            currentUserNode.ObserveEvent(DataEventType.Value, (snapshot) =>
            {
                Console.WriteLine($"Snapshot: {snapshot}");
                var data = snapshot.GetValue<NSDictionary>();
                groupNodeKey = data["groupId"].ToString();

         
            });

         //   groupNode = user.Group != "m" ? AppDelegate.RootNode.GetChild("nearbyGroup").GetChild(user.Group)
                  //               : AppDelegate.RootNode.GetChild("nearbyGroup").GetChildByAutoId();    
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
            var id = groupNode.Key;
            var chat = new UINavigationController( new ChatViewController(id));
            chat.ModalPresentationStyle = UIModalPresentationStyle.FullScreen;
            chat.TransitioningDelegate = this;
            PresentViewController(chat, true, null);
        }

        public async void CreateNearbyChat(List<MCPeerID> peerUsers)
        {
            var locator = CrossGeolocator.Current;
            var position = await locator.GetPositionAsync(TimeSpan.FromSeconds(10));

            var lat = position.Latitude.ToString();
            var lon = position.Longitude.ToString();
            string[] users = { };

            foreach (var peer in peerUsers)
            {
                var id = peer.ToString();
                users.Append(id);
            }

            object[] keys = { "users", "lat", "lon" };
            object[] values = { users, lat, lon };
            var data = NSDictionary.FromObjectsAndKeys(values, keys, keys.Length);

            groupNode.KeepSynced(true);
            groupNode.SetValue(data);
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

