#include <cstdio>
#include <iostream>
#include <string>
#include <sstream> 
#include <vector>
using namespace std;

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif 
	
	string line;
	vector<string> words[1010];
	int w_maxsize[200] = {0};
	int l_index = 0;
	while (cin) {
		getline(cin, line);
		if (line.size() == 0) break; 
		istringstream ss(line);
		
		string w;
		int w_index = 0;
		while (ss >> w) {
			words[l_index].push_back(w);
			if (w.size() > w_maxsize[w_index]) {
				w_maxsize[w_index] = w.size();
			}
			w_index++;
		}
		l_index++;
	}
	
	int l_size = l_index;
	for (l_index = 0; l_index < l_size; l_index++) {
		for (int i = 0; i < words[l_index].size(); i++) {
			string w = words[l_index][i];
			cout << w;
			
			if (i < words[l_index].size()-1) {
				for (int j = w.size(); j < w_maxsize[i]; j++) {
					cout << " ";
				} 	
				cout << " "; 
			}
		}
		cout << endl;
	}
	return 0;
} 
