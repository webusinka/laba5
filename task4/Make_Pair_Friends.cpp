#include <iostream>
#include<map>
#include<vector>

using namespace std;

void Make_Pair_Friends(map<string,vector<string>>& friends) {
	string name1, name2;

	cout << "\tСоздание пары друзей!" << endl;
	cout << "Введите имя первого друга: ";
	cin >> name1;
	cout << "Введите имя второго друга: ";
	cin >> name2;

	for (string a : friends[name1]) {
		if (a == name2) {
			cout << "Пара УЖЕ была создана!" << endl; //не добавляй заново, что уже было создано
            return;
		}
	}
	if (name1 == name2) {
		cout << "Одинаковое имя, аккуратнее!" << endl;
		return ;
	}

	friends[name1].push_back(name2);
	friends[name2].push_back(name1);
	cout << "Пара создана!"<< endl;
}