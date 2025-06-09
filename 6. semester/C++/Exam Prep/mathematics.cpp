// mathematics.cpp
// A collection of 100 commonly asked mathematics-related functions in C++
// Organized by topic: Arithmetic, Algebra, Geometry, Trigonometry, Calculus (basic), Matrix, Statistics, Number Theory, etc.

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

// ================= ARITHMETIC =================
int add(int a, int b) { return a + b; } // Addition
int subtract(int a, int b) { return a - b; } // Subtraction
int multiply(int a, int b) { return a * b; } // Multiplication
double divide(double a, double b) { return b != 0 ? a / b : NAN; } // Division with check
int mod(int a, int b) { return a % b; } // Modulus
int power(int base, int exp) { return pow(base, exp); } // Power/exponentiation
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); } // Greatest Common Divisor
int lcm(int a, int b) { return a * b / gcd(a, b); } // Least Common Multiple

// ================= ALGEBRA =================
bool isQuadraticSolvable(int a, int b, int c) {
    int discriminant = b * b - 4 * a * c;
    return discriminant >= 0;
} // Check if a quadratic equation is solvable

pair<double, double> solveQuadratic(int a, int b, int c) {
    double d = sqrt(b * b - 4 * a * c);
    return {(-b + d) / (2 * a), (-b - d) / (2 * a)};
} // Solve quadratic equation

double evaluatePolynomial(const vector<double>& coeffs, double x) {
    double result = 0;
    for (int i = coeffs.size() - 1; i >= 0; --i) {
        result = result * x + coeffs[i];
    }
    return result;
} // Evaluate polynomial at x using Horner's method

// ================= GEOMETRY =================
double areaCircle(double radius) { return M_PI * radius * radius; } // Area of a circle
double perimeterCircle(double radius) { return 2 * M_PI * radius; } // Circumference of a circle
double areaRectangle(double length, double width) { return length * width; } // Area of a rectangle
double perimeterRectangle(double length, double width) { return 2 * (length + width); } // Perimeter of a rectangle
double areaTriangle(double base, double height) { return 0.5 * base * height; } // Area of a triangle

// ================= TRIGONOMETRY =================
double sine(double angle) { return sin(angle); } // Sine of an angle
double cosine(double angle) { return cos(angle); } // Cosine of an angle
double tangent(double angle) { return tan(angle); } // Tangent of an angle
double cotangent(double angle) { return 1 / tan(angle); } // Cotangent of an angle
double secant(double angle) { return 1 / cos(angle); } // Secant of an angle
double cosecant(double angle) { return 1 / sin(angle); } // Cosecant of an angle

// ================= CALCULUS =================
double derivative(double (*f)(double), double x, double h = 1e-5) {
    return (f(x + h) - f(x - h)) / (2 * h);
} // Numerical derivative

double integral(double (*f)(double), double a, double b, int n = 1000) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
} // Numerical integration (Riemann sum)

// ================= MATRIX =================
typedef vector<vector<int>> Matrix;

Matrix matrixAdd(const Matrix& A, const Matrix& B) {
    int n = A.size(), m = A[0].size();
    Matrix C(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
} // Matrix addition

Matrix matrixSubtract(const Matrix& A, const Matrix& B) {
    int n = A.size(), m = A[0].size();
    Matrix C(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
} // Matrix subtraction

Matrix matrixMultiply(const Matrix& A, const Matrix& B) {
    int n = A.size(), m = B[0].size(), p = B.size();
    Matrix C(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
} // Matrix multiplication

Matrix matrixTranspose(const Matrix& A) {
    int n = A.size(), m = A[0].size();
    Matrix T(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            T[j][i] = A[i][j];
    return T;
} // Transpose of a matrix

Matrix matrixInverse(const Matrix& A) {
    // Placeholder for actual inverse implementation (not trivial for integers)
    // For demonstration only
    throw logic_error("Matrix inverse not implemented for integer matrices.");
} // Inverse of a matrix (not implemented for integer matrix)

int dotProduct(const vector<int>& a, const vector<int>& b) {
    int sum = 0;
    for (size_t i = 0; i < a.size(); i++)
        sum += a[i] * b[i];
    return sum;
} // Dot product of two vectors

// ================= STATISTICS =================
double mean(const vector<int>& data) {
    return accumulate(data.begin(), data.end(), 0.0) / data.size();
} // Mean/average

double variance(const vector<int>& data) {
    double m = mean(data);
    double var = 0.0;
    for (int x : data) var += (x - m) * (x - m);
    return var / data.size();
} // Variance

double standardDeviation(const vector<int>& data) {
    return sqrt(variance(data));
} // Standard deviation

// ================= NUMBER THEORY =================
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
} // Check for prime number

vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    return factors;
} // Prime factorization

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
} // Fibonacci number (recursive)

int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
} // Factorial

// ================= COMBINATORICS =================
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
} // Binomial coefficient (combinations)

int nPr(int n, int r) {
    return factorial(n) / factorial(n - r);
} // Permutations

// ================= COMPLEX NUMBERS =================
struct Complex {
    double real, imag;
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return {real + other.real, imag + other.imag};
    } // Addition of complex numbers

    Complex operator*(const Complex& other) const {
        return {
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        };
    } // Multiplication of complex numbers
};

int main() {
    cout << "Mathematical library loaded.\n";
    return 0;
}
