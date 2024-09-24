#include <iostream>
#include <array>
#include <string.h>
static constexpr int SIZE = 25;
class inherit_array: public std::array<char,SIZE>
{
private:
    /* data */
public:
    using myarray = std::array<char,SIZE>;
    inherit_array(const char *str);
    ~inherit_array();
    void print(){std::cout << myarray::data() << std::endl;};
    void clear(){memset(myarray::data(),0,SIZE);};
    void assign(const char *str){strncpy(myarray::data(),str,SIZE);};
};

inherit_array::inherit_array(const char *str)
{
    strncpy(myarray::data(), str,SIZE);
}

inherit_array::~inherit_array()
{
}



int main(int argc, char const *argv[])
{
    
    inherit_array s1("Hello world welcome");
    s1.print();
    std::cout << s1.size() << std::endl;
    s1.clear();
    s1.assign("Hello man!");
    s1.print();

    return 0;
}
