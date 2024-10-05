#include <array>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>


int main(int argc, char const *argv[])
{
    // //[1] open
    // std::string filename = "fifa.txt";
    // std::string filename2 = "anghami.txt";
    // std::fstream fs;
    // std::fstream fcreate;
    // fs.open(filename, std::ios::in);
    // //create (mode: out)
    // fcreate.open(filename2,std::ios_base::out);

    // //[2]is_open
    // if (fs.is_open())
    // {
    //     std::cout << "File1 is opened!" << std::endl;
    //     //[3]close
    //     fs.close();
    //     std::cout << "File1 is closed!" << std::endl;
    // }else
    // {
    //     std::cout << "Failed to open the file1!" << std::endl;
    // }

    // //[2]is_open
    // if (fcreate.is_open())
    // {
    //     std::cout << "File2 is opened!" << std::endl;
    //     //[3]close
    //     fcreate.close();
    //     std::cout << "File2 is closed!" << std::endl;
    // }else
    // {
    //     std::cout << "Failed to open the file2!" << std::endl;
    // }
    // std::string filename1{"uniform.txt"};
    // std::fstream fs_uniform;
    // fs_uniform.open(filename1, std::ios_base::in);

    // std::cout << std::boolalpha;
    // std::cout << "File is opened? " << fs_uniform.is_open() << std::endl;

    // if(!fs_uniform.is_open()){
    //     fs_uniform.clear();
    //     fs_uniform.open(filename1,std::ios_base::out);
    //     std::cout << "File is created." << std::endl;
    //     std::cout << "File is opened? " << fs_uniform.is_open() << std::endl;
    // }
    // std::fstream fs_ext{"fifa.txt",  fs_ext.out | fs_ext.in};
    // fs_ext.open("fifa.txt",std::ios_base::in);
    // std::cout << "File is opened? " << fs_ext.is_open() << std::endl;
    // fs_ext.swap(fs_uniform);



    // fs_uniform.close();
    // fs_ext.close();

    // //file1
    // std::string f1name{"file1.txt"};
    // std::fstream fs1;
    // //file2
    // //std::string f2name{"file2.txt"};
    // std::fstream fs2;

    // //open files
    // fs1.open(f1name,std::ios_base::in);
    // // fs2.open(f2name,std::ios_base::in);
    
    // //check
    // if(!fs1.is_open()){
    //     fs1.clear();
    //     fs1.open(f1name,std::ios_base::out);
    // }
    // // if(!fs2.is_open()){
    // //     fs2.clear();
    // //     fs2.open(f2name,std::ios_base::out);
    // // }
    // //print 
    // std::cout << "File1 is opened!" << std::endl;
    // //std::cout << "File2 is opened!" << std::endl;

    // fs2 = std::move(fs1);

    // if(!fs2.is_open()){
    //     std::cout << "Failed to open File!" << std::endl;
    // }else{
    //     std::cout << "File is opened successfully!" << std::endl;
    // }

    // //rdbuf
    // std::cout << ">> File content: " << std::endl  << "[" << fs2.rdbuf() << "]." << std::endl;

    //file1
    // std::string f1name{"file1.txt"};
    // std::fstream fs1;
    // //open files
    // fs1.open(f1name,std::ios_base::in | std::ios_base::out);

    // std::cout << "fs1.get() : " << static_cast<char>(fs1.get()) << std::endl;   //A
    // std::cout << "fs1.peek(): " << static_cast<char>(fs1.peek()) << std::endl;  //h
    // std::cout << "fs1.peek(): " << static_cast<char>(fs1.peek()) << std::endl;  //h
    // std::cout << "fs1.get() : " << static_cast<char>(fs1.get()) << std::endl;   //h
    // std::cout << "fs1.get() : " << static_cast<char>(fs1.get()) << std::endl;   //m
    // std::cout << "fs1.peek(): " << static_cast<char>(fs1.peek()) << std::endl;  //e
    
    //fs1.unget();
    //std::cout << "fs1.peek(): " << static_cast<char>(fs1.peek()) << std::endl;  //m
    
    // fs1.putback('p');
    // std::cout << "file content: " << std::endl << fs1.rdbuf() << std::endl;

    // std::cout << "modified? "<< std::boolalpha << static_cast<bool>(fs1.putback('w')) << std::endl;
    
    // std::cout << "file content: " << std::endl << fs1.rdbuf() << std::endl;

    // std::string f1name{"file1.txt"};
    // std::fstream fs1;
    // std::array<std::array<char, 20>, 10> data_array;
    
    // //open files
    // fs1.open(f1name,std::ios_base::in | std::ios_base::out);

    // // // fs1.ignore(20,'m');
    // // // fs1.getline(&data_array[0][0],20);
    // // // Read lines into data_array and print each one
    // for (size_t i = 0; i < data_array.size(); ++i) {
    //     fs1.getline(&data_array[i][0], 20,' '); // Reading one line
    //     for (auto x : data_array[i]) {
    //         if (x == '\0') break; // Stop printing when null character is found
    //         std::cout << x;
    //     }
    //     std::cout << std::endl;
    // }
    // fs1.clear();
    
    // std::cout << "good()? "<< std::boolalpha << fs1.good() << std::endl;
    // std::cout << "eof() ? "<< std::boolalpha << fs1.eof() << std::endl;
    // std::cout << "bad() ? "<< std::boolalpha << fs1.bad() << std::endl;
    // std::cout << "fail()? "<< std::boolalpha << fs1.fail() << std::endl;
    // fs1 << "\nusef Elbedwehyyyy";
    // fs1.write("\nUSef Elbedwehy!", 15);
    // fs1.flush();

    //fs1.close();

    std::string  filename{"a.out"};
    std::fstream fs;
    std::array<char, 17> magic;

    fs.open(filename,std::ios_base::in | std::ios_base::binary);

    if (fs.is_open())
    {
        fs.read(&magic[0], magic.size() -1);
        std::cout << "Read " << fs.gcount() << " bytes. \nmagic numbers: " ;
        for(int word : magic){
            std::cout << std::hex << std::setw(2) << std::setfill('0') << word << ' ';
        }
        std::cout << std::endl;
        std::cout << "               " ;  
        for(int i =0;i<magic.size();i++){
            printf("%02x ",magic[i]);
        }
        std::cout << std::endl;
        // +++ cmd to show the magic numbers: readelf -h a.out | head
    }
    

    return 0;
}