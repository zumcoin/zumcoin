// Copyright (c) 2019, ZumCoin Development Team
// 
// Please see the included LICENSE file for more information.

#pragma once

#include <string>

#include <vector>

#include <zumwallet/Commands.h>
#include <zumwallet/Types.h>

std::string yellowANSIMsg(std::string msg);

std::string getPrompt(std::shared_ptr<WalletInfo> walletInfo);

template<typename T>
std::string getInputAndWorkInBackground(const std::vector<T>
                                        &availableCommands,
                                        std::string prompt,
                                        bool backgroundRefresh,
                                        std::shared_ptr<WalletInfo>
                                        walletInfo);

template<typename T>
std::string getInput(const std::vector<T> &availableCommands,
                     std::string prompt);
