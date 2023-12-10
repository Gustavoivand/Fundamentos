#include <iostream>
#include <cstring>

const int BUFFER_SIZE = 1000;

void processString(char* buffer) {
    int length = strlen(buffer);

    // Remove blank spaces
    int readIndex = 0, writeIndex = 0;
    while (readIndex < length) {
        if (buffer[readIndex] != ' ') {
            buffer[writeIndex++] = buffer[readIndex];
        }
        readIndex++;
    }
    buffer[writeIndex] = '\0'; // Null-terminate the modified string

    // Replace characters with the next alphabet character
    for (int i = 0; i < writeIndex; ++i) {
        if (std::isalpha(buffer[i])) {
            if (buffer[i] == 'z') {
                buffer[i] = 'a';
            } else {
                buffer[i]++;
            }
        } else{
            if (buffer[i] == '9') {
                buffer[i] = '0';
            } else {
                buffer[i]++;
            }
        }
    }
}

int main() {
    // Allocate a fixed-size character buffer
    char buffer[BUFFER_SIZE];

    // Read a multi-line string from the user
    std::cout << "Enter a multi-line string (Ctrl+D to end on Unix/Linux, Ctrl+Z on Windows):\n";
    std::cin.getline(buffer, BUFFER_SIZE);

    // Process the string
    processString(buffer);

    // Display the modified string
    std::cout << "Modified string:\n" << buffer << std::endl;

    return 0;
}
