// Copyright (c) 2019, ZumCoin Development Team
// 
// Please see the included LICENSE file for more information.

#pragma once

#include <unordered_set>

#include "CryptoNoteProtocol/CryptoNoteProtocolDefinitions.h"

namespace CryptoNote {
struct PendingLiteBlock {
  NOTIFY_NEW_LITE_BLOCK_request request;
  std::unordered_set<Crypto::Hash> missed_transactions;
};
}  // namespace CryptoNote