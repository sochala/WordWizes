# COP3530 - WordWizes Project

## Overview

This project implements a word-processing system using efficient data structures (Trie and Hash Table). It reads a dataset of words and performs operations such as loading, searching, and comparing runtime performance.

---
## Report 

[Report_108 (3).pdf](https://github.com/user-attachments/files/26326649/Report_108.3.pdf)



## Requirements

* C++ (C++11 or higher)
* CMake
* CLion IDE (recommended)

---

## Clone the Repository

### Using CLion

1. Open CLion
2. Click **"Get from VCS"**
3. Paste the repository URL:

   ```
   https://github.com/sochala/WordWizes.git
   ```
4. Click **Clone**

---

## Dataset Setup (REQUIRED)

The dataset is NOT included in the repository.

### Download dataset:

```bash
curl -o resources/words_alpha.txt https://raw.githubusercontent.com/dwyl/english-words/master/words_alpha.txt
```

### Folder structure:

```
WordWizes/
├── resources/
│   └── words_alpha.txt
```
 IMPORTANT:

* The program expects the dataset at:

  ```
  ../resources/words_alpha.txt
  ```
* Do NOT rename or move the file unless you update the path in `main.cpp`

---

## Build and Run

### Using CLion

1. Open the project
2. Click the **Run** button
3. The program runs in the built-in terminal

### Using Terminal

```bash
mkdir build
cd build
cmake ..
make
./WordWizes
```

---

## Recommended Workflow

1. Load Trie (Option 1)
2. Load Hash Table (Option 2)
3. Test searches (Options 3 & 4)
4. Try prefix search (Option 5)
5. Run benchmark (Option 6)

---

## Example Program Output (Sample Run)

```
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
```

---

## Contributors

* Amber Nguyen
* Nicoandro Wences
* Soch Alvarez

