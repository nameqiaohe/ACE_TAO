// $Id$

#include "simpleI.h"

int
main( int argc, char *argv[] )
{
  ACE_TRY_NEW_ENV
    {

      CORBA::ORB_var orb = CORBA::ORB_init(argc, argv, ""
                                           TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Object_var obj = orb->resolve_initial_references("RootPOA"
                                                              TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      PortableServer::POA_var poa = PortableServer::POA::_narrow(obj.in()
                                                                 TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var man = poa->the_POAManager(TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      man->activate(TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      simple_i simp;

      PortableServer::ObjectId_var objId = poa->activate_object(&simp
                                                                TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      orb->run(TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }

  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Exception in main():");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}
