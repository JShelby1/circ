using System;
using Foundation;
using UIKit;
using Firebase.Database;
using Firebase.Auth;
namespace Circle
{
    public partial class BaseViewController : UIViewController
    {
        public NSObject authStateDidChangeListenerHandle;
        public DatabaseReference userNode;
        public Firebase.Auth.User currentUser;

        public BaseViewController(string nibName, NSBundle bundle) : base (nibName, bundle)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();
            // Perform any additional setup after loading the view, typically from a nib.
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
    }
}

