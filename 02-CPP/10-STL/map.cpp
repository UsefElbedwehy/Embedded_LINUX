#include <iostream>
#include <map>
#include <string>
#include "map.h"

int main(int argc, char const *argv[])
{
    std::map<std::string , std::string> automotive_map{
        {"GPIOA","0b10000001"},
        {"GPIOB","0b11000011"},
        {"GPIOC","0b11100111"},
        {"GPIOD","0b11111111"},
        {"GPIOE","0b00000000"}
    };
    printMap(automotive_map);

    automotive_map["GPIOE"] = "0b11111111";

    printMap(automotive_map);

    automotive_map.insert({"USART2","0XFFFFFFFF"});
    automotive_map.emplace("USART3","0XFFFFFFFF");
    automotive_map.emplace("USART3","0XFFFFFFFA");
    printMap(automotive_map);

    if(automotive_map.find("GPIOA") !=automotive_map.end()){
        automotive_map.erase("GPIOA");
        std::cout << "Done>..." << std::endl;
    }
    printMap(automotive_map);


    return 0;
}

void printMap(std::map<std::string, std::string> &automotive_map)
{
    for (auto s : automotive_map)
    {
        std::cout << s.first << " " << s.second << " " << std::endl;
    }
    std::cout << std::string(30, '*') << std::endl;
}
