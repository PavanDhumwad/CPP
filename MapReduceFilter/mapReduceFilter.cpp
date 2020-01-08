#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
int main()
{
    std::vector<int> vin  {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vout(vin.size());
    //map
    std::cout<<"Map"<<std::endl;
    std::transform(vin.begin(),vin.end(),vout.begin(),[](int &value){return value*3;});
    for(auto &iter:vout)
        std::cout<<iter<<std::endl;

    //reduce
    int finalValue = std::accumulate(vout.begin(),vout.end(),0,[](int first, int second){return first+second;});
    std::cout<<"Final value = "<<finalValue<<std::endl;

    //filter
    std::cout<<"Filter"<<std::endl;
    auto endIter = std::remove_if(vout.begin(),vout.end(),[](int &value)
                                                        {
                                                            if(value%2==0)
                                                                return true;
                                                            return false;
                                                        });
    for(auto  iter=vout.begin(); iter!=endIter; iter++)
         std::cout<<*iter<<std::endl;
    return 0;

}