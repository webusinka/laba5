#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

void Towns_For_Plane(map<string, vector<string>>& route) {
    string plane;
    cout << "Введите название самолета: "; //какой самолет пролетает
    cin >> plane;

    if (route.count(plane) > 0) {
        cout << "Города, через которые пролетает самолет " << plane << ": "; //выведи все города у самолета
        for (string town : route[plane]) {
            cout << town << " ";
        }
        cout << endl;

        for (string town : route[plane]) {  //просмотри города
            if (route.count(town) > 0) {
                for (const string& a : route[town]) {
                    if (a != plane && !route[a].empty()) { //если самолет не равен введенному и этот самолет не пустой
                        cout << "Также через город " << town << " пролетают самолеты:";
                        cout << a << " ";
                    }
                }
            }
        }
        cout << endl;

    } else {
        cout << "Самолет " << plane << " не найден." << endl;
    }
    cout << endl;
}
