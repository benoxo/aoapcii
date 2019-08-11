#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, string> morse;	// morse code for each character
unordered_map<string, vector<string> > context;	// corresponding context

// check if a is prefix of b 
bool IsPrefix(string a, string b) {
	return a.size() <= b.size() && b.compare(0, a.size(), a) == 0;
} 

int main() {
	#ifdef LOCAL
	freopen("508.in", "r", stdin);
	freopen("508.out", "w", stdout);
	#endif
	
	char cha;
	string mors;
	while (cin >> cha && cha != '*') {
		cin >> mors;
		morse[cha] = mors;

	}
	
	string ctx;
	while (cin >> ctx && ctx != "*") {
		ostringstream ss; 
		for (char c : ctx) {
			ss << morse[c];
		}
		context[ss.str()].push_back(ctx);
	}
	
	string code;
	while (cin >> code && code != "*") {
		if (context.count(code)) {
			cout << context[code].front();
			if (context[code].size() > 1) cout << "!";
			cout << endl;
			continue;
		}
		
		map<int, string> ans;
		for (const auto& ctx : context) {
			string k = ctx.first;
			if ( IsPrefix(code, k) ) {
				ans[k.size() - code.size()] = ctx.second.front();
			} else if ( IsPrefix(k, code) ) {
				ans[code.size() - k.size()] = ctx.second.front();
			}
 		}
 		cout<<ans.begin()->second<<"?"<<endl;
	}
	return 0;
} 
