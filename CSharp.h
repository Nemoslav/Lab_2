#ifndef CSHARP_H
#define CSHARP_H

#include "base_unit.h"

// языковая конструкция класса языка C#
class CSharpClassUnit : public ClassUnit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;        // набор модификаторов доступа

public:
    explicit CSharpClassUnit(const std::string &name) : ClassUnit(name, ACCESS_MODIFIERS.size())    // передача базовому классу количество модификаторов доступа
    {

    }

    void Add(const std::shared_ptr<Unit> &unit, Flags flags = 0)     // функция Add служит для конструирования кода на языке C#
    {
        if (unit == nullptr)
        {
            throw std::runtime_error("The unit is nullptr.");
        }
        size_t access_modifier = PRIVATE;

        if (flags < fields_.size())
        {
            access_modifier = flags;
        }
        fields_[access_modifier].push_back(unit);
    }

    std::string Compile(unsigned int level = 0) const         // генерация кода на языке C#
    {
        std::string result = "class " + name_ + " {\n";          // имя класса

        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); i++)       // перебор всех наборов модификаторов доступа
        {
            for (const auto &f : fields_[i])
            {
                result += GenerateIndent(level + 1) + ACCESS_MODIFIERS[i] + " " + f->Compile(level + 1);    // вывод языковых конструкций
            }
        }
        result += GenerateIndent(level) + "};\n";     // конец конструкции класса
        return result;
    }
};

const std::vector<std::string> CSharpClassUnit::ACCESS_MODIFIERS =     // список всех модификаторов доступа, который поддерживает язык C#
{
    "public",
    "protected",
    "private",
    "internal",                 // добавились ещё 3 модификатора доступа
    "protected internal",
    "private protected"
};

#endif // CSHARP_H
