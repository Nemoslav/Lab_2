#ifndef JAVA_METHOD_UNIT_H
#define JAVA_METHOD_UNIT_H

#include "method_unit.h"

// языковая конструкция метода языка Java
class JavaMethodUnit : public MethodUnit
{
public:
    JavaMethodUnit(const std::string &name, const std::string &returnType, Flags flags) : MethodUnit(name, returnType, flags)
    {

    }

    std::string Compile(unsigned int level = 0) const          // функция проверки поддерживаемых флагов
    {
        std::string result = "";

        if (flags_ & STATIC)
        {
            result += "static ";
        }

        if (flags_ & FINAL)
        {
            result += "final ";
        }
        result += return_type_ + " ";           // тип возвращаемого значения
        result += name_ + "() {\n";          // название функции

        for (const auto &b : body_)
        {
            result += b->Compile(level + 1);     // добавление конструкции
        }
        result += GenerateIndent(level) + "}\n";    // конец конструкции метода
        return result;
    }
};

#endif // JAVA_METHOD_UNIT_H
