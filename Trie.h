#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <cctype>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd; // marks if a word actually ends here

    TrieNode() {
        isEnd = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

    // forcing everything to lowercase
    string toLowerCase(string word) {
        for (char& c : word) {
            c = tolower(static_cast<unsigned char>(c));
        }
        return word;
    }

    // helper
    void collectWords(TrieNode* node, string word, vector<string>& res) {
        if (node == nullptr) return;

        if (node->isEnd) {
            res.push_back(word);
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char next = 'a' + i;

                collectWords(node->children[i], word + next, res);
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // inserts word into trie (builds path if needed)
    void insert(string word) {
        word = toLowerCase(word); // normalize input first

        TrieNode* curr = root;

        for (char c : word) {

            // ignore anything not a-z just in case
            if (c < 'a' || c > 'z') continue;

            int idx = c - 'a';

            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    // checks if full word exists
    bool search(string word) {
        word = toLowerCase(word);

        TrieNode* curr = root;

        for (char c : word) {

            // if weird char -> just fail
            if (c < 'a' || c > 'z') return false;

            int idx = c - 'a';

            // path missing -> word not there
            if (curr->children[idx] == nullptr) {
                return false;
            }

            curr = curr->children[idx];
        }

        return curr->isEnd;
    }

    vector<string> prefixFind(string prefix) {
        prefix = toLowerCase(prefix);

        vector<string> res;
        TrieNode* curr = root;

        for (char c : prefix) {

            if (c < 'a' || c > 'z') return res;

            int idx = c - 'a';

            // if prefix path breaks -> no matches
            if (curr->children[idx] == nullptr) {
                return res;
            }

            curr = curr->children[idx];
        }

        collectWords(curr, prefix, res);

        return res;
    }
};

#endif