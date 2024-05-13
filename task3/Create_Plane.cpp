#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void Create_Plane(vector<string>& towns, vector<string>& planes, map<string, vector<string>>& route) {
    string plane, str_towns; // самолет и остановки

    cout << "Введите название самолета: ";
    cin >> plane;
    cin.ignore();

    // Проверка наличия самолета с таким же названием
    if (find(planes.begin(), planes.end(), plane) != planes.end()) {
        cout << "ОШИБКА: Самолет с таким названием уже существует. Пожалуйста, введите другое название.\n" << endl;
        return;
    }

    planes.push_back(plane); // добавь в вектор всех самолетов

    cout << "Введите города, через которые пролетает самолет через пробел: "; // добавляем в города
    getline(cin, str_towns);  // закинули строку
    string town;
    int town_count = 0;
    vector<string> new_towns; // вектор для новых городов

    for (auto a : str_towns) { // добавляем все города
        if (a != ' ') {
            town.push_back(a);
        } else {                  // дошли до пробела
            new_towns.push_back(town); // добавляем город в новый вектор
            town.clear();  // почисти строку
            town_count++;
        }
    }

    new_towns.push_back(town); // последний город самолета не забудь закинуть

    // Проверка наличия одинаковых городов в маршруте
    sort(new_towns.begin(), new_towns.end());
    if (adjacent_find(new_towns.begin(), new_towns.end()) != new_towns.end()) {
        cout << "ОШИБКА: Введены одинаковые города. Пожалуйста, введите разные города.\n" << endl;
        planes.pop_back(); //удаляем этот самолет
        return;
    }
    
    // Проверка наличия маршрута с такими же остановками, но другим самолетом
    for (const auto& pair : route) {
        if (pair.second == new_towns && pair.first != plane) {
			planes.pop_back(); //удаляем этот самолет
            cout << "ОШИБКА: Самолет с таким же маршрутом уже существует.\n" << endl;
            return;
        }
    }

    // Добавляем новые города и маршрут
    for (const auto& new_town : new_towns) {
        towns.push_back(new_town);
        route[new_town].push_back(plane);
        route[plane].push_back(new_town);
    }

    if (town_count == 0) {
        cout << "ОШИБКА: Введен только один город. Пожалуйста, введите два или более городов.\n" << endl;
        for (const auto& new_town : new_towns) {
			planes.pop_back(); //удаляем этот самолет
            towns.pop_back(); // удаляем последний город
            route[new_town].pop_back(); // удаляем последний город из маршрута
            route[plane].pop_back(); // удаляем последний город из маршрута самолета
        }
    } else {
        cout << "Ваш самолет был добавлен в расписание!!\n" << endl;
    }
}