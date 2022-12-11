#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

//A/X rock
//B/Y paper
//C/Z scizzors

void part1() {
    int score = 0;
    for (std::string line; std::getline(std::cin, line); ) {
        char mine = line[2];
        char theirs = line[0];

        score += mine - 87;

        //Check if won
        if (
            mine == 'X' && theirs == 'C' ||
            mine == 'Y' && theirs == 'A' || 
            mine == 'Z' && theirs == 'B'
        ) {
            score += 6;
        }

        //Check if tied
        else if (
            mine == 'X' && theirs == 'A' ||
            mine == 'Y' && theirs == 'B' || 
            mine == 'Z' && theirs == 'C'
        ) {
            score += 3;
        }

    }

    std::cout << score << std::endl;
}

void part2() {
    int score = 0;

    //Key = opponents choice, value = the option you must pick to win
    std::unordered_map<char, char> choiceToWin = {
        {'A', 'Y'},
        {'B', 'Z'},
        {'C', 'X'}
    };

    //Key = opponents choice, value = the option you must pick to lose
    std::unordered_map<char, char> choiceToLose = {
        {'A', 'Z'},
        {'B', 'X'},
        {'C', 'Y'}
    };

    std::unordered_map<char, char> choiceToTie = {
        {'A', 'X'},
        {'B', 'Y'},
        {'C', 'Z'}
    };

    for (std::string line; std::getline(std::cin, line); ) {
        char mine;
        char strategy = line[2];
        char theirs = line[0];

        switch (strategy) {
            case 'X':   //lose
                mine = choiceToLose[theirs];
                break;
            case 'Z':   //win
                mine = choiceToWin[theirs];
                break;
            case 'Y':   //tie
                mine = choiceToTie[theirs];
                break;
        }

        std::cout << theirs << " " << mine << std::endl; 

        score += mine - 87;

        //Check if won
        if (
            mine == 'X' && theirs == 'C' ||
            mine == 'Y' && theirs == 'A' || 
            mine == 'Z' && theirs == 'B'
        ) {
            score += 6;
        }

        //Check if tied
        else if (
            mine == 'X' && theirs == 'A' ||
            mine == 'Y' && theirs == 'B' || 
            mine == 'Z' && theirs == 'C'
        ) {
            score += 3;
        }

        std::cout << score << std::endl; 

    }

    std::cout << score << std::endl;
}

int main() {
    // part1();
    part2();

    return 0;
}