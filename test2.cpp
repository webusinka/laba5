#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <limits>
using namespace std;

bool compareTime(const pair <string, int>& lhs, const pair <string, int>& rhs) {
    return lhs.second > rhs.second;
}

bool compareQueue(const pair <vector <string>, int>& lhs, pair <vector <string>, int>& rhs) {
    return lhs.second < rhs.second;
}

vector <pair <vector <string>, int> > optimizeQueue(int numWindows, vector <pair <string, int> >& data) {
    vector <pair <vector <string>, int> > queues(numWindows); // first is sum of time, second is vector of tickets
    sort(data.begin(), data.end(), compareTime); // sorting by time, first element must have the biggest time.

    for (auto element : data) {
        queues[0].first.push_back(element.first); //insert a ticket
        queues[0].second += element.second; //add time 
        sort(queues.begin(), queues.end(), compareQueue);
    }
   
    return queues;
}

int main() {
    system("chcp 65001");

    int numWindows;
    cout << "Введите количество окон: ";
    cin >> numWindows;

    vector <pair <string, int> > data;
    vector <pair <vector <string>, int> > result;
    int startNumber = 100;
    string ticket = "T" + to_string(startNumber);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        string input;
        cout << "Enter a command (ENQUEUE *number* / DISTRIBUTE): ";
        getline(cin, input);
        istringstream iss(input);
        string currentData;
        iss >> currentData;

        if (currentData == "ENQUEUE") {
            int timeClient;
            iss >> timeClient;
            cout << "\tNumber ticket of you: " << ticket << endl;

            data.push_back(make_pair(ticket, timeClient));
            startNumber +=1;
            ticket = "T" + to_string(startNumber);

        } else if (currentData == "DISTRIBUTE") {
            if (data.size() == 0){
                cout << "\tThere is no one in the queue yet)" << endl;
            } else {
                result = optimizeQueue(numWindows, data);  
                int number_of_queue = 1;

                for (auto queue: result) {
                    cout << "\tWindow " << number_of_queue << " (" << queue.second << " minutes): ";
                    for (auto tickets: queue.first) {
                        cout << tickets << " ";
                    }
                    number_of_queue++;
                    cout << endl;
                }
                return 0;
            }
        } else {
            cout << "Invalid command." << endl;
        }
    }
    return 0;
}