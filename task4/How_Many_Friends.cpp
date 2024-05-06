#include <iostream>
#include<map>
#include<vector>

using namespace std;

void How_Many_Friends(map<string, vector<string>>& friends) {
	string name;

	cout << "\tСколько друзей у человека" << endl;
	cout << "Введите имя человека число друзей которого хотите узнать: ";
	cin >> name;

	if (friends.count(name) > 0) {     //обработка ошибок, количество по имени больше 0
		if (!friends[name].empty()) {  //у человека точно есть друг
			auto count = friends[name].size();
			cout << "У " << name << " " << count << " друзей"; //количество друзей

		} else {
			cout << "У " << name << " пока что нет друзей, добавьте друга с помощью команды (1)!" << endl;
		}

	} else {
		cout << "Этот человек еще не внесен в учет" << endl;
	}
	cout << endl;
}