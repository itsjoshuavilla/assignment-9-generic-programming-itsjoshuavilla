#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class GenericArray {
private:
    T* data;
    int length;

public:
    // Constructor
    GenericArray() : data(nullptr), length(0) {}

    // Destructor
    ~GenericArray() {
        delete[] data;
    }

    // Add element to end of array
    void addElement(const T& value) {
        T* newData = new T[length + 1];

        for (int i = 0; i < length; ++i)
            newData[i] = data[i];

        newData[length] = value;

        delete[] data;
        data = newData;
        length++;
    }

    // Access element at index
    T& at(int index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& at(int index) const {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Return size
    int size() const {
        return length;
    }

    // Sum of elements
    T sum() const {
        if (length == 0)
            return T();  

        T total = T();
        for (int i = 0; i < length; ++i)
            total += data[i];

        return total;
    }

    // Max element
    T max() const {
        if (length == 0)
            throw std::runtime_error("Cannot call max() on empty array");

        T maxVal = data[0];
        for (int i = 1; i < length; ++i)
            if (data[i] > maxVal)
                maxVal = data[i];

        return maxVal;
    }

    // Min element
    T min() const {
        if (length == 0)
            throw std::runtime_error("Cannot call min() on empty array");

        T minVal = data[0];
        for (int i = 1; i < length; ++i)
            if (data[i] < minVal)
                minVal = data[i];

        return minVal;
    }

    // Slice into NEW array (caller must delete[])
    T* slice(int begin, int end) const {
        if (begin < 0 || end < 0 || begin > end || end >= length) {
            std::cerr << "Invalid slice range\n";
            return nullptr;
        }

        int newSize = end - begin + 1;
        T* sliced = new T[newSize];

        for (int i = 0; i < newSize; ++i)
            sliced[i] = data[begin + i];

        return sliced;
    }
};

#endif
