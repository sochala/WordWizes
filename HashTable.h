#ifndef DSA_PROJECT_2B_HASHTABLE_H
#define DSA_PROJECT_2B_HASHTABLE_H

#include <string>
#include <vector>
#include <list>
#include <chrono>

using namespace std;
using namespace std::chrono;

class WordSearch {
private:
    vector<list<string>> table;
    int size;

    int hashFunction(const string& key) {
        return std::hash<string>{}(key) % size;
    }

public:
    WordSearch(int tableSize) {
        size = tableSize;
        table.resize(size);
    }

    void insert(const string& word) {
        int index = hashFunction(word);

        for (const auto& w : table[index]) {
            if (w == word) return; //Stops duplicates
        }

        table[index].push_back(word);
    }
    bool search(const string& word) {
        int index = hashFunction(word);

        for (const auto& w : table[index]) {
            if (w == word)
                return true;
        }
        return false;
    }
};
#endif