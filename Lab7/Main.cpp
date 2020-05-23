#include "CircularBuffer.h"
using namespace std;

int main() {
    CircularBuffer<int> Buffer(10);   
    Buffer.push_back(-5);   
    Buffer.push_back(-4);
    Buffer.push_back(-3);
    Buffer.push_back(-2);
    Buffer.push_back(-1);
    Buffer.push_back(0);
    Buffer.push_back(1);
    Buffer.push_back(2);
    Buffer.push_back(3);
    Buffer.push_back(4); 
    cout << "Buffer with capacity 10: ";
    print(Buffer);
    cout << endl;

    cout << "Erase element -2: ";
    Buffer.erase(find(Buffer.begin(), Buffer.end(), -2));
    print(Buffer);
    cout << endl;

    cout << "Insert element 222 via iterator on 6nd position: ";
    Buffer.insert(find(Buffer.begin(), Buffer.end(), Buffer[5]), 222);
    print(Buffer);
    cout << endl;

    cout << "Change buffer capacity to 6: ";
    Buffer.resize(6);
    print(Buffer);
    cout << endl;

    
    cout << "Pushing to front number -100: ";
    Buffer.push_front(-100);
    print(Buffer);
    cout << endl;

    cout << "Pushing to back number 100: ";
    Buffer.push_back(100);
    print(Buffer);
    cout << endl;

    cout << "Pop to front 1 number: ";
    Buffer.pop_front();
    print(Buffer);
    cout << endl;

    cout << "Pop to back 1 number: ";
    Buffer.pop_back();
    print(Buffer);
    cout << endl;

    cout << "Sort buffer: ";
    sort(Buffer.begin(), Buffer.end());
    print(Buffer);
    cout << endl;

    cout << "Reverse buffer: ";
    reverse(Buffer.begin(), Buffer.end());
    print(Buffer);

    return 0;
}