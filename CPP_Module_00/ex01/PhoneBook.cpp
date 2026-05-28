#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>

namespace
{
/*
 * The phonebook table only has room for 10 visible characters per cell.
 * If the text is longer, we clip it and add a dot to show truncation.
 */
std::string fitField(const std::string &value)
{
    if (value.length() <= 10)
        return value;
    return value.substr(0, 9) + '.';
}
}

PhoneBook::PhoneBook()
    : contacts_(), count_(0), nextSlot_(0)
{
}

void PhoneBook::addContact(const Contact &contact)
{
    /*
     * The subject limits the phonebook to 8 contacts, so we reuse slots in a
     * circle instead of letting the container grow forever.
     */
    contacts_[nextSlot_] = contact;
    nextSlot_ = (nextSlot_ + 1) % 8;
    if (count_ < 8)
        ++count_;
}

bool PhoneBook::empty() const
{
    return count_ == 0;
}

std::size_t PhoneBook::size() const
{
    return count_;
}

std::size_t PhoneBook::slotForDisplay(std::size_t index) const
{
    if (count_ < 8)
        return index;
    return (nextSlot_ + index) % 8;
}

void PhoneBook::displayContacts() const
{
    /*
     * First print the header, then show each stored contact on one row.
     * The index shown to the user is the visible order, not the raw array slot.
     */
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|"
              << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (std::size_t i = 0; i < count_; ++i)
    {
        const std::size_t slot = slotForDisplay(i);

        std::cout << "|" << std::setw(10) << i << "|"
                  << std::setw(10) << fitField(contacts_[slot].getFirstName())
                  << "|" << std::setw(10) << fitField(contacts_[slot].getLastName())
                  << "|" << std::setw(10) << fitField(contacts_[slot].getNickname())
                  << "|" << std::endl;
    }
}

bool PhoneBook::showContact(std::size_t index) const
{
    /*
     * The visible index is converted back to the real slot before printing
     * the full contact information.
     */
    if (index >= count_)
        return false;
    contacts_[slotForDisplay(index)].printFull();
    return true;
}
