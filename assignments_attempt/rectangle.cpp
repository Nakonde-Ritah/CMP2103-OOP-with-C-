
#include <iostream>

using namespace std;

class Rectangle{
    private: 
        double length;
        double width;

    public:
        Rectangle(double length, double width):length(length), width(width) {}
        void set_Length(double set_length){
                length = set_length;
            }

            void set_Width(double set_width){
                width = set_width;
            }

            double get_Length(){
                return length;
            }

            double get_Width(){
                return width;
            }   

            double calc_area(){
                return length * width;
            }

            double calc_perimeter(){
                return 2 * (length + width);
            }

};

int main(){
    Rectangle rectangle1(4.5 , 7.0);

    Rectangle rectangle2(6.8 , 9.0);

    rectangle1.set_Length(3.0);  

    cout << "Rectangle 1: Length = " << rectangle1.get_Length() << ", Width = " << rectangle1.get_Width() << endl;
    cout << "Rectangle 1: Area = " << rectangle1.calc_area() << ", Perimeter = " << rectangle1.calc_perimeter() << endl;

    cout << "Rectangle 2: Length = " << rectangle2.get_Length() << ", Width = " << rectangle2.get_Width() << endl;
    cout << "Rectangle 2: Area = " << rectangle2.calc_area() << ", Perimeter = " << rectangle2.calc_perimeter() << endl;

}