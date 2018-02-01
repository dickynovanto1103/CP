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

int main(){
	int n,c;
	int a[100001];
	scanf("%d %d",&n,&c);
	for(int i=0;i<n;i++){scanf("%d",&a[i]);}
	int cnt = 1;
	for(int i=1;i<n;i++){
		if(a[i] - a[i-1]>c){cnt = 1;}
		else{cnt++;}
	}
	printf("%d\n",cnt);
	return 0;
};