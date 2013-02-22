//
// Abstract.hpp for Abstract in /home/chirou_t//tek2/projets/c++/TP_abstract
//
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
//
// Started on  Mon Feb 11 15:18:07 2013 thomas chiroussot-chambeaux
// Last update Fri Feb 22 18:52:17 2013 robin goupil
//

#ifndef __ABSTRACT__
# define __ABSTRACT__

# include <iostream>
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
  IOperand		*dump(bool print = false);

  IOperand		*add();
  IOperand		*sub();
  IOperand		*mul();
  IOperand		*div();
  IOperand		*mod();
};

enum eFuncId
  {
    pushId = 0,
    popId,
    dumpId,
    assertId,
    addId,
    subId,
    mulId,
    divId,
    modId,
    printId,
    exitId,
    noneId,
  };

typedef struct s_funcInfo
{
  eFuncId	id;
  std::string	name;
} t_funcInfo;

static t_funcInfo	g_funcInfo[] =
  {
    {pushId, "push"},
    {popId, "pop"},
    {dumpId, "dump"},
    {assertId, "assert"},
    {addId, "add"},
    {subId, "sub"},
    {mulId, "mul"},
    {divId, "div"},
    {modId, "mod"},
    {printId, "print"},
    {exitId, "exit"},
    {noneId, ""}
  };

#endif
