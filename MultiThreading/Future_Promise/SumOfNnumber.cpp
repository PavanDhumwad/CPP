#include<iostream>
#include<thread>
#include<future>
#include<chrono>
using namespace std::chrono;
class SumOfNnumber
{
    public:
    void findSumOfNnumber(int n, std::promise<int> *promObj)
    {
	//Can't use Reference in thread
        int sum = 0;
        for(int i=1; i<=n; i++)
            sum+=i;
	std::this_thread::sleep_for(seconds(10));
        promObj->set_value(sum);
    }
};
int main()
{
    SumOfNnumber obj;
    int num = 10;
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    std::thread t1(&SumOfNnumber::findSumOfNnumber, &obj, num, &promiseObj);
    std::cout<<"Blocked for 10sec"<<std::endl;    
    std::cout<<"S("<<num<<") = "<<futureObj.get()<<std::endl;
    std::cout<<"Unblocked"<<std::endl;
    t1.join();
}
