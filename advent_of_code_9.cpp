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
   newfile.open("input_9.txt");
   
   std::vector <int> verteilung;
   std::string candidate;

   std::vector<std::vector <int>> lows; 

   int num_columns = 0;
   std::getline(newfile, candidate);
  
   num_columns = candidate.size();
  
   long int sum = 0; 


   int num_rows = 1;
   while(std::getline(newfile, candidate)){
       num_rows +=1;
       

   }

   newfile.close(); 
   std::fstream newfile2;
   newfile2.open("input_9.txt");

   std::vector<std::vector <int>> matrix {100, std::vector<int>(100,0)}; 
   
   int i = 0;
   
   while(std::getline(newfile2, candidate)){
   
   for (int k =0; k < 100; k++){
   matrix[i][k] = candidate[k] - '0';

   }
   i+=1;
   }
   
   int m_0 = matrix[0][0];  
   int m_1 = matrix[99][0];  
   int m_2 = matrix[0][99];  
   int m_3 = matrix[99][99];  

   if ((m_0 < matrix[1][0]) && (m_0 < matrix[1][1]) && (m_0 < matrix[0][1])){
     sum += m_0 +1 ; 
     lows.push_back(std::vector<int> {0,0});
   } else if ((m_1 < matrix[99][1]) && (m_1 < matrix[98][0]) && (m_1 < matrix[98][1])){

     sum += m_1 +1 ; 
     lows.push_back(std::vector<int> {99,0});
   } else if ((m_2 < matrix[0][98]) && (m_2 < matrix[1][98]) && (m_2 < matrix[1][99])){

     sum += m_2 +1 ; 
     lows.push_back(std::vector<int> {0,99});
   }else if ((m_3 < matrix[98][98]) && (m_3 < matrix[98][99]) && (m_3 < matrix[99][98])){

     sum += m_3 +1 ; 
     lows.push_back(std::vector<int> {99,99});
   }
   
   for (int l =1;  l < 99; l++){
    m_0 = matrix[0][l];
    m_1 = matrix[99][l];
     if ((m_0  < matrix[0][l - 1]) && (m_0 < matrix[1][l]) && (m_0 < matrix[0][l + 1])){
     
     sum += m_0 +1 ; 
     lows.push_back(std::vector<int> {0,l});
   } else if ((m_1 < matrix[99][l - 1]) && (m_1 < matrix[98][l]) && (m_1 < matrix[99][l + 1])){

     sum += m_1 +1 ; 
     lows.push_back(std::vector<int> {99,l});
   } 
   }

   for (int l =1;  l < 99; l++){
    m_2 = matrix[l][0];
    m_3 = matrix[l][99];

   if ((m_2 < matrix[l -1 ][0]) && (m_2 < matrix[l][1]) && (m_2 < matrix[l + 1][0])){

     sum += m_2 +1 ; 
     lows.push_back(std::vector<int> {l,99});
   } else if ((m_3  < matrix[l - 1][99]) && (m_3 < matrix[l][98]) && (m_3 < matrix[l + 1][99])){
     
     sum += m_3 +1 ; 
     lows.push_back(std::vector<int> {l,0});
   }

   }


   



   for (int m = 1; m < 99; m++){
       for (int k = 1; k < 99;  k++){
           int val =  matrix[m][k];
           
           bool case1 = val < matrix[m -1 ][k -1];
           bool case2 = val < matrix[m -1 ][k];
           bool case3 = val < matrix[m- 1][k+ 1];
           
           bool case4 = val < matrix[m][k-1];
           bool case5 = val < matrix[m][k+1];
           
           bool case6 = val < matrix[m+1][k-1];
           bool case7 = val < matrix[m+1][k];
           bool case8 = val < matrix[m+1][k+1];
           bool all_cases = case1 && case2 && case3 && case4 && case5 && case6 && case7 && case8;

           if (all_cases){

             sum += val +1 ; 
             lows.push_back(std::vector<int> {m,k});

           }
     }
   }
   std::cout << "risk level is: " << sum << std::endl; 
   newfile2.close(); 
return 0;
}
