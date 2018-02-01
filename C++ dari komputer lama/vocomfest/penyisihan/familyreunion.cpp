#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector<int> vi;
typedef pair<int,int> ii;

map<string,int> mapper;
map<string,int>::iterator it;
map<int, string> mapper2;

vector<vi> AdjList, AdjList1;
vector<string> list1,list2,list3,list4;

vi dfs_num;
bool found;
string lowest;

void dfs1(int a){
	string kata = mapper2[a];
	//printf("dfs1: kata yang dipush: "); cout<<kata<<endl;
	list1.push_back(kata);
	dfs_num[a] = visited;
	for(int i = 0;i<AdjList1[a].size();i++){
		int v = AdjList1[a][i];
		if(dfs_num[v]==unvisited){dfs1(v);}
	}
}

void dfs2(int a){
	string kata = mapper2[a];
	//printf("dfs2: kata yang dipush: "); cout<<kata<<endl;
	list2.push_back(kata);
	if(found){return;}
	//cari kata dulu di list1
	for(int i = 0;i < list1.size();i++){
		if(list1[i]==kata){lowest = kata;found=true; return;}
	}
	dfs_num[a] = visited;
	for(int i = 0;i<AdjList1[a].size();i++){
		int v = AdjList1[a][i];
		if(dfs_num[v]==unvisited){dfs2(v);}
	}
}

int main(){
	int n,t,cnt=0,i,j;
	
	string kata1,kata2;
	scanf("%d %d",&n,&t);
	AdjList1.assign(1005,vi());
	for(i=0;i<n-1;i++){
		cin>>kata1>>kata2;
		it = mapper.find(kata1);
		if(it==mapper.end()){mapper[kata1]=cnt; mapper2[cnt] = kata1; cnt++;}
		it = mapper.find(kata2);
		if(it==mapper.end()){mapper[kata2]=cnt; mapper2[cnt] = kata2; cnt++;}
		int a = mapper[kata1],b = mapper[kata2];
		//AdjList[b].push_back(a);
		AdjList1[a].push_back(b);
	}
	
	string orang;
	for(i=0;i<t;i++){
		if(i>0){printf("\n");}
		found = false;
		printf("Case #%d:\n",i+1);
		cin>>orang;
		//cout<<"orang: "<<orang<<endl;
		int idx_blangkon = mapper["Blangkon"], idx_orang = mapper[orang];
		dfs_num.assign(cnt,unvisited);

		dfs1(idx_blangkon);
		dfs_num.assign(cnt,unvisited);
		dfs2(idx_orang);
		//sudah dapat list orang
		int cnt1 = list1.size(),cnt2 = list2.size();
		//cout<<"lowest: "<<lowest<<endl;
		for(j=0;j<cnt1;j++){
			//printf("yang dipush: %d")
			list3.push_back(list1[j]);
			if(list1[j]==lowest) break;
		}
		for(j=0;j<cnt2;j++){
			list4.push_back(list2[j]);
			if(list2[j]==lowest) break;
		}
		reverse(list3.begin(), list3.end()); reverse(list4.begin(), list4.end());

		for(j=0;j<list3.size();j++){
			if(j==0){cout<<list3[j];}
			else{cout<<"->"<<list3[j];}
		}
		printf("\n");
		for(j=0;j<list4.size();j++){
			if(j==0){cout<<list4[j];}
			else{cout<<"->"<<list4[j];}
		}
		printf("\n");
		list1.clear(); list2.clear(); list3.clear(); list4.clear();
	}
	return 0;
}