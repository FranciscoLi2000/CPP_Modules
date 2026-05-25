#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>

namespace
{
/*
 * The table is limited to 10 characters per field, so longer text is clipped
 * and ends with a dot to show that data was removed.
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
     * The phonebook behaves like a ring buffer: once it is full, the next
     * insertion overwrites the oldest slot instead of growing forever.
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
    if (index >= count_)
        return false;
    contacts_[slotForDisplay(index)].printFull();
    return true;
}
