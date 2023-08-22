#include <iostream>
using namespace std;

const int MAX = 1000;
int N;
int arr[MAX];

int res[MAX];

void mergeSort(int s, int e, int arr[], int res[]) {
	if (s >= e) return;

	int m = (s + e) / 2;

	mergeSort(s, m, arr, res);
	mergeSort(m + 1, e, arr, res);

	int i = s;
	int j = m+1;

	int k = s;
	for (k = s; k <= e;) {
		if (i > m) res[k++] = arr[j++];
		else if (j > e) res[k++] = arr[i++];
		else {
			if (arr[i] <= arr[j]) res[k++] = arr[i++];
			else res[k++] = arr[j++];
		}
	}

	for (int i = s; i <= e; ++i) {
		arr[i] = res[i];
	}

	for (int i = 0; i < N; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(void) {
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	mergeSort(0, N - 1, arr, res);

	

}