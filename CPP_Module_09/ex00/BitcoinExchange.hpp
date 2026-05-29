/*
** CPP09 ex00 - Bitcoin Exchange
**
** This exercise introduces map-based lookups.
** We store historical prices by date, then use the sorted nature of std::map
** to find the closest previous date when an exact match is missing.
*/

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> _rates;

    static std::string trim(const std::string& text);
    static bool isValidDate(const std::string& date);
    static bool parseValue(const std::string& text, double& value);
    double rateForDate(const std::string& date) const;

public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange(void);

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename) const;
};

#endif
