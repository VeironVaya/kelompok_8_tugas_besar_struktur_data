# TUBES STRUKTUR DATA KELOMPOK 8

Oleh: 
- `103012300100` Veiron Vaya Yarief
- `103012300039` Muhammad Irgiansyah

## DESKRIPSI

Membuat aplikasi tentang mahasiswa dan mata kuliah serta relasi antara kedua entitas tersebut

### A. Fungsi dalam aplikasi:  

#### 1. Insert data parent dari depan/belakang (5) -> insert last dari (admin) 
#### 2. Show all data parent (5) -> show mahasiswa (admin) 
#### 3. Menghapus data parent dan childnya (5) -> hapus mahasiswa dan relasinya (admin) 
#### 4. Mencari data parent (5) -> (admin?) 
#### 5. Insert data child (10) -> buat relasi "Tambah Matkul" (mahasiswa) 
#### 6. Mengubah data parent / data child (10) -> edit nama mahasiswa / edit judul mata kuliah (admin) 
#### 7. Menampilkan seluruh data parent beserta childnya (15) -> show mahasiswa dan relasinya "mata kuliah" (admin) 
#### 8. Mencari data child pada parent tertentu (10) -> ditemukan atau tidak "apakah {mahasiswa.nama} mengambil mata kuliah {matakuliah.nama}" (admin & mahasiswa) 
#### 9. Menghapus data child pada parent tertentu (15) -> hapus relasi "Hapus Matkul" (mahasiswa) 
#### 10. Menghitung total sks yang diambil (10) -> udah ada di show all (admin) && tiap mahasiswa bisa melihat juga tapi hanya untuk dirinya 
#### 11. Main program (10) -> switch case pilihan

### B. Fungsi dalam program:


```c++
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
```
