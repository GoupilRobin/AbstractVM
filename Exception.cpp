//
// Exception.cpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Sat Feb 23 16:19:09 2013 robin goupil
// Last update Sat Feb 23 17:47:34 2013 robin goupil
//

#include "Exception.hpp"

overflowException::overflowException(const double value, const std::string &type_name, const t_operand &op)
{
  std::ostringstream	oss;

  oss << "Error: Value (" << value << ") overflow the type " << type_name << " (min=" << op.min_size << " - max=" << op.max_size << ").";
  _str = oss.str();
}

const char			*overflowException::what() const throw()
{
  return (_str.c_str());
}

popException::popException()
{
  std::ostringstream	oss;

  oss << "Error: Pop on empty stack.";
  _str = oss.str();
}

const char			*popException::what() const throw()
{
  return (_str.c_str());
}

mathException::mathException(const std::string &str)
{
  _str = str;
}

const char			*mathException::what() const throw()
{
  return (_str.c_str());
}

exitException::exitException()
{ }

const char			*exitException::what() const throw()
{
  return ("exit");
}
