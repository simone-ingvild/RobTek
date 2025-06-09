#include <fstream>
#include <iostream>
#include <vector>
#include <string>

// Read all whitespace-separated tokens from a file (as raw strings)
bool readTokens(const std::string& filename, std::vector<std::string>& tokens)
{
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Cannot open " << filename << '\n';
        return false;
    }
    std::string tok;
    while (in >> tok) tokens.push_back(tok);
    return true;
}

// Write tokens to a file in reverse order, separated by single blanks
bool writeTokensReversed(const std::string& filename,
                         const std::vector<std::string>& tokens)
{
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Cannot create " << filename << '\n';
        return false;
    }
    for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) {
        if (it != tokens.rbegin()) out << ' ';
        out << *it;
    }
    out << '\n';
    return true;
}

// Convenience wrapper: read → reverse → write
bool reverseFileTokens(const std::string& inName, const std::string& outName)
{
    std::vector<std::string> tokens;
    if (!readTokens(inName, tokens)) return false;
    return writeTokensReversed(outName, tokens);
}

int main(int argc, char* argv[])
{
    const std::string inName  = (argc > 1) ? argv[1] : "file.csv";
    const std::string outName = "out.csv";

    if (!reverseFileTokens(inName, outName))
        return 1;

    // Optionally echo result to console
    // std::cout << "Reversed tokens written to " << outName << '\n';
    return 0;
}
