#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[110];

bool isAllBenar(int n){
	for(int i=0;i<=n;i++){
		if(a[i]!=1){return false;}
	}
	return true;
}
bool adaNegatifdanPositif(int n){
	int i,j;
	for(i=0;i<=n;i++){
		if(a[i]>1){//cari negatifnya
			for(j=0;j<=n;j++){
				if(a[j]==a[i]*-1){return true;}
			}
		}
	}
	return false;
}

int main() {
	int tc,i;
	string kata;
	scanf("%d",&tc);
	cin>>ws;
	while(tc--){
		for(i=0;i<101;i++){a[i] = -inf;}
		cin>>kata;
		int n = kata.length();
		int cnt = 0;
		bool found = false;
		for(i=0;i<n;i++){
			
			if(kata[i]=='B'){a[cnt] = 1;}
			else if(kata[i]=='S'){a[cnt] = 0; printf("salah\n"); found = true; break;}
			else if(kata[i]=='^'){cnt++;}
			else{
				if(kata[i]=='~'){//lihat kata selanjutnya
					//hitung berapa jumlah ~
				
					i=i+1;
					//printf("j: %d i: %d\n",j,i);
					if(kata[i]=='B'){
						a[cnt] = 0; printf("salah\n"); found = true; break;
					}
					else if(kata[i]=='S'){
						a[cnt] = 1;
					}else{
						char kar = kata[i];
						int bil = kar;
						a[cnt] = -bil;
					}
				}else{
					char kar = kata[i];
					int bil = kar;
					a[cnt] = bil;
				}
			}
			//printf("membaca kata[%d]: %c dengan a[%d] = %d\n",i,kata[i], cnt, a[cnt]);
			//printf("a[%d] = %d\n",cnt,a[cnt]);
		}
		/*for(i=0;i<=cnt;i++){
			if(i){printf(" ");}
			printf("%d",a[i]);
		}
		printf("\n");*/
		if(!found){
			if(isAllBenar(cnt)){printf("benar\n");}
			else{
				if(adaNegatifdanPositif(cnt)){printf("salah\n");}
				else{printf("mungkin\n");}
			}
		}
		
		
	}
	return 0;
}