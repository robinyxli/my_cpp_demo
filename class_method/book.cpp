#include <iostream>
#include "novel.hpp"
#include "JaneAusten.hpp"
int main() {
  //Create a novel object
  Novel gone_with_the_wind("Gone with the Wind", "Margaret Mitchell");
  std::cout << "Enter Current Reading Status for " << gone_with_the_wind.get_title() << ":\n";
  std::string s;
  std::cin >> s;
  gone_with_the_wind.set_status(s);

  //std::cout << gone_with_the_wind.get_status() << "\n";
  
  Novel::printInstances();

  //Create a Jane Austen object
  JaneAusten emma("Emma");
  
  //Call the methods and print the results
  //std::cout << emma.get_title() << "\n";
  //std::cout << emma.get_author() << "\n";

  std::cout << "Enter Current Reading Status for " << emma.get_title() << ":\n";
  std::cin >> s;
  emma.set_status(s);

  //Call the methods and print the results
  //std::cout << emma.get_status() << "\n";

  JaneAusten::printInstances();

  return 0;
}