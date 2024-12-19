#include "tubes.h"

int landingPage()
{
    int pilihan;
    cout << "========= M E N U =========" << endl;
    cout << "1. Login Admin" << endl;
    cout << "2. Login Mahasiswa" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan anda: ";
    cin >> pilihan;
    return pilihan;
}

int menuAdmin()
{
    int pilihan;
    cout << "========= M E N U  A D M I N =========" << endl;
    cout << "1. Input Mahasiswa" << endl;
    cout << "2. Input Mata Kuliah" << endl;
    cout << "3. Lihat Daftar Mahasiswa" << endl;
    cout << "4. Lihat Daftar Mata Kuliah" << endl;
    cout << "5. Cari Mahasiswa" << endl;
    cout << "6. Hapus Data Mahasiswa" << endl;
    cout << "7. Ubah Nama Mahasiswa" << endl;
    cout << "8. Ubah Judul Mata Kuliah" << endl;
    cout << "9. Cek Apakah Mahasiswa Mengambil Mata Kuliah Spesifi" << endl;
    cout << "0. Kembali" << endl;
    cout << "Pilihan anda: ";
    cin >> pilihan;
    return pilihan;
}

int menuMahasiswa()
{
    int pilihan;
    cout << "======= M E N U  M A H A S I S W A =======" << endl;
    cout << "1. Lihat Daftar Mata Kuliah" << endl;
    cout << "2. Tambah Mata Kuliah" << endl;
    cout << "3. Batalkan Pengambilan Mata Kuliah" << endl;
    cout << "4. Lihat Profil" << endl;
    cout << "0. Kembali" << endl;
    cout << "Pilihan anda: ";
    cin >> pilihan;
    return pilihan;
}

void createListMHS(ListMHS &LM)
{
    LM.firstMHS = nullptr;
    LM.lastMHS = nullptr;
}
void createListMK(ListMK &LMK)
{
    LMK.firstMK = nullptr;
}
void createListR(ListRLS &LR)
{
    LR.firstRLS = nullptr;
}

void tambahMahasiswa_Admin(int jumlahMHS,ListMHS &LM)
{
    int i;
    adrMHS p;
    for (i = 1 ; i <= jumlahMHS ; i++)
    {
        p = new elmListMHS;
        p->nextMHS = nullptr;
        p->prevMHS = nullptr;
        cout << "Mahasiswa ke-" << i <<endl;
        cout << "Nama Mahasiswa: ";
        cin >> p->infoMHS.nama;

        cout << "Nim Mahasiswa: ";
        cin >> p->infoMHS.nim;

        cout << "Semester Mahasiswa: ";
        cin >> p->infoMHS.semester;

        p->infoMHS.sksDiambil = 0;
        insertLastMHS(p,LM);

    }
}
void insertLastMHS(adrMHS p,ListMHS &LM)
{
    if (LM.firstMHS == nullptr)
    {
        LM.firstMHS = p;
        LM.lastMHS = p;
    }
    else
    {
        p->prevMHS= LM.lastMHS;
        LM.lastMHS->nextMHS = p;
        LM.lastMHS = p;
    }
}

void showAllMahasiswa_Admin(ListMHS LM,ListRLS LR)
{
    adrMHS q;

    q = LM.firstMHS;
    if (q != nullptr)
    {
        cout << endl << "\033[33mDATA SEMUA MAHASISWA\033[0m" << endl;
        while (q != nullptr)
        {
            showEveryStudent_Admin(q,LR);
            q = q->nextMHS;
        }
    }
    else
    {
        cout << "\033[31mTidak ada mahasiswa\033[0m" << endl;
    }
}
void tambahMataKuliah_Admin(int jumlahMK,ListMK &LMK)
{
    int i;
    adrMK p;
    for (i = 1 ; i <= jumlahMK ; i++)
    {
        p = new elmListMK;
        p->nextMK = nullptr;
        cout << "Mata Kuliah ke-" << i <<endl;

        cout << "Kode Mata Kuliah: ";
        cin >> p->infoMK.kode;

        cout << "Nama Mata Kuliah: ";
        cin >> p->infoMK.judul;

        cout << "Bobot SKS Mata Kuliah: ";
        cin >> p->infoMK.sks;

        cout << "Mata Kuliah Semester: ";
        cin >> p->infoMK.semester;
        insertLastMK(p,LMK);

    }
}

