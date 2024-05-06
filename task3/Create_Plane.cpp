#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void Create_Plane(vector<string>& towns, vector<string>& planes, map<string,vector<string>>& route) {
	string plane, str_towns; //самолет и остановки

	cout << "Введите название самолета: ";
	cin >> plane;
	cin.ignore();
	planes.push_back(plane); //добавь в вектор всех самолетов

	cout << "Введите города, через которые пролетает самолет через пробел: "; //добавляем в города
	getline(cin, str_towns);  //закинули строчку 
	string town;

	for (auto a : str_towns) { //добавляем все города
		if (a != ' ') {
			town.push_back(a);

		} else {                  //дошли до пробела
			towns.push_back(town);       //в вектор городов -город
			route[town].push_back(plane);  //в вектор дорог(map) по городу добавляем самолет
			route[plane].push_back(town);  //и также по ключу самолеты
			town.clear();  //почисти строку
		}
	}
    
	towns.push_back(town); //последний город самолета не забудь закинуть
	route[town].push_back(plane);
	route[plane].push_back(town);
	cout << "Ваш самолет был добавлен в расписание!!" << endl;
}
