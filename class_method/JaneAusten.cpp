#include "JaneAusten.hpp"

JaneAusten::JaneAusten(std::string book_title)
:Novel(book_title, "Jane Austen") {}

std::string JaneAusten::get_author() const {
    return "Jane Austen";
}

