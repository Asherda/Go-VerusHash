/* File : verushash.i */
%module VH
%include "std_string.i"
%include "carrays.i"
%include "cdata.i"
%{
#include "verushash.h"
%}

%insert(cgo_comment_typedefs) %{
#cgo LDFLAGS: -L${SRCDIR}/build -l:libverushash.a -lsodium
%}


%include "verushash.h"
