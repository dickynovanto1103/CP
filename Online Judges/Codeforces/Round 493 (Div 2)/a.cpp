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
	int a[14];
	if(n==1){
		printf("-1\n");
		return 0;
	}
	set<int> s;
	int pref[12];
	int sum = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		s.insert(a[i]);
		sum+=a[i];
		if(i==0){pref[i] = a[i];}
		else{pref[i] = pref[i-1] + a[i];}
	}
	if(n==2){
		if(s.size() == 1){
			printf("-1\n");	
		}else{

			printf("1\n1\n");
		}
		

	}else{
		if(s.size() == 1){
			printf("1\n1\n");	
		}else{
			bool isValid = false;
			vi ans;
			for(i=0;i<n;i++){
				ans.pb(i+1);
				if(pref[i] == (sum-pref[i])){continue;}
				else{
					isValid = true;
					break;
				}
			}
			if(!isValid){printf("-1\n"); return 0;}
			printf("%d\n",(int)ans.size());
			for(i=0;i<ans.size();i++){
				if(i){printf(" ");}
				printf("%d",ans[i]);
			}
			printf("\n");
		}
		
	}

	return 0;
};