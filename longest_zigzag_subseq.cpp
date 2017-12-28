// Question in below links
// https://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493
// Screenshot - https://i.imgur.com/9JB2PmR.png

// 1. Solution using DP. Time - O(N^2), Space - O(N).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lzs(vector<int> a)
{
	int n = a.size();
	if(n == 0)
		return 0;
		
	vector<int> up(n, 1);
	vector<int> down(n, 1);
	int max_len = 1;
	int old_len = 0, new_len = 0, diff = 0;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			diff = a[i] - a[j];
			if(diff > 0) {
				old_len = up[i];
				new_len = down[j] + 1;
				if(new_len > old_len)
					up[i] = new_len;
			}
			else if(diff < 0) {
				old_len = down[i];
				new_len = up[j] + 1;
				if(new_len > old_len)
					down[i] = new_len;
			}
		}
		max_len = max(max_len, max(up[i], down[i]));
	}
	
	return max_len;
}

int main()
{
	vector<int> a = {1, 7, 4, 9, 2, 5};
	vector<int> b = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
	vector<int> c = {44};
	vector<int> d = {1, 1};
	vector<int> e = {1, 2, 3, 4, 5, 6};
	cout << lzs(a) << "\n" << lzs(b) << "\n" << lzs(c) << "\n" << lzs(d) << "\n" << lzs(e) << "\n";
	return 0;
}