/*
ID: jason.z2
PROG: palsquare
LANG: C++
*/

#include <fstream>
#include <array>
#include <string>
#include <algorithm>

bool isPalindrome(std::string s);
std::string changeBase(int base, int num);

std::array<char, 20> baseChars = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J' };

int main() {
	int base;
	std::ifstream input("palsquare.in");
	input >> base;
	input.close();

	std::ofstream output("palsquare.out");

	for (int i = 1; i <= 300; i++) {
		int isd = i * i;
		if (isPalindrome(changeBase(base, isd))) {
			output << changeBase(base, i) << " " << changeBase(base, isd) << "\n";
		}
	}

	output.close();
	return 0;
}

bool isPalindrome(const std::string s) {
	std::string _string = s;
	std::string _string2 = s;
	std::reverse(_string2.begin(), _string2.end());
	if (_string != _string2) return false;
	else return true;
}

std::string changeBase(const int base, const int num) {
	int num2 = num;
	std::string s = "";

	while (1) {
		if (base > num2) break;
		s += baseChars[num2 % base];
		num2 /= base;
	}
	s += baseChars[num2 % base];


	std::reverse(s.begin(), s.end());

	return s;
}
