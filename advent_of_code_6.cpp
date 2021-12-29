#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <list>

class fish {
    public:
    int internal_clock;
    long long int generation_size = 0;
};


int main(){
   std::fstream newfile;
   newfile.open("input_6.txt");
   
   std::vector <int> initial;
   std::string candidate;

   std::getline(newfile, candidate);
   std::istringstream split(candidate);


   std::vector<fish> population; 
   for (int k = 0; k < 9; k++){
   fish fish_gen;
   fish_gen.internal_clock = k; 
   population.push_back(fish_gen);
   }

   for(std::string each; std::getline(split, each, ','); initial.push_back(stoi(each)));

   for(int i=0; i < initial.size(); i++){
    population[initial[i]].generation_size += 1;
   }
   
// for(int i=0; i < population.size(); i++){
//  std::cout << "i: "  << i <<  population[i].generation_size << std::endl;
// }


   int dayplus  =0;
   int max_days = 256;
   while(dayplus < max_days){
       
   std::vector <long long int> temp1 (9,0);
       for (int k = 0; k < 9; k++){
           if (k != 0){
//                std::cout << "k:" << k << std::endl;
                temp1[k - 1] += population[k].generation_size;
//                std::cout << "generation size 8 " << temp1.at(8);
                }
           else {
                temp1[6] += population[0].generation_size;
                temp1[8] += population[0].generation_size;
           }
       }
   for (int i=0; i <9; i++){
      population[i].generation_size = temp1[i];
   }
// std::cout << "day" << dayplus << ": ";
// for (int i =0; i < population.size(); i++ ){

// std::cout << population[i].internal_clock << ", ";
// }

//  std::cout << "midnight" << std::endl;
//  for(int i=0; i < population.size(); i++){
//  std::cout << "i: "  << i <<  population[i].generation_size << std::endl;
// }
   dayplus += 1; 
//   std::cout << "done "<<std::endl;
   }
   
   long long int sum = 0;

   for (int i =0; i<9; i++){
    sum += population[i].generation_size;
   }
   std::cout << "entire population: " << sum << std::endl;
   newfile.close(); 
return 0;
}
