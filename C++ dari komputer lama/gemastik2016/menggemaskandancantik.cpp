#include <bits/stdc++.h>

using namespace std;
#define maxn 50000

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <int> vi;
string name[maxn+10];
int main(){
	int tc,n,i,j,k,g,c,m,cnt;
	ll totalcantik,totalgemas,total,ans;
	vi idx,ansidx;
	char kata[10];
	scanf("%d",&tc);
	vector <ii> a,b;//a untuk gemas dan b untuk cantik
	while(tc--){
		scanf("%d",&n);
		a.clear(); b.clear();
		for(i=0;i<n;i++){
			scanf("%s %d %d",kata,&g,&c);
			name[i]=kata;
			//printf("test\n");
			a.push_back(make_pair(g,i));
			b.push_back(make_pair(c,i));
		}
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		sort(b.begin(),b.end());
		reverse(b.begin(),b.end());
		/*printf("a:");
		for(i=0;i<n;i++){
			printf("gemas: %d id: %d\n",a[i].first,a[i].second);
		}
		printf("b:");
		for(i=0;i<n;i++){
			printf("cantik: %d id: %d\n",b[i].first,b[i].second);
		}*/
		ans=-1;
		for(i=0;i<6;i++){
			for(j=i+1;j<6;j++){
				for(k=j+1;k<6;k++){
					//if(i==j || i==k || j==k){continue;}
					totalgemas=a[i].first*a[j].first*a[k].first;
					//idx.push_back(a[i].second); idx.push_back(a[j].second); idx.push_back(a[k].second);
					cnt=0;
					totalcantik=1;
					idx.clear();
					for(m=0;m<6 && cnt<3;m++){
						int id = b[m].second;
						if(id == a[i].second || id==a[j].second || id==a[k].second){continue;}
						//klo ga ada yang sama
						totalcantik*=b[m].first;
						idx.push_back(id);
						cnt++;
					}
					
						total=totalgemas+totalcantik;
						if(ans < total){
							ans=total;
							ansidx.clear();
							ansidx.push_back(a[i].second); ansidx.push_back(a[j].second); ansidx.push_back(a[k].second);
							for(m=0;m<idx.size();m++){ansidx.push_back(idx[m]);}
						}
						//printf("total: %lld ans: %lld\n",total,ans);
					
					
					//ansidx.clear();
				}
			}
		}
		//assert(ansidx.size()==6);
		printf("%lld\n",ans);
		for(i=0;i<3;i++){
			if(i!=0){printf(" ");}
			cout<<name[ansidx[i]];
		}
		printf("\n");
		for(i=3;i<6;i++){
			if(i!=3){printf(" ");}
			cout<<name[ansidx[i]];
		}
		printf("\n");
		
	}
	return 0;
}
