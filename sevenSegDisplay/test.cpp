int pinList[] = {1, 2, 3, 4, 5, 6, 7};
int arrSize = sizeof(pinList) / sizeof(pinList[0]);
int combination[2][7] = {
    {1,5}, {2,1,4,7,6}
};

#include <iostream>
using namespace std;

void start()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++) {
            cout << combination[i][j] << endl; 
        }
    }
}

void back() {
    for (int i = arrSize - 1; i >= 0; i--)
    {
        cout << i << endl; 
    }
}

int main() {
    start();
    //back();
    return 0;
}