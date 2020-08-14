#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype> 
#include <vector> 
using namespace std;

string repr(const string& s) {
	string ans = s;
	for (int i = 0; i < ans.size(); i++) {
		ans[i] = tolower(ans[i]);
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	map<string, int> dict;
	vector<string> word_vec;
	vector<string> ans_vec;
	string word;
	
	while (cin >> word) {
		if (word == "#") break;
		word_vec.push_back(word);
		
		word = repr(word);
		if (dict.find(word) == dict.end()) {
			dict[word] = 1;
		} else {
			dict[word]++;
		}
		
	}
	
	for (int i = 0; i < word_vec.size(); i++) {
		word = word_vec[i];
		if (dict[repr(word)] == 1) {
			ans_vec.push_back(word); 
		}
	}
	sort(ans_vec.begin(), ans_vec.end());
	for (int i = 0; i < ans_vec.size(); i++) {
		cout << ans_vec[i] << endl;
	}
	
	return 0;
} 
