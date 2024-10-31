#include <iostream>
#include <vector>
using namespace std;


void print(string s, vector<int> v)
{
	cout<<s<<endl;
	
	for(int i=0; i<v.size();i++){
		cout<<v[i]<<endl;
	}
	
}



int main()
{
	vector<int> vettore = {2,4,5};
	string s = "ciao";
	print(s,vettore);
	return 0;
}

