//
//  CPapi.h
//  candpiosapp
//
//  Created by Alexi (Love Machine) on 2012/02/06.
//  Copyright (c) 2012 Coffee and Power Inc. All rights reserved.
//  
//  This is the (un)official C&P iOS API! These functions are to
//  be used to interact with the C&P web services.



#import <Foundation/Foundation.h>
#import "AFNetworking.h"
#import "CPVenue.h"
#import "ChatHistory.h"
#import <CoreLocation/CoreLocation.h>

@interface CPapi : NSObject


// Helper functions
+ (NSString *)urlEncode:(NSString *)string;
+ (NSString *)urlDecode:(NSString *)string;

// Login functions
+ (void)verifyLoginStatusWithBlock:(void(^)(void))successBlock
                     failureBlock:(void(^)(void))failureBlock;

// Chat functions
+ (void)sendOneOnOneChatMessage:(NSString *)message
                        toUser:(int)userId;
+ (void)oneOnOneChatGetHistoryWith:(User *)User
                        completion:(void (^)(NSDictionary *, NSError *))completion;

# pragma mark - Map Dataset
+ (void)getVenuesWithCheckinsWithinSWCoordinate:(CLLocationCoordinate2D)swCoord
                      NECoordinate:(CLLocationCoordinate2D)neCoord
                      userLocation:(CLLocationCoordinate2D)userLocation
                    checkedInSince:(CGFloat)daysInterval
                            mapQueue:(NSOperationQueue *)mapQueue
             withCompletion:(void (^)(NSDictionary *, NSError *))completion;

+ (void)getNearestVenuesWithCheckinsToCoordinate:(CLLocationCoordinate2D)coordinate
                                        mapQueue:(NSOperationQueue *)mapQueue
                                      completion:(void (^)(NSDictionary *, NSError *))completion;

#pragma mark - Contact Request
+ (void)sendContactRequestToUserId:(int)userId;
+ (void)sendAcceptContactRequestFromUserId:(int)userId
                                completion:(void (^)(NSDictionary *, NSError *))completion;
+ (void)sendDeclineContactRequestFromUserId:(int)userId
                                 completion:(void (^)(NSDictionary *, NSError *))completion;

# pragma mark - Face to Face
+ (void)sendF2FInvite:(int) userId;
+ (void)sendF2FAccept:(int) userId;
+ (void)sendF2FDecline:(int) userId;
+ (void)sendF2FVerify:(int) userId
             password:(NSString *) password;

# pragma mark - Checkins
+ (void)getUsersCheckedInAtFoursquareID:(NSString *)foursquareID
                                       :(void(^)(NSDictionary *json, NSError *error))completion; 

+ (void)checkInToLocation:(CPVenue *)place
              checkInTime:(NSInteger)checkInTime
             checkOutTime:(NSInteger)checkOutTime
               statusText:(NSString *)stausText
                isVirtual:(BOOL)isVirtual
          completionBlock:(void (^)(NSDictionary *, NSError *))completion;

+ (void)checkOutWithCompletion:(void(^)(NSDictionary *json, NSError *error))completion;

# pragma mark - User Profile
+ (void)getResumeForUserId:(int)userId andCompletion:(void(^)(NSDictionary *json, NSError *error))completion;
+ (void)getUserProfileWithCompletionBlock:(void(^)(NSDictionary *json, NSError *error))completion;
+ (void)getUserTrasactionDataWithCompletitonBlock:(void(^)(NSDictionary *json, NSError *error))completion;
+ (void)getCheckInDataWithUserId:(int)userId
                   andCompletion:(void (^)(NSDictionary *, NSError *))completion;
+ (void)getInvitationCodeForLocation:(CLLocation *)location
                withCompletionsBlock:(void(^)(NSDictionary *json, NSError *error))completion;
+ (void)enterInvitationCode:(NSString *)invitationCode
                forLocation:(CLLocation *)location
       withCompletionsBlock:(void(^)(NSDictionary *json, NSError *error))completion;

# pragma mark - Love
+ (void)sendLoveToUserWithID:(int)recieverID
                 loveMessage:(NSString *)loveMessage
                  completion:(void(^)(NSDictionary *json, NSError *error))completion;

+ (void)sendPlusOneForLoveWithID:(int)reviewID 
                    completion:(void(^)(NSDictionary *json, NSError *error))completion;

+ (void)sendPlusOneForLoveWithID:(int)reviewID 
     fromVenueChatForVenueWithID:(int)venueID
                 lastChatEntryID:(int)lastID
                       chatQueue:(NSOperationQueue *)chatQueue
                      completion:(void (^)(NSDictionary *, NSError *))completion;

# pragma mark - Contact List
+ (void)getContactListWithCompletionsBlock:(void(^)(NSDictionary *json, NSError *error))completion;

+ (void)getVenuesInSWCoords:(CLLocationCoordinate2D)SWCoord
                andNECoords:(CLLocationCoordinate2D)NECoord
               userLocation:(CLLocation *)userLocation
              withCompletion:(void (^)(NSDictionary *, NSError *))completion;

# pragma mark - User Settings

+ (void)getNotificationSettingsWithCompletition:(void(^)(NSDictionary *json, NSError *error))completion;

+ (void)setNotificationSettingsForDistance:(NSString *)distance
                              andCheckedId:(BOOL)checkedOnly
                                 quietTime:(BOOL)quietTime
                             quietTimeFrom:(NSDate *)quietTimeFrom
                               quietTimeTo:(NSDate *)quietTimeTo
                   timezoneOffsetInSeconds:(NSInteger)tzOffsetSeconds                                  
                      chatFromContactsOnly:(BOOL)chatFromContactsOnly;

+ (void)setUserProfileDataWithDictionary:(NSMutableDictionary *)dataDict
                            andCompletion:(void (^)(NSDictionary *, NSError *))completion;
+ (void)uploadUserProfilePhoto:(UIImage *)image 
                withCompletion:(void (^)(NSDictionary *, NSError *))completion;

+ (void)saveUserMajorJobCategory:(NSString *)majorJobCategory
             andMinorJobCategory:(NSString *)minorJobCategory;

+ (void)saveUserSmartererName:(NSString *)name
                                       :(void(^)(NSDictionary *json, NSError *error))completion; 

# pragma mark - Venue Chat
+ (void)getVenueChatForVenueWithID:(int)venueID
                        lastChatID:(int)lastChatID
                             queue:(NSOperationQueue *)chatQueue
                        completion:(void (^)(NSDictionary *, NSError *))completion;

+ (void)sendVenueChatForVenueWithID:(int)venueIDString
                            message:(NSString *)message
                        lastChatID:(int)lastChatIDString
                              queue:(NSOperationQueue *)chatQueue
                        completion:(void (^)(NSDictionary *, NSError *))completion;

+ (void)saveVenueAutoCheckinStatus:(CPVenue *)venue;

@end
