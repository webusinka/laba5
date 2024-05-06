#include <iostream>
#include<map>
#include<vector>

using namespace std;

void Are_They_Friends(map<string, vector<string>>& friends) {
	string name1, name2;

	cout << "\tОни друзья?" << endl;
	cout << "Введите имя первого человека: ";
	cin >> name1;
	cout << "Введите имя второго человека: ";
	cin >> name2;

	if (friends.count(name1) > 0 && friends.count(name2) > 0) {
        for (auto ok : friends[name1]) {
			for (auto ok : friends[name1]) {
			    if (ok == name2) {
				    cout << "Да, они друзья" << endl;
				    return;

			    } else {
                    cout << "Нет, они не друзья, пусть познакомятся!" << endl;	
                    return;   
                }
            }
		}

	} else {
		cout << "Один или оба человека не найдены!" << endl;
	}
}