#include <iostream>
using namespace std;

class angka {
private:
    int *arr;
    int panjang;
public:
    angka(int); //Contructor
    ~angka(); // Destructor
    void cetakData();
    void isiData();
};
