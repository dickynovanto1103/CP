#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<vi> chamber;

int main(){
	int s,c,i,j,a[15];
	
	double avg;
	int test = 1;
	while(scanf("%d %d",&c,&s)!=EOF){
		chamber.assign(6,vi());
		int sum = 0;
		for(i=0;i<s;i++){scanf("%d",&a[i]); sum+=a[i];}
		int countChamber = c;
		avg = (double) sum / (double) countChamber;
		if(s<2*c){
			for(i=s;i<2*c;i++){a[i] = 0;}
		}
		sort(a,a+2*c);
		/*for(i=0;i<2*c;i++){
			if(i>0){printf(" ");}
			printf("%d",a[i]);
		}
		printf("\n");*/
		double diff = 0.0;
		for(i=0;i<c;i++){
			j = 2*c-i-1;
			int total = 0;
			if(a[i]!=0){chamber[i].push_back(a[i]); total+=a[i];}
			if(a[j]!=0){chamber[i].push_back(a[j]); total+=a[j];}
			diff+=fabs(total-avg);
		}
		printf("Set #%d\n",test++);
		for(i=0;i<c;i++){
			printf(" %d:",i);
			for(j=0;j<chamber[i].size();j++){
				printf(" %d",chamber[i][j]);
			}
			printf("\n");
		}
		printf("IMBALANCE = %.5lf\n",diff);
		printf("\n");
		chamber.clear();
	}
	

	return 0;
}