/*
** CPP09 ex02 - PmergeMe
**
** Two containers are used here so we can compare their behaviour while the
** same merge-insert idea is applied to both data structures.
*/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

class PmergeMe
{
public:
static voidrun(int argc, char** argv);

private:
static boolparsePositiveInt(const std::string& text, int& value);
static voidmergeInsertSort(std::vector<int>& numbers);
static voidmergeInsertSort(std::deque<int>& numbers);
static voidprintSequence(const char* label, const std::vector<int>& numbers);
static voidprintTiming(const char* label, std::size_t count, std::clock_t start, std::clock_t end);
};

#endif
