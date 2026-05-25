#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
        for (int j = 0; argv[i][j] != '\0'; ++j)
        {
            /*
            std::toupper expects an unsigned char value converted to int.
            Casting avoids undefined behavior when char is signed and the
            input contains bytes with the high bit set.
            */
            std::cout << static_cast<char>(
                std::toupper(static_cast<unsigned char>(argv[i][j])));
        }
    }
    std::cout << std::endl;
    return 0;
}