void insertLastMK(adrMK p,ListMK &LMK)
{
    if (LMK.firstMK == nullptr)
    {
        LMK.firstMK = p;
    }
    else
    {
        adrMK q = LMK.firstMK;
        while (q->nextMK != nullptr )
        {
            q = q->nextMK;

        }
        q->nextMK = p;

    }
}

void showAllMataKuliah_Admin(ListMK LMK)
{
    adrMK q;

    q = LMK.firstMK;
    if (q != nullptr)
    {
        cout << endl << "\033[33mDATA SEMUA MATA KULIAH\033[0m" << endl;
        while (q != nullptr)
        {
            cout << " ----------------------------- " << endl;
            cout << "| kode matkul: ";
            cout << q->infoMK.kode;
            cout <<endl;
            cout << "| nama matkul: ";
            cout << q->infoMK.judul;
            cout <<endl;
            cout << "| bobot: ";
            cout << q->infoMK.sks << " sks";
            cout << endl;
            cout << "| semester: ";
            cout << q->infoMK.semester  ;
            cout << endl;
            cout << " ----------------------------- " << endl;
            q = q->nextMK;
        }
    }
    else
    {
        cout << "\033[31mTidak ada mata kuliah\033[0m" << endl;
    }
}

adrMHS cariMahasiswa(long nim,ListMHS LM)
{
    adrMHS q = LM.firstMHS;

    while (q != nullptr)
    {
        if (q->infoMHS.nim == nim)
        {
            return q;
        }
        q = q->nextMHS;
    }
    return nullptr;

}
void showMahasiswaDicari(adrMHS p)
{
    if (p != nullptr)
    {
        cout << "\033[32mMahasiswa Ditemukan\033[0m" << endl;
        cout << " ----------------------------- " << endl;
        cout << "| nama: ";
        cout << p->infoMHS.nama;
        cout <<endl;
        cout << "| nim: ";
        cout << p->infoMHS.nim;
        cout << endl;
        cout << "| semester: ";
        cout << p->infoMHS.semester;
        cout << endl;
        cout << "| sks diambil: ";
        cout << p->infoMHS.sksDiambil;
        cout << endl;
        cout << " ----------------------------- " << endl;

    }
    else
    {
        cout << "\033[31mMahasiswa tidak ditemukan\033[0m" << endl;
    }
    return;
}

bool loginMahasiswa(adrMHS &M,ListMHS LM)
{
    M = nullptr;
    long nim;
    int i = 3;
    while (M == nullptr && i >= 1)
    {
        cout << "Masukkan NIM Anda: ";
        cin >> nim ;
        M = cariMahasiswa(nim,LM);
        if (M != nullptr)
        {
            return true;

        }
        cout << "NIM anda tidak ditemukan, sisa percobaan sebanyak " << i-1 << " kali" << endl;
        i--;
    }
    return false;
}

void showAllMataKuliah_Mahasiswa(adrMHS p,ListMK LMK)
{
    adrMK q;

    q = LMK.firstMK;
    if (q != nullptr)
    {
        cout << endl << "\033[33mDATA SEMUA MATA KULIAH\033[0m" << endl;
        while (q != nullptr)
        {
            if (q->infoMK.semester == p->infoMHS.semester)
            {
                cout << " ----------------------------- " << endl;
                cout << "| kode matkul: ";
                cout << q->infoMK.kode;
                cout <<endl;
                cout << "| nama matkul: ";
                cout << q->infoMK.judul;
                cout <<endl;
                cout << "| bobot: ";
                cout << q->infoMK.sks << " sks";
                cout << endl;
                cout << "| semester: ";
                cout << q->infoMK.semester ;
                cout << endl;
                cout << " ----------------------------- " << endl;
            }
            q = q->nextMK;
        }
    }
    else
    {
        cout << "\033[31mTidak ada mata kuliah di semester anda\033[0m" << endl;
    }
}

