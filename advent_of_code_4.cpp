#include <iostream>
#include <fstream>
#include <string>


qq
























#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <list>

class BingoBoard {
    public:
    std::vector <std::vector <int>> board {5 , std::vector<int>(5, 5)};
    int first_done;
    bool done  = false;
    long int result;
    std::vector <std::vector <int>> board_transposed {5 , std::vector<int>(5, 5)};
    std::list <std::vector<int>> lines;

    //void print_line(){
    //for (int i = 0; i < 12; i++){
    //  std::cout << binary_num.at(i);
    // }

    //}
};



int binary_to_int(std::vector <int> fname){
int result = 0;

for (int i=0; i < fname.size(); i++){
result += pow(2,i)*fname[fname.size() - 1 - i];
}
return result;
}


int main(){
   bool most_num = true;
   long int end_result = 0;
   long int result = 0;
   
   std::fstream newfile;
   newfile.open("input_4.txt"); //open a file to perform read operation using file object
     

   std::vector <std::string> temp;
   
   std::vector <int> random_numb;
   std::string candidate;
   
   std::getline(newfile, candidate);
   
   std::istringstream split(candidate);

   for (std::string each; std::getline(split, each, ','); temp.push_back(each));
   
// for (int i =0; i < temp.size(); i++){
//  std::cout << temp[i] << std::endl;
// }
   for (int i =0; i < temp.size(); i++){
    random_numb.push_back(stoi(temp[i]));
   }

   

   std::list <std::vector <int>> list_vec;
 
   list_vec.push_back(random_numb);
   std::list<std::vector<int>>::iterator list_it;

   std::vector<int>::iterator vec_it;
//  for (list_it = list_vec.begin(); list_it != list_vec.end(); 
//          ++ list_it)
//  {

//      for (vec_it = list_it->begin(); vec_it != list_it->end(); ++ vec_it)
//      {
//          //do something with vec_it
//          //for example call member function of Class
//          std::cout << *vec_it << std::endl;
//      }
//  } 
    

   std::vector <BingoBoard> examples; 


   while(std::getline(newfile, candidate)) {  //read data from file object and put it into string.
       


        //std::vector <std::vector <int>> board ( 5 , std::vector<int>(5,0));
        BingoBoard biboard;
      
        //std::cout << "board before process" << candidate << std::endl;
        if (candidate.empty()){

            for (int i = 0; i < 5; i++){
            std::getline(newfile, candidate);

            std::istringstream split(candidate);
            std::string each;
          
            std::vector <std::string> rows;
            //for (std::string each; std::getline(split, each, ' '); rows.push_back(each));
            
            int matrix_element;

          for (int j =0; j <5; j++){
           //biboard.board[i][j] = std::stoi(rows[j]) ;
           
           split >> matrix_element;
           biboard.board[j][i] = matrix_element;
           biboard.board_transposed[i][j] = matrix_element;
          }
          }
        }else{

        std::cout << "something unexpected happened" << std::endl;
        }
       
       for (int  i= 0; i <5; i++){
       biboard.lines.push_back(biboard.board[i]);
       biboard.lines.push_back(biboard.board_transposed[i]);
       }
   
      examples.push_back(biboard);
   }
   



   bool fin = false;

   for (int i = 0; i < random_numb.size(); i ++){
       std::cout << "random_numb:" << random_numb[i] << std::endl;
       for(int k = 0; k < examples.size(); k ++){
       for(int j = 0; j <5; j++){
       examples[k].board[j].erase(std::remove(examples[k].board[j].begin(), examples[k].board[j].end(),random_numb[i]), examples[k].board[j].end());
       examples[k].board_transposed[j].erase(std::remove(examples[k].board_transposed[j].begin(), examples[k].board_transposed[j].end(),random_numb[i]), examples[k].board_transposed[j].end());

       if (examples[k].board[j].size() == 0 || examples[k].board_transposed[j].size() == 0 ){
       std::cout << "number for correct board is: " << k << std::endl;
       std::cout << "corect last bingo number is: " << random_numb[i] << std::endl;
       
           result = 0;
       for (int l =0; l <5; l++){
       for (int m = 0; m < examples[k].board[l].size() ; m++ ){
           result += examples[k].board[l][m];
           std::cout << "remaining number on board: " <<examples[k].board[l][m] << std::endl;
       }
       }
       end_result = result*random_numb[i];
   
       if (examples[k].done == false){
       examples[k].first_done = i;
       examples[k].done = true;
       examples[k].result = end_result;
       }


       std::cout << "end_result: " << end_result << std::endl;
       
       fin = true;
       break;
       }
 
       }
       }
   }

   int last=0;
   int rem=0;
   for (int k = 0; k < examples.size(); k++){
   if (examples[k].first_done > rem){
      rem = examples[k].first_done;
      last = k;
   }
   }

   std::cout << "last board" << examples[last].result << std::endl;
   newfile.close();   //close the file object.
return 0;
}
