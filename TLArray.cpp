#include <iostream>
#include <algorithm>
using namespace std;

// Class template for Array
template <typename T>
class Array {
private:
    T* array;
    int size;

public:
    // Constructor to allocate the array based on the size entered
    Array(int size) : size(size) {
        array = new T[size];
    }

    // Destructor to delete the array
    ~Array() {
        delete[] array;
    }

    // Function to allow the user to fill in the array based on the size
    void fillArray() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> array[i];
        }
    }

    // Function used to display the elements of the array
    void displayArray() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Function that sorts the array and displays the sorted elements
    void sortArray() {
        sort(array, array + size);
        cout << "Sorted array elements: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

// Main function to test the Array class template
int main() {
    // Program header
    cout << "*******************************************" << endl;
    cout << "**       Array Template Program          **" << endl;
    cout << "**     Author: Austin Farias             **" << endl;
    cout << "**   Purpose: Demonstrating the use of   **" << endl;
    cout << "**            the Array template         **" << endl;
    cout << "**   Compiler: C++ Compiler              **" << endl;
    cout << "**         Date: March 12, 2024           **" << endl;
    cout << "*******************************************" << endl;
    cout << endl;

    // Create an object of Array with double type
    int size1;
    cout << "Enter the size of the first array: ";
    cin >> size1;
    Array<double> arr1(size1);
    arr1.fillArray();
    cout << "First ";
    arr1.displayArray();
    arr1.sortArray();

    // Create an object of Array with int type
    int size2;
    cout << "Enter the size of the second array: ";
    cin >> size2;
    Array<int> arr2(size2);
    arr2.fillArray();
    cout << "Second ";
    arr2.displayArray();
    arr2.sortArray();

    return 0;
}
