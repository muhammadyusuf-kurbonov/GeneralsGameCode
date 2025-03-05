#pragma once

enum ePeerFlag
{
  PEER_FLAG_OP
};

enum eStagingRoomResponse
{
  PEERFullRoom,
  PEERInviteOnlyRoom,
  PEERBannedFromRoom,
  PEERBadPassword,
  PEERAlreadyInRoom,
  PEERNoConnection,
  PEERJoinSuccess,
};

enum eStagingRoomAction
{
  PEER_CLEAR,
  PEER_ADD,
  PEER_REMOVE,
  PEER_UPDATE,
};

enum RoomType
{
  StagingRoom,
  GroupRoom,
};

const Bool PEERTrue = TRUE;