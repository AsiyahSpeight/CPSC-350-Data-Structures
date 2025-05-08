# Scare Game - Programming Assignment 5

## Student Information
- **Full Name:** Asiyah Speight  
- **Student ID:** 2357167  
- **Chapman Email:** aspeight@chapman.edu  
- **Course:** CPSC-350 (Data Structures and Algorithms)  
- **Section:** 02  
- **Assignment:** PA5: Scare Games

---

## Submitted Source Files
- `main.cpp`  
- `RunScareGame.cpp`, `RunScareGame.h`  
- `Monster.cpp`, `Monster.h`  
- `TournamentNode.h`  
- `TournamentTree.h`  
- `DOTFileGeneratorMethods.h`
- `DOTFileGenerator.cpp` (file was already created and just needed to be implemented into my code. However, for grading purposes it will be part of what i submitted. Meaning, I am stating that I did not create this code, I am only adding it in, since it is part of the code that needs to be implemented and executed.)

---

## Description
This program simulates a **scare-themed tournament** using a binary tree structure to model **single** and **double elimination** brackets.

- Monsters are loaded from a user-provided file.
- Each monster has a name and a `screamPower` level.
- In *single elimination*, winners advance in a single bracket.
- In *double elimination*, losers also get a second chance via a loser bracket, and the final winner is chosen from a match between the top of both brackets.

The final tournament tree is exported as a `.dot` file for visualization using [Graphviz Online](https://dreampuf.github.io/GraphvizOnline/).

---


## Notes on Implementation
- I created a separate header file DOTFileGeneratorMethods.h because the PA5 spec mentioned that the logic for generating DOT files was prewritten and not to be modified.
- Since I wasn't allowed to modify the provided .cpp implementation file for DOT output, I had to manually declare the DOT file generation function in a new .h file and call it properly from my TournamentTree template class to prevent compiler and linker errors.
- This was necessary because template functions must be implemented in headers to allow instantiation during compilation.
- The new header exposes the saveTreeAsDot() function to TournamentTree.h for correct tree visualization.
---

## Known Errors / Limitations

- No known compile-time or runtime errors.
- The .dot file output may appear vertically compressed in Graphviz Online Viewer depending on tree depth.
- The added DOTFileGeneratorMethods.h file was necessary to implement templated DOT output in compliance with C++ header-only rules for templates.

---

## DOT Output Expectations

- Single Elimination, Outputs one file → single_bracket.dot
- Double Elimination, Outputs two files:
    - winner_bracket.dot
    - loser_bracket.dot

This follows the assignment requirement of:
> 1 DOT file for single elimination, and 2 for double elimination (winner + loser brackets).

---

## References

- Slack help from CPSC 350 student Chantelle Chan on DOT file requirements (Sidenote: we are in the same class and helped with which files that needed to be outputted when the code ran).
- Discussions with team members regarding bracket visualization output.
- [Graphviz](https://graphviz.org/) for DOT file visualization.
- C++ documentation for template behavior and header-only design: [cppreference.com](https://en.cppreference.com)
- LLM ChatGPT was used for debugging and fixing comiple errors that occured 

---

## How to Compile and Run

```bash
# Compile the program:
g++ *.cpp -o monster.exe

# Run the executable:
./monster.exe

# Program will prompt:
# Enter input file name (e.g., monsters.txt)
# Enter mode (single or double)