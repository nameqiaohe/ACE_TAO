// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.2
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

#include "RG_LateBinding_Receiver_exec.h"
#include "RG_LateBinding_Receiver_impl.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"

namespace CIAO_RG_LateBinding_Receiver_Impl
{

  /**
   * Facet Executor Implementation Class: info_get_status_exec_i
   */

  info_get_status_exec_i::info_get_status_exec_i (
        ::RG_LateBinding::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::RG_LateBinding::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_get_status_exec_i::~info_get_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  info_get_status_exec_i::on_requested_deadline_missed (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_get_status_exec_i::on_sample_lost (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleLostStatus & /* status */)
  {
    /* Your code here. */
  }

  /**
   * Facet Executor Implementation Class: info_read_status_exec_i
   */

  info_read_status_exec_i::info_read_status_exec_i (
        ::RG_LateBinding::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::RG_LateBinding::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_read_status_exec_i::~info_read_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  info_read_status_exec_i::on_requested_deadline_missed (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_read_status_exec_i::on_sample_lost (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleLostStatus & /* status */)
  {
    /* Your code here. */
  }

  /**
   * Facet Executor Implementation Class: reader_start_exec_i
   */

  reader_start_exec_i::reader_start_exec_i (
        ::RG_LateBinding::CCM_Receiver_Context_ptr ctx,
        Receiver_exec_i &callback)
    : ciao_context_ (
        ::RG_LateBinding::CCM_Receiver_Context::_duplicate (ctx))
      , callback_ (callback)
  {
  }

  reader_start_exec_i::~reader_start_exec_i (void)
  {
  }

  // Operations from ::ReaderStarter

  void
  reader_start_exec_i::start_read (void)
  {
    this->callback_.start_read ();
  }

  void
  reader_start_exec_i::set_reader_properties (::CORBA::UShort nr_keys,
  ::CORBA::UShort nr_iterations)
  {
    this->callback_.keys (nr_keys);
    this->callback_.iterations (nr_iterations);
  }

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void)
    : impl_ (0)
      , keys_ (5)
      , iterations_ (0)
  {
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
    delete this->impl_;
  }

  // Supported operations and attributes.

  void
  Receiver_exec_i::start_read (void)
  {
    ACE_NEW_THROW_EX (this->impl_,
                      RG_LateBinding_Receiver_impl (
                        this->ciao_context_.in (),
                        this->iterations_,
                        this->keys_),
                      ::CORBA::INTERNAL ());
    this->impl_->start ();
  }

  void
  Receiver_exec_i::keys (::CORBA::UShort keys)
  {
    this->keys_ = keys;
  }

  void
  Receiver_exec_i::iterations (::CORBA::UShort iterations)
  {
    this->iterations_ = iterations;
  }
  // Component attributes and port operations.

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_get_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_get_status_.in ()))
      {
        info_get_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_get_status_exec_i (
            this->ciao_context_.in ()),
            ::CCM_DDS::CCM_PortStatusListener::_nil ());

          this->ciao_info_get_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_get_status_.in ());
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_read_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_read_status_.in ()))
      {
        info_read_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_read_status_exec_i (
            this->ciao_context_.in ()),
            ::CCM_DDS::CCM_PortStatusListener::_nil ());

          this->ciao_info_read_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_read_status_.in ());
  }

  ::CCM_ReaderStarter_ptr
  Receiver_exec_i::get_start_reading (void)
  {
    if ( ::CORBA::is_nil (this->ciao_reader_start_.in ()))
      {
        reader_start_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          reader_start_exec_i (
            this->ciao_context_.in (),
            *this),
            ::CCM_ReaderStarter::_nil ());

          this->ciao_reader_start_ = tmp;
      }

    return
      ::CCM_ReaderStarter::_duplicate (
        this->ciao_reader_start_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::RG_LateBinding::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_RG_LateBinding_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
