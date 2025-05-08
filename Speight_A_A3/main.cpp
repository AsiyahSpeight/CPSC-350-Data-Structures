/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA3: Do you see what I see?
 */

/*
main.cpp:
this is the main method that will taken in the input file name as a command line argument and then uses the speakerView
class to compute the output.
*/

#include "SpeakerView.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    SpeakerView speakerView(argv[1]);
    speakerView.computeVisibility();
    return 0;
}