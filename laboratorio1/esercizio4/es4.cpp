#include <iostream>
#include <vector>
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
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr;
    }
}

int main()
{
    string s = "ciao";
    vector<int> vettore = fibonacci(1, 2, 500);
    print(s, vettore);
    return 0;
}
