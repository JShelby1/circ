using System;
using Firebase.Auth;
using Firebase.Database;
using UIKit;
using Foundation;

namespace Circle
{
    public partial class ProfileViewController : UIViewController
    {
        private NSObject authStateDidChangeListenerHandler;
        private Firebase.Auth.User currentUser;
        private string username { get; set; }
        private string email { get; set; }

        public ProfileViewController() : base("ProfileViewController", null)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

            Title = "Profile";

            // Perform any additional setup after loading the view, typically from a nib.

            Initilize();
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


        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

        private void Initilize()
        {
            ProfileImageView.ClipsToBounds = true;
            ProfileImageView.Image = UIImage.FromFile("profile.jpg");
            ProfileImageView.Layer.CornerRadius = ProfileImageView.Frame.Width / 2;
            SettingsButton.Layer.CornerRadius = SettingsButton.Frame.Width / 2;
            EditButton.Layer.CornerRadius = EditButton.Frame.Width / 2;
           // LogoutButton.Layer.CornerRadius = LogoutButton.Frame.Height / 2;

            TopView.Layer.MasksToBounds = false;
            TopView.Layer.ShadowOffset = new CoreGraphics.CGSize(0, 3);
            TopView.Layer.ShadowRadius = 5;
            TopView.Layer.ShadowOpacity = 0.2f;



            // LogoutButton.Layer.MasksToBounds = false;
            // LogoutButton.Layer.ShadowOffset = new CoreGraphics.CGSize(0, 5);
            // LogoutButton.Layer.ShadowRadius = 5;
            // LogoutButton.Layer.ShadowOpacity = 0.2f;




        }

        private void GetCurrentUser()
        {
            var id = currentUser.Uid;
            Database.DefaultInstance.GetReferenceFromPath("users").GetChild(id).ObserveSingleEvent(DataEventType.Value, (snapshot) =>
            {
                var data = snapshot.GetValue<NSDictionary>();
                FullName.Text = data["username"].ToString();
                Username.Text = data["email"].ToString();

            },null);
        }
    }
}

