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

bool isIntersect(int y1, int x1, int depth1, int y2, int x2, int depth2)
{
	if((abs(x2 - x1) <= depth1 && abs(y2 - y1) <= depth2) || (abs(x2 - x1) <= depth2 && abs(y2 - y1) <= depth1))
	{
		return true;
	}
	if((y1 == y2 && abs(x1 - x2) <= depth1 + depth2) || (x1 == x2 && abs(y1 - y2) <= depth1 + depth2))
	{
		return true;
	}
	return false;
}

int main()
{
//	cout << "brute force branch" << endl;
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
			int max2K = 0, max2L = 0, bestDepth1 = 0, bestDepth2 = 0,
					highestVal = 0;
			for (int d1 = 0; d1 <= depthSet[i][j]; d1++)
			{
				for (int k = 1; k < height - 1; k++)
				{
					for (int l = 1; l < width - 1; l++)
					{
						for (int d2 = 0; d2 <= depthSet[k][l]; d2++)
						{
							if (k != i || l != j)
							{
								if (!(isIntersect(i,j,d1,k,l,d2)))
								{
									if (((4 * d1) + 1) * ((4 * d2) + 1)
											> highestVal)
									{
										highestVal = ((4 * d1) + 1)
												* ((4 * d2) + 1);
										max2K = k;
										max2L = l;
										bestDepth1 = d1;
										bestDepth2 = d2;
									}
								}
							}
						}
					}
				}
			}
			solnSet[i][j] = ((4 * bestDepth1) + 1)
					* ((4 * bestDepth2) + 1);
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
//	cout << endl << solnSet[1][8] << endl << depthSet[5][5];

	return 0;
}


