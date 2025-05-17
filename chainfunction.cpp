#include <iostream>
using namespace std;

class buku
{
    string judul;

public:
    buku setjudul(string judul)
    {
        this->judul = judul;
        return *this; // chain funtion
    }
    string getJudul()
    {
        return this->judul;
    }
} bukunya;

int main()
{
    // bukunya.setJudul("Matematika");
    // cout << bukunya.getJudul();
    cout << bukunya.setjudul("Matematika").getJudul(); // chain funtion calls

    return 0;
    
    
}