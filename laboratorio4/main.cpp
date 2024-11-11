#include <iostream>
#include "myVector2.cpp"
using namespace std;

int main(){
    // double a[] = {4,5,5};
    // myVector2 vector(3,a);

    myVector2 vect = {3,4,5};

    cout<<vect[2]<<endl;

    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);



    cout<<vect[7]<<endl;

    vect.pop_back();
    cout<<vect[6]<<endl;
    // cout<<vect[7]<<endl;
    // cout<<vect.at(7)<<endl;

    vect.push_back(10);
    cout<<vect[7]<<endl;


    return 0;
}