#include <iostream>
#include "GenericArray.h"

int main() {
    GenericArray<int> int_array;

    // Add elements
    int_array.addElement(10);
    int_array.addElement(20);
    int_array.addElement(5);
    int_array.addElement(7);
    int_array.addElement(42);
    int_array.addElement(15);
    int_array.addElement(30);

    // Print info
    std::cout << "Size of array: " << int_array.size() << std::endl;
    std::cout << "Sum of array: " << int_array.sum() << std::endl;
    std::cout << "Max value: " << int_array.max() << std::endl;
    std::cout << "Min value: " << int_array.min() << std::endl;

    // Test at()
    std::cout << "Element at index 2: " << int_array.at(2) << std::endl;

    // Slice test
    int begin = 1;
    int end = 4;

    int* sliced_array = int_array.slice(begin, end);

    if (sliced_array != nullptr) {
        std::cout << "Sliced array [" << begin << " to " << end << "]: ";
        for (int i = 0; i < (end - begin + 1); i++) {
            std::cout << sliced_array[i] << " ";
        }
        std::cout << std::endl;

        delete[] sliced_array;
    }

    return 0;
}
