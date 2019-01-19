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
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	map<string, int> mapper;
	for(i=0;i<n;i++){
		string kata;
		int n;
		cin>>kata>>n;
		mapper[kata] = n;
	}
	string dum;
	getline(cin, dum);
	for(i=0;i<m;i++){
		int sum = 0;
		while(getline(cin, dum), dum!="."){
			// cout<<"dum: "<<dum<<endl;
			string temp = "";
			for(j=0;j<dum.length();j++){
				if(dum[j] == ' '){
					if(mapper.find(temp) != mapper.end()){
						// printf("temp: "); cout<<temp<<endl;
						// printf("sum ditambah: %d\n",mapper[temp]);
						sum += mapper[temp];	
						// printf("sum jadi: %d\n", sum);
					}
					
					temp = "";
				}else{
					temp += dum[j];
				}
			}
			if(mapper.find(temp) != mapper.end()){
				sum += mapper[temp];	
			}
			
		}
		printf("%d\n",sum);
		// getline(cin, dum);
		// printf("dum: "); cout<<dum<<endl;
		// getline(cin,dum);
		// printf("dum: "); cout<<dum<<endl;
	}


	return 0;
};