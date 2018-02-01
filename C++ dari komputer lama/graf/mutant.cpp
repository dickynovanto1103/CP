#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef pair<int,int> ii;

int main(){
	int n,m,i,j,x,y,pjg,cnt=0;
	char dir;
	bool lost;
	map <ii,int> mapper;
	map <ii,int>::iterator it;
	string kata;
	scanf("%d %d",&n,&m);
	while(scanf("%d %d %c",&x,&y,&dir)!=EOF){
		getline(cin>>ws,kata);
		pjg = kata.length();
		lost = false;
		for(i=0;i<pjg;i++){
			if(dir=='N'){
				if(kata[i]=='F'){
					y++;
					if(y>m){
						y=m; 
						it = mapper.find(ii(x,y));
						if(it==mapper.end()){lost = true;}
					}
				}else if(kata[i]=='L'){dir = 'W';}
				else if(kata[i]=='R'){dir = 'E';}
			}else if(dir=='E'){
				if(kata[i]=='F'){
					x++;
					if(x>n){
						x=n; 
						it = mapper.find(ii(x,y));
						if(it==mapper.end()){lost = true;}
					}
				}else if(kata[i]=='L'){dir = 'N';}
				else if(kata[i]=='R'){dir = 'S';}
			}else if(dir=='W'){
				if(kata[i]=='F'){
					x--;
					if(x<0){
						x=0; 
						it = mapper.find(ii(x,y));
						if(it==mapper.end()){lost = true;}
					}
				}else if(kata[i]=='L'){dir = 'S';}
				else if(kata[i]=='R'){dir = 'N';}
			}else if(dir=='S'){
				if(kata[i]=='F'){
					y--;
					if(y<0){
						y=0;
						it = mapper.find(ii(x,y));
						if(it==mapper.end()){lost = true;}
					}
				}else if(kata[i]=='L'){dir = 'E';}
				else if(kata[i]=='R'){dir = 'W';}
			}
			if(lost){mapper[ii(x,y)]=cnt++; break;}
		}
		printf("%d %d %c",x,y,dir);
		if(lost){printf(" LOST\n");}
		else{printf("\n");}
	}
	return 0;
}