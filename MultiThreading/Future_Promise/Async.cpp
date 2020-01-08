#include<iostream>
#include<thread>
#include<future>
int asyncFunc()
{
    std::cout<<"Async Thread ID ="<<std::this_thread::get_id()<<std::endl;
    return 10;
}

int main()
{
    std::cout<<"Main Thread ID = "<<std::this_thread::get_id()<<std::endl;
    std::future<int> fn = std::async(std::launch::async, asyncFunc);  
    int returnValue = fn.get();
    std::cout<<"Return value stored in std::future object "<<returnValue<<std::endl;  
    return 0;
}
