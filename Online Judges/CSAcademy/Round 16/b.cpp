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
	int n,i,j;
	int a[10];
	scanf("%d",&n);

	int correct = 0;
	for(i=9;i>=0;i--){
		printf("Q ");
		for(j=correct;j<n;j++){a[j] = i;}
		for(j=0;j<n;j++){printf("%d",a[j]);}
		printf("\n");
		fflush(stdout);

		scanf("%d",&correct);
		if(correct == n){
			printf("A ");
			for(j=0;j<n;j++){printf("%d",a[j]);}
			printf("\n");
			fflush(stdout);
			return 0;
		}
		

	}
	return 0;
};