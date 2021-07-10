#include <bits/stdc++.h>

using namespace std;

struct Person {
    int weight, age;
};

struct {
    bool operator()(Person a, Person b)
    {
        return a.age > b.age;
    }
} functor1;

int main()
{
    Person myArray[] = {{5, 6}, {6, 7}, {8, 10}, {10, 15}};
    vector<Person> myVector(myArray, myArray + 4);
    sort(myVector.begin(), myVector.end(), functor1);
    for_each(myVector.begin(), myVector.end(), [](Person x) { printf("%d ", x.age); });
    return 0;
}
