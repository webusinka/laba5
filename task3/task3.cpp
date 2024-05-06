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

	cout << "График движения самолетов" << endl;
	cout <<	"(1) Создание самолета, который пролетает через город или несколько городов. " << endl;
	cout << "(2) Вывод всех самолетов, которые пролетают через указанный город." << endl;
	cout <<	"(3) Вывод всех городов, которые пролетает указанный самолет." << endl;
	cout <<	"(4) Отображение всех самолетов с их маршрутами" << endl;
	cout <<	"(5) Выход из программы." << endl;

	bool exit = true;                    //для выхода
	vector<string> towns;                //вектор городов
	vector<string> planes;               //вектор самолетов
	map <string, vector <string>> route; //вектор остановок

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
			if (!route.empty()) { //если не пустой - зайди в функцию
				Planes(planes, route);

			} else {
				cout << "Вы не добавили ни одного самолета!" << endl;
			}
		} else if (command == planetown::EXIT) {
			cout << "Спасибо за использование!";
			break;
			
		} else {
			cout << "Такой команды не существует" << endl;
		}
	}
}