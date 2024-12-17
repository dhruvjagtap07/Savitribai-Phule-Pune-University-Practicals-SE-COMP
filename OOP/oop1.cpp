#include<iostream>

using namespace std;

// Implement a class Complex which represents the Complex Number data type. Implement the
// following
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers.
// 4. Overload operators << and >> to print and read Complex Numbers

class complex{
      private: 
      float real, img;
      public:
        //  float real, img;
         complex () {}
         complex operator + (complex);
         complex operator * (complex);
         friend ostream & operator << (ostream &, complex &);
         friend istream & operator >> (istream &, complex &);
};

complex complex::operator + (complex obj){

    complex temp;
    temp.real = real + obj.real; 
    temp.img = img + obj.img;
    return (temp);
}
    

complex complex::operator * (complex obj){

    complex temp;
    temp.real = real * obj.real - img * obj.img;          
    temp.img = img * obj.real + real * obj.img;
    return (temp);
}

ostream & operator << (ostream &os, complex &obj) {

    os << " " << obj.real;
    os << "+" << obj.img << "i";
    return os;
}

istream & operator >> (istream &is, complex &obj) {

    is >> obj.real;
    is >> obj.img;
    return is;
}
 
int main () {
    
    complex a, b, c, d;
    cout << "Enter the first complex no. " << endl;
    cout << "Enter the real and img: ";
    cin >> a;
    cout << "Enter the second complex no. " << endl;
    cout << "Enter the real and img: ";
    cin >> b;
    cout << "Arithmetic Operation" << endl;
    c = a + b;
    cout << "Addition: " << c << endl;
    d  = a * b;
    cout << "Multiplication: " << d << endl;
    
    return 0;
}
    
    

     



        
        