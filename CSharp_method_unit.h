#ifndef CSHARP_METHOD_UNIT_H
#define CSHARP_METHOD_UNIT_H

#include "method_unit.h"

// языковая конструкция метода языка C#
class CSharpMethodUnit : public MethodUnit
{
public:
    CSharpMethodUnit(const std::string &name, const std::string &returnType, Flags flags) : MethodUnit(name, returnType, flags)
    {

    }

    std::string Compile(unsigned int level = 0) const    // функция проверки поддерживаемых флагов
    {
        std::string result = "";

        if (flags_ & STATIC)
        {
            result += "static ";
        }
        else if (flags_ & VIRTUAL)
        {
            result += "virtual ";
        }
        result += return_type_ + " ";     // тип возвращаемого значения
        result += name_ + "() {\n";     // название функции

        for (const auto &b : body_)
        {
            result += b->Compile(level + 1);     // добавление конструкции
        }
        result += GenerateIndent(level) + "}\n";     // конец конструкции метода
        return result;
    }
};

#endif // CSHARP_METHOD_UNIT_H
