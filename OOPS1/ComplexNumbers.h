#include <iostream>

class ComplexNumbers {
    private:
        int real;
        int imaginary;
    public:
        ComplexNumbers(int real, int imaginary);
        void plus(const ComplexNumbers &c1);
        void multiply(const ComplexNumbers &c1);
        void print();
};

ComplexNumbers::ComplexNumbers(int real, int imaginary)
    : real {real}, imaginary {imaginary} {}

void ComplexNumbers::plus(const ComplexNumbers &c1) {
    real += c1.real;
    imaginary += c1.imaginary;
}

void ComplexNumbers::multiply(const ComplexNumbers &c1) {
    int realX = (real * c1.real) - (imaginary * c1.imaginary);
    int imaginaryY = (real * c1.imaginary) + (imaginary * c1.real);
    
    real = realX;
    imaginary = imaginaryY;
}

void ComplexNumbers::print() {
    std::cout << real << " + " << "i" << imaginary << std::endl;
}
