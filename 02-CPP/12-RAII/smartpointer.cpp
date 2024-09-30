#include <iostream>
#include <memory>

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired.\n";
    }
    ~Resource() {
        std::cout << "Resource destroyed.\n";
    }
    void sayHello() {
        std::cout << "Hello from Resource.\n";
    }
};

int main() {
    // Creating a unique_ptr that manages a Resource object
    //std::unique_ptr<Resource> resPtr;
    // std::unique_ptr<Resource> resUnPtr = std::make_unique<Resource>();

    // resUnPtr->sayHello();  // Accessing the Resource through the unique_ptr

    std::shared_ptr<Resource> resShPtr1 = std::make_shared<Resource>();
    {
        std::shared_ptr<Resource> sharedPtr2 = resShPtr1;  // Both sharedPtr1 and sharedPtr2 now share ownership
        std::cout << "sharedPtr2 goes out of scope.\n";
    }  // sharedPtr2 goes out of scope, but the Resource is not destroyed yet
    resShPtr1.reset();
    std::cout << ">>>> sharedPtr2 goes out of scope, but the Resource is not destroyed yet <<<<" << std::endl;
    // Resource will be destroyed when sharedPtr1 goes out of scope

    // Resource is automatically destroyed when the unique_ptr goes out of scope
    return 0;
}