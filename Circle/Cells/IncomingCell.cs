using System;

using Foundation;
using UIKit;

namespace Cirlce
{
    public partial class IncomingCell : UICollectionViewCell
    {
        public static readonly NSString Key = new NSString("IncomingCell");
        public static readonly UINib Nib;

        static IncomingCell()
        {
            Nib = UINib.FromName("IncomingCell", NSBundle.MainBundle);
        }

        protected IncomingCell(IntPtr handle) : base(handle)
        {
            // Note: this .ctor should not contain any initialization logic.
        }
    }
}
