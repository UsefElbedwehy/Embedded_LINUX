#include <iostream>
#include <array>


int main(int argc, char const *argv[])
{
    std::array<std::array<char,3>,3> tic_tac_teo{
        'X',' ','O',
        ' ','X','O',
        'O',' ','X'};
    
    std::cout << "tic-tac-teo board: " << std::endl; 
    for(const auto &i : tic_tac_teo){
        for(char j : i){
            if(!tic_tac_teo.empty()){
            std::cout << j << " ";
        }
        }
    std::cout << std::endl;
    }

    return 0;
}
