// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.dre.vanderbilt.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:887

#ifndef _TAO_IDL_RTCORBA_RT_PROTOCOLPROPERTIESA_H_
#define _TAO_IDL_RTCORBA_RT_PROTOCOLPROPERTIESA_H_

#include /**/ "ace/pre.h"

#include /**/ "tao/RTCORBA/rtcorba_export.h"
#define TAO_RTCORBA_SAFE_INCLUDE
#include "tao/RTCORBA/RT_ProtocolPropertiesC.h"
#undef TAO_RTCORBA_SAFE_INCLUDE


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:59

namespace RTCORBA
{

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_RTCORBA_Export ::CORBA::TypeCode_ptr const _tc_ProtocolProperties;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:86

} // module RTCORBA


// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:54



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace RTCORBA
{
  TAO_RTCORBA_Export void operator<<= ( ::CORBA::Any &, ProtocolProperties_ptr); // copying
  TAO_RTCORBA_Export void operator<<= ( ::CORBA::Any &, ProtocolProperties_ptr *); // non-copying
  TAO_RTCORBA_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ProtocolProperties_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_RTCORBA_Export void operator<<= (::CORBA::Any &, RTCORBA::ProtocolProperties_ptr); // copying
TAO_RTCORBA_Export void operator<<= (::CORBA::Any &, RTCORBA::ProtocolProperties_ptr *); // non-copying
TAO_RTCORBA_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, RTCORBA::ProtocolProperties_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

TAO_END_VERSIONED_NAMESPACE_DECL



#include /**/ "ace/post.h"

#endif /* ifndef */
