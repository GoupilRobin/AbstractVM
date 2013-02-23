//
// Exec.cpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/WORK
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Fri Feb 22 17:33:33 2013 robin goupil
// Last update Sat Feb 23 16:49:07 2013 robin goupil
//

#include "Exec.hpp"

Exec::Exec(int pac, char **pav)
{
  ac = pac;
  av = pav;
}

Exec::~Exec()
{ }

void			Exec::start()
{
  std::list<std::string>	list;
  std::string			func;
  std::string			type;
  std::string			val;

  start_parse();

  list = parse.getList();
  for (std::list<std::string>::iterator it = list.begin(); it != list.end(); ++it)
    {
      try
	{
	  func = *it;
	  ++it;
	  type = *it;
	  ++it;
	  val = *it;
	  exec_func(func, type, val);
	}
      catch (const std::exception &e)
	{
	  std::cerr << e.what() << std::endl;
	  abst.exit_func();
	}
    }
}

void			Exec::start_parse()
{
  int	i;

  i = 1;
  if (ac > 1)
    {
      while (av[i] != NULL)
	{
	  std::filebuf id;
	  if (id.open(av[i], std::ios::in))
	    {
	      std::istream is(&id);
	      parse.my_parse(&is);
	      id.close();
	    }
	  else
	    std::cout << "Error : File does not exist or Permission denied." << std::endl;
	  i++;
	}
    }
  else
    parse.my_parse(&(std::cin));
}

void			Exec::exec_func(std::string func, std::string type, std::string val)
{
  eOperandType		iopType = None;
  IOperand		*iop;
  eFuncId		funcId = noneId;

  for (int i = 0; g_funcInfo[i].id != noneId; i++)
    if (g_funcInfo[i].name == func)
      funcId = g_funcInfo[i].id;
  for (int i = 0; g_OperandTypeInfo[i].type != None; i++)
    if (g_OperandTypeInfo[i].type_name == type)
      {
	iopType = g_OperandTypeInfo[i].type;
	break;
      }
  if (iopType != None)
    iop = abst.createOperand(iopType, val);

  switch(funcId)
    {
    case pushId:
      abst.push(iop);
      break;
    case popId:
      abst.pop();
      break;
    case dumpId:
      abst.dump(true);
      break;
    case assertId:
      abst.assert(iop);
      break;
    case addId:
      abst.add();
      break;
    case subId:
      abst.sub();
      break;
    case mulId:
      abst.mul();
      break;
    case divId:
      abst.div();
      break;
    case modId:
      abst.mod();
      break;
    case printId:
      abst.print();
      break;
    case exitId:
      abst.exit_func();
      break;
    default:
      break;
    }
}
