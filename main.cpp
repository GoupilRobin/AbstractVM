//
// main.cpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Wed Feb 13 10:47:40 2013 robin goupil
// Last update Sun Feb 17 13:11:16 2013 robin goupil
//

#include <iostream>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Abstract.hpp"

int		main(int ac, char **av)
{
  (void) ac;
  (void) av;
  Abstract	a;
  IOperand	*op1 = a.createOperand(Int8, "2");
  IOperand	*op2 = a.createOperand(Int8, "2");
  IOperand	*op3 = a.createOperand(Int8, "5");

  a.push(op1);
  a.push(op2);
  a.push(op3);
  a.push(a.createOperand(Int8, "120"));

  std::cout << "Result add:" << *(a.add()) << std::endl;
  std::cout << "Result add:" << *(a.add()) << std::endl;
  std::cout << "Result add:" << *(a.add()) << std::endl;

  return (0);
}
