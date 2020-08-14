#include <cstdio>
#include <iostream> 
#include <set>
#include <string>
#include <sstream>
using namespace std;

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	set<string> dict;
	string s, buf;
	while (cin >> s) {
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i])) {
				s[i] = tolower(s[i]);
			} else {
				s[i] = ' ';
			}
		}
		stringstream ss(s);
		while (ss >> buf) {
			dict.insert(buf);
		}
	}
	
	auto it = dict.begin();
	while (it != dict.end()) {
		cout << *it << endl;
		it++;
	} 
	
	return 0;
}
