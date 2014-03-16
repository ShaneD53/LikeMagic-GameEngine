#include "Configuration.hpp"
#include <fstream>
#include <sstream>

using namespace std;
using namespace IoDbg;

#ifndef NO_LOAD_GDB

#define BOOST_FILESYSTEM_VERSION 3
#include "boost/process.hpp"
namespace bp = ::boost::process;

#endif

#if defined(_WIN32)
    char const* logFileName = ".\\debug.log";
#else
    char const* logFileName = "./debug.log";
#endif

Configuration::~Configuration() {}

class ReplayConfiguration : public Configuration
{
private:

    std::ifstream replay_file;
    std::ofstream log_file;
    std::stringstream dummy;

public:

    ReplayConfiguration(string replayFileName)
        : replay_file(replayFileName),
          log_file(logFileName, ofstream::out)
    {
        // If we did not do this, the dummy stringstream
        // would return one empty read, which affects testing.
        dummy.setstate(ios_base::eofbit);
    }

    virtual ~ReplayConfiguration()
    {
    }

    istream& get_from_log()
    {
        return replay_file;
    }

    ostream& get_to_log()
    {
        return log_file;
    }

    istream& get_from_user()
    {
        return dummy;
    }

    ostream& get_to_user()
    {
        return cout;
    }

    istream& get_from_gdb()
    {
        return dummy;
    }

    ostream& get_to_gdb()
    {
        return cout;
    }

    istream& get_from_gdb_err()
    {
        return dummy;
    }

    ostream& get_to_user_err()
    {
        return cerr;
    }
};

class NormalConfiguration : public Configuration
{
private:

    std::stringstream dummy_replay_file;
    std::ofstream log_file;

#ifdef NO_LOAD_GDB

    std::stringstream dummy;

#else

    bp::child gdb_process;

    bp::child start_gdb(int argc, char* argv[])
    {
        std::vector<std::string> args;
        args.push_back("/usr/bin/gdb");

        for (int i=1; i<argc; ++i)
            args.push_back(argv[i]);

        std::string exec = args[0];

        bp::context ctx;
        ctx.stdout_behavior = bp::capture_stream();
        ctx.stderr_behavior = bp::capture_stream();
        ctx.stdin_behavior = bp::capture_stream();

        return bp::launch(exec, args, ctx);
    }

#endif

public:

    NormalConfiguration(int argc, char* argv[])
        :
          log_file(logFileName, ofstream::out)
#ifndef NO_LOAD_GDB
        ,gdb_process(start_gdb(argc, argv))
#endif

    {
#ifdef NO_LOAD_GDB
        // If we did not do this, the dummy stringstream
        // would return one empty read, which is undesirable.
        dummy.setstate(ios_base::eofbit);
#endif

        // If we did not do this, the dummy stringstream
        // would return one empty read, which is undesirable.
        dummy_replay_file.setstate(ios_base::eofbit);
    }

    virtual ~NormalConfiguration()
    {
        // Doesn't work?
        //bp::status s = gdb_process.wait();
        //std::cerr << "exited = " << s.exited() << " exit_status = " << s.exit_status() << std::endl;
    }

    istream& get_from_log()
    {
        return dummy_replay_file;
    }

    ostream& get_to_log()
    {
        return log_file;
    }

    istream& get_from_user()
    {
        return std::cin;
    }

    ostream& get_to_user()
    {
        return cout;
    }

    istream& get_from_gdb()
    {
#ifndef NO_LOAD_GDB
        return gdb_process.get_stdout();
#else
        return dummy;
#endif
    }

    ostream& get_to_gdb()
    {
#ifndef NO_LOAD_GDB
        return gdb_process.get_stdin();
#else
        return cout;
#endif
    }

    istream& get_from_gdb_err()
    {
#ifndef NO_LOAD_GDB
        return gdb_process.get_stderr();
#else
        return dummy;
#endif
    }

    ostream& get_to_user_err()
    {
        return cerr;
    }
};

boost::shared_ptr<Configuration> IoDbg::getConfiguration(int argc, char* argv[])
{
    if (argc == 3 && string(argv[1]) == string("--replay-log"))
        return boost::shared_ptr<Configuration>(new ReplayConfiguration(string(argv[2])));
    else
        return boost::shared_ptr<Configuration>(new NormalConfiguration(argc, argv));
}