adrMK cariMataKuliah(string kodeMK,ListMK LMK)
{
    adrMK q = LMK.firstMK;

    while (q != nullptr)
    {
        if (q->infoMK.kode == kodeMK)
        {
            return q;
        }
        q = q->nextMK;
    }
    return nullptr;
}

void tambahMataKuliah_Mahasiswa(ListRLS &LR,ListMK LMK,adrMHS &M)
{

    adrRLS p;
    string k;
    adrMK pK;
    p = new elmListRLS;
    p->next = nullptr;


    cout << "Masukkan Kode Mata Kuliah yang ingin Anda Ambil: ";
    cin >> k;
    pK = cariMataKuliah(k,LMK);

    if (pK != nullptr){
        if (!(sudahAmbilMatkulSpesifik_Mahasiswa(M,LR,pK->infoMK.kode))){
        p->keMHS = M;
        p->keMK = pK;
        M->infoMHS.sksDiambil = M->infoMHS.sksDiambil + pK->infoMK.sks;
        insertLastRLS(p,LR);
        cout << "\033[32mMata Kuliah Berhasil Ditambahkan\033[0m" << endl;
        } else {
            cout << "\033[31mAnda Sudah Mengambil Mata Kuliah Tersebut, Silahkan Pilih Mata Kuliah Lain\033[0m" <<endl;
        }
    } else {
        cout << "\033[31mMata Kuliah Tidak Tersedia\033[0m" <<endl;
    }


}

void insertLastRLS(adrRLS p,ListRLS &LR)
{
    if (LR.firstRLS == nullptr)
    {
        LR.firstRLS = p;
    }
    else
    {
        adrRLS q = LR.firstRLS;
        while (q->next != nullptr )
        {
            q = q->next;

        }
        q->next = p;

    }
}
void showEveryStudent_Admin(adrMHS M,ListRLS LR){

    adrRLS p;
    p = LR.firstRLS;


    cout << " ----------------------------- " << endl;
        cout << "| nama: ";
        cout << M->infoMHS.nama;
        cout <<endl;
        cout << "| nim: ";
        cout << M->infoMHS.nim;
        cout << endl;
        cout << "| semester: ";
        cout << M->infoMHS.semester;
        cout << endl;
        cout << "| sks diambil: ";
        cout << M->infoMHS.sksDiambil;
        cout << endl;
        cout << " ----------------------------- " << endl;
    if (sudahAmbilMatkul_Mahasiswa(M,LR)){
        cout << "| \033[1;34mMata Kuliah Diambil\033[0m: " << endl;;
    } else {
        cout << "| \033[1;31mBelum Mengambil Matakuliah\033[0m" <<endl;
        cout << " ----------------------------- " << endl;
    }

    while (p != nullptr){
        if (p->keMHS == M){
            cout << "| ";
            cout << p->keMK->infoMK.judul << ", " << p->keMK->infoMK.sks << " sks" <<endl;
        }
        p = p->next;

    }
    if (sudahAmbilMatkul_Mahasiswa(M,LR)){
        cout << " ----------------------------- " << endl;
    }

}
void lihatProfil_Mahasiswa(adrMHS M,ListRLS LR){

    adrRLS p;
    p = LR.firstRLS;


    cout << " ----------------------------- " << endl;
        cout << "| nama: ";
        cout << M->infoMHS.nama;
        cout <<endl;
        cout << "| nim: ";
        cout << M->infoMHS.nim;
        cout << endl;
        cout << "| semester: ";
        cout << M->infoMHS.semester;
        cout << endl;
        cout << "| sks diambil: ";
        cout << M->infoMHS.sksDiambil;
        cout << endl;
        cout << " ----------------------------- " << endl;
    if (sudahAmbilMatkul_Mahasiswa(M,LR)){
        cout << "| Mata Kuliah Diambil: " << endl;
    } else {
        cout << "| Belum Ada Mata Kuliah yang Ditambahkan, Silahkan Kembali ke Menu" <<endl ;
    }
    while (p != nullptr){
        if (p->keMHS == M){
            cout << "| ";
            cout << p->keMK->infoMK.judul << ", " << p->keMK->infoMK.sks << " sks" <<endl;
        }
        p = p->next;

    }

        cout << " ----------------------------- " << endl;


}

