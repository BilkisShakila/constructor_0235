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

//Definisi member Functon
angka:: angka(int i){ // Constructor
     panjang = i;
     arr = new int[i];
     isiData;
}
