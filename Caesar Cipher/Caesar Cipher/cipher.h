#ifndef GUARD_CIPHER_H
#define GUARD_CIHPER_H

#include <vector>
#include <string>

int cipher(std::vector<char>& output_vec, std::string target_file, std::string& original_file_string, int& shift, std::string& direction);

#endif