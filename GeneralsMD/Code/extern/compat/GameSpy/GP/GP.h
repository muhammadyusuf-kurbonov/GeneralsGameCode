#pragma once

typedef int GPEnum;
typedef int GPProfile;

const size_t GP_NICK_LEN = 128;
const size_t GP_EMAIL_LEN = 128;
const size_t GP_PASSWORD_LEN = 128;
const size_t GP_STATUS_STRING_LEN = 128;
const size_t GP_LOCATION_STRING_LEN = 128;
const size_t GP_COUNTRYCODE_LEN = 128;
const size_t GP_REASON_LEN = 128;

typedef unsigned int GPErrorCode;
typedef unsigned int GPResult;

enum eGPStatus
{
	GP_ONLINE,
	GP_OFFLINE,
	GP_RECV_GAME_INVITE,
};
