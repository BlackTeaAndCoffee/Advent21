#include <iostream>
#include <fstream>
#include <string>
int main(){

   int increased = 0;
   std::fstream newfile;
   newfile.open("input_1.txt"); //open a file to perform read operation using file object
   

   if (newfile.is_open()){   //checking whether the file is open
      std::string first;
      std::string second;
      std::string third;
      std::string fourth;

      std::getline(newfile, first);
      std::getline(newfile, second);
      std::getline(newfile, third);


      while(std::getline(newfile, fourth)) {  //read data from file object and put it into string.
         
         int first_int = std::stoi(first);
         int second_int = std::stoi(second);
         int third_int = std::stoi(third);
         int fourth_int  = std::stoi(fourth);
         
         int first_sum = first_int + second_int + third_int; 
         int second_sum = second_int + third_int + fourth_int; 


         if (second_sum > first_sum){
         increased += 1;
         std::cout << increased << std::endl;
         }
         first = second;
         second = third; 
         third = fourth; 

    } 
      newfile.close();   //close the file object.
   }
return increased;
}
