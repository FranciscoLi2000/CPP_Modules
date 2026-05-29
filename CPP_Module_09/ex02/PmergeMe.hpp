/*
** CPP09 ex02 - PmergeMe
**
** Two containers are used here so we can compare their behaviour while the
** same merge-insert idea is applied to both data structures.
*/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <ctime>
#include <cstddef>
#include <string>
#include <vector>

class PmergeMe
{
public:
	static void run(int argc, char** argv);

private:
	static bool parsePositiveInt(const std::string& text, int& value);
	static void mergeInsertSort(std::vector<int>& numbers);
	static void mergeInsertSort(std::deque<int>& numbers);
	static void printSequence(const char* label, const std::vector<int>& numbers);
	static void printTiming(const char* label, std::size_t count, std::clock_t start, std::clock_t end);
};

#endif
