#include <iostream>
#include <fstream>

int main() {
    // Specify the file path
    std::string filePath = "square.txt";

    // Open the file for writing
    std::ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file for writing.\n";
        return 1;
    }

    // Set the size of the square
    int size;
    std::cout << "Enter the size of the square: ";
    std::cin >> size;

    // Draw and write the square to the file
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            outputFile << "* ";
        }
        outputFile << "\n";
    }

    // Close the file
    outputFile.close();

    std::cout << "Square created and saved to: " << filePath << std::endl;

    return 0;
}