#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include <queue>
#define MOD (1000000007)

using namespace std;

void update(priority_queue<long long> &ansTemp, int K, const vector<long long> &n){
ansTemp.push(-n[2]);
//printf("-%d %d %d %d \n", n[0], n[1], n[2], n[3]);
if(ansTemp.size()>K){
ansTemp.pop();
}
}

int totalCount[1000001] = {0};
int solve(){

int N, K;

scanf(" %d %d", &N, &K);
vector<vector<long long>> data;

int a, b, x, y;
for(int i=0 ; i<N ; i++){
scanf(" %d %d %d %d", &a, &b, &x, &y);
data.push_back({a, -x, b, y});

totalCount[i] = 0;
}
stable_sort(data.begin(), data.end());

priority_queue<vector<long long>> now;
// location, total val, preval;
priority_queue<long long> ansTemp;

vector<long long> temp;
int l = 0, r;
int xx;
while(l<N){
xx = K-1;
while(now.size() && ((-now.top()[0])<data[l][0])){
update(ansTemp, K, now.top());
now.pop();
}

r = l;
while(r<N && data[l][0]==data[r][0]){
now.push({-data[r][2], -data[r][3], 0, data[r][3]});
r++;
}
while(now.size() && ((-now.top()[0])==data[l][0])){
temp = now.top();
now.pop();

update(ansTemp, K, temp);

if(totalCount[r-1]<K){
for(int i=l ; i<r && (data[i][1]+temp[3]<0); i++){
if(totalCount[i]>K) {
l = i;
continue;
}
totalCount[i]++;
now.push({-data[i][2], temp[1] - data[i][1] - data[i][3], temp[2] + (-data[i][1]-temp[3]), data[i][3]});
}
}
}
l = r;
}
while(now.size()){
update(ansTemp, K, now.top());
now.pop();
}

long long ans = 0;
while(ansTemp.size()){
if(ansTemp.top()>0){
ansTemp.pop();
continue;
}
ans = (ans - ansTemp.top())%MOD;
ansTemp.pop();
}

return ans;
}

int main(void){
int N;
scanf(" %d", &N);

for(int i=1 ; i<=N ; i++){
printf("Case #%d: %d\n", i, solve());
}
}