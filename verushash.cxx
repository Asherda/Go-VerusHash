/* File : verushash.cxx */

#include "verushash.h"

#include <stdint.h>
#include <vector>
#include <csignal>
#include <sodium.h>
#include <iostream>
#include "include/verus_hash.h"
#include "solutiondata.h"

#include <sstream>

bool initialized = false;


void Verushash::initialize() {
    if (!initialized)
    {
        CVerusHash::init();
        CVerusHashV2::init();
        if (sodium_init() == -1) {
            // try again
            if (sodium_init() == -1) {
                // failed twice, give up
                // complain first
                cout << "verushash: unable to load sodium_init(), failed to intialize" << endl;
                raise(SIGINT);
            }
       	}
    }
    initialized = true;
}


void Verushash::verushash(const char * bytes, int length, void * ptrResult) {
    if (initialized == false) {
        initialize();
    }
    verus_hash(ptrResult, bytes, length);
}

void Verushash::verushash_v2(const char * bytes, int length, void * ptrResult) {
    CVerusHashV2 vh2(SOLUTION_VERUSHHASH_V2);
    
    if (initialized == false) {
        initialize();
    }

    vh2.Reset();
    vh2.Write((unsigned char *) bytes, length);
    vh2.Finalize((unsigned char *) ptrResult);
}

void Verushash::verushash_v2b(const char * bytes, int length, void * ptrResult) {
    CVerusHashV2 vh2(SOLUTION_VERUSHHASH_V2);
    
    if (initialized == false) {
        initialize();
    }

    vh2.Reset();
    vh2.Write((unsigned char *) bytes, length);
    vh2.Finalize2b((unsigned char *) ptrResult);
}

void Verushash::verushash_v2b1(std::string const bytes, int length, void * ptrResult) {
    CVerusHashV2 vh2b1(SOLUTION_VERUSHHASH_V2_1);

    if (initialized == false) {
        initialize();
    }

    vh2b1.Reset();
    vh2b1.Write((unsigned char *) &bytes[0], length);
    vh2b1.Finalize2b((unsigned char *) ptrResult);
}

void Verushash::verushash_v2b2(std::string const bytes, void * ptrResult)
{
    uint256 result;


    if (initialized == false) {
        initialize();
    }

    CBlockHeader bh;
    CDataStream s(bytes.data(), bytes.data() + bytes.size(), SER_GETHASH, 0);

    try
    {
        s >> bh;
        result = bh.GetVerusV2Hash();
    }
    catch(const std::exception& e)
    {
    }

    memcpy(ptrResult, &result, 32);
}
