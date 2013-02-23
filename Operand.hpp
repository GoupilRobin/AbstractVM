//
// Operand.hpp for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
//
// Made by robin goupil
// Login   <goupil_r@epitech.net>
//
// Started on  Wed Feb 13 13:52:55 2013 robin goupil
// Last update Sat Feb 23 17:02:40 2013 robin goupil
//

#ifndef OPERAND_HPP_
# define OPERAND_HPP_

# include <iostream>
# include <cstdlib>
# include <string>
# include <sstream>
# include "IOperand.hpp"
# include "Exception.hpp"

static t_operand	g_OperandTypeInfo[] =
  {
    {Int8, "int8", 0, 127, -128},
    {Int16, "int16", 1, 32767, -32768},
    {Int32, "int32", 2, 2147483647, -2147483648},
    {Float, "float", 3, 32767, -32768},
    {Double, "double", 4, 2147483647, -2147483648},
    {None, "", 0, 0, 0}
  };

template <typename T>
class Operand : public IOperand
{
private:
  eOperandType			_type;
  std::string			_type_name;
  int				_precision;
  T				_value;

public:
  explicit Operand(eOperandType type, const double &value)
  {
    _type = type;
    _type_name = g_OperandTypeInfo[type].type_name;
    _precision = g_OperandTypeInfo[type].precision;
    if (value > g_OperandTypeInfo[type].max_size || value < g_OperandTypeInfo[type].min_size)
      {
	throw overflowException(value, _type_name, g_OperandTypeInfo[type]);
	exit(-1);
      }
    _value = value;
  }

  virtual std::string const	&toString() const // Return string representation
  {
    std::string			*str = new std::string();
    std::ostringstream		ss;

    /*
    str->append("[(");
    str->append(_type_name);
    str->append(") ");
    */
    if (_type == Int8)
      ss << (int)_value;
    else
      ss << _value;
    str->append(ss.str());
    /*
    if (_type_name == g_OperandTypeInfo[Float].type_name)
      str->append("f");
    str->append("]");
    */
    return (*str);
  }

  virtual int			getPrecision() const // Return precision
  {
    return (_precision);
  }

  virtual eOperandType		getType() const // Return type
  {
    return (_type);
  }

  virtual T			getValue() const // Return value
  {
    return (_value);
  }

  virtual IOperand		*operator+(const IOperand &iop) const // add
  {
    IOperand			*out = NULL;
    eOperandType		type;
    double			res;

    type = _precision >= iop.getPrecision() ? _type : iop.getType();
    res = _value + atof(iop.toString().c_str());
    switch (type)
      {
      case Int8:
	out = new Operand<char>(type, res);
	break;
      case Int16:
	out = new Operand<short>(type, res);
	break;
      case Int32:
	out = new Operand<int>(type, res);
	break;
      case Float:
	out = new Operand<float>(type, res);
	break;
      default:
	out = new Operand<double>(type, res);
	break;
      }
    return (out);
  }

  virtual IOperand		*operator-(const IOperand &iop) const // sub
  {
    IOperand			*out = NULL;
    eOperandType		type;
    double			res;

    type = _precision >= iop.getPrecision() ? _type : iop.getType();
    res = _value - atof(iop.toString().c_str());
    switch (type)
      {
      case Int8:
	out = new Operand<char>(type, res);
	break;
      case Int16:
	out = new Operand<short>(type, res);
	break;
      case Int32:
	out = new Operand<int>(type, res);
	break;
      case Float:
	out = new Operand<float>(type, res);
	break;
      default:
	out = new Operand<double>(type, res);
	break;
      }
    return (out);
  }

  virtual IOperand		*operator*(const IOperand &iop) const // mul
  {
    IOperand			*out = NULL;
    eOperandType		type;
    double			res;

    type = _precision >= iop.getPrecision() ? _type : iop.getType();
    res = _value * atof(iop.toString().c_str());
    switch (type)
      {
      case Int8:
	out = new Operand<char>(type, res);
	break;
      case Int16:
	out = new Operand<short>(type, res);
	break;
      case Int32:
	out = new Operand<int>(type, res);
	break;
      case Float:
	out = new Operand<float>(type, res);
	break;
      default:
	out = new Operand<double>(type, res);
	break;
      }
    return (out);
  }

  virtual IOperand		*operator/(const IOperand &iop) const // div
  {
    IOperand			*out = NULL;
    eOperandType		type;
    double			res;

    type = _precision >= iop.getPrecision() ? _type : iop.getType();
    if (atof(iop.toString().c_str()) == 0)
      throw mathException("Error: Division by 0.");
    res = _value / atof(iop.toString().c_str());
    switch (type)
      {
      case Int8:
	out = new Operand<char>(type, res);
	break;
      case Int16:
	out = new Operand<short>(type, res);
	break;
      case Int32:
	out = new Operand<int>(type, res);
	break;
      case Float:
	out = new Operand<float>(type, res);
	break;
      default:
	out = new Operand<double>(type, res);
	break;
      }
    return (out);
  }

  virtual IOperand		*operator%(const IOperand &iop) const // mod
  {
    IOperand			*out = NULL;
    eOperandType		type;

    type = _precision >= iop.getPrecision() ? _type : iop.getType();
    if (atof(iop.toString().c_str()) == 0)
      throw mathException("Error: Modulo by 0.");
    if (_type >= Float || iop.getType() >= Float)
      throw mathException("Error: Modulo with decimal type.");
    out = new Operand(type, (long)_value % atoi(iop.toString().c_str()));
    return (out);
  }

  std::ostream		&operator<< (std::ostream &os)
  {
    os << this->getValue();
    return (os);
  }
};

std::ostream		&operator<< (std::ostream &os, IOperand const &iop);

#endif
