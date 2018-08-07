using System;
using Foundation;
using UIKit;
using Firebase.Database;
using Firebase.Auth;
using System.Collections.Generic;
using MultipeerConnectivity;
using Plugin.Geolocator;
using System.Linq;

namespace Circle
{
    public partial class BaseViewController : UIViewController
    {
        public NSObject authStateDidChangeListenerHandle;
        public DatabaseReference currentUserNode;
        public Firebase.Auth.User currentUser;
        public DatabaseReference groupsCountNode;
        public nuint groupsCount;
        public DatabaseQuery groupsByDate;
        public DatabaseReference groupNode;
        public Group group { get; set; }
        public List<Group> groups = new List<Group>();
        public DatabaseReference messageNode;
        public DatabaseQuery messagesByDate;
        public DatabaseReference messageCountNode;
        public nuint messagesCount;
        public DatabaseReference userNode;
        public Plugin.Geolocator.Abstractions.Position position;

        public BaseViewController(string nibName, NSBundle bundle) : base (nibName, bundle)
        {
        }

        public override async void ViewDidLoad()
        {
            base.ViewDidLoad();
            // Perform any additional setup after loading the view, typically from a nib.

            var locator = CrossGeolocator.Current;
            if (position == null)
                position = await locator.GetPositionAsync(TimeSpan.FromSeconds(10));

            NSNotificationCenter.DefaultCenter.AddObserver((NSString)"MCDidChangeStateWithNotification", DidChangeStateWithNotification);
        }


        public override void ViewWillAppear(bool animated)
        {
            base.ViewWillAppear(animated);

            this.authStateDidChangeListenerHandle = Auth.DefaultInstance.AddAuthStateDidChangeListener(HandleAuthStateDidChangeListenerHandler);

            CreateNodes();

                
        }

        public override void ViewWillDisappear(bool animated)
        {
            base.ViewWillDisappear(animated);
            var handle = this.authStateDidChangeListenerHandle;
            Auth.DefaultInstance.RemoveAuthStateDidChangeListener(handle);
            RemoveObservers();
        }


        private void DidChangeStateWithNotification(NSNotification notification)
        {
            NSDictionary dict = notification.UserInfo;
            Console.WriteLine(dict);
        }


        void HandleAuthStateDidChangeListenerHandler(Auth auth, Firebase.Auth.User user)
        {
            if (auth.CurrentUser != null)
            {
                
                currentUser = auth.CurrentUser;
                CreateUserNode(currentUser.Uid);
                if (View.Tag == 500)
                {
                    MoveToNext();
                }
                if (AppDelegate.manager == null)
                    AppDelegate.SetUpManager(currentUser.Uid);
                
            }
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


        private void CreateUserNode(string uid)
        {
            currentUserNode = AppDelegate.RootNode.GetChild("users").GetChild(uid);
        }

        private void CreateNodes()
        {
            userNode = AppDelegate.RootNode.GetChild("users").GetChildByAutoId();
            groupNode = AppDelegate.RootNode.GetChild("groups").GetChildByAutoId();
            groupsCountNode = AppDelegate.RootNode.GetChild("groups").GetChild("groupsCount");
            groupsByDate = groupNode.GetQueryOrderedByChild("negativeLastModified");
            messageCountNode = AppDelegate.RootNode.GetChild("messages").GetChild("messagesCount");
            messageNode = AppDelegate.RootNode.GetChild("messages").GetChildByAutoId();
            messagesByDate = messageNode.GetQueryOrderedByChild("negativeLastModified");
        }

        private void RemoveObservers()
        {
            userNode.RemoveAllObservers();
            currentUserNode.RemoveAllObservers();
            messageNode.RemoveAllObservers();
            messageCountNode.RemoveAllObservers();
            groupNode.RemoveAllObservers();
            groupsCountNode.RemoveAllObservers();
            groupsByDate.RemoveAllObservers();
        }


        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
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

        public void RetrieveGroups()
        {
            groups.Clear();

            Console.WriteLine($"Groups Count: {groupsCount}");
            if (groupsCount == 0)
            {
                return;
            }

            groupsByDate.ObserveEvent(DataEventType.ChildAdded, (snapshot) =>
            {
                var data = snapshot.GetValue<NSDictionary>();
                var name = data["name"].ToString();
                var lat = data["lat"].ToString();
                var lon = data["lon"].ToString();
                var lastModified = (data["lastModified"] as NSNumber).StringValue;
                var created = (data["created"] as NSNumber).StringValue;

                groups.Add(new Group
                {
                    Node = snapshot.Key,
                    Name = name,
                    Id = "Group",
                    Members = "m",
                    Lat = lat,
                    Lon = lon,
                    Created = AppDelegate.ConvertUnformattedUtcDateToCurrentDate(created),
                    LastModified = AppDelegate.ConvertUnformattedUtcDateToCurrentDate(lastModified)
                });
                Console.WriteLine($"Groups array Count: {groups.Count}");

                //CompareLocations(position.Latitude, position.Longitude);
            });

        }

    }
}

