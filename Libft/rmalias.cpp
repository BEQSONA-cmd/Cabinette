#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

void removeLines(const char* filename, const std::vector<std::string>& linesToRemove) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        perror("Error opening the file");
        exit(1);
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(inFile, line)) {
        if (std::find(linesToRemove.begin(), linesToRemove.end(), line) == linesToRemove.end()) {
            lines.push_back(line);
        }
    }

    inFile.close();

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        perror("Error opening the file");
        exit(1);
    }

    for (std::vector<std::string>::const_iterator it = lines.begin(); it != lines.end(); ++it) {
        outFile << *it << "\n";
    }

    outFile.close();
}

int main() {
    const char* filename = "Makefile";

    std::vector<std::string> linesToRemove;
    linesToRemove.push_back("test: all ");
    linesToRemove.push_back("\t$(CC) main.c libft.a");
    linesToRemove.push_back("\t./a.out");
    linesToRemove.push_back("\t@rm a.out");
    linesToRemove.push_back("\t@make fclean");

    removeLines(filename, linesToRemove);

    return 0;
}
