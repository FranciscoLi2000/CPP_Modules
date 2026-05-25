#include "Contact.hpp"

#include <iostream>

Contact::Contact()
    : firstName_(), lastName_(), nickname_(), phoneNumber_(), darkestSecret_()
{
}

void Contact::set(const std::string &firstName,
                  const std::string &lastName,
                  const std::string &nickname,
                  const std::string &phoneNumber,
                  const std::string &darkestSecret)
{
    firstName_ = firstName;
    lastName_ = lastName;
    nickname_ = nickname;
    phoneNumber_ = phoneNumber;
    darkestSecret_ = darkestSecret;
}

const std::string &Contact::getFirstName() const
{
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
     * Each member is printed on its own line so the user can inspect the
     * complete contact after selecting it from SEARCH.
     */
    std::cout << "First name: " << firstName_ << std::endl;
    std::cout << "Last name: " << lastName_ << std::endl;
    std::cout << "Nickname: " << nickname_ << std::endl;
    std::cout << "Phone number: " << phoneNumber_ << std::endl;
    std::cout << "Darkest secret: " << darkestSecret_ << std::endl;
}
