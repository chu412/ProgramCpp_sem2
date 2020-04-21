#include "Algorithm.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool funcInt(T x)
{
    return x > 0;
}

template <typename T>
bool isMore(T x, T y)
{
    return x > y;
}

template <typename T>
bool isEquals(T x, T y)
{
    return x == y;
}

class CPoint {
private:
    int x;
    int y;
public:
    CPoint(int x, int y) : x(x), y(y){}
    bool operator == (const CPoint& p) const {
        return (x == p.x) and (y == p.y);
    }
};

int main() 
{
    vector<int> A = { 1, 8, 3 };
    cout << "1. All of A? : ";
    cout << ((all_of(A.begin(), A.end(), funcInt<int>)) ? "TRUE" : "FALSE") << endl;

    vector<int> B, B1, B2;
    B.push_back(9);

    B1.push_back(2);
    B1.push_back(5);
    B1.push_back(2);

    B2.push_back(1);
    B2.push_back(2);
    B2.push_back(3);

    vector<CPoint> P1, P2;
    P1.push_back(CPoint(0, 0));
    P1.push_back(CPoint(1, 1));
    P1.push_back(CPoint(0, 0));

    P2.push_back(CPoint(0, 0));
    P2.push_back(CPoint(1, 1));
    P2.push_back(CPoint(1, 0));
 
    cout << "5. Is B sorted? : " << (is_sorted(B, isMore<int>) ? "TRUE" : "FALSE") << endl;
    cout << "   Is B1 sorted? : " << (is_sorted(B1, isMore<int>) ? "TRUE" : "FALSE") << endl;
    cout << "   Is B2 sorted? : " << (is_sorted(B2, isMore<int>) ? "TRUE" : "FALSE") << endl;

    cout << "9. Is B a palindrome? : " << (is_palindrome(B, isEquals<int>) ? "TRUE" : "FALSE") << endl;
    cout << "   Is B1 a palindrome? : " << (is_palindrome(B1, isEquals<int>) ? "TRUE" : "FALSE") << endl;
    cout << "   Is B2 a palindrome? : " << (is_palindrome(B2, isEquals<int>) ? "TRUE" : "FALSE") << endl;
    cout << "   Is P1 a palindrome? : " << (is_palindrome(P1, isEquals<CPoint>) ? "TRUE" : "FALSE") << endl;
    cout << "   Is P2 a palindrome? : " << (is_palindrome(P2, isEquals<CPoint>) ? "TRUE" : "FALSE") << endl;

    return 0;
}