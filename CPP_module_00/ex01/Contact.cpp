#include "Contact.hpp"

#include <iostream>

Contact::Contact()
    : firstName_(), lastName_(), nickname_(), phoneNumber_(), darkestSecret_()
{
    /*
     * Default construction gives us an empty but valid object.
     * Each field starts as an empty string until the user enters data.
     */
}

void Contact::set(const std::string &firstName,
                  const std::string &lastName,
                  const std::string &nickname,
                  const std::string &phoneNumber,
                  const std::string &darkestSecret)
{
    /*
     * We copy all values into the object so the contact keeps its own data
     * after the input variables go out of scope.
     */
    firstName_ = firstName;
    lastName_ = lastName;
    nickname_ = nickname;
    phoneNumber_ = phoneNumber;
    darkestSecret_ = darkestSecret;
}

const std::string &Contact::getFirstName() const
{
    /* Returning a const reference avoids copying the string. */
    return firstName_;
}

const std::string &Contact::getLastName() const
{
    return lastName_;
}

const std::string &Contact::getNickname() const
{
    return nickname_;
}

const std::string &Contact::getPhoneNumber() const
{
    return phoneNumber_;
}

const std::string &Contact::getDarkestSecret() const
{
    return darkestSecret_;
}

void Contact::printFull() const
{
    /*
     * SEARCH uses this function to show every stored field clearly.
     * One line per member keeps the output easy to read.
     */
    std::cout << "First name: " << firstName_ << std::endl;
    std::cout << "Last name: " << lastName_ << std::endl;
    std::cout << "Nickname: " << nickname_ << std::endl;
    std::cout << "Phone number: " << phoneNumber_ << std::endl;
    std::cout << "Darkest secret: " << darkestSecret_ << std::endl;
}
