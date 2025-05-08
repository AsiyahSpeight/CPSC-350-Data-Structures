/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA3: Do you see what I see?
 */

/*
SpeakerView Class:
This is a class that takes in a plain text file that consists of N+2 lines. The first line of the file will be the string  “BEGIN.” 
The last line of the file will be the string “END.” Each of the N lines between the first and last will consist of P doubles 
(representing heights) separated by spaces. The class should also be as OO (object oriented) as possible.
*/

/*
The program will then use a monotonically desceasing stack to determine the number of people in each column of seats that are able to see
the speaker clearly, as well as the heights of those people in each column of seats that are able to see the speaker clearly,as well as
the heights of those people.
*/

/*
Expected Output:
the output can be displayed to the terminal but should be descriptive so it is easy to understand.
*/

#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // for string stream, suggestion from ChatGPT LLM

using namespace std;

class SpeakerView{
    public:
        SpeakerView(const string& filename); // constructor that takes in the input file name
        ~SpeakerView(); // destructor 
        void computeVisibility(); // computes the visibility of the speaker
    
    private:
        double** heights;
        int rows, cols;
};

#endif