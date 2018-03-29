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
	string project, subproject, method;
	map<string, int> mapperProject;
	map<string, int> mapperSubproject;
	map<string, int> mapperMethod;
	map<string, int>::iterator it;
	char dum;
	
	for(i=0;i<n;i++){
		string hasil = "";
		string kata;
		string hasilParse[3];
		cin>>kata;
		// printf("kata: "); cout<<kata<<endl;
		int cnt = 0;
		
		for(j=1;j<kata.length();j++){
			char kar = kata[j];
			if(kar=='/'){
				hasilParse[cnt] = hasil;
				hasil="";
				cnt++;
			}else{
				hasil+=kar;	
			}

			
		}
		hasilParse[2] = hasil;
		project = hasilParse[0]; subproject = hasilParse[1]; method = hasilParse[2];
		int idxProject = 0, idxSubproject = 0, idxMethod = 0;
		if(mapperProject.find(project))
	}
	return 0;
};