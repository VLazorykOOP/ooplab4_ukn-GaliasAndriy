#include <iostream>
#include "Lab4Tasks.h" 
using namespace std;

int showTask(int answerTask)
{
    switch (answerTask) {
    case 1:
        vector3D();
        break;
    /*case 2:
        showSecondTaskVector();
        break;
    case 3:
        showTwoDimensionalArray();
        break;*/
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

    do {
        cout << "\n    Enter: "; cin >> answer;
        showTask(answer);
    } while (answer <= 0 || answer > 3);
    
    return 0;
}

//and here