#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <limits>
using namespace std;

struct Shelve { //ячейки и продукты в ней
    map<string, int> product; //сколько лежит продуктов
    int current_number;  //Общее количество
};

struct Warehouse {
    int current_number; //текущая загруженность склада          (0)
    const int capacity; //общая вместимость склада             (640)
    const int number_of_zones; //количество зон                 (4)
    const int number_of_rocks; //стеллажи                       (8)
    const int number_of_vertical_section; //вертикальная секция (2)
    const int number_of_shelves; //полка                        (1)

    vector<int> load_of_zones; //загруженность зон
    vector<Shelve> cells; //ячеечки
};

void create_space(struct Warehouse* warehouse) {   //первичное заполнение ячеек нулями с сохранением размера
    warehouse->load_of_zones.resize(warehouse->number_of_zones);
    warehouse->cells.resize(warehouse->capacity);
}

pair<int, int> search_index(int count, string cell, struct Warehouse& warehouse) { //вычисление индекса для ячейки
    pair<int, int> result(-1, -1); //дефолтный результат
    string tmp;
    int index = 0;
    tmp = cell.substr(0, 1); //первичный показатель - зона
    int zone_index = 0;  //сохранения индекса зоны

    if (tmp[0] == 'A') {
        index += 0;

    } else if (tmp[0] == 'B') {
        index += warehouse.capacity / warehouse.number_of_zones;
        zone_index = 1;

    } else if (tmp[0] == 'C') {
        index += warehouse.capacity / warehouse.number_of_zones * 2;
        zone_index = 2;

    } else if (tmp[0] == 'D') {
        index += warehouse.capacity / warehouse.number_of_zones * 3;
        zone_index = 3;

    } else {
        cout << "Wrotng input";
        return result;
    }

    tmp = cell.substr(1, 1); //смещение по стеллажу
    index += (stoi(tmp) - 1) * warehouse.number_of_vertical_section * warehouse.number_of_shelves;

    tmp = cell.substr(2, 1); //смещение по вертикальной секции
    index += (stoi(tmp) - 1) * warehouse.number_of_shelves;

    tmp = cell.substr(3, 1); //смещение по ячейке
    index += (stoi(tmp) - 1);

    result.first = index;
    result.second = zone_index;

    return result;
}

void add (string name, int count, string cell, struct Warehouse& warehouse) {
    pair<int, int> indexies = search_index(count, cell, warehouse);

    if (indexies.first == -1) {
        return;

    } else if (10 - warehouse.cells[indexies.second].current_number < count) {
        cout << "Wrotng input, lack of space for your product" << std::endl;
        return;

    } else {
        warehouse.cells[indexies.first].product[name] += count;
        warehouse.cells[indexies.first].current_number += count;
        warehouse.load_of_zones[indexies.second] += count;
        warehouse.current_number += count;

        cout << "Seccesfull adding" << endl;
        return;
    }
}

void remove(string name, int count, string cell, struct Warehouse& warehouse) {
    pair<int, int> indexies = search_index(count, cell, warehouse);

    if (indexies.first == -1) {
        return;

    } else if (warehouse.cells[indexies.second].current_number < count) {
        std::cout << "Wrotng input, too big number" << std::endl;
        return;

    } else {
        if (warehouse.cells[indexies.first].product[name] == count) {
            warehouse.cells[indexies.first].product.erase(name);

        } else {
            warehouse.cells[indexies.first].product[name] -= count;
        }

        warehouse.cells[indexies.first].current_number -= count;
        warehouse.load_of_zones[indexies.second] -= count;
        warehouse.current_number -= count;

        std::cout << "Seccesfull removing" << std::endl;
        return;
    }
}

int info(struct Warehouse& warehouse) {
    //заполнения склада
    cout << "Load of warehouse: " << warehouse.current_number << " / " << warehouse.capacity << endl;

    //процент заполнения каждой зоны
    for (int i = 0; i < warehouse.load_of_zones.size(); i++) {
        if (i == 0) {
            cout << "Zone A: " << warehouse.load_of_zones[i] << endl;

        } else if (i == 1){
            cout << "Zone B: " << warehouse.load_of_zones[i] << endl;

        } else if (i == 2){
            cout << "Zone C: " << warehouse.load_of_zones[i] << endl;

        } else {
            cout << "Zone D: " << warehouse.load_of_zones[i] << endl;
       }
    }

    //в каждой зоне - вывести наполнение ячейки, если > 1
    string cell_address = "";
    int index = 0;
    vector<string> empty_cell;     //вывести все пустые ячейки

    for (int zone = 0; zone < warehouse.number_of_zones; zone++) { //формируем в строке зону
        char ch = 'A' + zone;
        cell_address += ch;

        for (int rock = 1; rock <= warehouse.number_of_rocks; rock++) { //добавляем номер стелажа
            cell_address += to_string(rock);

            for (int vertical_section = 1; vertical_section <= warehouse.number_of_vertical_section; vertical_section++) {
                cell_address += to_string(vertical_section); //добавляем номер вертикальной секции

                for (int shelves = 1; shelves <= warehouse.number_of_shelves; shelves++){  //добавляем номер ячейки
                    cell_address += to_string(shelves);

                    if (warehouse.cells[index].product.size() == 0){
                        empty_cell.push_back(cell_address);
                        cell_address = "";
                        cell_address += ch;

                    } else {
                        for (const auto& cell_iterator: warehouse.cells[index].product) {
                            cout << "Cells " << cell_address << " "<< cell_iterator.first << " = " << cell_iterator.second << endl;
                            cell_address = "";
                            cell_address += ch; 
                            cell_address += to_string(shelves);      
                        }
                    }
                    index++;
                }
                //запоминаем зону и вертикальная секция
                cell_address = "";
                cell_address += ch;
                cell_address += to_string(rock);
            }
            //запомнить только зону
            cell_address = "";
            cell_address += ch;
        }
        //обнулить строку вообще
        cell_address = "";
    }

    for(auto void_cell: empty_cell) {
        cout << void_cell << ", ";
    }
    cout << endl;

    return 0;
}

int main() {
    Warehouse wildberries{ 0, 640, 4, 8, 2, 1};
    create_space(&wildberries);

    cout << "Enter one of the commands:" << endl;
    cout << "\tADD - product, quantity and cell;" << endl;
    cout << "\tREMOVE - product, quantity and cell;" << endl;
    cout << "\tINFO - information about the status of the warehouse." << endl;

    while(true){
        string input;
        getline(cin, input);
        istringstream iss(input);
        string command;
        iss >> command;

        if (command == "ADD") {
            string name_product;
            iss >> name_product;
            int count_product;
            iss >> count_product;
            string cell;
            iss >> cell;

            add(name_product, count_product, cell, wildberries);

        } else if (command == "REMOVE") {
            string name_product;
            iss >> name_product;
            int count_product;
            iss >> count_product;
            string cell;
            iss >> cell;

            remove(name_product, count_product, cell, wildberries);

        } else if (command == "INFO") {
            info(wildberries);

        } else {
            cout << "Wrong input, sorry, but you will not pass!!!";
        }
        
    }
    return 0;
}