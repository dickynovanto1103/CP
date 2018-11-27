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

const int maxn = 101;

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int idx;
	string arah;
	cin>>idx>>arah;
	idx--;
	int sum = 0;
	if(arah == "right"){

		for(i=idx;i<n;i++){
			sum += a[i];
		}
	}else{
		for(i=idx;i>=0;i--){
			sum += a[i];
		}
	}

	cin>>idx>>arah;
	idx--;
	int cnt = 0;
	if(arah == "right"){

		for(i=idx;i<n;i++){
			if(a[i] == 0){cnt++;}
		}
	}else{
		for(i=idx;i>=0;i--){
			if(a[i] == 0){cnt++;}
		}
	}	
	printf("%d %d\n",sum,cnt);
	return 0;
};