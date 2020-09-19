#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

#include "cipher.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ios_base;
using std::ifstream;

// the file to be encrypted
const string& input_file_path = "test.txt";

int main() {
    string target_file = input_file_path;
    
    ifstream input_file(target_file);
    if (!input_file.is_open()) {
        cout << "Input file couldn't open." << endl;
        return 1;
    }

    int shift;
    cout << "Shift value: ";
    cin >> shift;
    while (cin.fail() || !(shift >= 0)) {
        cout << "Invalid input please enter a number." << endl;
        cout << "Shift value: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> shift;
    }
    // clean up cin for getline
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string direction;
    cout << "Direction (left/right): ";
    getline(cin, direction);
    while (direction != "left" && direction != "right") {
        cout << "Invalid input please enter 'left' or 'right'." << endl;
        cout << "Direction (left/right): ";
        getline(cin, direction);
        cin.clear();
    }

    vector<char> vec;
    string file_string;
    string original_output_string = "";

    cout << "File contents:" << endl;
    while (getline(input_file, file_string)) {
        std::copy(file_string.begin(), file_string.end(), back_inserter(vec));
        vec.push_back('\n');
        cout << file_string << endl;
        original_output_string += file_string + '\n' ;
    }

    input_file.close();
    cipher(vec, target_file, original_output_string, shift, direction);

    return 0;
}