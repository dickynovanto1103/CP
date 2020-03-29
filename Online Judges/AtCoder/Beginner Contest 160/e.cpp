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

const int maxn = 1e5 + 5;

int main(){
	int x,y,a,b,c,i,j;
	scanf("%d %d %d %d %d",&x,&y,&a,&b,&c);
	int ar1[maxn], ar2[maxn], ar3[maxn];
	for(i=0;i<a;i++){
		scanf("%d",&ar1[i]);
	}
	for(i=0;i<b;i++){
		scanf("%d",&ar2[i]);
	}
	for(i=0;i<c;i++){
		scanf("%d",&ar3[i]);
	}
	sort(ar1, ar1+a);
	sort(ar2, ar2+b);
	priority_queue<int, vi, greater<int> > pq1, pq2;
	int idx = a-1;
	for(i=0;i<x;i++){
		pq1.push(ar1[idx]);
		// printf("push: %d\n",ar1[idx]);
		idx--;
	}
	idx = b-1;
	for(i=0;i<y;i++){
		pq2.push(ar2[idx]);
		// printf("push: %d\n",ar2[idx]);
		idx--;
	}
	for(i=0;i<c;i++){
		int bil = ar3[i];
		int minim1 = pq1.top(), minim2 = pq2.top();
		int minim = min(minim1, minim2);
		if(minim >= bil){continue;}
		if(minim == minim1){
			pq1.pop();
			pq1.push(bil);
			// printf("pq1 push %d\n",bil);
		}else{
			pq2.pop();
			pq2.push(bil);
			// printf("pq2 push %d\n",bil);
		}
	}
	ll sum = 0;
	while(!pq1.empty()){
		sum += pq1.top(); pq1.pop();
	}
	while(!pq2.empty()){
		sum += pq2.top(); pq2.pop();
	}
	printf("%lld\n",sum);
	return 0;
};