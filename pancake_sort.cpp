// Stack pancakes from smallest at top to largest at bottom. The only operation permitted is a flip.
// A flip at index i reverses the elements from index 0 to i.
// http://datagenetics.com/blog/february42018/index.html
// https://austingwalters.com/everyday-algorithms-pancake-sort/
// For example,
// Let the order be 2, 4, 3, 1 (Top to bottom)
// Flipping at index 1 gives: 4, 2, 3, 1
// Flipping at index 3 gives: 1, 3, 2, 4
// Flipping at index 1 gives: 3, 1, 2, 4
// Flipping at index 2 gives: 2, 1, 3, 4
// Flipping at index 1 gives: 1, 2, 3, 4
// Done

// 1. Move largest out of order pancake to top then bottom. Time - O(N^2), Space - O(1).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void pancake_sort(vector<int> a);
void flip(vector<int>& a, int end);

int main()
{
	vector<int> a = {3, 1, 5, 4, 2};
	pancake_sort(a);
	return 0;
}

void pancake_sort(vector<int> a)
{
	int size = a.size();
	for(int i = 0; i < size - 1; i++) {
		int flip_idx = distance(a.begin(), max_element(a.begin(), a.end() - i));
		flip(a, flip_idx);
		flip(a, size - 1 - i);
	}
	
	for(auto& i: a)
		cout << i << " ";
	cout << "\n";
}

void flip(vector<int>& a, int end)
{
	int start = 0;
	while(start < end) {
		swap(a[start], a[end]);
		start++;
		end--;
	}
}