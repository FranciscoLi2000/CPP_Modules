#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <cstddef>

class PhoneBook
{
public:
    PhoneBook();

    /*
     * addContact stores one new entry. The book has a fixed size, so old
     * entries are overwritten once all 8 slots are full.
     */
    void addContact(const Contact &contact);
    bool empty() const;
    std::size_t size() const;

    /* displayContacts prints the searchable table shown to the user. */
    void displayContacts() const;
    /* showContact prints the full details for the chosen visible index. */
    bool showContact(std::size_t index) const;

private:
    Contact contacts_[8];
    std::size_t count_;
    std::size_t nextSlot_;

    std::size_t slotForDisplay(std::size_t index) const;
};

#endif
