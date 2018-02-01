#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    int a;
    double b;
    
    cin>>a>>b;

	string nama;

	getline(cin >> ws,nama);
	
	
	a+=i;
	b+=d;
    nama = s + nama;
	//cout<<"c adalah "<<nama<<endl;
	cout<<a<<endl;
    cout<<fixed;
    cout<<setprecision(1)<<b<<endl;
	cout<<nama<<endl;
	return 0;
}