#include <iostream>
using namespace std;

// Function to find the intersection of two arrays and remove duplicates
int* findIntersection(const int* arr1, int size1, const int* arr2, int size2, int& resultSize) {
    int maxSize = std::min(size1, size2);
    int* resultArray = new int[maxSize];  // Dynamically allocate memory for the result array
    resultSize = 0;

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            // Check if the element is not already in the result array
            bool found = false;
            for (int k = 0; k < resultSize; ++k) {
                if (resultArray[k] == arr1[i]) {
                    found = true;
                    break;
                }
            }

            if (!found && arr1[i] == arr2[j]) {
                resultArray[resultSize++] = arr1[i];
                break;  // Break to avoid counting duplicates in arr2
            }
        }
    }

    return resultArray;
}

int main() {
    int size1, size2;

    // Get the size of the first array from the user
    std::cout << "Enter the size of the first array: ";
    std::cin >> size1;

    // Create the first array using pointers
    int* arr1 = new int[size1];
    std::cout << "Enter the elements of the first array:\n";
    for (int i = 0; i < size1; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr1[i];
    }

    // Get the size of the second array from the user
    std::cout << "Enter the size of the second array: ";
    std::cin >> size2;

    // Create the second array using pointers
    int* arr2 = new int[size2];
    std::cout << "Enter the elements of the second array:\n";
    for (int i = 0; i < size2; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr2[i];
    }

    // Find the intersection of the arrays
    int resultSize;
    int* intersection = findIntersection(arr1, size1, arr2, size2, resultSize);

    // Display the intersection
    std::cout << "Intersection of the arrays (without duplicates): ";
    for (int i = 0; i < resultSize; ++i) {
        std::cout << intersection[i] << " ";
    }
    std::cout << std::endl;

    // Clean up - free dynamically allocated memory
    delete[] arr1;
    delete[] arr2;
    delete[] intersection;

    return 0;
}