#include <iostream>
#include <thread>

// Функція для обчислення факторіалу
void calculateFactorial(int n) {
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    std::cout << "Factorial of " << n << " is " << factorial << std::endl;
}

// Функція для знаходження n-го члена послідовності Фібоначчі
void calculateFibonacci(int n) {
    unsigned long long a = 0, b = 1, c;
    if (n == 0) {
        std::cout << "Fibonacci number " << n << " is " << a << std::endl;
        return;
    }
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    std::cout << "Fibonacci number " << n << " is " << b << std::endl;
}

int main() {
    int num;

    std::cout << "Enter a number for factorial calculation: ";
    std::cin >> num;
    std::thread t1(calculateFactorial, num);

    std::cout << "Enter a number for Fibonacci calculation: ";
    std::cin >> num;
    std::thread t2(calculateFibonacci, num);

    t1.join();
    t2.join();

    return 0;
}
