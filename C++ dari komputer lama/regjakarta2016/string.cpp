#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);
	string kata,temp;
	int hari,bulan,tahun;
	cin>>kata;
	temp=kata[0]+kata[1];
	hari=stoi(temp);
	bulan=stoi(kata[3]+kata[4]);
	tahun=stoi(kata[6]+kata[7]);
	printf("%d %d %d\n",hari,bulan,tahun);
	return 0;
}