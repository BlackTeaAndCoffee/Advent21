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

   std::string file_name = "input_9.txt";
   std::fstream newfile;
   newfile.open(file_name);
   
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
   newfile2.open(file_name);

   std::vector<std::vector <int>> matrix {num_rows, std::vector<int>(num_columns,0)}; 
   
   int i = 0;


   int max_col_index = num_columns -1;
   int max_row_index = num_rows -1; 

   while(std::getline(newfile2, candidate)){
   
   for (int k =0; k < num_columns; k++){
   matrix[i][k] = candidate[k] - '0';

   }
   i+=1;
   }
   
   for (int k =0; k < num_rows; k++){
   for (int j = 0; j < num_columns; j++){
       std::cout << matrix.at(k).at(j) ;

  }
       std::cout<< "|" << std::endl;
   }








   int m_0 = matrix.at(0).at(0);  
   int m_1 = matrix.at(max_row_index).at(0);  
   int m_2 = matrix.at(0).at(max_col_index);  
   int m_3 = matrix.at(max_row_index).at(max_col_index);  

   std::cout << m_0 << ":" << m_1 << ":" << m_2 << ":" << m_3 << std::endl;




   if ((m_0 < matrix.at(1).at(0)) && (m_0 < matrix.at(0).at(1))){
     sum += m_0 +1 ;
     std::cout << "m_0: " << m_0 << std::endl;
     lows.push_back(std::vector<int> {0,0, m_0});
    }


   if ((m_1 < matrix.at(max_row_index).at(1)) && (m_1 < matrix.at(max_row_index - 1).at(0)) ){

     std::cout << "m_1: " << m_1 << std::endl;
     sum += m_1 +1 ; 
     lows.push_back(std::vector<int> {num_rows -1,0, m_1});
   } 

   if ((m_2 < matrix.at(0).at(max_col_index - 1)) && (m_2 < matrix.at(1).at(max_col_index)) ){
     
     std::cout << "m_2: " << m_2 << std::endl;
     sum += m_2 +1 ; 
     lows.push_back(std::vector<int> {0,max_col_index, m_2});
   } 
   if ((m_3 < matrix.at(max_row_index -1 ).at(max_col_index)) && (m_3 < matrix.at(max_row_index).at(max_col_index -1))){

     std::cout << "m_3: " << m_3 << std::endl;
     sum += m_3 +1 ; 
     lows.push_back(std::vector<int> {max_row_index, max_col_index, m_3});
   }
   int n_0 = 0;  

   int n_1 = 0;  
    for (int l =1;  l < max_col_index; l++){
    int n_0 = matrix.at(0).at(l);
    int n_1 = matrix.at(max_row_index).at(l);
     if ((n_0  < matrix.at(0).at(l - 1)) && (n_0 < matrix.at(1).at(l)) && (n_0 < matrix.at(0).at(l + 1))){
     
     sum += n_0 +1 ; 
     lows.push_back(std::vector<int> {0,l,n_0});
   } if ((n_1 < matrix.at(max_row_index).at(l - 1)) && (n_1 < matrix.at(max_row_index -1).at(l)) && (n_1 < matrix.at(max_row_index).at(l + 1))){

     sum += n_1 +1 ; 
     lows.push_back(std::vector<int> {max_row_index,l,n_1});
   } 
   }

   for (int l =1;  l < max_row_index ; l++){
    int n_2 = matrix.at(l).at(0);
    int n_3 = matrix.at(l).at(max_col_index);

   if ((n_2 < matrix.at(l -1).at(0)) && (n_2 < matrix.at(l).at(1)) && (n_2 < matrix.at(l + 1).at(0))){

     sum += n_2 +1 ; 
     lows.push_back(std::vector<int> {l,0, n_2});
   } if ((n_3  < matrix.at(l - 1).at(max_col_index)) && (n_3 < matrix.at(l).at(max_col_index -1)) && (n_3 < matrix.at(l + 1).at(max_col_index))){
     
     sum += n_3 +1 ; 
     lows.push_back(std::vector<int> {l,max_col_index, n_3});
   }

   }


   



   for (int m = 1; m < max_row_index; m++){
       for (int k = 1; k < max_col_index;  k++){
           int val =  matrix.at(m).at(k);
           
           bool case2 = val < matrix.at(m -1).at(k);
           
           bool case4 = val < matrix.at(m).at(k-1);
           bool case5 = val < matrix.at(m).at(k+1);
           
           bool case7 = val < matrix.at(m+1).at(k);
           bool all_cases = case2 && case4 && case5 && case7;

           if (all_cases){

             sum += val +1 ; 
             lows.push_back(std::vector<int> {m,k, val});

           }
     }
   }
   std::cout << "risk level is: " << sum << std::endl;
   std::cout << "num_rows" << num_rows << "num_columns" << num_columns << std::endl;
   for (int k = 0; k < lows.size() ; k++){
        std::cout << "the lows: " << lows.at(k).at(0) << "," << lows.at(k).at(1) << "," << lows.at(k).at(2) <<  std::endl;
   }
   newfile2.close(); 
return 0;
}
