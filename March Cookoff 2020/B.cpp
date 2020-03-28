#include<bits/stdc++.h>

using namespace std;

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

int t;
ll n;

int main(){
	fast();

	cin >> t;
	while(t--){
		cin >> n;

		vll a, index;

		for(ll i=0;i<n;i++){
			ll temp;
			cin >> temp;
			a.pb(temp);
		}

		// Find Max element
		ll maxi = INT_MIN;

		for(ll i=0; i<n;i++){
			if(a[i] > maxi){
				maxi = a[i];
			}
		}

		//cout << "MAXIMUM = " << maxi << endl;

		// Hold indices of max element
		for(ll i=0;i<n;i++){
			//cout << "Element " << a[i] << " ";	
			if(a[i] == maxi){
				index.pb(i);
				//cout << "Index of Max = " << i << endl;
			}
		}


		ll last_index = index.size()-1;

		/*cout << "INDEX ARRAY = ";
		for(int i=0;i<=last_index;i++){
			cout << index[i] << " ";
		}

		cout << endl << index[last_index] << " - Last Index\n";
		*/
		
		// Corner Case
		if((index[last_index] - index[0]) >= (n/2)){
			cout << "0\n";
			continue;
		}

		ll ans = 1;

		ans += (index[0] + ((n-1) - index[last_index]) - (n/2));

		cout << ans << "\n";

	}
	
	return 0;
}