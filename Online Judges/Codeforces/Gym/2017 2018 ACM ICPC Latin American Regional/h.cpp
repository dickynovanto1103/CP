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
	int a[3],b[3],i,j;
	int sum = 0;
	for(i=0;i<3;i++){scanf("%d",&a[i]);}
	for(i=0;i<3;i++){scanf("%d",&b[i]);}
	for(i=0;i<3;i++){
		if(b[i] > a[i]){
			sum += b[i] - a[i];
		}
	}
	printf("%d\n",sum );
	
	return 0;
};