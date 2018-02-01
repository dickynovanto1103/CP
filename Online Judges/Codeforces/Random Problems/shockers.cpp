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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	char effect[maxn];
	string listKata[maxn];

	scanf("%d",&n);
	if(n==1){printf("0\n"); return 0;}
	for(i=0;i<n;i++){cin>>effect[i]>>listKata[i];}
	set<char> s,s1;
	set<char>::iterator it;
	int ans = 0;
	bool isFixed = false;
	for(char c = 'a';c<='z';c++){
		s.insert(c);
	}
	for(i=0;i<n;i++){
		char efek = effect[i];
		string kata = listKata[i];
		// printf("i: %d\n",i);
		if(efek=='!'){
			
			if(s.size()==1){ans++;}
			for(j=0;j<kata.length();j++){
				if(s.count(kata[j])){
					s1.insert(kata[j]);
				}
				
			}//masukkan
			s = s1;
			s1.clear();
		
		}else if(efek=='?'){
			if(s.size()==1){
				if(kata[0]!=*(s.begin())){
					ans++;	
				}
			}else{
				if(s.count(kata[0])){
					s.erase(kata[0]);
				}
			}
			// if(s.size()==1){
			// 	if(*(s.begin())!=kata[0]){
			// 		ans++;	
			// 	}
				
			// }

		}else if(efek=='.'){
			if(isFixed){continue;}
			if(s.size()==1){continue;}
			for(j=0;j<kata.length();j++){
				char kar = kata[j];
				if(s.count(kar)){
					s.erase(kar);
				}
			}
			if(s.size()==1){isFixed = true;}
		}
		// printf("ans: %d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
};