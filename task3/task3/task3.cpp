#include <iostream>
using namespace std;
void Pair(int arr[], int n, int t) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == t)
            {
                cout << arr[i] << " " << arr[j] << endl;
                return;
            }
        }
    }
    cout << "Pair not found" << endl;
}
int main()
{
    int arr[100];
    int n;
    cin >> n;
    int t;
    cin >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Pair(arr, n, t);
}

