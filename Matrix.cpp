#include <iostream>

using namespace std;

class Matrix3D {
public:

    double a[3]{}, b[3]{}, c[3]{};

    Matrix3D() : Matrix3D(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) {
        //инициализация нулями без введения данных.
    }

    Matrix3D(double a11, double a12, double a13,
             double a21, double a22, double a23,
             double a31, double a32, double a33) {
        this->a[0] = a11;
        this->a[1] = a12;
        this->a[2] = a13;
        this->b[0] = a21;
        this->b[1] = a22;
        this->b[2] = a23;
        this->c[0] = a31;
        this->c[1] = a32;
        this->c[2] = a33;
        //задание непосредственно параметрами
    }
    //просто первый коммит

    Matrix3D operator*(const double a) {
        return {this->a[0] * a, this->a[1] * a, this->a[2] * a,
                this->b[0] * a, this->b[1] * a, this->b[2] * a,
                this->c[0] * a, this->c[1] * a, this->c[2] * a};
    }

    Matrix3D operator-(const Matrix3D &matrix) {
        return {this->a[0] - matrix.a[0], this->a[1] - matrix.a[1], this->a[2] - matrix.a[2],
                this->b[0] - matrix.b[0], this->b[1] - matrix.b[1], this->b[2] - matrix.b[2],
                this->c[0] - matrix.c[0], this->c[1] - matrix.c[1], this->c[2] - matrix.c[2]};
    }

    Matrix3D operator+(const Matrix3D &matrix) {
        return {this->a[0] + matrix.a[0], this->a[1] + matrix.a[1], this->a[2] + matrix.a[2],
                this->b[0] + matrix.b[0], this->b[1] + matrix.b[1], this->b[2] + matrix.b[2],
                this->c[0] + matrix.c[0], this->c[1] + matrix.c[1], this->c[2] + matrix.c[2]};
    }


    Matrix3D operator*(const Matrix3D &matrix) {
        return {this->a[0] * matrix.a[0] + this->a[1] * matrix.b[0] + this->a[2] * matrix.c[0],
                this->a[0] * matrix.a[1] + this->a[1] * matrix.b[1] + this->a[2] * matrix.c[1],
                this->a[0] * matrix.a[2] + this->a[1] * matrix.b[2] + this->a[2] * matrix.c[2],
                this->b[0] * matrix.a[0] + this->b[1] * matrix.b[0] + this->b[2] * matrix.c[0],
                this->b[0] * matrix.a[1] + this->b[1] * matrix.b[1] + this->b[2] * matrix.c[1],
                this->b[0] * matrix.a[2] + this->b[1] * matrix.b[2] + this->b[2] * matrix.c[2],
                this->c[0] * matrix.a[0] + this->c[1] * matrix.b[0] + this->c[2] * matrix.c[0],
                this->c[0] * matrix.a[1] + this->c[1] * matrix.b[1] + this->c[2] * matrix.c[1],
                this->c[0] * matrix.a[2] + this->c[1] * matrix.b[2] + this->c[2] * matrix.c[2]};
    }

    double determinant() {
        return a[0] * (b[1] * c[2] - b[2] * c[1]) -
               a[1] * (b[0] * c[2] - b[2] * c[0] + a[2] * (b[0] * c[1] - b[1] * c[0]));
    }
};

ostream &operator<<(ostream &os, const Matrix3D &matrix) {
    os << "(" << matrix.a[0] << " " << matrix.a[1] << " " << matrix.a[2] << ")" << endl;
    os << "(" << matrix.b[0] << " " << matrix.b[1] << " " << matrix.b[2] << ")" << endl;
    os << "(" << matrix.c[0] << " " << matrix.c[1] << " " << matrix.c[2] << ")" << endl;
    return os;
}

istream &operator>>(istream &is, Matrix3D &matrix) {
    cin >> matrix.a[0] >> matrix.a[1] >> matrix.a[2];
    cin >> matrix.b[0] >> matrix.b[1] >> matrix.b[2];
    cin >> matrix.c[0] >> matrix.c[1] >> matrix.c[2];
    return is;
}

Matrix3D operator*(const double a, const Matrix3D &matrix) {
    cout << matrix.c[2];
    return {matrix.a[0] * a, matrix.a[1] * a, matrix.a[2] * a,
            matrix.b[0] * a, matrix.b[1] * a, matrix.b[2] * a,
            matrix.c[0] * a, matrix.c[1] * a, matrix.c[2] * a};
}


int main() {
    // Матрица задана в коде
    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    // Матрица читается из cin
   Matrix3D D;
    cin >> D;

    // Базовые операции с матрицами
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "Умножение матрицы на число C * 3 = "<< endl << C * 3 << endl;
    cout << "Умножение числа на матрицу 2 * D = " << endl << 2 * D << endl;
    cout << "Сумма C + D = " << endl << C + D << endl;
    cout << "Разность C - D = " << endl << C - D << endl;
    cout << "Произведение C * D = " << endl << C * D << endl;

    // Детерминант матрицы
    cout << "det(D) = " << D.determinant() << endl;

    return 0;
}
