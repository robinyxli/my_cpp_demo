#include "novel.hpp"
#ifndef JANEAUSTEN_HPP
#define JANEAUSTEN_HPP

class JaneAusten: public Novel {
public:
JaneAusten(std::string book_title);
std::string get_author() const override;
};
#endif // JANEAUSTEN_HPP

