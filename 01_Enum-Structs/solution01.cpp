#include <iostream>

struct ComplexNumber {

    double real;
    double imaginary;
};

void readComplexNumber(ComplexNumber& compNum) {

    std::cout << "Enter complex number:";
    std::cin >> compNum.real >> compNum.imaginary;
}

void printComplexNumber(const ComplexNumber& compNum) {

    std::cout << compNum.real;

    if (compNum.imaginary >= 0) {
        std::cout << '+' << compNum.imaginary << 'i';

    }  else {
        std::cout << '-' << -compNum.imaginary << 'i';
    }

    std::cout << std::endl;
}

ComplexNumber sumOfComplexNumber(const ComplexNumber& compNum1, const ComplexNumber& compNum2) {

    ComplexNumber result;
    result.real      = compNum1.real + compNum2.real;
    result.imaginary = compNum1.imaginary + compNum2.imaginary;
    
    /* 
    * Second way:
    * ComplexNumber result{ compNum1.real + compNum2.real , compNum1.imaginary + compNum2.imaginary };
    */
    return result;
}

int main() {

    ComplexNumber compNum1;
    readComplexNumber(compNum1);

    ComplexNumber compNum2;
    readComplexNumber(compNum2);

    printComplexNumber(sumOfComplexNumber(compNum1, compNum2));


    ComplexNumber compNum3 = { 7, 1 };  // 7 + 1i
    ComplexNumber compNum4 = { 8, 2 };  // 8 + 2i

    ComplexNumber result = sumOfComplexNumber(compNum3, compNum4);
    printComplexNumber(result);
    

    ComplexNumber compNum5; 
    compNum5.real = -3;
    compNum5.imaginary = -8;

    ComplexNumber compNum6;  
    compNum6.real = 10;
    compNum6.imaginary = 11;

    printComplexNumber(sumOfComplexNumber(compNum5, compNum6));

    return 0;
}
