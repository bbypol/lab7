#include <iostream>
#include<fstream>

#include "Functions.hpp"

using namespace std;

namespace fc
{
	int flag1 = 0, flag2 = 0, flag = 0;
	int pr1 = 1, pr2 = 1;
	void Read(int& n, int& m, int mass[100][100])
	{
		ifstream in("input.txt");
		in >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				in >> mass[i][j];
			}
		}
		in.close(); //��� ��� �������
	}


	int maxzn(int n, int m, int mass[100][100], int K)    //����� ������������� �������� � K ������  (�������� ��� ��� ������ �������� ._. )
	{
		for (K = 0; K < n; K++)
		{
			int jM = INT_MIN;
			for (int j = 1; j < m; j++)
			{
				if (mass[K][j] > mass[K][jM]) jM = j;
			}
		}
	}

	void diagonal1(int n, int m, int mass[100][100])
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if ((i == j) && (maxzn(n, m, mass, i) == mass[i][j]))
				{
					flag1 += 1;
					pr1 *= mass[i][j];
					break;

				}
			}
		}
	}


	void diagonal2(int n, int m, int mass[100][100])
	{
		if ((flag1 == n) || (flag2 == m))
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if ((i == m - j - 1) && (maxzn(n, m, mass, i) == mass[i][j]))
					{
						flag2 += 1;
						pr2 *= mass[i][j];
						break;
					}
				}
			}
	}

	void proverka(int n, int m, int mass[100][100])
	{
		if (flag1 == flag2)
		{
			int x = 0;
			for (int j = 0; j < m; j++)
			{
				for (int i = 0; i < n; i++)
				{
					if (mass[i][j] == 0) //��������� ����� �� ����
					{
						mass[i][j] = (pr1 * pr2);
						break;
					}
					else
					{
						while (mass[i][j] > 0) //���� ������ � �����)
						{
							x = abs(mass[i][j]);
							if (x == 0)
							{
								mass[i][j] = (pr1 * pr2);
								break;
							}
							mass[i][j] /= 10;
						}

					}

				}
			}
		}

	}

	void Out(int n, int m, int mass[100][100])
	{
		ofstream out("output.txt");
		out << "\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				out << mass[i][j] << " ";
			}
			out << "\n";
		}
		out.close(); //� ��� ������� ^-^
	}
}
	