//
// Exception.hpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Sat Feb 23 16:10:07 2013 robin goupil
// Last update Sat Feb 23 17:46:59 2013 robin goupil
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

#include <iostream>
#include <sstream>
#include <exception>
#include "IOperand.hpp"

class overflowException : public std::exception
{
public:
  overflowException(const double value, const std::string &type_name, const t_operand &op);
  virtual		~overflowException() throw()
  { }

  virtual const char	*what() const throw();

private:
  std::string		_str;
};

class popException : public std::exception
{
public:
  popException();
  virtual		~popException() throw()
  { }

  virtual const char	*what() const throw();

private:
  std::string		_str;
};

class mathException : public std::exception
{
public:
  mathException(const std::string &str);
  virtual		~mathException() throw()
  { }

  virtual const char	*what() const throw();

private:
  std::string		_str;
};

class exitException : public std::exception
{
public:
  exitException();
  virtual		~exitException() throw()
  { }

  virtual const char	*what() const throw();
};

#endif
