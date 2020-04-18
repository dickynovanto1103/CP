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

const ll maxn = inf;

void generate(int n){
	int smallest = 0;
	int i,j;
	set<int> s;
	int counter = 1;
	for(int tt=1;tt<=n;tt++){
		//find triple
		bool found = false;
		for(i=smallest+1;i<=inf;i++){
			if(s.find(i) != s.end()){continue;}
			for(j=i+1;j<=inf;j++){
				if(s.find(j) != s.end()){continue;}
				int sor = i^j;
				if(sor > j){
					
					
					if(s.find(sor) != s.end()){
						continue;
					}
					smallest = i;
					printf("%d %d %d urutan: %d\n",i, j, sor, counter++);
					s.insert(i); s.insert(j); s.insert(sor);
					found = true;
					break;
				}
			}
			if(found){break;}
		}
	}
}

int main(){
	generate(100);
	return 0;
};