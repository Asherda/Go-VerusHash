/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

// source: verushash.i

#define SWIGMODULE verushash

#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if defined(__GNUC__)
#  if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    ifndef GCC_HASCLASSVISIBILITY
#      define GCC_HASCLASSVISIBILITY
#    endif
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>



typedef long long intgo;
typedef unsigned long long uintgo;


# if !defined(__clang__) && (defined(__i386__) || defined(__x86_64__))
#   define SWIGSTRUCTPACKED __attribute__((__packed__, __gcc_struct__))
# else
#   define SWIGSTRUCTPACKED __attribute__((__packed__))
# endif



typedef struct { char *p; intgo n; } _gostring_;
typedef struct { void* array; intgo len; intgo cap; } _goslice_;




#define swiggo_size_assert_eq(x, y, name) typedef char name[(x-y)*(x-y)*-2+1];
#define swiggo_size_assert(t, n) swiggo_size_assert_eq(sizeof(t), n, swiggo_sizeof_##t##_is_not_##n)

swiggo_size_assert(char, 1)
swiggo_size_assert(short, 2)
swiggo_size_assert(int, 4)
typedef long long swiggo_long_long;
swiggo_size_assert(swiggo_long_long, 8)
swiggo_size_assert(float, 4)
swiggo_size_assert(double, 8)

#ifdef __cplusplus
extern "C" {
#endif
extern void crosscall2(void (*fn)(void *, int), void *, int);
extern char* _cgo_topofstack(void) __attribute__ ((weak));
extern void _cgo_allocate(void *, int);
extern void _cgo_panic(void *, int);
#ifdef __cplusplus
}
#endif

static char *_swig_topofstack() {
  if (_cgo_topofstack) {
    return _cgo_topofstack();
  } else {
    return 0;
  }
}

static void _swig_gopanic(const char *p) {
  struct {
    const char *p;
  } SWIGSTRUCTPACKED a;
  a.p = p;
  crosscall2(_cgo_panic, &a, (int) sizeof a);
}




#define SWIG_contract_assert(expr, msg) \
  if (!(expr)) { _swig_gopanic(msg); } else


static void Swig_free(void* p) {
  free(p);
}

static void* Swig_malloc(int c) {
  return malloc(c);
}


#include <string>


typedef struct SWIGCDATA {
    char *data;
    intgo len;
} SWIGCDATA;



static SWIGCDATA cdata_void(void *ptr, int nelements) {



   SWIGCDATA d;
   d.data = (char *) ptr;



   d.len  = nelements;

   return d;
}


struct swigcdata {
  intgo size;
  void *data;
};


#include "verushash.h"

