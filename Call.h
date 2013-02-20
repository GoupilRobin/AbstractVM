/*
** Call.h for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
**
** Made by robin goupil
** Login   <goupil_r@epitech.net>
**
** Started on  Wed Feb 20 10:56:34 2013 robin goupil
** Last update Wed Feb 20 11:03:47 2013 robin goupil
*/

#ifndef CALL_H_
# define CALL_H_

#include <list>
#include "IOperand.h"

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
  eFuncId		id;
  list<IOperand *>	param;
} t_func;

#endif
