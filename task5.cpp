#include <iostream>

class Polynomial {
private:
    int* coeffs;
    int degree;

public:
    Polynomial(int deg) : degree(deg) {
        coeffs = new int[degree + 1]();
    }

    ~Polynomial() {
        delete[] coeffs;
    }

    void setCoefficient(int power, int coefficient) {
        if (power <= degree) {
            coeffs[power] = coefficient;
        }
    }

    Polynomial operator+(const Polynomial& other) {
        int maxDegree = std::max(degree, other.degree);
        Polynomial result(maxDegree);

        for (int i = 0; i <= maxDegree; ++i) {
            int coeff1 = (i <= degree) ? coeffs[i] : 0;
            int coeff2 = (i <= other.degree) ? other.coeffs[i] : 0;
            result.setCoefficient(i, coeff1 + coeff2);
        }

        return result;
    }

    Polynomial operator-(const Polynomial& other) {
        int maxDegree = std::max(degree, other.degree);
        Polynomial result(maxDegree);

        for (int i = 0; i <= maxDegree; ++i) {
            int coeff1 = (i <= degree) ? coeffs[i] : 0;
            int coeff2 = (i <= other.degree) ? other.coeffs[i] : 0;
            result.setCoefficient(i, coeff1 - coeff2);
        }

        return result;
    }

    Polynomial operator*(const Polynomial& other) {
        int resultDegree = degree + other.degree;
        Polynomial result(resultDegree);

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                result.coeffs[i + j] += coeffs[i] * other.coeffs[j];
            }
        }

        return result;
    }

    int evaluate(int x) {
        int result = 0;
        for (int i = degree; i >= 0; --i) {
            result = result * x + coeffs[i];
        }
        return result;
    }

    void display() {
        for (int i = degree; i >= 0; --i) {
            if (coeffs[i] != 0) {
                std::cout << coeffs[i] << "x^" << i;
                if (i != 0) {
                    std::cout << " + ";
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Polynomial p1(2);
    p1.setCoefficient(0, 1);
    p1.setCoefficient(1, 2);
    p1.setCoefficient(2, 3);

    Polynomial p2(2);
    p2.setCoefficient(0, 4);
    p2.setCoefficient(1, 5);
    p2.setCoefficient(2, 6);

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;
    int eval = p1.evaluate(2);

    std::cout << "Polynomial 1: ";
    p1.display();
    std::cout << "Polynomial 2: ";
    p2.display();
    std::cout << "Sum: ";
    sum.display();
    std::cout << "Difference: ";
    diff.display();
    std::cout << "Product: ";
    prod.display();
    std::cout <<