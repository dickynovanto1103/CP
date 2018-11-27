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
	string kata;
	scanf("%d",&n);
	cin>>kata;
	string ans1 = "";
	string ans = "";
	for(i=0;i<n-1;i++){
		ans += kata[i];
	}
	for(i=1;i<n;i++){
		ans1 += kata[i];
	}
	string jawab = "";
	if(kata[0] > kata[1]){
		cout<<ans1<<endl;
		return 0;
	}
	jawab = ans;
	for(i=0;i<(n-2);i++){
		string kata2 = kata.substr(i,3);
		kata2.erase(1,1);
		string kata1 = kata.substr(i,2);
		// cout<<"kata1: "<<kata1<<" kata2:"<<kata2<<endl;
		if(kata2 < kata1){
			for(j=0;j<=i;j++){printf("%c",kata[j]);}
			for(j=i+2;j<n;j++){printf("%c",kata[j]);}
			printf("\n");
			return 0;
		}
	}
	cout<<jawab<<endl;
	
	return 0;
};