using System;

using Foundation;
using UIKit;
using CoreGraphics;
using JSQMessagesViewController;


namespace Circle
{
    public partial class ChatViewController : UIViewController, IUICollectionViewDelegate, IUICollectionViewSource, IUITextFieldDelegate, IUICollectionViewDelegateFlowLayout
    {

        private string CellId = "CellId";
        private UICollectionView CollectionView;
        public ChatViewController() 
        {
        }
        private UITextField textField;
        private UITextField TextField()
        {
            textField = new UITextField()
            {
                Placeholder = TextLibrary.ChatFieldText,
                TranslatesAutoresizingMaskIntoConstraints = false,
                Delegate = this
            };
            return textField;
        }
        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

            NavigationItem.SetLeftBarButtonItem(new UIBarButtonItem("Done", UIBarButtonItemStyle.Done, GoBack), true);
            Title = "Chat";

            var layout = new UICollectionViewFlowLayout();
            layout.ScrollDirection = UICollectionViewScrollDirection.Vertical;
            CollectionView = new UICollectionView(UIScreen.MainScreen.Bounds, layout);
            CollectionView.BackgroundColor = UIColor.FromRGB(249, 249, 249);
            CollectionView.Delegate = this;
            CollectionView.DataSource = this;
            CollectionView.Bounces = true;
            CollectionView.RegisterClassForCell(typeof(OutgoingCell), OutgoingCell.Key);
            View.AddSubview(CollectionView);

            //SetupInputComponents();

            // Perform any additional setup after loading the view, typically from a nib.
        }

        void ObserveMessages()
        {
            
        }

        void GoBack(object sender, EventArgs e)
        {
            DismissViewController(true, null);
        }

        void SetupInputComponents()
        {
            var containerView = new UIView();
            containerView.BackgroundColor = UIColor.White;
            containerView.TranslatesAutoresizingMaskIntoConstraints = false;
            View.AddSubview(containerView);

            containerView.LeftAnchor.ConstraintEqualTo(View.LeftAnchor).Active = true;
            containerView.BottomAnchor.ConstraintEqualTo(View.BottomAnchor).Active = true;
            containerView.WidthAnchor.ConstraintEqualTo(View.WidthAnchor).Active = true;
            containerView.HeightAnchor.ConstraintEqualTo(50).Active = true;

            var sendButton = new UIButton(UIButtonType.System);
            sendButton.SetTitle(TextLibrary.SendButton, UIControlState.Normal);
            sendButton.TranslatesAutoresizingMaskIntoConstraints = false;
            containerView.AddSubview(sendButton);

            sendButton.RightAnchor.ConstraintEqualTo(containerView.RightAnchor).Active = true;
            sendButton.BottomAnchor.ConstraintEqualTo(containerView.BottomAnchor).Active = true;
            sendButton.WidthAnchor.ConstraintEqualTo(100).Active = true;
            sendButton.HeightAnchor.ConstraintEqualTo(60).Active = true;

            var tf = TextField();
            containerView.AddSubview(tf);
            tf.BottomAnchor.ConstraintEqualTo(containerView.BottomAnchor).Active = true;
            tf.RightAnchor.ConstraintEqualTo(containerView.RightAnchor).Active = true;
            tf.WidthAnchor.ConstraintEqualTo(containerView.WidthAnchor).Active = true;
            tf.HeightAnchor.ConstraintEqualTo(containerView.HeightAnchor).Active = true;
        }

        [Export("HandleSend")]
        void HandleSend()
        {
            
        }

        [Export("numberOfSectionsInCollectionView:")]
        public nint NumberOfSections(UICollectionView collectionView)
        {
            return 1;
        }

        [Export("collectionView:layout:sizeForItemAtIndexPath:")]
        public CGSize GetSizeForItem(UICollectionView collectionView, UICollectionViewLayout layout, NSIndexPath indexPath)
        {

            var height = EstimateSizeForText().Height + 20;
            return new CGSize(UIScreen.MainScreen.Bounds.Width, height);
        }

        [Export("collectionView:numberOfItemsInSection:")]
        public nint GetItemsCount(UICollectionView collectionView, nint section)
        {
            return 20;
        }

        [Export("collectionView:cellForItemAtIndexPath:")]
        public UICollectionViewCell GetCell(UICollectionView collectionView, NSIndexPath indexPath)
        {
            var cell = (OutgoingCell)collectionView.DequeueReusableCell(OutgoingCell.Key, indexPath);
        
            return cell;
        }

        private CGRect EstimateSizeForText(string text = "Sample text for now")
        {
            var size = new CGSize(0.7 * UIScreen.MainScreen.Bounds.Width, 1000);
            var options = NSStringDrawingOptions.UsesFontLeading & NSStringDrawingOptions.UsesLineFragmentOrigin;
            var attr = new UIStringAttributes
            {
                Font = UIFont.SystemFontOfSize(16)
            };

            return new NSString(text).GetBoundingRect(size, options, attr, null);
        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

    }


}

