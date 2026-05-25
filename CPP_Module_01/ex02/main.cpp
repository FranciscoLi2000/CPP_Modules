#include <iostream>
#include <string>

int main()
{
    /*
     * A string object stores the actual characters.
     * The pointer and the reference both point to that same object in memory.
     */
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "String address: " << &brain << std::endl;
    std::cout << "Pointer address: " << stringPTR << std::endl;
    std::cout << "Reference address: " << &stringREF << std::endl;

    std::cout << "String value: " << brain << std::endl;
    std::cout << "Pointer value: " << *stringPTR << std::endl;
    std::cout << "Reference value: " << stringREF << std::endl;
    return 0;
}
