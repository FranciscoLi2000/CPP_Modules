#include <cctype>
#include <iostream>

/*
 * This exercise is about command-line arguments:
 * - argc tells us how many arguments were passed.
 * - argv stores each argument as a C-style string (a char array ending with '\0').
 */
int main(int argc, char **argv)
{
    /*
     * If there are no words after the program name, we must print the
     * subject's default "megaphone" message.
     */
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    /*
     * argv[0] is always the program name, so we start at 1.
     * We then visit every character in every argument one by one.
     */
    for (int i = 1; i < argc; ++i)
    {
        for (int j = 0; argv[i][j] != '\0'; ++j)
        {
            /*
            * std::toupper expects an unsigned char value in the int range.
            * Casting first avoids undefined behavior for non-ASCII bytes.
            */
            std::cout << static_cast<char>(
               std::toupper(static_cast<unsigned char>(argv[i][j])));
        }
    }
    std::cout << std::endl;
    return 0;
}
