//
// parseur_ll.cpp for avm in /home/chirou_t//tek2/projets/c++/abstract/AbstractVM
// 
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
// 
// Started on  Wed Feb 20 19:17:08 2013 thomas chiroussot-chambeaux
// Last update Thu Feb 21 19:06:39 2013 thomas chiroussot-chambeaux
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "Parse.hpp"
#include "Operand.hpp"

std::list<std::string>	get_form(std::string ligne, std::list<std::string> list)
{
  int	i;
  int	flag;
  std::string new_string;

  i = -1;
  flag = 0;
  while (ligne.c_str()[++i])
    {
      if (ligne.c_str()[i] == ' ' || ligne.c_str()[i] == '(' || ligne.c_str()[i] == ')')
	{
	  flag++;
	  i++;
	  list.push_back(new_string);
	  new_string.clear();
	}
      new_string += ligne.c_str()[i];
    }
  if (flag == 0)
    {
      list.push_back(new_string);
      list.push_back("empty");
      list.push_back("empty");
    }
  return list;
}

