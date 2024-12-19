#ifndef TUBES_H_INCLUDED
#include <iostream>
#define TUBES_H_INCLUDED
using namespace std;

struct Mahasiswa {
    long nim;
    string nama;
    int semester;
    int sksDiambil;
};

struct MataKuliah {
    string kode;
    int sks;
    string judul;
    int semester;
};

typedef Mahasiswa InfoTypeMHS;
typedef MataKuliah InfoTypeMK;

typedef struct elmListMHS *adrMHS;
typedef struct elmListMK *adrMK;
typedef struct elmListRLS *adrRLS;

struct elmListMHS {
    adrMHS nextMHS;
    adrMHS prevMHS;
    InfoTypeMHS infoMHS;
};

struct elmListMK {
    adrMK nextMK;
    InfoTypeMK infoMK;
};

struct elmListRLS{
    adrMHS keMHS;
    adrMK keMK;
    adrRLS next;
};

struct ListMHS{
    adrMHS firstMHS;
    adrMHS lastMHS;
};
struct ListMK{
    adrMK firstMK;
};
struct ListRLS{
    adrRLS firstRLS;
};

int landingPage();
int menuMahasiswa();
int menuAdmin();
void createListMHS(ListMHS &LM);
void createListMK(ListMK &LMK);
void createListR(ListRLS &LR);
void tambahMahasiswa_Admin(int jumlahMHS,ListMHS &LM);
void insertLastMHS(adrMHS p,ListMHS &LM);
void tambahMataKuliah_Admin(int jumlahMK,ListMK &LMK);
void insertLastMK(adrMK p,ListMK &LMK);
void showAllMahasiswa_Admin(ListMHS LM,ListRLS LR);
void showAllMataKuliah_Admin(ListMK LMK);
adrMHS cariMahasiswa(long nim, ListMHS LM);
void showMahasiswaDicari(adrMHS p);
bool loginMahasiswa(adrMHS &p,ListMHS LM);
void showAllMataKuliah_Mahasiswa(adrMHS p,ListMK LMK);
adrMK cariMataKuliah(string kodeMK,ListMK LMK);
void tambahMataKuliah_Mahasiswa(ListRLS &LR,ListMK LMK,adrMHS &M);
void insertLastRLS(adrRLS p,ListRLS &LR);
void lihatProfil_Mahasiswa(adrMHS M,ListRLS LR);
void hapusMahasiswa_Admin(ListMHS &LM, ListRLS &LR);
void deleteFirstRelasi(ListRLS &LR, adrRLS &p);
void deleteAfterRelasi(ListRLS &LR, adrRLS &prec);
void deleteFirstMHS(ListMHS &LM);
void deleteLastMHS(ListMHS &LM);
void deleteAfterMHS(ListMHS &LM,adrMHS &M);
void showEveryStudent_Admin(adrMHS M,ListRLS LR);
void editNamaMahasiswa_Admin(ListMHS &LM);
void editJudulMatkul_Admin(ListMK &LMK);
bool sudahAmbilMatkul_Mahasiswa(adrMHS M,ListRLS LR);
bool sudahAmbilMatkulSpesifik_Mahasiswa(adrMHS M, ListRLS LR, string kodeMK);
void cekAmbilMatkul_Admin(ListRLS LR,ListMHS LM);
void batalAmbilMatkul_Mahasiswa(string kode, adrMHS &M, ListMHS &LM, ListRLS &LR);





#endif // TUBES_H_INCLUDED
