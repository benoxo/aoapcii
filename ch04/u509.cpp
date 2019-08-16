#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char HEX[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int D, S, B;
char parity;
vector<string> vdata;
int nset;	// record the #disk set
	
bool Validate() {
	int fbit = (parity == 'E' ? 0 : 1); 
	bool valid = true;
	for (int sb = 0; sb < S*B; sb++) {
		// validate
		int sum = 0;	// sum of bits
		int nxbit = 0;	// number of x
		int xpos = -1;	// index of x
		for (int d = 0; d < D; d++) {
			char cbit = vdata[d][sb];
			if ( cbit == 'x' ) {
				nxbit++;
				xpos = d;
				continue;
			} 
			sum += cbit - '0';
		}
		if ((nxbit == 0 && (sum + fbit)%2) || nxbit > 1) {
			valid = false;
			break;
		}
		// recover the data
		if (nxbit) vdata[xpos][sb] = (sum + fbit)%2 + '0';
	}
	return valid;
}

string GetContents() {
	string content;
	string datastr;
	for (int b = 0; b < B; b++) {
		for (int d = 0; d < D; d++) {
			if (b % D == d) continue;
			
			string bistr = vdata[d].substr(b*S, S);
			datastr += bistr;
		}
	}
	
	//  add extra '0' bits
	while (datastr.size() % 4) {
		datastr.push_back('0');
	}
	while ( datastr.size() >= 4 ) {
		string bistr = datastr.substr(0, 4);
		int hexidx = 0;
		while (!bistr.empty()) {
			hexidx = hexidx*2 + bistr.front() - '0';
			bistr.erase(0, 1);
		}
		
		content += HEX[hexidx];
		datastr.erase(0, 4);
	}
	return content;
}

int main() {
	#ifdef LOCAL
	freopen("509i.txt", "r", stdin);
	freopen("509o.txt", "w", stdout);
	#endif
	
	nset = 0;
	while ( cin >> D && D ) {
		nset++;
		cin >> S >> B;
		getchar(); // filter \n 
		cin >> parity;
		vdata.clear();
		
		for (int d = 0; d < D; d++) {
			string strdata;
			cin >> strdata;
			vdata.push_back(strdata);
		}
		
		if (!Validate()) {
			cout << "Disk set " << nset << " is invalid." << endl;
		} else {
			cout << "Disk set " << nset << " is valid, contents are: " << GetContents() << endl;
		}
	}
	
	
	return 0;
} 
