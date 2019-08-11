// Copyright (c) 2019, ZumCoin Development Team
//
// Please see the included LICENSE file for more information.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {  

  {0, "dc51426ce3e703aad3fb8f89dd91832f0ca09fa04313ee9aeaece419884151e2"},
  {7, "9aecfd1d952338d1a790fdcd515150852592cc7ad0349291c0b5c4f5eb6635b6"},
  {14, "2da6d083ff162dbe7a70089229e7de11f6f5b68b58761dd784b62eae8140fdf1"},
  {21, "343b8c791f307b29953f0e93de7d3ebaf000e6943e7b1f472b3715b2dedd5e9a"},

};

}
