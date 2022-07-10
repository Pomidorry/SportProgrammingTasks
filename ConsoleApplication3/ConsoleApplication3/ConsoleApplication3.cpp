#include<iostream>
using namespace std;
void sort(int arr[], int n){
	int z = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			z++;
		}
	}
	for (int i = 0; i < z; i++) {
		arr[i] = 0;
	}
	for (int i = z; i < n; i++) {
		arr[i] = 1;
	}
}
int main() {
	int A[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A, n);
	for (int i = 0; i < n; i++) {
		cout<< A[i]<<" ";
	}
}