//
// Operand.cpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/WORK
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Thu Feb 14 19:13:12 2013 robin goupil
// Last update Sat Feb 16 13:58:39 2013 robin goupil
//

#include "Operand.hpp"

std::ostream		&operator<< (std::ostream &os, IOperand const &iop)
{
  os << iop.toString();
  return (os);
}
