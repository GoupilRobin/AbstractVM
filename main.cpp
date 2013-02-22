//
// Avm.cpp for avm in /home/chirou_t//tek2/projets/c++/abstract/AbstractVM
// 
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
// 
// Started on  Wed Feb 13 14:52:06 2013 thomas chiroussot-chambeaux
// Last update Fri Feb 22 17:45:39 2013 thomas chiroussot-chambeaux
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "Parse.hpp"
#include "Operand.hpp"

int	main(int ac, char **av)
{
  int	i;
  Parse p;
  i = 1;
  if (ac > 1)
    {
      while (av[i] != NULL)
	{
	  std::filebuf id;
	  if (id.open(av[i], std::ios::in))
	    {
	      std::istream is(&id);
	      p.my_parse(&is);

	      id.close();
	    }
	  else
	    std::cout << "Error : File does not exist or Permission denied." << std::endl;
	  i++;
	}
    }
  else
    {
      p.my_parse(&(std::cin));

    }
}
