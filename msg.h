#ifndef _MSG_H
#define _MSG_H

#define GIF_LOGIN_MSG 1
#define GIF_CALL_MSG 2
#define GIF_ADDRLIST_MSG 3
#define GIF_ADD_CONTACTS_MSG 4
#define GIF_DELETE_CONTACTS_MSG 5
#define GIF_CHAT_MSG 6
#define GIF_DISCONNECT_MSG 7
#define GIF_SUCCESS_REQUEST_MSG 8
#define GIF_OFFLINE_REQUEST_MSG 9
#define GIF_OFFLINE_MSG 10
#define GIF_OFFLINE_DELETE_MSG 11

#define GIF_ERROR_LOGIN_INCORRECT 101
#define GIF_SUCCESS_ADD_CONTACTS 102
#define GIF_ERROR_ASS_CONTACTS 103
#define GIF_SUCCESS_DELETE_CONTACTS 104
#define GIF_ERROR_DELETE_CONTACTS_NOT_A_CONTACT 105
#define GIF_ERROR_DELETE_CONTACTS_NOT_A_MEMBER 106


struct MsgHeader
{
    unsigned int type;
    unsigned int length;
    char sender[10];
    char receiver[10];
    unsigned int reserved;
};
typedef struct MsgHeader msg_header_t;

struct User
{
    char name[20];
    char password[20];
};
typedef struct User user_t;

struct OnlineUser
{
    char name[20];
    int sockfd;
};
typedef struct OnlineUser online_user_t;

struct ContactUser
{
    char name[20];
};
typedef struct ContactUser contack_user_t;

struct UserStatus
{
    char name[20];
    unsigned int status;
};
typedef struct UserStatus user_status_t;

struct MsgOffline
{
    char sender_name[20];
    char time[20];
    unsigned int new;
    char msg[1024];
};
typedef struct MsgOffline msg_offline_t;

struct MsgOfflineSend
{
    char sender_name[20];
    char time[20];
    unsigned int new;
    unsigned int length;
};
typedef struct MsgOfflineSend msg_offline_send_t;

#endif








