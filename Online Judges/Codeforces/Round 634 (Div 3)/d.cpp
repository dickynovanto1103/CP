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
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		string s[10];
		for(i=0;i<9;i++){
			cin>>s[i];
		}
		vii koor;
		koor.pb(ii(0,0));
		koor.pb(ii(3,1));
		koor.pb(ii(6,2));

		koor.pb(ii(1,3));
		koor.pb(ii(4,4));
		koor.pb(ii(7,5));

		koor.pb(ii(2,6));
		koor.pb(ii(5,7));
		koor.pb(ii(8,8));

		for(i=0;i<9;i++){
			ii ko = koor[i];
			int x = ko.first, y = ko.second;
			int bil = s[x][y] - '0';
			bil++;
			if(bil == 10){bil = 1;}
			s[x][y] = bil + '0';
		}
		for(i=0;i<9;i++){
			cout<<s[i]<<endl;
		}	
	}
	
	return 0;
};