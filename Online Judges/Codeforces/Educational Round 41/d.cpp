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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;
bool valid = false;
bool isVisited[maxn];
int n;
ll x[maxn], y[maxn];
vi listIdx;

ll cross(ii a, ii b){
	return a.first*b.second - a.second*b.first;
}

bool isAllVisited(){
	for(int i=0;i<n;i++){
		if(!isVisited[i]){return false;}
	}
	return true;
}

void check2(int n){
	if(n<=2){
		memset(isVisited,true,sizeof isVisited);
		return;
	}
	int acuan = listIdx[0], idx = listIdx[1];
	ii vec = ii(x[idx] - x[acuan], y[idx] - y[acuan]);
	isVisited[idx] = isVisited[acuan] = true;
	for(int i=2;i<n;i++){
		int indeks = listIdx[i];
		ii vec1 = ii(x[indeks] - x[acuan], y[indeks] - y[acuan]);
		// printf("i: %d\n",i);
		// printf("check2\n");
		// printf("vec1: %lld %lld vec: %lld %lld cross: %lld\n",vec1.first, vec1.second, vec.first, vec.second, cross(vec,vec1));
		if(cross(vec, vec1)==0){isVisited[indeks]=true;}
	}
	listIdx.clear();
}

bool check(int acuan, int idx){
	// printf("acuan: %d idx: %d\n",acuan, idx);
	memset(isVisited,false,sizeof isVisited);
	ii vec = ii(x[idx]-x[acuan], y[idx]-y[acuan]);
	isVisited[idx] = isVisited[acuan] = true;
	for(int i=0;i<n;i++){
		if(isVisited[i]){continue;}
		ii vec1 = ii(x[i] - x[acuan], y[i] - y[acuan]);
		// printf("i: %d\n",i);
		// printf("vec1: %lld %lld vec: %lld %lld cross: %lld\n",vec1.first, vec1.second, vec.first, vec.second, cross(vec,vec1));
		if(cross(vec, vec1)==0){
			// printf("i: %d\n",i);
			isVisited[i] = true;
		}
	}

	for(int i=0;i<n;i++){
		if(isVisited[i]){continue;}
		listIdx.pb(i);
		// printf("yang dipush: %d\n",i);
	}
	// printf("\n");
	check2(listIdx.size());

	if(isAllVisited()){
		return true;
	}else{
		return false;
	}
}

int main(){
	int i,j;
	// printf("%.2lf\n",hypot(3,4));
	scanf("%d",&n);
	if(n<=4){printf("YES\n"); return 0;}
	for(i=0;i<n;i++){
		scanf("%lld %lld",&x[i],&y[i]);
	}
	
	if(check(0,1) || check(0,2) || check(1,2)) {
		printf("YES\n");
	}else{
		printf("NO\n");
	}

	return 0;
};