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
	int n,i,j;
	string kata[1010];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	int maks = 0;
	for(i=0;i<7;i++){
		int counter = 0;
		for(j=0;j<n;j++){
			if(kata[j][i]=='1'){counter++;}
		}
		maks = max(maks,counter);
	}
	printf("%d\n",maks);
	return 0;
};