// $Id$

#include "Client_Task.h"
#include "ace/Get_Opt.h"

static const ACE_TCHAR *ior = ACE_TEXT("file://server.ior");
static size_t nthreads = 1;

int
parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT("k:n:"));
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        ior = get_opts.opt_arg ();
        break;
      case 'n':
        nthreads = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-k <ior> "
                           "-n <nthreads> "
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  try
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv);

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var tmp =
        orb->string_to_object(ior);

      Test::Big_Reply_var reply_gen =
        Test::Big_Reply::_narrow(tmp.in ());

      if (CORBA::is_nil (reply_gen.in ()))
        {
          ACE_ERROR_RETURN ((LM_DEBUG,
                             "Nil coordinator reference <%s>\n",
                             ior),
                            1);
        }


      Client_Task client_task (reply_gen.in (),
                               10,
                               ACE_Thread_Manager::instance ());

      if (client_task.activate (THR_NEW_LWP | THR_JOINABLE,
                                nthreads, 1) == -1)
        {
          ACE_ERROR ((LM_ERROR, "Error activating client task\n"));
        }
      ACE_Thread_Manager::instance ()->wait ();

      reply_gen->shutdown ();

      orb->destroy ();
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return 1;
    }

  return 0;
}
