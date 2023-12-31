#pragma once

#include <iostream>

namespace rdi
{
template <class Container>
void print(const Container& container)
{
    for (const auto& elem : container)
    {
        std::cout << elem << std::endl;
    }
}

std::string searchConfig(const std::string& name);

}  // namespace rdi
