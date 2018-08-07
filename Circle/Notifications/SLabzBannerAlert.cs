using System;
using UIKit;
using Foundation;
using CoreGraphics;
using CoreFoundation;

namespace Circle
{
    public class SLabzBannerAlert : UIView
    {

        private UILabel titleLabel;
        private UILabel messageLabel;
        private float alertHeight;
        private float viewWidth;
        private float textXOffset;
        private float notchedPhoneYOffset;
        private float notchedPhoneXOffset;
        private float displayInterval;
        private bool viewWasDismissed;

        public SLabzBannerAlert(string alertTitle, string alertMessage, float displayTime, UIImage alertImage = null)
        {
            UIView view = UIApplication.SharedApplication.Delegate.GetWindow().ViewWithTag(100);
            if (view != null)
                view = null;
                 
            if (Frame == CGRect.Empty)
            {
                ConfigureiVarsWithImage(alertImage, displayTime);
                Frame = FrameAfterReset();
                BackgroundColor = Colors.AppLighBlue;
                if (alertImage != null)
                    AddSubview(ImageViewWithImage(alertImage));
                if (alertTitle != null)
                    AddSubview(Title(alertTitle));
                AddSubview(Message(alertMessage));
                AddGestureRecognizer(Tap());
                AddGestureRecognizer(Pan());
                Tag = 100;
                UIApplication.SharedApplication.Delegate.GetWindow().AddSubview(this);

            }
        }

        public void ConfigureiVarsWithImage(UIImage alertImage, float displayTime)
        {
            //2. Set global variables.
            displayInterval = displayTime == 0f ? 4 : displayTime;
            alertHeight = 64;
            viewWidth = (float)UIScreen.MainScreen.Bounds.Width;
            textXOffset = alertImage != null ? 64 : 15; //Slides text to left if no image
            viewWasDismissed = false; //Flag set when dismiss is called
            notchedPhoneYOffset = 0;
        }

        public CGRect FrameAfterReset()
        {

            if (UIDevice.CurrentDevice.CheckSystemVersion(11,0))
            {
                UIEdgeInsets insets = UIApplication.SharedApplication.Delegate.GetWindow().SafeAreaInsets;
                if (insets.Top > 0 || insets.Right > 0)
                {
                    notchedPhoneXOffset = insets.Left > 0 ? 24 : 0;
                    notchedPhoneYOffset = insets.Top > 0 ? 24 : 0;
                    alertHeight += notchedPhoneYOffset;
                }
            }
            return new CGRect(0, -alertHeight, viewWidth, alertHeight);

        }

        public void SetAlertTitleColor(UIColor alertTitleColor)
        {
            if (titleLabel==null) {return;}
            titleLabel.TextColor = alertTitleColor;
        }

        public void SetAlertTitleFont(UIFont alertTitleFont)
        {
            if (titleLabel== null){ return; }
            titleLabel.Font = alertTitleFont;
        }

        public void SetAlertMessageColor(UIColor alertMessageColor)
        {
            messageLabel.TextColor = alertMessageColor;
        }

        public void SetAlertMessageFont(UIFont alertMessageFont)
        {
            messageLabel.Font = alertMessageFont;
        }

        public void SetAlertBackgroundColor(UIColor alertBackgroundColor)
        {
            BackgroundColor = alertBackgroundColor;
        }

        public UIImageView ImageViewWithImage(UIImage alertImage)
        {
            CGRect viewRect = new CGRect(15 + notchedPhoneXOffset, 14 + notchedPhoneYOffset, 36, 36);
            UIImageView view = new UIImageView(viewRect);
            view.Image = alertImage;
            return view;
        }

        public UILabel Title(string alertTitle)
        {
            titleLabel = new UILabel();
            var frame = new CGRect(textXOffset + notchedPhoneXOffset, 14 + notchedPhoneYOffset, Frame.Width-(textXOffset + notchedPhoneXOffset + 10), 20);
            titleLabel.Frame = frame;
            titleLabel.Text = alertTitle;
            titleLabel.TextColor = UIColor.White;
           // titleLabel.Font = UIFont.fontWithName:@"Avenir-Heavy" size:self.viewWidth > 321 ? 15.5 : 13]];
            return titleLabel;
        }


        public UILabel Message(string alertMessage)
        {
            messageLabel = new UILabel();
            var frame = new CGRect(textXOffset  + notchedPhoneXOffset, 32 + notchedPhoneYOffset, Frame.Width-(textXOffset + notchedPhoneXOffset + 10), 20);
            messageLabel.Lines = titleLabel == null ? 1 : 2;
            messageLabel.Text = alertMessage;
            messageLabel.TextColor = UIColor.White;
      //  messageLabel.Font = UIFont fontWithName:@"Avenir-Light" size:self.viewWidth > 321 ? 13.5 : 11.5]];
            if (titleLabel == null) {
                 VerticallyCenterLabel(messageLabel);
            }
             return messageLabel;
        }

        public UILabel VerticallyCenterLabel(UILabel messageLabel)
        {
            //1. Get the x origin
            float x = (float)messageLabel.Frame.X;

            //2. Resize the frame to fit (does not affect x origin)
            messageLabel.SizeToFit();

            //3. Set the new centered frame
            messageLabel.Frame = new CGRect(x, ((alertHeight) - messageLabel.Frame.Height) / 2, messageLabel.Frame.Width, messageLabel.Frame.Height + notchedPhoneYOffset);
    
            return messageLabel;
        }

        public UITapGestureRecognizer Tap()
        {
            return new UITapGestureRecognizer(this, new ObjCRuntime.Selector("UserGestureDetected:"));
        }

        public UIPanGestureRecognizer Pan()
        {
            return new UIPanGestureRecognizer(this, new ObjCRuntime.Selector("UserGestureDetected:"));
        }


        public void UserGestureDetected(UIGestureRecognizer gesture)
        {
    //1. Limit pan gesture recognition to initial gesture state
            if (gesture.GetType() == typeof(UIPanGestureRecognizer) && gesture.State != UIGestureRecognizerState.Began)
            {
                return;
            }

            InvokeOnMainThread(() => {
                DismissView(gesture);
            });
        }

        public void Display()
        {

            StatusBarToBottom();

            Animate(0.5, () =>
            {
                CGRect shiftFrame = this.Frame;
                shiftFrame.Y += alertHeight;
                Frame = shiftFrame;
            });

            TimedDismiss();
        }

        public void TimedDismiss()
        {
            var interval = (long)displayInterval;
            DispatchQueue.CurrentQueue.DispatchAfter(new DispatchTime(DispatchTime.Now,interval * 1000000000), () =>
            {
                DismissView(null);
            });
        }

        public void DismissView(UIGestureRecognizer gesture)
        {
            Animate(0.5, () =>
            {
                CGRect shiftFrame = this.Frame;
                shiftFrame.Y -= alertHeight;
                Frame = shiftFrame;
            }, () =>
            {
                CleanUp();  
            });

        }

    void CleanUp()
    {
            this.RemoveFromSuperview();
    }

    void StatusBarToBottom()
    {
        UIApplication.SharedApplication.Delegate.GetWindow().WindowLevel = UIWindowLevel.StatusBar + 1;
                

    }

    void StatusBarToTop()
    {
        UIApplication.SharedApplication.Delegate.GetWindow().WindowLevel = UIWindowLevel.Normal;    

    }

    }
}
