#ifndef CSHARP_PRINT_OPERATOR_UNIT_H
#define CSHARP_PRINT_OPERATOR_UNIT_H

#include "print_operator_unit.h"

// языковая конструкция оператора печати языка C#
class CSharpPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CSharpPrintOperatorUnit(const std::string &text) : PrintOperatorUnit(text)
    {

    }

    std::string Compile(unsigned int level = 0) const
    {
        return GenerateIndent(level) + "Console.WriteLine(\"" + text_ + "\");\n";
    }
};

#endif // CSHARP_PRINT_OPERATOR_UNIT_H
