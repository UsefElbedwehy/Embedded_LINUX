import threading
import time 

def task1(self):
    while True:
        print("Task1 says hello")
        time.sleep(1)

def task2(self):
    while True:
        print("Task2 says hello")
        time.sleep(1)



if __name__ == "__main__":

    t1 = threading.Thread(target=task1,args=(1,))
    t2 = threading.Thread(target=task2,args=(1,))

    t1.start()
    t2.start()

    t1.join()
    t2.join()

    print("Done")