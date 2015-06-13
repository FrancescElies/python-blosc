/*********************************************************************
  Blosc - Blocked Shuffling and Compression Library

  Author: Francesc Alted <francesc@blosc.org>

  See LICENSES/BLOSC.txt for details about copyright and rights to use.
**********************************************************************/

#ifndef SHUFFLE_COMMON_H
#define SHUFFLE_COMMON_H

/* Macro for specifying an exported function. */
#if defined(_WIN32) && defined(BLOSC_DLL_EXPORT)
  #undef BLOSC_DLL_EXPORT
  #define BLOSC_DLL_EXPORT __declspec(dllexport)
#else
#if (defined(__GNUC__) && __GNUC__ >= 4) || defined(__clang__)
  #undef BLOSC_DLL_EXPORT
  #define BLOSC_DLL_EXPORT __attribute__((visibility("hidden")))
#else
  #undef BLOSC_DLL_EXPORT
  #define BLOSC_DLL_EXPORT
#endif
#endif

/* Define the __SSE2__ symbol if compiling with Visual C++ and
   targeting the minimum architecture level supporting SSE2.
   Other compilers define this as expected and emit warnings
   when it is re-defined. */
#define STRING2(x) #x
#define STRING(x) STRING2(x)


#pragma message("__SSE2__ = " STRING(__SSE2__))
#pragma message("_MSC_VER = " STRING(_MSC_VER))
#pragma message("_M_X64 = " STRING(_M_X64))
#pragma message("_M_IX86 = " STRING(_M_IX86))
#pragma message("_M_IX86_FP = " STRING(_M_IX86_FP))

#if !defined(__SSE2__) && defined(_MSC_VER) && \
    (defined(_M_X64) || (defined(_M_IX86) && _M_IX86_FP >= 2))
  #define __SSE2__
#endif

/* Import standard integer type definitions */
#if defined(_WIN32) && !defined(__MINGW32__)
  #include <windows.h>
  #include "win32/stdint-windows.h"
#else
  #include <stdint.h>
  #include <stddef.h>
  #include <inttypes.h>
  #include <string.h>
#endif  /* _WIN32 */

#endif  /* SHUFFLE_COMMON_H */
