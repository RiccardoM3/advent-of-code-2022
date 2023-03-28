#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

void addToMap(std::unordered_map<char, int>& map, char c) {
    if (map.find(c) == map.end()) {
        map[c] = 1;
    } else {
        map[c] = map[c] + 1;
    }
}

void removeFromMap(std::unordered_map<char, int>& map, char c) {
    if (map[c] == 1) {
        map.erase(c);
    } else {
        map[c] = map[c] - 1;
    }
}

void part1() {

    int curr = 0;
    std::string line;
    std::getline(std::cin, line);
    
    std::cout << line << std::endl;

    int left = 0;
    int right = 3;

    std::unordered_map<char, int> map;
    addToMap(map, line[0]);
    addToMap(map, line[1]);
    addToMap(map, line[2]);
    addToMap(map, line[3]);

    while (map.size() < 4) {
        removeFromMap(map, line[left]);
        left++;
        right++;
        addToMap(map, line[right]);
    }

    std::cout << (right+1) << std::endl;
}

void part2() {
    
    int curr = 0;
    std::string line;
    std::getline(std::cin, line);
    
    std::cout << line << std::endl;

    int left = 0;
    int right = 13;

    std::unordered_map<char, int> map;
    for (int i = 0; i < 14; i++) {
        addToMap(map, line[i]);
    }

    while (map.size() < 14) {
        removeFromMap(map, line[left]);
        left++;
        right++;
        addToMap(map, line[right]);
    }

    std::cout << (right+1) << std::endl;
}

int main() {
    // part1();
    part2();

    return 0;
}