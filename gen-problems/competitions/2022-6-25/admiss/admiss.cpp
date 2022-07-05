#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name, current_school = "-1";
    int score = -1;
    vector<string> schools;
    bool operator>(const Student& b) const
    {
        return this->score > b.score;
    }
    bool operator<(const Student& b) const
    {
        return this->score < b.score;
    }
    void clearData()
    {
        name.clear();
        score = -1;
        schools.clear();
    }
};

map<string, pair<int, int>> schools; // <schoolname,<expect_number,current_number>>
vector<Student> datas; // score,name,schools

int main()
{
    freopen("data/example.in", "r", stdin);
    freopen("data/example.out", "w", stdout);
    int m, n, a, low, tempNum;
    cin >> m >> n >> a >> low;
    string tempStr;
    for (int i = 1; i <= m; i++) {
        cin >> tempStr >> tempNum;
        schools.insert(make_pair(tempStr, make_pair(tempNum, 0)));
    }
    Student tempStudent;
    for (int i = 1; i <= n; i++) {
        tempStudent.clearData();
        cin >> tempStudent.name >> tempStudent.score;
        for (int j = 1; j <= a; j++) {
            cin >> tempStr;
            tempStudent.schools.push_back(tempStr);
        }
        datas.push_back(tempStudent);
    }
    sort(datas.begin(), datas.end(), greater<Student>());
    for (auto& it : datas) {
        if (it.score < low) {
            // The score of this student is too low!
            continue;
        }
        for (const auto& es : it.schools) {
            if (schools[es].first > schools[es].second) { // This student can be inserted
                it.current_school = es; // Admiss this student
                schools[es].second++; // Count of this school is added
                goto isAdmiss; // compute next student
            }
        }
    isAdmiss:
        continue;
    }
    for (auto it : datas) {
        cout << it.name << endl
             << it.score << endl
             << it.current_school << endl;
    }
    return 0;
}