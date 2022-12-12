#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

void part1() {

    std::cout << count << std::endl;
}

void part2() {
    int count = 0;
    for (std::string line; std::getline(std::cin, line); ) {
        std::string line1 = line.substr(0, line.find(","));
        std::string line2 = line.substr(line.find(",")+1, line.length());

        int line1delimIndex = line1.find("-");
        int line2delimIndex = line2.find("-");
        int line1num1 = std::stoi(line1.substr(0, line1delimIndex));
        int line1num2 = std::stoi(line1.substr(line1delimIndex+1, line1.length()));
        int line2num1 = std::stoi(line2.substr(0, line2delimIndex));
        int line2num2 = std::stoi(line2.substr(line2delimIndex+1, line2.length()));

        // std::cout << line1num1 << " " << line1num2 << " " << line2num1 << " " << line2num2 << std::endl;

        if (
            (line1num1 <= line2num2 && line2num1 <= line1num2)
            ) {
            count++;
        }

    }

    std::cout << count << std::endl;
}

int main() {
    // part1();
    part2();

    return 0;
}