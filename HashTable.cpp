#include "HashTable.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
using namespace std::chrono;

/* This program utilizes a hash table to traverse a data set of
 * approximately 470,000 words, and return whether a word or set
 * of words was found in the dataset. The program will also
 * display the time it took to find (or not find) the inputs
 * from the user. This is an example main */

int main() {
    string filename = "words.txt";
    ifstream file(filename);

    if (!file) {
        cout << "There was an error opening the file. \n";
        return 1;
    }

    WordSearch ws(200000);

    vector<string> words;
    string word;

    //Loads the words from the dataset
    while (getline(file, word)) {
        words.push_back(word);
    }
    file.close();

    //Inserts data into hash table
    for (const auto& w : words) {
        ws.insert(w);
    }

    cout << "\nEnter word(s). Use spaces to seperate multiple:\n";
    string input;
    getline(cin, input);

    stringstream ss(input);
    vector<string> queries;
    string query;

    while (ss >> query) {
        queries.push_back(query);
    }

    //Timer for successful (or unsuccessful) search
    auto beginSearch = high_resolution_clock::now();

    for (const auto& q : queries) {
        bool found = ws.search(q);
        cout << q << ": " << (found ? "Found!" : "Not Found!") << endl;
    }

    auto stopSearch = high_resolution_clock::now();

    cout << "Search time: " << duration_cast<microseconds>(stopSearch - beginSearch).count() << " microseconds\n";

    return 0;
}
