#include <bits/stdc++.h>

using namespace std;
#define inf 500000000
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

const int maxn = 1e3 + 4;

int a[maxn];

bool isSorted(int l, int r) {
	int i,j;
	for(i=l+1;i<=r;i++){
		if(a[i] >= a[i-1]){

		}else{
			return false;
		}
	}
	return true;
}

bool solve(int l, int r) {
	bool isAllVisited = true;
	int i,j;
	for(i=l;i<=r;i++){
		if(a[i] == -1){isAllVisited = false;}
	}
	if(isAllVisited){
		if(isSorted(l, r)){
			return false;
		}
	}else{
		int cur = inf*2;
		for(i=l;i<=r;i++){
			if(a[i] == -1){a[i] = cur-1;}
			cur = a[i];
		}
		if(isSorted(l,r)){
			assert(false);
		}
	}
	return true;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	
	memset(a, -1, sizeof a);
	vii listNol, listSatu;
	for(i=0;i<m;i++){
		int type, l,r;
		scanf("%d %d %d",&type, &l,&r);
		l--; r--;
		if(type == 1) {
			listSatu.pb(ii(l,r));
		}else{
			listNol.pb(ii(l,r));
		}
	}
	sort(listSatu.begin(), listSatu.end());
	sort(listNol.begin(), listNol.end());
	int bil = inf;
	int last = 0;
	for(i=0;i<listSatu.size();i++){
		ii pas = listSatu[i];
		int l = pas.first, r = pas.second;
		if(a[l] == -1){
			int selisih = l - last;
			bil-=selisih;
		}
		for(j=l;j<=r;j++){
			a[j] = bil;
		}
		last = r;
	}
	for(i=0;i<listNol.size();i++){
		ii pas = listNol[i];
		int l = pas.first, r = pas.second;
		if(solve(l, r)){

		}else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=0;i<n;i++){
		if(a[i] == -1){a[i] = inf;}
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
};