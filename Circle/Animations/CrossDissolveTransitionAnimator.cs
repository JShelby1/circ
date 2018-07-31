using UIKit;
using CoreAnimation;
using Foundation;

namespace Circle {
    public class CrossDissolveTransitionAnimator : UIViewControllerAnimatedTransitioning, ICAAnimationDelegate {

		public override double TransitionDuration (IUIViewControllerContextTransitioning transitionContext)
		{
			return 0.35;
		}

		public override void AnimateTransition (IUIViewControllerContextTransitioning transitionContext)
		{
            /*var home = new HomeViewController();
            var buttonFrame = home.chatButton.Frame;
            var endFrame = UIScreen.MainScreen.Bounds;
            var fromViewController = transitionContext.GetViewControllerForKey(UITransitionContext.FromViewControllerKey) as UIViewController;
            var toViewController = transitionContext.GetViewControllerForKey(UITransitionContext.ToViewControllerKey) as UIViewController;
            var destinationView = toViewController.View;

            var containerView = transitionContext.ContainerView;

            containerView.AddSubview(fromViewController.View);
            containerView.AddSubview(destinationView);

            var maskPath = UIBezierPath.FromOval(buttonFrame);

            var maskLayer = new CAShapeLayer();
            maskLayer.Frame = destinationView.Frame;
            maskLayer.Path = maskPath.CGPath;
            toViewController.View.Layer.Mask = maskLayer;

            var bigCirclePath = UIBezierPath.FromOval(endFrame);

            var pathAnimation = CABasicAnimation.FromKeyPath("path");
            pathAnimation.From = ObjCRuntime.Runtime.GetNSObject(maskPath.CGPath.Handle);
            pathAnimation.To = bigCirclePath;
            pathAnimation.Duration = TransitionDuration(transitionContext);
            pathAnimation.AnimationStopped += (object sender, CAAnimationStateEventArgs e) => {
                if (e.Finished == true)
                {
                    transitionContext.CompleteTransition(true);
                }
            };
            maskLayer.Path = bigCirclePath.CGPath;
            maskLayer.AddAnimation(pathAnimation, "pathAnimation");
            
*/

            var fromViewController = transitionContext.GetViewControllerForKey(UITransitionContext.FromViewControllerKey);
			var toViewController = transitionContext.GetViewControllerForKey(UITransitionContext.ToViewControllerKey);

			UIView containerView = transitionContext.ContainerView;

			var fromView = transitionContext.GetViewFor(UITransitionContext.FromViewKey);
			var toView = transitionContext.GetViewFor(UITransitionContext.ToViewKey);

			fromView.Frame = transitionContext.GetInitialFrameForViewController (fromViewController);
			toView.Frame = transitionContext.GetFinalFrameForViewController (toViewController);

			fromView.Alpha = 1f;
			toView.Alpha = 0f;

			containerView.AddSubview (toView);
			var transitionDuration = TransitionDuration (transitionContext);

			UIView.Animate (transitionDuration, 0, UIViewAnimationOptions.TransitionNone, () => {
					fromView.Alpha = 0f;
					toView.Alpha = 1f;
				}, () => {
					bool wasCancel = transitionContext.TransitionWasCancelled;
					transitionContext.CompleteTransition (!wasCancel);
				}
			);
			
        }


	}
}
