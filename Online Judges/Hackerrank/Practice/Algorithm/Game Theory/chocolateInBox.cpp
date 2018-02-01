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

int a[1000010];

int main(){
	int n,i;
	scanf("%d",&n);
	int sum = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]); sum^=a[i];
	}
	if(sum==0){printf("0\n");}
	else{
		int cnt = 0;
		for(i=0;i<n;i++){
			int temp = sum;	
			int bil = temp^a[i];
			if(a[i]>bil){cnt++;}
		}
		printf("%d\n",cnt);
	}
	return 0;
};