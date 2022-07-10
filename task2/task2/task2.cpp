
#include <iostream>
using namespace std;
void printSubs(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == 0) {
                cout << "{" << a[i] << "..." << a[j] << "}"<<endl;
            }
        }
    }
}
int main()
{
    int A[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    printSubs(A, n);
}

