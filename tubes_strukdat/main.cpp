#include <iostream>
#include "tubes.h"
using namespace std;

int main()
{
    int pilihan = -1;
    int n;
    string yesNo = "y";
    ListMHS LM;
    ListMK LMK;
    ListRLS LR;

    createListMHS(LM);
    createListMK(LMK);
    createListR(LR);


    while (pilihan != 0 && yesNo == "y")
    {
        pilihan = landingPage();
        switch (pilihan)
        {
        case 1:
        {
            while (yesNo == "y")
            {
                int adminChoice = menuAdmin();
                switch (adminChoice)
                {
                case 1:
                    cout << "Berapa Data Mahasiswa yang Diinput:" ;
                    cin >> n;
                    tambahMahasiswa_Admin(n,LM);
                    break;
                case 2:
                    cout << "Berapa Data Mata Kuliah yang Diinput:" ;
                    cin >> n;
                    tambahMataKuliah_Admin(n,LMK);
                    break;

                case 3:
                    showAllMahasiswa_Admin(LM,LR);
                    break;
                case 4:
                    showAllMataKuliah_Admin(LMK);
                    break;
                case 5:
                    long nim;
                    cout << "Masukkan NIM Mahasiswa yang ingin Dicari: ";
                    cin >> nim;
                    adrMHS m ;
                    m = cariMahasiswa(nim,LM);
                    showMahasiswaDicari(m);
                    break;
                case 6:
                    hapusMahasiswa_Admin(LM,LR);
                    break;
                case 7:
                    editNamaMahasiswa_Admin(LM);
                    break;
                case 8:
                    editJudulMatkul_Admin(LMK);
                    break;
                case 9:
                    cekAmbilMatkul_Admin(LR,LM);
                    break;
                case 0:
                    yesNo = "n";
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                }

                if (adminChoice != 0)
                {
                    cout << "Kembali ke menu admin? (y/n): ";
                    cin >> yesNo;
                    cout << endl;
                }
            }
            break;
        }
        case 2:
        {

            adrMHS M;
            if (loginMahasiswa(M,LM))
            {
                while (yesNo == "y")
                {
                    int mahasiswaChoice = menuMahasiswa();
                    switch (mahasiswaChoice)
                    {
                    case 1:
                        showAllMataKuliah_Mahasiswa(M,LMK);
                        break;
                    case 2:
                        tambahMataKuliah_Mahasiswa(LR,LMK,M);
                        break;
                    case 3: {
                        string KODE;
                        cout << "Masukkan Kode Matkul Yang Ingin Dihapus: " ;
                        cin >> KODE;
                        batalAmbilMatkul_Mahasiswa(KODE,M,LM,LR);

                        break;}
                    case 4:
                        lihatProfil_Mahasiswa(M,LR);
                        break;
                    case 0:
                        yesNo = "n";
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                    }

                    if (mahasiswaChoice != 0)
                    {
                        cout << "Kembali ke menu mahasiswa? (y/n): ";
                        cin >> yesNo;
                        cout << endl;
                    }
                }
            }
            else
            {
                break;
            }
            break;
        }
        case 0:
            cout << endl<<"\033[1;32mTerima kasih telah menggunakan program ini!\033[0m" << endl;
            break;
        default:
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }

        if (pilihan != 0)
        {
            cout << "Kembali ke Menu Awal? (y/n): ";
            cin >> yesNo;
            cout << endl;
        }
    }

    return 0;
}
