// -*- C++ -*-
//$Id$

// The following configuration file contains defines for Borland compilers.

#ifndef ACE_CONFIG_WIN32_BORLAND_H
#define ACE_CONFIG_WIN32_BORLAND_H
#include "ace/pre.h"

#ifndef ACE_CONFIG_WIN32_H
#error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */

#include "config-borland-common.h"

// Automatically define WIN32 macro if the compiler tells us it is our
// target platform.
# if defined (__WIN32__) && !defined (WIN32)
#  define WIN32 1
# endif

// When building a VCL application, the main VCL header file should be
// included before anything else. You can define ACE_HAS_VCL=1 in your
// project settings to have this file included for you automatically.
# if defined (ACE_HAS_VCL) && (ACE_HAS_VCL != 0)
#  include /**/ <vcl.h>
# endif

# define ACE_CC_PREPROCESSOR "CPP32.EXE"

# include "ace/config-win32-common.h"

# define ACE_STRCASECMP_EQUIVALENT ::stricmp
# define ACE_STRNCASECMP_EQUIVALENT ::strnicmp
# define ACE_WCSDUP_EQUIVALENT ::_wcsdup

# define ACE_LACKS_MODE_MASKS 1
# define ACE_WSTRING_HAS_USHORT_SUPPORT 1
# define ACE_HAS_ITOA 1

#ifdef ACE_USES_STD_NAMESPACE_FOR_STDC_LIB
#undef ACE_USES_STD_NAMESPACE_FOR_STDC_LIB
#define ACE_USES_STD_NAMESPACE_FOR_STDC_LIB 1
#endif

#define ACE_NEEDS_DL_UNDERSCORE

#include "ace/post.h"
#endif /* ACE_CONFIG_WIN32_BORLAND_H */
