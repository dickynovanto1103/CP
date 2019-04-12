#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

template<class T>
struct mapper{
  std::vector<T> m;
  mapper(){}
  mapper(const T *arr, int sz){mapping(arr, sz);}
  mapper(const vector<T> &arr){mapping(arr);}
  void mapping(const T *arr, int sz){
    m.clear();
    for(int i=0;i<sz;++i)
      m.pb(arr[i]);
    sort(m.begin(), m.end());
    m.erase(unique(m.begin(), m.end()), m.end());
  }
  void mapping(const vector<T> &arr){
    m.clear();
    for(const T &x : arr)
      m.pb(x);
    sort(m.begin(), m.end());
    m.erase(unique(m.begin(), m.end()), m.end());
  }
  int get(const T &val){ return lower_bound(m.begin(), m.end(), val) - m.begin();}
  int operator[] (const T &val){ return get(val);}
};


struct Photo {
  char orientation;
  vector<string> tags;
  vector<int> ntags;
  int cnt_tags;
  string output;
  
  Photo() : orientation('-'), cnt_tags(0) {}
  Photo(char orientation, vector<string> tags, int cnt_tags) {
    this->orientation = orientation;
    this->tags = tags;
    this->cnt_tags = cnt_tags;
  }

  int get_diff(Photo& other) {
    int ans = 0;
    for(int x : other.ntags){
      if(binary_search(ntags.begin(), ntags.end(), x)){
        ans++;
      }
    }
    return min(ans, (int) min(ntags.size()-ans, other.ntags.size()-ans));
  }

  void union_vertical(Photo& other) {
    vector<int> tmp, merg;
    for(int x : other.ntags){
      if(!binary_search(ntags.begin(), ntags.end(), x)){
        tmp.push_back(x);
      }
    }
    int i,j;
    for(i=j=0;i<ntags.size() && j<other.ntags.size();){
      if(ntags[i]  <= other.ntags[j]){
        merg.pb(ntags[i]);
        ++i;
      }
      else{
        merg.pb(other.ntags[j]);
        ++j;
      }
    }

    while(i<ntags.size()){
      merg.pb(ntags[i]);
      ++i;
    }

    while(j<other.ntags.size()){
      merg.pb(other.ntags[j]);
      ++j;
    }

    this->orientation = 'H';
    this->cnt_tags = this->tags.size();
    this->output += " ";
    this->output += other.output;
  }
};

vector<Photo> listPhoto;
vector<Photo> verListPhoto;
vector<bool> verTaken;
vector<bool> horTaken;
vector<string> result;
vector<string> vStr;
mapper<string> mep;
int numberGraphTaken = 0;
vector<int> random_number;
vector<vi> AdjList;

int main(){
  srand(time(NULL));
  int n;
  cin>>n;
  AdjList.assign(100010, vi());
  cerr<<"hehe masuk input\n";
  /* baca input */
  int cnt[100010];
  memset(cnt, 0, sizeof cnt);
  map<string, int> mapper;
  set<string> s;
  set<string>::iterator it;
  int idx = 0;
  for(int i=0;i<n;++i){
    cin.get();
    Photo temp;
    cin>>temp.orientation>>temp.cnt_tags;
    for(int j=0;j<temp.cnt_tags;++j){
      string str_tmp;
      cin>>str_tmp;
      s.insert(str_tmp);
      if(mapper.find(str_tmp) == mapper.end()){
        mapper[str_tmp] = idx;
        AdjList[idx].pb(i);
        cnt[idx++] = 1;
      }else{
        int idx = mapper[str_tmp];
        AdjList[idx].pb(i);
        cnt[idx]++;
      }
      temp.tags.pb(str_tmp);
      vStr.pb(str_tmp);
    }
    temp.output = to_string(i);
    if(temp.orientation == 'V'){
      verListPhoto.pb(temp);
    }
    else{
      listPhoto.pb(temp);
    }
  }

  // for(it=s.begin();it!=s.end();it++){
  //   int idx = mapper[*it];
  //   cout<<*it<<" "<<cnt[idx]<<endl;
  // }
  int i,j;
  printf("idx: %d\n",idx);
  for(i=0;i<idx;i++){
    printf("i: %d->",i);
    for(j=0;j<AdjList[i].size();j++){
      printf(" %d",AdjList[i][j]);
    }
    printf("\n");
  }
  return 0;
  mep.mapping(vStr);
  for(Photo &x : verListPhoto){
    for(string &y : x.tags){
      x.ntags.pb(mep[y]);
    }
    sort(x.ntags.begin(), x.ntags.end());
    x.tags.clear();
  }
  for(Photo &x : listPhoto){
    for(string &y : x.tags){
      x.ntags.pb(mep[y]);
    }
    sort(x.ntags.begin(), x.ntags.end());
    x.tags.clear();
  }
  cerr<<"hehe masuk construct ver\n";
  /* construct graph di vertical list photo*/
  int ukuran = verListPhoto.size();
  random_shuffle(verListPhoto.begin(), verListPhoto.end());
  verTaken.assign(ukuran, 0);
  for(int i=0;i<ukuran - 1;++i) {
    if(verTaken[i]) continue;
    int idx = -1;
    int mi = -1;
    for(int j=i+1;j<ukuran;++j){
      if(verTaken[j]) continue;
      if(idx == -1){
        idx = j;
        mi = verListPhoto[i].get_diff(verListPhoto[j]);
      }
      else{
        int tmp = verListPhoto[i].get_diff(verListPhoto[j]); 
        if(tmp < mi){
          idx = j;
          mi = tmp;
        }
      }
    }
    verTaken[i] = true;
    verTaken[idx] = true;
    verListPhoto[i].union_vertical(verListPhoto[idx]);
    listPhoto.pb(verListPhoto[i]);
  }
  for(int i = 0; i < listPhoto.size(); i++) {
    random_number.push_back(i);
  }
  random_shuffle(random_number.begin(), random_number.end());
  cerr<<"hehe masuk graph sol\n";
  /*graph solution*/
  random_shuffle(listPhoto.begin(), listPhoto.end());
  int ukuranHorizontal = listPhoto.size();
  horTaken.assign(ukuranHorizontal, 0);
  int now = 0;
  while(numberGraphTaken < listPhoto.size()) {
    numberGraphTaken++;

    result.push_back(listPhoto[now].output);
    horTaken[now] = true;

    int maks_index = -1;
    int maks_diff = 0;
    
    for(int i = 0; i < listPhoto.size(); i++) {
      if (i != now) {
        if (!(horTaken[i])) {
          int diff = listPhoto[now].get_diff(listPhoto[i]);
          if (maks_diff < diff) {
            maks_index = i;
            maks_diff = diff;
          }
        }
      } 
    }

    if (maks_index == -1) {
      while(horTaken[random_number.back()]) {
        random_number.pop_back();
      }
      now = random_number.back();
    } else {
      now = maks_index;
    }
  }
  cout << result.size() << "\n";
  for(int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }
  
  return 0;
};