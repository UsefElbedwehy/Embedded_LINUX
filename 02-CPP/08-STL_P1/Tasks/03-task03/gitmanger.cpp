//author: Usef Elbedwehy
//date: Fri 06 Sep 2024
//@session: 08
//@topic: OOP
//@brief: git Manager

#include <iostream>
#include <string>

class Git
{
private:
    std::string current_branch;
    int add_number = 0;
    int commits_number = 0;
public:
    Git();
    ~Git();
    void add(){ //start of add()
    add_number++;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "-                                    -" << std::endl;
    std::cout << "-                add                 -" << std::endl;
    std::cout << "-                                    -" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "[!] would you add all changing files? [y / n]" << std::endl;
    std::string add_status;
    std::getline(std::cin , add_status);
    if((add_status == "y") || (add_status == "Y")){
        std::string system_cmd = "git add ." ; 
        system(system_cmd.c_str());
        std::cout << "[+] added successfully!" << std::endl;
    }else if((add_status == "n") || (add_status == "N")){
        std::cout << "choose the filename to add..." << std::endl;
        std::string file_name;
        std::getline(std::cin , file_name);
        std::string system_cmd = "git add " + file_name ; 
        system(system_cmd.c_str());
    }
    }//END of add()

    void commit(){ //start of commit()
   if(add_number != 0){
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "-                                    -" << std::endl;
    std::cout << "-               commit               -" << std::endl;
    std::cout << "-                                    -" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Please write your commit message" << std::endl;
    std::string commit_msg;
    std::cin.ignore();  // Ignore the newline character left by previous `cin`
    std::getline(std::cin, commit_msg);
    std::string system_cmd = "git commit -m \"" + commit_msg + "\""; // Commit command
    std::cout << system_cmd << std::endl;
    system(system_cmd.c_str());
    commits_number++;
   }else{
    std::cout << "Nothing added...can not commit. add then try to commit again..." << std::endl;
   }
    }//End of commit()

    void push(){ //start of push()
    if(commits_number != 0){
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "-                                    -" << std::endl;
        std::cout << "-                push                -" << std::endl;
        std::cout << "-                                    -" << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        
        std::string system_cmd = "git push origin " + current_branch ; 
        int push_status = system(system_cmd.c_str());
        if(push_status == 0){
            std::cout << "[+] pushed successfully!" << std::endl;
            add_number     = 0;
            commits_number = 0;
        }else{
            std::cout << "[-] Failed to push. Please check the branch and try again." << std::endl;
        }
 
    }else{
        std::cout << "Nothing on the stage to push.";
    }
    }//end of push()

    void clone(const std::string& url){
        std::string system_cmd = "git clone " + url ; 
        system(system_cmd.c_str());
    }
    void check_status(){
        std::string system_cmd = "git status" ; 
        system(system_cmd.c_str());
    }
    void view_log(){
        std::string system_cmd = "git log" ; 
        system(system_cmd.c_str());
    }
    void create_branch(){
        std::cout << "Enter the branch name: " ;
        std::string branch;
        std::getline(std::cin , branch);
        current_branch = branch;
        std::string system_cmd = "git checkout " + branch ; 
        system(system_cmd.c_str());
    }
    void switch_branch(){
        std::cout << "Enter the branch name: " ;
        std::string branch;
        std::getline(std::cin , branch);
        current_branch = branch;
        std::string system_cmd = "git checkout " + branch ; 
        system(system_cmd.c_str());
    }
    void pull(){
        std::string system_cmd = "git pull "; 
        system(system_cmd.c_str());
    }

};

Git::Git()
{
    system("cd ..");
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "-                                    -" << std::endl;
    std::cout << "-               start                -" << std::endl;
    std::cout << "-                                    -" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "[-] This status before running the script." << std::endl;
    //system("git status");
}

Git::~Git()
{
}
#define EXIT_CMD                0
#define PULL_REMOTE_CMD         1
#define PUSH_REMOTE_CMD         2
#define ADD_FILE_CMD            3
#define COMMIT_CHANGES_CMD      4
#define VIEW_LOG_CMD            5
#define CREATE_BRANCH_CMD       6
#define SWITCH_BRANCH_CMD       7
#define CLONE_CMD               8
#define CHECK_STS_CMD           9

void DisplayMenu(){
        std::cout << "Choose option: " << std::endl;
        std::cout << "1- pull remote repo" << std::endl;
        std::cout << "2- push remote repo" << std::endl;
        std::cout << "3- add file" << std::endl;
        std::cout << "4- commit changes" << std::endl;
        std::cout << "5- view log" << std::endl;
        std::cout << "6- create branch" << std::endl;
        std::cout << "7- switch branch" << std::endl;
        std::cout << "8- clone remote repo" << std::endl;
        std::cout << "9- check status" << std::endl;
        std::cout << "0- Exit" << std::endl;
}

int main(int argc, char const *argv[])
{
    Git git;

    int user_choice = 10;

    while (user_choice != EXIT_CMD)
    {
        DisplayMenu();
        std::cin >> user_choice ;
        std::cin.ignore(); // To clear input buffer
        switch (user_choice)
        {
        case PULL_REMOTE_CMD:
            git.pull();
            break;
        case PUSH_REMOTE_CMD:
            git.push();
            break;
        case ADD_FILE_CMD:
            git.add();
            break;
        case COMMIT_CHANGES_CMD:
            git.commit();
            break;
        case VIEW_LOG_CMD:
            git.view_log();
            break;
        case CREATE_BRANCH_CMD:
            git.create_branch();
            break;
        case SWITCH_BRANCH_CMD:
            git.switch_branch();
            break;
        case CLONE_CMD:
            std::string url;
            std::cout << "Enter the repository URL: ";
            // std::cin.ignore();  // Ignore the newline character left by previous `cin`
            std::getline(std::cin, url);
            git.clone(url);
            break;
        case CHECK_STS_CMD:
            git.check_status();
            break;
        case EXIT_CMD:
            std::cout << "Exiting program..." << std::endl;
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
    }
    

    return 0;
}
