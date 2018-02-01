#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime[255];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int main(){
	int a,b;
	int tt,tc;
	memset(isprime,true,sizeof isprime);
	sieve(250);
	/*int cnt = 0;
	for(int i=0;i<=100;i++){
		if(isprime[i]){
			//printf("i: %d\n",i);
			cnt++;
		}
	}*/
	//printf("cnt: %d\n",cnt);
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&a,&b);
		int jml = a+b;
		bool found;
		if(isprime[jml]){found = true;}
		else{found = false;}
		if(found){printf("Cocok\n");}
		else{printf("Tidak Cocok\n");}
		
	}
	return 0;
};