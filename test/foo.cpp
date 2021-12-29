#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>    // std::remove_if
#include <list>
#include <set>
class Binary{
public:
std::string blabla;
int mad; 
};

bool isZero(Binary k){
return (k.mad == 0);
}

int main(){
    std::list<std::string> listOfStrs =
    { "First", "Sec", "Third", "Fourth", "Fifth", "Sixth" };
    

    std::set <int> s2 = {1,2,3,4};

    std::set <int> s1 = {2,3,4,5};
std::set<int> result;
std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
    std::inserter(result, result.end()));


    std::set<int>::iterator it;



    for (it = result.begin() ; it != result.end(); ++it){
    std::cout << *it << std::endl;
    }
//  std::list<std::string>::iterator it = listOfStrs.begin();
//  std::advance(it, 2);
//  std::cout << "3rd element = " << *it << std::endl;
//  
//  auto it1 = std::next(listOfStrs.begin(), 2);
//  std::cout << "3rd element = " << *it1 << std::endl;

return 0;
}
