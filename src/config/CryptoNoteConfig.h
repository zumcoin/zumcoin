// Copyright (c) 2019, ZumCoin Development Team
//
// Please see the included LICENSE file for more information.

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <limits>
#include <initializer_list>
#include <boost/uuid/uuid.hpp>

namespace CryptoNote {
namespace parameters {


const uint64_t DIFFICULTY_TARGET                             = 120; //2 minute
const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t COIN                                          = UINT64_C(100000000); // 1.00 ZUM
const uint64_t MONEY_SUPPLY                                  = UINT64_C(1000000000000000000);
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 4153412; // Address prefix Zum1
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 30;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V3         = 3 * DIFFICULTY_TARGET;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V4         = 6 * DIFFICULTY_TARGET;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V3          = 11;

const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX                   = 1;
const size_t   ZAWY_DIFFICULTY_V2                            = 2;
const uint8_t  ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_VERSION      = 3;

const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX                 = 4;
const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX_V2              = 5;
const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX_V3              = 6;

const uint64_t LWMA_3_DIFFICULTY_BLOCK_INDEX                 = 7;

const unsigned EMISSION_SPEED_FACTOR                         = 29;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");


const char     GENESIS_COINBASE_TX_HEX[]                     = "011e01ff000195fab98eb2d4b8af01024cf7615dafc328b49d168ef7f9f62610665737ff73d494fbf314387c696b0d1e21010b0e93efebfa98585aa94eab4e492bc2c414afe4fe92a6923bf0ab1ed66a4c99";
static_assert(sizeof(GENESIS_COINBASE_TX_HEX)/sizeof(*GENESIS_COINBASE_TX_HEX) != 1, "GENESIS_COINBASE_TX_HEX must not be empty.");
const uint64_t GENESIS_BLOCK_REWARD                          = UINT64_C(98765432123456789);
const uint64_t GENESIS_BLOCK_TIMESTAMP                       = 1565498348; // This is the unix timestamp

/* This section defines our block reward for for first 300k block */
const uint64_t REWARD_JACKPOT                                = UINT64_C(777787654321);  // 7777.876... ZUM coins
const uint64_t REWARD_MEGA_7                                 = UINT64_C(77787654321);   // 777.876... ZUM coins
const uint64_t REWARD_SUPER_7                                = UINT64_C(29987654321);   // 299.876... ZUM coins
const uint64_t REWARD_LUCKY_7                                = UINT64_C(19987654321);   // 199.876... ZUM coins
const uint64_t REWARD_MAX                                    = UINT64_C(9987654321);    // 99.876... ZUM coins
const uint64_t REWARD_MIN                                    = UINT64_C(1912345678);    // 19.123 ZUM coins
const uint64_t REWARD_V1                                     = UINT64_C(1412345678);    // 14.123... Initial Reward


/* The heights to activate the reward at */
const uint32_t REWARD_V1_HEIGHT                              = 1;
const uint32_t REWARD_V2_HEIGHT                              = 10;  // Height reward switches to random


const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 500000; // 500kb size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 20000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 10000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;

const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;

const uint64_t MINIMUM_FEE                                   = UINT64_C(1000000); // 0.01 ZUM
const uint64_t DEFAULT_FEE                                   = UINT64_C(10000000); // 0.10 ZUM

/* This section defines our minimum and maximum mixin counts required for transactions */
const uint64_t MINIMUM_MIXIN_V1                              = 0;
const uint64_t MAXIMUM_MIXIN_V1                              = 3;

const uint64_t MINIMUM_MIXIN_V2                              = 3;
const uint64_t MAXIMUM_MIXIN_V2                              = 7;

const uint64_t MINIMUM_MIXIN_V3                              = 5;
const uint64_t MAXIMUM_MIXIN_V3                              = 10;

/* The heights to activate the mixin limits at */
const uint32_t MIXIN_LIMITS_V1_HEIGHT                        = 1;
const uint32_t MIXIN_LIMITS_V2_HEIGHT                        = 225000;
const uint32_t MIXIN_LIMITS_V3_HEIGHT                        = 550000;

/* The mixin to use by default with zumwallet and zum-service */
/* DEFAULT_MIXIN_V0 is the mixin used before MIXIN_LIMITS_V1_HEIGHT is started */
const uint64_t DEFAULT_MIXIN_V0                              = 0;
const uint64_t DEFAULT_MIXIN_V1                              = MINIMUM_MIXIN_V1;
const uint64_t DEFAULT_MIXIN_V2                              = MINIMUM_MIXIN_V2;
const uint64_t DEFAULT_MIXIN_V3                              = MINIMUM_MIXIN_V3;

const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(1);
const uint64_t DEFAULT_DUST_THRESHOLD_V2                     = UINT64_C(0);

const uint32_t DUST_THRESHOLD_V2_HEIGHT                      = MIXIN_LIMITS_V2_HEIGHT;
const uint32_t FUSION_DUST_THRESHOLD_HEIGHT_V2               = 225000; // height will be adjusted in future as per requirement


const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;

const size_t   DIFFICULTY_WINDOW                             = 17;
const size_t   DIFFICULTY_WINDOW_V1                          = 17;
const size_t   DIFFICULTY_WINDOW_V2                          = 17;
const uint64_t DIFFICULTY_WINDOW_V3                          = 60;
const uint64_t DIFFICULTY_BLOCKS_COUNT_V3                    = DIFFICULTY_WINDOW_V3 + 1;

const size_t   DIFFICULTY_CUT                                = 0;  // timestamps to cut after sorting
const size_t   DIFFICULTY_CUT_V1                             = 0;
const size_t   DIFFICULTY_CUT_V2                             = 0;
const size_t   DIFFICULTY_LAG                                = 0;  
const size_t   DIFFICULTY_LAG_V1                             = 0;
const size_t   DIFFICULTY_LAG_V2                             = 0;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 200000; // 200kb initial block size
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;
const uint64_t MAX_EXTRA_SIZE                                = 1024;

const uint64_t TRANSACTION_SIGNATURE_COUNT_VALIDATION_HEIGHT = 0;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 3; //seconds, 3 days 
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 3;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = MAX_BLOCK_SIZE_INITIAL * 20 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 1;
const uint32_t UPGRADE_HEIGHT_V3                             = 2;
const uint32_t UPGRADE_HEIGHT_V4                             = 3; 
const uint32_t UPGRADE_HEIGHT_V5                             = 4; // Upgrade height for CN-Zum Variant 2 switch.
const uint32_t UPGRADE_HEIGHT_CURRENT                        = UPGRADE_HEIGHT_V5;

const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

/* Block heights we are going to have hard forks at */
const uint64_t FORK_HEIGHTS[] =
{
  1, // 0
  225000, // 1
  550000, // 2
  775000, // 3
  1000000, // 4 
};

/* MAKE SURE TO UPDATE THIS VALUE WITH EVERY MAJOR RELEASE BEFORE A FORK */
const uint64_t SOFTWARE_SUPPORTED_FORK_INDEX                 = 0;

const uint64_t FORK_HEIGHTS_SIZE = sizeof(FORK_HEIGHTS) / sizeof(*FORK_HEIGHTS);

/* The index in the FORK_HEIGHTS array that this version of the software will
   support. For example, if CURRENT_FORK_INDEX is 3, this version of the
   software will support the fork at 775,000 blocks.

   This will default to zero if the FORK_HEIGHTS array is empty, so you don't
   need to change it manually. */
const uint8_t CURRENT_FORK_INDEX = FORK_HEIGHTS_SIZE == 0 ? 0 : SOFTWARE_SUPPORTED_FORK_INDEX;

static_assert(CURRENT_FORK_INDEX >= 0, "CURRENT FORK INDEX must be >= 0");
/* Make sure CURRENT_FORK_INDEX is a valid index, unless FORK_HEIGHTS is empty */
static_assert(FORK_HEIGHTS_SIZE == 0 || CURRENT_FORK_INDEX < FORK_HEIGHTS_SIZE, "CURRENT_FORK_INDEX out of range of FORK_HEIGHTS!");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "ZumCoin";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;

const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MAJOR_VERSION_5                         =  5;

const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const uint64_t BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  100;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  17936;
const int      RPC_DEFAULT_PORT                              =  17935;
const int      SERVICE_DEFAULT_PORT                          =  17070;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

// P2P Network Configuration Section - This defines our current P2P network version
// and the minimum version for communication between nodes
const uint8_t  P2P_CURRENT_VERSION                           = 1;
const uint8_t  P2P_MINIMUM_VERSION                           = 1;

// This defines the minimum P2P version required for lite blocks propogation
const uint8_t P2P_LITE_BLOCKS_PROPOGATION_VERSION            = 1;

// This defines the number of versions ahead we must see peers before we start displaying
// warning messages that we need to upgrade our software.
const uint8_t  P2P_UPGRADE_WINDOW                            = 1;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

const uint64_t DATABASE_WRITE_BUFFER_MB_DEFAULT_SIZE         = 256;
const uint64_t DATABASE_READ_BUFFER_MB_DEFAULT_SIZE          = 10;
const uint32_t DATABASE_DEFAULT_MAX_OPEN_FILES               = 100;
const uint16_t DATABASE_DEFAULT_BACKGROUND_THREADS_COUNT     = 2;

const char     LATEST_VERSION_URL[]                          = "http://latest.zumcoin.org";
const std::string LICENSE_URL                                = "https://github.com/zumcoin/zumcoin/blob/master/LICENSE";
const static   boost::uuids::uuid CRYPTONOTE_NETWORK         =
{
    {  0xeb, 0x1b, 0x3b, 0x5d, 0xc9, 0x6d, 0x65, 0xd3, 0xaf, 0x3e, 0xb9, 0x3d, 0xc7, 0xfd, 0x54, 0xaf  }
};

const char* const SEED_NODES[] = {
  "sn1.zumcoin.org:17936",
  "sn2.zumcoin.org:17936",
  "sn3.zumcoin.org:17936",
  "sn4.zumcoin.org:17936",

};
} // CryptoNote
