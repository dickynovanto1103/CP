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

const int maxn = 1e7 + 1;
ii pas[maxn+10];

int main(){
	int n,i;
	pas[1].first = 1; pas[1].second = 1;
	pas[2].first = 1; pas[2].second = 2;
	bool kurangPenyebut = true;
	for(i=3;i<maxn;i++){
		if(kurangPenyebut){
			pas[i].first = pas[i-1].first+1;
			pas[i].second = pas[i-1].second-1;
			if(pas[i].second==1){
				i++;
				pas[i].first = pas[i-1].first+1; pas[i].second = pas[i-1].second;
				kurangPenyebut = false;
			}
		}else{
			pas[i].first = pas[i-1].first-1;
			pas[i].second = pas[i-1].second+1;
			if(pas[i].first==1){
				i++;
				pas[i].second = pas[i-1].second+1; pas[i].first = pas[i-1].first;
				kurangPenyebut = true;
			}
		}
		
	}
	int idx;
	while(scanf("%d",&idx)!=EOF){
		printf("TERM %d IS %d/%d\n",idx,pas[idx].first,pas[idx].second);
	}
	
	return 0;
};