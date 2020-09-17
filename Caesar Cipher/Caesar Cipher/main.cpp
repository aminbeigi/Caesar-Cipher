#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "cipher.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ios_base;
using std::ifstream;
using std::copy;

int main() {
    vector<char> vec;
    string file_string;

    string target_file = "test.txt";
    /*
    cout << "Enter file name to be encrypted: ";
    string target_file;
    cin >> target_file;
    */

    unsigned int shift;
    cout << "Shift value: ";
    cin >> shift;

    string direction;
    cout << "Direction (left/right): ";
    cin >> direction;
    cout << endl;

    typedef vector<char>::size_type vec_sz;

    ifstream input_file(target_file);

    if (!input_file.is_open()) {
        cout << "Input file couldn't open." << endl;
        return 1;
    }

    cout << "File contents:" << endl;

    while (getline(input_file, file_string)) {
        copy(file_string.begin(), file_string.end(), back_inserter(vec));

        cout << file_string << endl;
    }

    vec_sz size = vec.size();
    cout << endl;

    cout << "file contains " << size << " characters" << endl;

    input_file.close();

    cipher(vec, target_file, shift, direction);

    return 0;
}