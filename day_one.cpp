#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ranges>

using namespace std;

int get_list_sim_score(vector <int> list1, vector <int> list2) {

    vector<int> difference;

    difference.reserve(list1.size());

    for (int i : list1) {
        difference.push_back(ranges::count(list2, i) * i);
    }

    auto result = std::reduce(difference.begin(), difference.end());

    return result;
}

int get_list_distance(vector <int> list1, vector <int> list2) {
    vector<int> difference;
    difference.reserve(list1.size());

    for (int i : list1) {
        difference.push_back(abs(i - list2[i]));
    }

    auto result = std::reduce(difference.begin(), difference.end());

    return result;
}
int main () {
    ifstream myfile("day_one_data.txt");

    vector<int> left_side;
    vector<int> right_side;

    if (myfile.is_open()) {
        string line;
        while (myfile) {
            getline(myfile, line);
            stringstream ss(line);
            string word;
            int count = 1;

            while (ss >> word) {
                int num = stoi(word);
                if (count == 1) {
                    left_side.push_back(num);
                    count++;
                } else {
                    right_side.push_back(num);
                }
            }
        }
        myfile.close();
    }

    std::sort(left_side.begin(), left_side.end());
    std::sort(right_side.begin(), right_side.end());


    cout << "The similarity scores between the two vectors is: " << get_list_sim_score(left_side, right_side) << endl;
    cout << "The difference between the two vectors is: " << get_list_distance(left_side, right_side) << endl;
}
