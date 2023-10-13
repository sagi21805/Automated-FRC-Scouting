#ifndef __numpyArr__HPP
#define __numpyArr__HPP

#include <stdio.h>
#include "cnpy.h"
#include <iostream>


std::vector<int> loadNpArrInt(std::string path);

std::vector<double> loadNpArrDouble(std::string path);

void saveNpArr(char *path, std::vector<int> data, std::vector<size_t> shape, std::string mode);

void saveNpArr(char *path, std::vector<double> data, std::vector<size_t> shape, std::string mode);


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

#endif