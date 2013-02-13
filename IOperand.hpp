//
// IOperand.hpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Wed Feb 13 10:40:07 2013 robin goupil
// Last update Wed Feb 13 14:38:18 2013 robin goupil
//

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

# include <string>

enum eOperandType
  {
    Int8 = 0, // char
    Int16, // short
    Int32, // int
    Float, // float
    Double, // double
  };

typedef struct	s_operand
{
  eOperandType	type;
  std::string	type_name;
  int		precision;
} t_operand;

class IOperand
{
public:
  virtual std::string const	&toString() const = 0; // Return string representation

  virtual int			getPrecision() const = 0; // Return precision
  virtual eOperandType		getType() const = 0; // Return type

  virtual IOperand		*operator+(const IOperand &iop) const = 0; // add
  virtual IOperand		*operator-(const IOperand &iop) const = 0; // sub
  virtual IOperand		*operator*(const IOperand &iop) const = 0; // mul
  virtual IOperand		*operator/(const IOperand &iop) const = 0; // div
  virtual IOperand		*operator%(const IOperand &iop) const = 0; // mod

  virtual			~IOperand() {}
};

#endif
