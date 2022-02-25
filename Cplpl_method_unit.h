#ifndef CPLPL_METHOD_UNIT_H
#define CPLPL_METHOD_UNIT_H

#include "method_unit.h"

// языковая конструкция метода языка C++
class CplplMethodUnit : public MethodUnit
{
public:
    CplplMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
        : MethodUnit(name, returnType, flags)
    {

    }

    std::string Compile(unsigned int level = 0) const     // функция проверки поддерживаемых флагов
    {
        std::string result = GenerateIndent(level);

        if (flags_ & STATIC)
        {
            result += "static ";
        }
        else if (flags_ & VIRTUAL)
        {
            result += "virtual ";
        }

        result += return_type_ + " ";       // тип возвращаемого значения
        result += name_ + "()";           // название функции

        if (flags_ & CONST)
        {
            result += " const";
        }
        result += " {\n";               // начало конструкции метода

        for (const auto &b : body_)
        {
            result += b->Compile(level + 1);       // добавление конструкции
        }
        result += GenerateIndent(level) + "}\n";        // конец конструкции метода
        return result;
    }
};

#endif // CPLPL_METHOD_UNIT_H
