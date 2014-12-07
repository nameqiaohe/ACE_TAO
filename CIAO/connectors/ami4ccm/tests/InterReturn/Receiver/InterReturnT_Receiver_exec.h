// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/
#ifndef CIAO_INTERRETURNT_RECEIVER_EXEC_1ZDCPF_H_
#define CIAO_INTERRETURNT_RECEIVER_EXEC_1ZDCPF_H_

#include /**/ "ace/pre.h"

#include "InterReturnT_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "InterReturnT_Receiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_InterReturnT_Receiver_Impl
{

  /**
   * Provider Executor Implementation Class: do_my_foo_exec_i
   */

  class do_my_foo_exec_i
    : public virtual ::InterReturnT::CCM_MyFoo,
      public virtual ::CORBA::LocalObject
  {
  public:
    do_my_foo_exec_i (
      ::InterReturnT::CCM_Receiver_Context_ptr ctx);
    virtual ~do_my_foo_exec_i (void);

    //@{
    /** Operations and attributes from InterReturnT::MyFoo. */

    virtual
    void ret_void (const char * in_str,
    ::CORBA::String_out answer,
    ::CORBA::Long_out l_cmd);

    virtual
    ::CORBA::Long ret_long (const char * in_str,
    ::CORBA::String_out answer,
    ::CORBA::Long_out l_cmd);

    virtual
    ::CORBA::Double ret_double (const char * in_str,
    ::CORBA::String_out answer,
    ::CORBA::Long_out l_cmd);

    virtual
    ::InterReturnT::TestStruct * ret_struct (const char * in_str,
    ::CORBA::String_out answer,
    ::CORBA::Long_out l_cmd);

    virtual
    ::InterReturnT::TestArray_slice * ret_array (const char * in_str,
    ::CORBA::String_out answer,
    ::CORBA::Long_out l_cmd);

    virtual
    ::InterReturnT::TestSeq * ret_seq (const char * in_str,
    ::CORBA::String_out answer,
    ::CORBA::Long_out l_cmd);

    virtual
    ::InterReturnT::X_Union * ret_union (const char * in_str,
    ::CORBA::String_out answer,
    ::CORBA::Long_out l_cmd);

    virtual
    ::InterReturnT::test_enum ret_enum (const char * in_str,
    ::CORBA::String_out answer,
    ::CORBA::Long_out l_cmd);
    //@}

  private:
    ::InterReturnT::CCM_Receiver_Context_var ciao_context_;
  };

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  class Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::InterReturnT::CCM_MyFoo_ptr
    get_do_my_foo (void);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined public operations. */
    //@}

  private:
    ::InterReturnT::CCM_Receiver_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::InterReturnT::CCM_MyFoo_var ciao_do_my_foo_;
    //@}

    //@{
    /** User defined members. */
    //@}

    //@{
    /** User defined private operations. */
    //@}
  };

  extern "C" INTERRETURN_T_RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_InterReturnT_Receiver_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
