
// Copyright (c) 2020 Michael Toutonghi
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "crypto/utilstrencodings.h"
#include "solutiondata.h"

CActivationHeight CConstVerusSolutionVector::activationHeight;
uint160 ASSETCHAINS_CHAINID = uint160(ParseHex("1af5b8015c64d39ab44c60ead8317f9f5a9b6c4c"));

[[noreturn]] void new_handler_terminate()
{
    // Rather than throwing std::bad-alloc if allocation fails, terminate
    // immediately to (try to) avoid chain corruption.
    // Since LogPrintf may itself allocate memory, set the handler directly
    // to terminate first.
    std::set_new_handler(std::terminate);
    fputs("Error: Out of memory. Terminating.\n", stderr);

    // The log was successful, terminate now.
    std::terminate();
};

// checks that the solution stored data for this header matches what is expected, ensuring that the
// values in the header match the hash of the pre-header.
bool CBlockHeader::CheckNonCanonicalData() const
{
    CPBaaSPreHeader pbph(*this);
    CPBaaSBlockHeader pbbh1 = CPBaaSBlockHeader(ASSETCHAINS_CHAINID, pbph);
    CPBaaSBlockHeader pbbh2;

    int32_t idx = GetPBaaSHeader(pbbh2, ASSETCHAINS_CHAINID);
    if (idx != -1)
    {
        if (pbbh1.hashPreHeader == pbbh2.hashPreHeader)
        {
            return true;
        }
    }
    return false;
}

// checks that the solution stored data for this header matches what is expected, ensuring that the
// values in the header match the hash of the pre-header.
bool CBlockHeader::CheckNonCanonicalData(uint160 &cID) const
{
    CPBaaSPreHeader pbph(*this);
    CPBaaSBlockHeader pbbh1 = CPBaaSBlockHeader(cID, pbph);
    CPBaaSBlockHeader pbbh2;
    int32_t idx = GetPBaaSHeader(pbbh2, cID);
    if (idx != -1)
    {
        if (pbbh1.hashPreHeader == pbbh2.hashPreHeader)
        {
            return true;
        }
    }
    return false;
}

uint256 CBlockHeader::GetVerusV2Hash() const
{
    if (hashPrevBlock.IsNull())
    {
        // always use SHA256D for genesis block
        return SerializeHash(*this);
    }
    else
    {
        if (nVersion == VERUS_V2)
        {
            int solutionVersion = CConstVerusSolutionVector::Version(nSolution);

            // in order for this to work, the PBaaS hash of the pre-header must match the header data
            // otherwise, it cannot clear the canonical data and hash in a chain-independent manner
            int pbaasType = CConstVerusSolutionVector::HasPBaaSHeader(nSolution);
            bool debugPrint = false;

            if (pbaasType != 0 && CheckNonCanonicalData())
            {
                CBlockHeader bh = CBlockHeader(*this);
                bh.ClearNonCanonicalData();
                return SerializeVerusHashV2b(bh, solutionVersion);
            }
            else
            {
                return SerializeVerusHashV2b(*this, solutionVersion);
            }
        }
        else
        {
            return SerializeVerusHash(*this);
        }
    }
}

// returns -1 on failure, upon failure, pbbh is undefined and likely corrupted
int32_t CBlockHeader::GetPBaaSHeader(CPBaaSBlockHeader &pbh, const uint160 &cID) const
{
    // find the specified PBaaS header in the solution and return its index if present
    // if not present, return -1
    if (nVersion == VERUS_V2)
    {
        // search in the solution for this header index and return it if found
        CPBaaSSolutionDescriptor d = CVerusSolutionVector::solutionTools.GetDescriptor(nSolution);
        if (CVerusSolutionVector::solutionTools.HasPBaaSHeader(nSolution) != 0)
        {
            int32_t numHeaders = d.numPBaaSHeaders;
            const CPBaaSBlockHeader *ppbbh = CVerusSolutionVector::solutionTools.GetFirstPBaaSHeader(nSolution);
            for (int32_t i = 0; i < numHeaders; i++)
            {
                if ((ppbbh + i)->chainID == cID)
                {
                    pbh = *(ppbbh + i);
                    return i;
                }
            }
        }
    }
    return -1;
}

CPBaaSPreHeader::CPBaaSPreHeader(const CBlockHeader &bh)
{
    hashPrevBlock = bh.hashPrevBlock;
    hashMerkleRoot = bh.hashMerkleRoot;
    hashFinalSaplingRoot = bh.hashFinalSaplingRoot;
    nNonce = bh.nNonce;
    nBits = bh.nBits;
    CPBaaSSolutionDescriptor descr = CConstVerusSolutionVector::GetDescriptor(bh.nSolution);
    if (descr.version >= CConstVerusSolutionVector::activationHeight.ACTIVATE_PBAAS_HEADER)
    {
        hashPrevMMRRoot = descr.hashPrevMMRRoot;
        hashBlockMMRRoot = descr.hashBlockMMRRoot;
    }
}

CPBaaSBlockHeader::CPBaaSBlockHeader(const uint160 &cID, const CPBaaSPreHeader &pbph) : chainID(cID)
{
    CBLAKE2bWriter hw(SER_GETHASH, 0);

    // all core data besides version, and solution, which are shared across all headers 
    hw << pbph;

    hashPreHeader = hw.GetHash();
}
