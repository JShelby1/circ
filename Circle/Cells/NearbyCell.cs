using System;
using UIKit;
using CoreGraphics;
using Foundation;

namespace Circle
{
    public class NearbyCell : UIView
    {
        private CGRect frame;
        private UIImageView imageView;
        private UILabel nameLabel;
        private UILabel connectionLabel;
        private UITapGestureRecognizer TapRecognizer { get; set; }

        public int Position { get; set; }

        public event EventHandler<ViewUserEventArgs> ItemClicked;

        public NearbyCell(CGRect frame)
        {
            this.frame = frame;
            Initialize();
        }

        private void Initialize()
        {
            BackgroundColor = UIColor.White;
            Layer.CornerRadius = 10;

            var imageWidth = 50;
            var imageHeight = 50;

            var imageFrame = new CGRect(frame.Width / 2 - 0.5 * imageWidth, 20,
                                        imageWidth, imageHeight);
            imageView = new UIImageView(imageFrame);
            imageView.Layer.CornerRadius = imageView.Frame.Width / 2;
            imageView.BackgroundColor = Colors.AppGreen;

      
            var nameHeight = 21;

            var nameFrame = new CGRect(0, imageView.Frame.GetMaxY() + 30, frame.Width, nameHeight);

            nameLabel = new UILabel(nameFrame);
            nameLabel.TextAlignment = UITextAlignment.Center;
            nameLabel.TextColor = Colors.AppMainLabe;
            nameLabel.Font = UIFont.BoldSystemFontOfSize(17);
            nameLabel.Text = "Jordan"; 

            AddSubview(imageView);
            AddSubview(nameLabel);

            Layer.MasksToBounds = false;
            Layer.ShadowOffset = new CoreGraphics.CGSize(0, 2);
            Layer.ShadowRadius = 2;
            Layer.ShadowOpacity = 0.2f;

            TapRecognizer = new UITapGestureRecognizer(() =>
            {
                ItemClicked?.Invoke(this, new ViewUserEventArgs(Position));
            });
            AddGestureRecognizer(TapRecognizer);
        }


    }
}
