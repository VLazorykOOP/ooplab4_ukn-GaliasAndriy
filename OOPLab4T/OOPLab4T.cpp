#include <iostream>
#include "Lab4Tasks.h" 
using namespace std;
char c;

int showTask(char answerTask)
{
    switch (answerTask) {
    case '1':
        vector3D();
        break;
    case '2':
        matrixVeryLong();
        break;
    default:
        cout << "Try again!";
        break;
    }
    return answerTask;
}

int main()
{
    int answer;
    cout << "Choose a task! Enter number from 1 to 3" << endl;
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1 (Vector3D) \n";
    cout << "    2.  Task 2 (MatrixLong) \n";
    cout << "    3.  Task 3 (List of people: N=, LastName, FirstName, MiddleName) \n";
    cout << "    4.  Exit \n";

    do {
        cout << "\n    Enter: ";
        c = cin.get();
        cin.get();
        showTask(c);
    } while (c != '4');

    return 0;
}
