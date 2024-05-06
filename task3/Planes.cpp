#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

void Planes(vector<string>& planes, map<string, vector<string>>& route) {
	for (string plane : planes) {
		cout << "Самолет " << plane << " пролетает через следующие остановки:";
		for (string town : route[plane]) {
			cout << town << " ";
		}
		cout << endl;
	}
	cout << endl;
}
