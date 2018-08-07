using System;
using Firebase.Database;
using Firebase.Auth;
using UIKit;
using CoreGraphics;
using System.Collections.Generic;
using System.Threading.Tasks;
using Foundation;
using Plugin.Geolocator;
using CoreLocation;

namespace Circle
{
    public partial class AddGroupViewController : BaseViewController
    {
        #region Computed Properties
        public static bool UserInterfaceIdiomIsPhone
        {
            get { return UIDevice.CurrentDevice.UserInterfaceIdiom == UIUserInterfaceIdiom.Phone; }
        }

        public static LocationManager Manager { get; set; }
        #endregion
        private CLLocation location;
        private double longitude;
        private double latitude;
        Plugin.Geolocator.Abstractions.IGeolocator locator = CrossGeolocator.Current;
        public AddGroupViewController() : base("AddGroupViewController", NSBundle.MainBundle)
        {
            Manager = new LocationManager();
            Manager.StartLocationUpdates();

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

          /*  UIApplication.Notifications.ObserveDidBecomeActive((sender, args) => {
             //   Manager.LocationUpdated += HandleLocationChanged;
                locator.PositionChanged += delegate {


                };
            });

            // Whenever the app enters the background state, we unsubscribe from the event 
            // so we no longer perform foreground updates
            UIApplication.Notifications.ObserveDidEnterBackground((sender, args) => {
              //  Manager.LocationUpdated -= HandleLocationChanged;
                locator.PositionChanged -= delegate {


                };
            });*/


        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

        public override void ViewWillAppear(bool animated)
        {
            base.ViewWillAppear(animated);

            GetGroupsCount();
        }

        public override void ViewWillDisappear(bool animated)
        {
            base.ViewWillDisappear(animated);
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
            var created = AppDelegate.GetUtcTimestamp();
            var lat = position.Latitude.ToString();
            var lon = position.Longitude.ToString();

            object[] keys = { "name", "lat", "lon", "lastModified", "negativeLastModified" };
            object[] values = { name, lat, lon, created, -created };
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

        public void HandleLocationChanged(object sender, LocationUpdatedEventArgs e)
        {
            location = e.Location;
            latitude = e.Location.Coordinate.Latitude;
            longitude = e.Location.Coordinate.Longitude;


        }

        private void GoBack()
        {
            NavigationController.PopViewController(true);
        }

    }
}

