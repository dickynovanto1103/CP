#include <bits/stdc++.h>

using namespace std;
typedef pair <int,int> ii;

struct p{
	int x;
	int y;
};

bool acompare(p lhs, p rhs){return lhs.x < rhs.x;}
bool bcompare(p lhs, p rhs){return lhs.y < rhs.y;}

vector <int> arr;
vector <int>::iterator it2;
int main(){
	int n,tc,i,j,k,l,m,ans,int1,int2,curx,idxcurx,cnt;

	map <ii,int> mapper;
	map <ii,int>::iterator it;
	p a[40];
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		cnt=1;
		printf("Case #%d: ",i);
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d %d",&int1,&int2);
			a[j].x=int1; a[j].y=int2;
			mapper[ii(int1,int2)]=cnt;
			//printf("untuk point %d %d map: %d\n",int1,int2,cnt);
			cnt++;
		}
		
		//break;
		sort(a,a+n,acompare);
		curx=a[0].x; idxcurx=0;
		for(j=1;j<n;j++){
			while(curx==a[j].x){j++;}
			sort(a+idxcurx,a+j,bcompare);
			idxcurx=j; curx=a[j].x;
		}
		/*for(it=mapper.begin();it!=mapper.end();++it){
			printf("point: %d %d hasil mapping: %d\n",it->first.first,it->first.second,it->second);
		}*/
		/*printf("array terurut:\n");
		for(j=0;j<n;j++){
			printf("%d %d\n",a[j].x, a[j].y);
		}*/
		if(n<=3){printf("0\n");}
		else{
			for(m=0;m<n;m++){
				for(j=m+1;j<n;j++){
					for(k=j+1;k<n;k++){
						for(l=k+1;l<n;l++){
							int selisih=(int)abs(a[m].y-a[j].y);
							if((a[m].x - a[j].x == 0) && (a[k].x-a[j].x == selisih) && (a[k].x-a[j].x == a[j].y-a[k].y) && (a[k].x == a[l].x) && (a[l].y - a[k].y==selisih)){
								it=mapper.find(ii(a[m].x,a[m].y));
								arr.push_back(it->second);
								//printf("point: %d %d yang dipush: %d\n",a[m].x,a[m].y,it->second);
								it=mapper.find(ii(a[j].x,a[j].y));
								arr.push_back(it->second);
								//printf("point: %d %d yang dipush: %d\n",a[j].x,a[j].y,it->second);
								it=mapper.find(ii(a[k].x,a[k].y));
								arr.push_back(it->second);
								//printf("point: %d %d yang dipush: %d\n",a[k].x,a[k].y,it->second);
								it=mapper.find(ii(a[l].x,a[l].y));
								arr.push_back(it->second);
								//printf("point: %d %d yang dipush: %d\n",a[l].x,a[l].y,it->second);
							}
						}
					}
				}
			}
			sort(arr.begin(),arr.end());
			/*printf("hasil:\n");
			for(it2=arr.begin();it2!=arr.end();it2++){
				printf("%d ",*it2);
			}
			printf("\n");*/
			it2 = unique(arr.begin(),arr.end());
			arr.resize(distance(arr.begin(),it2));
			/*printf("hasil unique:\n");
			for(it2=arr.begin();it2!=arr.end();it2++){
				printf("%d ",*it2);
			}
			printf("\n\n");*/
			printf("%d\n",arr.size());
			mapper.clear();arr.clear();
		}
	}
	return 0;
}