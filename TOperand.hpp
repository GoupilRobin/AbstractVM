//
// TOperand.hpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Wed Feb 13 13:52:55 2013 robin goupil
// Last update Wed Feb 13 14:41:22 2013 robin goupil
//

#ifndef TOPERAND_HPP_
# define TOPERAND_HPP_

# include <string>
# include "IOperand.hpp"

template<typename T>
class TOperand : public IOperand
{
private:
  eOperandType			_type;
  std::string			_type_name;
  int				_precision;
  T				_value;

public:
  TOperand(eOperandType type, T value);
  virtual ~TOperand() {}

  virtual std::string const	&toString() const; // Return string representation

  virtual int			getPrecision() const; // Return precision
  virtual eOperandType		getType() const; // Return type
  virtual T			getValue() const = 0; // Return value

  virtual IOperand		*operator+(const IOperand &iop) const = 0; // add
  virtual IOperand		*operator-(const IOperand &iop) const = 0; // sub
  virtual IOperand		*operator*(const IOperand &iop) const = 0; // mul
  virtual IOperand		*operator/(const IOperand &iop) const = 0; // div
  virtual IOperand		*operator%(const IOperand &iop) const = 0; // mod
};

#endif
