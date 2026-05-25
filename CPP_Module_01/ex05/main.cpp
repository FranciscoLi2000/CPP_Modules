#include "Karen.hpp"

#include <string>

int main(int argc, char **argv)
{
    /*
     * The demo can print one chosen level, but when no argument is given it
     * walks through all levels so the student can compare the outputs.
     */
    Karen karen;

    if (argc == 2)
    {
        karen.complain(argv[1]);
        return 0;
    }

    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "UNKNOWN"};
    for (int i = 0; i < 5; ++i)
        karen.complain(levels[i]);
    return 0;
}
