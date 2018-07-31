#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic ignored "-Wtypedef-redefinition"
#pragma clang diagnostic ignored "-Wobjc-designated-initializers"
#define DEBUG 1
#include <stdarg.h>
#include <objc/objc.h>
#include <objc/runtime.h>
#include <objc/message.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Speech/Speech.h>
#import <UserNotifications/UserNotifications.h>
#import <Photos/Photos.h>
#import <MultipeerConnectivity/MultipeerConnectivity.h>
#import <MediaPlayer/MediaPlayer.h>
#import <CoreMotion/CoreMotion.h>
#import <CoreLocation/CoreLocation.h>
#import <QuartzCore/QuartzCore.h>
#import <EventKit/EventKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreGraphics/CoreGraphics.h>

@protocol UICollectionViewSource;
@class UIViewControllerTransitioningDelegate;
@class UIViewControllerAnimatedTransitioning;
@class UIApplicationDelegate;
@class CLLocationManagerDelegate;
@class UIKit_UIControlEventProxy;
@class UIImagePickerControllerDelegate;
@class UISearchBarDelegate;
@class UITableViewSource;
@class __MonoMac_NSActionDispatcher;
@class __MonoMac_NSAsyncActionDispatcher;
@class NSURLConnectionDataDelegate;
@class Cirlce_IncomingCell;
@class MonoTouch_Dialog_DialogViewController;
@class Circle_UserInfoViewController;
@class ChatViewController;
@class ProfileViewController;
@class WelcomeViewController;
@class MainViewController;
@class NearbyViewModel;
@class MessagesViewModel;
@class ProfileViewModel;
@class ProfileViewModelBase;
@class Circle_MainTabBarController;
@class Circle_NearbyCell;
@class UserViewController;
@class Circle_GenericTableViewController_1;
@class Circle_OutgoingCell;
@class HomeViewController;
@class Circle_TransitionDelegate;
@class BaseViewController;
@class Cirlce_CrossDissolveTransitionAnimator;
@protocol FIRMessagingDelegate;
@class AppDelegate;
@class Circle_Manager;
@class GroupsViewController;
@class NearbyViewController;
@class RegisterViewController;
@class AddGroupViewController;
@class Circle_CrossDissolveTransitionAnimator;
@class Circle_CustomPresentationController;
@class Circle_SLabzBannerAlert;
@class CoreLocation_CLLocationManager__CLLocationManagerDelegate;
@class UIKit_UIAlertView__UIAlertViewDelegate;
@class UIKit_UIBarButtonItem_Callback;
@class UIKit_UIView_UIViewAppearance;
@class UIKit_UIControl_UIControlAppearance;
@class UIKit_UIButton_UIButtonAppearance;
@class __UIGestureRecognizerToken;
@class __UIGestureRecognizerParameterlessToken;
@class UIKit_UISearchBar__UISearchBarDelegate;
@class UIKit_UITableViewCell_UITableViewCellAppearance;
@class UIKit_UITextField__UITextFieldDelegate;
@class UIKit_UIScrollView__UIScrollViewDelegate;
@class UIKit_UITextView__UITextViewDelegate;
@class UIKit_UITabBarController__UITabBarControllerDelegate;
@class UIKit_UIWebView__UIWebViewDelegate;
@class __NSObject_Disposer;
@class FIRMessagingMessageInfo;
@class FIRMessagingDelegate;
@class FIRMessagingRemoteMessage;
@class FIRMessaging;
@class FIRInstanceID;
@class FIRAnalyticsConfiguration;
@class FIRApp;
@class FIRConfiguration;
@class FIROptions;
@class FIRAnalytics;
@class FIRDatabaseQuery;
@class FIRDatabaseReference;
@class FIRDataSnapshot;
@class FIRMutableData;
@class FIRDatabase;
@class FIRServerValue;
@class FIRTransactionResult;
@class FIRActionCodeInfo;
@class FIRActionCodeSettings;
@class FIRAdditionalUserInfo;
@class FIRAuthCredential;
@class FIRAuthDataResult;
@protocol FIRAuthUIDelegate;
@class FIRAuthUIDelegate;
@class FIREmailAuthProvider;
@class FIRFacebookAuthProvider;
@class FIRGitHubAuthProvider;
@class FIRGoogleAuthProvider;
@class FIROAuthProvider;
@class FIRPhoneAuthCredential;
@class FIRTwitterAuthProvider;
@protocol FIRUserInfo;
@class FIRUserMetadata;
@class FIRAuth;
@class FIRPhoneAuthProvider;
@class FIRUser;
@class FIRUserProfileChangeRequest;
@class MonoTouch_Dialog_MessageSummaryView;
@class MonoTouch_Dialog_RefreshTableHeaderView;
@class MonoTouch_Dialog_GlassButton;
@class MonoTouch_Dialog_BaseBooleanImageElement_TextWithImageCellView;
@class MonoTouch_Dialog_HtmlElement_WebViewController;
@class MonoTouch_Dialog_ImageElement_MyDelegate;
@class MonoTouch_Dialog_DateTimeElement_MyViewController;
@class MonoTouch_Dialog_DialogViewController_SearchDelegate;
@class MonoTouch_Dialog_DialogViewController_Source;
@class MonoTouch_Dialog_DialogViewController_SizingSource;
@class MonoTouch_Dialog_MessageElement_MessageCell;
@class MonoTouch_Dialog_OwnerDrawnElement_OwnerDrawnCell;
@class MonoTouch_Dialog_OwnerDrawnElement_OwnerDrawnCellView;
@class MonoTouch_Dialog_JsonElement_ConnectionDelegate;
@class Plugin_Geolocator_GeolocationSingleUpdateDelegate;
@class FloatLabeledTextField;
@protocol FBSDKAppGroupAddDialogDelegate;
@class FBSDKAppGroupAddDialogDelegate;
@protocol FBSDKCopying;
@class FBSDKAppGroupContent;
@protocol FBSDKAppGroupJoinDialogDelegate;
@class FBSDKAppGroupJoinDialogDelegate;
@class FBSDKAppInviteContent;
@protocol FBSDKAppInviteDialogDelegate;
@class FBSDKAppInviteDialogDelegate;
@class FBSDKCameraEffectArguments;
@class FBSDKCameraEffectTextures;
@class FBSDKGameRequestContent;
@protocol FBSDKGameRequestDialogDelegate;
@class FBSDKGameRequestDialogDelegate;
@class FBSDKHashtag;
@protocol FBSDKLiking;
@class FBSDKLiking;
@protocol FBSDKSharing;
@protocol FBSDKSharingDialog;
@class FBSDKMessageDialog;
@class FBSDKShareAPI;
@protocol FBSDKSharingContent;
@class FBSDKShareCameraEffectContent;
@class FBSDKShareDialog;
@class FBSDKShareLinkContent;
@class FBSDKShareMediaContent;
@protocol FBSDKShareMessengerActionButton;
@class FBSDKShareMessengerGenericTemplateContent;
@class FBSDKShareMessengerGenericTemplateElement;
@class FBSDKShareMessengerMediaTemplateContent;
@class FBSDKShareMessengerOpenGraphMusicTemplateContent;
@class FBSDKShareMessengerURLActionButton;
@protocol FBSDKShareOpenGraphValueContaining;
@class FBSDKShareOpenGraphValueContainer;
@class FBSDKShareOpenGraphAction;
@class FBSDKShareOpenGraphContent;
@class FBSDKShareOpenGraphObject;
@class FBSDKShareOpenGraphValueContaining;
@class FBSDKSharePhoto;
@class FBSDKSharePhotoContent;
@class FBSDKShareVideo;
@class FBSDKShareVideoContent;
@class FBSDKSharing;
@protocol FBSDKSharingButton;
@class FBSDKSharingButton;
@protocol FBSDKSharingDelegate;
@class FBSDKSharingDelegate;
@class FBSDKSharingDialog;
@class FBSDKPlacesManager;
@class FBSDKMessengerContext;
@class FBSDKMessengerBroadcastContext;
@class FBSDKMessengerShareButton;
@class FBSDKMessengerShareOptions;
@class FBSDKMessengerSharer;
@class FBSDKMessengerURLHandlerCancelContext;
@protocol FBSDKMessengerURLHandlerDelegate;
@class FBSDKMessengerURLHandlerDelegate;
@class FBSDKMessengerURLHandlerOpenFromComposerContext;
@class FBSDKMessengerURLHandlerReplyContext;
@class FBSDKDeviceLoginCodeInfo;
@protocol FBSDKDeviceLoginManagerDelegate;
@class FBSDKDeviceLoginManagerDelegate;
@class FBSDKDeviceLoginManagerResult;
@protocol FBSDKLoginButtonDelegate;
@class FBSDKLoginButtonDelegate;
@class FBSDKLoginManagerLoginResult;
@protocol FBSDKLoginTooltipViewDelegate;
@class FBSDKLoginTooltipViewDelegate;
@class FBSDKSettings;
@class FBSDKAccessToken;
@class FBSDKAppEvents;
@class FBSDKApplicationDelegate;
@protocol BFAppLinkResolving;
@class FBSDKAppLinkResolver;
@class BFAppLinkResolving;
@class FBSDKCopying;
@protocol FBSDKErrorRecoveryAttempting;
@class FBSDKErrorRecoveryAttempting;
@class FBSDKGraphErrorRecoveryProcessor;
@protocol FBSDKGraphErrorRecoveryProcessorDelegate;
@class FBSDKGraphErrorRecoveryProcessorDelegate;
@class FBSDKGraphRequest;
@protocol FBSDKGraphRequestConnectionDelegate;
@class FBSDKGraphRequestConnectionDelegate;
@class FBSDKGraphRequestDataAttachment;
@protocol FBSDKMutableCopying;
@class FBSDKMutableCopying;
@class FBSDKProfile;
@class BFTask;
@class FBSDKTestUsersManager;
@class FBSDKUtility;
@class Facebook_ShareKit_AppGroupAddDialog__AppGroupAddDialogDelegate;
@class FBSDKAppGroupAddDialog;
@class Facebook_ShareKit_AppGroupJoinDialog__AppGroupJoinDialogDelegate;
@class FBSDKAppGroupJoinDialog;
@class Facebook_ShareKit_AppInviteDialog__AppInviteDialogDelegate;
@class FBSDKAppInviteDialog;
@class Facebook_ShareKit_GameRequestDialog__GameRequestDialogDelegate;
@class FBSDKGameRequestDialog;
@class Facebook_CoreKit_Button_ButtonAppearance;
@class Facebook_ShareKit_LikeButton_LikeButtonAppearance;
@class FBSDKButton;
@class FBSDKLikeButton;
@class Facebook_ShareKit_LikeControl_LikeControlAppearance;
@class FBSDKLikeControl;
@class Facebook_ShareKit_SendButton_SendButtonAppearance;
@class FBSDKSendButton;
@class Facebook_ShareKit_ShareButton_ShareButtonAppearance;
@class FBSDKShareButton;
@class Facebook_MessengerShareKit_MessengerUrlHandler__MessengerUrlHandlerDelegate;
@class FBSDKMessengerURLHandler;
@class Facebook_LoginKit_DeviceLoginManager__DeviceLoginManagerDelegate;
@class FBSDKDeviceLoginManager;
@class Facebook_LoginKit_LoginButton__LoginButtonDelegate;
@class Facebook_LoginKit_LoginButton_LoginButtonAppearance;
@class FBSDKLoginButton;
@class FBSDKLoginManager;
@class Facebook_LoginKit_LoginTooltipView__LoginTooltipViewDelegate;
@class Facebook_LoginKit_TooltipView_TooltipViewAppearance;
@class Facebook_LoginKit_LoginTooltipView_LoginTooltipViewAppearance;
@class FBSDKTooltipView;
@class FBSDKLoginTooltipView;
@class FBSDKAppLinkUtility;
@class Facebook_CoreKit_GraphRequestConnection__GraphRequestConnectionDelegate;
@class FBSDKGraphRequestConnection;
@class Facebook_CoreKit_ProfilePictureView_ProfilePictureViewAppearance;
@class FBSDKProfilePictureView;

