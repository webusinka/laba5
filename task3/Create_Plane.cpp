#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void Create_Plane(vector<string>& towns, vector<string>& planes, map<string,vector<string>>& route) {
	string plane, str_towns;

	cout << "Введите название самолета: ";
	cin >> plane;
	cin.ignore();
	planes.push_back(plane);

	cout << "Введите города, через которые пролетает самолет через пробел: ";
	getline(cin, str_towns);
	string town;

	for (auto a : str_towns) {
		if (a != ' ') {
			town.push_back(a);

		} else {
			towns.push_back(town);
			route[town].push_back(plane);
			route[plane].push_back(town);
			town.clear();
		}
	}
    
	towns.push_back(town);
	route[town].push_back(plane);
	route[plane].push_back(town);
	cout << "Ваш самолет был добавлен в расписание!!" << endl;
}
