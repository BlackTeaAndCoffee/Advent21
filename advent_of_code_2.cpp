#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main(){

   int increased = 0;
   std::fstream newfile;
   newfile.open("input_2.txt"); //open a file to perform read operation using file object
   

   if (newfile.is_open()){   //checking whether the file is open
      long int depth {0};
      long int forward {0};
      long int endval {0};
      long int aim {0};

      std::string candidate;

      while(std::getline(newfile, candidate)) {  //read data from file object and put it into string.
         
         char split_char = ' ';

         // work
         std::istringstream split(candidate);
         std::vector<std::string> tokens;
         for (std::string each; std::getline(split, each, split_char); tokens.push_back(each));
            

         if(tokens.at(0) == "up"){
            aim -= std::stoi(tokens.at(1));}
         else if(tokens.at(0) == "down"){
            aim += std::stoi(tokens.at(1));}
         else if (tokens.at(0) == "forward"){ 
            forward += std::stoi(tokens.at(1));
            depth += aim*std::stoi(tokens.at(1));
            }

         else {
            std::cout << "Out of cases!" << std::endl;
         }

    } 
      newfile.close();   //close the file object.
  
      endval = depth*forward;
   
      std::cout << "Product of integers: " << endval << std::endl;
   }
return 0;
}
