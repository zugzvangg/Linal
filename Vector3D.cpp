#include <iostream>
using namespace std;

class Vector3D
{
private:
    double x, y, z;
public:

    Vector3D() : Vector3D(0.0, 0.0, 0.0)
    {}
// установка значений координат вектора:
//try commit
    Vector3D(double x, double y, double z)
    {
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    ~Vector3D()
    {}

    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    double getZ() const
    {
        return z;
    }

    void setX(double x)
    {
        this -> x = x;
    }
    void setY(double y)
    {
        this -> y = y;
    }
    void setZ(double y)
    {
        this -> z = z;
    }

    bool operator == (const Vector3D& v3) const
    {

        return (this->getX() - v3.x == 0) && (this->getY() - v3.y == 0) && (this->getZ() - v3.z ==0);
    }

    bool operator != (const Vector3D& v3) const
    {
        return !(*this == v3);
    }

    Vector3D operator + (const Vector3D& v3) const
    {
        return Vector3D(this -> getX() + v3.x, this -> getY() + v3.y, this -> getZ() + v3.y);
    }

    Vector3D operator - (const Vector3D& v3) const
    {
        return Vector3D(this -> getX() - v3.getX(), this -> getY() - v3.getY(), this -> getZ() - v3.getZ());
    }

    Vector3D operator * (double a) const
    {
        return Vector3D(this -> x * a, this -> y * a, this -> z*a);
    }

    double operator * (const Vector3D& v3)
    {
        return this -> getX() * v3.x + this -> y * v3.getY() + this -> z * v3.getZ();
    }


};

ostream& operator << (ostream& os, const Vector3D& v3)
{
    os << "(" << v3.getX() << "; " << v3.getY() << "; " << v3.getZ() << ")" << endl;
    return os;
}

Vector3D operator * (const double a, const Vector3D& v3)
{
    return Vector3D(v3.getX() * a, v3.getY() * a, v3.getZ() * a);
}

istream& operator >> (istream &is, Vector3D &v3)
{
    double a, b, c;
    cin >> a >> b >> c;
    v3.setX(a);
    v3.setY(b);
    v3.setZ(c);
    return is;
}



int main()
{
    
    Vector3D A(1, 2, 3);
    Vector3D B;
   
    cout << "Значение A = " << A << endl;
    cout << "Значение B = " << B << endl;
    cout << "Умножение вектора на число:" << A * 3 << endl;
    cout << "Умножение числа на вектор:" << 2 * B << endl;
    cout << "Сумма векторов A + B = " << A + B << endl;
    cout << "Разность A - B = " << A - B << endl;


    return 0;
};
