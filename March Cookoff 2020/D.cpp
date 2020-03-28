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
ll n,q;

ll maxSubArraySum(vll a, ll size){ 
   ll max_so_far = a[0]; 
   ll curr_max = a[0]; 
  
   for (ll i = 1; i < size; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   }

   return max_so_far; 
}

void U(vll &B,vll &sum, ll pos, ll v){
	B[pos-1] = v;

	ll j = (pos==1) ? 1 : pos-1;
	sum[pos-1] = (pos==1) ? B[pos-1] : (sum[pos-2] + B[pos-1]);

	cout << "sum[pos-1] = " << sum[pos-1];
	for(ll i=pos;i<n;i++){
		sum[i] = sum[i-1] + B[i];
	}

	cout << "Sum Array \n";
	for(ll i=0;i<n;i++){
		cout << sum[i] << " ";
	}
	cout << "\n";

	//return maxSubArraySum(B, B.size());
}


ll Q(vll B, vll sum, ll x, ll y){
	ll start = x-1;
	ll fini = y-1;

	ll result_sum;

	if(start == 0){
		result_sum = sum[fini];
	}

	else{
		result_sum = sum[fini] - sum[start-1];
	}

	cout << "Result Sum = " << result_sum << endl;

	while(start >= 0){
		ll temp_sum;
		if(start == 0){
			temp_sum = result_sum + (sum[x-1] - sum[start]);
		}
		else{
			temp_sum = result_sum + (sum[x-1] - sum[start-1]);
		}
		cout << "Temp Sum = " << temp_sum << ", result_sum = " << result_sum << endl;
		if(temp_sum >= result_sum){
			start--;
			result_sum = temp_sum;
		}

		else{
			break;
		}
	}

	while(fini < n-1){
		ll temp_sum = result_sum + (sum[fini] - sum[y-1]);
		cout << "Temp Sum = " << temp_sum << ", result_sum = " << result_sum << endl;
		if(temp_sum >= result_sum){
			fini++;
			result_sum = temp_sum;
		}

		else{
			break;
		}
	}

	return result_sum;
}

int main(){
	fast();

	cin >> t;
	while(t--){
		cin >> n >> q;
		vll B;
		for(ll i=0;i<n;i++){
			ll temp;
			cin >> temp;

			B.pb(temp);
		}

		vll sum; // stores prefix sum
		sum.pb(B[0]);
		cout << "PREFIX SUM = " << sum[0] << " ";
		for(ll i=1;i<n;i++){
			sum.pb(B[i] + sum[i-1]);
			cout << sum[i] << " ";
		}
		cout << endl;

		for(ll i=0;i<q;i++){
			char choice;
			ll x, y;
			cin >> choice >> x >> y;

			if(choice == 'Q'){
				cout << "Q , " << x << " , " << y << endl;
				cout << Q(B,sum,x,y) << "\n";
			}

			else if(choice == 'U'){
				cout << "U , " << x << " , " << y << endl;
				U(B,sum, x, y);
			}
		}
	}
	
	return 0;
}