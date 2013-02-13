//
// IOperand.hpp for IOperand in /home/chirou_t//tek2/projets/c++/TP_abstract
// 
// Made by thomas chiroussot-chambeaux
// Login   <chirou_t@epitech.net>
// 
// Started on  Mon Feb 11 15:12:35 2013 thomas chiroussot-chambeaux
// Last update Mon Feb 11 17:15:21 2013 thomas chiroussot-chambeaux
//

#ifndef	__IOPERAND__

# define __IOPERAND__

# include <iostram>
# include <string>

class IOperand
{
public:
enum eOperandType
  {
    Int8,
    Int16,
    Int32,
    Float,
    Double
  };

  virtual std::string const & toString() const = 0; // Renvoie une string reprensentant l’instance

  virtual int getPrecision() const = 0; // Renvoie la precision du type de l’instance
  virtual eOperandType getType() const = 0; // Renvoie le type de l’instance.

  virtual IOperand * operator+(const IOperand &rhs) const = 0; // Somme
  virtual IOperand * operator-(const IOperand &rhs) const = 0; // Difference
  virtual IOperand * operator*(const IOperand &rhs) const = 0; // Produit
  virtual IOperand * operator/(const IOperand &rhs) const = 0; // Quotient
  virtual IOperand * operator%(const IOperand &rhs) const = 0; // Modulo

  virtual ~IOperand() {}
};

#endif
