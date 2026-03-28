# COP3530 - WordWizes Project

Overview

This project implements a word-processing system using efficient data structures (Trie and/or Hash Table). It reads a dataset of words and performs operations like loading and searching a word and comparing runtime performances.

---

 Requirements

* C++ (C++11 or higher)
* CMake
* CLion IDE (recommended)

---

Clone the Repository
-Using CLion, in the main screen, click clone repository and paste this url
https://github.com/sochala/WordWizes.git

--
Dataset Setup (REQUIRED)

⚠️ The dataset is NOT included in the repository.

Download dataset:
[curl -o resources/words_alpha.txt https://raw.githubusercontent.com/dwyl/english-words/master/words_alpha.txt](https://github.com/dwyl/english-words/blob/master/words_alpha.txt) 
Folder structure should look like:
WordWizes/
├── resources/
│   └── words_alpha.txt

⚠️ IMPORTANT:

The program expects the dataset at:

../resources/words_alpha.txt
Do NOT rename or move the file unless you update the path in main.cpp
Build and Run
Using CLion
Open the project in CLion
Click the Run (▶️) button
Program will execute in the built-in terminal
Using Terminal
mkdir build
cd build
cmake ..
make
./WordWizes
---
Recommended workflow

Load Trie (Option 1)
Load Hash Table (Option 2)
Test searches (Options 3 & 4)
Try prefix search (Option 5)
Run benchmark (Option 6)
---

Example program output (Sample run)
===== WordWizes Menu =====
1. Load dataset into Trie
2. Load dataset into Hash Table
3. Search word in Trie
4. Search word in Hash Table
5. Prefix search in Trie
6. Run full runtime benchmark
7. Exit
Choose an option: 1
Loaded 370105 words into Trie.
Insert time: 609.726 ms
===== WordWizes Menu =====
Choose an option: 3
Enter word to search in Trie: apple
Word found in Trie.
Search time: 11.363 microseconds
===== WordWizes Menu =====
Choose an option: 5
Enter prefix: app
Matches found: 525
app
appair
appal
appalachia
appalachian
appalachians
appale
appall
appalled
appalling
appallingly
appallingness
appallment
appalls
appalment
appaloosa
appaloosas
appals
appalto
appanage
...and more
Prefix search time: 922.784 microseconds

===== WordWizes Menu =====
Choose an option: 2
Loaded 370105 words into Hash Table.
Insert time: 240.821 ms
===== WordWizes Menu =====
Choose an option: 4
Enter word to search in Hash Table: apple
Word found in Hash Table.
Search time: 4.683 microseconds
===== Runtime Comparison =====
Dataset: ../resources/words_alpha.txt
Words loaded: 370105
Trie insert time: 639.233 ms
Hash insert time: 252.105 ms
Trie search time: 254.622 ms
Hash search time: 188.872 ms

Faster insert: Hash Table
Faster search: Hash Table
===== WordWizes Menu =====
Choose an option: 7
Exiting program.
---

Contributors

* Amber Nguyen
* Nicoandro Wences
* Soch Alvarez
