#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string cogwheels[5];
int rotation[5];
int K, chainNum, d, ret;

void turnRight(string &cogwheel) {
    char tmp = cogwheel[7];
    for(int i = 7; i > 0; --i)
        cogwheel[i] = cogwheel[i-1];
    cogwheel[0] = tmp;
}

void turnLeft(string &cogwheel) {
    char tmp = cogwheel[0];
    for(int i = 0; i < 7; ++i)
        cogwheel[i] = cogwheel[i+1];
    cogwheel[7] = tmp;
}

void turnChain() {
    for(int i = 1; i <= 4; ++i) {
        if(rotation[i] == 1)
            turnRight(cogwheels[i]);
        else if(rotation[i] == -1)
            turnLeft(cogwheels[i]);
    }
}

void turnFirst(int dir) {
    rotation[1] = dir;
    for(int i = 1; i < 4; ++i) {
        if(cogwheels[i][2] == cogwheels[i+1][6])
            return;
        dir = -dir;
        rotation[i+1] = dir;
    }
}

void turnSecond(int dir) {
    rotation[2] = dir;
    if(cogwheels[1][2] != cogwheels[2][6])
        rotation[1] = -dir;
    if(cogwheels[2][2] == cogwheels[3][6])
        return;
    rotation[3] = -dir;
    if(cogwheels[3][2] == cogwheels[4][6])
        return;
    rotation[4] = dir;
}

void turnThird(int dir) {
    rotation[3] = dir;
    if(cogwheels[3][2] != cogwheels[4][6])
        rotation[4] = -dir;
    if(cogwheels[2][2] == cogwheels[3][6])
        return;
    rotation[2] = -dir;
    if(cogwheels[1][2] == cogwheels[2][6])
        return;
    rotation[1] = dir;
}

void turnFourth(int dir) {
    rotation[4] = dir;
    for(int i = 4; i > 1; --i) {
        if(cogwheels[i][6] == cogwheels[i-1][2])
            return;
        dir = -dir;
        rotation[i-1] = dir;
    }
}

void chainRule(int num, int dir) {
    memset(rotation, 0, sizeof(rotation));
    if(num == 1)
        turnFirst(dir);
    else if(num == 2)
        turnSecond(dir);
    else if(num == 3)
        turnThird(dir);
    else
        turnFourth(dir);
    turnChain();
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < 5; ++i)
        cin >> cogwheels[i];
    cin >> K;
    for(int i = 0; i < K; ++i) {
        cin >> chainNum >> d;
        chainRule(chainNum, d);
    }

    for(int i = 1; i < 5; ++i)
        ret += ((cogwheels[i][0] - '0') << (i-1));
    cout << ret << "\n";

    return 0;
}