@protocol UICollectionViewSource<UICollectionViewDataSource, UICollectionViewDelegate>
@end

@interface UIViewControllerTransitioningDelegate : NSObject<UIViewControllerTransitioningDelegate> {
}
	-(id) init;
@end

@interface UIViewControllerAnimatedTransitioning : NSObject<UIViewControllerAnimatedTransitioning> {
}
	-(id) init;
@end

@interface UIApplicationDelegate : NSObject<UIApplicationDelegate> {
}
	-(id) init;
@end

@interface CLLocationManagerDelegate : NSObject<CLLocationManagerDelegate> {
}
	-(id) init;
@end

@interface UIImagePickerControllerDelegate : NSObject<UINavigationControllerDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, UINavigationControllerDelegate> {
}
	-(id) init;
@end

@interface UISearchBarDelegate : NSObject<UISearchBarDelegate, UIBarPositioningDelegate> {
}
	-(id) init;
@end

@interface UITableViewSource : NSObject<UIScrollViewDelegate> {
}
	-(id) init;
@end

@interface NSURLConnectionDataDelegate : NSObject<NSURLConnectionDelegate, NSURLConnectionDataDelegate, NSURLConnectionDelegate> {
}
	-(id) init;
@end

@interface Cirlce_IncomingCell : UICollectionViewCell {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface MonoTouch_Dialog_DialogViewController : UITableViewController {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(BOOL) shouldAutorotateToInterfaceOrientation:(NSInteger)p0;
	-(void) didRotateFromInterfaceOrientation:(NSInteger)p0;
	-(void) loadView;
	-(void) viewWillAppear:(BOOL)p0;
	-(void) viewWillDisappear:(BOOL)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface Circle_UserInfoViewController : MonoTouch_Dialog_DialogViewController {
}
	-(void) viewDidAppear:(BOOL)p0;
@end

@interface ChatViewController : UIViewController<UITextFieldDelegate, UICollectionViewDelegateFlowLayout, UICollectionViewDataSource, UICollectionViewDelegate> {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) viewDidLoad;
	-(void) HandleSend;
	-(NSInteger) numberOfSectionsInCollectionView:(UICollectionView *)p0;
	-(CGSize) collectionView:(UICollectionView *)p0 layout:(UICollectionViewLayout *)p1 sizeForItemAtIndexPath:(NSIndexPath *)p2;
	-(NSInteger) collectionView:(UICollectionView *)p0 numberOfItemsInSection:(NSInteger)p1;
	-(UICollectionViewCell *) collectionView:(UICollectionView *)p0 cellForItemAtIndexPath:(NSIndexPath *)p1;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface ProfileViewController : UIViewController {
}
	@property (nonatomic, assign) UIButton * EditButton;
	@property (nonatomic, assign) UILabel * FullName;
	@property (nonatomic, assign) UIImageView * ProfileImageView;
	@property (nonatomic, assign) UIButton * SettingsButton;
	@property (nonatomic, assign) UIView * TopView;
	@property (nonatomic, assign) UILabel * Username;
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIButton *) EditButton;
	-(void) setEditButton:(UIButton *)p0;
	-(UILabel *) FullName;
	-(void) setFullName:(UILabel *)p0;
	-(UIImageView *) ProfileImageView;
	-(void) setProfileImageView:(UIImageView *)p0;
	-(UIButton *) SettingsButton;
	-(void) setSettingsButton:(UIButton *)p0;
	-(UIView *) TopView;
	-(void) setTopView:(UIView *)p0;
	-(UILabel *) Username;
	-(void) setUsername:(UILabel *)p0;
	-(void) viewDidLoad;
	-(void) viewWillAppear:(BOOL)p0;
	-(void) viewWillDisappear:(BOOL)p0;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface WelcomeViewController : UIViewController {
}
	@property (nonatomic, assign) UIButton * LoginBtn;
	@property (nonatomic, assign) UIButton * RegisterBtn;
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIButton *) LoginBtn;
	-(void) setLoginBtn:(UIButton *)p0;
	-(UIButton *) RegisterBtn;
	-(void) setRegisterBtn:(UIButton *)p0;
	-(void) viewDidLoad;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface MainViewController : UIViewController {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) viewDidLoad;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface NearbyViewModel : UIViewController {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) viewDidLoad;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface MessagesViewModel : UIViewController {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) viewDidLoad;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface ProfileViewModel : UIViewController {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) viewDidLoad;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface ProfileViewModelBase : UIViewController {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) viewDidLoad;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface Circle_MainTabBarController : UITabBarController<UIViewControllerTransitioningDelegate, UITabBarControllerDelegate> {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface Circle_NearbyCell : UIView {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface UserViewController : UIViewController {
}
	@property (nonatomic, assign) UIButton * ChatButton;
	@property (nonatomic, assign) UIImageView * ProfileImageView;
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIButton *) ChatButton;
	-(void) setChatButton:(UIButton *)p0;
	-(UIImageView *) ProfileImageView;
	-(void) setProfileImageView:(UIImageView *)p0;
	-(void) viewDidLoad;
	-(void) didReceiveMemoryWarning;
	-(BOOL) hidesBottomBarWhenPushed;
	-(void) setHidesBottomBarWhenPushed:(BOOL)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface Circle_GenericTableViewController_1 : UITableViewController {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) viewDidLoad;
	-(void) didReceiveMemoryWarning;
	-(UITableViewCell *) tableView:(UITableView *)p0 cellForRowAtIndexPath:(NSIndexPath *)p1;
	-(NSInteger) numberOfSectionsInTableView:(UITableView *)p0;
	-(NSInteger) tableView:(UITableView *)p0 numberOfRowsInSection:(NSInteger)p1;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface Circle_OutgoingCell : UICollectionViewCell {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) updateConstraints;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface HomeViewController : UIViewController<UIViewControllerTransitioningDelegate> {
}
	@property (nonatomic, assign) UIButton * Chat;
	@property (nonatomic, assign) UIButton * Groups;
	@property (nonatomic, assign) UIButton * Nearby;
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIButton *) Chat;
	-(void) setChat:(UIButton *)p0;
	-(UIButton *) Groups;
	-(void) setGroups:(UIButton *)p0;
	-(UIButton *) Nearby;
	-(void) setNearby:(UIButton *)p0;
	-(void) viewDidLoad;
	-(void) viewWillLayoutSubviews;
	-(void) didReceiveMemoryWarning;
	-(id) animationControllerForPresentedController:(UIViewController *)p0 presentingController:(UIViewController *)p1 sourceController:(UIViewController *)p2;
	-(id) animationControllerForDismissedController:(UIViewController *)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface Circle_TransitionDelegate : NSObject<UIViewControllerTransitioningDelegate> {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(id) animationControllerForPresentedController:(UIViewController *)p0 presentingController:(UIViewController *)p1 sourceController:(UIViewController *)p2;
	-(id) interactionControllerForDismissal:(id)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface BaseViewController : UIViewController {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) viewDidLoad;
	-(void) viewWillAppear:(BOOL)p0;
	-(void) viewWillDisappear:(BOOL)p0;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface Cirlce_CrossDissolveTransitionAnimator : NSObject<UIViewControllerAnimatedTransitioning> {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(double) transitionDuration:(id)p0;
	-(void) animateTransition:(id)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@protocol FIRMessagingDelegate
	@optional -(void) applicationReceivedRemoteMessage:(id)p0;
	@optional -(void) messaging:(id)p0 didRefreshRegistrationToken:(NSString *)p1;
	@optional -(void) messaging:(id)p0 didReceiveRegistrationToken:(NSString *)p1;
	@optional -(void) messaging:(id)p0 didReceiveMessage:(id)p1;
@end

@interface AppDelegate : NSObject<UNUserNotificationCenterDelegate, FIRMessagingDelegate, UIApplicationDelegate> {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIWindow *) window;
	-(void) setWindow:(UIWindow *)p0;
	-(BOOL) application:(UIApplication *)p0 didFinishLaunchingWithOptions:(NSDictionary *)p1;
	-(void) messaging:(id)p0 didReceiveRegistrationToken:(NSString *)p1;
	-(void) application:(UIApplication *)p0 didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)p1;
	-(void) application:(UIApplication *)p0 didReceiveRemoteNotification:(NSDictionary *)p1 fetchCompletionHandler:(id)p2;
	-(void) messaging:(id)p0 didReceiveMessage:(id)p1;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface Circle_Manager : NSObject<MCNearbyServiceAdvertiserDelegate, MCNearbyServiceBrowserDelegate, MCSessionDelegate> {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) advertiser:(MCNearbyServiceAdvertiser *)p0 didReceiveInvitationFromPeer:(MCPeerID *)p1 withContext:(NSData *)p2 invitationHandler:(id)p3;
	-(void) browser:(MCNearbyServiceBrowser *)p0 foundPeer:(MCPeerID *)p1 withDiscoveryInfo:(NSDictionary *)p2;
	-(void) browser:(MCNearbyServiceBrowser *)p0 lostPeer:(MCPeerID *)p1;
	-(void) session:(MCSession *)p0 peer:(MCPeerID *)p1 didChangeState:(NSInteger)p2;
	-(void) session:(MCSession *)p0 didReceiveData:(NSData *)p1 fromPeer:(MCPeerID *)p2;
	-(void) session:(MCSession *)p0 didStartReceivingResourceWithName:(NSString *)p1 fromPeer:(MCPeerID *)p2 withProgress:(NSProgress *)p3;
	-(void) session:(MCSession *)p0 didFinishReceivingResourceWithName:(NSString *)p1 fromPeer:(MCPeerID *)p2 atURL:(NSURL *)p3 withError:(NSError *)p4;
	-(void) session:(MCSession *)p0 didReceiveStream:(NSInputStream *)p1 withName:(NSString *)p2 fromPeer:(MCPeerID *)p3;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface GroupsViewController : UIViewController<UITableViewDelegate, UITableViewDataSource> {
}
	@property (nonatomic, assign) UITableView * TableView;
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UITableView *) TableView;
	-(void) setTableView:(UITableView *)p0;
	-(void) viewDidLoad;
	-(void) viewWillAppear:(BOOL)p0;
	-(void) viewWillDisappear:(BOOL)p0;
	-(void) didReceiveMemoryWarning;
	-(NSInteger) tableView:(UITableView *)p0 numberOfRowsInSection:(NSInteger)p1;
	-(UITableViewCell *) tableView:(UITableView *)p0 cellForRowAtIndexPath:(NSIndexPath *)p1;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface NearbyViewController : UIViewController {
}
	@property (nonatomic, assign) UIScrollView * ScrollView;
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIScrollView *) ScrollView;
	-(void) setScrollView:(UIScrollView *)p0;
	-(void) viewDidLoad;
	-(void) viewWillAppear:(BOOL)p0;
	-(void) viewWillDisappear:(BOOL)p0;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface RegisterViewController : UIViewController {
}
	@property (nonatomic, assign) UIButton * FacebookButton;
	@property (nonatomic, assign) UILabel * RegisterLabel;
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIButton *) FacebookButton;
	-(void) setFacebookButton:(UIButton *)p0;
	-(UILabel *) RegisterLabel;
	-(void) setRegisterLabel:(UILabel *)p0;
	-(void) viewDidLoad;
	-(void) viewWillAppear:(BOOL)p0;
	-(void) viewWillDisappear:(BOOL)p0;
	-(void) didReceiveMemoryWarning;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface AddGroupViewController : UIViewController {
}
	@property (nonatomic, assign) UIButton * AddButton;
	@property (nonatomic, assign) UITextField * TextField;
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIButton *) AddButton;
	-(void) setAddButton:(UIButton *)p0;
	-(UITextField *) TextField;
	-(void) setTextField:(UITextField *)p0;
	-(void) viewDidLoad;
	-(void) didReceiveMemoryWarning;
	-(void) viewWillAppear:(BOOL)p0;
	-(void) viewWillDisappear:(BOOL)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface Circle_CrossDissolveTransitionAnimator : NSObject<CAAnimationDelegate, UIViewControllerAnimatedTransitioning> {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(double) transitionDuration:(id)p0;
	-(void) animateTransition:(id)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface Circle_CustomPresentationController : UIPresentationController<UIViewControllerTransitioningDelegate, UIViewControllerAnimatedTransitioning> {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIView *) presentedView;
	-(void) presentationTransitionWillBegin;
	-(void) presentationTransitionDidEnd:(BOOL)p0;
	-(void) dismissalTransitionWillBegin;
	-(void) dismissalTransitionDidEnd:(BOOL)p0;
	-(void) preferredContentSizeDidChangeForChildContentContainer:(id)p0;
	-(CGSize) sizeForChildContentContainer:(id)p0 withParentContainerSize:(CGSize)p1;
	-(CGRect) frameOfPresentedViewInContainerView;
	-(void) containerViewWillLayoutSubviews;
	-(double) transitionDuration:(id)p0;
	-(void) animateTransition:(id)p0;
	-(UIPresentationController *) presentationControllerForPresentedViewController:(UIViewController *)p0 presentingViewController:(UIViewController *)p1 sourceViewController:(UIViewController *)p2;
	-(id) animationControllerForPresentedController:(UIViewController *)p0 presentingController:(UIViewController *)p1 sourceController:(UIViewController *)p2;
	-(id) animationControllerForDismissedController:(UIViewController *)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface Circle_SLabzBannerAlert : UIView {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface UIKit_UIView_UIViewAppearance : NSObject {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIColor *) backgroundColor;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface UIKit_UIControl_UIControlAppearance : UIKit_UIView_UIViewAppearance {
}
@end

@interface UIKit_UIButton_UIButtonAppearance : UIKit_UIControl_UIControlAppearance {
}
@end

@interface __UIGestureRecognizerToken : NSObject {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface __UIGestureRecognizerParameterlessToken : __UIGestureRecognizerToken {
}
	-(void) target;
@end

@interface UIKit_UITableViewCell_UITableViewCellAppearance : UIKit_UIView_UIViewAppearance {
}
@end

@interface FIRMessagingMessageInfo : NSObject {
}
	-(NSInteger) status;
	-(id) init;
@end

@interface FIRMessagingDelegate : NSObject<FIRMessagingDelegate> {
}
	-(id) init;
@end

@interface FIRMessagingRemoteMessage : NSObject {
}
	-(NSDictionary *) appData;
@end

@interface FIRMessaging : NSObject {
}
	-(id) appDidReceiveMessage:(NSDictionary *)p0;
	-(void) connectWithCompletion:(id)p0;
	-(void) deleteFCMTokenForSenderID:(NSString *)p0 completion:(id)p1;
	-(void) disconnect;
	-(void) retrieveFCMTokenForSenderID:(NSString *)p0 completion:(id)p1;
	-(void) sendMessage:(NSDictionary *)p0 to:(NSString *)p1 withMessageID:(NSString *)p2 timeToLive:(long long)p3;
	-(void) setAPNSToken:(NSData *)p0 type:(NSInteger)p1;
	-(void) subscribeToTopic:(NSString *)p0;
	-(void) unsubscribeFromTopic:(NSString *)p0;
	-(NSData *) APNSToken;
	-(void) setAPNSToken:(NSData *)p0;
	-(id) delegate;
	-(void) setDelegate:(id)p0;
	-(NSString *) FCMToken;
	-(BOOL) isDirectChannelEstablished;
	-(id) remoteMessageDelegate;
	-(void) setRemoteMessageDelegate:(id)p0;
	-(BOOL) shouldEstablishDirectChannel;
	-(void) setShouldEstablishDirectChannel:(BOOL)p0;
@end

@interface FIRInstanceID : NSObject {
}
	-(void) deleteIDWithHandler:(id)p0;
	-(void) deleteTokenWithAuthorizedEntity:(NSString *)p0 scope:(NSString *)p1 handler:(id)p2;
	-(void) getIDWithHandler:(id)p0;
	-(void) tokenWithAuthorizedEntity:(NSString *)p0 scope:(NSString *)p1 options:(NSDictionary *)p2 handler:(id)p3;
	-(void) setAPNSToken:(NSData *)p0 type:(NSInteger)p1;
	-(NSString *) token;
@end

@interface FIRAnalyticsConfiguration : NSObject {
}
	-(void) setAnalyticsCollectionEnabled:(BOOL)p0;
	-(void) setMinimumSessionInterval:(double)p0;
	-(void) setSessionTimeoutInterval:(double)p0;
@end

@interface FIRApp : NSObject {
}
	-(void) deleteApp:(id)p0;
	-(NSString *) name;
	-(id) options;
@end

@interface FIRConfiguration : NSObject {
}
	-(void) setLoggerLevel:(NSInteger)p0;
	-(id) analyticsConfiguration;
	-(void) setAnalyticsConfiguration:(id)p0;
	-(NSInteger) logLevel;
	-(void) setLogLevel:(NSInteger)p0;
@end

@interface FIROptions : NSObject {
}
	-(NSObject *) copyWithZone:(id)p0;
	-(NSString *) androidClientID;
	-(void) setAndroidClientID:(NSString *)p0;
	-(NSString *) APIKey;
	-(void) setAPIKey:(NSString *)p0;
	-(NSString *) bundleID;
	-(void) setBundleID:(NSString *)p0;
	-(NSString *) clientID;
	-(void) setClientID:(NSString *)p0;
	-(NSString *) databaseURL;
	-(void) setDatabaseURL:(NSString *)p0;
	-(NSString *) deepLinkURLScheme;
	-(void) setDeepLinkURLScheme:(NSString *)p0;
	-(NSString *) GCMSenderID;
	-(void) setGCMSenderID:(NSString *)p0;
	-(NSString *) googleAppID;
	-(void) setGoogleAppID:(NSString *)p0;
	-(NSString *) projectID;
	-(void) setProjectID:(NSString *)p0;
	-(NSString *) storageBucket;
	-(void) setStorageBucket:(NSString *)p0;
	-(NSString *) trackingID;
	-(void) setTrackingID:(NSString *)p0;
	-(id) initWithGoogleAppID:(NSString *)p0 bundleID:(NSString *)p1 GCMSenderID:(NSString *)p2 APIKey:(NSString *)p3 clientID:(NSString *)p4 trackingID:(NSString *)p5 androidClientID:(NSString *)p6 databaseURL:(NSString *)p7 storageBucket:(NSString *)p8 deepLinkURLScheme:(NSString *)p9;
	-(id) initWithContentsOfFile:(NSString *)p0;
	-(id) initWithGoogleAppID:(NSString *)p0 GCMSenderID:(NSString *)p1;
@end

@interface FIRAnalytics : NSObject {
}
	-(NSString *) appInstanceID;
	-(id) init;
@end

@interface FIRDatabaseQuery : NSObject {
}
	-(id) queryEndingAtValue:(NSObject *)p0;
	-(id) queryEndingAtValue:(NSObject *)p0 childKey:(NSString *)p1;
	-(id) queryEqualToValue:(NSObject *)p0;
	-(id) queryEqualToValue:(NSObject *)p0 childKey:(NSString *)p1;
	-(id) queryLimitedToFirst:(NSUInteger)p0;
	-(id) queryLimitedToLast:(NSUInteger)p0;
	-(id) queryOrderedByChild:(NSString *)p0;
	-(id) queryOrderedByKey;
	-(id) queryOrderedByPriority;
	-(id) queryOrderedByValue;
	-(id) queryStartingAtValue:(NSObject *)p0;
	-(id) queryStartingAtValue:(NSObject *)p0 childKey:(NSString *)p1;
	-(void) keepSynced:(BOOL)p0;
	-(NSUInteger) observeEventType:(NSInteger)p0 withBlock:(id)p1;
	-(NSUInteger) observeEventType:(NSInteger)p0 andPreviousSiblingKeyWithBlock:(id)p1;
	-(NSUInteger) observeEventType:(NSInteger)p0 withBlock:(id)p1 withCancelBlock:(id)p2;
	-(NSUInteger) observeEventType:(NSInteger)p0 andPreviousSiblingKeyWithBlock:(id)p1 withCancelBlock:(id)p2;
	-(void) observeSingleEventOfType:(NSInteger)p0 withBlock:(id)p1;
	-(void) observeSingleEventOfType:(NSInteger)p0 andPreviousSiblingKeyWithBlock:(id)p1;
	-(void) observeSingleEventOfType:(NSInteger)p0 withBlock:(id)p1 withCancelBlock:(id)p2;
	-(void) observeSingleEventOfType:(NSInteger)p0 andPreviousSiblingKeyWithBlock:(id)p1 withCancelBlock:(id)p2;
	-(void) removeAllObservers;
	-(void) removeObserverWithHandle:(NSUInteger)p0;
	-(id) ref;
	-(id) init;
@end

@interface FIRDatabaseReference : FIRDatabaseQuery {
}
	-(void) cancelDisconnectOperations;
	-(void) cancelDisconnectOperationsWithCompletionBlock:(id)p0;
	-(id) child:(NSString *)p0;
	-(id) childByAppendingPath:(NSString *)p0;
	-(id) childByAutoId;
	-(id) queryEndingAtValue:(NSObject *)p0;
	-(id) queryEndingAtValue:(NSObject *)p0 childKey:(NSString *)p1;
	-(id) queryEqualToValue:(NSObject *)p0;
	-(id) queryEqualToValue:(NSObject *)p0 childKey:(NSString *)p1;
	-(id) queryLimitedToFirst:(NSUInteger)p0;
	-(id) queryLimitedToLast:(NSUInteger)p0;
	-(id) queryOrderedByChild:(NSString *)p0;
	-(id) queryOrderedByKey;
	-(id) queryOrderedByPriority;
	-(id) queryStartingAtValue:(NSObject *)p0;
	-(id) queryStartingAtValue:(NSObject *)p0 childKey:(NSString *)p1;
	-(void) keepSynced:(BOOL)p0;
	-(NSUInteger) observeEventType:(NSInteger)p0 withBlock:(id)p1;
	-(NSUInteger) observeEventType:(NSInteger)p0 andPreviousSiblingKeyWithBlock:(id)p1;
	-(NSUInteger) observeEventType:(NSInteger)p0 withBlock:(id)p1 withCancelBlock:(id)p2;
	-(NSUInteger) observeEventType:(NSInteger)p0 andPreviousSiblingKeyWithBlock:(id)p1 withCancelBlock:(id)p2;
	-(void) observeSingleEventOfType:(NSInteger)p0 withBlock:(id)p1;
	-(void) observeSingleEventOfType:(NSInteger)p0 andPreviousSiblingKeyWithBlock:(id)p1;
	-(void) observeSingleEventOfType:(NSInteger)p0 withBlock:(id)p1 withCancelBlock:(id)p2;
	-(void) observeSingleEventOfType:(NSInteger)p0 andPreviousSiblingKeyWithBlock:(id)p1 withCancelBlock:(id)p2;
	-(void) removeAllObservers;
	-(void) removeObserverWithHandle:(NSUInteger)p0;
	-(void) removeValue;
	-(void) removeValueWithCompletionBlock:(id)p0;
	-(void) onDisconnectRemoveValue;
	-(void) onDisconnectRemoveValueWithCompletionBlock:(id)p0;
	-(void) runTransactionBlock:(id)p0;
	-(void) runTransactionBlock:(id)p0 andCompletionBlock:(id)p1;
	-(void) runTransactionBlock:(id)p0 andCompletionBlock:(id)p1 withLocalEvents:(BOOL)p2;
	-(void) setPriority:(NSObject *)p0;
	-(void) setPriority:(NSObject *)p0 withCompletionBlock:(id)p1;
	-(void) updateChildValues:(NSDictionary *)p0;
	-(void) updateChildValues:(NSDictionary *)p0 withCompletionBlock:(id)p1;
	-(void) onDisconnectUpdateChildValues:(NSDictionary *)p0;
	-(void) onDisconnectUpdateChildValues:(NSDictionary *)p0 withCompletionBlock:(id)p1;
	-(void) setValue:(NSObject *)p0;
	-(void) setValue:(NSObject *)p0 withCompletionBlock:(id)p1;
	-(void) setValue:(NSObject *)p0 andPriority:(NSObject *)p1;
	-(void) setValue:(NSObject *)p0 andPriority:(NSObject *)p1 withCompletionBlock:(id)p2;
	-(void) onDisconnectSetValue:(NSObject *)p0;
	-(void) onDisconnectSetValue:(NSObject *)p0 withCompletionBlock:(id)p1;
	-(void) onDisconnectSetValue:(NSObject *)p0 andPriority:(NSObject *)p1;
	-(void) onDisconnectSetValue:(NSObject *)p0 andPriority:(NSObject *)p1 withCompletionBlock:(id)p2;
	-(id) database;
	-(NSString *) description;
	-(NSString *) key;
	-(id) parent;
	-(id) root;
	-(NSString *) URL;
	-(id) init;
@end

@interface FIRDataSnapshot : NSObject {
}
	-(id) childSnapshotForPath:(NSString *)p0;
	-(BOOL) hasChild:(NSString *)p0;
	-(NSEnumerator *) children;
	-(NSUInteger) childrenCount;
	-(BOOL) exists;
	-(BOOL) hasChildren;
	-(NSString *) key;
	-(NSObject *) priority;
	-(id) ref;
	-(NSObject *) valueInExportFormat;
	-(void *) value;
	-(id) init;
@end

@interface FIRMutableData : NSObject {
}
	-(id) childDataByAppendingPath:(NSString *)p0;
	-(BOOL) hasChildAtPath:(NSString *)p0;
	-(NSEnumerator *) children;
	-(NSUInteger) childrenCount;
	-(BOOL) hasChildren;
	-(NSString *) key;
	-(NSObject *) priority;
	-(void) setPriority:(NSObject *)p0;
	-(void *) value;
	-(void) setValue:(void *)p0;
	-(id) init;
@end

@interface FIRDatabase : NSObject {
}
	-(id) referenceWithPath:(NSString *)p0;
	-(id) referenceFromURL:(NSString *)p0;
	-(id) reference;
	-(void) goOffline;
	-(void) goOnline;
	-(void) purgeOutstandingWrites;
	-(id) app;
	-(id) callbackQueue;
	-(void) setCallbackQueue:(id)p0;
	-(NSUInteger) persistenceCacheSizeBytes;
	-(void) setPersistenceCacheSizeBytes:(NSUInteger)p0;
	-(BOOL) persistenceEnabled;
	-(void) setPersistenceEnabled:(BOOL)p0;
@end

@interface FIRServerValue : NSObject {
}
@end

@interface FIRTransactionResult : NSObject {
}
@end

@interface FIRActionCodeInfo : NSObject {
}
	-(NSString *) dataForKey:(NSInteger)p0;
	-(NSInteger) operation;
@end

@interface FIRActionCodeSettings : NSObject {
}
	-(void) setAndroidPackageName:(NSString *)p0 installIfNotAvailable:(BOOL)p1 minimumVersion:(NSString *)p2;
	-(BOOL) androidInstallIfNotAvailable;
	-(NSString *) androidMinimumVersion;
	-(NSString *) androidPackageName;
	-(BOOL) handleCodeInApp;
	-(void) setHandleCodeInApp:(BOOL)p0;
	-(NSString *) iOSBundleID;
	-(void) setIOSBundleID:(NSString *)p0;
	-(NSURL *) URL;
	-(void) setURL:(NSURL *)p0;
	-(id) init;
@end

@interface FIRAdditionalUserInfo : NSObject {
}
	-(BOOL) isNewUser;
	-(NSDictionary <NSString *, NSObject *>*) profile;
	-(NSString *) providerID;
	-(NSString *) username;
@end

@interface FIRAuthCredential : NSObject {
}
	-(NSString *) provider;
@end

@interface FIRAuthDataResult : NSObject {
}
	-(id) additionalUserInfo;
	-(id) user;
@end

@protocol FIRAuthUIDelegate
	@required -(void) presentViewController:(UIViewController *)p0 animated:(BOOL)p1 completion:(id)p2;
	@required -(void) dismissViewControllerAnimated:(BOOL)p0 completion:(id)p1;
@end

@interface FIRAuthUIDelegate : NSObject<FIRAuthUIDelegate> {
}
	-(id) init;
@end

@interface FIREmailAuthProvider : NSObject {
}
@end

@interface FIRFacebookAuthProvider : NSObject {
}
@end

@interface FIRGitHubAuthProvider : NSObject {
}
@end

@interface FIRGoogleAuthProvider : NSObject {
}
@end

@interface FIROAuthProvider : NSObject {
}
@end

@interface FIRPhoneAuthCredential : FIRAuthCredential {
}
@end

@interface FIRTwitterAuthProvider : NSObject {
}
@end

@protocol FIRUserInfo
	@required @property (nonatomic, assign, readonly) NSString * uid;
	@required @property (nonatomic, assign, readonly) NSString * displayName;
	@required @property (nonatomic, assign, readonly) NSString * email;
	@required @property (nonatomic, assign, readonly) NSString * providerID;
	@required @property (nonatomic, assign, readonly) NSString * phoneNumber;
	@required @property (nonatomic, copy, readonly) NSURL * photoURL;
@end

@interface FIRUserMetadata : NSObject {
}
	-(NSDate *) creationDate;
	-(NSDate *) lastSignInDate;
@end

@interface FIRAuth : NSObject {
}
	-(NSObject *) addAuthStateDidChangeListener:(id)p0;
	-(NSObject *) addIDTokenDidChangeListener:(id)p0;
	-(void) applyActionCode:(NSString *)p0 completion:(id)p1;
	-(BOOL) canHandleNotification:(NSDictionary *)p0;
	-(BOOL) canHandleURL:(NSURL *)p0;
	-(void) checkActionCode:(NSString *)p0 completion:(id)p1;
	-(void) confirmPasswordResetWithCode:(NSString *)p0 newPassword:(NSString *)p1 completion:(id)p2;
	-(void) createUserWithEmail:(NSString *)p0 password:(NSString *)p1 completion:(id)p2;
	-(void) createUserAndRetrieveDataWithEmail:(NSString *)p0 password:(NSString *)p1 completion:(id)p2;
	-(void) fetchProvidersForEmail:(NSString *)p0 completion:(id)p1;
	-(void) removeAuthStateDidChangeListener:(NSObject *)p0;
	-(void) removeIDTokenDidChangeListener:(NSObject *)p0;
	-(void) sendPasswordResetWithEmail:(NSString *)p0 completion:(id)p1;
	-(void) sendPasswordResetWithEmail:(NSString *)p0 actionCodeSettings:(id)p1 completion:(id)p2;
	-(void) setAPNSToken:(NSData *)p0 type:(NSInteger)p1;
	-(void) signInWithEmail:(NSString *)p0 password:(NSString *)p1 completion:(id)p2;
	-(void) signInWithCredential:(id)p0 completion:(id)p1;
	-(void) signInWithCustomToken:(NSString *)p0 completion:(id)p1;
	-(void) signInAndRetrieveDataWithEmail:(NSString *)p0 password:(NSString *)p1 completion:(id)p2;
	-(void) signInAndRetrieveDataWithCredential:(id)p0 completion:(id)p1;
	-(void) signInAndRetrieveDataWithCustomToken:(NSString *)p0 completion:(id)p1;
	-(void) signInAnonymouslyWithCompletion:(id)p0;
	-(void) signInAnonymouslyAndRetrieveDataWithCompletion:(id)p0;
	-(BOOL) signOut:(NSError **)p0;
	-(void) useAppLanguage;
	-(void) verifyPasswordResetCode:(NSString *)p0 completion:(id)p1;
	-(NSData *) APNSToken;
	-(void) setAPNSToken:(NSData *)p0;
	-(id) app;
	-(id) currentUser;
	-(NSString *) languageCode;
	-(void) setLanguageCode:(NSString *)p0;
@end

@interface FIRPhoneAuthProvider : NSObject {
}
	-(id) credentialWithVerificationID:(NSString *)p0 verificationCode:(NSString *)p1;
	-(void) verifyPhoneNumber:(NSString *)p0 completion:(id)p1;
	-(void) verifyPhoneNumber:(NSString *)p0 UIDelegate:(id)p1 completion:(id)p2;
@end

@interface FIRUser : NSObject {
}
	-(void) deleteWithCompletion:(id)p0;
	-(void) getIDTokenWithCompletion:(id)p0;
	-(void) getIDTokenForcingRefresh:(BOOL)p0 completion:(id)p1;
	-(void) getTokenWithCompletion:(id)p0;
	-(void) getTokenForcingRefresh:(BOOL)p0 completion:(id)p1;
	-(void) linkWithCredential:(id)p0 completion:(id)p1;
	-(void) linkAndRetrieveDataWithCredential:(id)p0 completion:(id)p1;
	-(id) profileChangeRequest;
	-(void) reauthenticateWithCredential:(id)p0 completion:(id)p1;
	-(void) reauthenticateAndRetrieveDataWithCredential:(id)p0 completion:(id)p1;
	-(void) reloadWithCompletion:(id)p0;
	-(void) sendEmailVerificationWithCompletion:(id)p0;
	-(void) sendEmailVerificationWithActionCodeSettings:(id)p0 completion:(id)p1;
	-(void) unlinkFromProvider:(NSString *)p0 completion:(id)p1;
	-(void) updateEmail:(NSString *)p0 completion:(id)p1;
	-(void) updatePassword:(NSString *)p0 completion:(id)p1;
	-(void) updatePhoneNumberCredential:(id)p0 completion:(id)p1;
	-(NSString *) displayName;
	-(NSString *) email;
	-(BOOL) isAnonymous;
	-(BOOL) isEmailVerified;
	-(id) metadata;
	-(NSString *) phoneNumber;
	-(NSURL *) photoURL;
	-(NSArray *) providerData;
	-(NSString *) providerID;
	-(NSString *) refreshToken;
	-(NSString *) uid;
@end

@interface FIRUserProfileChangeRequest : NSObject {
}
	-(void) commitChangesWithCompletion:(id)p0;
	-(NSString *) displayName;
	-(void) setDisplayName:(NSString *)p0;
	-(NSURL *) photoURL;
	-(void) setPhotoURL:(NSURL *)p0;
@end

@interface MonoTouch_Dialog_MessageSummaryView : UIView {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) drawRect:(CGRect)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
	-(id) init;
@end

@interface MonoTouch_Dialog_RefreshTableHeaderView : UIView {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) layoutSubviews;
	-(void) drawRect:(CGRect)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface MonoTouch_Dialog_GlassButton : UIButton {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(BOOL) isEnabled;
	-(void) setEnabled:(BOOL)p0;
	-(BOOL) beginTrackingWithTouch:(UITouch *)p0 withEvent:(UIEvent *)p1;
	-(void) endTrackingWithTouch:(UITouch *)p0 withEvent:(UIEvent *)p1;
	-(BOOL) continueTrackingWithTouch:(UITouch *)p0 withEvent:(UIEvent *)p1;
	-(void) drawRect:(CGRect)p0;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface MonoTouch_Dialog_BaseBooleanImageElement_TextWithImageCellView : UITableViewCell {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) layoutSubviews;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface MonoTouch_Dialog_DialogViewController_Source : NSObject<UIScrollViewDelegate> {
}
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(void) tableView:(UITableView *)p0 accessoryButtonTappedForRowWithIndexPath:(NSIndexPath *)p1;
	-(NSInteger) tableView:(UITableView *)p0 numberOfRowsInSection:(NSInteger)p1;
	-(NSInteger) numberOfSectionsInTableView:(UITableView *)p0;
	-(NSString *) tableView:(UITableView *)p0 titleForHeaderInSection:(NSInteger)p1;
	-(NSString *) tableView:(UITableView *)p0 titleForFooterInSection:(NSInteger)p1;
	-(UITableViewCell *) tableView:(UITableView *)p0 cellForRowAtIndexPath:(NSIndexPath *)p1;
	-(void) tableView:(UITableView *)p0 willDisplayCell:(UITableViewCell *)p1 forRowAtIndexPath:(NSIndexPath *)p2;
	-(void) tableView:(UITableView *)p0 didDeselectRowAtIndexPath:(NSIndexPath *)p1;
	-(void) tableView:(UITableView *)p0 didSelectRowAtIndexPath:(NSIndexPath *)p1;
	-(UIView *) tableView:(UITableView *)p0 viewForHeaderInSection:(NSInteger)p1;
	-(CGFloat) tableView:(UITableView *)p0 heightForHeaderInSection:(NSInteger)p1;
	-(UIView *) tableView:(UITableView *)p0 viewForFooterInSection:(NSInteger)p1;
	-(CGFloat) tableView:(UITableView *)p0 heightForFooterInSection:(NSInteger)p1;
	-(void) scrollViewDidScroll:(UIScrollView *)p0;
	-(void) scrollViewWillBeginDragging:(UIScrollView *)p0;
	-(void) scrollViewDidEndDragging:(UIScrollView *)p0 willDecelerate:(BOOL)p1;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@interface MonoTouch_Dialog_DialogViewController_SizingSource : MonoTouch_Dialog_DialogViewController_Source<UIScrollViewDelegate> {
}
	-(CGFloat) tableView:(UITableView *)p0 heightForRowAtIndexPath:(NSIndexPath *)p1;
@end

@interface FloatLabeledTextField : UITextField {
}
	@property (nonatomic, assign) UIColor * FloatingLabelTextColor;
	@property (nonatomic, assign) UIColor * FloatingLabelActiveTextColor;
	-(void) release;
	-(id) retain;
	-(int) xamarinGetGCHandle;
	-(void) xamarinSetGCHandle: (int) gchandle;
	-(UIColor *) FloatingLabelTextColor;
	-(void) setFloatingLabelTextColor:(UIColor *)p0;
	-(UIColor *) FloatingLabelActiveTextColor;
	-(void) setFloatingLabelActiveTextColor:(UIColor *)p0;
	-(void) awakeFromNib;
	-(NSString *) placeholder;
	-(void) setPlaceholder:(NSString *)p0;
	-(CGRect) textRectForBounds:(CGRect)p0;
	-(CGRect) editingRectForBounds:(CGRect)p0;
	-(CGRect) clearButtonRectForBounds:(CGRect)p0;
	-(void) layoutSubviews;
	-(BOOL) conformsToProtocol:(void *)p0;
@end

@protocol FBSDKAppGroupAddDialogDelegate
	@required -(void) appGroupAddDialog:(id)p0 didCompleteWithResults:(NSDictionary *)p1;
	@required -(void) appGroupAddDialog:(id)p0 didFailWithError:(NSError *)p1;
	@required -(void) appGroupAddDialogDidCancel:(id)p0;
@end

@interface FBSDKAppGroupAddDialogDelegate : NSObject<FBSDKAppGroupAddDialogDelegate> {
}
	-(id) init;
@end

@protocol FBSDKCopying
	@required -(NSObject *) copy;
@end

@interface FBSDKAppGroupContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(BOOL) isEqualToAppGroupContent:(id)p0;
	-(NSString *) groupDescription;
	-(void) setGroupDescription:(NSString *)p0;
	-(NSString *) name;
	-(void) setName:(NSString *)p0;
	-(NSUInteger) privacy;
	-(void) setPrivacy:(NSUInteger)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@protocol FBSDKAppGroupJoinDialogDelegate
	@required -(void) appGroupJoinDialog:(id)p0 didCompleteWithResults:(NSDictionary *)p1;
	@required -(void) appGroupJoinDialog:(id)p0 didFailWithError:(NSError *)p1;
	@required -(void) appGroupJoinDialogDidCancel:(id)p0;
@end

@interface FBSDKAppGroupJoinDialogDelegate : NSObject<FBSDKAppGroupJoinDialogDelegate> {
}
	-(id) init;
@end

@interface FBSDKAppInviteContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(BOOL) isEqualToAppInviteContent:(id)p0;
	-(NSURL *) appLinkURL;
	-(void) setAppLinkURL:(NSURL *)p0;
	-(NSUInteger) destination;
	-(void) setDestination:(NSUInteger)p0;
	-(NSURL *) appInvitePreviewImageURL;
	-(void) setAppInvitePreviewImageURL:(NSURL *)p0;
	-(NSString *) promotionCode;
	-(void) setPromotionCode:(NSString *)p0;
	-(NSString *) promotionText;
	-(void) setPromotionText:(NSString *)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@protocol FBSDKAppInviteDialogDelegate
	@required -(void) appInviteDialog:(id)p0 didCompleteWithResults:(NSDictionary *)p1;
	@required -(void) appInviteDialog:(id)p0 didFailWithError:(NSError *)p1;
@end

@interface FBSDKAppInviteDialogDelegate : NSObject<FBSDKAppInviteDialogDelegate> {
}
	-(id) init;
@end

@interface FBSDKCameraEffectArguments : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(NSArray *) arrayForKey:(NSString *)p0;
	-(NSString *) stringForKey:(NSString *)p0;
	-(void) setArray:(NSArray *)p0 forKey:(NSString *)p1;
	-(void) setString:(NSString *)p0 forKey:(NSString *)p1;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKCameraEffectTextures : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(UIImage *) imageForKey:(NSString *)p0;
	-(void) setImage:(UIImage *)p0 forKey:(NSString *)p1;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKGameRequestContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(BOOL) isEqualToGameRequestContent:(id)p0;
	-(NSUInteger) actionType;
	-(void) setActionType:(NSUInteger)p0;
	-(NSString *) data;
	-(void) setData:(NSString *)p0;
	-(NSUInteger) filters;
	-(void) setFilters:(NSUInteger)p0;
	-(NSString *) message;
	-(void) setMessage:(NSString *)p0;
	-(NSString *) objectID;
	-(void) setObjectID:(NSString *)p0;
	-(NSArray *) recipientSuggestions;
	-(void) setRecipientSuggestions:(NSArray *)p0;
	-(NSArray *) recipients;
	-(void) setRecipients:(NSArray *)p0;
	-(NSArray *) suggestions;
	-(void) setSuggestions:(NSArray *)p0;
	-(NSString *) title;
	-(void) setTitle:(NSString *)p0;
	-(NSArray *) to;
	-(void) setTo:(NSArray *)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@protocol FBSDKGameRequestDialogDelegate
	@required -(void) gameRequestDialog:(id)p0 didCompleteWithResults:(NSDictionary *)p1;
	@required -(void) gameRequestDialog:(id)p0 didFailWithError:(NSError *)p1;
	@required -(void) gameRequestDialogDidCancel:(id)p0;
@end

@interface FBSDKGameRequestDialogDelegate : NSObject<FBSDKGameRequestDialogDelegate> {
}
	-(id) init;
@end

@interface FBSDKHashtag : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(BOOL) isEqualToHashtag:(id)p0;
	-(NSString *) stringRepresentation;
	-(void) setStringRepresentation:(NSString *)p0;
	-(BOOL) isValid;
	-(void) setValid:(BOOL)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@protocol FBSDKLiking
	@optional -(NSString *) objectID;
	@optional -(void) setObjectID:(NSString *)p0;
	@optional -(NSUInteger) objectType;
	@optional -(void) setObjectType:(NSUInteger)p0;
@end

@interface FBSDKLiking : NSObject<FBSDKLiking> {
}
	-(id) init;
@end

@protocol FBSDKSharing
	@optional -(id) delegate;
	@optional -(void) setDelegate:(id)p0;
	@optional -(id) shareContent;
	@optional -(void) setShareContent:(id)p0;
	@optional -(BOOL) shouldFailOnDataError;
	@optional -(void) setShouldFailOnDataError:(BOOL)p0;
	@optional -(BOOL) validateWithError:(NSError **)p0;
@end

@protocol FBSDKSharingDialog
	@required -(BOOL) canShow;
	@required -(BOOL) show;
@end

@interface FBSDKMessageDialog : NSObject {
}
	-(BOOL) canShow;
	-(id) delegate;
	-(id) shareContent;
	-(BOOL) shouldFailOnDataError;
	-(void) setDelegate:(id)p0;
	-(void) setShareContent:(id)p0;
	-(void) setShouldFailOnDataError:(BOOL)p0;
	-(BOOL) show;
	-(BOOL) validateWithError:(NSError **)p0;
@end

@interface FBSDKShareAPI : NSObject {
}
	-(BOOL) canShare;
	-(BOOL) createOpenGraphObject:(id)p0;
	-(id) delegate;
	-(id) shareContent;
	-(BOOL) shouldFailOnDataError;
	-(void) setDelegate:(id)p0;
	-(void) setShareContent:(id)p0;
	-(void) setShouldFailOnDataError:(BOOL)p0;
	-(BOOL) share;
	-(BOOL) validateWithError:(NSError **)p0;
	-(id) accessToken;
	-(void) setAccessToken:(id)p0;
	-(NSString *) graphNode;
	-(void) setGraphNode:(NSString *)p0;
	-(NSString *) message;
	-(void) setMessage:(NSString *)p0;
@end

@protocol FBSDKSharingContent
	@required @property (nonatomic, copy) id hashtag;
	@required @property (nonatomic, assign) NSString * pageID;
	@required @property (nonatomic, assign, readonly) NSString * shareUUID;
	@required -(NSURL *) contentURL;
	@required -(void) setContentURL:(NSURL *)p0;
	@required -(NSArray *) peopleIDs;
	@required -(void) setPeopleIDs:(NSArray *)p0;
	@required -(NSString *) placeID;
	@required -(void) setPlaceID:(NSString *)p0;
	@required -(NSString *) ref;
	@required -(void) setRef:(NSString *)p0;
@end

@interface FBSDKShareCameraEffectContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(BOOL) isEqualToShareCameraEffectContent:(id)p0;
	-(NSURL *) contentURL;
	-(NSArray *) peopleIDs;
	-(NSString *) placeID;
	-(NSString *) ref;
	-(void) setContentURL:(NSURL *)p0;
	-(void) setPeopleIDs:(NSArray *)p0;
	-(void) setPlaceID:(NSString *)p0;
	-(void) setRef:(NSString *)p0;
	-(id) effectArguments;
	-(void) setEffectArguments:(id)p0;
	-(NSString *) effectID;
	-(void) setEffectID:(NSString *)p0;
	-(id) effectTextures;
	-(void) setEffectTextures:(id)p0;
	-(id) hashtag;
	-(void) setHashtag:(id)p0;
	-(NSString *) pageID;
	-(void) setPageID:(NSString *)p0;
	-(NSString *) shareUUID;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareDialog : NSObject {
}
	-(BOOL) canShow;
	-(id) delegate;
	-(id) shareContent;
	-(BOOL) shouldFailOnDataError;
	-(void) setDelegate:(id)p0;
	-(void) setShareContent:(id)p0;
	-(void) setShouldFailOnDataError:(BOOL)p0;
	-(BOOL) show;
	-(BOOL) validateWithError:(NSError **)p0;
	-(UIViewController *) fromViewController;
	-(void) setFromViewController:(UIViewController *)p0;
	-(NSUInteger) mode;
	-(void) setMode:(NSUInteger)p0;
	-(id) init;
@end

@interface FBSDKShareLinkContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(NSURL *) contentURL;
	-(NSArray *) peopleIDs;
	-(NSString *) placeID;
	-(NSString *) ref;
	-(BOOL) isEqualToShareLinkContent:(id)p0;
	-(void) setContentURL:(NSURL *)p0;
	-(void) setPeopleIDs:(NSArray *)p0;
	-(void) setPlaceID:(NSString *)p0;
	-(void) setRef:(NSString *)p0;
	-(NSString *) contentDescription;
	-(NSString *) contentTitle;
	-(id) hashtag;
	-(void) setHashtag:(id)p0;
	-(NSURL *) imageURL;
	-(NSString *) pageID;
	-(void) setPageID:(NSString *)p0;
	-(NSString *) quote;
	-(void) setQuote:(NSString *)p0;
	-(NSString *) shareUUID;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareMediaContent : NSObject {
}
	-(BOOL) isEqualToShareMediaContent:(id)p0;
	-(NSArray *) media;
	-(void) setMedia:(NSArray *)p0;
	-(id) init;
@end

@protocol FBSDKShareMessengerActionButton
	@required @property (nonatomic, assign) NSString * title;
@end

@interface FBSDKShareMessengerGenericTemplateContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(NSURL *) contentURL;
	-(NSArray *) peopleIDs;
	-(NSString *) placeID;
	-(NSString *) ref;
	-(void) setContentURL:(NSURL *)p0;
	-(void) setPeopleIDs:(NSArray *)p0;
	-(void) setPlaceID:(NSString *)p0;
	-(void) setRef:(NSString *)p0;
	-(id) element;
	-(void) setElement:(id)p0;
	-(id) hashtag;
	-(void) setHashtag:(id)p0;
	-(NSUInteger) imageAspectRatio;
	-(void) setImageAspectRatio:(NSUInteger)p0;
	-(BOOL) isSharable;
	-(void) setIsSharable:(BOOL)p0;
	-(NSString *) pageID;
	-(void) setPageID:(NSString *)p0;
	-(NSString *) shareUUID;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareMessengerGenericTemplateElement : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(id) button;
	-(void) setButton:(id)p0;
	-(id) defaultAction;
	-(void) setDefaultAction:(id)p0;
	-(NSURL *) imageURL;
	-(void) setImageURL:(NSURL *)p0;
	-(NSString *) subtitle;
	-(void) setSubtitle:(NSString *)p0;
	-(NSString *) title;
	-(void) setTitle:(NSString *)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareMessengerMediaTemplateContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(NSURL *) contentURL;
	-(NSArray *) peopleIDs;
	-(NSString *) placeID;
	-(NSString *) ref;
	-(void) setContentURL:(NSURL *)p0;
	-(void) setPeopleIDs:(NSArray *)p0;
	-(void) setPlaceID:(NSString *)p0;
	-(void) setRef:(NSString *)p0;
	-(NSString *) attachmentID;
	-(id) button;
	-(void) setButton:(id)p0;
	-(id) hashtag;
	-(void) setHashtag:(id)p0;
	-(NSUInteger) mediaType;
	-(void) setMediaType:(NSUInteger)p0;
	-(NSURL *) mediaURL;
	-(NSString *) pageID;
	-(void) setPageID:(NSString *)p0;
	-(NSString *) shareUUID;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithAttachmentID:(NSString *)p0;
	-(id) initWithMediaURL:(NSURL *)p0;
@end

@interface FBSDKShareMessengerOpenGraphMusicTemplateContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(NSURL *) contentURL;
	-(NSArray *) peopleIDs;
	-(NSString *) placeID;
	-(NSString *) ref;
	-(void) setContentURL:(NSURL *)p0;
	-(void) setPeopleIDs:(NSArray *)p0;
	-(void) setPlaceID:(NSString *)p0;
	-(void) setRef:(NSString *)p0;
	-(id) button;
	-(void) setButton:(id)p0;
	-(id) hashtag;
	-(void) setHashtag:(id)p0;
	-(NSString *) pageID;
	-(void) setPageID:(NSString *)p0;
	-(NSString *) shareUUID;
	-(NSURL *) url;
	-(void) setUrl:(NSURL *)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareMessengerURLActionButton : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(NSURL *) fallbackURL;
	-(void) setFallbackURL:(NSURL *)p0;
	-(BOOL) isMessengerExtensionURL;
	-(void) setIsMessengerExtensionURL:(BOOL)p0;
	-(BOOL) shouldHideWebviewShareButton;
	-(void) setShouldHideWebviewShareButton:(BOOL)p0;
	-(NSString *) title;
	-(void) setTitle:(NSString *)p0;
	-(NSURL *) url;
	-(void) setUrl:(NSURL *)p0;
	-(NSUInteger) webviewHeightRatio;
	-(void) setWebviewHeightRatio:(NSUInteger)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@protocol FBSDKShareOpenGraphValueContaining
	@required -(NSArray *) arrayForKey:(NSString *)p0;
	@required -(void) enumerateKeysAndObjectsUsingBlock:(id)p0;
	@required -(NSEnumerator *) keyEnumerator;
	@required -(NSNumber *) numberForKey:(NSString *)p0;
	@required -(NSEnumerator *) objectEnumerator;
	@required -(id) objectForKey:(NSString *)p0;
	@required -(NSObject *) objectForKeyedSubscript:(NSString *)p0;
	@required -(void) parseProperties:(NSDictionary *)p0;
	@required -(id) photoForKey:(NSString *)p0;
	@required -(void) removeObjectForKey:(NSString *)p0;
	@required -(void) setArray:(NSArray *)p0 forKey:(NSString *)p1;
	@required -(void) setNumber:(NSNumber *)p0 forKey:(NSString *)p1;
	@required -(void) setObject:(id)p0 forKey:(NSString *)p1;
	@required -(void) setPhoto:(id)p0 forKey:(NSString *)p1;
	@required -(void) setString:(NSString *)p0 forKey:(NSString *)p1;
	@required -(void) setURL:(NSURL *)p0 forKey:(NSString *)p1;
	@required -(NSString *) stringForKey:(NSString *)p0;
	@required -(NSURL *) URLForKey:(NSString *)p0;
@end

@interface FBSDKShareOpenGraphValueContainer : NSObject {
}
	-(NSArray *) arrayForKey:(NSString *)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(void) enumerateKeysAndObjectsUsingBlock:(id)p0;
	-(NSString *) stringForKey:(NSString *)p0;
	-(NSURL *) URLForKey:(NSString *)p0;
	-(NSEnumerator *) keyEnumerator;
	-(NSNumber *) numberForKey:(NSString *)p0;
	-(NSEnumerator *) objectEnumerator;
	-(id) objectForKey:(NSString *)p0;
	-(NSObject *) objectForKeyedSubscript:(NSString *)p0;
	-(void) parseProperties:(NSDictionary *)p0;
	-(id) photoForKey:(NSString *)p0;
	-(void) removeObjectForKey:(NSString *)p0;
	-(void) setArray:(NSArray *)p0 forKey:(NSString *)p1;
	-(void) setNumber:(NSNumber *)p0 forKey:(NSString *)p1;
	-(void) setObject:(id)p0 forKey:(NSString *)p1;
	-(void) setPhoto:(id)p0 forKey:(NSString *)p1;
	-(void) setString:(NSString *)p0 forKey:(NSString *)p1;
	-(void) setURL:(NSURL *)p0 forKey:(NSString *)p1;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareOpenGraphAction : FBSDKShareOpenGraphValueContainer {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(BOOL) isEqualToShareOpenGraphAction:(id)p0;
	-(NSString *) actionType;
	-(void) setActionType:(NSString *)p0;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareOpenGraphContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(NSURL *) contentURL;
	-(NSArray *) peopleIDs;
	-(NSString *) placeID;
	-(NSString *) ref;
	-(BOOL) isEqualToShareOpenGraphContent:(id)p0;
	-(void) setContentURL:(NSURL *)p0;
	-(void) setPeopleIDs:(NSArray *)p0;
	-(void) setPlaceID:(NSString *)p0;
	-(void) setRef:(NSString *)p0;
	-(id) action;
	-(void) setAction:(id)p0;
	-(id) hashtag;
	-(void) setHashtag:(id)p0;
	-(NSString *) pageID;
	-(void) setPageID:(NSString *)p0;
	-(NSString *) previewPropertyName;
	-(void) setPreviewPropertyName:(NSString *)p0;
	-(NSString *) shareUUID;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareOpenGraphObject : FBSDKShareOpenGraphValueContainer {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(BOOL) isEqualToShareOpenGraphObject:(id)p0;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareOpenGraphValueContaining : NSObject<FBSDKShareOpenGraphValueContaining> {
}
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKSharePhoto : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(BOOL) isEqualToSharePhoto:(id)p0;
	-(NSString *) caption;
	-(void) setCaption:(NSString *)p0;
	-(UIImage *) image;
	-(void) setImage:(UIImage *)p0;
	-(NSURL *) imageURL;
	-(void) setImageURL:(NSURL *)p0;
	-(BOOL) isUserGenerated;
	-(void) setUserGenerated:(BOOL)p0;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKSharePhotoContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(NSURL *) contentURL;
	-(NSArray *) peopleIDs;
	-(NSString *) placeID;
	-(NSString *) ref;
	-(BOOL) isEqualToSharePhotoContent:(id)p0;
	-(void) setContentURL:(NSURL *)p0;
	-(void) setPeopleIDs:(NSArray *)p0;
	-(void) setPlaceID:(NSString *)p0;
	-(void) setRef:(NSString *)p0;
	-(id) hashtag;
	-(void) setHashtag:(id)p0;
	-(NSString *) pageID;
	-(void) setPageID:(NSString *)p0;
	-(NSArray *) photos;
	-(void) setPhotos:(NSArray *)p0;
	-(NSString *) shareUUID;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareVideo : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(BOOL) isEqualToShareVideo:(id)p0;
	-(id) previewPhoto;
	-(void) setPreviewPhoto:(id)p0;
	-(NSURL *) videoURL;
	-(void) setVideoURL:(NSURL *)p0;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKShareVideoContent : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(NSURL *) contentURL;
	-(NSArray *) peopleIDs;
	-(NSString *) placeID;
	-(NSString *) ref;
	-(BOOL) isEqualToShareVideoContent:(id)p0;
	-(void) setContentURL:(NSURL *)p0;
	-(void) setPeopleIDs:(NSArray *)p0;
	-(void) setPlaceID:(NSString *)p0;
	-(void) setRef:(NSString *)p0;
	-(id) hashtag;
	-(void) setHashtag:(id)p0;
	-(NSString *) pageID;
	-(void) setPageID:(NSString *)p0;
	-(id) previewPhoto;
	-(void) setPreviewPhoto:(id)p0;
	-(NSString *) shareUUID;
	-(id) video;
	-(void) setVideo:(id)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKSharing : NSObject<FBSDKSharing> {
}
	-(id) init;
@end

@protocol FBSDKSharingButton
	@optional -(id) shareContent;
	@optional -(void) setShareContent:(id)p0;
@end

@interface FBSDKSharingButton : NSObject<FBSDKSharingButton> {
}
	-(id) init;
@end

@protocol FBSDKSharingDelegate
	@required -(void) sharer:(id)p0 didCompleteWithResults:(NSDictionary *)p1;
	@required -(void) sharer:(id)p0 didFailWithError:(NSError *)p1;
	@required -(void) sharerDidCancel:(id)p0;
@end

@interface FBSDKSharingDelegate : NSObject<FBSDKSharingDelegate> {
}
	-(id) init;
@end

@interface FBSDKSharingDialog : NSObject<FBSDKSharingDialog> {
}
	-(id) init;
@end

@interface FBSDKPlacesManager : NSObject {
}
	-(id) currentPlaceFeedbackRequestForPlaceID:(NSString *)p0 tracking:(NSString *)p1 wasHere:(BOOL)p2;
	-(void) generateCurrentPlaceRequestWithMinimumConfidenceLevel:(NSInteger)p0 fields:(NSArray *)p1 completion:(id)p2;
	-(void) generateCurrentPlaceRequestForCurrentLocation:(CLLocation *)p0 withMinimumConfidenceLevel:(NSInteger)p1 fields:(NSArray *)p2 completion:(id)p3;
	-(id) placeInfoRequestForPlaceID:(NSString *)p0 fields:(NSArray *)p1;
	-(void) generatePlaceSearchRequestForSearchTerm:(NSString *)p0 categories:(NSArray *)p1 fields:(NSArray *)p2 distance:(double)p3 cursor:(NSString *)p4 completion:(id)p5;
	-(id) placeSearchRequestForLocation:(CLLocation *)p0 searchTerm:(NSString *)p1 categories:(NSArray *)p2 fields:(NSArray *)p3 distance:(double)p4 cursor:(NSString *)p5;
	-(id) init;
@end

@interface FBSDKMessengerContext : NSObject {
}
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKMessengerBroadcastContext : FBSDKMessengerContext {
}
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKMessengerShareButton : NSObject {
}
@end

@interface FBSDKMessengerShareOptions : NSObject {
}
	-(id) contextOverride;
	-(void) setContextOverride:(id)p0;
	-(NSString *) metadata;
	-(void) setMetadata:(NSString *)p0;
	-(BOOL) renderAsSticker;
	-(void) setRenderAsSticker:(BOOL)p0;
	-(NSURL *) sourceURL;
	-(void) setSourceURL:(NSURL *)p0;
	-(id) init;
@end

@interface FBSDKMessengerSharer : NSObject {
}
@end

@interface FBSDKMessengerURLHandlerCancelContext : FBSDKMessengerContext {
}
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@protocol FBSDKMessengerURLHandlerDelegate
	@optional -(void) messengerURLHandler:(id)p0 didHandleReplyWithContext:(id)p1;
	@optional -(void) messengerURLHandler:(id)p0 didHandleOpenFromComposerWithContext:(id)p1;
	@optional -(void) messengerURLHandler:(id)p0 didHandleCancelWithContext:(id)p1;
@end

@interface FBSDKMessengerURLHandlerDelegate : NSObject<FBSDKMessengerURLHandlerDelegate> {
}
	-(id) init;
@end

@interface FBSDKMessengerURLHandlerOpenFromComposerContext : FBSDKMessengerContext {
}
	-(NSString *) metadata;
	-(NSSet *) userIDs;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKMessengerURLHandlerReplyContext : FBSDKMessengerContext {
}
	-(NSString *) metadata;
	-(NSSet *) userIDs;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
@end

@interface FBSDKDeviceLoginCodeInfo : NSObject {
}
	-(NSDate *) expirationDate;
	-(NSString *) identifier;
	-(NSString *) loginCode;
	-(NSUInteger) pollingInterval;
	-(NSURL *) verificationURL;
@end

@protocol FBSDKDeviceLoginManagerDelegate
	@required -(void) deviceLoginManager:(id)p0 startedWithCodeInfo:(id)p1;
	@required -(void) deviceLoginManager:(id)p0 completedWithResult:(id)p1 error:(NSError *)p2;
@end

@interface FBSDKDeviceLoginManagerDelegate : NSObject<FBSDKDeviceLoginManagerDelegate> {
}
	-(id) init;
@end

@interface FBSDKDeviceLoginManagerResult : NSObject {
}
	-(id) accessToken;
	-(BOOL) isCancelled;
@end

@protocol FBSDKLoginButtonDelegate
	@required -(void) loginButton:(id)p0 didCompleteWithResult:(id)p1 error:(NSError *)p2;
	@required -(void) loginButtonDidLogOut:(id)p0;
	@optional -(BOOL) loginButtonWillLogin:(id)p0;
@end

@interface FBSDKLoginButtonDelegate : NSObject<FBSDKLoginButtonDelegate> {
}
	-(id) init;
@end

@interface FBSDKLoginManagerLoginResult : NSObject {
}
	-(NSSet *) declinedPermissions;
	-(void) setDeclinedPermissions:(NSSet *)p0;
	-(NSSet *) grantedPermissions;
	-(void) setGrantedPermissions:(NSSet *)p0;
	-(BOOL) isCancelled;
	-(id) token;
	-(void) setToken:(id)p0;
	-(id) init;
	-(id) initWithToken:(id)p0 isCancelled:(BOOL)p1 grantedPermissions:(NSSet *)p2 declinedPermissions:(NSSet *)p3;
@end

@protocol FBSDKLoginTooltipViewDelegate
	@optional -(BOOL) loginTooltipView:(id)p0 shouldAppear:(BOOL)p1;
	@optional -(void) loginTooltipViewWillAppear:(id)p0;
	@optional -(void) loginTooltipViewWillNotAppear:(id)p0;
@end

@interface FBSDKLoginTooltipViewDelegate : NSObject<FBSDKLoginTooltipViewDelegate> {
}
	-(id) init;
@end

@interface FBSDKSettings : NSObject {
}
@end

@interface FBSDKAccessToken : NSObject {
}
	-(NSObject *) copy;
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(BOOL) hasGranted:(NSString *)p0;
	-(BOOL) isEqualToAccessToken:(id)p0;
	-(NSString *) appID;
	-(NSSet *) declinedPermissions;
	-(NSDate *) expirationDate;
	-(BOOL) isExpired;
	-(NSSet *) permissions;
	-(NSDate *) refreshDate;
	-(NSString *) tokenString;
	-(NSString *) userID;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithTokenString:(NSString *)p0 permissions:(NSArray *)p1 declinedPermissions:(NSArray *)p2 appID:(NSString *)p3 userID:(NSString *)p4 expirationDate:(NSDate *)p5 refreshDate:(NSDate *)p6;
@end

@interface FBSDKAppEvents : NSObject {
}
@end

@interface FBSDKApplicationDelegate : NSObject {
}
	-(BOOL) application:(UIApplication *)p0 didFinishLaunchingWithOptions:(NSDictionary *)p1;
	-(BOOL) application:(UIApplication *)p0 openURL:(NSURL *)p1 sourceApplication:(NSString *)p2 annotation:(NSObject *)p3;
	-(BOOL) application:(UIApplication *)p0 openURL:(NSURL *)p1 options:(NSDictionary *)p2;
@end

@protocol BFAppLinkResolving
	@required -(id) appLinkFromURLInBackground:(NSURL *)p0;
@end

@interface FBSDKAppLinkResolver : NSObject {
}
	-(id) appLinkFromURLInBackground:(NSURL *)p0;
	-(id) appLinksFromURLsInBackground:(NSArray *)p0;
@end

@interface BFAppLinkResolving : NSObject<BFAppLinkResolving> {
}
	-(id) init;
@end

@interface FBSDKCopying : NSObject<FBSDKCopying> {
}
	-(id) init;
@end

@protocol FBSDKErrorRecoveryAttempting
	@required -(void) attemptRecoveryFromError:(NSError *)p0 optionIndex:(NSUInteger)p1 delegate:(NSObject *)p2 didRecoverSelector:(SEL)p3 contextInfo:(NSObject *)p4;
@end

@interface FBSDKErrorRecoveryAttempting : NSObject<FBSDKErrorRecoveryAttempting> {
}
	-(id) init;
@end

@interface FBSDKGraphErrorRecoveryProcessor : NSObject {
}
	-(void) didPresentErrorWithRecovery:(BOOL)p0 contextInfo:(NSObject *)p1;
	-(BOOL) processError:(NSError *)p0 request:(id)p1 delegate:(id)p2;
	-(id) delegate;
	-(id) init;
@end

@protocol FBSDKGraphErrorRecoveryProcessorDelegate
	@required -(void) processorDidAttemptRecovery:(id)p0 didRecover:(BOOL)p1 error:(NSError *)p2;
	@optional -(BOOL) processorWillProcessError:(id)p0 error:(NSError *)p1;
@end

@interface FBSDKGraphErrorRecoveryProcessorDelegate : NSObject<FBSDKGraphErrorRecoveryProcessorDelegate> {
}
	-(id) init;
@end

@interface FBSDKGraphRequest : NSObject {
}
	-(void) setGraphErrorRecoveryDisabled:(BOOL)p0;
	-(id) startWithCompletionHandler:(id)p0;
	-(NSString *) graphPath;
	-(NSString *) HTTPMethod;
	-(NSMutableDictionary *) parameters;
	-(NSString *) tokenString;
	-(NSString *) version;
	-(id) initWithGraphPath:(NSString *)p0 parameters:(NSDictionary *)p1;
	-(id) initWithGraphPath:(NSString *)p0 parameters:(NSDictionary *)p1 HTTPMethod:(NSString *)p2;
	-(id) initWithGraphPath:(NSString *)p0 parameters:(NSDictionary *)p1 tokenString:(NSString *)p2 version:(NSString *)p3 HTTPMethod:(NSString *)p4;
@end

@protocol FBSDKGraphRequestConnectionDelegate
	@optional -(void) requestConnectionWillBeginLoading:(id)p0;
	@optional -(void) requestConnectionDidFinishLoading:(id)p0;
	@optional -(void) requestConnection:(id)p0 didFailWithError:(NSError *)p1;
	@optional -(void) requestConnection:(id)p0 didSendBodyData:(NSInteger)p1 totalBytesWritten:(NSInteger)p2 totalBytesExpectedToWrite:(NSInteger)p3;
@end

@interface FBSDKGraphRequestConnectionDelegate : NSObject<FBSDKGraphRequestConnectionDelegate> {
}
	-(id) init;
@end

@interface FBSDKGraphRequestDataAttachment : NSObject {
}
	-(NSString *) contentType;
	-(NSData *) data;
	-(NSString *) filename;
	-(id) initWithData:(NSData *)p0 filename:(NSString *)p1 contentType:(NSString *)p2;
@end

@protocol FBSDKMutableCopying
	@required -(NSObject *) mutableCopy;
@end

@interface FBSDKMutableCopying : NSObject<FBSDKMutableCopying> {
}
	-(id) init;
@end

@interface FBSDKProfile : NSObject {
}
	-(NSObject *) copyWithZone:(id)p0;
	-(void) encodeWithCoder:(NSCoder *)p0;
	-(NSString *) imagePathForPictureMode:(NSUInteger)p0 size:(CGSize)p1;
	-(NSURL *) imageURLForPictureMode:(NSUInteger)p0 size:(CGSize)p1;
	-(BOOL) isEqualToProfile:(id)p0;
	-(NSString *) firstName;
	-(NSString *) lastName;
	-(NSURL *) linkURL;
	-(NSString *) middleName;
	-(NSString *) name;
	-(NSDate *) refreshDate;
	-(NSString *) userID;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithUserID:(NSString *)p0 firstName:(NSString *)p1 middleName:(NSString *)p2 lastName:(NSString *)p3 name:(NSString *)p4 linkURL:(NSURL *)p5 refreshDate:(NSDate *)p6;
@end

@interface BFTask : NSObject {
}
	-(NSError *) error;
	-(NSException *) exception;
	-(BOOL) isCancelled;
	-(BOOL) isCompleted;
	-(BOOL) isFaulted;
	-(NSObject *) result;
	-(id) init;
@end

@interface FBSDKTestUsersManager : NSObject {
}
	-(void) addTestAccountWithPermissions:(NSSet *)p0 completionHandler:(id)p1;
	-(void) makeFriendsWithFirst:(id)p0 second:(id)p1 callback:(id)p2;
	-(void) removeTestAccount:(NSString *)p0 completionHandler:(id)p1;
	-(void) requestTestAccountTokensWithArraysOfPermissions:(NSArray *)p0 createIfNotFound:(BOOL)p1 completionHandler:(id)p2;
@end

@interface FBSDKUtility : NSObject {
}
@end

@interface FBSDKAppGroupAddDialog : NSObject {
}
	-(BOOL) show;
	-(BOOL) validateWithError:(NSError **)p0;
	-(BOOL) canShow;
	-(id) content;
	-(void) setContent:(id)p0;
	-(id) delegate;
	-(void) setDelegate:(id)p0;
	-(id) init;
@end

@interface FBSDKAppGroupJoinDialog : NSObject {
}
	-(BOOL) show;
	-(BOOL) validateWithError:(NSError **)p0;
	-(BOOL) canShow;
	-(id) delegate;
	-(void) setDelegate:(id)p0;
	-(NSString *) groupID;
	-(void) setGroupID:(NSString *)p0;
	-(id) init;
@end

@interface FBSDKAppInviteDialog : NSObject {
}
	-(BOOL) show;
	-(BOOL) validateWithError:(NSError **)p0;
	-(BOOL) canShow;
	-(id) content;
	-(void) setContent:(id)p0;
	-(id) delegate;
	-(void) setDelegate:(id)p0;
	-(UIViewController *) fromViewController;
	-(void) setFromViewController:(UIViewController *)p0;
	-(id) init;
@end

@interface FBSDKGameRequestDialog : NSObject {
}
	-(BOOL) show;
	-(BOOL) validateWithError:(NSError **)p0;
	-(BOOL) canShow;
	-(id) content;
	-(void) setContent:(id)p0;
	-(id) delegate;
	-(void) setDelegate:(id)p0;
	-(BOOL) frictionlessRequestsEnabled;
	-(void) setFrictionlessRequestsEnabled:(BOOL)p0;
	-(id) init;
@end

@interface Facebook_CoreKit_Button_ButtonAppearance : UIKit_UIButton_UIButtonAppearance {
}
@end

@interface Facebook_ShareKit_LikeButton_LikeButtonAppearance : Facebook_CoreKit_Button_ButtonAppearance {
}
@end

@interface FBSDKButton : UIButton {
}
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithFrame:(CGRect)p0;
@end

@interface FBSDKLikeButton : FBSDKButton {
}
	-(NSString *) objectID;
	-(NSUInteger) objectType;
	-(void) setObjectID:(NSString *)p0;
	-(void) setObjectType:(NSUInteger)p0;
	-(BOOL) isSoundEnabled;
	-(void) setSoundEnabled:(BOOL)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithFrame:(CGRect)p0;
@end

@interface Facebook_ShareKit_LikeControl_LikeControlAppearance : UIKit_UIControl_UIControlAppearance {
}
@end

@interface FBSDKLikeControl : UIControl {
}
	-(NSString *) objectID;
	-(NSUInteger) objectType;
	-(void) setObjectID:(NSString *)p0;
	-(void) setObjectType:(NSUInteger)p0;
	-(UIColor *) foregroundColor;
	-(void) setForegroundColor:(UIColor *)p0;
	-(NSUInteger) likeControlAuxiliaryPosition;
	-(void) setLikeControlAuxiliaryPosition:(NSUInteger)p0;
	-(NSUInteger) likeControlHorizontalAlignment;
	-(void) setLikeControlHorizontalAlignment:(NSUInteger)p0;
	-(NSUInteger) likeControlStyle;
	-(void) setLikeControlStyle:(NSUInteger)p0;
	-(CGFloat) preferredMaxLayoutWidth;
	-(void) setPreferredMaxLayoutWidth:(CGFloat)p0;
	-(BOOL) isSoundEnabled;
	-(void) setSoundEnabled:(BOOL)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithFrame:(CGRect)p0;
@end

@interface Facebook_ShareKit_SendButton_SendButtonAppearance : Facebook_CoreKit_Button_ButtonAppearance {
}
@end

@interface FBSDKSendButton : FBSDKButton {
}
	-(id) shareContent;
	-(void) setShareContent:(id)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithFrame:(CGRect)p0;
@end

@interface Facebook_ShareKit_ShareButton_ShareButtonAppearance : Facebook_CoreKit_Button_ButtonAppearance {
}
@end

@interface FBSDKShareButton : FBSDKButton {
}
	-(id) shareContent;
	-(void) setShareContent:(id)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithFrame:(CGRect)p0;
@end

@interface FBSDKMessengerURLHandler : NSObject {
}
	-(BOOL) canOpenURL:(NSURL *)p0 sourceApplication:(NSString *)p1;
	-(BOOL) openURL:(NSURL *)p0 sourceApplication:(NSString *)p1;
	-(id) delegate;
	-(void) setDelegate:(id)p0;
	-(id) init;
@end

@interface FBSDKDeviceLoginManager : NSObject {
}
	-(void) cancel;
	-(void) start;
	-(id) delegate;
	-(void) setDelegate:(id)p0;
	-(NSArray *) permissions;
	-(NSURL *) redirectURL;
	-(void) setRedirectURL:(NSURL *)p0;
	-(id) initWithPermissions:(NSArray *)p0 enableSmartLogin:(BOOL)p1;
@end

@interface Facebook_LoginKit_LoginButton_LoginButtonAppearance : Facebook_CoreKit_Button_ButtonAppearance {
}
@end

@interface FBSDKLoginButton : FBSDKButton {
}
	-(NSUInteger) defaultAudience;
	-(void) setDefaultAudience:(NSUInteger)p0;
	-(id) delegate;
	-(void) setDelegate:(id)p0;
	-(NSUInteger) loginBehavior;
	-(void) setLoginBehavior:(NSUInteger)p0;
	-(NSArray *) publishPermissions;
	-(void) setPublishPermissions:(NSArray *)p0;
	-(NSArray *) readPermissions;
	-(void) setReadPermissions:(NSArray *)p0;
	-(NSUInteger) tooltipBehavior;
	-(void) setTooltipBehavior:(NSUInteger)p0;
	-(NSUInteger) tooltipColorStyle;
	-(void) setTooltipColorStyle:(NSUInteger)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithFrame:(CGRect)p0;
@end

@interface FBSDKLoginManager : NSObject {
}
	-(void) logInWithPublishPermissions:(NSArray *)p0 handler:(id)p1;
	-(void) logInWithPublishPermissions:(NSArray *)p0 fromViewController:(UIViewController *)p1 handler:(id)p2;
	-(void) logInWithReadPermissions:(NSArray *)p0 handler:(id)p1;
	-(void) logInWithReadPermissions:(NSArray *)p0 fromViewController:(UIViewController *)p1 handler:(id)p2;
	-(void) logOut;
	-(NSUInteger) defaultAudience;
	-(void) setDefaultAudience:(NSUInteger)p0;
	-(NSUInteger) loginBehavior;
	-(void) setLoginBehavior:(NSUInteger)p0;
	-(id) init;
@end

@interface Facebook_LoginKit_TooltipView_TooltipViewAppearance : UIKit_UIView_UIViewAppearance {
}
@end

@interface Facebook_LoginKit_LoginTooltipView_LoginTooltipViewAppearance : Facebook_LoginKit_TooltipView_TooltipViewAppearance {
}
@end

@interface FBSDKTooltipView : UIView {
}
	-(void) dismiss;
	-(void) presentFromView:(UIView *)p0;
	-(void) presentInView:(UIView *)p0 withArrowPosition:(CGPoint)p1 direction:(NSUInteger)p2;
	-(NSUInteger) colorStyle;
	-(void) setColorStyle:(NSUInteger)p0;
	-(double) displayDuration;
	-(void) setDisplayDuration:(double)p0;
	-(NSString *) message;
	-(void) setMessage:(NSString *)p0;
	-(NSString *) tagline;
	-(void) setTagline:(NSString *)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithFrame:(CGRect)p0;
	-(id) initWithTagline:(NSString *)p0 message:(NSString *)p1 colorStyle:(NSUInteger)p2;
@end

@interface FBSDKLoginTooltipView : FBSDKTooltipView {
}
	-(id) delegate;
	-(void) setDelegate:(id)p0;
	-(BOOL) forceDisplay;
	-(void) setForceDisplay:(BOOL)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithFrame:(CGRect)p0;
@end

@interface FBSDKAppLinkUtility : NSObject {
}
@end

@interface FBSDKGraphRequestConnection : NSObject {
}
	-(void) addRequest:(id)p0 completionHandler:(id)p1;
	-(void) addRequest:(id)p0 completionHandler:(id)p1 batchEntryName:(NSString *)p2;
	-(void) addRequest:(id)p0 completionHandler:(id)p1 batchParameters:(NSDictionary *)p2;
	-(void) cancel;
	-(void) overrideVersionPartWith:(NSString *)p0;
	-(void) setDelegateQueue:(NSOperationQueue *)p0;
	-(void) start;
	-(id) delegate;
	-(void) setDelegate:(id)p0;
	-(double) timeout;
	-(void) setTimeout:(double)p0;
	-(NSHTTPURLResponse *) URLResponse;
	-(id) init;
@end

@interface Facebook_CoreKit_ProfilePictureView_ProfilePictureViewAppearance : UIKit_UIView_UIViewAppearance {
}
@end

@interface FBSDKProfilePictureView : UIView {
}
	-(void) setNeedsImageUpdate;
	-(NSUInteger) pictureMode;
	-(void) setPictureMode:(NSUInteger)p0;
	-(NSString *) profileID;
	-(void) setProfileID:(NSString *)p0;
	-(id) init;
	-(id) initWithCoder:(NSCoder *)p0;
	-(id) initWithFrame:(CGRect)p0;
@end


