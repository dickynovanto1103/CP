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

const int maxn = 2e5 + 5;
int a[maxn];

int main(){
	int n,k,i,j;
	
	bool isVisited[maxn], isVisitedAsli[maxn];
	memset(isVisited,false,sizeof isVisited);
	scanf("%d %d",&n,&k);
	int maks = 0;
	for(i=0;i<k;i++){
		scanf("%d",&a[i]);
		maks = max(maks,a[i]);
		isVisited[a[i]] = true;
		
	}
	int idx = k;
	for(i=k-1;i>=0;i--){
		int bil = a[i];
		int target = a[i+1];
		for(j=bil-1;j>target;j--){	
			if(isVisited[j]){
				break;
			}
			else{a[idx] = j; idx++;}
		}
	}
	stack<int> s;
	vector<int> b;
	
	for(i=n;i>maks;i--){
		
		a[idx] = i;
		idx++;
		isVisited[i] = true;
		
	}
	if(idx!=n){printf("-1\n"); return 0;}
	int harapan = 1;
	for(i=0;i<n;i++){
		if(a[i]==harapan){harapan++;}
		else{
			if(!s.empty()){
				while(s.top()==harapan){
					harapan++; s.pop();
					if(s.empty()){break;}
				}
				if(a[i]==harapan){harapan++;}
				else{s.push(a[i]);}
			}else{
				s.push(a[i]);
			}
		}
		
	}

	while(!s.empty()){
		if(s.top()==harapan){harapan++; s.pop();}
		else{printf("-1\n"); return 0;}
	}
	
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
};