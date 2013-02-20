//
// Parse.cpp for avm in /home/chirou_t//tek2/projets/c++/abstract/AbstractVM
// 
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
// 
// Started on  Fri Feb 15 15:54:05 2013 thomas chiroussot-chambeaux
// Last update Fri Feb 15 16:01:33 2013 thomas chiroussot-chambeaux
//

#include <iostream>
#include "Parse.hpp"

Parse::Parse()
{
  this->_list.clear();
}

Parse::~Parse()
{

}

std::list<std::string> const & Parse::getList() const
{
  return (this->_list);
}

void	Parse::setList(std::list<std::string> const &list)
{
  this->_list = list;
}
