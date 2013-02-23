//
// Avm.cpp for avm in /home/chirou_t//tek2/projets/c++/abstract/AbstractVM
//
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
//
// Started on  Wed Feb 13 14:52:06 2013 thomas chiroussot-chambeaux
// Last update Sat Feb 23 18:27:20 2013 robin goupil
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "Parse.hpp"
#include "Operand.hpp"
#include "Exec.hpp"

int	main(int ac, char **av)
{
  bool	keepStack;
  Exec	e(ac, av);
  int	i;

  if (ac > 1)
    {
      keepStack = false;
      for (i = 1; i < ac && !keepStack; i++)
	if (strcmp(av[i], "--keep") == 0)
	  keepStack = true;
      if (keepStack)
	e.start(1, i - 1, true);
      else
	e.start();
    }
}
