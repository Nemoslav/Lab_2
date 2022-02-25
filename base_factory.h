#ifndef BASE_FACTORY_H
#define BASE_FACTORY_H

#include "Cplpl.h"
#include "Cplpl_method_unit.h"
#include "Cplpl_print_operator_unit.h"

#include "CSharp.h"
#include "CSharp_method_unit.h"
#include "CSharp_print_operator_unit.h"

#include "Java.h"
#include "Java_method_unit.h"
#include "Java_print_operator_unit.h"


// базовый абстрактный класс фабрики языков
class Factory
{
public:
    virtual ~Factory() = default;        // виртуальный деструктор
    virtual std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const = 0;        // интерфейс фабричного метода для создания класса
    virtual std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type, Unit::Flags flags) const = 0;    // интерфейс фабричного метода для создания метода
    virtual std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const = 0;     // интерфейс фабричного метода для создания оператора печати
};

// фабрика языка C++
class CplplFactory : public Factory
{
public:
    std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const
    {
        return std::make_shared<CplplClassUnit>(name);             // создание класса C++
    }
    std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type, Unit::Flags flags) const
    {
        return std::make_shared<CplplMethodUnit>(name, return_type, flags);       // создание метода C++
    }
    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const
    {
        return std::make_shared<CplplPrintOperatorUnit>(name);   // создание оператора печати C++
    }
};

// фабрика языка C#
class CSharpFactory : public Factory
{
public:
    std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const
    {
        return std::make_shared<CSharpClassUnit>(name);            // создание класса C#
    }
    std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type, Unit::Flags flags) const
    {
        return std::make_shared<CSharpMethodUnit>(name, return_type, flags);        // создание метода C#
    }
    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const
    {
        return std::make_shared<CSharpPrintOperatorUnit>(name);         // создание оператора печати C#
    }
};

// фабрика языка Java
class JavaFactory : public Factory
{
public:
    std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const
    {
        return std::make_shared<JavaClassUnit>(name);           // создание класса Java
    }
    std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type, Unit::Flags flags) const
    {
        return std::make_shared<JavaMethodUnit>(name, return_type, flags);         // создание метода Java
    }
    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const
    {
        return std::make_shared<JavaPrintOperatorUnit>(name);     // создание оператора печати Java
    }
};

#endif // BASE_FACTORY_H
