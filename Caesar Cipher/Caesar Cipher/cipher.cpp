#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::fstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::ios_base;

#define A 65
#define a 97
#define Z 90
#define z 122
#define ALPHABET_SIZE 26

// the file to be outputted to
const string& outputFilePath = "new_text.txt";

int cipher(vector<char> output_vec, string target_file, string& original_file_string, int shift, string& direction) {


    // open a file in write mode
    ofstream output_file(outputFilePath);
    if (!output_file.is_open()) {
        cout << "Output file couldn't open." << endl;
        return 1;
    }

    if (shift % ALPHABET_SIZE == 0) {
        cout << "Encrtyped file contents" << endl;
        cout << original_file_string << endl;
        output_file << original_file_string;
        return 0;
    }
    
    if (direction == "right") {
        for (int i : output_vec) {
            int decimal = (int)i;
            for (int j = 0; j < shift; ++j) {
                // set decimal to 'A'
                if (decimal == 90) {
                    decimal = 65;
                    continue;
                }

                // set decimal to 'a'
                if (decimal == 122) {
                    decimal = 97;
                    continue;
                }

                // ignore anything at isn't a character from [a-z][A-Z]
                if (!(decimal >= 65 && decimal <= 90 || decimal >= 97 && decimal <= 122)) {
                    continue;
                }

                ++decimal;
            }
            output_file << (char)decimal;
        }
    }

    if (direction == "left") {
        for (int i : output_vec) {
            int decimal = (int)i;
            for (int j = 0; j < shift; ++j) {
                // set decimal to 'Z'
                if (decimal == 65) {
                    decimal = 90;
                    continue;
                }

                // set decimal to 'z'
                if (decimal == 97) {
                    decimal = 122;
                    continue;
                }

                // ignore anything at isn't a character from [a-z][A-Z]
                if (!(decimal >= 65 && decimal <= 90 || decimal >= 97 && decimal <= 122)) {
                    continue;
                }

                --decimal;
            }
            output_file << (char)decimal;
        }
    }

    output_file.close();
    cout << "file has successfully been encrytped" << endl;
    return 0;
}