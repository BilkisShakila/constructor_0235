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

void angka:: cetakData(){
    for(int i=1;i<=panjang;i++){
        cout<<i<<" = "<<arr[i]<<endl;
    }
}

void angka::isiData(){
    for(int i=1;i<=panjang;i++){
        cout<<i<<" = ";cin>>arr[i];
    }
    cout<<endl;
}

int main(){
    angka belajarcpp(3); //Constructor Dipanggil
    angka *ptrBelajarcpp = new angka(5); //Contructor Dipanggil
    delete ptrBelajarcpp; //Destructor Dipanggil

    return 0;
}//Destructor Dipanggil