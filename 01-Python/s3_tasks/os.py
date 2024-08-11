import os
import shutil

if os.path.exists("project"):
    shutil.rmtree("project")
    print("Folder is deleted...")

#os.mkdir("./project")
#os.mkdir("./project/src")
#make directories: src ,tests and build
os.system("mkdir -p ./project/src")
os.system("mkdir -p ./project/tests")
os.system("mkdir -p ./project/build")
#create files
os.system("touch ./project/src/main.cpp")
os.system("touch ./project/CMakeLists.txt")
#open and write into file
mainCppFile = open("./project/src/main.cpp","w")
#write
mainCppFile.write("#include <iostream> \n\
int main(){ std::cout << \"Helloworld\" << std::endl; \nreturn 0; }")
#close
mainCppFile.close()

#update CMakeListsFile
CMakeListsFile = open("./project/CMakeLists.txt","w")
#write
CMakeListsFile.write("cmake_minimum_required(VERSION 3.10)\n\
project(USef)\n\
add_executable(USef src/main.cpp)")
#close
CMakeListsFile.close()

#go to build file and run
os.chdir("project/build")
os.system("cmake .. && make -j && ./USef")

#finished
print("Done!")




