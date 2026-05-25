#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace
{
/*
 * The file is read into one string so we can search and rebuild it with
 * std::string::find and substr without using the forbidden replace method.
 */
std::string replaceAll(std::string text, const std::string &from, const std::string &to)
{
    std::string::size_type pos = 0;

    while ((pos = text.find(from, pos)) != std::string::npos)
    {
        text = text.substr(0, pos) + to + text.substr(pos + from.length());
        pos += to.length();
    }
    return text;
}

int error(const std::string &message)
{
    std::cerr << message << std::endl;
    return 1;
}
}

int main(int argc, char **argv)
{
    /*
     * This program rewrites a file by replacing every s1 with s2.
     * The whole point is to practice string operations and file streams.
     */
    if (argc != 4 || argv[2][0] == '\0' || argv[3][0] == '\0')
        return error("Usage: ./replace filename s1 s2");

    std::ifstream input(argv[1]);
    if (!input)
        return error("Error: cannot open input file");

    std::ostringstream buffer;
    buffer << input.rdbuf();

    std::ofstream output((std::string(argv[1]) + ".replace").c_str());
    if (!output)
        return error("Error: cannot open output file");

    output << replaceAll(buffer.str(), argv[2], argv[3]);
    return 0;
}
