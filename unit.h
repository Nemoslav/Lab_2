#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>
#include <memory>

// самый самый базовый класс (взят из примера)
class Unit
{
public:
    using Flags = unsigned int;

public:
    virtual ~Unit() = default;                                // виртуальный деструктор
    /* Виртуальная функция-член предназначена для добавления вложенных элементов (передача происходит через умный
указатель) умный указатель std::shared_ptr).Также эта функция принимает параметр
Flags */
    virtual void Add(const std::shared_ptr<Unit> &, Flags)
    {
        throw std::runtime_error("Not supported");
    }
    /* Функция генерирует код, соответствующий содержимому элемента. Результат возвращается в виде строки
std::string */
    virtual std::string Compile(unsigned int level = 0) const = 0;        // функция компиляции кода
protected:
    /* Вспомогательная функция-член всего лишь возвращает строку, состоящую из нужного числа пробелов */
    virtual std::string GenerateIndent(unsigned int level) const            // функция генерации отступов
    {
        static const auto DEFAULT_INDENT = "    ";
        std::string result;
        for (unsigned int i = 0; i < level; i++)            // добавление отступов
        {
            result += DEFAULT_INDENT;
        }

        return result;
    }
};

#endif // UNIT_H
