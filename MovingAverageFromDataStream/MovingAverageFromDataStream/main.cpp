//
//  main.cpp
//  MovingAverageFromDataStream
//
//  Created by Wenzhen Zhu on 3/20/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class MovingAverage {
private:
    queue<int> myQueue;
    int averageSize;
    double sum;
    
public:
    MovingAverage(int size): averageSize(size), sum(0){}
    
    double next(int val) {
        sum += val;
        myQueue.push(val);
        int queueSize = (int) myQueue.size();
        if(queueSize <= averageSize){
            return sum / queueSize;
        } else {
            sum -= myQueue.front();
            myQueue.pop();
            return sum / averageSize;
        }
    }
};

int main(int argc, const char * argv[]) {
    MovingAverage ma = *new MovingAverage(3);
    cout << ma.next(1) << endl;
    cout << ma.next(10) << endl;
    cout << ma.next(3) << endl;
    return 0;
}
