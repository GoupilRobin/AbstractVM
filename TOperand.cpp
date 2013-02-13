//
// TOperand.cpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Wed Feb 13 14:27:00 2013 robin goupil
// Last update Wed Feb 13 14:43:08 2013 robin goupil
//

#include "TOperand.hpp"

t_operand	g_OperandTypeInfo[] =
  {
    {Int8, "int8", 0},
    {Int16, "int16", 1},
    {Int32, "int32", 2},
    {Float, "float", 3},
    {Double, "double", 4},
  };

template <typename T>
TOperand<T>::TOperand(eOperandType type, T value)
{
  _type = type;
  _type_name = g_OperandTypeInfo[type].type_name;
  _precision = g_OperandTypeInfo[type].precision;
  _value = value;
}

template <typename T>
const std::string		&TOperand<T>::toString() const
{
  return (_type_name);
}

template <typename T>
int				TOperand<T>::getPrecision() const
{
  return (_precision);
}

template <typename T>
eOperandType			TOperand<T>::getType() const
{
  return (_type);
}

template <typename T>
T				TOperand<T>::getValue() const
{
  return (_value);
}
