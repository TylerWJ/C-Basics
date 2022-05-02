#include <iostream>

class Log 
{

public: // fields/variables

    enum Level {
        LevelError = 0, LevelWarning, LevelInfo // 'LevelError' and not just 'Error' because their is also a function in this namespace with the name 'Error'
    };

private:
    Level m_LogLevel = LevelInfo; // m stands for class private members


public: // methods
    void SetLevel(Level level)
    {
        m_LogLevel = level;
    }

    // Level = Error    --> shows only error
    // Level = Warning  --> shows errors and warnings
    // Level = Info     --> shows errors, warnings, and info

    void Error(const char* message)
    {
        if (m_LogLevel >= LevelError)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    void Warn(const char* message)
    {
        if (m_LogLevel >= LevelWarning)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    void Info(const char* message)
    {
        if (m_LogLevel >= LevelInfo)
            std::cout << "[INFO]: " << message << std::endl;
    }
};