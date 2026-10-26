
#include <iostream>
using namespace std;

int& highest(int marks[], int n) {
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (marks[i] > marks[index])
            index = i;
    }

    return marks[index];
}

int main() {
    int marks[] = {75, 92, 85, 88};

    cout << "Highest mark: " << highest(marks, 4) << '\n';

    highest(marks, 4) += 2;

    cout << "After moderation: "
         << highest(marks, 4) << '\n';

    return 0;
}
