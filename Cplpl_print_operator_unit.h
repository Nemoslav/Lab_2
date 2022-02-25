#ifndef CPLPL_PRINT_OPERATOR_UNIT_H
#define CPLPL_PRINT_OPERATOR_UNIT_H

#include "print_operator_unit.h"

// языковая конструкция оператора печати языка C++
class CplplPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CplplPrintOperatorUnit(const std::string &text) : PrintOperatorUnit(text)
    {

    }

    std::string Compile(unsigned int level = 0) const
    {
        return GenerateIndent(level) + "printf(\"" + text_ + "\");\n";
    }
};

#endif // CPLPL_PRINT_OPERATOR_UNIT_H
