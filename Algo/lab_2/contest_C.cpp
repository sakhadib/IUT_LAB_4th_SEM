#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second

int cntSortness(string s){
	int n = s.size(), i, j, cnt = 0;
	for(i = 0; i < n - 1; i++){
		for(j = i + 1;  j < n; j++){
			if(s[i] > s[j]) cnt++;
		}
	}
	return cnt;
}

bool cmp(pair<string, int> a, pair<string, int> b){
	int x = cntSortness(a.fr);
	int y = cntSortness(b.fr);
	if(x != y) return x < y;
	return a.sc < b.sc;
}

signed main()
{
    // // Redirect input from input.txt
    // ifstream in("../input.txt");
    // cin.rdbuf(in.rdbuf());

    // // Redirect output to output.txt
    // ofstream out("../output.txt");
    // cout.rdbuf(out.rdbuf());
	
	int tst, len, n, i;
	cin >> tst;

	for(int k = 1; k <= tst; k++){
		cin.ignore();
		cin >> len >> n;
		vector<pair<string, int> > v(n);
		
		int i = 0;
		for(auto &e : v) cin >> e.fr, e.sc = i++;
		sort(v.begin(), v.end(), cmp);

		for(auto &e : v) cout << e.fr << "\n";
		if(k != tst) cout << "\n";
	}
	
	return 0;
}