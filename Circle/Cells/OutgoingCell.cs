using System;
using Foundation;
using UIKit;
using CoreGraphics;

namespace Circle
{
    public partial class OutgoingCell : UICollectionViewCell
    {
        public static readonly NSString Key = new NSString("OutgoingCell");
        public static readonly UINib Nib;

        public OutgoingCell()
        {
        }

        protected OutgoingCell(IntPtr handle) : base(handle)
        {
             Initialize();
        }

        private UIImageView imageView;
        private UIImageView ImageView()
        {
            var frame = new CGRect(10, 10, 40, 40);
            imageView = new UIImageView(frame);
            imageView.BackgroundColor = Colors.AppGreen;
            imageView.Layer.CornerRadius = 20;
            return imageView;
        }

        private UITextView textView;
        private UITextView TextView()
        {
            var frame = new CGRect(imageView.Frame.GetMaxX() + 10, 10, 0.7 * Frame.Size.Width, this.Frame.Height);
            textView = new UITextView(frame)
            {
                BackgroundColor = UIColor.Clear,
                Text = "Sample text for now",
                Font = UIFont.SystemFontOfSize(16),
                TranslatesAutoresizingMaskIntoConstraints = false
            };

            return textView;
        }
        public override void UpdateConstraints()
        {
            base.UpdateConstraints();

            var imageLeadingConstraint = NSLayoutConstraint.Create(this, NSLayoutAttribute.Leading, NSLayoutRelation.Equal, ImageView(), NSLayoutAttribute.Leading, 1, 16);
            var imageTopConstraint = NSLayoutConstraint.Create(this, NSLayoutAttribute.Top, NSLayoutRelation.Equal, ImageView(), NSLayoutAttribute.Top, 1, 5);
            ImageView().AddConstraint(imageLeadingConstraint);
            ImageView().AddConstraint(imageTopConstraint);
            ImageView().WidthAnchor.ConstraintEqualTo(40).Active = true;
            ImageView().HeightAnchor.ConstraintEqualTo(40).Active = true;
            ImageView().Layer.CornerRadius = 20;

            var textViewLeftConstraint = NSLayoutConstraint.Create(ImageView(), NSLayoutAttribute.Left, NSLayoutRelation.Equal, TextView(), NSLayoutAttribute.Left, 1, 10);
            var textViewTopConstraint = NSLayoutConstraint.Create(this, NSLayoutAttribute.Top, NSLayoutRelation.Equal, TextView(), NSLayoutAttribute.Top, 1, 10);
            TextView().AddConstraint(textViewLeftConstraint);
            TextView().AddConstraint(textViewTopConstraint);
            TextView().WidthAnchor.ConstraintEqualTo(200).Active = true;
            TextView().HeightAnchor.ConstraintEqualTo(HeightAnchor).Active = true;
        }

        void Initialize()
        {
            AddSubview(ImageView());
            AddSubview(TextView());

        }
    }
}
