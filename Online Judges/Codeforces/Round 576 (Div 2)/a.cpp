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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,x,y,i,j;
	scanf("%d %d %d",&n,&x,&y);
	map<int,int> mapper;
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		mapper[a[i]] = i;
	}
	int start = 0, end = x+y;
	for(i=0;i<n;i++){
		int minim = a[i];
		int kiri = max(i - x,0);
		int kanan = min(i+y, n-1);
		bool valid = true;
		for(j=i-1;j>=kiri;j--){
			if(minim > a[j]){valid = false; break;}
		}
		for(j=i+1;j<=kanan;j++){
			if(minim > a[j]){valid =false; break;}
		}
		if(valid){printf("%d\n",i+1); return 0;}
	}
	return 0;
};