//
// Avm.cpp for avm in /home/chirou_t//tek2/projets/c++/abstract/AbstractVM
// 
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
// 
// Started on  Wed Feb 13 14:52:06 2013 thomas chiroussot-chambeaux
// Last update Thu Feb 21 19:07:46 2013 thomas chiroussot-chambeaux
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "Parse.hpp"
#include "Operand.hpp"

int	check_line(std::string ligne)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  if (ligne == "pop" || ligne == "dump" || ligne == "add" || ligne == "sub" 
      || ligne == "mul" || ligne == "div" || ligne == "mod" || ligne == "print" 
      || ligne == "exit" || ligne == ";;")
    return 1;
  else if (!strncmp(ligne.c_str(), "push ", 5) || !strncmp(ligne.c_str(), "assert ", 7))
    while (!g_OperandTypeInfo[++i].type_name.empty())
      if (strstr(ligne.c_str(), g_OperandTypeInfo[i].type_name.c_str()) != 0)
	{
	  if (!strncmp(ligne.c_str(), "push ", 5))
	    j = 5 + g_OperandTypeInfo[i].type_name.length();
	  else
	    j = 7 + g_OperandTypeInfo[i].type_name.length();
	  if (ligne.c_str()[j] != '(')
	    return 0;
	  while (isdigit(ligne[++j]));
	  if ((g_OperandTypeInfo[i].type_name == "double" 
	       || g_OperandTypeInfo[i].type_name == "float") && ligne.c_str()[j] == '.')
	    while (isdigit(ligne[++j]));
	  if (ligne.c_str()[j] == ')' && ligne.c_str()[j + 1] == '\0')
	  return 1;
	}
  return 0;
}

void	my_parse(std::istream *is)
{
  std::string ligne;
  std::list<std::string> list;
  int	i;
  Parse	parsed;

  i = 0;
  while (!(*is).eof() && ligne.compare(";;"))
    {
      i++;
      std::getline((*is), ligne);
      if (check_line(ligne))
	list = get_form(ligne, list);
      else
	{
	  std::cout << "Syntax Error : Line " << i << " : " << ligne << std::endl;
	  return;
	}
    }
  parsed.setList(list);
  std::cout << "the content of the list is : " << std::endl;
  for(std::list<std::string>::iterator it = list.begin(); it != list.end(); it++)
    std::cout << *it  << std::endl;
}

int	main(int ac, char **av)
{
  int	i;
  
  i = 1;
  if (ac > 1)
    {
      while (av[i] != NULL)
	{
	  std::filebuf id;
	  if (id.open(av[i], std::ios::in))
	    {
	      std::istream is(&id);
	      my_parse(&is);
	      id.close();
	    }
	  else
	    std::cout << "Error : File does not exist or Permission denied." << std::endl;
	  i++;
	}
    }
  else
    my_parse(&(std::cin));
}
