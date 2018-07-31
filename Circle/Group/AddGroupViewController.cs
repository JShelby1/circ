using System;
using Firebase.Database;
using Firebase.Auth;
using UIKit;
using CoreGraphics;
using System.Collections.Generic;
using System.Threading.Tasks;
using Foundation;
using Plugin.Geolocator;

namespace Circle
{
    public partial class AddGroupViewController : UIViewController
    {
        private NSObject authStateDidChangeListenerHandle;
        private DatabaseReference groupNode;
        private Firebase.Auth.User currentUser;
        public Plugin.Geolocator.Abstractions.Position position;
        private DatabaseReference groupsCountNode;
        private nuint groupsCount;

        public AddGroupViewController() : base("AddGroupViewController", null)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

            // Perform any additional setup after loading the view, typically from a nib.

            Initialize();
        }

        private void Initialize()
        {
            AddButton.TouchUpInside += CreateGroup;
        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

        public override void ViewWillAppear(bool animated)
        {
            base.ViewWillAppear(animated);

            this.authStateDidChangeListenerHandle = Auth.DefaultInstance.AddAuthStateDidChangeListener(HandleAuthStateDidChangeListenerHandler);

            CreateGroupNode();
            GetGroupsCount();
        }

        public override void ViewWillDisappear(bool animated)
        {
            base.ViewWillDisappear(animated);
            var handle = this.authStateDidChangeListenerHandle;
            Auth.DefaultInstance.RemoveAuthStateDidChangeListener(handle);
            groupNode.RemoveAllObservers();
            groupsCountNode.RemoveAllObservers();
        }

        void HandleAuthStateDidChangeListenerHandler(Auth auth, Firebase.Auth.User user)
        {
            if (auth.CurrentUser != null)
            {
                currentUser = auth.CurrentUser;
            }
        }

        private void CreateGroupNode()
        {
            groupNode = AppDelegate.RootNode.GetChild("groups").GetChildByAutoId();
            groupsCountNode = AppDelegate.RootNode.GetChild("groups").GetChild("groupsCount");

        }

        void GetGroupsCount()
        {
            groupsCountNode.ObserveEvent(DataEventType.Value, (snapshot) =>
            {
                groupsCount = snapshot.Exists ? snapshot.GetValue<NSNumber>().NUIntValue : 0;
            });
        }


        public async void CreateGroup(object sender, EventArgs e)
        {
            
            var name = TextField.Text != null ? TextField.Text : "Group";

            var loc = GetLocation().ToString();
            /*  if (position == null)
              {
                 // var locator = CrossGeolocator.Current;
                 // position = await locator.GetPositionAsync(TimeSpan.FromSeconds(10));
              }*/

            var lat = "lat";
            var lon = "lon";

            object[] keys = { "name", "location", "lat", "lon" };
            object[] values = { name, loc, lat, lon };
            var data = NSDictionary.FromObjectsAndKeys(values, keys, keys.Length);

            try
            {
                groupNode.KeepSynced(true);
                groupNode.SetValue(data);
                groupsCountNode.SetValue(NSNumber.FromNUInt(++groupsCount));
            }
            catch (Exception t)
            {
                Console.WriteLine($"Create group error: {t.Message}");
            }
        
            //Navigate Back
            GoBack();
		}

        private void GoBack()
        {
            NavigationController.PopViewController(true);
        }

		public void CompareLocations()
		{
			
		}

        private async Task<Plugin.Geolocator.Abstractions.Position> GetLocation()
        {
            var locator = CrossGeolocator.Current;

            position = await locator.GetPositionAsync(TimeSpan.FromSeconds(10));

            return position;
        }

    }
}

