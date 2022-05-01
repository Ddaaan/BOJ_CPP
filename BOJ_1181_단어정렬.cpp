#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {
	int n;
	string temp;
	cin >> n;
	vector <string> word;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		word.push_back(temp);
	}
	sort(word.begin(), word.end(), compare);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << word[0] << "\n";
			continue;
		}
		else {
			if (word[i] != word[i - 1]) cout << word[i] << "\n";
		}
	}
	return 0;
}