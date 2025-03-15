// EX_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

string isPalindromePermutation(const string& s) {
	unordered_map<char, int> freq;
	unsigned int i = 0;

	// Count character frequencies
	for (char c : s) {
		
		if (freq.find(c) == freq.end()) //if key not found
		{
			i = 0;
			i++;
			freq[c] = i;
		}
		else //if key found
		{
			i = freq[c];
			i++;
			freq[c] = i;
		}
		
		//freq[c]++;
	}

	int oddCount = 0;

	// Count how many characters have an odd frequency
	for (const auto& pair : freq) {
		char ch = pair.first;
		int count = pair.second;
		if (count % 2 != 0) {
			oddCount++;
		}

		// A string can be rearranged into a palindrome if at most one character has an odd frequency
		if (oddCount > 1) {
			return "NO";
		}
	}

	return "YES";
}

int main()
{
	string input;
	cin >> input;
	cout << isPalindromePermutation(input) << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
