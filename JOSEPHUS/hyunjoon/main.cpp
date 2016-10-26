#include <iostream>
using namespace std;

typedef struct _soldier {
	int number;
	struct _soldier* next;
	struct _soldier* prev;
} soldier;

int live1, live2;

void run(int n, int k);

int main() {
	int count;
	cin >> count;
	
	for (int i = 0; i < count; ++i) {
		int n, k;
		cin >> n >> k;
		run(n, k);
		cout << live1 << " " << live2 << endl;
	}
	
	return 0;
}

void run(int n, int k) {
	soldier* first = (soldier*)malloc(sizeof(soldier)*n);
	soldier* iter = first;
	
	first[0].next = &first[1];
	first[0].prev = &first[n-1];
	first[0].number = 1;
	for (int i = 1; i < n-1; ++i) {
		first[i].next = &first[i+1];
		first[i].prev = &first[i-1];
		first[i].number = i+1;
	}
	first[n-1].next = &first[0];
	first[n-1].prev = &first[n-2];
	first[n-1].number = n;
	
	for (int i = 0; i < n-2; ++i) {
		iter->prev->next = iter->next;
		iter->next->prev = iter->prev;
		for (int j = 0; j < k; ++j) {
			iter = iter->next;
		}	
	}
	
	live1 = iter->number;
	live2 = iter->next->number;
	
	if (live1 > live2) {
		int temp = live1;
		live1 = live2;
		live2 = temp;
	}
	
	free(first);
}
