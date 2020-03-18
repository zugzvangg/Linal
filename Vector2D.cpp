#include <iostream>
using namespace std;

class Vector2D
{
private:
    double x, y;
public:

    Vector2D() :Vector2D(0.0, 0.0)
    {}
// установка значений координат вектора:

    Vector2D(double x, double y)
    {
        this -> x = x;
        this -> y = y;
    }
    ~Vector2D()
    {}

    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }


    void setX(double x)
    {
        this -> x = x;
    }
    void setY(double y)
    {
        this -> y = y;
    }

    bool operator == (const Vector2D& v2) const
    {

        return (this->getX() - v2.x == 0) && (this->getY() - v2.y == 0);
    }

    bool operator != (const Vector2D& v2) const
    {
        return !(*this == v2);
    }

    Vector2D operator + (const Vector2D& v2) const
    {
        return Vector2D(this -> getX() + v2.x, this -> getY() + v2.y);
    }

    Vector2D operator - (const Vector2D& v2) const
    {
        return Vector2D(this -> getX() - v2.getX(), this -> getY() - v2.getY());
    }

    Vector2D operator * (double a) const
    {
        return Vector2D(this -> x * a, this -> y * a);
    }

    double operator * (const Vector2D& v2)
    {
        return this -> getX() * v2.x + this -> y * v2.getY();
    }


};

Vector2D operator * (const double a, const Vector2D& v2)
{
    return Vector2D(v2.getX() * a, v2.getY() * a);
}

ostream& operator << (ostream& os, const Vector2D& v2)
{
    os << "(" << v2.getX() << "; " << v2.getY() << ")" << endl;
    return os;
}

istream& operator >> (istream &is, Vector2D &v2)
{
    double a, b;
    cin >> a >> b;
    v2.setX(a);
    v2.setY(b);
    return is;
}



int main()
{
    
    Vector2D A(1, 2);
    Vector2D B;

    cout << "Значение A = " << A << endl;
    cout << "Значение B = " << B << endl;
    cout << "Умножение вектора на число:" << A * 3 << endl;
    cout << "Умножение числа на вектор:" << 2 * B << endl;
    cout << "Суума векторов A + B = " << A + B << endl;
    cout << "Разность A - B = " << A - B << endl;


    return 0;
};
