#include"cnpy.h"
#include<stdio.h>

using namespace std;
using namespace cnpy;

std::vector<int> loadNpArrInt(char *path){
    cnpy::NpyArray numpyArr = cnpy::npy_load(path);
    return numpyArr.as_vec<int>();
}

std::vector<double> loadNpArrDouble(char *path){
    cnpy::NpyArray numpyArr = cnpy::npy_load(path);
    return numpyArr.as_vec<double>();
}

void saveNpArr(char *path, std::vector<int> data, std::vector<size_t> shape, std::string mode){
    cnpy::npy_save(path ,&data[0],shape,mode);
}

void saveNpArr(char *path, std::vector<double> data, std::vector<size_t> shape, std::string mode){
    cnpy::npy_save(path ,&data[0],shape,mode);
}
