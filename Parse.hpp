//
// Parse.hpp for AVM in /home/chirou_t//tek2/projets/c++/abstract/AbstractVM
// 
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
// 
// Started on  Fri Feb 15 15:29:04 2013 thomas chiroussot-chambeaux
// Last update Thu Feb 21 16:03:50 2013 thomas chiroussot-chambeaux
//

#ifndef __PARSE__

# define __PARSE__

#include <string>
#include <list>
#include "Call.h"

class	Parse
{
private:
  std::list<std::string> _list;
  func_list _struct;
public:
  Parse();
  ~Parse();
  std::list<std::string> const &getList() const;
  void	setList(std::list<std::string> const & list);
};

std::list<std::string>  get_form(std::string ligne, std::list<std::string> list);
void    my_parse(std::istream *is);

#endif
