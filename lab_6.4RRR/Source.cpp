#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
using namespace std;
int a;
int b;
int k = 0;
void Create(int* mas, int size, int i)
{
	mas[i] = -100 + rand() % (-200 + 1);
	if (i < size - 1)
		Create(mas, size, i + 1);
}


void Print(int* a, int size, int i)
{
	cout << setw(2) << a[i] << " ";
	if (i < size - 1)
		Print(a, size, i + 1);
}
int Max(int* mas, const int size, int i, int max)
{
	if (max <= mas[i])
		max = mas[i];
	if (i < size - 1)
		return Max(mas, size, i + 1, max);
	else
		return max;
}
int Sum(int* mas, const int size, int i, int j, int S, int k)
{
	if (i < size - k - 1)
	{
		S += mas[i];
	}
	if (j < 0 && mas[j] > 0)
		k++;
		
	if (i < size - 1)
	{
		return Sum(mas, size, i + 1, j - 1, S, k);
	}
			else
			{
				return S;
			}
}
void Shrink(int* mas, int size, int i)
{

	if (abs(mas[i]) >= a && abs(mas[i]) <= b)
	{
		mas[i] = 0;
		if (abs(mas[size - k - 1]) >= a && abs(mas[size - k - 1]) <= b)
		{
			mas[size - k - 1] = 0;
			swap(mas[i], mas[size - k - 2]);
			k += 2;
		}
		else
		{
			swap(mas[i], mas[size - k - 1]);
			k++;
		}
	}
	if (i < size - 1)
		Shrink(mas, size, i + 1);
}
int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "n = "; cin >> n;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	int* mas;
	mas = new int[n];
	Create(mas, n, 0);
	cout << "a[";
	Print(mas, n, 0);
	cout << "]" << endl;
	cout << "Max Element = " << Max(mas, n, 0, 0) << endl;
	cout << "Sum = " << Sum(mas, n, 0, n, 0, 0) << endl;
	Shrink(mas, n, 0);
	n -= k;
	cout << "a[";
	Print(mas, n, 0);
	cout << "]" << endl;
	return 0;
}