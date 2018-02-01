#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int m,s,i;
	scanf("%d %d",&m,&s);
	if(s==0) {
		if(m==1){printf("0 0\n");}
		else{printf("-1 -1\n");}
		return 0;
	}
	if(s>(9*m)){printf("-1 -1\n"); return 0;}
	
	vi listAngka;

	while(s>0) {
		int angka = min(9,s);
		listAngka.pb(angka);
		s-=angka;
	}
	if(listAngka.size()==m){
		//langsung output
		for(i=listAngka.size()-1;i>=0;i--){printf("%d",listAngka[i]);}
		printf(" ");
		
		for(i=0;i<listAngka.size();i++){printf("%d",listAngka[i]);}
		printf("\n");
	}else{//pasti lebih kecil dari 
		//iterasi dari belakang sampe ke depan..cari yang lebih dari 1
		ll maks = 0;
		int sisaPanjang = m-listAngka.size();
		//tambah 0;
		for(i=0;i<sisaPanjang;i++){listAngka.pb(0);}
		vi listAngkaMaks = listAngka;

		for(i=listAngka.size()-1;i>=0;i--){
			if(listAngka[i]!=0){
				listAngka[i]--;
				listAngka[m-1] = 1;
				break;
			}
		}

		//print minimum
		for(i=listAngka.size()-1;i>=0;i--){
			printf("%d",listAngka[i]);
		}
		printf(" ");
		for(i=0;i<listAngkaMaks.size();i++){
			printf("%d",listAngkaMaks[i]);
		}
		printf("\n");
	}
	
	return 0;
};