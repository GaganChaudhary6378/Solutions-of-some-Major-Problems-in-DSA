#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


int main(){
    unordered_map<string,int> ourmap;
    ourmap["abc"]=1;
    ourmap["def"]=2;
    ourmap["ghi"]=3;
    ourmap["jkl"]=4;
    ourmap["mnp"]=5;

    // Creating the iterator of unordered map

    unordered_map<string,int> :: iterator it=ourmap.begin(); // This iterator will point to the very first element or we can say the address of first element.

    // Now we are trying to print all the keys along with their values so for that we will use loop

    while(it!=ourmap.end()){
        cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;
        it++;
    }

    // Iterators in vectors

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>:: iterator it2=v.begin();

    while(it2!=v.end()){
        cout<<*it2<<endl;
        it2++;
    }

    // The find method gives us the iterator point to that element

    unordered_map<string,int> :: iterator it1=ourmap.find("ghi");

    // Similarly in erase function we can pass iterator as well and this will delete the element at that position

    ourmap.erase(it1);

    // Or we can pass range in erase function by providing start and end

    ourmap.erase(it1,ourmap.end());

}