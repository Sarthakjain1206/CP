#include<string>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string s) {
	// stack <char> st;
	char prev_s;
	string output = "";
	int i = 0;
	while(i < s.length()) {
		
		if(s[i] == '/') {
			int length = output.length();
			if(length == 0 || output[length - 1] != '/')
				output.push_back(s[i]);
		}
		else if(s[i] != '/') {
			string curr_s = "";
			while(s[i] != '/') {
				curr_s.push_back(s[i]);
				i++;
			}
			i--;
			if(curr_s.length() > 2) output += curr_s;
			if(curr_s == "..") {
				output.pop_back();
				int length = output.length();
				while(length != 0 && output[length - 1] != '/')
					output.pop_back(), length--;
				if(length != 0) output.pop_back();
			}
		}
		i++;
	}
	cout << output;
	return "Hello";
}

int main() {
	string s;
	cin >> s;
	vector<int> v{0, 3, 5, 7};

	cout<<lower_bound(v.begin(), v.end(), 2) - v.begin();
	// cout<<simplifyPath(s);
}