#pragma once

#include <stdint.h>

typedef struct Msg {
  uint64_t type; //usually masked out to be an enum
} Msg;