#include <N1ghtTheF0x/LibKitsune/Logger.hpp>

#include <iostream>

#include <N1ghtTheF0x/LibKitsune/Date.hpp>

const char* levelStrings[] = {
    "Info",
    "Error",
    "Warn",
    "Debug"
};

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        Logger::Logger(const char* label): _label(label)
        {
            
        }
        Logger::Logger(const std::string label): _label(label)
        {

        }
        Logger::Logger(const std::stringstream &stream): _label(stream)
        {

        }
        Logger::Logger(const String label): _label(label)
        {
            
        }
        std::ostream &Logger::print(Level level,std::ostream &stream) const
        {
            Date date;
            stream << "[" << date.toTimeString() << "] [" << levelStrings[(u64)level] << "/" << _label << "] ";
            return stream;
        }
        std::ostream &Logger::print(Level level) const
        {
            return print(level,std::cout);
        }
        std::ostream &Logger::info() const
        {
            return print(Level::Info);
        }
        std::ostream &Logger::error() const
        {
            return print(Level::Error,std::cerr);
        }
        std::ostream &Logger::warn() const
        {
            return print(Level::Warn,std::cerr);
        }
        std::ostream &Logger::debug() const
        {
            return print(Level::Debug);
        }
        const String &Logger::label() const
        {
            return _label;
        }
    }
}