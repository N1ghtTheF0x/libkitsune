#include <N1ghtTheF0x/LibKitsune/Threads.hpp>

#ifdef CAN_THREAD
#ifdef WIN32_THREAD

DWORD WINAPI win32_ThreadFunction(LPVOID lpParam)
{

}

#endif
namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        Thread::Thread(const Executor executor): Thread(executor,0)
        {

        }
#ifdef WIN32_THREAD
        Thread::Thread(const Executor executor,void* data): _executor(executor)
        {
            _handle = CreateThread(
                NULL,
                0,
                win32_ThreadFunction,
                data,
                0,
                &_id
            );
        }
#elif STD_THREAD
        Thread::Thread(const Executor executor,void* data): _executor(executor), _handle(executor,data)
        {

        }
#endif
        Thread &Thread::join()
        {
#ifdef STD_THREAD
            _handle.join();
#endif
            return *this;
        }
        Thread &Thread::detach()
        {
#ifdef STD_THREAD
            _handle.detach();
#endif
            return *this;
        }
        THREAD_ID_TYPE Thread::id() const
        {
#ifdef STD_THREAD
            return _handle.get_id();
#endif
        }
        bool Thread::joinable() const
        {
#ifdef STD_THREAD
            return _handle.joinable();
#endif
        }
    }
}

#endif