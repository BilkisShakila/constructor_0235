#include <iostream>
#include <string>
using namespace std;

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

class Staff {
private:
    string nama;
    int idStaff;
    float gaji;

public:
    Staff(string pNama, int pId, float pGaji) : nama(pNama), idStaff(pId), gaji(pGaji) {

    void tampilkanInfo() {
        cout << "Nama Staff     : " << nama << endl;
        cout << "ID Staff       : " << idStaff << endl;
    }

class Universitas {
public:
    void lihatGaji(Dosen* d) {
        cout << "Gaji Dosen     : " << aksesGaji(d) << endl;
    }

    void lihatGaji(Staff* s) {
        cout << "Gaji Staff     : " << lihatGajiStaff(s) << endl;
    }
};

int main() {
    // Membuat objek
    Mahasiswa mhs("Bilkis");
    Dosen dosen("Dr. fitri", "001124", "Lektor", 11000000);
    Staff staff("alana", 97, 6000000);
    Universitas univ;

    // Dosen memberi nilai
    dosen.beriNilai(&mhs, 85.5);

    // Staff mengubah pangkat dosen
    staff.ubahPangkat(&dosen, "Guru Besar");

    // Tampilkan data
    cout << "=== DATA MAHASISWA ===" << endl;
    mhs.tampilkanInfo();

    cout << "\n=== DATA DOSEN ===" << endl;
    dosen.tampilkanInfo();

    cout << "\n=== DATA STAFF ===" << endl;
    staff.tampilkanInfo();

    return 0;
}
