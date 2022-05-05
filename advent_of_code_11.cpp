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

   int number_cycles = 1000;
  long int zaehler = 0; 
   std::string file_name = "input_11.txt";
   std::fstream newfile;
   newfile.open(file_name);
   
   std::vector <int> verteilung;
   std::string candidate;

   std::vector<std::vector <int>> lows; 

   int num_cols = 0;
   std::getline(newfile, candidate);
  
   num_cols = candidate.size();
  
   long int sum = 0; 


   int num_rows = 1;
   while(std::getline(newfile, candidate)){
       num_rows +=1;
       

   }

   newfile.close();






   std::fstream newfile2;
   newfile2.open(file_name);

   std::vector<std::vector <int>> matrix (num_rows, std::vector<int>(num_cols,0)); 
   
   int i = 0;


   int max_col_index = num_cols -1;
   int max_row_index = num_rows -1; 

   while(std::getline(newfile2, candidate)){
   
   for (int k =0; k < num_cols; k++){
   matrix[i][k] = candidate[k] - '0';

   }
   i+=1;
   }
   

   for (int k =0; k < num_rows; k++){
   for (int j = 0; j < num_cols; j++){
       std::cout << matrix.at(k).at(j) << "," ;

  }
       std::cout<< "|" << std::endl;
   }

  std::cout << "new matrix: " << std::endl;


  newfile2.close(); 
   int cycle_of_sim =0; 

   for (int it =0; it < number_cycles; it++){
   bool not_finished = true; 

   bool nested_loop_break = false; 


   for (int m = 0; m < num_rows; m++){ 
      for (int k = 0; k < num_cols;  k++){
              matrix.at(m).at(k) += 1; 

       }
   }
   
   while(not_finished){

   nested_loop_break = false;
   for (int m = 0; m < num_rows; m++){ 
      for (int k = 0; k < num_cols;  k++){
      //std::cout << "m,k: " << m << "," << k << std::endl;
          if (matrix.at(m).at(k) >= 10){
              //std::cout << "yay" << std::endl;
              zaehler +=  1 ;
              matrix.at(m).at(k) = 0; 
              std::vector<std::vector<int>> indices {{m -1, k - 1},{m-1, k},{m-1, k + 1},{m, k -1},{m, k+1},{m+1, k-1},{m+1, k},{m+1 ,k +1}};
              for (int l =0; l < 8; l++){
                  if((indices.at(l).at(0) >= 0) && (indices.at(l).at(0) < num_rows) && (indices.at(l).at(1)>= 0)&& (indices.at(l).at(1) < num_cols)){
                     if( matrix.at(indices.at(l).at(0)).at(indices.at(l).at(1)) !=0 ){
                     matrix.at(indices.at(l).at(0)).at(indices.at(l).at(1)) += 1;
                    }
                  }

              }

          nested_loop_break = true;
          break;
          }
        
   if((m ==(num_rows-1)) && (k ==(num_cols -1)) &&(matrix.at(m).at(k) < 10)){
        //std::cout << "rows, cols: " << num_rows << "," << num_cols << "not_finished_false" << std::endl;
        not_finished = false;
   }
      
       }
   if (nested_loop_break){
        break;
   }
    
   }
    
   }

   std::cout << "new_matrix" << std::endl;
   int sum_matrix = 0;
   for (int k =0; k < num_rows; k++){
   for (int j = 0; j < num_cols; j++){
       std::cout << matrix.at(k).at(j) << "," ;
       sum_matrix+=matrix.at(k).at(j);
  }
       std::cout<< "|" << std::endl;
   }
   if (sum_matrix ==0){
       cycle_of_sim = it;
       std::cout << "cycle_of_sim" << cycle_of_sim << std::endl;
       break;
   }
   std::cout << "zaehler = " << zaehler << std::endl;
   }

return 0;
}
