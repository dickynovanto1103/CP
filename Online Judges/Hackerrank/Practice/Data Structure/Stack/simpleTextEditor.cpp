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

stack<string> s;

int main(){
	int q,i;
	scanf("%d",&q);
	while(q--){
		int com;
		
		scanf("%d",&com);
		//printf("com: %d\n",com);
		if(com==4){s.pop();}
		else{
			int bil;
			string temp;
			if(com==1){
				cin>>temp;
				//printf("temp: "); cout<<temp<<endl;
				if(s.empty()){s.push(temp); continue;}
				string kata = s.top();
				kata+=temp;
				s.push(kata);
			}else if(com==2){
				scanf("%d",&bil);
				string kata = s.top();

				while(bil--){kata.pop_back();}
				s.push(kata);
			}else{
				scanf("%d",&bil);
				bil--;
				string kata = s.top();				
				printf("%c\n",kata[bil]);
			}
		}
	}
	return 0;
};