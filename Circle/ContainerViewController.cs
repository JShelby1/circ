using System;
using CoreGraphics;
using UIKit;


namespace CloudMessagingSample
{
	public partial class ContainerViewController : PagingViewController
    {
        public ContainerViewController()  { }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();
			// Perform any additional setup after loading the view, typically from a nib.
		

			var numPages = 3;


			var contentWidth = UIScreen.MainScreen.Bounds.Width * numPages;
			var pageWidth = UIScreen.MainScreen.Bounds.Width;
			var contentHeight = ScrollView.Frame.Height;
			ScrollView.ContentSize = new CGSize(contentWidth, contentHeight);

			var subviewWidth = UIScreen.MainScreen.Bounds.Width;

			AddView();
            
            /*
		    for (int i = 0; i < 3; i++)
			{
				var frame = new CGRect(i * pageWidth, 0, subviewWidth, contentHeight);
				var view = views[i];
				view.Frame = UIScreen.MainScreen.Bounds;
				ScrollView.AddSubview(view);
			}   
			*/
            
        }

		private void Initilize()
		{

			var chat = new ChatViewController().View;
            var profile = new ProfileViewController().View;
            var nearby = new NearbyViewController().View;

			var views = new UIView[] { profile, nearby, chat };

			var profile1 = UIImage.FromFile("admin.png").ImageWithRenderingMode(UIImageRenderingMode.AlwaysTemplate);
			var profile2 = UIImage.FromFile("admin.png").ImageWithRenderingMode(UIImageRenderingMode.AlwaysTemplate);
			var profile3 = UIImage.FromFile("admin.png").ImageWithRenderingMode(UIImageRenderingMode.AlwaysTemplate);
            
			var imageView1 = new UIImageView(profile1);
			var imageView2 = new UIImageView(profile2);
			var imageView3 = new UIImageView(profile3);

			var images = new UIImageView[] { imageView1, imageView2, imageView3 };

			var pagingViewController = new PagingViewController(images, views, false);
		}
      

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

        private void AddView()
		{
			var width = UIScreen.MainScreen.Bounds.Width;
			var height = UIScreen.MainScreen.Bounds.Height;

			var chat = new ChatViewController().View;
            var profile = new ProfileViewController().View;
            var nearby = new NearbyViewController().View;

			var profileFrame = new CGRect(0, 0, width, height);
			profile.Frame = profileFrame;

			var nearbyFrame = new CGRect(width, 0, width, height);
			nearby.Frame = nearbyFrame;

			var chatFrame = new CGRect(width * 2, 0, width, height);
			chat.Frame = chatFrame;

			ScrollView.AddSubview(profile);
			ScrollView.AddSubview(nearby);
			ScrollView.AddSubview(chat);

		}

		public override void ViewWillAppear(bool animated)
		{
			base.ViewWillAppear(animated);

			ScrollView.SetContentOffset(new CGPoint(UIScreen.MainScreen.Bounds.Width, 0), false);
		}
	}
}

