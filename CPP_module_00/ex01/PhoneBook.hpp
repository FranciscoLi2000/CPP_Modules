#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <cstddef>

class PhoneBook
{
public:
    PhoneBook();

    void addContact(const Contact &contact);
    bool empty() const;
    std::size_t size() const;

    void displayContacts() const;
    bool showContact(std::size_t index) const;

private:
    Contact contacts_[8];
    std::size_t count_;
    std::size_t nextSlot_;

    std::size_t slotForDisplay(std::size_t index) const;
};

#endif
