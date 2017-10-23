/*
 * Ema-Super-Computer-Source-Code.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: s105308
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int height;
	int width;

	cin >> height;
	cin >> width;

	int depthSet[height][width] =
	{ };

//	cout << height;
//	cout << width;

	bool grid[height][width] =
	{ };

	for (int i = 0; i < height; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < width; j++)
		{
			if (s.substr(j, 1) == "G")
			{
				grid[i][j] = true;
			} else
			{
				grid[i][j] = false;
			}
//			cout << grid[i][j];
		}
//		cout << endl;

	}

//	height = 6;
//	width = 6;
//
//	int grid[6][6] = {
//	   {0, 1, 0, 0, 1, 0} ,
//	   {1, 1, 1, 1, 1, 1} ,
//	   {0, 1, 0, 0, 1, 0} ,
//	   {1, 1, 1, 1, 1, 1} ,
//	   {0, 1, 0, 0, 1, 0} ,
//	   {0, 1, 0, 0, 1, 0}
//	};
//
//	int depthSet[6][6] = {};

	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 1; j < width - 1; j++)
		{
			if (grid[i][j])
			{
				int depth = 0;
				while ((depth <= i) && (depth <= (height - 1) - i)
						&& (depth <= j) && (depth <= (width - 1) - j)
						&& grid[i + depth][j] && grid[i - depth][j]
						&& grid[i][j + depth] && grid[i][j - depth])
				{
					depth++;
				}
				depthSet[i][j] = depth - 1;
			}
		}
	}

//	for(int i = 0; i < height; i++)
//	{
//		for(int j = 0; j < width; j++)
//		{
//			cout << depthSet[i][j] << " ";
//		}
//		cout << endl;
//	}

	int solnSet[height][width] =
	{ };
	int solnKSet[height][width] =
	{ };
	int solnLSet[height][width] =
	{ };

	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 1; j < width - 1; j++)
		{
			int max2K = 0, max2L = 0;
			for (int k = 1; k < height - 1; k++)
			{
				for (int l = 1; l < width - 1; l++)
				{
					if (depthSet[k][l] > depthSet[max2K][max2L]
							&& (k != i || l != j))
					{
						if (!((abs(i - k) <= depthSet[i][j]
								|| abs(i - k) <= depthSet[k][l])
								&& (abs(j - l) <= depthSet[i][j]
										|| abs(j - l) <= depthSet[k][l]))
								&& !(i == k
										&& abs(j - l)
												<= depthSet[i][j]
														+ depthSet[k][l])
								&& !(j == l
										&& abs(i - k)
												<= depthSet[i][j]
														+ depthSet[k][l]))
						{
							max2K = k;
							max2L = l;
						}
					}
				}
			}
			solnSet[i][j] = (4 * depthSet[i][j] + 1)
					* (4 * depthSet[max2K][max2L] + 1);
			solnKSet[i][j] = max2K;
			solnLSet[i][j] = max2L;
		}
	}

	int maxSoln = 0;
	int solnI = 0, solnJ = 0;
	for (int i = 1; i < height; i++)
	{
		for (int j = 1; j < width; j++)
		{
			if (solnSet[i][j] > maxSoln)
			{
				maxSoln = solnSet[i][j];
				solnI = i;
				solnJ = j;
			}
		}
	}

	cout << solnI << " " << solnJ << " " << depthSet[solnI][solnJ] << endl;
	cout << solnKSet[solnI][solnJ] << " " << solnLSet[solnI][solnJ] << " "
			<< depthSet[solnKSet[solnI][solnJ]][solnLSet[solnI][solnJ]] << endl;
	cout << maxSoln;

	return 0;
}
