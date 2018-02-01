#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

bool isSorted(string angka) {
	int i;
	int n = angka.length();
	
	bool found = true;
	for(i = 0; i < n-1; i++) {
		if(angka[i]> angka[i+1]) {found = false; break;}
	}
	return found;
}

int idxfind(string angka){
	int i,idx;
	int n = angka.length();
	for(i = 0; i < n-1; i++) {
		if(angka[i]> angka[i+1]) { idx =i;break;}
	}
	return idx;
}

int main() {
	int tc,test=1,i;
	string angka;
	bool found;
	scanf("%d",&tc);
	while(tc--) {
		printf("Case #%d: ",test++);
		cin>>angka;
		//cout<<angka<<endl;
		int n = angka.length();
		while(!isSorted(angka)){
			int idx = idxfind(angka);
			int bil = angka[idx];
			//printf("karakter awal: %c idx: %d bil: %d\n",angka[idx],idx, bil);
			bil-=48;
			bil--;
			char karakter = bil+48;
			//printf("pada idx: %d karakter jd %c\n",idx,karakter);
			angka[idx] = karakter;
			for(i=idx+1;i<n;i++){angka[i]='9';}
		}
		for(i=0;i<n;i++){
			if(angka[i]!='0'){printf("%c",angka[i]);}
		}
		printf("\n");
	}
	return 0;
}
