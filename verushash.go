package verushash

import (
	"github.com/hashpool/go-verushash/verushash"
	"unsafe"
)

// Initialize verushash object once.
var verusHash = VH.NewVerushash()

func VerusHash(serializedHeader []byte) []byte {
	hash := make([]byte, 32)
	ptrHash := uintptr(unsafe.Pointer(&hash[0]))
	length := len(serializedHeader)
	verusHash.Verushash(string(serializedHeader), length, ptrHash)
	return hash
}

func VerusHash_V2B(serializedHeader []byte) []byte {
	hash := make([]byte, 32)
	ptrHash := uintptr(unsafe.Pointer(&hash[0]))
	length := len(serializedHeader)
	verusHash.Verushash_v2b(string(serializedHeader), length, ptrHash)
	return hash
}

func VerusHash_V2B1(serializedHeader []byte) []byte {
	hash := make([]byte, 32)
	ptrHash := uintptr(unsafe.Pointer(&hash[0]))
	length := len(serializedHeader)
	verusHash.Verushash_v2b1(string(serializedHeader), length, ptrHash)
	return hash
}

func VerusHash_V2B2(serializedHeader []byte) []byte {
	hash := make([]byte, 32)
	ptrHash := uintptr(unsafe.Pointer(&hash[0]))
	verusHash.Verushash_v2b2(string(serializedHeader), ptrHash)
	return hash
}
