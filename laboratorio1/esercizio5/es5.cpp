#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void print(string s, vector<int> v)
{
    cout << s << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

vector<int> fibonacci(int x, int y, int n)
{
    vector<int> arr;
    if (n <= 0)
    {
        return {0};
    }
    else if (n == 1)
    {
        arr.push_back(x);
        return arr;
    }
    else if (n >= 2)
    {
        arr.resize(n); // Imposta la lunghezza del vettore
        arr[0] = x;
        arr[1] = y;
        for (int i = 2; i < n; i++)
        {
            int number = arr[i - 1] + arr[i - 2];
            if(number < pow(2,31)){ // un intero può contenere 4 byte->32 bit quindi un numero massimo di 2^31-1
                arr[i] = number;
            }
            else{
                return arr;
            }
            
        }
        return arr;
    }
}


int main()
{
    string s = "ciao";
    vector<int> vettore = fibonacci(1, 2, 45); //45 numero massimo
    print(s, vettore);
    return 0;
}
