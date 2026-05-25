#include <cctype>
#include <iostream>

/*
 * argc = number of command-line arguments.
 * argv = array of C strings containing those arguments.
 */
int main(int argc, char **argv)
{
    /*
     * If the program is launched with no extra arguments, print the
     * default "megaphone" message required by the subject.
     */
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    /*
     * Start at index 1 because argv[0] is the program name itself.
     * Then walk through each character of each argument.
     */
    for (int i = 1; i < argc; ++i)
    {
        for (int j = 0; argv[i][j] != '\0'; ++j)
        {
            /*
            * std::toupper works on character values, but the input must be
            * converted carefully to avoid undefined behavior.
            */
            std::cout << static_cast<char>(
               std::toupper(static_cast<unsigned char>(argv[i][j])));
        }
    }
    std::cout << std::endl;
    return 0;
}
