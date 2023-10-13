// #include <stdio.h>
#include "numpyArr.hpp"
#include <iostream>

// void main(){
//     std::vector<int> arr = loadNpArrInt("/home/sagi/Desktop/vscode/Automated-FRC-Scouting/data/arr2.npy");
 
// Driver Code
int main(){
    std::vector<int> arr = loadNpArrInt("/home/sagi/Desktop/vscode/Automated-FRC-Scouting/data/arr2.npy");

    // vector containing integer elements
   
 
    std::cout << arr << std::endl;
 
    return 0;
}


