#ifndef CPLPL_H
#define CPLPL_H

#include "base_unit.h"

class CplplClassUnit : public ClassUnit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;       // набор модификаторов доступа
public:
    explicit CplplClassUnit(const std::string &name) : ClassUnit(name, ACCESS_MODIFIERS.size())      // передача базовому классу количество модификаторов доступа
    {

    }

    void Add(const std::shared_ptr<Unit> &unit, Flags flags)        // функция Add служит для конструирования кода на языке C++
    {
        if (unit == nullptr)                                  // исключительная ситуация
        {
            throw std::runtime_error("The unit is nullptr."); // выброс ошибки
        }

        size_t access_modifier = PRIVATE;

        if (flags < fields_.size())
        {
            access_modifier = flags;
        }
        fields_[access_modifier].push_back(unit);
    }

    std::string Compile(unsigned int level = 0) const          // генерация кода на языке C++
    {
        std::string result = GenerateIndent(level) + "class " + name_ + " {\n";      // имя класса

        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); i++)     // перебор всех наборов модификаторов доступа
        {
            if (fields_[i].empty())
            {
                continue;
            }
            result += ACCESS_MODIFIERS[i] + ":\n";          // указание блока модификатора доступа

            for (const auto &f : fields_[i])
            {
                result += f->Compile(level + 1);         // вывод языковых конструкций
            }
            result += "\n";
        }
        result += GenerateIndent(level) + "};\n";           // конец конструкции класса
        return result;
    }
};

const std::vector<std::string> CplplClassUnit::ACCESS_MODIFIERS =         // список всех модификаторов доступа, который поддерживает язык C++
{ "public",
  "protected",
  "private"
};

#endif // CPLPL_H
