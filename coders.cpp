#include <cstdio>
#include<queue>
#include<iostream>
using namespace std;

deque< pair<int, int> > dqmin, dqmax;

long long n, t;
int ans = 0, bound = 0;

int main(){
	ios_base::sync_with_stdio(0);
   cin.tie(0);
	cin >> t >> n;
	for(int i=1; i<=n; i++){
		long long x; cin >> x;
		while(dqmin.size() && dqmin.back().first >= x) dqmin.pop_back();
		while(dqmax.size() && dqmax.back().first <= x) dqmax.pop_back();
		dqmin.push_back({x, i});
		dqmax.push_back({x, i});
		while(dqmax.front().first - dqmin.front().first > t){
			if(dqmin.front().second < dqmax.front().second){
				bound = dqmin.front().second;
				dqmin.pop_front();
			}else{
				bound = dqmax.front().second;
				dqmax.pop_front();
			}
		}
		ans = max(ans, i - bound);
	}
	cout << ans;
}
