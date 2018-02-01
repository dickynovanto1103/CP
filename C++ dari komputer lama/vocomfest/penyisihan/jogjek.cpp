#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
#define inf 1000000000
int main(){
	int n,m,tc,test=1,i,j,k;
	int a[110],b[110],c[110],d[110],x[110],y[110];
	vector<string> list;
	map<string,int> mapper;
	map<string,int>::iterator it;
	string nama[110];
	scanf("%d",&tc);
	while(tc--){
		printf("Case #%d:\n",test++);
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){
			cin>>nama[i]>>x[i]>>y[i];
			mapper[nama[i]] = i;

		}
		for(i=0;i<m;i++){scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);}
		//proses
		for(i=0;i<m;i++){
			int temp = inf;
			for(j=0;j<n;j++){
				int jarak = abs(x[j]-a[i]) + abs(y[j]-b[i]);
				if(temp > jarak){temp = jarak;}
			}
			int minim = temp;
			for(j=0;j<n;j++){
				int jarak = abs(x[j]-a[i]) + abs(y[j]-b[i]);
				if(minim == jarak){list.push_back(nama[j]);}
			}
			sort(list.begin(), list.end());
			cout<<list[0]<<endl;
			int idx = mapper[list[0]];
			x[idx] = c[i]; y[idx] = d[i];
			list.clear();
		}
		mapper.clear(); list.clear();
	}
	return 0;
}