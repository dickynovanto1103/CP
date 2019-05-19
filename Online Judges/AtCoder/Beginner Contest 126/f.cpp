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

int main(){
	int m,k,i,j;

	scanf("%d %d",&m,&k);
	int sor = 0;
	for(i=0;i<(1<<m);i++){
		if(i != k){
			sor ^= i;
		}
	}
	if(k == 0){
		for(i=0;i<(1<<(m));i++){
			if(i){printf(" ");}
			printf("%d %d",i,i);
		}
		printf("\n");
		return 0;
	}
	// printf("sor: %d\n",sor);
	if(sor == k){
		deque<int> q;
		q.pb(k);
		for(i=0;i<(1<<m);i++){
			if(i != k){
				q.pb(i);
				q.push_front(i);
			}
		}
		q.pb(k);
		bool first = true;
		for(int i=0;i<q.size();i++){
			if(!first){printf(" ");}

			printf("%d", q[i]);
			first = false;
		}
		printf("\n");
	}else{
		printf("-1\n");
	}
	return 0;
};