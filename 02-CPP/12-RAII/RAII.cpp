#include <iostream>
#include <string>
#include <fstream>
class FileHandler {
    private:
    std::ofstream file; 
    public:
    FileHandler(const std::string& filename){
        file.open(filename);
        if(file.is_open()){
            std::cout << "File "<<filename << " opened successfully." << std::endl;
        }
        else{
            std::cerr << "Failed to open file: " << filename << std::endl;
        }
    }

    void writeToFile(const std::string& content){
        if(file.is_open()){
            file << content;
            std::cout << "> Content written to the file: "<< content ;
        }
    }

    ~FileHandler(){
        if(file.is_open()){
            file.close();
            std::cout << "File closed automatically in destructor." << std::endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    FileHandler fileHandler("example.txt");
    
    fileHandler.writeToFile("This is an example of RAII in C++.\n");


    return 0;
}
