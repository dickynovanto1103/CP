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
	int n,t;
	scanf("%d %d",&n,&t);
	int i,j;
	string kata;
	cin>>kata;
	for(i=0;i<t;i++){
		for(j=0;j<(n-1);j++){
			char kar1 = kata[j], kar2 = kata[j+1];
			if(kar1 == 'B' && kar2 == 'G') {
				swap(kata[j], kata[j+1]);
				j++;//lgsg skip
			}
		}
	}
	cout<<kata<<endl;
	return 0;
};