void hapusMahasiswa_Admin(ListMHS &LM, ListRLS &LR) {
    adrMHS M;
    adrRLS R, prev = nullptr;
    long nim;

    cout << "Masukkan NIM Mahasiswa: ";
    cin >> nim;

    M = cariMahasiswa(nim, LM);
    if (M != nullptr) {
        R = LR.firstRLS;
        while (R != nullptr) {
            if (R->keMHS == M) {
                if (R == LR.firstRLS) {
                    deleteFirstRelasi(LR, R);
                    R = LR.firstRLS;
                } else {
                    adrRLS temp = R;
                    R = R->next;
                    deleteAfterRelasi(LR, prev);
                }
            } else {
                prev = R;
                R = R->next;
            }
        }
        if (M == LM.firstMHS) {
            deleteFirstMHS(LM);
        } else if (M == LM.lastMHS) {
            deleteLastMHS(LM);
        } else {
            deleteAfterMHS(LM, M);
        }
        cout << "\033[1;32mMahasiswa berhasil dihapus.\033[0m" << endl;
    } else {
        cout << "\033[1;31mMahasiswa Tidak Ada di Dalam Daftar\033[0m" << endl;;
    }
}


void deleteFirstMHS(ListMHS &LM){
    adrMHS p = LM.firstMHS;
    LM.firstMHS = p->nextMHS;
    p->nextMHS = nullptr;
    delete p;
}
void deleteLastMHS(ListMHS &LM){
    adrMHS p = LM.firstMHS;
    if (p->nextMHS == nullptr) {
        LM.firstMHS = nullptr;
        LM.lastMHS = nullptr;
    } else {
        while (p->nextMHS != LM.lastMHS) {
            p = p->nextMHS;
        }
        adrMHS temp = LM.lastMHS;
        LM.lastMHS = p;
        p->nextMHS = nullptr;
        delete temp;
    }
}
void deleteAfterMHS(ListMHS &LM,adrMHS &M){
    adrMHS p = LM.firstMHS;
    while (p->nextMHS != M) {
        p = p->nextMHS;
    }
    p->nextMHS = M->nextMHS;
    M->nextMHS = nullptr;
    delete M;
}
void deleteFirstRelasi(ListRLS &LR, adrRLS &p) {
    p = LR.firstRLS;
    LR.firstRLS = p->next;
    p->next = nullptr;
    delete p;
}

void deleteAfterRelasi(ListRLS &LR, adrRLS &prec) {
    adrRLS p = prec->next;
    if (p != nullptr) {
        prec->next = p->next;
        p->next = nullptr;
        delete p;
    }
}


void editNamaMahasiswa_Admin(ListMHS &LM){
    adrMHS M;
    long nim;
    string nama;

    cout << "Untuk Mengubah Nama, Silahkan Masukkan NIM Mahasiswa: ";
    cin >> nim;
    M = cariMahasiswa(nim,LM);
    if (M == nullptr){
        cout << "\033[1;31mMahasiswa tidak ditemukan\033[0m" << endl;

    } else {
        cout << "Masukkan Nama Mahasiswa yang Benar: ";
        cin >> nama;
        M->infoMHS.nama = nama;
        cout << "\033[1;32mNama Mahasiswa Berhasil Diubah\033[0m" << endl;
    }
}

