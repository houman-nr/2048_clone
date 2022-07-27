#include <iostream>
using namespace std;
int main()
{
	long long n[30], m[10], sum;
	for (int i = 0; i <= 29; i++) cin >> n[i];
	for (int j = 1; j <= 29;j + 3)
	{
		sum = 0;
		for (int i = j - 1;i <= j + 1;i++) sum = sum + n[i];
		m[(j - 1) / 3] = sum;
	}
	for (int i = 0; i <= 9;i++) cout << m[i] << " ";
}