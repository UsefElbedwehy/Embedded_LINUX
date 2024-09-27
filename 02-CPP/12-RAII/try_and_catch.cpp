#include <iostream>
// [01]
// -Exceptions are the unexpected situations that arise during the execution of a program.
// -these Exceptions exhibit odd behaviour in a program that should be taken care of.
// -Exception handling provides a way to handle these Exceptions.
// [02]
// -Exceptions handling provides a mechanism through which we can handle the error generating part separately from the rest of the code.
// -it provides the information to the user, so that he can detect the mistake and correct it.
// [03]
// - Exceptions handling helps in dealing with the Exceptions by transfering the control from one part of the program to another and 
// take care of the Exceptions by providing certain code. 
// -These Exceptions are handled with the help of 3 keywords. [try - catch - throw] 
//  (1)-> try  : this part assumes that the error will take place.
//  (2)-> catch: this part identifies which Exception has occured and tries to catch it. 
//  (3)-> throw: when the program encounters an issue, it throws an exception.
//  ->[3]->(1): try: 
//              -try blocks are used to enclose the statements which may cause the exceptions.
//              -try blocks is followed up by one or more catch blocks.
//              -the Exceptions will be thrown from the try block towards the catch block. 
//  ->[3]->(2): catch: 
//              -Handling these exceptions is the actual job of the catch block.
//              -This block catches the exception thrown from the try block.
//              -Both the try and catch blocks work together. Every try block has at least one catch block attached to it. 
//  ->[3]->(3): throw: 
//              -The throw statement is used to throw an exception and its value to a consecutive exception handler.
//              -Whenever a program experiences an issue, the throw keyword assists the program by performing the operation.



int main(int argc, char const *argv[])
{
    int age = 33;
    try{
        if(age > 24){
            std::cout << "You can access the program." << std::endl;
        }else{
            throw(age);
        }
    }catch(int age){
        std::cout << "You are under the age limit." << std::endl;
        std::cout << "Your age is " << age << std::endl;
    }



    return 0;
}
