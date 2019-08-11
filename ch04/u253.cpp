#include <cstdio>
#include <cstring>
#include <cstdlib>

char s[20];
char rotated_s[20];
bool rotated_same;

bool Same() {
	bool res = true;
	for (int i = 0; i < 6; i++) {
		if (rotated_s[i] != rotated_s[6+i]) res = false; 
	} 
	return res;
}

// rotate the cube according to the part in x, y, z axies 
bool rotate(int h, int v, int k) {
	char vs[4];
	vs[0] = rotated_s[0];
	vs[1] = rotated_s[1];
	vs[2] = rotated_s[5];
	vs[3] = rotated_s[4];
	rotated_s[0] = vs[h%4];
	rotated_s[1] = vs[(h+1)%4];
	rotated_s[5] = vs[(h+2)%4];
	rotated_s[4] = vs[(h+3)%4];
	
	char hs[4];
	hs[0] = rotated_s[1];
	hs[1] = rotated_s[3];
	hs[2] = rotated_s[4];
	hs[3] = rotated_s[2];
	rotated_s[1] = hs[v%4];
	rotated_s[3] = hs[(v+1)%4];
	rotated_s[4] = hs[(v+2)%4];
	rotated_s[2] = hs[(v+3)%4];
	
	char ks[4];
	ks[0] = rotated_s[0];
	ks[1] = rotated_s[2];
	ks[2] = rotated_s[5];
	ks[3] = rotated_s[3];
	rotated_s[0] = ks[k%4];
	rotated_s[2] = ks[(k+1)%4];
	rotated_s[5] = ks[(k+2)%4];
	rotated_s[3] = ks[(k+3)%4];
}

bool RotateOrien(int orien) {
	if (orien == 1) {
		char c = rotated_s[0];
		rotated_s[0] = rotated_s[1];
		rotated_s[1] = rotated_s[5];
		rotated_s[5] = rotated_s[4];
		rotated_s[4] = c;
	} else if (orien == 2) {
		char c = rotated_s[1];
		rotated_s[1] = rotated_s[3];
		rotated_s[3] = rotated_s[4];
		rotated_s[4] = rotated_s[2];
		rotated_s[2] = c;
	} else {
		char c = rotated_s[0];
		rotated_s[0] = rotated_s[2];
		rotated_s[2] = rotated_s[5];
		rotated_s[5] = rotated_s[3];
		rotated_s[3] = c;
	}
} 

int main() {
	#ifdef LOCAL
	freopen("253.in", "r", stdin);
	freopen("253.out", "w", stdout);
	#endif
	
	
	while (scanf("%s", s) == 1 && strlen(s)>0) {
		rotated_same = false;
		strcpy(rotated_s, s);
		for (int h = 0; h < 4; h++) {
			RotateOrien(1);
			for (int v = 0; v < 4; v++) {
				RotateOrien(2);
				for (int k = 0; k < 4; k++) {
					RotateOrien(3);
					if (rotated_same = Same()) break;
				}
				if (rotated_same) break;
			} 
			if (rotated_same) break;
		}
		
		if (rotated_same) printf("TRUE\n");
		else printf("FALSE\n");
	} 
	
	return 0;
} 


