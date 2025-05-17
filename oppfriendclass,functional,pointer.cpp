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

      void tampilkanInfo() {
        cout << "Nama Dosen     : " << nama << endl;
        cout << "NIDN           : " << nidn << endl;
        cout << "Pangkat        : " << pangkat << endl;
    }

      // Hanya Staff yang bisa mengubah pangkat
    friend class Staff;

    // Fungsi friend untuk akses gaji, digunakan oleh Universitas
    friend float aksesGaji(Dosen* d);
};

// Fungsi friend untuk akses gaji dosen
float aksesGaji(Dosen* d) {
    return d->gaji;
}

class Staff {
private:
    string nama;
    int idStaff;
    float gaji;

public:
    Staff(string pNama, int pId, float pGaji) : nama(pNama), idStaff(pId), gaji(pGaji) {}

    void ubahPangkat(Dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }

    void tampilkanInfo() {
        cout << "Nama Staff     : " << nama << endl;
        cout << "ID Staff       : " << idStaff << endl;
    }

    // Fungsi friend untuk akses gaji staff oleh Universitas
    friend float lihatGajiStaff(Staff* s);
};
