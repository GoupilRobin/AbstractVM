//
// Exec.hpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/WORK
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Fri Feb 22 17:33:14 2013 robin goupil
// Last update Fri Feb 22 18:37:22 2013 robin goupil
//

#ifndef EXEC_HPP_
# define EXEC_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <fstream>
#include "Parse.hpp"
#include "IOperand.hpp"
#include "Abstract.hpp"

class Exec
{
public:
  Exec(int ac, char **av);
  ~Exec();

  void			start();

private:
  void			start_parse();
  void			exec_func(std::string func, std::string type, std::string val);

private:
  int			ac;
  char			**av;
  Parse			parse;
  Abstract		abst;
};

#endif
