#include <iostream>
#include "library/Matrix.h"

using namespace std;

int main() {

    Matrix test, test2;
    test = test.random(4, 5);
    cout << test << endl << endl;
    test2 = test2.random(4, 5);
    cout << test2 << endl << endl;
    test2 = test2.add(test);
    cout << test2 << endl << endl;

    cout << test2.transpose() << endl;

}
