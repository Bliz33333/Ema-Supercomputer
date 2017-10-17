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

struct plus
{
	int yPos;
	int xPos;

	int armLength;
};

int main()
{
	int height;
	int width;

	cin >> height;
	cin >> width;
//	cout << height;
//	cout << width;
	bool grid[height][width];

	for(int i = 0; i < height; i++)
	{
		string s;
		cin >> s;

		for(int j = 0; j < width; j++)
		{
			if(s.substr(j, 1) == "G")
			{
				grid[i][j] = true;
			}
			else
			{
				grid[i][j] = false;
			}
			cout << grid[i][j];
		}
		cout << endl;

	}


	return 0;
}
