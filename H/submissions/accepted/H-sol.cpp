#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n, in, count = 1;
	cin >> n;
	map<long long int, long long int> cnt;
	while(n--){
		cin >> in;
		cnt[in]++;
	}
	long long int ans = 0;
	for(auto x : cnt)
		if(!(x.first%2)) ans += x.second;

	if(!(ans%2) && ans){
		cout << "YES" << endl;		
		for(auto x : cnt)
			if(!(x.first%2))
				while(x.second--)
					 cout << x.first << " ";
		cout << endl; 
	}
	else if(ans%2 && ans > 1){
		cout << "OuO" << endl;
		for(auto x : cnt){
			if(!(x.first%2)){
				cout << x.first << endl;
				break;
			}
		}
	}
	else cout << "NO" << endl;
		
	return 0;
}
