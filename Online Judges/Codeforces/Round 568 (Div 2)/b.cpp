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
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		int idx1 = 0, idx2 = 0;
		int pjg1 = a.length(), pjg2 = b.length();
		if(pjg2 < pjg1){printf("NO\n"); continue;} 
		char last = 'A';
		bool valid = true;
		for(j=0;j<pjg1;j++){
			char kar = a[j];
			// printf("kar: %c last: %c\n",kar, last);
			if(idx2 == pjg2){valid = false; break;}
			if(b[idx2] != kar) {
				if(b[idx2] == last){
					while(idx2 < pjg2 && b[idx2] == last){
						idx2++;
					}
					if(idx2 == pjg2){valid = false; break;}
					if(b[idx2] == kar){
						idx2++;
					}else{
						valid = false; break;
					}
				}else{
					valid = false; break;
				}
			}else{
				idx2++;
			}
			last = kar;
		}
		while(idx2 < pjg2){
			if(b[idx2] == last){
				idx2++;
			}else{
				valid = false;
				break;
			}
		}
		if(valid){printf("YES\n");}
		else{printf("NO\n");}
	}

	return 0;
};