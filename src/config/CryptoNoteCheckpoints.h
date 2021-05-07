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
  {100000, "8153aecc6cbd9c302f202a016367d0b0c55a665465be6520728048cb6e32fc48"},
  {150000, "6e990ffe1ea7d8254c678bb812a3bb7269bbdd9eaa21407b0deeb4dcd0017c74"},
  {200000, "7465a5a0e9fa2994e5db684b07fcd031e10ac09def80d2b17ea32136f2c12e1a"},
  {300000, "2fd5aab7bbc0df8b48319ff7c9582bc8742d2dd51d73b883ed20b01404316b14"},
  {400000, "b2cbde99bfae9d398a133f2fb52458f0c752d6e506e8e48bdbe01a217bdb0b6b"},
  {450000, "34fc960f343a163fc05c3ef943372fd6250664ed7c4363a1c26675f69877a964"},

};

}
