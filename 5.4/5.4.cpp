// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;

double S1(const int k, const int N, const int i)
{
	if (i > N)
		return 0;
	else
		return (1.*i * i) / (1.*k * k +1.* N * N) + S1(k, N, i + 1);
}
double S2(const int k, const int N, const int i)
{
	if (i < k)
		return 0;
	else
		return (1.*i * i) / (1.*k * k + 1.*N * N) + S2(k, N, i - 1);
}
double S3(const int k, const int N, const int i, double t)
{
	t = t +(1.*i * i) / (1.*k * k + 1.*N * N);
	if (i >= N)
		return t;
	else
		return S3(k, N, i + 1, t);
}
double S4(const int k, const int N, const int i, double t)
{
	t = t + (1.*i * i) / (1.*k * k + 1.*N * N);
	if (i <= k)
		return t;
	else
		return S4(k, N, i - 1, t);
}
double S5(const int k, const int N)
{
	double s = 0;
	for (int i = k; i <= N; i++)
		s += (1. * i * i) / (1. * k * k + 1. * N * N);
	return s;
}

int main()
{
	int k, N;
	cout << "k = "; cin >> k;
	cout << "N = "; cin >> N;
	cout << "(rec up ++) S1 = " << S1(k, N, k) << endl;
	cout << "(rec up --) S2 = " << S2(k, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(k, N, k, 0) << endl;
	cout << "(rec down --) S4 = " << S4(k, N, N, 0) << endl;
	cout << "(iter) S5 = " << S5(k, N) << endl;
	return 0;
}
