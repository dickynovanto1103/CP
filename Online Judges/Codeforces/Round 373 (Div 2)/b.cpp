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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	string kata; cin>>kata;
	int a[maxn], harus1[maxn], harus2[maxn];
	int temp[maxn];
	for(i=0;i<n;i++){
		if(kata[i]=='r'){a[i] = 0;}
		else{a[i] = 1;}
		temp[i] = a[i];
	}
	harus1[0] = 0; harus2[0] = 1;
	for(i=1;i<n;i++){
		harus1[i] = 1-harus1[i-1];
		harus2[i] = 1-harus2[i-1];
	}

	//coba apply ke harus 1
	int ans = inf;
	int cnt = 0;
	int cnt0 = 0, cnt1 = 0;;

	for(i=0;i<n;i++){
		if(temp[i]!=harus1[i]){
			if(temp[i]==0){cnt0++;}
			else{cnt1++;}
		}
	}
	cnt = min(cnt1,cnt0);
	cnt+=(max(cnt1,cnt0) - min(cnt1,cnt0));
	ans = min(ans,cnt);

	//ke harus2
	cnt = 0;
	cnt0 = cnt1 = 0;

	for(i=0;i<n;i++){
		if(temp[i]!=harus2[i]){
			if(temp[i]==0){cnt0++;}
			else{cnt1++;}
		}
	}
	cnt = min(cnt1,cnt0);
	cnt+=(max(cnt1,cnt0) - min(cnt1,cnt0));
	ans = min(ans,cnt);

	printf("%d\n",ans);
	return 0;
};