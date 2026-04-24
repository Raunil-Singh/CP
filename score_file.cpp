#include <iostream>
#include <fstream>
#include <string>

double calculate_score(int chars) {
    if (chars >= 5000) {
        return 0;
    }
    return 100 - (chars / 50.0);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <source_file.cpp>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    
    // Open the file in binary mode and go to the end
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    // Get the file size (character count)
    int char_count = file.tellg();
    
    // Calculate the score
    double score = calculate_score(char_count);

    std::cout << "--- Code Score Report ---" << std::endl;
    std::cout << "File: " << filename << std::endl;
    std::cout << "Characters (Bytes): " << char_count << std::endl;
    std::cout << "Score: " << score << std::endl;
    std::cout << "-------------------------" << std::endl;

    return 0;
}