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
	deque<string> d;
	int q;
	scanf("%d",&q);
	while(q--){
		int a;
		string kata;
		scanf("%d",&a);
		
		if(a==1){cin>>kata;d.push_front(kata);}
		else if(a==2){cin>>kata;d.push_back(kata);}
		else if(a==3){
			kata = d.front(); d.pop_front();
			cout<<kata<<endl;
		}else{
			kata = d.back(); d.pop_back();
			cout<<kata<<endl;
		}
	}
	return 0;
}