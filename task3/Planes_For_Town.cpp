#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void Planes_For_Town(map<string, vector<string>>& route) {
	string town;
	cout << "Введите название города: "; //какой город проверяем
	cin >> town;

	if (route.count(town) > 0) {          //пока есть самолеты
		cout << "Через город " << town << " пролетают самолеты: ";
		for (string plane : route[town]) {  //выведи все значения по ключу город
			cout << plane << " ";
		}

	} else {
		cout << "Город "<< town <<" не найден";
	}
	cout << endl;
}