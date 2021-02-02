/*
 * Driver for simple int Square class.
 *
 * Author: Kelvin Sung
 * Date: Oct 2018
 */

#include <iostream>
#include "Square.h"

using namespace std;
template<class T>
void MySwap(Square<T> &s1, Square<T> &s2) {
    Square<T> t = s1;
    s1 = s2;
    s2 = t;
}

// template allows to other data types to be accepted
template<class T>
void MyBubbleSort(T *data, int size) {
    for (int i = 0; i<size; i++) {
        for (int j = 0; j<size-1-i; j++) {
            if (data[j] < data[j+1])
                MySwap(data[j], data[j+1]);
        }
    }
}
template<class T>
void printArray(string msg, Square<T> *data, int size) {
    cout << msg << endl;
    for (int i = 0; i<size; i++) {
        cout <<  data[i] << " ";
    }
    cout << endl;
}


int main(int argc, char** argv)
{
    Square<int> s1, s2;

    s1.setSize(5);
    s2.setSize(3);

    cout << "S1 is: " << s1 << endl;
    cout << "S2 is: " << s2 << endl;

    if (s1 < s2) 
        cout << "s1 is smaller" << endl;
    else 
        cout << "s2 is smaller" << endl;

    s1 = s2;
    cout << "after assignment" << endl;
    cout << "s1 is:" << s1 << endl;
    cout << "s2 is:" << s2 << endl;
    
    // do bubble sort
    int  num[10] = {10, 9, 8, 1, 0, 7, 20, 14, 2, 4};
    Square<int> sArray[10];  // call initialize by default constructors
    for (int i = 0; i<10; i++) {
        sArray[i].setSize(num[i]);
    }
    printArray("Array before sorting:", sArray, 10);
    MyBubbleSort(sArray, 10);
    printArray("Array after sorting:", sArray, 10);

    // dynamically creating a Square<double> and running bubble sort
    double num2[10] = {5.2,123.3,5.45,234.3,563.12,3.2,4312.1,456.5,45.6,2.3};
    Square<double> sq[10];
    for (int i = 0; i < 10; i++) {
        sq[i].setSize(num2[i]);
    }
    MyBubbleSort(sq, 10);
    printArray("Array after sorting:", sq, 10);
}
