#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void Planes_For_Town(map<string, vector<string>>& route) {
	string town;
	cout << "Введите название города:";
	cin >> town;

	if (route.count(town) > 0) {
		cout << "Через город " << town << " пролетаютт самолеты:";
		for (string plane : route[town]) {
			cout << plane << " ";
		}

	} else cout << "Город "<< town <<" не найден";
	cout << endl;
}