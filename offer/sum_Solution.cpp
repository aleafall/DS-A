//
// Created by aleafall on 17-2-16.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int Sum_Solution(int n) {
		return n ? n + Sum_Solution(n - 1) : 0;
	}
};
int main(){
	Solution solution;
	cout << solution.Sum_Solution(100) << endl;
	return 0;
}