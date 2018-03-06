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
	int tc,m,n,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Kasus #%d: ",tt);
		scanf("%d %d",&m,&n);
		int bil = m-n;
		int cnt = 0;
		for(i=1;i*i<=bil;i++){
			if(bil%i==0){
				int bil1 = i;
				int bil2 = bil/i;
				if(bil1==bil2){
					if(m%bil1==n){cnt++;}
				}else{
					if(m%bil1==n){cnt++;}
					if(m%bil2==n){cnt++;}	
				}
				
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
};