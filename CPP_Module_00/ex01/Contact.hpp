#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
    Contact();

    /*
     * A single setter keeps the class simple: the caller gathers the data,
     * then hands all fields to the object in one step.
     */
    void set(const std::string &firstName,
             const std::string &lastName,
             const std::string &nickname,
             const std::string &phoneNumber,
             const std::string &darkestSecret);

    /* Getters return read-only access to the stored strings. */
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickname() const;
    const std::string &getPhoneNumber() const;
    const std::string &getDarkestSecret() const;

    /* printFull is used by SEARCH to show the complete contact. */
    void printFull() const;

private:
    std::string firstName_;
    std::string lastName_;
    std::string nickname_;
    std::string phoneNumber_;
    std::string darkestSecret_;
};

#endif
