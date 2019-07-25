#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <cstdlib>
#include <vector> 
#include <algorithm>

using namespace std;

typedef struct S {
	long long SID;
	int CID;
	char Name[20];
	int Score[4];
	int removed;
	int TotalScore;
	int Rank;
	int Passed; 
	
	bool operator < (const S b) {
		return this->TotalScore > b.TotalScore;
	} 
} Student;
//map<long long, Student> stus;
vector<Student> stus;

void print_menu() {
    printf("Welcome to Student Performance Management System (SPMS).\n\n\
1 - Add\n\
2 - Remove\n\
3 - Query\n\
4 - Show ranking\n\
5 - Show Statistics\n\
0 - Exit\n\n");
}

vector<int> SearchByName(char name[]) {
	vector<int> v_idx;
	for (int i = 0; i < stus.size(); i++) {
//		if (stus[i].removed) continue;
		if (strcmp(stus[i].Name, name) == 0) {
			v_idx.push_back(i); 
		} 
	}
	return v_idx;
}

int SearchBySID(long long sid) {
	int index = -1;
	
	for (int i = 0; i < stus.size(); i++) {
//		if (stus[i].removed) continue;
		if (stus[i].SID == sid) {
			index = i;
			break; 
		} 
	}
	return index;
}

void Add() {
	while (true) {
		Student S;
		printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
		scanf("%lld", &S.SID);
		if (S.SID == 0) break;
		
		scanf("%d %s %d %d %d %d", &S.CID, S.Name, &S.Score[0], &S.Score[1], &S.Score[2], &S.Score[3]);
		if (SearchBySID(S.SID) > -1) {
			printf("Duplicated SID.\n");
			continue;
		}
		
		S.removed = 0;
		S.Passed = 0;
		S.TotalScore = S.Score[0] + S.Score[1] + S.Score[2] + S.Score[3]; 
		stus.push_back(S);
	}
}

void Remove() {
	while (true) {
		char op[20];
		Student S;
		printf("Please enter SID or name. Enter 0 to finish.\n");
		scanf("%s", op);
		if (strlen(op) == 1 && op[0] == '0') break;
		
		int removed = 0;
		if (isdigit(op[0])) {
			S.SID = atoll(op);
			int index = SearchBySID(S.SID);
			if (index > -1) {
//				stus[index].removed = 1;
				stus.erase(stus.begin() + index);
				removed++;
			}
		} else {
			strcpy(S.Name, op);
			vector<int> v_idx = SearchByName(S.Name);
			for (int i = v_idx.size()-1; i >= 0; i--) {
				int index = v_idx[i];
//				stus[index].removed = 1;
				stus.erase(stus.begin() + index);
			} 
			removed = v_idx.size();
		}
		
		printf("%d student(s) removed.\n", removed);
	}
}

bool SortByPtr(Student* A, Student* B) {
	return A->TotalScore > B->TotalScore;
}

void Rank() {
	vector<Student*> stuPtrs;
	for (int i = 0; i < stus.size(); i++) {
		stuPtrs.push_back(&stus[i]);
	}
	sort(stuPtrs.begin(), stuPtrs.end(), SortByPtr);
	int rank = 1;
	for (int i = 0; i < stuPtrs.size(); i++) {
		if (i > 0 && stuPtrs[i]->TotalScore < stuPtrs[i-1]->TotalScore) {
			rank = i+1;
		}
		stuPtrs[i]->Rank = rank;
	} 
}

void Query() {
	Rank();
	while (true) {
		char op[20];
		Student S;
		printf("Please enter SID or name. Enter 0 to finish.\n");
		scanf("%s", op);
		if (strlen(op) == 1 && op[0] == '0') break;
		
		if (isdigit(op[0])) {
			S.SID = atoll(op);
			int index = SearchBySID(S.SID);
			if (index > -1) {
				S = stus[index]; 
				printf("%d %010lld %d %s %d %d %d %d %d %.2f\n", 
					S.Rank, S.SID, S.CID, S.Name, S.Score[0], S.Score[1], S.Score[2], S.Score[3], S.TotalScore, S.TotalScore/4.0);
			}
		} else {
			strcpy(S.Name, op);
			vector<int> v_idx = SearchByName(S.Name);
			for (int i = 0; i < v_idx.size(); i++) {
				int index = v_idx[i];
				S = stus[index];
				printf("%d %010lld %d %s %d %d %d %d %d %.2f\n", 
					S.Rank, S.SID, S.CID, S.Name, S.Score[0], S.Score[1], S.Score[2], S.Score[3], S.TotalScore, S.TotalScore/4.0);
			} 
		}
	}
}

void ShowRank() {
	printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
}

void ShowStatistic() {
	printf("Please enter class ID, 0 for the whole statistics.\n");
	int cid, passed[4], failed[4], total[4], size;
	int stuPass[4]; // stuPass[0] represents the number of students passed 1 or more exam ...
	char courses[4][20];
	double avg[4];
	scanf("%d", &cid);
	
	strcpy(courses[0], "Chinese");
	strcpy(courses[1], "Mathematics");
	strcpy(courses[2], "English");
	strcpy(courses[3], "Programming");
	for (int i = 0; i < 4; i++) {
		passed[i] = failed[i] = 0;
		stuPass[i] = 0;
		total[i] = 0;
	}
	size = 0;
	
	for (int i = 0; i < stus.size(); i++) {
		if (cid != 0 && stus[i].CID != cid) continue;
		Student& S = stus[i];
		S.Passed = 0;
		for (int j = 0; j < 4; j++) {
			if (S.Score[j] < 60) {
				failed[j]++;
			} else {
				passed[j]++;
				S.Passed++;
			}
			total[j] += S.Score[j];
		}
		size++;
		switch(S.Passed) {
		case 4: stuPass[3]++;
		case 3: stuPass[2]++;
		case 2: stuPass[1]++;
		case 1: stuPass[0]++;
		}
	}
	
	for (int i = 0; i < 4; i++) {
		printf("%s\nAverage Score: %.2f\n", courses[i], total[i]*1.0/size);
		printf("Number of passed students: %d\n", passed[i]);
		printf("Number of failed students: %d\n\n", failed[i]);
	}
	printf("Overall:\nNumber of students who passed all subjects: %d\n", stuPass[3]);
	printf("Number of students who passed 3 or more subjects: %d\n", stuPass[2]);
	printf("Number of students who passed 2 or more subjects: %d\n", stuPass[1]);
	printf("Number of students who passed 1 or more subjects: %d\n", stuPass[0]);
	printf("Number of students who failed all subjects: %d\n\n", size - stuPass[0]);
	
}

int main() {
    #ifdef LOCAL
    freopen("12412.in", "r", stdin);
    freopen("12412.out", "w", stdout);
    #endif

    for (;;) {
        int choice;
        print_menu();
        scanf("%d", &choice);
        switch(choice) {
        case 0: break;
        case 1: Add(); break;
        case 2: Remove(); break;
        case 3: Query(); break;
        case 4: ShowRank(); break;
        case 5: ShowStatistic(); break;
        default: break;
        }

        if (!choice) break;
    }
    return 0;
}

