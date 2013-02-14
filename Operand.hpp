//
// Operand.hpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Wed Feb 13 13:52:55 2013 robin goupil
// Last update Thu Feb 14 19:26:03 2013 robin goupil
//

#ifndef TOPERAND_HPP_
# define TOPERAND_HPP_

# include <iostream>
# include <cstdlib>
# include <string>
# include "IOperand.hpp"

class Operand : public IOperand
{
private:
  eOperandType			_type;
  std::string			_type_name;
  int				_precision;
  double			_value;

public:
  explicit Operand(eOperandType type, const double &value);

  ~Operand() {}

  virtual void			castValue(const double &value);

  virtual std::string const	&toString() const; // Return string representation
  virtual int			getPrecision() const; // Return precision
  virtual eOperandType		getType() const; // Return type
  virtual double		getValue() const; // Return value

  virtual IOperand		*operator+(const IOperand &iop) const; // add
  virtual IOperand		*operator-(const IOperand &iop) const; // sub
  virtual IOperand		*operator*(const IOperand &iop) const; // mul
  virtual IOperand		*operator/(const IOperand &iop) const; // div
  virtual IOperand		*operator%(const IOperand &iop) const; // mod
};

std::ostream		&operator<< (std::ostream &os, IOperand const &iop);

#endif
