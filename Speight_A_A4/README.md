# 🧱 Blockchain Ledger – Programming Assignment 4

## **Student Information**
- **Full Name:** Asiyah Speight  
- **Student ID:** 2357167  
- **Chapman Email:** aspeight@chapman.edu  
- **Course:** CPSC-350 (Data Structures and Algorithms)  
- **Section:** 02  
- **Assignment:** PA4: Blockchain Ledger  

---

## **Submitted Files**
The following files are included in this assignment submission:
- `main.cpp`
- `Block.cpp`, `Block.h`
- `Blockchain.cpp`, `Blockchain.h`
- `myBlockChain.txt` (sample test file for validation)

---

## **Description**
This program simulates a simplified **blockchain ledger** using a **custom-built doubly linked list** (no STL containers). Each block contains:

- `Index`: Block’s position in the chain  
- `Timestamp`: Time of creation  
- `Data`: Transaction or user-entered content  
- `Previous Hash`: Hash of the prior block  
- `Hash`: A custom hash generated from ASCII values of the block's content

A blockchain is created by linking these blocks together via their hash values, with tampering detection implemented via hash recomputation and chain validation logic.

---

## **Input Format**
The program accepts and writes blockchain data in the following format (pipe-separated, one block per line):
index|timestamp|data|previousHash|hash


Example:
0|Sat Mar 22 06:15:37 2025|Genesis Block|0|ad8 1|Sat Mar 22 06:15:41 2025|Elia sent Erik 1000 Panther Coins|ad8|11b7


---

## **Output Format**
When interacting with the console, the program uses the following structured output:
 New Block Added Index: 2 Timestamp: Sat Mar 22 06:15:54 2025 Data: Erik sent Elizabeth 88 Panther Coins Previous Hash: 11b7 Hash: 1386


Menu options are displayed repeatedly:
Welcome to your Panther Blockchain Ledger:
1. Add a New Block
2. Display the Blockchain
3. Validate the Blockchain
4. Save Blockchain to File
5. Load Blockchain from File
6. Exit


Validation success:
Performing blockchain validation... Result: Blockchain is valid 


Validation failure (e.g., tampered file):
Block 2 has an invalid current hash! Result: Blockchain is invalid!


---

## **Known Issues / Limitations**
- No known compile or runtime errors.  
- Assumes blockchain files are properly formatted with pipe separators.  
- Timestamps include trailing newline from `ctime()` formatting.  
- Does not support loading malformed or inconsistent blockchain files.

---

## **References & Citations**
The following resources were used in the completion of this assignment:

- **C++ Date/Time Reference**: [W3Schools](https://www.w3schools.com/cpp/cpp_date.asp)  
- **cppreference.com**: Used for string parsing and formatting  
- **Course Lecture Notes**: For pointers, file I/O, and doubly linked list design  
-  
```cpp
// BEGIN CODE FROM CHAT GPT, PROMPT: "How do I implement a blockchain in C++ using a doubly linked list?"
// ChatGPT assisted with logic organization, edge case testing, validation routines, hash design, and README formatting.
// ChatGPT also helped simulate runs from the assignment spec and created tampered file test cases.
// END CODE FROM CHAT GPT

## **Compilation & Execution Instructions**

This program is compiled using `g++` and executed from the command line.

### **To Compile:**
```bash
g++ *.cpp -o A4.exe
```

### **To Run:**
```bash
./A4.exe