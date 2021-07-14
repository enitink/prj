#include <iostream>
#include <cstdio>
#include <fstream>
//#include <filesystem>
#include <stdio.h>

using std::ofstream;
using namespace std;
#define DEBUG "DEBUG "
#define INFO "INFO "
#define WARN "WARN "
#define ERROR "ERROR "

#define EOL "\n"

class Logger
{
private:
    // Disable copy constructor  since std::ofstream is not copyable.
    Logger(Logger const &) = delete;

    // Constructor
    explicit Logger()
        : log_file("Magnitude_test.log")
    {
        if (!log_file.is_open())
        {
            throw std::runtime_error("Unable to open log file");
        }
    }

    // Disable copy.
    Logger &operator=(Logger const &) = delete;

public:
    // Cleanup.
    ~Logger()
    {
        log_file.close();
    }

    // Write a single value into log file stream.
    template <typename T>
    void write(T const &v)
    {
        log_file << v;
    }

    // Write multiple values.
    template <typename Arg, typename... Args>
    void write(Arg const &arg, Args const &...args)
    {
        // here we write the first value of the values list.
        write(arg);
        // here we recursively pass the rest values to the function.
        write(args...);
    }

    static Logger *getInstance()
    {
        if (logger_instance == NULL)
        {
            logger_instance = new Logger();
        }
        return logger_instance;
    }

private:
    // Log file stream.
    std::ofstream log_file;

    static Logger *logger_instance;
};

Logger *Logger::logger_instance = NULL;

int main()
{
    Logger *log = Logger::getInstance();
            Logger::getInstance()->write(INFO, "Main program started.", "testing", EOL);

    try
    {

        Logger::getInstance()->write(INFO, "Main program started.", "testing", EOL);
                Logger::getInstance()->write(INFO, "Main program started.", "testing", EOL);

        Logger::getInstance()->write(INFO, "Main program started.", "testing", EOL);

    }
    catch (std::exception &e)
    {
        Logger::getInstance()->write(ERROR, "Exception caught, Error: %s", e.what(), EOL);
    }
    catch (...)
    {
        Logger::getInstance()->write(ERROR, "Excption caught in main.", EOL);
    }
}