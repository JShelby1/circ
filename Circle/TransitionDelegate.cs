using System;
using UIKit;
using Foundation;

namespace Circle
{
    public class TransitionDelegate : UIViewControllerTransitioningDelegate
    {
        public UIViewControllerContextTransitioning transitionContext;
        public TransitionDelegate()
        {
        }

        [Export("animationControllerForPresentedController:presentingController:sourceController:")]
        public IUIViewControllerAnimatedTransitioning GetAnimationControllerForPresentedController(UIViewController presented, UIViewController presenting, UIViewController source)
        {
            throw new System.NotImplementedException();
        }

        public override IUIViewControllerInteractiveTransitioning GetInteractionControllerForDismissal(IUIViewControllerAnimatedTransitioning animator)
        {
            return base.GetInteractionControllerForDismissal(animator);
        }


    }
}
