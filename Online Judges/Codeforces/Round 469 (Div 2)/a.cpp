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
	int l,r,a;
	scanf("%d %d %d",&l,&r,&a);
	while(true){
		if(a==0){break;}
		if(l<=r){
			while(l<=r){
				l++; a--;
				if(a==0){break;}
			}
		}else{
			while(l>r){
				r++; a--;
				if(a==0){break;}
			}
		}
		if(a==0){break;}
	}
	printf("%d\n",2*min(l,r));
	
	return 0;
};