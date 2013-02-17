//
// Abstract.hpp for Abstract in /home/chirou_t//tek2/projets/c++/TP_abstract
//
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
//
// Started on  Mon Feb 11 15:18:07 2013 thomas chiroussot-chambeaux
// Last update Sun Feb 17 12:33:30 2013 robin goupil
//

#ifndef __ABSTRACT__
# define __ABSTRACT__

# include <cstdlib>
# include <string>
# include <stack>
# include "IOperand.hpp"
# include "Operand.hpp"

typedef	std::stack<IOperand *> opStack;

class	Abstract
{
private:
  typedef IOperand *(Abstract::*funcPtr)(const std::string &);

private:
  funcPtr		_funcList[5];
  opStack		_stack;

private:
  IOperand		*createInt8(const std::string &value);
  IOperand		*createInt16(const std::string &value);
  IOperand		*createInt32(const std::string &value);
  IOperand		*createFloat(const std::string &value);
  IOperand		*createDouble(const std::string &value);

public:
  Abstract();
  ~Abstract() {}

  IOperand		*createOperand(eOperandType type, const std::string &value);
  void			push(IOperand *iop);
  void			pop();
  IOperand		*dump();

  IOperand		*add();
  IOperand		*sub();
  IOperand		*mul();
  IOperand		*div();
  IOperand		*mod();
};

#endif
