using System;
using MultipeerConnectivity;
using Foundation;
using System.Collections.Generic;
using System.Linq;
using Firebase.Database;
using Plugin.Geolocator;
using System.Threading.Tasks;

namespace Circle
{

	public class Manager : NSObject, IMCNearbyServiceAdvertiserDelegate, IMCNearbyServiceBrowserDelegate, IMCSessionDelegate
	{
		const string serviceType = "Nearby";
		public MCPeerID peerID;
		public MCSession session;
		public MCNearbyServiceBrowser browser;
		public MCNearbyServiceAdvertiser advertiser;
		public List<MCPeerID> peers = new List<MCPeerID>();
        public Plugin.Geolocator.Abstractions.Position position;
        public DatabaseReference groupNode;
        public List<MCPeerID> MCPeers = new List<MCPeerID>();

		public Manager()
		{
			
		}

		public void setupPeerAndSession(NSString displayName)
		{
			peerID = new MCPeerID(displayName);

			session = new MCSession(peerID, null, MCEncryptionPreference.None);
			session.Delegate = this;
		}

		public void setupBrowser()
		{
			browser = new MCNearbyServiceBrowser(peerID, serviceType);

			browser.Delegate = this;
			browser.StartBrowsingForPeers();
		}

		public void advertiseSelf(bool shouldAdvertise)
		{
			if (shouldAdvertise)
			{
				NSMutableDictionary elements = new NSMutableDictionary();
				//elements.SetValueForKey(
				advertiser = new MCNearbyServiceAdvertiser(peerID, elements, serviceType);
				advertiser.Delegate = this;
				advertiser.StartAdvertisingPeer();
			}
			else {
				advertiser.StopAdvertisingPeer();
				advertiser = null;

			}
		}

        public void disconnect()
		{
			advertiser.StopAdvertisingPeer();
			advertiser.Delegate = null;
			advertiser = null;

			browser.StopBrowsingForPeers();
			browser.Delegate = null;
			browser = null;

			session.Disconnect();
           
			session.Delegate = null;
			session = null;
		}

        public List<MCPeerID> NearbyUsers()
        {
            return MCPeers;
        }

		void IMCNearbyServiceAdvertiserDelegate.DidReceiveInvitationFromPeer(MCNearbyServiceAdvertiser advertiser, MCPeerID peerID, NSData context, MCNearbyServiceAdvertiserInvitationHandler invitationHandler)
		{
			invitationHandler(true, session);
			NSNotificationCenter.DefaultCenter.PostNotificationName("MCDidRecieveInvitationNotification", null, null);
		
		}

		void IMCNearbyServiceBrowserDelegate.FoundPeer(MCNearbyServiceBrowser browser, MCPeerID peerID, NSDictionary info)
		{
            if (peerID.DisplayName == this.peerID.DisplayName) return;
			else {
				browser.InvitePeer(peerID, session, null, 15);
                MCPeers.Add(peerID);
            
			}
		}

		void IMCNearbyServiceBrowserDelegate.LostPeer(MCNearbyServiceBrowser browser, MCPeerID peerID)
		{
			if (peerID.DisplayName == this.peerID.DisplayName) return;
            MCPeers.Remove(peerID);
			Console.WriteLine("Peer Lost");
		}

		void IMCSessionDelegate.DidChangeState(MCSession session, MCPeerID peerID, MCSessionState state)
		{
			var dictionary = new Dictionary<string, object> 
			{
				{"PeerID", peerID},
				{"state", state}
			};
			var myResult = NSDictionary.FromObjectsAndKeys(dictionary.Values.ToArray()
														   , dictionary.Keys.ToArray());

			                           NSNotificationCenter.DefaultCenter.PostNotificationName("MCDidChangeStateWithNotification", null, myResult);
		}

		void IMCSessionDelegate.DidReceiveData(MCSession session, NSData data, MCPeerID peerID)
		{
			var dictionary = new Dictionary<string, object>
			{
				{"PeerID", peerID},
				{"data", data}
			};
			var myResult = NSDictionary.FromObjectsAndKeys(dictionary.Values.ToArray()
														   , dictionary.Keys.ToArray());
			NSNotificationCenter.DefaultCenter.PostNotificationName("MCDidRecieveDataNotification", null, myResult);
		
		}

		void IMCSessionDelegate.DidStartReceivingResource(MCSession session, string resourceName, MCPeerID fromPeer, NSProgress progress)
		{
			throw new NotImplementedException();
		}

		void IMCSessionDelegate.DidFinishReceivingResource(MCSession session, string resourceName, MCPeerID fromPeer, NSUrl localUrl, NSError error)
		{
			throw new NotImplementedException();
		}

		void IMCSessionDelegate.DidReceiveStream(MCSession session, NSInputStream stream, string streamName, MCPeerID peerID)
		{
			throw new NotImplementedException();
		}

        public async void CreateNearbyChat(List<MCPeerID> peerUsers)
        {
            var locator = CrossGeolocator.Current;
            var position = await locator.GetPositionAsync(TimeSpan.FromSeconds(10));

            var lat = position.Latitude.ToString();
            var lon = position.Longitude.ToString();
            string[] users = { };

            foreach (var peer in peerUsers)
            {
                var id = peer.ToString();
                users.Append(id);
            }

            object[] keys = { "users", "lat", "lon" };
            object[] values = { users, lat, lon };
            var data = NSDictionary.FromObjectsAndKeys(values, keys, keys.Length);

            groupNode.KeepSynced(true);
            groupNode.SetValue(data);
        }


        void AddUserToGroup()
        {
            
        }

        void RemoveUserFromGroup()
        {
            
        }
    }
}
