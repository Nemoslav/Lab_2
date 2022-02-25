#ifndef PRINT_OPERATOR_UNIT_H
#define PRINT_OPERATOR_UNIT_H

#include "unit.h"

// элемент Оператор печати
class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit(const std::string &text) : text_(text)
    {

    }
    virtual ~PrintOperatorUnit() = default;
protected:
    std::string text_;
};

#endif // PRINT_OPERATOR_UNIT_H
