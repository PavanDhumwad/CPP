#include<iostream>
class BaseClass
{
    public:
        virtual void Display()
        {
            std::cout<<"\n\tThis is Display() method of Base Class";
        }
        void Show()
        {
            std::cout<<"\n\tThis is Show() method of Base Class (A Non-Virtual function)";
        }

};
 
class DerivedClass : public BaseClass
{
    public:
        void Display()
        {
            std::cout<<"\n\tThis is Display() method of Derived Class (A virtual function)";
        }
        void Show()
        {
            std::cout<<"\n\tThis is Show() method of Derived Class";
        }

};
int main()
{
    DerivedClass D;
    BaseClass *B;
    B = new BaseClass;
    B->Display();  //This will invoke Display() method of Base Class
    B->Show();     //This will invoke Show() method of Base Class
    B=&D;
    B->Display(); //This will invoke Display() method of Derived Class bcoz Display() method is virtual in Base Class
    B->Show();    //This will invoke Show() method of Base Class bcoz Show() method is not virtual in Base Class
    return 0;
                                               
}
