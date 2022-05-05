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
#include <bits/stdc++.h>
#include <map>


class Fold {
    public:
    std::string name;
    int pos; 

};
int main(){

   std::string file_name = "input_13.txt";
   std::fstream newfile;
   newfile.open(file_name);
  
   std::string candidate;

   int size_x = 0;
   int size_y = 0;

   
   std::vector<std::vector<int>> pairs; 
   
   std::vector<int> verteilung;
   std::vector<std::string> verteilung2;

   std::vector<std::string> verteilung3;
   
   std::vector<Fold> pairs_fold;


   std::vector<int> temp;
   
   bool run = true; 



   int kk = 0; 

   int mm = 0;

   std::vector<int> be_pushed(2,0);
   while(run){
   std::getline(newfile,candidate);
   std::istringstream split(candidate);


   if (candidate != "" ){
   for(std::string each; std::getline(split, each, ','); verteilung.push_back(std::stoi(each)));
  

   }else{
    run = false; 
   }
   }


   for (int k=0; k < verteilung.size()/2; k++){

   be_pushed.at(0) = verteilung.at(2*k);
   be_pushed.at(1) = verteilung.at(2*k+1);
   pairs.push_back(be_pushed);


   }



   while (std::getline(newfile,candidate)){

   std::istringstream split2(candidate);

   std::vector<std::string> verteilung2;
   for(std::string each; std::getline(split2, each, ' '); verteilung2.push_back(each));
   
   std::cout << verteilung2.at(2) << std::endl;   
   std::istringstream split3(verteilung2.at(2));
   for(std::string each; std::getline(split3, each, '='); verteilung3.push_back(each));
   }

   for (int k=0; k < verteilung3.size()/2; k++){

   Fold fold_it; 

   fold_it.name = verteilung3.at(2*k);
   fold_it.pos = std::stoi(verteilung3.at(2*k+1));
   pairs_fold.push_back(fold_it);


   }

   for (int k=0; k < pairs_fold.size(); k++){

   std::cout << pairs_fold.at(k).name << "," << pairs_fold.at(k).pos << std::endl;
   }


   int x_max  = 0; 

   int y_max = 0; 


   for (int k=0; k < pairs.size(); k++){
       if (pairs.at(k).at(0) > x_max){
            x_max =pairs.at(k).at(0);
       }else if (pairs.at(k).at(1) > y_max){
           y_max = pairs.at(k).at(1);
       }
   }

   std::vector<std::vector<int>> matrix (y_max +1, std::vector<int>(x_max +1 , 1)); 


   for (int k=0; k < pairs.size(); k++){
       matrix.at(pairs.at(k).at(1)).at(pairs.at(k).at(0)) = 0;
   }
   

   for (int i =0; i < pairs_fold.size(); i++){
   

   if (pairs_fold.at(i).name == "x"){
       x_max = pairs_fold.at(i).pos; 

       std::vector<std::vector<int>> matrix_new (y_max +1, std::vector<int>(x_max , 1)); 
   
   for (int k=0; k < pairs.size(); k++){
       if (pairs.at(k).at(0) < x_max){
           matrix_new.at(pairs.at(k).at(1)).at(pairs.at(k).at(0)) = 0;

       } else{

          int x_fold = 2*x_max  - pairs.at(k).at(0); 
          matrix.at(pairs.at(k).at(1)).at(x_fold) = 0;
          pairs.at(k).at(0) = x_fold; 
       }
   }
      for (int m=0; m<y_max +1; m++){
      for (int l=0; l <matrix_new.at(0).size(); l++){
          
          std::cout <<  matrix.at(m).at(l) << ",";
      }
      std::cout << "|" << std::endl;
   }

   } else{

   y_max = pairs_fold.at(i).pos; 

   std::vector<std::vector<int>> matrix_new (y_max, std::vector<int>(x_max + 1  , 1)); 
   
   for (int k=0; k < pairs.size(); k++){
       if (pairs.at(k).at(1) < y_max){
       matrix_new.at(pairs.at(k).at(1)).at(pairs.at(k).at(0)) = 0;

       } else{

       int y_fold = 2*y_max  - pairs.at(k).at(1); 
       matrix.at(y_fold).at(pairs.at(k).at(0)) = 0;
       pairs.at(k).at(1) = y_fold; 
       }
   }

   for (int m=0; m<y_max +1; m++){
      for (int l=0; l <matrix_new.at(0).size(); l++){
          
          std::cout <<  matrix.at(m).at(l) << ",";
      }
      std::cout << "|" << std::endl;
   }



   }

     }
   return 0;
}
