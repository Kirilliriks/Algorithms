//
// Created by KirilliriK on 28.10.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <chrono>

#include "AVLTree.h"

typedef std::vector<std::string> Strings;
typedef std::pair<std::string, std::string> Pair;

const int MAX_STRING_SIZE = 10;

const int FIRST_DATA_SIZE = 1000;

const int SECOND_DATA_SIZE = 10000;

int randomInt(int min, int max);
void generateInputData(Strings &strings, size_t size);

int main() {
    Strings strings;
    AVLTree tree;
    std::map<std::string, std::string> testMap;

    generateInputData(strings, FIRST_DATA_SIZE);

    auto startTime = std::chrono::system_clock::now();
    for (auto &str : strings) {
        tree.addNode(str);
    }
    auto endTime = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> finalTime = endTime - startTime;
    std::cout << "Fill AVL tree with a " << FIRST_DATA_SIZE << " strings take " << finalTime.count() << " milliseconds." << std::endl;

    startTime = std::chrono::system_clock::now();
    for (auto &str : strings) {
        testMap.insert(Pair(str, str));
    }
    endTime = std::chrono::system_clock::now();
    finalTime = endTime - startTime;
    std::cout << "Fill map with a " << FIRST_DATA_SIZE << " strings take " << finalTime.count() << " milliseconds." << std::endl;

    std::cout << "[@@@]" << std::endl;

    strings.clear();
    tree.clear();
    testMap.clear();
    generateInputData(strings, SECOND_DATA_SIZE);

    startTime = std::chrono::system_clock::now();
    for (auto &str : strings) {
        tree.addNode(str);
    }
    endTime = std::chrono::system_clock::now();
    finalTime = endTime - startTime;
    std::cout << "Fill AVL tree with a " << SECOND_DATA_SIZE << " strings " << " take " << finalTime.count() << " milliseconds." << std::endl;

    startTime = std::chrono::system_clock::now();
    for (auto &str : strings) {
        testMap.insert(Pair(str, str));
    }
    endTime = std::chrono::system_clock::now();
    finalTime = endTime - startTime;
    std::cout << "Fill map with a " << SECOND_DATA_SIZE << " strings " << " take " << finalTime.count() << " milliseconds." << std::endl;
    return 0;
}

void generateInputData(Strings &strings, size_t size) {
    static const char alphabet[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    static const size_t alphabetSize = 10 + 26 + 26;
    std::string tmp;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < MAX_STRING_SIZE; j++)
            tmp += alphabet[randomInt(0, alphabetSize)];
        strings.push_back(tmp);
    }
}

int randomInt(int min, int max) {
    std::random_device randomDevice;
    std::mt19937 randomAlgorithm(randomDevice());
    std::uniform_int_distribution<int> dist(min, max);

    return dist(randomAlgorithm);
}