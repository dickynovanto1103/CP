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
	int n;
	string kata;
	int cnt1 = 0, cnt0 = 0;
	cin>>n>>kata;
	int i;
	for(i=0;i<n;i++){
		if(kata[i] == '1'){
			cnt1++;
		}else{
			cnt0++;
		}
	}

	if(cnt1==0){printf("0\n");}
	else{
		printf("1");
		for(i=0;i<cnt0;i++){printf("0");}
		printf("\n");
	}
	return 0;
};