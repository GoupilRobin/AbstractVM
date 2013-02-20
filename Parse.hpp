//
// Parse.hpp for AVM in /home/chirou_t//tek2/projets/c++/abstract/AbstractVM
// 
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
// 
// Started on  Fri Feb 15 15:29:04 2013 thomas chiroussot-chambeaux
// Last update Tue Feb 19 19:00:25 2013 thomas chiroussot-chambeaux
//

#ifndef __PARSE__

# define __PARSE__

#include <string>
#include <list>

class	Parse
{
private:
  std::list<std::string> _list;

public:
enum func_nb
  {

  };
  Parse();
  ~Parse();
  std::list<std::string> const &getList() const;
  void	setList(std::list<std::string> const & list);
};

#endif
