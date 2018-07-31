using System;
using Foundation;
using UIKit;


using System.Collections.Generic;
using System.Linq;
using Firebase.Auth;

namespace Circle
{
    public partial class MainTabBarController : UITabBarController, IUIViewControllerTransitioningDelegate, IUITabBarControllerDelegate
    {

        UIViewController profileTab, chatTab, groupsTab, nearbyTab;
        UINavigationController profileNav, chatNav, groupsNav, nearbyNav;

        List<string> images = new List<string>() { "chat@2x.png", "nearby@2x.png", "groups@2x.png", "profile@2x.png"};

        public MainTabBarController()
        {
            this.Delegate = this;

            this.TabBar.TintColor = Colors.AppLighBlue;

            profileTab = new ProfileViewController();
            profileTab.TabBarItem.Image = UIImage.FromFile(images[3]);
            profileTab.Title = "Profile";

            chatTab = new ChatViewController();
            chatTab.TabBarItem.Image = UIImage.FromFile(images[0]);
            chatTab.Title = "Chat";

            groupsTab = new GroupsViewController();
            groupsTab.TabBarItem.Image = UIImage.FromFile(images[2]);
            groupsTab.Title = "Groups";

            nearbyTab = new NearbyViewController();
            nearbyTab.TabBarItem.Image = UIImage.FromFile(images[1]);
            nearbyTab.Title = "Nearby";

            profileNav = new UINavigationController(profileTab);
            chatNav = new UINavigationController(chatTab);
            groupsNav = new UINavigationController(groupsTab);
            nearbyNav = new UINavigationController(nearbyTab);

            var navs = new UINavigationController[] { chatNav, nearbyNav, groupsNav, profileNav };

            foreach (var nav in navs)
            {
                nav.NavigationBar.SetBackgroundImage(new UIImage(), UIBarMetrics.Default);
                nav.NavigationBar.ShadowImage = new UIImage();
                nav.NavigationBar.Translucent = false;
                nav.NavigationBar.BarTintColor = UIColor.FromRGB(249, 249, 249);
                nav.NavigationBar.TintColor = UIColor.Black;

            }


            var tabs = navs;

            ViewControllers = tabs;



        }
        void HandleAuthStateDidChangeListener(Auth auth, User user)
        {
            if (auth.CurrentUser != null)
            {
                
            }
        }







    }
}


