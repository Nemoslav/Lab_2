#ifndef BASE_UNIT_H
#define BASE_UNIT_H

#include "unit.h"

// элемент Класс (взят из примера)
class ClassUnit : public Unit
{
public:
    enum AccessModifier          // модификаторы доступа для всех языков (C++, C#, Java)
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;
public:
    explicit ClassUnit(const std::string &name, size_t fields_size) : name_(name), fields_(fields_size)   // количество модификаторов доступа, которое может поддерживать язык
    {

    }
    virtual ~ClassUnit() = default;       // виртуальный деструктор

protected:
    using Field = std::vector<std::shared_ptr<Unit>>;        // тип данных для набора полей класса
    std::string name_;                          // имя создаваемого класса
    std::vector<Field> fields_;
};

const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS =
{
  "public",
  "protected",
  "private"
};

#endif // BASE_UNIT_H
