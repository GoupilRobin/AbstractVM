//
// Operand.cpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/WORK
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Thu Feb 14 19:13:12 2013 robin goupil
// Last update Thu Feb 14 19:25:46 2013 robin goupil
//

#include "Operand.hpp"

t_operand	g_OperandTypeInfo[] =
  {
    {Int8, "int8", 0, 127, -128},
    {Int16, "int16", 1, 32767, -32768},
    {Int32, "int32", 2, 2147483647, -2147483648},
    {Float, "float", 3, 32767, -32768},
    {Double, "double", 4, 2147483647, -2147483648},
  };

Operand::Operand(eOperandType type, const double &value)
{
  _type = type;
  _type_name = g_OperandTypeInfo[type].type_name;
  _precision = g_OperandTypeInfo[type].precision;
  if (value > g_OperandTypeInfo[type].max_size || value < g_OperandTypeInfo[type].min_size)
    {
      std::cout << "Error: Value (" << value << ") overflow in the type " << _type_name << " (min=" << g_OperandTypeInfo[type].min_size << " - max=" << g_OperandTypeInfo[type].max_size << ")." << std::endl;
      exit(-1);
    }
  castValue(value);
}

void			Operand::castValue(const double &value)
{
  switch (_type)
    {
    case Int8:
      _value = (char)value;
      break;
    case Int16:
      _value = (short)value;
      break;
    case Int32:
      _value = (int)value;
      break;
    case Float:
      _value = (float)value;
      break;
    default:
      _value = value;
      break;
    }
}

std::string const	&Operand::toString() const // Return string representation
{
  return (_type_name);
}

int			Operand::getPrecision() const // Return precision
{
  return (_precision);
}

eOperandType		Operand::getType() const // Return type
{
  return (_type);
}

double			Operand::getValue() const // Return value
{
  return (_value);
}

IOperand		*Operand::operator+(const IOperand &iop) const // add
{
  IOperand			*out = NULL;
  eOperandType		type;
  const Operand		*tmp;

  type = _precision >= iop.getPrecision() ? _type : iop.getType();
  tmp = &(static_cast<const Operand &>(iop));
  out = new Operand(type, _value + tmp->getValue());
  return (out);
}

IOperand		*Operand::operator-(const IOperand &iop) const // sub
{
  IOperand			*out = NULL;
  eOperandType		type;
  const Operand		*tmp;

  type = _precision >= iop.getPrecision() ? _type : iop.getType();
  tmp = &(static_cast<const Operand &>(iop));
  out = new Operand(type, _value - tmp->getValue());
  return (out);
}

IOperand		*Operand::operator*(const IOperand &iop) const // mul
{
  IOperand			*out = NULL;
  eOperandType		type;
  const Operand		*tmp;

  type = _precision >= iop.getPrecision() ? _type : iop.getType();
  tmp = &(static_cast<const Operand &>(iop));
  out = new Operand(type, _value * tmp->getValue());
  return (out);
}

IOperand		*Operand::operator/(const IOperand &iop) const // div
{
  IOperand			*out = NULL;
  eOperandType		type;
  const Operand		*tmp;

  type = _precision >= iop.getPrecision() ? _type : iop.getType();
  tmp = &(static_cast<const Operand &>(iop));
  if (tmp->getValue() == 0)
    {
      std::cout << "Error: Division by 0." << std::endl;
      exit(-1);
    }
  out = new Operand(type, _value / tmp->getValue());
  return (out);
}

IOperand		*Operand::operator%(const IOperand &iop) const // mod
{
  IOperand			*out = NULL;
  eOperandType		type;
  const Operand		*tmp;

  type = _precision >= iop.getPrecision() ? _type : iop.getType();
  tmp = &(static_cast<const Operand &>(iop));
  if (tmp->getValue() == 0)
    {
      std::cout << "Error: Modulo by 0." << std::endl;
      exit(-1);
    }
  out = new Operand(type, (long)_value % (long)tmp->getValue());
  return (out);
}

std::ostream		&operator<< (std::ostream &os, IOperand const &iop)
{
  os << ((const Operand &)iop).getValue();
  return (os);
}
