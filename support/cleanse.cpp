// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://www.opensource.org/licenses/mit-license.php .

#include <iostream>
#include <cstring>
#include "cleanse.h"

void memory_cleanse(void *ptr, size_t len)
{
    std::memset(ptr, 0, len);
}
