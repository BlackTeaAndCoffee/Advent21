#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>




int main(){
std::ifstream file;
file.open("numbers.txt");



std::vector <std::vector <int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

std::vector <int> vec;

matrix[0].erase(std::remove(matrix[0].begin(), matrix[0].end(), 1),matrix[0].end()) ;
for (int i = 0; i <3; i++){
std::cout << matrix[0][i] << std::endl;
}

float m = 2.0;
int dd = 0;

dd = int(m);
std::cout << dd << std::endl;
return 0;
}
