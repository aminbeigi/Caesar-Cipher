#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using std::vector;
using std::string;
using std::fstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::ios_base;
using std::list;

int cipher(vector<char> output_vec, string target_file, unsigned int& shift, string& direction) {
    ofstream output_file;

    output_file.open("new_text.txt", fstream::out);

    if (!output_file.is_open()) {
        cout << "Output file couldn't open." << endl;
        return 1;
    }

    output_file.close();


    // now append
    output_file.open("new_text.txt", ios_base::app);
    if (!output_file.is_open()) {
        cout << "Output file couldn't open." << endl;
        return 1;
    }

    if (shift == 0) {
        for (auto i : output_vec) {
            output_file << i;
        }
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