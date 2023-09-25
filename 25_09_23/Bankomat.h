#include <string>;

class Bankomat
{
    int id;
    int am100;
    int am200;
    int am500;
    int am1000;
    int total;
    int min;
    int max;
public:
    static int count;
    Bankomat();
    Bankomat(int, int, int, int ,int ,int);
    void randomize();
    void withdraw();
    void deposit();
    void print();
    std::string toString();
};

