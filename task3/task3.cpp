#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "Create_Plane.h"
#include "Planes_For_Town.h"
#include "Towns_For_Plane.h"
#include "Planes.h"
using namespace std;

enum planetown {      //перечислимый тип, ввод с консоли числа
	CREATE_PLANE = 1,  
	PLANES_FOR_TOWN,
	TOWNS_FOR_PLANE,
	PLANES,
	EXIT
};

int main() {
	system("chcp 65001");

	cout << "График движения самолетов" << endl <<
		"(1) Создание самолета, который пролетает через город или несколько городов. " << endl <<
		"(2) Вывод всех самолетов, которые пролетают через указанный город." << endl <<
		"(3) Вывод всех городов, которые пролетает указанный самолет." << endl <<
		"(4) Отображение всех самолетов с их маршрутами" << endl <<
		"(5) Выход из программы." << endl;

	bool exit = true;
	vector<string> towns;
	vector<string> planes;
	map <string, vector <string>> route;

	for (int i = 0; exit; i++) {     //считываем команду с клавиатуры
		cout << "Введите команду: ";
		int command;
		cin >> command;

		if (command == planetown::CREATE_PLANE) {
			Create_Plane(towns, planes, route);
            
		} else if (command == planetown::PLANES_FOR_TOWN) {
			Planes_For_Town(route);

		} else if (command == planetown::TOWNS_FOR_PLANE) {
			Towns_For_Plane(route);

		} else if (command == planetown::PLANES) {
			if (!route.empty()) {
				Planes(planes, route);

			} else {
				cout << "Вы не добавили ни одного самолета!" << endl;
			}
		} else if (command == planetown::EXIT) {
			cout << "Спасибо за использование!";
			break;
		}
	}
}