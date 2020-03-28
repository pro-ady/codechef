#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(i=0;i<n;i++)
#define repd(i,n) for(i=n;i>=0;i--)
#define REP(i,k,n) for(i=k;i<=n;i++)
#define REPD(i,k,n) for(i=k;i>=n;i--)

void fast(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
    cin.tie(0);
}

int t,n;

int main(){
	fast();
	cin >> t;
	while(t--){
		cin >> n;

		vll a;

		for(int i=0;i<n;i++){
			ll temp;
			cin >> temp;
			a.pb(temp);
		}

		ll ans = 1;

		for(int i=1;i<n;i++){
			if(__builtin_popcount(a[i-1] & ~a[i]) > 0){
				ans = 0;
				break;
			}

			ll and_result = a[i] & a[i-1];
			//cout << "AND RESULT = " << and_result << "\n";
			ll set_bits = __builtin_popcount(and_result) % MOD;
			//cout << "SET BITS " << set_bits << "\n";
			ans = (ans*(ll)pow(2,set_bits)) % MOD;
		}

		cout << ans%MOD << "\n";
	}
	return 0;
}