//assignment for csc 226

#include<iostream>
#include<vector>

using namespace std;

double average(){

    // the sum is zero by default
    int sum = 0;

    // set the type and var name for user input
    int number;

    // declare the array size, make it constant
    // since we're dealing with a fixed value size
    // note: we can make the user to set this value.
    static const int arrsize = 10;

    // average can be in decimal places
    // make it to be of type double
    double average = 0.0;

    // run a for loop and capture the items
    // to be calculated
    for(int i = 0; i < arrsize; i++){
        cout << "declare numbers" << endl;
        cin >> number;
        sum = sum + number;
    }

    // average is the total sum divided by array size
    average = sum/arrsize;
    cout << "average is -> "<< average << endl;
    return average;
}

int main (){
    // call the function inside main
    double a = average();
    cout << a << endl;
}