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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	deque<int> dq;
	bool normal = true;
	while(n--){
		string s;
		cin>>s;
		
		// cout<<"s: "<<s<<" normal: "<<normal<<endl;
		if(s == "add"){
			int x,y;
			scanf("%d %d",&x,&y);
			while(y--){
				if(normal){dq.push_back(x);}
				else{dq.push_front(x);}
			}
			printf("%d\n", (int)dq.size());
		}else if(s == "del") {
			int bil;
			scanf("%d",&bil);
			int angka = -1;
			while(bil--) {
				if(normal){
					if(angka == -1){angka = dq.front();}
					dq.pop_front();
				}else{
					if(angka == -1){angka = dq.back();}
					dq.pop_back();
				}
			}
			printf("%d\n", angka);
		}else{
			normal = 1 - normal;
		}
	}
	
	return 0;
};