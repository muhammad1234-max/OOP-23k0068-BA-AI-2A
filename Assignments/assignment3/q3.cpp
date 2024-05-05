#include <iostream>
#include <vector>

using namespace std;

// Base Matrix class template
template <typename T>
class Matrix {
protected:
    int rows;
    int cols;
    vector<vector<T>> data;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<T>(c)) {}

    // Addition operator overloading
    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Subtraction operator overloading
    Matrix<T> operator-(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Multiplication operator overloading
    template <typename U>
    Matrix<U> operator*(const Matrix<U>& other) const {
        Matrix<U> result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Display method
    virtual void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Accessor operator to access individual elements
    T& operator()(int i, int j) {
        return data[i][j];
    }
};

// Specialized Matrix class for integers
class IntMatrix : public Matrix<int> {
public:
    // Constructor
    IntMatrix(int r, int c) : Matrix<int>(r, c) {}

    // Conversion constructor from base Matrix class
    IntMatrix(const Matrix<int>& other) : Matrix<int>(other) {}

    // Display method for integers
    void display() const override {
        Matrix<int>::display();
    }
};

// Specialized Matrix class for doubles
class DoubleMatrix : public Matrix<double> {
public:
    // Constructor
    DoubleMatrix(int r, int c) : Matrix<double>(r, c) {}

    // Conversion constructor from base Matrix class
    DoubleMatrix(const Matrix<double>& other) : Matrix<double>(other) {}

    // Display method for doubles
    void display() const override {
        Matrix<double>::display();
    }
};
int main() {
    // Create instances of IntMatrix and DoubleMatrix
    IntMatrix intMat(2, 2);
    DoubleMatrix doubleMat(2, 2);

    // Initialize matrices
    intMat(0, 0) = 1; intMat(0, 1) = 2;
    intMat(1, 0) = 3; intMat(1, 1) = 4;

    doubleMat(0, 0) = 1.1; doubleMat(0, 1) = 2.2;
    doubleMat(1, 0) = 3.3; doubleMat(1, 1) = 4.4;

    // Display matrices
    cout << "IntMatrix:" << endl;
    intMat.display();
    cout << endl;

    cout << "DoubleMatrix:" << endl;
    doubleMat.display();
    cout << endl;

    // Perform matrix operations
    IntMatrix intResultAdd = intMat + intMat;
    IntMatrix intResultSub = intMat - intMat;
    IntMatrix intResultMul = intMat * intMat;

    DoubleMatrix doubleResultAdd = doubleMat + doubleMat;
    DoubleMatrix doubleResultSub = doubleMat - doubleMat;
    DoubleMatrix doubleResultMul = doubleMat * doubleMat;

    // Display results
    cout << "IntMatrix + IntMatrix:" << endl;
    intResultAdd.display();
    cout << endl;

    cout << "IntMatrix - IntMatrix:" << endl;
    intResultSub.display();
    cout << endl;

    cout << "IntMatrix * IntMatrix:" << endl;
    intResultMul.display();
    cout << endl;

    cout << "DoubleMatrix + DoubleMatrix:" << endl;
    doubleResultAdd.display();
    cout << endl;

    cout << "DoubleMatrix - DoubleMatrix:" << endl;
    doubleResultSub.display();
    cout << endl;

    cout << "DoubleMatrix * DoubleMatrix:" << endl;
    doubleResultMul.display();

    return 0;
}
