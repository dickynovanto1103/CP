#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int bil1,bil2;
	int test = 1;
	while(scanf("%d",&bil1)!=EOF){
		string op;
		string ans;

		cin>>op; scanf("%d",&bil2);
		//printf("%d %d ",bil1,bil2); cout<<op<<endl;
		if(op=="E"){break;}
		printf("Case %d: ",test++);
		if(op==">"){
			if(bil1>bil2){printf("true\n");}
			else{printf("false\n");}
		}else if(op==">="){
			if(bil1>=bil2){printf("true\n");}
			else{printf("false\n");}
		}else if(op=="<"){
			if(bil1<bil2){printf("true\n");}
			else{printf("false\n");}
		}else if(op=="<="){
			if(bil1<=bil2){printf("true\n");}
			else{printf("false\n");}
		}else if(op=="=="){
			if(bil1==bil2){printf("true\n");}
			else{printf("false\n");}
		}else if(op=="!="){
			if(bil1!=bil2){printf("true\n");}
			else{printf("false\n");}
		}
	}
	return 0;
}

