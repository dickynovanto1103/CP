#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[95],i;
	string kata;
	memset(a,0,sizeof a);
	/*
	2 represents C, G, J, K, Q, S, X, or Z
	3 represents D or T
	4 represents L
	5 represents M or N
	6 represents R
	*/
	a['B'] = a['F'] = a['P'] = a['V'] = 1;
	a['C'] = a['G'] = a['J'] = a['K'] = a['Q'] = a['S'] = a['X'] = a['Z'] = 2;
	a['D'] = a['T'] = 3;
	a['L'] = 4;
	a['M'] = a['N'] = 5;
	a['R'] = 6;
	
	while(cin>>kata){
		int ukuran = kata.length();
		int curbil = 0;
		string ans = "";
		for(i=0;i<ukuran;i++){
			char kar = kata[i];
			int bil = a[kar];
			//printf("kar: %c bil: %d\n",kar,bil);
			if(bil==0){curbil = 0;}
			if(bil!=curbil && bil!=0){
				char karbaru = bil+48;
				//printf("karbaru: %c\n",karbaru);
				ans+=karbaru;
				curbil = bil;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}