#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;

mutex m;

void foo(int a){
    m.lock();
    // it took too long so i commented it out
    // sleep(5);

    cout << a << endl;
    m.unlock();
}

int main(){
    thread threads[20];

    for(int i=0; i < 20; i++){
        threads[i] = thread(foo, i);
    }

    for(int i=0; i < 20; i++){
        threads[i].join();
    }
}