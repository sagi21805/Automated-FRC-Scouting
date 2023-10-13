#ifndef __printVector__HPP
#define __printVector__HPP

#include <stdio.h>
#include "cnpy.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//TODO imporve to Nd arrays.
template <typename S>
std::ostream& operator<<(std::ostream& os, const std::vector<S>& vector){
    // Printing all the elements
    // using <<
    os << "[";
    for (auto element : vector) {
        os << element << " ";
    }
    os << "\b]";
    return os;
}

vector<vector<int>> vector1Dto2D(vector<int> input, vector<size_t> newShape);

#endif