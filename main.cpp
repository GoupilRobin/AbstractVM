//
// Avm.cpp for avm in /home/chirou_t//tek2/projets/c++/abstract/AbstractVM
// 
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
// 
// Started on  Wed Feb 13 14:52:06 2013 thomas chiroussot-chambeaux
// Last update Tue Feb 19 19:00:29 2013 thomas chiroussot-chambeaux
//

#include <iostream>
#include <fstream>
#include <string>
#include "Parse.hpp"

void	my_parse(std::istream *is)
{
  std::string ligne;
  std::list<std::string> list;
  std::list<std::string> toto;
  Parse	parsed;

  while (!(*is).eof() && ligne.compare(";;"))
    {
      std::getline((*is), ligne);

      list.push_back(ligne);
    }
  parsed.setList(list);
  toto = parsed.getList();
  std::cout << "the content of the list is : " << std::endl;
  for(std::list<std::string>::iterator it = toto.begin(); it != toto.end(); it++)
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
