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

struct pasangan{
	string kata;
	int pjg;
};

bool cmp(string a, string b) {

	return a.length() < b.length();
}

int main(){
	int n,i,j;
	string kata[110];
	pasangan pas[110];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cin>>kata[i];
		int pjg = kata[i].length();
		pas[i].kata = kata[i];
		pas[i].pjg = pjg;
	}

	sort(kata, kata+n, cmp);
	for(i=1;i<n;i++){
		if(kata[i].find(kata[i-1]) == -1){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=0;i<n;i++){
		cout<<kata[i]<<endl;
	}
	return 0;
};