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


class Knot {
    public:
    std::string name;
    std::set<std::string> next_pos;
    std::vector<std::string> next_pos_vec;
    int label; 

};

bool isSmallCap(std::string test){

    bool returnval = false; :q


    std::vector<std::string> match_str {"a", "b", "c", "d", "e", "f", "g", "h", "i","j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    for (int i=0; i < match_str.size(); i++){
    std::string buchstabe = ""; 

    buchstabe += test.at(0); 
    if (match_str.at(i) == buchstabe){
    returnval = true;
    }
    }

    return returnval;

}
std::vector<Knot> temp_knot; 


std::vector<std::string> routes; 


int func_next_cave(Knot cand,   std::map<std::string, Knot> map_knot){

    bool match_bool = false; 
 
    
    for (int l=0; l < temp_knot.size(); l++){
    std::cout << "temp_knot: " << temp_knot.at(l).name << std::endl; 
    if (cand.name == temp_knot.at(l).name){
    match_bool = true;
    }
    }

    temp_knot.push_back(cand);

    if ((match_bool && isSmallCap(cand.name)) || (cand.name == "end") ){
    if (cand.name == "end"){
    std::string route_string = ""; 

    for (int k =0; k < temp_knot.size(); k++){

    route_string += temp_knot.at(k).name + "-";
    }
    routes.push_back(route_string);

    }


    int index_of_cand = temp_knot.size() - 1; 
     
      
    for (int k =0; k < temp_knot.size(); k++){
     std::cout << "temp_knot_vor: " << temp_knot.at(k).name << std::endl; 
    }
   

    temp_knot.erase(temp_knot.begin() + index_of_cand);

    for (int k =0; k < temp_knot.size(); k++){

     std::cout << "temp_knot_nach: " << temp_knot.at(k).name << std::endl; 
    }

    return 0;

    }else{

    for (int k =0; k < cand.next_pos_vec.size(); k++){
    
    std::cout << cand.name << " , cand_next_pos: " << cand.next_pos_vec.at(k) << std::endl;
    func_next_cave(map_knot[cand.next_pos_vec.at(k)], map_knot);

    }
    }

    return 0;
}

int main(){

   std::string file_name = "input_12_test.txt";
   std::fstream newfile;
   newfile.open(file_name);
   

   std::string candidate;
   std::vector<std::vector <std::string>> connections;
   std::vector<std::string> verteilung; 

   
   std::set<std::string> caves; 
   std::vector<std::string> pair; 

   std::vector<Knot> knot_vector; 

   std::map<std::string, Knot> map_knot; 
    
   while(std::getline(newfile, candidate)){
      std::istringstream split(candidate); 
      for(std::string each; std::getline(split, each, '-'); verteilung.push_back(each));

   }
   
   for (int i =0; i < verteilung.size(); i++){
       caves.insert(verteilung.at(i)); 
       
   } 

   for (int i =0; i < verteilung.size()/2; i++){

         pair =  {verteilung.at(2*i),verteilung.at(2*i +1)};
         connections.push_back(pair); 
       
   } 

   for (auto i = caves.begin(); i != caves.end(); i++){
       Knot knoten; 
       knoten.name = *i;
       map_knot.insert({*i, knoten});

   } 
  
     for (int k =0; k < connections.size(); k++){

        map_knot[connections.at(k).at(0)].next_pos.insert(connections.at(k).at(1));
      
        map_knot[connections.at(k).at(1)].next_pos.insert(connections.at(k).at(0));
     }

 
  for (auto i = map_knot["start"].next_pos.begin(); i != map_knot["start"].next_pos.end(); i++){
      std::cout << *i << " " << std::endl;

  }
  

  for (auto i= caves.begin();  i !=  caves.end(); i++){
      for (auto k = map_knot[*i].next_pos.begin(); k != map_knot[*i].next_pos.end(); k++ ){
            map_knot[*i].next_pos_vec.push_back(*k);
  
  }

  }
  

   

   newfile.close();
   func_next_cave(map_knot["start"], map_knot);   
   
   for (int m=0; m < routes.size(); m++){
   std::cout<< routes.at(m) << std::endl;
   }

   return 0;
}
