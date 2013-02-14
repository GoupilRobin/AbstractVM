//
// main.cpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Wed Feb 13 10:47:40 2013 robin goupil
// Last update Thu Feb 14 19:31:49 2013 robin goupil
//

#include <iostream>
#include "IOperand.hpp"
#include "Operand.hpp"

int		main(int ac, char **av)
{
  Operand		a(Int8, 100.3);
  Operand		b(Double, 127);
  IOperand		*res;

  (void) ac;
  (void) av;
  res = (a + b);
  std::cout << "(dynamic) a + b = " << *(a + b) << std::endl;
  std::cout << "(stored) a + b = " << *res << std::endl;
  std::cout << "(dynamic) x + y = " << *(Operand(Int8, 1) + Operand(Float, 3.14)) << std::endl;
  return (0);
}
