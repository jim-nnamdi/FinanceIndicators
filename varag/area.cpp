// assignment to csc 226

#include<iostream>
#include<cmath>

using namespace std;

template<class T>
class Area {
  public:
  T areaOfSquare(T side);
  T areaOfTriangle(T base, T height);
  T areaOfCircle(double pi, double radius);  
};

template<class T>
T Area<T>::areaOfSquare(T side){

    /**
     * we can also use the math lib
     * to solve for this pow(side, side)
     */
    T area = side * side;
    return area;
}

template<class T>
T Area<T>::areaOfTriangle(T base, T height){
    T area = (base * height)/2;
    return area;
}

template<class T>
T Area<T>::areaOfCircle(double pi, double radius){
    // we can also do pi * (radius * radius)
    // but i decided to use the math std lib here ...
    T area = pi * pow(radius, radius);
    return area;
}


int main(){
    // since we're using template class
    // its easy to create solutions for 
    // different primitive types.

    Area<int> a;
    cout <<"area of square -> " << a.areaOfSquare(2) << endl;
    cout <<"area of triangle -> " << a.areaOfTriangle(2,3) << endl;
    cout <<"area of circle -> " << a.areaOfCircle(3.142,4) << endl;

    Area<double> b;
    cout <<"area of square -> " << b.areaOfSquare(2) << endl;
    cout <<"area of triangle -> " << b.areaOfTriangle(2,3) << endl;
    cout <<"area of circle -> " << b.areaOfCircle(3.142,4) << endl;

    Area<float> c;
    cout <<"area of square -> " << c.areaOfSquare(2) << endl;
    cout <<"area of triangle -> " << c.areaOfTriangle(2,3) << endl;
    cout <<"area of circle -> " << c.areaOfCircle(3.142,4) << endl;

}