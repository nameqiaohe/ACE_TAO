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
#ifndef CIAO_GETCOMP_RECEIVER_EXEC_ILLRIY_H_
#define CIAO_GETCOMP_RECEIVER_EXEC_ILLRIY_H_

#include /**/ "ace/pre.h"

#include "GetComp_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "GetComp_Receiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_GetComp_Receiver_Impl
{

  /**
   * Provider Executor Implementation Class: do_my_foo_exec_i
   */

  class do_my_foo_exec_i
    : public virtual ::GetComp::CCM_MyFoo,
      public virtual ::CORBA::LocalObject
  {
  public:
    do_my_foo_exec_i (
      ::GetComp::CCM_Receiver_Context_ptr ctx);
    virtual ~do_my_foo_exec_i (void);

    //@{
    /** Operations and attributes from GetComp::MyFoo. */

    virtual
    ::CORBA::Long foo (const char * in_str,
    ::CORBA::String_out answer);
    //@}

  private:
    ::GetComp::CCM_Receiver_Context_var ciao_context_;
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

    virtual ::GetComp::CCM_MyFoo_ptr
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
    ::GetComp::CCM_Receiver_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::GetComp::CCM_MyFoo_var ciao_do_my_foo_;
    //@}

    //@{
    /** User defined members. */

    //@}

    //@{
    /** User defined private operations. */

    //@}
  };

  extern "C" GETCOMP_T_RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_GetComp_Receiver_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
