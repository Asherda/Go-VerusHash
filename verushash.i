/* File : verushash.i */
%module verushash
%include "std_string.i"
%include "carrays.i"
%include "cdata.i"
%{
#include "verushash.h"
%}

%insert(cgo_comment_typedefs) %{
#cgo LDFLAGS: -L${SRCDIR}  -l:libverushash.a -lsodium
%}


%include "verushash.h"
