#include <iostream>
#include <thread>

//THREADING

//function: task1
void task1(){
    std::cout << "Hello from task1!" << std::endl;
}


//function: task2
void task2(){
    std::cout << "Hello from task2!" << std::endl;
}

//function: task3
void task3(){
    int count = 0;
    while (1){
        std::cout << "Hello from task3! " << count << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count++;
        if(count == 30){
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    // std::thread t1(task1);
    // std::thread t2(task2);
    // //Main thread will wait till the t thread is ﬁnished
    // t1.join();
    // t2.join();

    //Inform main thread to detach the thread and stop it as same as main thread
    // t1.detach();
    // t2.detach();

    // std::cout << "msg1" << std::endl;
    // std::cout << "msg2" << std::endl;
    // std::cout << "msg3" << std::endl;
    // std::cout << "msg4" << std::endl;
    // std::cout << "msg5" << std::endl;
    // std::cout << "msg6" << std::endl;
    // std::cout << "msg7" << std::endl;
    // std::cout << "msg8" << std::endl;
    // std::cout << "msg9" << std::endl;
    // std::cout << "msg10" << std::endl;



    std::thread t(task3);
    t.join();
    int count=0;
    while(1){
        std::cout << "Hello, World! "<< count << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count++;
        if (count == 15)
        {
            break;
        }
        
    }

    return 0;
}
// [++++++] From Linux how to see threads: ps -auHx | grep a.out 
