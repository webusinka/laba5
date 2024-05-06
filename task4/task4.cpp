#include <iostream>
#include<map>
#include<vector>
#include "Make_Pair_Friends.h"
#include "How_Many_Friends.h"
#include "Are_They_Friends.h"

using namespace std;

enum friendsij {
	MAKE_PAIR_FRIENDS = 1, //для пользователя с 1
	HOW_MANY_FRIENDS,
	ARE_THEY_FRIENDS,
	EXIT
};

int main() {
	system("chcp 65001");

	cout << "Программа для друзей" << endl;
	cout <<	"(1) Создать пару друзей." << endl;
	cout <<	"(2) Посмотреть сколько друзей у человека." << endl;
	cout <<	"(3) Посмотреть дружат ли 2 человека." << endl;
	cout <<	"(4) Выход из программы." << endl;

	map<string, vector<string>> friends;
	int command;

	for (int i = 0; exit; i++) {
		cout << endl;
		cout << "Введите команду: ";
		cin >> command;

		if (command == friendsij::MAKE_PAIR_FRIENDS) {
			Make_Pair_Friends(friends);

		} else if (command == friendsij::HOW_MANY_FRIENDS) {
			How_Many_Friends(friends);

		} else if (command == friendsij::ARE_THEY_FRIENDS) {
			Are_They_Friends(friends);

		} else if (command == friendsij::EXIT) {
			cout << "Спасибо за использование!";
			break;

		} else {
			cout << "Такой команды не существует" << endl;
		}
	}
}