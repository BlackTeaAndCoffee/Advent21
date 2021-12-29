#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <list>

class Boards {
    public:
    std::vector <std::vector <int>> board {5 , std::vector<int>(5, 5)};
    int first_done;
    bool done  = false;
    long int result;
    std::vector <std::vector <int>> board_transposed {5 , std::vector<int>(5, 5)};
    std::list <std::vector<int>> lines;

};

class Routes {
    public:
    std::vector <int> x_route;
    std::vector <int> y_route;
    bool horiz_or_vert = false;
    Routes (float x_1,float y_1,float x_2, float y_2){
        int x_begin = int(x_1);
        int x_end = int(x_2);
        
        //std::cout   << "at the top"<< x_begin<< x_end << std::endl;
        if(x_1 != x_2){  
        
            float m=0;
            float t = 0; 
            m = (y_2 - y_1)/(x_2 - x_1);
            t = y_1 - m*x_1;
             
//          std::cout << "m: " << int(m) << std::endl;
            if (m == 0.0 || m == -0.0){
//            std::cout << "hori_vert" << horiz_or_vert << std::endl;
            horiz_or_vert = true;
            }


            float y;
            if (x_1 < x_2){
                for (int x = x_begin; x <= x_end; x++){
                    x_route.push_back(x);
                    y = m*x + t;
                    y_route.push_back(int(y));
                }
            }else if(x_1 > x_2){
                for (int x = int(x_2); x <= int(x_1); x++){
                   x_route.push_back(x);
                    y = m*x + t;
                    y_route.push_back(int(y));
                }
            }
//      for (int i =0; i < x_route.size();  i++){
//      std::cout << "x: " << x_route[i] << "y: " << y_route[i] << std::endl;
//      }
        }else if (x_1 == x_2){
//          std::cout << "x_1 === x_2" << x_1 << x_2 << std::endl;
            horiz_or_vert = true;
            int y_begin = int(y_1);
            int y_end = int(y_2);
            
            if (y_1 < y_2){
                for (int y = y_begin; y <= y_end; y++){
                    x_route.push_back(x_begin);
                    y_route.push_back(y);
                }
            }else if(y_1 > y_2){
                for (int y = y_end; y <= y_begin; y++){
                    x_route.push_back(x_begin);
                    y_route.push_back(y);
                }

            }
        }
      }
};


int main(){
   std::fstream newfile;
   newfile.open("input_5.txt");
   int diag_max = 1000;   

   std::vector <Routes> vec_of_routes;
   std::string candidate;

   std::vector <std::vector <int>> board (diag_max, std::vector <int> (diag_max,0)); 
   

   while(std::getline(newfile, candidate)) {  //read data from file object and put it into string.
   std::istringstream split(candidate);
   
   std::vector <std::string> temp;
   for (std::string each; std::getline(split, each, ' '); temp.push_back(each));
   std::istringstream mfirst(temp[0]);

   std::istringstream msecond(temp[2]);
   std::vector <int> first_spot;

   std::vector <int> second_spot;
   for (std::string each; std::getline(mfirst, each, ','); first_spot.push_back(std::stoi(each)));

   for (std::string each; std::getline(msecond, each, ','); second_spot.push_back(std::stoi(each)));
   
   Routes routes(first_spot[0], first_spot[1], second_spot[0], second_spot[1]);
   vec_of_routes.push_back(routes);
   }
   
//  for (int i=0; i < vec_of_routes[0].x_route.size(); i++){
//  std::cout << "x:" << vec_of_routes[0].x_route[i] << std::endl;
// }
   
   for (int k = 0; k < vec_of_routes.size(); k++){
       for (int l = 0; l < vec_of_routes[k].x_route.size();l++){
           //if (vec_of_routes[k].horiz_or_vert){ 
           //std::cout << "here "<< vec_of_routes[k].y_route[l] << vec_of_routes[k].y_route[l] << std::endl;
           board.at(vec_of_routes[k].y_route[l]).at(vec_of_routes[k].x_route[l]) += 1;
       //}
       }
   }
   
   int summation = 0;

   for (int i=0; i <diag_max; i++){

       for (int k=0; k <diag_max; k++){

           std::cout <<  board[i][k];
           if (board[i][k] >=2){
                summation +=1;
           }
       }
       std::cout << ";" << std::endl;
   }
   std::cout << "summation: " << summation << std::endl;
newfile.close(); 
return 0;
}
