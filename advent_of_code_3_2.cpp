#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <algorithm>

class BinaryLine {
    public:
    std::vector <int> binary_num;
    int bit_in = 0;

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

bool isZero(BinaryLine k){
   return (k.bit_in == 0);
}

bool isOne(BinaryLine k){
    return (k.bit_in == 1);
}

int main(){
   bool most_num = true;
   int end_result = 0;
   int gamma_int = 0;
   int epsilon_int = 0;

   
   std::fstream newfile;
   newfile.open("input_3.txt"); //open a file to perform read operation using file object
     

   std::vector <int> temp (12,0);
   
   std::vector <BinaryLine> all_lines;
   std::string candidate;
   while(std::getline(newfile, candidate)) {  //read data from file object and put it into string.
        
        for (int i = 0; i < 12; i++){
            
            temp.at(i) = candidate[i] - '0';

        }
        BinaryLine new_line;
        new_line.binary_num = temp;
        all_lines.push_back(new_line); 
}

   newfile.close();   //close the file object.

   long int half_of_nol_floor {0};
   long int number_of_lines {0};
   long int sum_of_bits {0};
   long int half_of_nol_ceil {0};


   for (int i=0; i < 12; i ++){  //read data from file object and put it into string.
        
        number_of_lines = all_lines.size();
        if (number_of_lines ==0){
        std::cout << "number of_lines  is zero" << std::endl;
        }
        else if (number_of_lines ==1){
        

        std::cout <<  "all_lines" << std::endl;

        for (int i = 0; i < 12; i++){
        std::cout << all_lines.at(0).binary_num.at(i);
        }
        break;
        }

        half_of_nol_floor = floor(number_of_lines/2);
        half_of_nol_ceil = ceil(float(number_of_lines)/2.0);
        sum_of_bits = 0;


        for (int j = 0; j < number_of_lines; j++){
            all_lines[j].bit_in = all_lines[j].binary_num.at(i);
            sum_of_bits += all_lines[j].binary_num.at(i);

        }
         
        if (most_num){
       

        std::cout <<"i: " << i << "number_of_lines: " << number_of_lines<< "all_lines_size(): "<< all_lines.size()<<"half_of_nol_ceil"<< half_of_nol_ceil  << "half_of_nol_floor" << half_of_nol_floor << "sum_of_bits" << sum_of_bits << std::endl;

        if (sum_of_bits == number_of_lines){
            std::cout <<  "yay" << std::endl;
            continue;
        }else if(sum_of_bits == 0) {
            continue;

        }else if ((half_of_nol_ceil == half_of_nol_floor) && (sum_of_bits == half_of_nol_floor)){
              all_lines.erase(std::remove_if(all_lines.begin(), all_lines.end(), isZero),all_lines.end());
               

            std::cout <<  "yay2" << std::endl;
            continue;
        }

        else if(sum_of_bits >= half_of_nol_ceil) {
              all_lines.erase(std::remove_if(all_lines.begin(), all_lines.end(), isZero),all_lines.end());
              std::cout << "size of all _lines: " << all_lines.size() << std::endl;
        } else if (sum_of_bits < half_of_nol_ceil){
              all_lines.erase(std::remove_if(all_lines.begin(), all_lines.end(), isOne), all_lines.end());

              std::cout << "size of all _lines: " << all_lines.size()<< std::endl;
        }
        } else{

        std::cout <<"i: " << i << "number_of_lines: " << number_of_lines<< "all_lines_size(): "<< all_lines.size()<<"half_of_nol_ceil"<< half_of_nol_ceil  << "half_of_nol_floor" << half_of_nol_floor << "sum_of_bits" << sum_of_bits << std::endl;
        if (sum_of_bits == number_of_lines){
            std::cout << "yayy";
            continue;

        }else if (sum_of_bits == 0){
             continue;
        }else if ((half_of_nol_ceil == half_of_nol_floor) && (sum_of_bits == half_of_nol_floor)){
              all_lines.erase(std::remove_if(all_lines.begin(), all_lines.end(), isOne),all_lines.end());
              continue; 
        }

        else if (sum_of_bits >= half_of_nol_ceil) {
              all_lines.erase(std::remove_if(all_lines.begin(), all_lines.end(), isOne),all_lines.end());

              std::cout << "size of all _lines: " << all_lines.size()<< std::endl;
        } else if (sum_of_bits < half_of_nol_ceil){
              all_lines.erase(std::remove_if(all_lines.begin(), all_lines.end(), isZero), all_lines.end());
        
              std::cout << "size of all _lines: " << all_lines.size()<< std::endl;
        }


        }


        for (int m = 0; m < all_lines.size(); m++){
            std::cout << "iteration i:"<< i << ", number_of_lines"<<all_lines.size() << "sum_of_bits" << sum_of_bits<< ",  ";
            for(int l = 0; l < 12; l++){
            std::cout << all_lines.at(m).binary_num[l];
        }}


        }

        for (int i = 0; i < 12; i++){
            std::cout << all_lines.at(0).binary_num[i];
        }
        end_result =binary_to_int(all_lines.at(0).binary_num); 

        std::cout << "result is: " << end_result << std::endl;


return 0;
}
