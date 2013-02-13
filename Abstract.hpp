//
// Abstract.hpp for Abstract in /home/chirou_t//tek2/projets/c++/TP_abstract
// 
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
// 
// Started on  Mon Feb 11 15:18:07 2013 thomas chiroussot-chambeaux
// Last update Mon Feb 11 17:16:16 2013 thomas chiroussot-chambeaux
//

#ifndef __ABSTRACT__

# define __ABSTRACT__

# include "IOperand.hpp"

class	Abstract : public IOperand
{
private:

  IOperand * createInt8(const std::string & value);
  IOperand * createInt16(const std::string & value);
  IOperand * createInt32(const std::string & value);
  IOperand * createFloat(const std::string & value);
  IOperand * createDouble(const std::string & value);

public:

  Abstract();

  std::string const & toString() const;
  int getPrecision() const; // Renvoie la precision du type de l’instance
  eOperandType getType() const; // Renvoie le type de l’instance.

  IOperand * operator+(const IOperand &rhs) const; // Somme
  IOperand * operator-(const IOperand &rhs) const; // Difference
  IOperand * operator*(const IOperand &rhs) const; // Produit
  IOperand * operator/(const IOperand &rhs) const; // Quotient
  IOperand * operator%(const IOperand &rhs) const; // Modulo

  IOperand * createOperand(eOperandType type, const std::string & value);

  ~Abstract();
};

#endif
