#include <iostream>

class ImaginaryNumber {
private:
    double realPart;
    double imaginaryPart;

public:
    // Constructor
    ImaginaryNumber(double real, double imaginary) : realPart(real), imaginaryPart(imaginary) {}

    // Addition
    ImaginaryNumber operator+(const ImaginaryNumber& other) const {
        return ImaginaryNumber(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    // Subtraction
    ImaginaryNumber operator-(const ImaginaryNumber& other) const {
        return ImaginaryNumber(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }

    // Multiplication
    ImaginaryNumber operator*(const ImaginaryNumber& other) const {
        double realResult = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
        double imaginaryResult = realPart * other.imaginaryPart + imaginaryPart * other.realPart;
        return ImaginaryNumber(realResult, imaginaryResult);
    }

    // Division
    ImaginaryNumber operator/(const ImaginaryNumber& other) const {
        double divisor = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        double realResult = (realPart * other.realPart + imaginaryPart * other.imaginaryPart) / divisor;
        double imaginaryResult = (imaginaryPart * other.realPart - realPart * other.imaginaryPart) / divisor;
        return ImaginaryNumber(realResult, imaginaryResult);
    }

    // Display the imaginary number
    void display() const {
        std::cout << realPart << " + " << imaginaryPart << "i" << std::endl;
    }
};

int main() {
    // Create two imaginary numbers
    ImaginaryNumber num1(3.0, 4.0);  // 3 + 4i
    ImaginaryNumber num2(1.0, -2.0); // 1 - 2i

    // Perform operations
    ImaginaryNumber sum = num1 + num2;
    ImaginaryNumber difference = num1 - num2;
    ImaginaryNumber product = num1 * num2;
    ImaginaryNumber quotient = num1 / num2;

    // Display results
    std::cout << "Number 1: ";
    num1.display();

    std::cout << "Number 2: ";
    num2.display();

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    difference.display();

    std::cout << "Product: ";
    product.display();

    std::cout << "Quotient: ";
    quotient.display();

    return 0;
}