#ifdef __cplusplus
extern "C" {
#endif

void _wrap_Swig_free_verushash_03acba9066aad4fc(void *_swig_go_0) {
  void *arg1 = (void *) 0 ;
  
  arg1 = *(void **)&_swig_go_0; 
  
  Swig_free(arg1);
  
}


void *_wrap_Swig_malloc_verushash_03acba9066aad4fc(intgo _swig_go_0) {
  int arg1 ;
  void *result = 0 ;
  void *_swig_go_result;
  
  arg1 = (int)_swig_go_0; 
  
  result = (void *)Swig_malloc(arg1);
  *(void **)&_swig_go_result = (void *)result; 
  return _swig_go_result;
}


long long _wrap_cdata_verushash_03acba9066aad4fc(intgo _swig_optargc, void *_swig_go_0, intgo _swig_go_1) {
  void *arg1 = (void *) 0 ;
  int arg2 ;
  SWIGCDATA result;
  long long _swig_go_result;
  struct swigcdata *swig_out ;
  
  arg2 = 1;
  arg1 = *(void **)&_swig_go_0; 
  if (_swig_optargc > 0) {
    arg2 = (int)_swig_go_1; 
  }
  
  result = cdata_void(arg1,arg2);
  
  swig_out = (struct swigcdata *)malloc(sizeof(*swig_out));
  if (swig_out) {
    swig_out->size = (&result)->len;
    swig_out->data = malloc(swig_out->size);
    if (swig_out->data) {
      memcpy(swig_out->data, (&result)->data, swig_out->size);
    }
  }
  _swig_go_result = *(long long *)(void **)&swig_out;
  
  return _swig_go_result;
}


void _wrap_memmove_verushash_03acba9066aad4fc(void *_swig_go_0, _gostring_ _swig_go_1, intgo _swig_go_2) {
  void *arg1 = (void *) 0 ;
  char *arg2 = (char *) 0 ;
  int arg3 ;
  
  arg1 = *(void **)&_swig_go_0; 
  
  arg2 = (char *)malloc(_swig_go_1.n + 1);
  memcpy(arg2, _swig_go_1.p, _swig_go_1.n);
  arg2[_swig_go_1.n] = '\0';
  
  arg3 = (int)_swig_go_2; 
  
  memmove(arg1,arg2,arg3);
  
  free(arg2); 
}


void _wrap_Verushash_initialized_set_verushash_03acba9066aad4fc(Verushash *_swig_go_0, bool _swig_go_1) {
  Verushash *arg1 = (Verushash *) 0 ;
  bool arg2 ;
  
  arg1 = *(Verushash **)&_swig_go_0; 
  arg2 = (bool)_swig_go_1; 
  
  if (arg1) (arg1)->initialized = arg2;
  
}


bool _wrap_Verushash_initialized_get_verushash_03acba9066aad4fc(Verushash *_swig_go_0) {
  Verushash *arg1 = (Verushash *) 0 ;
  bool result;
  bool _swig_go_result;
  
  arg1 = *(Verushash **)&_swig_go_0; 
  
  result = (bool) ((arg1)->initialized);
  _swig_go_result = result; 
  return _swig_go_result;
}


void _wrap_Verushash_initialize_verushash_03acba9066aad4fc(Verushash *_swig_go_0) {
  Verushash *arg1 = (Verushash *) 0 ;
  
  arg1 = *(Verushash **)&_swig_go_0; 
  
  (arg1)->initialize();
  
}


void _wrap_Verushash_verushash_verushash_03acba9066aad4fc(Verushash *_swig_go_0, _gostring_ _swig_go_1, intgo _swig_go_2, void *_swig_go_3) {
  Verushash *arg1 = (Verushash *) 0 ;
  char *arg2 = (char *) 0 ;
  int arg3 ;
  void *arg4 = (void *) 0 ;
  
  arg1 = *(Verushash **)&_swig_go_0; 
  
  arg2 = (char *)malloc(_swig_go_1.n + 1);
  memcpy(arg2, _swig_go_1.p, _swig_go_1.n);
  arg2[_swig_go_1.n] = '\0';
  
  arg3 = (int)_swig_go_2; 
  arg4 = *(void **)&_swig_go_3; 
  
  (arg1)->verushash((char const *)arg2,arg3,arg4);
  
  free(arg2); 
}


void _wrap_Verushash_verushash_v2_verushash_03acba9066aad4fc(Verushash *_swig_go_0, _gostring_ _swig_go_1, intgo _swig_go_2, void *_swig_go_3) {
  Verushash *arg1 = (Verushash *) 0 ;
  char *arg2 = (char *) 0 ;
  int arg3 ;
  void *arg4 = (void *) 0 ;
  
  arg1 = *(Verushash **)&_swig_go_0; 
  
  arg2 = (char *)malloc(_swig_go_1.n + 1);
  memcpy(arg2, _swig_go_1.p, _swig_go_1.n);
  arg2[_swig_go_1.n] = '\0';
  
  arg3 = (int)_swig_go_2; 
  arg4 = *(void **)&_swig_go_3; 
  
  (arg1)->verushash_v2((char const *)arg2,arg3,arg4);
  
  free(arg2); 
}


void _wrap_Verushash_verushash_v2b_verushash_03acba9066aad4fc(Verushash *_swig_go_0, _gostring_ _swig_go_1, intgo _swig_go_2, void *_swig_go_3) {
  Verushash *arg1 = (Verushash *) 0 ;
  char *arg2 = (char *) 0 ;
  int arg3 ;
  void *arg4 = (void *) 0 ;
  
  arg1 = *(Verushash **)&_swig_go_0; 
  
  arg2 = (char *)malloc(_swig_go_1.n + 1);
  memcpy(arg2, _swig_go_1.p, _swig_go_1.n);
  arg2[_swig_go_1.n] = '\0';
  
  arg3 = (int)_swig_go_2; 
  arg4 = *(void **)&_swig_go_3; 
  
  (arg1)->verushash_v2b((char const *)arg2,arg3,arg4);
  
  free(arg2); 
}


void _wrap_Verushash_verushash_v2b1_verushash_03acba9066aad4fc(Verushash *_swig_go_0, _gostring_ _swig_go_1, intgo _swig_go_2, void *_swig_go_3) {
  Verushash *arg1 = (Verushash *) 0 ;
  std::string arg2 ;
  int arg3 ;
  void *arg4 = (void *) 0 ;
  
  arg1 = *(Verushash **)&_swig_go_0; 
  (&arg2)->assign(_swig_go_1.p, _swig_go_1.n); 
  arg3 = (int)_swig_go_2; 
  arg4 = *(void **)&_swig_go_3; 
  
  (arg1)->verushash_v2b1(arg2,arg3,arg4);
  
}


void _wrap_Verushash_verushash_v2b2_verushash_03acba9066aad4fc(Verushash *_swig_go_0, _gostring_ _swig_go_1, void *_swig_go_2) {
  Verushash *arg1 = (Verushash *) 0 ;
  std::string arg2 ;
  void *arg3 = (void *) 0 ;
  
  arg1 = *(Verushash **)&_swig_go_0; 
  (&arg2)->assign(_swig_go_1.p, _swig_go_1.n); 
  arg3 = *(void **)&_swig_go_2; 
  
  (arg1)->verushash_v2b2(arg2,arg3);
  
}


Verushash *_wrap_new_Verushash_verushash_03acba9066aad4fc() {
  Verushash *result = 0 ;
  Verushash *_swig_go_result;
  
  
  result = (Verushash *)new Verushash();
  *(Verushash **)&_swig_go_result = (Verushash *)result; 
  return _swig_go_result;
}


void _wrap_delete_Verushash_verushash_03acba9066aad4fc(Verushash *_swig_go_0) {
  Verushash *arg1 = (Verushash *) 0 ;
  
  arg1 = *(Verushash **)&_swig_go_0; 
  
  delete arg1;
  
}


#ifdef __cplusplus
}
#endif

