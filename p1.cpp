#include <iostream>
#include <string>
#include <vector>
#include <queue>

void part1() {
    int calCount = 0;
    int maxCalCount = 0;

    for (std::string line; std::getline(std::cin, line); ) {
        if (line != "") {
            int newCalCount = std::stoi(line);
            maxCalCount = std::max(calCount + newCalCount, maxCalCount);
            calCount += std::stoi(line);
            
        } else {
            calCount = 0;
        }
    }

    std::cout << maxCalCount << std::endl;
}

void part2() {
    int calCount = 0;
    std::priority_queue< int, std::vector<int>, std::greater<int> > highestCalories;
    highestCalories.push(0);

    for (std::string line; std::getline(std::cin, line); ) {
        if (line != "") {
            calCount += std::stoi(line);
        } else {
            highestCalories.push(calCount);
            if (highestCalories.size() > 3) {
                highestCalories.pop();
            }
            calCount = 0;
        }
    }

    int totalCal = 0;
    while (highestCalories.size() != 0) {
        totalCal += highestCalories.top();
        highestCalories.pop();
    }

    std::cout << totalCal << std::endl;
}

int main() {
    // part1();
    part2();

    return 0;
}