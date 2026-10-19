// Operator overloading with vectors
// Read and understand the concept of operator overloading
// Read Chapter 7 to understand the difference between pass_by_reference, pass_by_value and pass_by_const_reference

import std;
using namespace std;

class Vector
{
    // Private data members
private:
    int x;
    int y;

    // Public member functions
public:
    Vector(int x, int y)
        : x{x}, y{y}
    {
    }

    // Constant member functions promises not to modify the object
    int get_x() const
    {
        return x;
    }

    int get_y() const
    {
        return y;
    }
};

// Overloaded operators

// {4, 6} {6, 8}
Vector operator+(const Vector &a, const Vector &b)
{
    return Vector{
        // You can only call member functions that promise not to modify the object
        a.get_x() + b.get_x(),
        a.get_y() + b.get_y()
    };
}

// {4, 5} {4, 9}
// 4 == 4 && 5  == 9
Vector operator-(const Vector &a, const Vector &b)
{
    return Vector{
        a.get_x() - b.get_x(),
        a.get_y() - b.get_y()
    };
}

// Overloaded operator for equality comparison
void print(const Vector &v)
{
    print("Vector({}, {})\n", v.get_x(), v.get_y());
}

int main()
{
    Vector v1{2, 4};
    Vector v2{5, 3};

    Vector v3 = v1 + v2;

    print(v1 - v2);
}

// Operator overloading with vectors
