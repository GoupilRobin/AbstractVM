/*
** Call.h for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
**
** Made by robin goupil
** Login   <goupil_r@epitech.net>
**
** Started on  Wed Feb 20 10:56:34 2013 robin goupil
** Last update Fri Feb 22 17:51:30 2013 thomas chiroussot-chambeaux
*/

#ifndef CALL_H_
# define CALL_H_

#include <list>
#include "IOperand.hpp"

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
    exitId
  };

typedef struct s_func
{
  eFuncId	id;
  IOperand	*param;
} t_func;

typedef std::list<t_func *> func_list;

#endif
