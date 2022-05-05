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


bool isnotin_vec(std::vector<int> vec, int first){
bool return_val = true; 

for(int i = 0; i < vec.size(); i++){
if(first == vec.at(i)){
std::cout << "da simma" << std::endl;
return_val = false;
}
}
return return_val;

}

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

   std::vector<std::vector <int>> matrix (num_rows, std::vector<int>(num_columns,0)); 

   
   int i = 0;


   int max_col_index = num_columns -1;
   int max_row_index = num_rows -1; 

   while(std::getline(newfile2, candidate)){
   int temp_int = 0; 

   for (int k =0; k < num_columns; k++){
   
       temp_int = candidate[k] - '0';
       if (temp_int == 9){
        matrix[i][k]  = 9; 
       } else {
        
        matrix[i][k]  = 0; 
       }

   }
   i+=1;
   }
   
   newfile2.close(); 


   for (int k =0; k < num_rows; k++){
   for (int j = 0; j < num_columns; j++){
       std::cout << matrix.at(k).at(j) ;

  }
       std::cout<< "|" << std::endl;
  }
  
  std::vector<int> exclude {9};
  int new_basin = 1; 
   

  std::vector <int> sizes; 

  for (int m =0; m < num_rows; m++){
  for (int j = 0; j < num_columns; j++){
  if(isnotin_vec(exclude, matrix.at(m).at(j))){

  int x_pos = j; 
  int y_pos = m;


  std::cout << "x_pos: " << x_pos << "y_pos: " << y_pos << std::endl;
  
  std::vector<int> pos {x_pos, y_pos};
  bool increasing = true; 

  std::set<std::vector <int>> locations;
  locations.insert(pos);
  

  while(increasing){
    exclude.push_back(new_basin);
    int size_1 = locations.size();
    std::set<std::vector<int>>::iterator it; 

    for (it= locations.begin(); it != locations.end(); ++it){
       std::vector<int> pos_cand  = *it;
       
       int x = pos_cand[0];
       int y = pos_cand[1];
       
       int x_1 = x -1;  
       int y_1 = y;
       
       int x_2 = x +1;
       int y_2 = y;
       
       int x_3 = x;
       int y_3 = y +1;
       
       int x_4 = x;
       int y_4 = y-1;
       
       std::vector<std::vector<int>> positions {{x_1, y_1}, {x_2,y_2}, {x_3, y_3}, {x_4, y_4}};
      
      std::cout << "max_row: " << max_row_index << "max_col_index: " << max_col_index << std::endl;
      std::cout << "x,y" << x_1 << "," << y_1 << "x,y" << x_2 << "," << y_2 << "x,y" << x_3 << "," << y_3 << "x,y" << x_4 << "," << y_4 << std::endl;
       for (int k = 0; k < 4; k++){
       if ( ((positions.at(k).at(0) >= 0) && (positions.at(k).at(0) <= max_col_index )) && ((positions.at(k).at(1) >= 0) && (positions.at(k).at(1) <= max_row_index))){
          if (isnotin_vec(exclude, matrix.at(positions.at(k).at(1)).at(positions.at(k).at(0)))){
              locations.insert(std::vector<int>{positions.at(k).at(0),positions.at(k).at(1)});
              matrix.at(positions.at(k).at(1)).at(positions.at(k).at(0)) = new_basin;              

          }
       }

       }
    }
    
    int size_2 = locations.size();
    if(size_2 == size_1){
        std::cout << "yay" << std::endl;
        increasing = false;
    }

  }
  
  new_basin += 1; 
  std::set<std::vector<int>>::iterator it2; 

//for (it2= locations.begin(); it2 != locations.end(); ++it2){
//    std::vector<int> index = *it2;
//    std::cout << index[0] <<"," << index[1] << std::endl;
//}
  sizes.push_back(locations.size());


  }}}
  

  
  sort(sizes.begin(), sizes.end(), std::greater<int>());
  std::cout << "biggest: " << sizes.at(0) << "second: " << sizes.at(1) << "third: " << sizes.at(2) << std::endl;
  std::cout << "result: " << sizes.at(0)*sizes.at(1)*sizes.at(2) << std::endl;
return 0;
}
