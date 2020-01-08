#include <iostream>       // std::cout
#include <thread>         // std::thread
#include<string>
#include<mutex>
std::mutex m;
class GettingStarted
{
    private:
        /* data */
    public:
        GettingStarted(/* args */);
        ~GettingStarted();
        void threadFunction(std::string str)
        {
	    std::lock_guard<std::mutex> lockGuard(m);
            std::cout<<"Call to threadFunction with param "<<str<<std::endl;
        }
	void operator()(std::string str)
	{
	    std::lock_guard<std::mutex> lockGuard(m);
	    std::cout<<"Call to Function Object, operator() with param "<<str<<std::endl;
	}
	void operator()( )
        {
            std::lock_guard<std::mutex> lockGuard(m);
	    std::cout<<"Call to no-arg Function Object, operator()"<<std::endl;
        }
};

GettingStarted::GettingStarted(/* args */)
{
     std::cout<<"Call to Constructor"<<std::endl;
}

GettingStarted::~GettingStarted()
{
    std::cout<<"Call to Destructor "<<std::endl;
}

int main()
{
    GettingStarted obj;
    std::string str = "Demo";
    std::thread t1(&GettingStarted::threadFunction,&obj,str);
    std::thread t2(obj,str);
    std::thread t3(obj);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}

