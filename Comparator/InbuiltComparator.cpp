#include<iostream>
#include<Map>
#include<algorithm>
template<typename type>
struct myComparator
{
      bool operator()(const type &First, const type &Second) const
      { return First.second < Second.second; }
};

int main()
{
    std::map<int,int> defaultSortingMap;
    defaultSortingMap[10] = 100;
    defaultSortingMap[20] = 200;
    defaultSortingMap[15] = 150;

    std::cout<<"By default Map is sorted in accending ord of key(By default lesser comprt is passed) "<<std::endl;
    for(auto &iter : defaultSortingMap)
        std::cout<<iter.first<<"  "<<iter.second<<std::endl;
//------------------------------------------------------------------------------------
    std::map<int,int,std::greater<int>> keySortedMap;
    keySortedMap[10] = 100;
    keySortedMap[20] = 200;
    keySortedMap[15] = 150;

    std::cout<<"\n\nMap is sorted in dccending ord of key(greater comprt is passed)"<<std::endl;
    for(auto &iter:keySortedMap)
        std::cout<<iter.first<<"  "<<iter.second<<std::endl;
//---------------------------------------------------------------------------------------------
    std::map<int,int,myComparator<int,int>> valueSortedMap;
    valueSortedMap[10] = 100;
    valueSortedMap[20] = 150;
    valueSortedMap[15] = 200;

    std::cout<<"\n\nMap is sorted in dccending ord of key(greater comprt is passed)"<<std::endl;
    for(auto &iter:valueSortedMap)
        std::cout<<iter.first<<"  "<<iter.second<<std::endl;
//--------------------------------------------------------------------------------------------


    
}