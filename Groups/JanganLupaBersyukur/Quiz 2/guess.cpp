#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

int main(){
	int n,i,j;
	ii op[1010];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d %d",&op[i].first,&op[i].second);
		}
		stack<int> s; priority_queue<int> pq; queue<int> q;
		//cek stack
		int cnt=0;
		for(i=0;i<n;i++){
			int oper = op[i].first, bil = op[i].second;
			if(oper==1){s.push(bil);}
			else{
				if(s.empty()){break;}
				if(s.top()!=bil){break;}
				else{s.pop();}
			}
		}
		string ans;
		if(i==n){cnt++; ans = "stack";}
		//queue
		for(i=0;i<n;i++){
			int oper = op[i].first, bil = op[i].second;
			if(oper==1){q.push(bil);}
			else{
				if(q.empty()){break;}
				if(q.front()!=bil){break;}
				else{q.pop();}
			}
		}
		if(i==n){cnt++; ans = "queue";}
		if(cnt==2){ans = "not sure";}
		else{
			for(i=0;i<n;i++){
				int oper = op[i].first, bil = op[i].second;
				if(oper==1){pq.push(bil);}
				else{
					if(pq.empty()){break;}
					if(pq.top()!=bil){break;}
					else{pq.pop();}
				}
			}
			if(i==n){cnt++; ans = "priority queue";}
			if(cnt==2){
				ans = "not sure";
			}else if(cnt==0){ans = "impossible";}
		}
		cout<<ans<<endl;
		//prio queue
		
	}
	return 0;



}