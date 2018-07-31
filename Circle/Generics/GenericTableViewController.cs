using System;
using Foundation;
using UIKit;
using System.Collections.Generic;

namespace Circle
{
    public partial class GenericTableViewController<T> : UITableViewController, IUITableViewDelegate, IUITableViewDataSource
    {
        List<T> items;

        public GenericTableViewController() 
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();


            // Perform any additional setup after loading the view, typically from a nib.
        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

        public override UITableViewCell GetCell(UITableView tableView, NSIndexPath indexPath)
        {
            var cell = new UITableViewCell(UITableViewCellStyle.Default, "cell");
            return cell;
        }

        [Export("numberOfSectionsInTableView:")]
        public nint NumberOfSections(UITableView tableView)
        {
            return 1;
        }

        public override nint RowsInSection(UITableView tableView, nint section)
        {
            return items.Count;
        }



    }
}

