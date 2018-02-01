#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int i,a[15];
	int n = 14;
	char kar[]={'h','a','l','o',' ','m','a','r','a','n','a','t','h','a'};
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			printf("%c",kar[i]);
		}
	}
	return 0;
}