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
    bool done =false;
    int label; 

};

bool isSmallCap(std::string test){

    bool returnval = false; 

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

bool isNotinVec(std::string cand, std::vector<std::string> vec){
for (int m=0; m < vec.size(); m++){
if (cand == vec.at(m)){
return false;
}
}
return true;
}

std::vector<std::string> routes; 


bool func_next_cave(std::vector<Knot> strasse, Knot candidate){

    bool match_bool = false; 
    if (strasse.back().name == "end" || candidate.name == "start"){return false;} 
    
    bool run =true; 
    std::vector<std::string> small_caves;


    int dd = 0; 
    std::string as ="";
    for (int m=0; m < strasse.size(); m++){
    std::string ds = strasse.at(m).name;
    if (isSmallCap(ds)){
        if(isNotinVec(ds,small_caves)){    
        small_caves.push_back(strasse.at(m).name);
        }else{
        dd+=1;;
        }
    }
    ds = as;
    }
         




//  int dd = 0; 
//  for (int l=0; l < strasse.size(); l++){
//  if (candidate.name == strasse.at(l).name){
//   dd +=1;   
//  }
//  }
    
    if (dd >= 2){
        match_bool = true;
    }

    if (match_bool && isSmallCap(candidate.name) ){
    return false;
    }else{
    return true;
    }
}

int main(){
   std::vector<std::vector<Knot>> temp_knot; 

   std::vector<std::vector<Knot>> temp_knot_zwei;
   std::vector<std::vector<Knot>> temp_knot_drei; 
   std::string file_name = "input_12.txt";
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


  for (auto i= caves.begin();  i !=  caves.end(); i++){
      for (auto k = map_knot[*i].next_pos.begin(); k != map_knot[*i].next_pos.end(); k++ ){
            map_knot[*i].next_pos_vec.push_back(*k);
  
  }

  }
  

   

   newfile.close();
   temp_knot.push_back(std::vector<Knot> (1,map_knot["start"]));

   
   bool again = true; 
   std::set<std::string>  wege;

   int total = 0;
   while(again){
      

      int first_size = temp_knot.size();
      for (int k=0; k < temp_knot.size(); k++){

             Knot next_cand = temp_knot.at(k).back();
             if(next_cand.name == "end"){
                  total +=1;
                 //temp_knot_zwei.push_back(temp_knot.at(k));
             }else{
 
             for(int l=0; l < next_cand.next_pos_vec.size(); l++){
             if(func_next_cave(temp_knot.at(k), map_knot[next_cand.next_pos_vec.at(l)])){
                 std::vector<Knot> new_route(temp_knot.at(k));
                 new_route.push_back(map_knot[next_cand.next_pos_vec.at(l)]);
                 temp_knot_zwei.push_back(new_route);
                }         
             }
             }
      }
     



      temp_knot = temp_knot_zwei;

      int second_size = temp_knot.size(); 

      if (second_size == 0){
          again = false;
      }
      
      temp_knot_zwei = temp_knot_drei; 
   }
   for (int k =0; k < temp_knot.size(); k++){
       for(int l=0; l < temp_knot.at(k).size();l++ ){
               std::cout << temp_knot.at(k).at(l).name << "-" ; 
       }
      std::cout << std::endl;
   }
   std::cout << "amount of legit routes is: " << total << std::endl; 
   return 0;
}
