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

const int maxn = 2e5 + 5;

int n;

int main(){
	int i,j;
	string kata;
	cin>>n>>kata;
	// cout<<"kata: "<<kata<<endl;
	string temp = kata;
	if(n == 1){printf("0\n"); cout<<kata<<endl; return 0;}
	char cur = kata[0];
	int cnt = 1;
	int ans = 0;
	int awal = 0, akhir;
	for(i=1;i<n;i++){
		if(cur != kata[i]){
			ans += cnt/2;
			// printf("ans jd: %d i: %d\n",ans,i);
			char harus;
			if(cnt%2 == 1){
				if(cnt > 1){
					set<char> s;
					s.insert(cur);
					if(!s.count('R')){
						harus = 'R';
					}else if(!s.count('G')){
						harus = 'G';
					}else{
						harus = 'B';
					}
					for(j = i-cnt+1;j<i;j+=2){
						kata[j] = harus;
					}
				}
			}else{
				set<char> s;
				if(i-cnt-1 >= 0){
					char kar = kata[i-cnt-1];
					
					s.insert(kar); s.insert(cur);
					if(!s.count('R')){
						harus = 'R';
					}else if(!s.count('G')){
						harus = 'G';
					}else{
						harus = 'B';
					}
					
				}else{
					s.insert(cur);
					if(!s.count('R')){
						harus = 'R';
					}else if(!s.count('G')){
						harus = 'G';
					}else{
						harus = 'B';
					}
					// printf("harus: %c\n",harus);

				}
				for(j=i-cnt;j<i;j+=2){
					kata[j] = harus;
				}	
			}
			
			cur = kata[i];
			cnt = 1;
		}else{
			cnt++;
		}
	}

	ans += cnt/2;
	char harus;
	if(cnt%2 == 1){
		set<char> s;
		s.insert(cur);
		if(!s.count('R')){
			harus = 'R';
		}else if(!s.count('G')){
			harus = 'G';
		}else{
			harus = 'B';
		}
		for(j = i-cnt+1;j<i;j+=2){
			kata[j] = harus;
		}
	}else{
		set<char> s;
		if(i-cnt-1 >= 0){
			char kar = kata[i-cnt-1];
			
			s.insert(kar); s.insert(cur);
			if(!s.count('R')){
				harus = 'R';
			}else if(!s.count('G')){
				harus = 'G';
			}else{
				harus = 'B';
			}
			
		}else{
			s.insert(cur);
			if(!s.count('R')){
				harus = 'R';
			}else if(!s.count('G')){
				harus = 'G';
			}else{
				harus = 'B';
			}

		}
		for(j=i-cnt;j<i;j+=2){
			kata[j] = harus;
		}	
	}
	
	printf("%d\n",ans); cout<<kata<<endl;
	return 0;
};