#ifndef METHOD_UNIT_H
#define METHOD_UNIT_H

#include "unit.h"

// языковая конструкция метода любого языка
class MethodUnit : public Unit
{
public:
    enum Modifier                // модификаторы методов для всех языков (C++, C#, Java)
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3
    };
public:
    MethodUnit(const std::string &name, const std::string &returnType, Flags flags) : name_(name), return_type_(returnType), flags_(flags)
    {

    }

    void Add(const std::shared_ptr<Unit> &unit, Flags /* flags */ = 0 )     // функция Add служит для конструирования кода на любом языке
    {
        if (unit == nullptr)
        {
            throw std::runtime_error("The unit is nullptr.");
        }
        body_.push_back(unit);
    }
    virtual ~MethodUnit() = default;

protected:
    std::string name_;            // имя метода
    std::string return_type_;       // тип возвращаемого методом значения
    Flags flags_;              // используемые модификаторы
    std::vector<std::shared_ptr<Unit>> body_;
};

#endif // METHOD_UNIT_H
