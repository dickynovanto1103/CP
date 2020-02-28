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

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	if(a > b){
		if(a == 9 && b == 1){
			printf("9 10\n");
		}else{
			printf("-1\n");
		}
	}else if(a == b){
		printf("%d11 %d12\n",a,b);
	}else{
		if(b - a == 1){
			printf("%d %d\n",a,b);
		}else{
			printf("-1\n");
		}
	}
	return 0;
};