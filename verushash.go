// +build ignore

package verushash

import (
	"github.com/asherda/go-verushash/verushash"
	_ "github.com/asherda/go-verushash/verushash/compat"
	_ "github.com/asherda/go-verushash/verushash/crypto"
	_ "github.com/asherda/go-verushash/verushash/crypto/sodium"
	_ "github.com/asherda/go-verushash/verushash/support"
	_ "github.com/asherda/go-verushash/verushash/support/allocators"
	"unsafe"
)

// Initialize verushash object once.
var verusHash = verushash.NewVerushash()

func hashHeader(serializedHeader []byte) {
	hash := make([]byte, 32)
	ptrHash := uintptr(unsafe.Pointer(&hash[0]))
	length := len(serializedHeader)
	if serializedHeader[0] == 4 && serializedHeader[2] >= 1 {
		if length < 144 || serializedHeader[143] < 3 {
			verusHash.Verushash_v2b(string(serializedHeader), length, ptrHash)
		} else {
			if serializedHeader[143] < 4 {
				verusHash.Verushash_v2b1(string(serializedHeader), length, ptrHash)
			} else {
				verusHash.Verushash_v2b2(string(serializedHeader), ptrHash)
			}
		}
	} else {
		verusHash.Verushash(string(serializedHeader), length, ptrHash)
	}
}
