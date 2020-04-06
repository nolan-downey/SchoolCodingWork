#ifndef TOWER_H
#define TOWER_H

#include <stack>

class Tower {

    private:
        int towerNum;

    public:
        std::stack<int> theStack;

        Tower(int tNum) : towerNum( tNum ), theStack() {}

        int getTowerNum() {

            return towerNum;
        }
};

#endif
