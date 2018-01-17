// Given an MxN matrix, print it in spiral form
// For example,
// Input -
// 1 2 3
// 4 5 6
// 7 8 9
// Output -
// 1 2 3 6 9 8 7 4 5

// Time - O(N * M), Space - O(1)

#include <iostream>
#include <vector>
using namespace std;

void spiral_print(const vector<vector<int>>& mat)
{
	int rows = mat.size();
	int cols = mat[0].size();
	int count = rows * cols;
	
	// Number of rows and columns to print in current iteration
	int col_count = cols;
	int row_count = rows - 1;
	// Starting index for row and column
	int c = 0;
	int r = 0;
	// What to add to get to next row or column
	int c_next = 1;
	int r_next = 1;
	
	bool print_column = true;
	
	for(int i = 0; i < count;) {
		if(print_column) {
			cout << mat[r][c];
			i++;
			// Print col_count columns
			for(int j = 0; j < col_count - 1; j++) {
				c += c_next;
				cout << " " << mat[r][c];
				i++;
			}
			cout << "\n";
			// There will be one less column to print next time
			col_count--;
			// Move in reverse next time
			c_next *= -1;
			// Update r for printing rows next time
			r += r_next;
		}
		else {
			// Print row_count rows
			cout << mat[r][c];
			i++;
			for(int j = 0; j < row_count - 1; j++) {
				r += r_next;
				cout << " " << mat[r][c];
				i++;
			}
			cout << "\n";
			row_count--;
			r_next *= -1;
			c += c_next;
		}
		
		print_column = !print_column;
	}
}

int main()
{
	vector<vector<int>> mat = {{1, 2, 3, 4, 5},
							   {14, 15, 16, 17, 6},
							   {13, 20, 19, 18, 7},
							   {12, 11, 10, 9, 8}};
	spiral_print(mat);
	return 0;
}