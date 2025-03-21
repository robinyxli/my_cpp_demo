#include <string>
#ifndef NOVEL_HPP
#define NOVEL_HPP

#include <iostream>
#include <vector>

class Novel {

private:  
  std::string title;
  std::string author;
  std::string status;
  static std::vector<Novel*> instances;

public:

  // Constructors
  Novel(std::string book_title, std::string book_author);
  
  std::string get_title();
  
  virtual std::string get_author() const;

  void set_status(std::string s){
    status = s;
  }
  std::string get_status();

  static void printInstances();

};
#endif // NOVEL_HPP