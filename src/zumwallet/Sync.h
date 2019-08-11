// Copyright (c) 2019, ZumCoin Development Team
// 
// Please see the included LICENSE file for more information.

#pragma once

#include <zumwallet/Types.h>

void syncWallet(CryptoNote::INode &node,
                std::shared_ptr<WalletInfo> walletInfo);

void checkForNewTransactions(std::shared_ptr<WalletInfo> walletInfo);
