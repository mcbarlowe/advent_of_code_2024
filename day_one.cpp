#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main () {
    ifstream myfile ("day_one_data.txt");
    string line;

    vector<int> left_side;
    vector<int> right_side;
    vector<int> difference;

    if ( myfile.is_open() ) {
        while ( myfile ) {
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

    sort(left_side.begin(), left_side.end());
    sort(right_side.begin(), right_side.end());

    for (int i = 0; i < left_side.size(); i++) {
        difference.push_back(abs(left_side[i] - right_side[i]));
    }

    auto result = std::reduce(difference.begin(), difference.end());

    cout << "The difference between the two vectors is: " << result << endl;

}
