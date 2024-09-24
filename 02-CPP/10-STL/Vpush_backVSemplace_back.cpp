#include <iostream>
#include <vector>
#include <string>

class Person {
public:
static int obj_counter;
    Person(){
        std::cout << "> Person default constructor " << ++obj_counter << " " << this << std::endl;
    }
    Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << ">Person Parameterized constructor " << ++obj_counter << " " << this << std::endl;
    }
    Person(const Person &other):name(other.name),age(other.age){
        std::cout << ">Person copy constructor " << ++obj_counter << " " << this << std::endl;
    }
    ~Person(){
        std::cout << "Person default destructor." << obj_counter-- << " " << this << std::endl;
    }
private:
    std::string name;
    int age;
};
int Person::obj_counter = 0 ;

int main(int argc, char const *argv[])
{
    std::vector<Person> people;
    //people.reserve(4);

    //Person p("John", 25);  // >>>>>>>>>>> copy constructor
    // people.push_back(p);
    std::cout << "-------------------------" << std::endl;
    people.push_back(Person("usef",23));
    std::cout << "-------------------------" << std::endl;

    //OUTPUT:
            //1- paramaterized constructor
            //2- copy constructor
            //3- paramaterized constructor
            //4- copy constructor
            //5- copy constructor

    people.emplace_back(Person("John", 25));  // Constructs the object in place, no temporary object
    //people.emplace_back("Doe", 30);   // Again, constructs directly in the container
    std::cout << "-------------------------" << std::endl;
    
    return 0;
}
