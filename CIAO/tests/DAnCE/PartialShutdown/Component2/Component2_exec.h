// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.0
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
#ifndef CIAO_COMPONENT2_EXEC_M1RLIS_H_
#define CIAO_COMPONENT2_EXEC_M1RLIS_H_

#include /**/ "ace/pre.h"

#include "Component2EC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Component2_exec_export.h"
#include "tao/LocalObject.h"

#include <vector>

namespace CIAO_PartialShutdown_Component2_Impl
{
  class Component2_exec_i;

  /**
   * WriteTicker
   */

  class WriteTicker :
    public ACE_Event_Handler
  {
  public:
    WriteTicker (Component2_exec_i &callback);
    int handle_timeout (const ACE_Time_Value &, const void *);
  private:
    /// Maintains a handle that actually process the event
    Component2_exec_i &callback_;
  };

  /**
   * ReadTicker
   */

  class ReadTicker :
    public ACE_Event_Handler
  {
  public:
    ReadTicker (Component2_exec_i &callback);
    int handle_timeout (const ACE_Time_Value &, const void *);
  private:
    /// Maintains a handle that actually process the event
    Component2_exec_i &callback_;
  };

  /**
   * Provider Executor Implementation Class: comp_2_writer_exec_i
   */

  class comp_2_writer_exec_i
    : public virtual ::PartialShutdown::CCM_Writer,
      public virtual ::CORBA::LocalObject
  {
  public:
    comp_2_writer_exec_i (
      ::PartialShutdown::CCM_Component2_Context_ptr ctx,
      Component2_exec_i &callback);
    virtual ~comp_2_writer_exec_i (void);

    //@{
    /** Operations and attributes from PartialShutdown::Writer. */

    virtual
    void write_line (const char * line);
    //@}

  private:
    ::PartialShutdown::CCM_Component2_Context_var ciao_context_;
    Component2_exec_i &callback_;
  };

  /**
   * Provider Executor Implementation Class: comp_2_reader_exec_i
   */

  class comp_2_reader_exec_i
    : public virtual ::PartialShutdown::CCM_Reader,
      public virtual ::CORBA::LocalObject
  {
  public:
    comp_2_reader_exec_i (
      ::PartialShutdown::CCM_Component2_Context_ptr ctx,
      Component2_exec_i &callback);
    virtual ~comp_2_reader_exec_i (void);

    //@{
    /** Operations and attributes from PartialShutdown::Reader. */

    virtual
    ::CORBA::StringSeq * read_lines (void);
    //@}

  private:
    ::PartialShutdown::CCM_Component2_Context_var ciao_context_;
    Component2_exec_i &callback_;
  };

  /**
   * Component Executor Implementation Class: Component2_exec_i
   */

  class Component2_exec_i
    : public virtual Component2_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Component2_exec_i (void);
    virtual ~Component2_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::PartialShutdown::CCM_Writer_ptr
    get_comp_2_writer (void);

    virtual ::PartialShutdown::CCM_Reader_ptr
    get_comp_2_reader (void);
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
    void read_all (void);
    void write_all (void);

    void write_line (const char * line);
    ::CORBA::StringSeq * read_lines (void);
    //@}

  private:
    ::PartialShutdown::CCM_Component2_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::PartialShutdown::CCM_Writer_var ciao_comp_2_writer_;
    ::PartialShutdown::CCM_Reader_var ciao_comp_2_reader_;
    //@}

    //@{
    /** User defined members. */
    WriteTicker * write_ticker_;
    ReadTicker * read_ticker_;
    TAO_SYNCH_MUTEX mutex_;
    typedef std::vector <const char *> Strings;
    Strings strings_;

    //@}

    //@{
    /** User defined private operations. */

    //@}

    /// Get the ACE_Reactor
    ACE_Reactor* reactor (void);
  };

  extern "C" COMPONENT2_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_PartialShutdown_Component2_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
