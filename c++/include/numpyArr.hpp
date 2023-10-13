#ifndef __numpyArr__HPP
#define __numpyArr__HPP

#include <stdio.h>
#include "cnpy.h"

std::vector<int> loadNpArrInt(char *path);

std::vector<double> loadNpArrDouble(char *path);

void saveNpArr(char *path, std::vector<int> data, std::vector<size_t> shape, std::string mode);

void saveNpArr(char *path, std::vector<double> data, std::vector<size_t> shape, std::string mode);

#endif