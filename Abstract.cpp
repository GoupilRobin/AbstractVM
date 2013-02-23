//
// Abstract.cpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/WORK
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Thu Feb 14 20:56:14 2013 robin goupil
// Last update Sat Feb 23 18:09:27 2013 robin goupil
//

#include "Abstract.hpp"

Abstract::Abstract()
{
  _stack.clear();
  _funcList[0] = &Abstract::createInt8;
  _funcList[1] = &Abstract::createInt16;
  _funcList[2] = &Abstract::createInt32;
  _funcList[3] = &Abstract::createFloat;
  _funcList[4] = &Abstract::createDouble;
}

Abstract::~Abstract()
{
  _stack.clear();
}

IOperand		*Abstract::createInt8(const std::string &value)
{
  IOperand		*out;

  out = new Operand<char>(Int8, atof(value.c_str()));
  return (out);
}

IOperand		*Abstract::createInt16(const std::string &value)
{
  IOperand		*out;

  out = new Operand<short>(Int16, atof(value.c_str()));
  return (out);
}

IOperand		*Abstract::createInt32(const std::string &value)
{
  IOperand		*out;

  out = new Operand<int>(Int32, atof(value.c_str()));
  return (out);
}

IOperand		*Abstract::createFloat(const std::string &value)
{
  IOperand		*out;

  out = new Operand<float>(Float, atof(value.c_str()));
  return (out);
}

IOperand		*Abstract::createDouble(const std::string &value)
{
  IOperand		*out;

  out = new Operand<double>(Double, atof(value.c_str()));
  return (out);
}

IOperand		*Abstract::createOperand(eOperandType type, const std::string &value)
{
  return ((this->*_funcList[type])(value));
}

void			Abstract::push(IOperand *iop)
{
  _stack.push_back(iop);
}

void			Abstract::pop()
{
  if (_stack.size() <= 0)
    throw popException();
  _stack.pop_back();
}

IOperand		*Abstract::dump(bool print)
{
  if (_stack.size() <= 0)
    return (NULL);
  if (print)
    for (opStack::reverse_iterator it = _stack.rbegin(); it != _stack.rend(); ++it)
      std::cout << **it << std::endl;
  return (_stack.back());
}

IOperand		*Abstract::add()
{
  IOperand		*a = dump();
  pop();
  IOperand		*b = dump();
  pop();

  push(*a + *b);
  return (dump());
}

IOperand		*Abstract::sub()
{
  IOperand		*a = dump();
  pop();
  IOperand		*b = dump();
  pop();

  push(*a - *b);
  return (dump());
}

IOperand		*Abstract::mul()
{
  IOperand		*a = dump();
  pop();
  IOperand		*b = dump();
  pop();

  push(*a * *b);
  return (dump());
}

IOperand		*Abstract::div()
{
  IOperand		*a = dump();
  pop();
  IOperand		*b = dump();
  pop();

  push(*a / *b);
  return (dump());
}

IOperand		*Abstract::mod()
{
  IOperand		*a = dump();
  pop();
  IOperand		*b = dump();
  pop();

  push(*a % *b);
  return (dump());
}

void			Abstract::exit_func()
{
  throw exitException();
}

void			Abstract::assert(IOperand *iop)
{
  if (dump()->toString() != iop->toString() || dump()->getType() != iop->getType())
    {
      std::cout << "Asert failed" << std::endl;
      exit_func();
    }
}

void			Abstract::print()
{
  if (dump()->getType() == Int8)
    std::cout << static_cast<Operand<char> *>(dump())->getValue() << std::endl;
  else
    {
      std::cout << "Print failed" << std::endl;
      exit_func();
    }
}
