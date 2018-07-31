using System;
using FloatLabeledEntry;
using UIKit;
using CoreGraphics;
using System.Collections.Generic;

namespace Circle
{
    public partial class WelcomeViewController : UIViewController
    {

        List<string> readPermissions = new List<string> { "public_profile" };

        public WelcomeViewController() : base("WelcomeViewController", null)
        {
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

			Initialize();         
        }

        public override void DidReceiveMemoryWarning()
        {
            base.DidReceiveMemoryWarning();
            // Release any cached data, images, etc that aren't in use.
        }

		public void Initialize()
		{
			Bind();
		}

        private void Bind()
		{
			RegisterBtn.TouchUpInside += GoToRegister;
		}

		private void GoToRegister(object sender, EventArgs e)
		{
			var register = new RegisterViewController();
			NavigationController.PushViewController(register, true);
		}



    }
}

