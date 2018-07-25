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
	int n,i,j;
	scanf("%d",&n);
	string kata;
	cin>>kata;
	for(i=1;i<=n;i++){
		if(n%i==0){
			//reverse
			reverse(kata.begin(), kata.begin() + i);
			// printf("i: %d\n",i);
			// cout<<"kata jadi: "<<kata<<endl;
		}
	}
	cout<<kata<<endl;
	return 0;
};