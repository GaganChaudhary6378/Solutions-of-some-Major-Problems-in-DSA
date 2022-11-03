#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;


int main(){
    unordered_map<string,int> mymap;

    // Inserting an element

    // Method 1
    pair<string,int> p("abc",1);
    // pair class has its own constructor
    mymap.insert(p);

    // Method 2
    // It is similar to what we do in array
    mymap["def"]=2;


    // Accessing the elements

    cout<<mymap["abc"]<<endl;
    cout<<mymap.at("abc")<<endl;

    // To check the size of map

    cout<<"size : "<<mymap.size()<<endl;

    // cout<<mymap.at("ghi")<<endl; will give an error because it does not exist in the map 

    cout<<mymap["ghi"]<<endl; // This will not give an error instead it would make a entry of ghi in map and assign its value to 0.

    cout<<"size : "<<mymap.size()<<endl;


    // To check the presence of any key in map

    if(mymap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }

    // To erase the key from a map

    mymap.erase("ghi");

    if(mymap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }
    cout<<"size : "<<mymap.size()<<endl;

    // Note: In a map a particualr key can not be more than 1 time either it will be 0 or 1
}