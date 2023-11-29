#include <iostream>
#include <cmath>

class Series {
public:
    virtual double calculateElement(int j) = 0;
    virtual double calculateSum(int n) = 0;
};

class Linear : public Series {
private:
    double a;
    double d;

public:
    Linear(double a, double d) : a(a), d(d) {}

    double calculateElement(int j) override {
        return a + d * j;
    }

    double calculateSum(int n) override {
        double a0 = calculateElement(0);
        double an = calculateElement(n);
        return ((a0 + an) / 2) * (n + 1);
    }
};

class Exponential : public Series {
private:
    double b0;
    double r;

public:
    Exponential(double b0, double r) : b0(b0), r(r) {}

    double calculateElement(int j) override {
        return b0 * std::pow(r, j);
    }

    double calculateSum(int n) override {
        return (b0 * (std::pow(r, n + 1) - 1)) / (r - 1);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Linear linear(0, 2);
    std::cout << "Арифметическая прогрессия:" << std::endl;
    for (int j = 0; j < 5; j++) {
        std::cout << "Элемент " << j << ": " << linear.calculateElement(j) << std::endl;
    }
    std::cout << "Сумма первых 5 элементов: " << linear.calculateSum(4) << std::endl;

    Exponential exponential(1, 2);
    std::cout << "Геометрическая прогрессия:" << std::endl;
    for (int j = 0; j < 5; j++) {
        std::cout << "Элемент " << j << ": " << exponential.calculateElement(j) << std::endl;
    }
    std::cout << "Сумма первых 5 элементов: " << exponential.calculateSum(4) << std::endl;

    return 0;
}
