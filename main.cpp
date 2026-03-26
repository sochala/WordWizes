#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include "Trie.h"
#include "HashTable.h"

using namespace std;
using namespace std::chrono;

const string DATASET_PATH = "../resources/words_alpha.txt";
const int HASH_TABLE_SIZE = 200003;

vector<string> loadWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return words;
    }

    string word;
    while (file >> word) {
        words.push_back(word);
    }

    file.close();
    return words;
}

double measureTrieInsert(Trie& trie, const vector<string>& words) {
    auto start = high_resolution_clock::now();

    for (const string& word : words) {
        trie.insert(word);
    }

    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}

double measureHashInsert(WordSearch& hashTable, const vector<string>& words) {
    auto start = high_resolution_clock::now();

    for (const string& word : words) {
        hashTable.insert(word);
    }

    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}

double measureTrieSearch(Trie& trie, const vector<string>& words) {
    auto start = high_resolution_clock::now();

    for (const string& word : words) {
        trie.search(word);
    }

    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}

double measureHashSearch(WordSearch& hashTable, const vector<string>& words) {
    auto start = high_resolution_clock::now();

    for (const string& word : words) {
        hashTable.search(word);
    }

    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}

void runBenchmark(const vector<string>& words) {
    Trie benchmarkTrie;
    WordSearch benchmarkHash(HASH_TABLE_SIZE);

    double trieInsertMs = measureTrieInsert(benchmarkTrie, words);
    double hashInsertMs = measureHashInsert(benchmarkHash, words);
    double trieSearchMs = measureTrieSearch(benchmarkTrie, words);
    double hashSearchMs = measureHashSearch(benchmarkHash, words);

    cout << "\n===== Runtime Comparison =====\n";
    cout << fixed << setprecision(3);
    cout << "Dataset: " << DATASET_PATH << endl;
    cout << "Words loaded: " << words.size() << endl;
    cout << "Trie insert time: " << trieInsertMs << " ms\n";
    cout << "Hash insert time: " << hashInsertMs << " ms\n";
    cout << "Trie search time: " << trieSearchMs << " ms\n";
    cout << "Hash search time: " << hashSearchMs << " ms\n";

    cout << "\nFaster insert: ";
    if (trieInsertMs < hashInsertMs) {
        cout << "Trie\n";
    } else {
        cout << "Hash Table\n";
    }

    cout << "Faster search: ";
    if (trieSearchMs < hashSearchMs) {
        cout << "Trie\n";
    } else {
        cout << "Hash Table\n";
    }
}

void printMenu() {
    cout << "\n===== WordWizes Menu =====\n";
    cout << "1. Load dataset into Trie\n";
    cout << "2. Load dataset into Hash Table\n";
    cout << "3. Search word in Trie\n";
    cout << "4. Search word in Hash Table\n";
    cout << "5. Prefix search in Trie\n";
    cout << "6. Run full runtime benchmark\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    vector<string> words = loadWordsFromFile(DATASET_PATH);

    if (words.empty()) {
        cout << "Dataset could not be loaded.\n";
        cout << "Make sure words_alpha.txt is inside the resources folder.\n";
        return 1;
    }

    Trie trie;
    WordSearch hashTable(HASH_TABLE_SIZE);

    bool trieLoaded = false;
    bool hashLoaded = false;

    int choice;

    do {
        printMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting program.\n";
            return 1;
        }

        if (choice == 1) {
            Trie freshTrie;
            trie = freshTrie;

            double timeMs = measureTrieInsert(trie, words);
            trieLoaded = true;

            cout << "Loaded " << words.size() << " words into Trie.\n";
            cout << fixed << setprecision(3)
                 << "Insert time: " << timeMs << " ms\n";
        }
        else if (choice == 2) {
            WordSearch freshHash(HASH_TABLE_SIZE);
            hashTable = freshHash;

            double timeMs = measureHashInsert(hashTable, words);
            hashLoaded = true;

            cout << "Loaded " << words.size() << " words into Hash Table.\n";
            cout << fixed << setprecision(3)
                 << "Insert time: " << timeMs << " ms\n";
        }
        else if (choice == 3) {
            if (!trieLoaded) {
                cout << "Trie not loaded yet.\n";
                continue;
            }

            string word;
            cout << "Enter word to search in Trie: ";
            cin >> word;

            auto start = high_resolution_clock::now();
            bool found = trie.search(word);
            auto end = high_resolution_clock::now();

            double timeUs = duration<double, micro>(end - start).count();

            cout << (found ? "Word found in Trie.\n" : "Word not found in Trie.\n");
            cout << fixed << setprecision(3)
                 << "Search time: " << timeUs << " microseconds\n";
        }
        else if (choice == 4) {
            if (!hashLoaded) {
                cout << "Hash Table not loaded yet.\n";
                continue;
            }

            string word;
            cout << "Enter word to search in Hash Table: ";
            cin >> word;

            auto start = high_resolution_clock::now();
            bool found = hashTable.search(word);
            auto end = high_resolution_clock::now();

            double timeUs = duration<double, micro>(end - start).count();

            cout << (found ? "Word found in Hash Table.\n" : "Word not found in Hash Table.\n");
            cout << fixed << setprecision(3)
                 << "Search time: " << timeUs << " microseconds\n";
        }
        else if (choice == 5) {
            if (!trieLoaded) {
                cout << "Trie not loaded yet.\n";
                continue;
            }

            string prefix;
            cout << "Enter prefix: ";
            cin >> prefix;

            auto start = high_resolution_clock::now();
            vector<string> matches = trie.prefixFind(prefix);
            auto end = high_resolution_clock::now();

            double timeUs = duration<double, micro>(end - start).count();

            cout << "Matches found: " << matches.size() << '\n';
            for (size_t i = 0; i < matches.size() && i < 20; i++) {
                cout << matches[i] << '\n';
            }
            if (matches.size() > 20) {
                cout << "...and more\n";
            }

            cout << fixed << setprecision(3)
                 << "Prefix search time: " << timeUs << " microseconds\n";
        }
        else if (choice == 6) {
            runBenchmark(words);
        }
        else if (choice == 7) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}