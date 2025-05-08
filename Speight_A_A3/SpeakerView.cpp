/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA3: Do you see what I see?
 */

/*
SpeakerView Class (.cpp):
This is a class that takes in a plain text file that consists of N+2 lines. The first line of the file will be the string  “BEGIN.”
The last line of the file will be the string “END.” Each of the N lines between the first and last will consist of P doubles
(representing heights) separated by spaces. The class should also be as OO (object oriented) as possible.
*/

#include "SpeakerView.h"

SpeakerView::SpeakerView(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: could not open file" << endl;
        exit(1);
    }

    string line;
    getline(file, line); // read BEGIN
    rows = 0;
    cols = 0;

    while (getline(file, line) && line != "END") {
        rows++;
        stringstream ss(line);
        double temp;
        int colCount = 0;
        
        while (ss >> temp) {
            colCount++;
        }
        
        if (cols == 0) cols = colCount;
    }

    file.clear(); // suggestion from ChatGPT LLM. Clears any errors that may have been set on the file stream.
    file.seekg(0); // suggestion from ChatGPT LLM. moves the read position of the file stream back to the begining of the file (position 0).
    getline(file, line);

    heights = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        heights[i] = new double[cols];
    }

    int rowIdx = 0;
    while (getline(file, line) && line != "END") {
        stringstream ss(line);
        for (int colIdx = 0; colIdx < cols; ++colIdx) {
            ss >> heights[rowIdx][colIdx];
        }
        rowIdx++;
    }
}

SpeakerView::~SpeakerView() {
    for (int i = 0; i < rows; ++i) {
        delete[] heights[i];
    }
    delete[] heights;
}

void SpeakerView::computeVisibility() {
    for (int col = 0; col < cols; ++col) {
        MonoStack<double> stack(rows, 'd'); // Monotonically decreasing stack
        double* visibleHeights = new double[rows];
        int count = 0;

        for (int row = 0; row < rows; ++row) {
            double height = heights[row][col];

            // Remove all elements that are shorter than the current height
            while (!stack.isEmpty() && stack.top() < height) {
                stack.pop();
            }

            // If the stack is empty, it means this person can see the speaker
            if (stack.isEmpty()) {
                visibleHeights[count++] = height;
            }

            stack.push(height); // Add person to stack
        }

        // Print the output for this column
        cout << "In column " << col << " there are " << count << " that can see. Their heights are: ";
        for (int i = 0; i < count; ++i) {
            cout << visibleHeights[i] << (i < count - 1 ? ", " : " inches.\n");
        }

        delete[] visibleHeights;
    }
}