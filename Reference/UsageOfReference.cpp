#include<iostream>

class UsageOfReference
{
    private:
        /* data */
    public:
       UsageOfReference(int & x);
       ~UsageOfReference();
};

UsageOfReference::UsageOfReference(int & x)
{
     std::cout<<"Initial value of X in constructor = "<<x<<std::endl;
     x++;
     std::cout<<"X is modified in constructor = "<<x<<std::endl;
}

UsageOfReference::~UsageOfReference()
{
}

int main()
{
    int a = 5;
    UsageOfReference obj(a);
    std::cout<<"Modied value of X reflected in main = "<<a<<std::endl;
}
