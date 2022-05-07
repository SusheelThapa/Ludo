#include <iostream>
using namespace std;

class LudoPiece
{
private:
public:
    static const int count = 10;
    LudoPiece();
    ~LudoPiece();
};

class BlueLudo : LudoPiece
{
public:
    int getCount()
    {
        return this->count;
    }
};

LudoPiece::LudoPiece()
{

    // count = 0;
    // count++;
}

LudoPiece::~LudoPiece()
{
}

int main()
{
    LudoPiece blue;
    BlueLudo red;

    cout << blue.count;
    cout << red.getCount();

    return 0;
}