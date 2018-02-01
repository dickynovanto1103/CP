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
	int tc,a,b,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&a,&b,&k);
		int banyakMaksLaki = a/b;
		if(a%b!=0){banyakMaksLaki++;}
		if(banyakMaksLaki>2){printf("mustahil\n"); continue;}
		
	}
	return 0;
};