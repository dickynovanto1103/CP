#include <bits/stdc++.h>

using namespace std;
typedef pair<int,string> is;

int main(){
	int n,i,money;
	char kata[35];
	is data;
	priority_queue <is> pq;

	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d %s",&money,kata); pq.push(make_pair(money,(string)kata));}
	while(!pq.empty()){data=pq.top(); pq.pop(); printf("%s has %d\n",((string)data.second).c_str(),data.first);}
	return 0;
}