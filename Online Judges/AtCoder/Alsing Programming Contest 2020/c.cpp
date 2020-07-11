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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j,k;
	scanf("%d",&n);
	int cnt[10001];
	for(i=1;i<=10000;i++){
		cnt[i] = 0;
	}
	for(i=1;i<=100;i++){
		for(j=1;j<=100;j++){
			for(k=1;k<=100;k++){
				int tot = i*i + j*j + k*k + i*j + i*k + j*k;
				if(tot <= 10000){
					cnt[tot]++;
				}
			}
		}
	}

	for(i=1;i<=n;i++){
		printf("%d\n",cnt[i]);
	}
	
	return 0;
};