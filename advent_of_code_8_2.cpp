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
#include <set>
#include <bits/stdc++.h>


class fish {
    public:
    int internal_clock;
    long long int generation_size = 0;
};


bool compare(std::set<char> s1, std::set<char> s2){

   std::set<char> result; 

   std::set<char> result_2; 
  

   std::set<char>::iterator it;

   std::cout << "here come s1" << std::endl;
   for (it = s1.begin(); it != s1.end(); ++it){
     std::cout << *it <<std::endl;
   }

   std::set<char>::iterator it2;

   std::cout << "here come s2" << std::endl;
   for (it2 = s2.begin(); it2 != s2.end(); ++it2){
     std::cout << *it2 <<std::endl;
   }


   std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), 
                        std::inserter(result, result.end()));

   std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), 
                        std::inserter(result_2, result_2.end()));
   
   bool return_val = false;
   if (result.empty() && result_2.empty()){
      return_val = true;
   }
   std::cout << "compare" << return_val<< std::endl;
   return return_val;
};

bool containity(int size){

bool return_val = false;
std::vector<int> unique {2,3,4,7};
for (int m= 0; m < 4; m++){
if (size == unique[m])
return_val = true;
}
return return_val;
}


int main(){
   std::fstream newfile;
   newfile.open("input_8.txt");
   
   std::string candidate;
   std::vector <std::set <char>> numbers {10, std::set<char>({})};
   

   int summand_1 = 0; 

   int summand_2 = 0;
   
   long long int sum = 0;

   while(std::getline(newfile, candidate)){


   std::istringstream split(candidate);

   std::vector <std::string> verteilung; 


   for(std::string each; std::getline(split, each, '|'); verteilung.push_back(each));


   std::vector <std::string> map = {"acedgfb","cdfbe","gcdfa", "fbcad","dab", "cefabd","cdfgeb","eafb","cagedb","ab"}; 
  
   std::vector <std::string> four_digits = {"cdfeb","fcadb","cdfeb","cdbaf"}; 
    
   std::istringstream zahlen(verteilung[0]);

   std::string temp_string; 
   for (int m = 0; m < 10; m++){
      zahlen >> map[m];
   }

   std::istringstream zahlen_vier(verteilung[1]);

   std::string temp_string_vier; 
   for (int m = 0; m < 4; m++){
      zahlen_vier >> four_digits[m];
   }




   


   std::vector <std::set <char>> six {3, std::set<char>({})};
  
   std::vector <std::set <char>> five {3, std::set<char>({})};


    
    int l =0; 
    int f = 0;

   for (int i =0; i <10; i++){
   
   int size_cand = map[i].size();
   

   std::cout << "i: " << std::endl;
   
   bool cases = containity(size_cand);
   std::cout << "case:" << i << "size" << size_cand <<" is it unique " << cases << std::endl; 
   if (cases){

   std::cout << "case:" << i << "size" << size_cand <<" is it unique " << cases << std::endl; 
      std::set<char> s = {}; 
      for (int j=0; j < size_cand;j++){
            s.insert(map[i][j]);
             
            //std::cout << map[i][j] << std::endl;
      
      }
      if (size_cand == 2){
           
           numbers[1] = s;
      } else if (size_cand == 4){
           numbers[4] = s;
      } else if (size_cand == 3){

           numbers[7] = s;
      } else if (size_cand == 7){
           
           numbers[8] = s;
      }




   } else if (size_cand ==6){
      std::set<char> s = {}; 
      for (int j=0; j < size_cand;j++){
            s.insert(map[i][j]);
            
            //std::cout << map[i][j] << std::endl;
      
      }
      six[l] = s;
   
      l += 1;
   }else if (size_cand == 5){

      std::set<char> s = {}; 
      for (int j=0; j < size_cand;j++){
            s.insert(map[i][j]);
            
            //std::cout << map[i][j] << std::endl;
      
      }
      five[f] = s;
   
      f += 1;

   }
   }


   int index_of_six =0;
   for (int m=0; m<3; m++){
   
   std::set<char> result; 
   std::set<char> result_2; 

   std::set_difference(numbers[8].begin(), numbers[8].end(), six[m].begin(), six[m].end(), 
                        std::inserter(result, result.end()));

   std::set_difference(result.begin(), result.end(), numbers[1].begin(), numbers[1].end(), 
                        std::inserter(result_2, result_2.end()));


   
   if (result_2.empty()){
   numbers[6] = six[m];
   index_of_six  = m;
   }}

   six.erase(six.begin() + index_of_six);

   for (int m=0; m<2; m++){
   
   std::set<char> result_3; 
   std::set<char> result_4; 
   std::set<char> result_5; 



   std::set_difference(numbers[8].begin(), numbers[8].end(), six[m].begin(), six[m].end(), 
                        std::inserter(result_3, result_3.end()));

   std::set_difference(result_3.begin(), result_3.end(), numbers[4].begin(), numbers[4].end(), 
                        std::inserter(result_4, result_4.end()));

   
   std::set_difference(six[m].begin(), six[m].end(), numbers[4].begin(), numbers[4].end(), 
                        std::inserter(result_5, result_5.end()));


   std::set<char> s = {}; 
   
   if(result_4.empty()){
   numbers[0] = six[m];
   } else if(result_5.size() == 2){
   numbers[9] = six[m];
   }
   }





    

   std::cout <<"numbers" << std::endl;
   std::set<char>::iterator it;

   for (it = numbers[9].begin(); it != numbers[9].end(); ++it){
     std::cout << *it <<std::endl;
   }
int index_three = 0;

for (int m = 0; m < 3; m++){
   
   std::set<char> result; 
   

   std::set_difference(five[m].begin(), five[m].end(), numbers[1].begin(), numbers[1].end(), 
                        std::inserter(result, result.end()));


     if(result.size() == 3){
   numbers[3] = five[m];
   index_three = m;
   
   }
   
   }

five.erase(five.begin() + index_three);






   for (int m = 0; m < 2; m++){
   
   std::set<char> result_2; 
   


   std::set_difference(five[m].begin(), five[m].end(), numbers[6].begin(), numbers[6].end(), 
                        std::inserter(result_2, result_2.end()));


   if(result_2.empty()){
   numbers[5] = five[m];
   } else if(!result_2.empty()){
   numbers[2] = five[m];
   }
   }


   std::vector<int> digit(4,0);

   std::vector <std::set <char>> display {4, std::set<char>({})};
   
   for (int i =0; i <4; i++){
   
   int size_cand = four_digits[i].size();


   std::set<char> s = {}; 
   for (int j=0; j < size_cand;j++){
         s.insert(four_digits[i][j]);
            
            //std::cout << map[i][j] << std::endl;
      
    }
    display[i] = s;
   }


   for (int ll = 0; ll <4; ll++){
   std::cout <<"display:" << ll  << std::endl;
   std::set<char>::iterator itf;

   for (itf = display[ll].begin(); itf != display[ll].end(); ++itf){
     std::cout << *itf <<std::endl;
   }
   }


   for (int i =0; i < 4; i++){
      for (int k = 0; k<10; k++){
        if (compare(display[i],numbers[k])){
          digit[i] = k;
        }

      }
   }

   std::cout << "result" << std::endl;
   for (int i = 0; i < 4; i++){
   std::cout << digit[i]<< std::endl;
}
   long int summands = 0; 
   
   for (int i = 0; i < 4; i++){
   summands += digit[i]*pow(10,3-i);
   
   }

   
   std::cout << "summands: " << summands << std::endl;
   sum += summands;
}
std::cout << "sum: " << sum << std::endl;
   newfile.close(); 
return 0;
}
