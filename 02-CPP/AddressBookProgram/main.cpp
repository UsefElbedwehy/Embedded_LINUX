//author: Usef Elbedwehy
//date: Thu 22 Aug 2024
//@session: 03
//@topic: derived part 2
//@brief: evelop a simple address book program
// that allows users to add, update, and
// search for contacts.
#include <iostream>

class Display{
    private:
    const std::string option_List[6] = {
        "   | List       |   Lists all users"        ,
        "   | Add        |   Adds an user"           ,
        "   | Delete     |   Deletes an user"        ,
        "   | Delete_all |   Remove all users"       ,
        "   | Search     |   Search for an user"     ,
        "   | Close      |   Close the address book"
        }; 
    public:
        Display(){

        }
        ~Display(){
            
        }
        void showWelcomeMsg(){
            std::cout << "Welcome to your favourite address book!" << std::endl;
        }
        void showMenu(){
            std::cout << "What do you want to do?" << std::endl;
            for(std::string lst : option_List){
                std::cout << lst << std::endl;
            }
        }


};

class Contact{
    private:
        std::string name;
        std::string phone;
        std::string email;

    public:
        Contact(): name(""),phone(""),email(""){

        } 
        Contact(std::string name,std::string phone,std::string email) : name(name),phone(phone),email(email) {
            
        } 
        ~Contact(){

        }
        void setter(std::string name_,std::string phone_,std::string email_){
            name  = name_;
            phone = phone_;
            email = email_;
        }
        void setName(std::string name_){
            name  = name_;

        }
        void setPhone(std::string phone_){
            
            phone = phone_;
            
        }
        void setEmail(std::string email_){

            email = email_;
        }

        std::string getName(){
            return name;
        }
        std::string getPhone(){
            return phone;
        }
        std::string getEmail(){
            return email;
        }

};

class AddresssBook{
    private:
        Contact* Contacts;
        int contactCounter;
        int capacity;
        void resize(){
            capacity = (capacity * 2 );
            Contact* newContacts = new Contact[capacity];
            for(int i=0;i<contactCounter;i++){
                newContacts[i] = Contacts[i];
            }
            delete[] Contacts;
            Contacts = newContacts;
        }
    public:
        AddresssBook(int init_capacity = 2):contactCounter(0) ,capacity(init_capacity) {
            Contacts = new Contact[capacity];
        }
        ~AddresssBook(){
            delete[] Contacts;
        }
        void addContact(){
            if(contactCounter >= capacity){
                resize();
            }
            std::string name,phone,email;
            std::cout << "name: ";
            std::cin >> name;
            std::cout << "phone: ";
            std::cin >> phone;
            std::cout << "email: ";
            std::cin >> email;
            Contacts[contactCounter].setter(name,phone,email);
            contactCounter++;
            std::cout << " > Contact added successfully!" << std::endl;
            
        }
        void listContact(){
            if(contactCounter==0){
                std::cout << " > No contacts available!...Empty"  << std::endl;
            }else{
                std::cout << "-----------------------------------------"  << std::endl;
                for(int i=0;i<contactCounter;i++){
                
                std::cout << "userName: " << Contacts[i].getName() << std::endl;
                std::cout << "userPhone: " << Contacts[i].getPhone() << std::endl;
                std::cout << "userEmail: " << Contacts[i].getEmail() << std::endl;
                std::cout << "-----------------------------------------"  << std::endl;
            }
            }
        }
        void deleteContact(){
            if(contactCounter == 0){
                std::cout << " > No contacts available!...Empty"  << std:: endl; 
            }else{
                std::string name_;
                std::cout << "name: ";
                std::cin >> name_;
                int index = -1;
                for(int i=0;i<contactCounter;i++){
                    if(name_ == Contacts[i].getName()){
                        index = i;
                        break;
                    }
                }
                if(index == -1){
                    std::cout << " > Contact not found." << std::endl;
                }else{
                    for(int i=index;i<contactCounter-1;i++){
                    Contacts[i] = Contacts[i+1];
                }
                std::cout << " > Contact deleted." << std::endl;
                contactCounter--;
                }
            }
        }
        void deleteAllContact(){
            if(contactCounter == 0){
                std::cout << " > No exist contact. add contact..."  << std:: endl; 
            }else{
                delete[] Contacts;
                contactCounter=0;
                std::cout << " > Deleted...Done!"  << std:: endl; 
            }
        }
        void searchContact(){
            if(contactCounter == 0){
                std::cout << " > No contacts available!...Empty"  << std::endl;
            }else{
                std::string name_;
                std::cout << "name: ";
                std::cin >> name_;
                for(int i=0;i<contactCounter;i++){
                    if(name_ == Contacts[i].getName()){
                    std::cout << "-----------------------------------------"  << std::endl;
                    std::cout << "userName: " << Contacts[i].getName() << std::endl;
                    std::cout << "userPhone: " << Contacts[i].getPhone() << std::endl;
                    std::cout << "userEmail: " << Contacts[i].getEmail() << std::endl;
                    std::cout << "-----------------------------------------"  << std::endl;
                    }
            }
            }
        }
};

   
int main() {

    std::string option{"Default"};
    Display D1;
    AddresssBook AddresssBooks;

    D1.showWelcomeMsg();

    while(option != "Close"){
        D1.showMenu();
        std::cin >> option;
        if(option == "List"){
            AddresssBooks.listContact();
        }else if(option == "Add"){
        AddresssBooks.addContact();
        }else if(option == "Delete"){  //delete
            AddresssBooks.deleteContact();
        }else if(option == "Delete_all"){//delete all 
            AddresssBooks.deleteAllContact();
        }else if(option == "Search"){//search
            AddresssBooks.searchContact();
        }else if(option == "Close"){// close
            std::cout << " > Bye...Bye...! :( " << std::endl;
            break;
        }else{//Not valid... try again...
            std::cout << " > Not a vaild option...try again..." << std::endl;
        }   
    }
    return 0;
}