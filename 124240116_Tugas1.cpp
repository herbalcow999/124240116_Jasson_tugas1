#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

void tampilkanData(int jumlahData, Mahasiswa mhs[]);
void cariBerdasarkanNIM(int jumlahData, Mahasiswa mhs[]);
void cariBerdasarkanNama(int jumlahData, Mahasiswa mhs[]);
void urutkanIPKAsc(int rendah, int tinggi, Mahasiswa mhs[]);
void urutkanIPKDesc(int jumlahData, Mahasiswa mhs[]);
void tampilkanMenu(int jumlahData, Mahasiswa mhs[]);

int main() {
    struct Mahasiswa mhs[15] = {
        {"Ahmad Fauzi", 123450001, 3.78},
        {"Bambang Sutrisno", 123450002, 3.65},
        {"Citra Dewi", 123450003, 3.82},
        {"Dedi Kusuma", 123450004, 3.48},
        {"Eva Rahmawati", 123450005, 3.91},
        {"Firman Syah", 123450006, 3.53},
        {"Gita Permata", 123450007, 3.68},
        {"Hendra Wijaya", 123450008, 3.87},
        {"Indah Puspita", 123450009, 3.72},
        {"Joni Prakoso", 123450010, 3.57},
        {"Kartika Sari", 123450011, 3.96},
        {"Lukman Hakim", 123450012, 3.42},
        {"Mira Agustina", 123450013, 3.77},
        {"Nurul Hidayati", 123450014, 3.33},
        {"Oki Setiawan", 123450015, 3.88}
    };
    int jumlahData = 15;

    tampilkanMenu(jumlahData, mhs);

    return 0;
}

void tampilkanMenu(int jumlahData, Mahasiswa mhs[]) {
    int pilihan;
    do {
        cout << "\n|           Menu Pilihan        |" << endl;
        cout << "=================================" << endl;
        cout << "1. Tampilkan Data Mahasiswa" << endl;
        cout << "2. Cari Berdasarkan NIM" << endl;
        cout << "3. Cari Berdasarkan Nama" << endl;
        cout << "4. Urutkan IPK Mahasiswa (Asc)" << endl;
        cout << "5. Urutkan IPK Mahasiswa (Desc)" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih Menu: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                tampilkanData(jumlahData, mhs);
                cout << endl;
                break;
            case 2:
                cariBerdasarkanNIM(jumlahData, mhs);
                system("pause");
                system("cls");
                break;
            case 3:
                cariBerdasarkanNama(jumlahData, mhs);
                system("pause");
                system("cls");
                break;
            case 4:
                urutkanIPKAsc(0, jumlahData - 1, mhs);
                cout << "Data telah diurutkan berdasarkan IPK (Asc)." << endl;
                tampilkanData(jumlahData, mhs);
                cout << endl;
                system("pause");
                system("cls");
                break;
            case 5:
                urutkanIPKDesc(jumlahData, mhs);
                cout << "Data telah diurutkan berdasarkan IPK (Desc)." << endl;
                tampilkanData(jumlahData, mhs);
                cout << endl;
                system("pause");
                system("cls");
                break;
            case 6:
                cout << "Keluar dari program..." << endl;
                exit(0);
                break;
            default:
                cout << "Pilihan tidak ada dalam menu" << endl;
        }
    } while (pilihan != 0);
}

void tampilkanData(int jumlahData, Mahasiswa mhs[]) {
    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << "NO: " << i + 1 << ",\t";
        cout << "Nama: " << mhs[i].nama << ",\t";
        cout << "NIM: " << mhs[i].nim << ",\t";
        cout << "IPK: " << mhs[i].ipk << endl;
    }
}

void cariBerdasarkanNIM(int jumlahData, Mahasiswa mhs[]) {
    int nimCari;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> nimCari;
    bool ditemukan = false;
    for (int i = 0; i < jumlahData; i++) {
        if (mhs[i].nim == nimCari) {
            cout << "\nMahasiswa ditemukan!" << endl;
            cout << "Nama\t: " << mhs[i].nama << endl;
            cout << "NIM\t: " << mhs[i].nim << endl;
            cout << "IPK\t: " << mhs[i].ipk << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

void cariBerdasarkanNama(int jumlahData, Mahasiswa mhs[]) {
    string namaCari;
    cout << "Masukkan nama yang ingin dicari: ";
    cin.ignore();
    getline(cin, namaCari);

    int kiri = 0;
    int kanan = jumlahData - 1;
    bool ditemukan = false;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if (mhs[tengah].nama == namaCari) {
            int awal = tengah;
            while (awal > 0 && mhs[awal - 1].nama == namaCari) {
                awal--;
            }
            int akhir = tengah;
            while (akhir < jumlahData - 1 && mhs[akhir + 1].nama == namaCari) {
                akhir++;
            }
            for (int i = awal; i <= akhir; i++) {
                if (!ditemukan) {
                    cout << "Data ditemukan!" << endl;
                    ditemukan = true;
                }
                cout << "\nData ke-" << i + 1 << endl;
                cout << "Nama Lengkap\t: " << mhs[i].nama << endl;
                cout << "NIM\t\t: " << mhs[i].nim << endl;
                cout << "IPK\t\t: " << mhs[i].ipk << endl;
            }
            break;
        } else if (mhs[tengah].nama < namaCari) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

void urutkanIPKAsc(int rendah, int tinggi, Mahasiswa mhs[]) {
    if (rendah < tinggi) {
        float pivot = mhs[tinggi].ipk;
        int i = rendah - 1;

        for (int j = rendah; j < tinggi; j++) {
            if (mhs[j].ipk < pivot) {
                i++;
                swap(mhs[i], mhs[j]);
            }
        }
        swap(mhs[i + 1], mhs[tinggi]);
        int pi = i + 1;

        urutkanIPKAsc(rendah, pi - 1, mhs);
        urutkanIPKAsc(pi + 1, tinggi, mhs);
    }
}

void urutkanIPKDesc(int jumlahData, Mahasiswa mhs[]) {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {
            if (mhs[j].ipk < mhs[j + 1].ipk) {
                swap(mhs[j], mhs[j + 1]);
            }
        }
    }
}