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

const int maxn = 104;
int x[maxn], y[maxn];
int n;

bool isExistPinggir(int banyak){
	int i,j;
	for(i=0;i<banyak;i++){
		if(x[i] == 0 || x[i] == (n-1) || y[i] == 0 || y[i] == (n-1)){
			return true;
		}
	}
	return false;
}

bool isExistDuaBerhadapan(int banyak){
	int i,j;
	int kiri = 0, kanan = 0, atas = 0, bawah = 0;
	for(i=0;i<banyak;i++){
		if(x[i] == 0){kiri++;}
		else if(x[i] == (n-1)){kanan++;}
		if(y[i] == 0){atas++;}
		else if(y[i] == (n-1)){bawah++;}
	}
	if(kiri && kanan){return true;}
	if(atas && bawah){return true;}
	return false;
}

bool isExistPojok(int banyak){
	int i,j;
	for(i=0;i<banyak;i++){
		if((x[i] == 0 && y[i] == (0))){return true;}
		if(x[i] == 0 && y[i] == (n-1)){return true;}
		if(x[i] == (n-1) && y[i] == 0){return true;}
		if(x[i] == (n-1) && y[i] == (n-1)){return true;}
	}
	return false;	
}

int main(){
	int tc,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&k,&n);
		int i,j;
		
		for(i=0;i<k;i++){
			scanf("%d %d",&x[i],&y[i]);
		}
		if(isExistPojok(k)){printf("yes\n"); continue;}
		if(k>=4){printf("yes\n");}
		else{
			if(k==3){
				//cek ada ga yang salah satu di pinggir
				if(isExistPinggir(k)){printf("yes\n");}
				else{printf("no\n");}
			}else if(k==2){
				if(isExistDuaBerhadapan(k)){printf("yes\n");}
				else{printf("no\n");}
			}else{
				printf("no\n");
			}
		}
	}
	return 0;
};