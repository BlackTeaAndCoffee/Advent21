#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <stdlib.h>

class fish {
    public:
    int internal_clock;
    long long int generation_size = 0;
};


int main(){
   std::fstream newfile;
   newfile.open("input_8.txt");
   
   std::string candidate;

   long int sum = 0;
   while(std::getline(newfile, candidate)){
   
   std::vector <std::string> verteilung;

   std::istringstream split(candidate);

   std::list<int> unique {2,3, 7, 4};



   for(std::string each; std::getline(split, each, '|'); verteilung.push_back(each));


   std::istringstream digits(verteilung[1]);

   std::string seven_symb;
   for (int i =0; i < 4; i++){
       digits >> seven_symb;
       std::cout << seven_symb << std::endl;
       int size_symb = seven_symb.size();
       std::cout << size_symb << std::endl;
       bool isin_unique = (std::find(unique.begin(), unique.end(), size_symb) != unique.end());
       if (isin_unique){
           std::cout << "yay"<< std::endl;
           sum += 1;
       }

   }
   

   };

   std::cout << "And the number is" << sum << std::endl;
   newfile.close(); 
return 0;
}
