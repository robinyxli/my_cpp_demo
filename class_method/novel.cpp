#include "novel.hpp"

std::vector<Novel*> Novel::instances;
//Implementation of Constructor
Novel::Novel(std::string book_title, std::string book_author)
  : title(book_title), author(book_author){
    instances.push_back(this);
  }

//Implementation of Methods
std::string Novel::get_title() {
  return title;
}
std::string Novel::get_author() const {
  return author;
}
std::string Novel::get_status() {
  return status;
}
void Novel::printInstances() {
    for (const auto& obj : instances) {
        std::cout << obj->title << ", " 
        << obj->author << ", "
        << obj->status << std::endl;
    }
}