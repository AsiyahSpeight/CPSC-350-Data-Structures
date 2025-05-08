# Do You See What I See? – Programming Assignment 3

## **Student Information**
- **Full Name:** Asiyah Speight  
- **Student ID:** 2357167  
- **Chapman Email:** aspeight@chapman.edu  
- **Course:** CPSC-350 (Data Structures and Algorithms)  
- **Section:** 02  
- **Assignment:** PA3: Do You See What I See?  

---

## **Submitted Files**
The following files are included in this assignment submission:
- `main.cpp`
- `SpeakerView.cpp`, `SpeakerView.h`
- `MonoStack.h`
- `input.txt` (Sample test input)

---

## **Description**
This program simulates a visibility analysis in a conference room scenario, where a company assigns seating for a motivational speech. The audience is arranged in an **N x P grid**, with each cell representing a person’s height.

The program uses a **monotonically decreasing stack** (custom implementation in `MonoStack.h`) to determine how many people in each **column** can see the speaker without being blocked by taller individuals sitting in front of them.

### **Input Format**
The input file includes:
- A `BEGIN` header on the first line
- N lines of P floating-point numbers (heights)
- An `END` footer on the last line

Example:
```
BEGIN
81.4 121.4 50.2 75.3 75.1
90.0 90.5 80.2 60.3 50.2
80.8 80.3 90.7 89.9 94.7
82.2 72.1 92.6 54.4 95.1
END
```

### **Output Format**
The program prints how many people in each column can see the speaker and their respective heights, e.g.:
```
In column 0 there are 2 that can see. Their heights are: 81.4, 90 inches.
```

---

## **Known Issues / Limitations**
- No known compilation or runtime errors.
- Assumes that all rows in the input file contain the same number of entries.
- Input must strictly follow the "BEGIN...END" format with valid floating-point numbers between.
- Does not support malformed files (e.g., missing "BEGIN"/"END" or inconsistent column counts).

---

## **References & Citations**
The following resources were used in the completion of this assignment:
- **C++ Documentation**: [cplusplus.com](http://www.cplusplus.com/)
- **Stack Overflow**: For error messages and syntax lookup
- **Course Lecture Code**: For array-based templated stack structure
- **ChatGPT**: Used for bug fixing and logic clarification  
  ```cpp
  // BEGIN CODE FROM CHAT GPT, PROMPT: "Why is my MonoStack constructor not being recognized?"
  // ChatGPT explained that the constructor name must match the class name exactly in the template definition.
  // END CODE FROM CHAT GPT
  ```

---

## **Compilation & Execution Instructions**

This program is compiled using `g++` and executed from the command line.

### **To Compile:**
```bash
g++ *.cpp -o PA3.exe
```

### **To Run:**
```bash
./PA3.exe input.txt
```

Make sure `input.txt` is in the same directory or specify the correct path.

---