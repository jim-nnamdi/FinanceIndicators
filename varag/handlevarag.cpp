#include<iostream>
#include<cstdarg>

using namespace std;

double average(int num, ...){
    int i;
    double sum = 0.0;

    va_list valist;

    // initialize the value of va_list in start
    va_start(valist, num);
    for(i = 0; i < num; i++){
        sum += va_arg(valist, int);
    }
    va_end(valist);
    return sum/num;
}

int main(){
    double avg = average(2,3,4,5);
    cout << "average of 2,3,4,5 is -> " << avg << endl;
}