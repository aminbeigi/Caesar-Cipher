#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

#define ALPHABET_SIZE 26

// the file to be outputted to
const string& output_file_path = "new_text.txt";

int cipher(vector<char>& output_vec, string target_file, string& original_file_string, int& shift, string& direction) {
    // open a file in write mode
    std::ofstream output_file(output_file_path);
    if (!output_file.is_open()) {
        cout << "Output file couldn't open." << endl;
        return 1;
    }

    int new_shift = shift % ALPHABET_SIZE;

    if (new_shift == 0) {
        cout << "Encrtyped file contents:" << endl;
        output_file << original_file_string;
        cout << original_file_string << endl;
        return 0;
    }
    
    string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
    string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int position = 0;
    int output = 0;
    string output_string = "";
    for (char c : output_vec) {
        // skip anything that is not an alphabet character
        if (!(std::isalpha(c))) {
            output_string += c;
            continue;
        }
        
        if (c == '\n') {
            output_string += '\n';
            continue;
        }

        if (std::isspace(c)) {
            output_string += c;
            continue;
        }
        // shift to the right
        if (direction == "right") {
            if (std::isupper(c)) {
                position = upper_alphabet.find(c) + new_shift;
            } else {
                position = lower_alphabet.find(c) + new_shift;
            }
            if (position >= ALPHABET_SIZE) {
                position -= ALPHABET_SIZE;
            }
        }

        // shift to the left
        if (direction == "left") {
            if (std::isupper(c)) {
                position = upper_alphabet.find(c) - new_shift;
            } else {
                position = lower_alphabet.find(c) - new_shift;
            }
            if (position < 0) {
                position += ALPHABET_SIZE;
            }
        }

        if (std::isupper(c)) {
            output_string += upper_alphabet[position];
            continue;
        }
        output_string += lower_alphabet[position];
    }

    cout << "Encrtyped file contents:" << endl;
    output_file << output_string;
    cout << output_string;

    output_file.close();
    return 0;
}
