#include "base_factory.h"

// функция, генерирующая код на разных языках
std::string GenerateProgram(const std::shared_ptr<Factory> &factory)
{
    /* С помощью auto компилятор может "угадать" тип переменной */
    auto my_class = factory->CreateClass("MyClass");     // класс MyClass

    my_class->Add(factory->CreateMethod("testFunc1", "void", 0), ClassUnit::PUBLIC);     // публичная функция, находящаяся в классе MyClass
    my_class->Add(factory->CreateMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);

    auto method = factory->CreateMethod("testFunc4", "void", MethodUnit::STATIC);    // создание метода
    method->Add(factory->CreatePrintOperator("Hello, world!"));    // добавление этого метода в функцию для вывода
    my_class->Add(method, ClassUnit::PROTECTED);     // добавление метода в класс MyClass

    my_class->Add(factory->CreateMethod("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);   // добавление приватной функции в класс MyClass

    return my_class->Compile();
}
