// Question in below links
// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=1759
// Direct link - https://icpcarchive.ecs.baylor.edu/external/37/3758.pdf
// Screenshots - https://i.imgur.com/CxGn2aT.png  https://i.imgur.com/vF7FrxV.png

#include <iostream>
using namespace std;

int top_corner(int N)
{
	if(N == 1)
		return 2;
	int result = N * N - N + 1;
	return result;
}

int main()
{
	int N;
	while(true) {
		cin >> N;
		if(N == 0)
			break;
		int result = top_corner(N);
		cout << N << " => " << result << "\n";
	}
}