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
   newfile.open("input_7.txt");
   
   std::vector <int> verteilung;
   std::string candidate;

   std::getline(newfile, candidate);
   std::istringstream split(candidate);



   long long int min_sum; 
   long long int sum;
   for(std::string each; std::getline(split, each, ','); verteilung.push_back(stoi(each)));

 
   long int max_val =0;
   
   for (int l=0; l < verteilung.size();  l++){
   if (verteilung[l] > max_val){
       max_val = verteilung[l];
   }
   }


   int new_pos= 1; 
   long int steps = 0;
   for(int i=0; i < verteilung.size(); i++){
    steps = abs(verteilung[i] - new_pos);
    for (int k = 1; k <= steps; k++){
    sum += k;
    }
   }
   min_sum = sum; 

   for (int k=2; k < max_val; k++){
   

   sum = 0;
   new_pos= k; 
   steps = 0;
   for(int i=0; i < verteilung.size(); i++){
    steps = abs(verteilung[i] - new_pos);
    for (int m = 1; m <= steps; m++){
    sum += m;
    }

   } 
   if (sum < min_sum){
      min_sum = sum;
   }
   }




   std::cout << "sum: " << min_sum << std::endl; 
// for(int i=0; i < population.size(); i++){
//  std::cout << "i: "  << i <<  population[i].generation_size << std::endl;
// }

   newfile.close(); 
return 0;
}
