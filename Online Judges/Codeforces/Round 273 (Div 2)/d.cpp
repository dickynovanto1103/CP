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
	int a,b,i;
	int arr[1000];
	int sum = 0;
	for(i=1;;i++){
		sum+=i;
		arr[i] = sum;
		if(arr[i]>400000){break;}
	}
	int idx = i;
	scanf("%d %d",&a,&b);
	sum = a+b;
	int banyakMaks = lower_bound(arr+1,arr+idx+1,sum) - (arr);
	printf(" maks: %d\n",banyakMaks);
	// for(i=1;i<=idx;i++){
	// 	printf("arr[%d]: %d\n",i,arr[i]);	
	// }

	
	return 0;
};