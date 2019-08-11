// Copyright (c) 2019, ZumCoin Development Team
// 
// Please see the included LICENSE file for more information.

#pragma once

#include <NodeRpcProxy/NodeRpcProxy.h>

#include <zumwallet/Types.h>

int main(int argc, char **argv);

void run(CryptoNote::WalletGreen &wallet, CryptoNote::INode &node,
         Config &config);
