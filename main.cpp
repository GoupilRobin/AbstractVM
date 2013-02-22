//
// Avm.cpp for avm in /home/chirou_t//tek2/projets/c++/abstract/AbstractVM
//
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
//
// Started on  Wed Feb 13 14:52:06 2013 thomas chiroussot-chambeaux
// Last update Fri Feb 22 18:09:42 2013 robin goupil
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
  Exec	e(ac, av);

  e.start();
}
