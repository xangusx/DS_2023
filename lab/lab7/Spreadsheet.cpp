#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5+10;

int n, m, a[N];
int dp[N];
int state[N]; // 0: unvisited, 1: finished, -1: instack
vector<int> G[N];

int f(int u) {	// return -1 if answer d.n.e, else return answer
	if (state[u] == -1) return -1;	
	if (state[u] == 0) {
		state[u] = -1;
		dp[u] = a[u];
		for (auto v: G[u]) {
			int ans = f(v);
			if (ans < 0) return -1;
			dp[u] += ans;
		}	
		state[u] = 1;
	}
	return dp[u];
}

int main() {
	
	cin >> n >> m;
	
	while (m--) {
		char opr;
		int u, v;
		cin >> opr >> u;
		for (int i='A'; i<opr; i++) {
			cin >> v;
			G[u].push_back(v);
		}
		cin >> a[u];
	}

	for (int i=1; i<=n; i++) {
		int ans = f(i);
		if (ans < 0) cout << "#REF!\n";
		else cout << ans << '\n';
	}
}