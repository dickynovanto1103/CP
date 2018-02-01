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
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int nAwal = n;
		if(n<38){printf("%d\n",n); continue;}
		while(n%5!=0){
			n++;
		}
		if((n-nAwal)<3){printf("%d\n",n);}
		else{printf("%d\n",nAwal);}

	}
	return 0;
};