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

stack<int> s1,s2;

int main(){
	int n,i,a[1001];
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int counter = 1;
		
		bool isPossible = true;
		for(i=0;i<n;i++){
			if(a[i]==counter){s1.push(a[i]); counter++;}
			else{
				//if not the same..we must check from both the remaining array or the stack 2
				if(!s2.empty()){
					int bil = s2.top();
					if(bil==counter){s2.pop(); s1.push(bil); counter++; i--;}
					else{s2.push(a[i]);}
				}else{
					s2.push(a[i]);
				}
				
			}
		}
		while(!s2.empty()){
			int bil = s2.top(); s2.pop();
			if(bil!=counter){isPossible = false; break;}
			else{counter++;}
		}
		while(!s1.empty()){s1.pop();}
		while(!s2.empty()){s2.pop();}
		if(!isPossible){printf("no\n");}
		else{printf("yes\n");}
	}
	return 0;
};