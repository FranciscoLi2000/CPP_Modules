#include "PhoneBook.hpp"

#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

namespace
{
/*
 * Using std::getline lets us keep spaces inside names and secrets.
 * A formatted input operator like std::cin >> value would stop at spaces.
 */
bool readLine(const std::string &prompt, std::string &value)
{
    std::cout << prompt;
    return static_cast<bool>(std::getline(std::cin, value));
}

void readContact(PhoneBook &phoneBook)
{
    Contact contact;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    if (!readLine("First name: ", firstName)
        || !readLine("Last name: ", lastName)
        || !readLine("Nickname: ", nickname)
        || !readLine("Phone number: ", phoneNumber)
        || !readLine("Darkest secret: ", darkestSecret))
        return;

    contact.set(firstName, lastName, nickname, phoneNumber, darkestSecret);
    phoneBook.addContact(contact);
}

bool parseIndex(const std::string &input, std::size_t &index)
{
    /*
     * SEARCH asks for a number, so we parse the whole string and reject any
     * extra characters such as "2abc" or negative values.
     */
    std::istringstream stream(input);
    int value = -1;
    char extra = '\0';

    if (!(stream >> value) || (stream >> extra) || value < 0)
        return false;
    index = static_cast<std::size_t>(value);
    return true;
}

void runSearch(const PhoneBook &phoneBook)
{
    if (phoneBook.empty())
        return;

    phoneBook.displayContacts();

    /*
     * SEARCH asks for an index after the list is shown. The input is parsed
     * carefully so bad text does not crash the program.
     */
    std::cout << "Enter index: ";
    std::string input;
    if (!std::getline(std::cin, input))
        return;

    std::size_t index = 0;
    if (!parseIndex(input, index) || !phoneBook.showContact(index))
        std::cout << "Error: invalid index" << std::endl;
}
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    /*
     * The program stays in a simple loop until the user types EXIT or the
     * input stream closes.
     */
    while (true)
    {
        std::cout << "Enter command: ";
        if (!std::getline(std::cin, command))
            break;
        if (command == "ADD")
            readContact(phoneBook);
        else if (command == "SEARCH")
            runSearch(phoneBook);
        else if (command == "EXIT")
            break;
    }
    return 0;
}
