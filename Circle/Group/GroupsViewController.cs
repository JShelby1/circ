using System;
using System.Collections.Generic;
using Foundation;
using UIKit;
using Firebase.Database;
using Firebase.Auth;

namespace Circle
{
    public partial class GroupsViewController : UIViewController, IUITableViewDelegate, IUITableViewDataSource
    {

        private DatabaseReference groupNode;
        private AuthStateDidChangeListenerHandler authStateDidChangeListener;
        private Firebase.Auth.User currentUser;
        private Group group { get; set; }
        private List<Group> groups = new List<Group>();
        private DatabaseReference groupsCountNode;
        private nuint groupsCount;
        private DatabaseQuery groupsByDate;


        public GroupsViewController() : base("GroupsViewController", null)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

            Title = "Groups";
            NavigationItem.SetLeftBarButtonItem(new UIBarButtonItem("Done", UIBarButtonItemStyle.Done, GoBack), true);
            NavigationItem.SetRightBarButtonItem(new UIBarButtonItem("Add", UIBarButtonItemStyle.Done, GoToAddGroup), true);

            Initialize();

        }

        public override void ViewWillAppear(bool animated)
        {
            base.ViewWillAppear(animated);

            CreateGroupNodes();
            GetGroupsCount();
        }

        public override void ViewWillDisappear(bool animated)
        {
            base.ViewWillDisappear(animated);
            RemoveAllObservers();
        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();

        }

        private void Initialize()
        {

            TableView.Delegate = this;
            TableView.DataSource = this;

            RetrieveGroups();
        }

        void RemoveAllObservers()
        {
            groupNode.RemoveAllObservers();
            groupsCountNode.RemoveAllObservers();
            groupsByDate.RemoveAllObservers();

        }

        void GoBack(object sender, EventArgs e)
        {
            DismissViewController(true, null);
        }

        void GoToAddGroup(object sender, EventArgs e)
        {
            NavigationController.PushViewController(new AddGroupViewController(), true);
        }

        private void CreateGroupNodes()
        {
            groupNode = AppDelegate.RootNode.GetChild("groups");
            groupsCountNode = AppDelegate.RootNode.GetChild("groups").GetChild("groupsCount");
            groupsByDate = groupNode.GetQueryOrderedByChild("negativeLastModified");
        }

        private void GetGroupsCount()
        {
            groupsCountNode.ObserveEvent(DataEventType.Value, (snapshot) =>
            {
                groupsCount = snapshot.Exists ? snapshot.GetValue<NSNumber>().NUIntValue : 0;
                RetrieveGroups();
                
            }, (error) => {
                Console.WriteLine($"Retrieve group error: {error.LocalizedDescription}");
            });
        }

        private void RetrieveGroups()
        {
            groups.Clear();

            if (groupsCount == 0)
            {
                return;
            }

            groupsByDate.ObserveEvent(DataEventType.ChildAdded, (snapshot) =>
            {
                if (snapshot.Key != "groupsCount")
                {
                    Console.WriteLine(snapshot);
                    var data = snapshot.GetValue<NSDictionary>();
                    var name = data["name"].ToString();

                    groups.Add(new Group
                    {
                        Node = snapshot.Key,
                        Name = name,
                        Id = "Group",
                        Members = "m"
                    });

                }
            });
        }
                                      

        public nint RowsInSection(UITableView tableView, nint section)
        {
            return (nint)groupsCount;
        }

        public UITableViewCell GetCell(UITableView tableView, NSIndexPath indexPath)
        {
            var group = groups[indexPath.Row];
            var cell = tableView.DequeueReusableCell("cell", indexPath);
            cell.TextLabel.Text = group.Name;
            return cell;
        }
    }
}

