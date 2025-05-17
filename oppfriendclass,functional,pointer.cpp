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

class Dosen {
private:
    string nama;
    string nidn;
    string pangkat;
    float gaji;

public:
    Dosen(string pNama, string pNidn, string pPangkat, float pGaji)
        : nama(pNama), nidn(pNidn), pangkat(pPangkat), gaji(pGaji) {}

    void beriNilai(Mahasiswa* m, float nilaiBaru) {
        m->nilai = nilaiBaru;
    }