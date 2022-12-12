#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

void part1() {

    int sumPriorities = 0;
    for (std::string line; std::getline(std::cin, line); ) {
        std::unordered_set<char> seenChars;

        for (int i = 0; i < line.length(); i++) {
            char ch = line[i];

            if (i < line.length() / 2 && seenChars.find(ch) == seenChars.end()) {
                seenChars.insert(ch);
            }

            if (i >= line.length() / 2) {
                if (seenChars.find(ch) != seenChars.end()) {
                    if (ch > 96) {
                        sumPriorities += ch - 96;
                    } else if (ch < 96) {
                        sumPriorities += ch - 64 + 26;
                    }
                    break;
                }
            }
        }

        
    }

    std::cout << sumPriorities << std::endl;
}

void part2() {
    int sumPriorities = 0;

    int type = 0;

    std::unordered_set<char> bag1;
    std::unordered_set<char> bag1and2;

    for (std::string line; std::getline(std::cin, line); ) {

        if (type == 0) {
            for (char ch : line) {
                bag1.insert(ch);
            }
        }
        
        if (type == 1) {
            for (char ch : line) {
                if (bag1.find(ch) != bag1.end()) {
                    bag1and2.insert(ch);
                }
            }    
        }
        
        if (type == 2) {
            for (char ch : line) {
                if (bag1.find(ch) != bag1.end() && bag1and2.find(ch) != bag1and2.end()) {
                    if (ch > 96) {
                        sumPriorities += ch - 96;
                    } else if (ch < 96) {
                        sumPriorities += ch - 64 + 26;
                    }
                    bag1.clear();
                    bag1and2.clear();
                    break;
                }
            } 
        }

        type = (type + 1) % 3; 
    }

    std::cout << sumPriorities << std::endl;
}

int main() {
    // part1();
    part2();

    return 0;
}