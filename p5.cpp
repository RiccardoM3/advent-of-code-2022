#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

void part1() {

    int numStacks = -1;
    std::vector< std::stack<char> > stacks1;
    std::vector< std::stack<char> > stacks2;

    int state = 0;
    for (std::string line; std::getline(std::cin, line); ) {
        if (numStacks == -1) {
            numStacks = (line.length()+1)/4;
            stacks1.resize(numStacks);
            stacks2.resize(numStacks);
        }

        //change state to 1, and reverse each stack
        if (state == 0 && line.length() >= 1 && line[1] == '1') {
            state = 1;

            for (int i = 0; i < stacks1.size(); i++) {
                while (!stacks1[i].empty()) {
                    stacks2[i].push(stacks1[i].top());
                    stacks1[i].pop();
                }
            }
        }

        //read boxes
        if (state == 0) {
             for (int i = 0; i < numStacks; i++) {
                char letter = line[i*4 + 1];
                if (letter != ' ') {
                    stacks1[i].push(letter);
                }
            }
        }

        //handle the moves
        if (state == 1 && line[0] == 'm') {
            int numMove, moveFrom, moveTo;
            sscanf(line.c_str(), "move %d from %d to %d", &numMove, &moveFrom, &moveTo);
            std::cout << numMove << " " << moveFrom << " " << moveTo << std::endl;

            while (numMove > 0) {
                stacks2[moveTo-1].push(stacks2[moveFrom-1].top());
                stacks2[moveFrom-1].pop();
                
                numMove--;
            }
        }
    }

    std::string output;
    for (auto stack : stacks2) {
        output += stack.top();
    }

    std::cout << output << std::endl;
}

void part2() {
    
    int numStacks = -1;
    std::vector< std::stack<char> > stacks1;
    std::vector< std::stack<char> > stacks2;

    int state = 0;
    for (std::string line; std::getline(std::cin, line); ) {
        if (numStacks == -1) {
            numStacks = (line.length()+1)/4;
            stacks1.resize(numStacks);
            stacks2.resize(numStacks);
        }

        //change state to 1, and reverse each stack
        if (state == 0 && line.length() >= 1 && line[1] == '1') {
            state = 1;

            for (int i = 0; i < stacks1.size(); i++) {
                while (!stacks1[i].empty()) {
                    stacks2[i].push(stacks1[i].top());
                    stacks1[i].pop();
                }
            }
        }

        //read boxes
        if (state == 0) {
             for (int i = 0; i < numStacks; i++) {
                char letter = line[i*4 + 1];
                if (letter != ' ') {
                    stacks1[i].push(letter);
                }
            }
        }

        //handle the moves
        if (state == 1 && line[0] == 'm') {
            int numMove, moveFrom, moveTo;
            sscanf(line.c_str(), "move %d from %d to %d", &numMove, &moveFrom, &moveTo);
            std::cout << numMove << " " << moveFrom << " " << moveTo << std::endl;

            std::stack<char> moveBoxQueue;
            for (int i = 0; i < numMove; i++) {
                moveBoxQueue.push(stacks2[moveFrom-1].top());
                stacks2[moveFrom-1].pop();
            }

            for (int i = 0; i < numMove; i++) {
                stacks2[moveTo-1].push(moveBoxQueue.top());
                moveBoxQueue.pop();
            }
        }
    }

    std::string output;
    for (auto stack : stacks2) {
        output += stack.top();
    }

    std::cout << output << std::endl;
}

int main() {
    // part1();
    part2();

    return 0;
}