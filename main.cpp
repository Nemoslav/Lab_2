#include <iostream>

#include "base_factory.h"
#include "generate.cpp"

int main(int argc, char *argv[])
{
    std::cout << "C++:" << std::endl;
    try                // обработка ошибок
     {
         std::cout << GenerateProgram(std::make_shared<CplplFactory>()) << std::endl;    // генерация кода на языке C++
     }
     catch (const std::runtime_error &error)
     {
         std::cout << error.what() << std::endl;
     }

    std::cout << "C#:" << std::endl;
    try                // обработка ошибок
    {
        std::cout << GenerateProgram(std::make_shared<CSharpFactory>()) << std::endl;    // генерация кода на языке C#
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "Java:" << std::endl;
    try                // обработка ошибок
    {
        std::cout << GenerateProgram(std::make_shared<JavaFactory>()) << std::endl;       // генерация кода на языке Java
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }

    return 0;
}
