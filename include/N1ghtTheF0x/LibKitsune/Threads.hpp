#ifndef __N1GHTTHEF0X_LIBKITSUNE_THREADS_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_THREADS_HPP

#ifndef CAN_THREAD
    #ifdef HAS_THREAD
        #include <thread>
        #define CAN_THREAD 1
        #define STD_THREAD 1
        #define THREAD_ID_TYPE std::thread::id
    #elif _WIN32
        #include <windows.h>
        #define CAN_THREAD 1
        #define WIN32_THREAD 1
        #define THREAD_ID_TYPE DWORD
    #else
        #error Can't use Threads in this enviroment!
    #endif
#endif

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        class Thread
        {
        public:
            typedef void (*Executor)(void *data);
        private:
            const Executor _executor;
#ifdef WIN32_THREAD
            HANDLE _handle;
            THREAD_ID_TYPE _id;
#elif STD_THREAD
            std::thread _handle;
#endif
        public:
            Thread(const Thread&) = delete;
            void operator=(const Thread&) = delete;

            Thread(const Executor Executor);
            Thread(const Executor executor,void* data);
            Thread &join();
            Thread &detach();
            bool joinable() const;
            THREAD_ID_TYPE id() const;
        };
    }
}

#endif