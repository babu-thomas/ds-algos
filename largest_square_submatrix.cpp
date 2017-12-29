// Given a binary matrix, find out the maximum size square sub-matrix with all ones.
// For example,
// Input -
//  1 1 0
//  1 1 0
//  0 0 1
// Output - 2

// 1. Brute force solution. Time - Exponential. Space - O(1).
// 2. DP solution. Time - O(M*N) and Space - O(M*N), where M and N are number of rows and columns.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> ivec2d;

int lss1(const ivec2d& mat);
int lss1(const ivec2d& mat, int r, int c);
int lss2(const ivec2d& mat);

int main()
{
	ivec2d mat1 =
	{
		{ 1, 0, 0, 0, 0 },
		{ 1, 0, 1, 1, 0 },
		{ 0, 1, 1, 1, 1 },
		{ 0, 1, 0, 0, 0 }
	};
	
	ivec2d mat2 =
	{
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 }, 
		{ 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1 }
	};
	
	cout << lss1(mat1) << "\n" << lss1(mat2) << "\n";
	cout << lss2(mat1) << "\n" << lss2(mat2) << "\n";
	
	return 0;
}

int lss1(const ivec2d& mat)
{
	int rows = mat.size();
	int cols = mat[0].size();
	int max_size = 0;
	for(int i = rows - 1; i >= 0; i--) {
		for(int j = cols - 1; j >= 0; j--) {
			if(mat[i][j] == 1)
				max_size = max(max_size, lss1(mat, i, j));
		}
	}
	
	return max_size;
}

int lss1(const ivec2d& mat, int r, int c)
{
	if(r == 0 || c == 0 || mat[r][c] == 0)
		return mat[r][c];
	
	int left = lss1(mat, r, c - 1);
	int top = lss1(mat, r - 1, c);
	int top_left = lss1(mat, r - 1, c - 1);
	
	return 1 + min(left, min(top, top_left));
}

int lss2(const ivec2d& mat)
{
	ivec2d dp = mat;
	int rows = dp.size();
	int cols = dp[0].size();
	int max_size = 0;
	int left, top, top_left;
	
	for(int i = 1; i < rows; i++) {
		for(int j = 1; j < cols; j++) {
			if(dp[i][j] == 1) {
				left = dp[i][j - 1];
				top = dp[i - 1][j];
				top_left = dp[i - 1][j - 1];
				dp[i][j] = 1 + min(left, min(top, top_left));
				max_size = max(max_size, dp[i][j]);
			}
		}
	}
	
	return max_size;
}