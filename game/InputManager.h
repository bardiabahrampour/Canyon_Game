#pragma once

#include <unordered_map>

/*****************************************
	There are two different styles of keys;
	direction keys and state changer keys(like shift)
	are completely seperated
	from other keys due to the nature of gameplay.
	to get multi directional input and change camera speed and...etc
	-------------------
	keys are stored in a simple array, indexes are stored in a simple enum
	then the system sends a message to the base framework and gets a response with
	the said data array then maps it to the keys
******************************************/

/*
	key types to be mapped in game
*/
enum KeyTypes {
  EXIT_GAME = 0,
  ROTATE_CAMERA_LEFT = 1,
  ROTATE_CAMERA_RIGHT = 2,
  MOVE_CAMERA_RIGHT = 3,
  MOVE_CAMERA_LEFT = 4,
  MOVE_CAMERA_UP = 5,
  MOVE_CAMERA_DOWN = 6,
  MOVE_CAMERA_FASTER = 7,
  CAMERA_ZOOM_IN = 8,
  CAMERA_ZOOM_OUT = 9,
  GAME_SCREENSHOT = 10,
};

/*
	these keys don't use the normal event
	system since they are made to pressed
	and hold together
*/
struct SpecialKeys {
  int left;
  int right;
  int up;
  int down;
  int faster;
  //int slower;
} SpecialKeys;

/*
	HACK:
	an array is used for keys,
	index is used via the enum above,
	HAS TO BE CHANGED ASAP FOR A BETTER IMPL!
*/
class InputManager {
  int keys[10];
 public:
  void Listen();
};
