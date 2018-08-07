using System;
using System.Collections.Generic;
using Foundation;
using UIKit;
using Firebase.Database;
using Firebase.Auth;
using Plugin.Geolocator;
using CoreLocation;


namespace Circle
{
    public partial class GroupsViewController : BaseViewController, IUITableViewDelegate, IUITableViewDataSource
    {

        private List<Group> removeList = new List<Group>();

        public GroupsViewController() : base("GroupsViewController", NSBundle.MainBundle) { }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();
            View.Tag = 400;
            Title = "Groups";
            NavigationItem.SetLeftBarButtonItem(new UIBarButtonItem("Done", UIBarButtonItemStyle.Done, GoBack), true);
            NavigationItem.SetRightBarButtonItem(new UIBarButtonItem("Add", UIBarButtonItemStyle.Done, GoToAddGroup), true);

            Initialize();

        }


        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
        }

        private void Initialize()
        {
            TableView.Delegate = this;
            TableView.DataSource = this;

        }

        public override void ViewWillAppear(bool animated)
        {
            base.ViewWillAppear(animated);

            GetGroupsCount();
            if (groups.Count == (int)groupsCount)
            {
                TableView.ReloadData();
            }
        }

        void GoBack(object sender, EventArgs e)
        {
            DismissViewController(true, null);
        }

        void GoToAddGroup(object sender, EventArgs e)
        {
            NavigationController.PushViewController(new AddGroupViewController(), true);
        }

        private void GetGroupsCount()
        {
            groupsCountNode.ObserveEvent(DataEventType.Value, (snapshot) =>
            {
                Console.WriteLine($"Group count snapshot: {snapshot}");
                groupsCount = snapshot.Exists ? snapshot.GetValue<NSNumber>().NUIntValue : 0;
                RetrieveGroups();
            }, (error) => {
                Console.WriteLine($"Retrieve group error: {error.LocalizedDescription}");
            });
        }



     

        public void CompareLocations(double lat, double lon)
        {
            var currentLocation = new CLLocation(lat, lon);
            var groupsForLoop = groups.ToArray();
            for (int i = 0; i < (int)groups.Count; i++)
            {
                var group = groups[i];
                var groupLatitude = Convert.ToDouble(group.Lat);
                var groupLongitude = Convert.ToDouble(group.Lon);
                var groupLocation = new CLLocation(groupLatitude, groupLongitude);

                var distance = groupLocation.DistanceFrom(currentLocation);
                Console.WriteLine(distance);
                if (distance > 15)
                    AddToRemoveList(groups[i]);   
            }

        }

        private void AddToRemoveList(Group group)
        {
            groups.Remove(group);
        }

        private void InsertRow(Group group)
        {
            var indexPath = new NSIndexPath[] { NSIndexPath.FromIndex(0) };
         
            groups.Insert(0, group);
            TableView.InsertRows(indexPath, UITableViewRowAnimation.Left);
            TableView.ReloadData();
        }

        private void DeleteRow(int index)
        {
            
        }

                                     
        public nint RowsInSection(UITableView tableView, nint section)
        {
            return (nint)groups.Count;
        }

        public UITableViewCell GetCell(UITableView tableView, NSIndexPath indexPath)
        {
            var group = groups[indexPath.Row];
            var cell = new UITableViewCell(UITableViewCellStyle.Default, "cell");
            cell.TextLabel.Text = group.Name;
            return cell;
        }
    }
}