void editJudulMatkul_Admin(ListMK &LMK) {
    adrMK M;
    string kodeMK;
    string namaMK;

    cout << "Untuk Mengubah Judul Mata Kuliah, Silahkan Masukkan Kode Mata Kuliah: ";
    cin >> kodeMK;
    M = cariMataKuliah(kodeMK, LMK);
    if (M == nullptr) {
        cout << "\033[1;31mMata Kuliah tidak ditemukan\033[0m" << endl;
    } else {
        cout << "Masukkan Judul Mata Kuliah yang Benar: ";
        cin >> namaMK;
        M->infoMK.judul = namaMK;
        cout << "\033[1;32mJudul Mata Kuliah Berhasil Diubah\033[0m" << endl;
    }
}


bool sudahAmbilMatkul_Mahasiswa(adrMHS M,ListRLS LR){
    adrRLS R;

    R = LR.firstRLS;
    while(R!= nullptr){
        if (R->keMHS == M){
            return true;

        }
        R = R->next;

    }
    return false;
}

bool sudahAmbilMatkulSpesifik_Mahasiswa(adrMHS M, ListRLS LR, string kodeMK) {
    adrRLS R = LR.firstRLS;

    while (R != nullptr) {
        if (R->keMHS == M && R->keMK->infoMK.kode == kodeMK) {
            return true;
        }
        R = R->next;
    }
    return false;
}

void cekAmbilMatkul_Admin(ListRLS LR, ListMHS LM) {
    adrMHS mahasiswa;
    long nomor;
    bool indikator;
    string kodeMatkul;

    cout << "NIM Mahasiswa Dicari: " << endl;
    cin >> nomor;

    mahasiswa = cariMahasiswa(nomor, LM);
    if (mahasiswa != nullptr) {
        cout << "Masukkan Kode Mata Kuliah yang Dicari: " << endl;
        cin >> kodeMatkul;

        indikator = sudahAmbilMatkulSpesifik_Mahasiswa(mahasiswa, LR, kodeMatkul);
        if (indikator) {
            cout << "Mahasiswa Dengan Nama: " << mahasiswa->infoMHS.nama
                 << " Mengambil Mata Kuliah dengan Kode " << kodeMatkul << endl;
        } else {
            cout << "Mahasiswa Tidak Mengambil Mata Kuliah dengan Kode " << kodeMatkul << endl;
        }
    } else {
        cout << "Mahasiswa Tidak Ada Dalam Daftar" << endl;
    }
}

void batalAmbilMatkul_Mahasiswa(string kode, adrMHS &M, ListMHS &LM, ListRLS &LR) {
    adrRLS R = LR.firstRLS;
    adrRLS prev = nullptr;
    adrRLS temp = nullptr;

    bool sudahDihapus = false;
    while (R != nullptr) {
        if (R->keMHS == M && R->keMK->infoMK.kode == kode) {
            if (R == LR.firstRLS) {
                M->infoMHS.sksDiambil = M->infoMHS.sksDiambil - R->keMK->infoMK.sks;
                deleteFirstRelasi(LR, temp);
                R = LR.firstRLS;

            } else {
                M->infoMHS.sksDiambil = M->infoMHS.sksDiambil - R->keMK->infoMK.sks;
                deleteAfterRelasi(LR, prev);
                R = prev->next;

            }
            sudahDihapus = true;
        } else {
            prev = R;
            R = R->next;
        }
    }

    if (sudahDihapus) {
        cout << "\033[1;32mMata kuliah dengan kode " << kode
             << " telah dihapus untuk mahasiswa " << M->infoMHS.nama
             << ".\033[0m" << endl;
    } else {
        cout << "\033[1;31mMata Kuliah dengan kode: " << kode
             << " belum Anda ambil.\033[0m" << endl;
    }
}



