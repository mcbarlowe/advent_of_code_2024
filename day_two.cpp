//
// Created by Matt Barlowe on 12/17/24.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ranges>
#include <numeric>

using namespace std;

bool is_safe(vector<int> row) {
    vector<int> diff(row.size());
    adjacent_difference(row.begin(), row.end(), diff.begin());
    bool result = std::all_of(diff.begin() + 1, diff.end(), [](int i) {
        if (abs(i) >= 1 && abs(i) <= 3) { return true; } else { return false; };
    });
    if (result) {
        bool all_decreasing = std::all_of(diff.begin() + 1, diff.end(), [](int i) { return i < 0; });
        bool all_increasing = std::all_of(diff.begin() + 1, diff.end(), [](int i) { return i > 0; });
        if (all_decreasing || all_increasing) {
            if (diff.size() < 2) {
                return false;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }
    return false;
}

int main() {
    ifstream myfile("day_two_data.txt");

    vector<int> safe;

    if (myfile.is_open()) {
        string line;
        while (std::getline(myfile, line)) {
            stringstream ss(line);
            string word;
            vector<int> row;

            while (ss >> word) {
                int num = stoi(word);
                row.push_back(num);
            }
            safe.push_back(is_safe(row));
        }
    }

    int num_of_safe_reports = std::reduce(safe.begin(), safe.end());
    cout << "The number of safe reports is: " << num_of_safe_reports << endl;
}
