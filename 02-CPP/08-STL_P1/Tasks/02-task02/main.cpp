//author: Usef Elbedwehy
//date: Mon 02 Sep 2024
//@session: 08
//@topic: OOP
//@brief: 0-3-5 rules
//task: 02-Create Class to handle Logs with diﬀerent Levels 
//                   and store Msgs as well for dump and clear the buﬀer

// LOG::Level(level::warn)<<” forget to close ﬁle “ ;
// LOG::Dump();
// LOG::Clear


#include <iostream>
#define lvl_size 100
#define lvl_num  3

class Log
{
public:
    enum Level { INFO ,  WARN ,  ERROR };

private:
    bool isAuthenticated;
    std::string password = "software";
    static std::string msgs[lvl_num][lvl_size];
    static Level current_lvl;
    static int info_Index;
    static int warn_Index;
    static int error_Index;

public:
    
Log& set_lvl(Level LL);
//parameterized Log constructor
    Log(const std::string& str);
//Log destructor    
    ~Log();
//methods to access private
    void clear();
    void dump();
//operator overloading
    Log& operator<<(const std::string& S){
        if(isAuthenticated){
        switch(current_lvl){        
        case Level::INFO:
            std::cout << "[INFO] " << S <<std::endl;
            msgs[current_lvl][info_Index++] = S;
            break;
        case Level::WARN:
            std::cout << "[WARN] " << S <<std::endl;
            msgs[current_lvl][warn_Index++] = S;
            break;
        case Level::ERROR:
            std::cout << "[ERROR] " << S <<std::endl;
            msgs[current_lvl][error_Index++] = S;
            break;
        }          
        }
        return *this;
    }
};

Log::Level Log::current_lvl = Log::Level::INFO;
int Log::info_Index  =0;
int Log::warn_Index  =0;
int Log::error_Index =0;
std::string Log::msgs[lvl_num][lvl_size] = {};

Log::Log(const std::string& str)
{
    if(str == Log::password){
        std::cout << "> Logged successfully!" << std::endl;
        isAuthenticated = true;
    }else{
        std::cout << "> Failed!...Wrong password!" << std::endl;
        isAuthenticated = false;
    }
}

Log::~Log()
{
    std::cout << "End of session!" << std::endl;
}

Log& Log::set_lvl(Level LL){
       current_lvl = LL;
       return *this;
    }
//clear logs
void Log::clear(){
        current_lvl = Level::INFO;
        info_Index  = 0;
        error_Index = 0;
        warn_Index  = 0;
    }
void Log::dump(){
    std::cout << "---------------------------------" << std::endl;
    std::cout << "INFO:" << std::endl;
    if(info_Index != 0){
        for(int i =0 ; i < info_Index ;i++){
            std::cout << "> " <<msgs[INFO][i] << std::endl;
        }
    }else{
        std::cout << "> XXX [No INFO msgs!] XXX" << std::endl;
    }
    std::cout << "WARNING:" << std::endl;
    if(warn_Index != 0){
        for(int i =0 ; i < warn_Index ;i++){
            std::cout << "> " << msgs[WARN][i] << std::endl;
        }
    }else{
        std::cout << "> XXX [No WARNING msgs!] XXX" << std::endl;
    }
    std::cout << "ERROR:" << std::endl;
    if(error_Index != 0){
        for(int i =0 ; i < error_Index ;i++){
        std::cout << "> " << msgs[ERROR][i] << std::endl;
    }
    }else{
        std::cout << "> XXX [No ERROR msgs!] XXX" << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
}

int main(){

    Log L1("software");
    L1.set_lvl(Log::Level::INFO) << "1st log!";
    L1.set_lvl(Log::Level::INFO) << "2nd log!";
    L1.set_lvl(Log::Level::INFO) << "3rd log!";
    L1.set_lvl(Log::Level::WARN) << "forgot to close the file!!!!!";
    L1.dump();
    L1.clear();
    L1.dump();

    return 0;
}