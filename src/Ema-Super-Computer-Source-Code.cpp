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

	int depthSet[height][width] = {};

//	cout << height;
//	cout << width;

	bool grid[height][width] = {};

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

	int max1I = 0, max1J = 0, max2I = 0, max2J = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (depthSet[i][j] > depthSet[max1I][max1J])
			{
				max1I = i;
				max1J = j;
			}
		}
	}

//	cout << max1I << " " << max1J << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (depthSet[i][j] > depthSet[max2I][max2J] && (i != max1I || j != max1J))
			{
				if( !(abs(max1I - max2I) < depthSet[max1I][max1J] && abs(max1J - max2J) < depthSet[max1I][max1J]) )
				{
					max2I = i;
					max2J = j;
				}
			}
		}
	}

//	cout << max2I << " " << max2J << endl;

	cout << ((depthSet[max1I][max1J] * 4 + 1) * (depthSet[max2I][max2J] * 4 + 1));

	return 0;
}
