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
typedef long long ll;
typedef vector<int> vi;
typedef pair<double,int> ii;
typedef vector<ii> vii;

int main(){
	int x,y,r,n;
	scanf("%d %d %d %d",&x,&y,&r,&n);
	int cnt = 0;
	vii listKoor;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		ll jarak = (ll)abs(a-x)*(ll)abs(a-x) + (ll)abs(y-b)*(ll)abs(y-b);
		ll maks = (ll)r*(ll)r;
		if(maks >= jarak){
			listKoor.pb(ii(a,b));
		}
	}
	set<ii> s;
	for(int i=0;i<listKoor.size();i++){
		ii pas = listKoor[i];
		int selisihY = pas.second - y;
		int selisihX = pas.first - x;
		double grad = (double)selisihY/(double)selisihX;
		if(pas.first == x) {
			if(pas.second < y) {
				s.insert(ii(inf, -1));
			}else{
				s.insert(ii(inf, 1));
			}
		}else if(pas.second == y){
			if(pas.first < x) {
				s.insert(ii(grad, -1));
			}else{
				s.insert(ii(grad, 1));
			}
		}else{
			if(pas.second < y){
				s.insert(ii(grad, -1));	
			}else{
				s.insert(ii(grad, 1));
			}
			
		}
		
	}
	printf("%d\n",(int)s.size());
	return 0;
};