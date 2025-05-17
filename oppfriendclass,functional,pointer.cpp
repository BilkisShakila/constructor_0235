#include <iostream>
#include <string>
using namespace std;

// Deklarasi awal agar bisa digunakan sebagai friend
    class Dosen;
    class Staff;

class Mahasiswa {
private:
    string nama;
    int nim;
    float nilai;

public:
    Mahasiswa(string pNama, int pNim) : nama(pNama), nim(pNim), nilai(0.0f) {}

    void tampilkanInfo() {
        cout << "Nama Mahasiswa : " << nama << endl;
        cout << "NIM            : " << nim << endl;
        cout << "Nilai          : " << nilai << endl;
    }

    // Dosen dapat mengakses dan mengubah nilai karena friend class
    friend class Dosen;
};