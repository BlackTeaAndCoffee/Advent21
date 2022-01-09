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

bool isin_vec(std::string cand, std::vector<std::string> vec){
bool return_val = false; 

for(int k=0; k < vec.size(); k++){

if (cand == vec[k]){
return_val = true; 
}
}
return return_val;
}
bool isinstring(std::string cand, std::string str){
bool return_val = false; 

for(int k=0; k < str.size(); k++){

std::string s = ""; 
s+= str[k]; 
if (cand == s){
return_val = true; 
}
}
return return_val;
}



std::string convert_to_string(char a){
 std::string s = ""; 
 s += a; 

 return s; 
}

int main(){
   std::vector <long int> complete_score; 

   std::fstream newfile;
   newfile.open("input_10.txt");
   
   std::string candidate;

   long int sum = 0;

   
 std::string round = ")";
 std::string pointy = "]";
 std::string curvy = "}";
 std::string bracket = ">";


 std::string round_open = "(";
 std::string pointy_open = "[";
 std::string curvy_open = "{";
 std::string bracket_open = "<";

   std::vector<std::string> brackets {"()", "[]", "<>", "{}"};
   std::vector<std::string> false_match {"(]", "[)", "<)", "(>", "(}","{)", "[>", "<]", "[}", "{]", "<}","{>"};

   while(std::getline(newfile, candidate)){
   bool still_looking = true; 
   while(still_looking){ 
   for (int i =0; i < (candidate.size() - 1); i++){
    std::string  first = convert_to_string(candidate[i]); 
    std::string second  = convert_to_string(candidate[i+1]);


    std::string what_is = ""; 
    what_is += first;
    what_is += second;

    std::cout << candidate << std::endl;
    if (isin_vec(what_is, brackets)){
        candidate.erase(i, 2);
        break;
    } else if (isin_vec(what_is, false_match)) {
        still_looking = false; 
        if(second == round){
          sum += 3; 
        }else if(second == pointy) {
  
          sum += 57; 

        } else if( second == curvy){
          sum += 1197;
        }else if( second == bracket){

          sum += 25137; 
        }
        break;
    } else if (!isinstring(round, candidate) && !isinstring(curvy, candidate) && !isinstring(pointy, candidate) && !isinstring(bracket, candidate)){
      long int second_sum = 0;


      for (int m =(candidate.size() - 1); m >= 0; m--){
      
      std::string s =""; 
      s+= candidate[m]; 
      if (s == round_open){
          second_sum = 5*second_sum + 1;
      } else if (s == pointy_open){
          second_sum = 5*second_sum + 2;
      } else if (s == curvy_open){
          second_sum = 5*second_sum + 3;
      } else if (s == bracket_open){
          second_sum = 5*second_sum + 4;
      }

      }
      
//      std::cout << "second_sum "  << s<<  std::endl;
      complete_score.push_back(second_sum);
      still_looking =false;
      break;

   }
   }


   }

   }

   sort(complete_score.begin(), complete_score.end());
    
   float comp_size = complete_score.size();
   int middle_index = ceil(comp_size/2);

   for (int i = 0; i < complete_score.size(); i ++){
       std::cout << complete_score[i] << std::endl;
   }
   std::cout << "middle is" << complete_score[middle_index -1 ] << std::endl;
   std::cout << "sum is: " << sum << std::endl;
   newfile.close(); 
return 0;
}
