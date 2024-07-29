#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data *data = new Data;
    data->s1 = "Hello";
    data->n = 42;
    data->s2 = "World";

    uintptr_t raw = Serializer::serialize(data);
    Data *deserialized_data = Serializer::deserialize(raw);

    std::cout << "data->s1: \t\t" << data->s1 << std::endl;
    std::cout << "data->n: \t\t" << data->n << std::endl;
    std::cout << "data->s2: \t\t" << data->s2 << std::endl;

    std::cout << "deserialized_data->s1: \t" << deserialized_data->s1 << std::endl;
    std::cout << "deserialized_data->n: \t" << deserialized_data->n << std::endl;
    std::cout << "deserialized_data->s2: \t" << deserialized_data->s2 << std::endl;

    std::cout << "data: \t\t\t" << data << std::endl;
    std::cout << "raw: \t\t\t" << raw << std::endl;
    std::cout << "deserialized_data: \t" << deserialized_data << std::endl;

    delete data;
    return 0;
}