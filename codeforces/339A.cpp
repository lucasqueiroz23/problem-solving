#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


void solve(std::string sum){
	std::vector<int> operands;
	for(int i = 0; i< sum.length(); i+=2){
		operands.push_back( (int) (sum[i]));
	}

	std::sort(operands.begin(), operands.end());
	for(int i = 0; i < operands.size(); i++){
		std::cout << (char) operands[i];
		if(i<operands.size() - 1)
			std::cout <<"+";
	}

	std::cout <<"\n";

}

int main(){
	std::string sum;
	std::cin >> sum;

	solve(sum);

	return 0;
}

