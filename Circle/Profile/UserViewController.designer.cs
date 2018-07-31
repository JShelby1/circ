// WARNING
//
// This file has been generated automatically by Visual Studio from the outlets and
// actions declared in your storyboard file.
// Manual changes to this file will not be maintained.
//
using Foundation;
using System;
using System.CodeDom.Compiler;
using UIKit;

namespace Circle
{
    [Register ("UserViewController")]
    partial class UserViewController
    {
        [Outlet]
        [GeneratedCode ("iOS Designer", "1.0")]
        UIKit.UIButton ChatButton { get; set; }

        [Outlet]
        [GeneratedCode ("iOS Designer", "1.0")]
        UIKit.UIImageView ProfileImageView { get; set; }

        void ReleaseDesignerOutlets ()
        {
            if (ChatButton != null) {
                ChatButton.Dispose ();
                ChatButton = null;
            }

            if (ProfileImageView != null) {
                ProfileImageView.Dispose ();
                ProfileImageView = null;
            }
        }
    }
}