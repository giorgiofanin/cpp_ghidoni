#include <iostream>

using namespace std;

//l' unica scelta è stata usare una variabile globale
int count = 0; 


void  call_counter(void){
    count +=1;
}

int main(){
    call_counter();
    call_counter();
    call_counter();
    call_counter();
    
    cout<<"Il count è "<< count<< endl;
    return 0;
}