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

int t, n;

int main(){
	fast();
	cin >> t;

	while(t--){
		cin >> n;
		vector<char> a;
		int x=0, y=0;


		char prev = '\0';;
		for(int i=0;i<n;i++){
			char c;
			cin >> c;

			if(c == prev){
				continue;
			}

			if((c == 'L' && prev == 'R') || (c=='R' && prev=='L') || (c=='U' && prev=='D') || (c=='D' && prev == 'U')){
				continue;
			}

			else{
				switch(c){
					case 'L':
						x--;
						break;

					case 'R':
						x++;
						break;

					case 'U':
						y++;
						break;

					case 'D':
						y--;
						break;
				}

				prev = c;
			}
		}

		cout << x << " " << y << "\n";
	}
	
	
	return 0;
}