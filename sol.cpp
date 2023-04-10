#include <bits/stdc++.h>
using namespace std;

/*

1 2 1 4
1 0 1 2
0 0 0 2

1 1 2 4
1 1 0 2 (2 moves)
1 0 0 1 (1 move)
0 0 0 0 (1 move)
total = 4 moves

1 1 2 4
1 1 2 0 (1 move)
1 0 1 0 (1 move)
0 0 0 0 (1 move)
total = 3 moves

if freq[num] is odd, then kill one monster
if freq[num] is even, then choose min(freq[num], by pairs)

n = 7
3 3 3 3 3 4 5
3 3 3 3 3 4 0 (1 move)
3 3 3 3 3 0 0 (1 move)
3 3 3 3 0 0 0 (1 move)
3 3 0 0 0 0 0 (3 move)
0 0 0 0 0 0 0 (3 move)
total = 9 moves



*/

void test_case(int& tc) {
	int n;
	cin >> n;
	int h[n], mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		mx = max(mx, h[i]);
	}
	int freq[mx+1];
	memset(freq, 0, sizeof(freq));
	for (int x : h)
		freq[x]++;
	int ans = 0;
	for (int num = 1; num <= mx; num++) {
		if (freq[num] % 2 == 1) {
			ans++;
			freq[num]--;
		}
		ans += min(freq[num], num * freq[num] / 2);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
