// Kelompok rowrrr
//Anggota Kelompok:
//1. Bais Cartensz Rumbiak  (25.11.6575)
//2. Natalies Lulut Damayanti(25.11.6583)
//3. Aziefa Maharani Gitaatmaja (25.11.6579)
//4. Fantos Sen gowi(25.11.6573)
//5. Danilo Sarwono(25.11.6551)

#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

//Jumlah data maksimal adalah 50 
const int MAX_DATA = 50;

// Definisi Struktur untuk Data Barang
struct Barang {
    string idBarang;
    string namaBarang;
    int jumlahBarang;
};

// Array untuk menyimpan data inventaris
Barang inventaris[MAX_DATA];

// Variabel global untuk melacak jumlah data barang yang sudah terisi
int jumlahDataSaatIni = 0;

// --- FUNGSI UNTUK INPUT DATA BARANG (Pilihan Menu 1) ---
void inputDataBarang() {
    system("cls"); // Bersihkan layar
    cout << "## Input Data Barang Baru ##" << endl;
    cout << "----------------------------" << endl;

    if (jumlahDataSaatIni < MAX_DATA) {
        cout << "Data ke-" << jumlahDataSaatIni + 1 << " dari " << MAX_DATA << endl;

        // Input idBarang
        cout << "Masukkan ID Barang: ";
        cin >> inventaris[jumlahDataSaatIni].idBarang;

        // Input namaBarang (gunakan getline setelah cin untuk menangani spasi)
        // Menggunakan cin.ignore() untuk membersihkan buffer sebelum getline
        cin.ignore();
        cout << "Masukkan Nama Barang: ";
        getline(cin, inventaris[jumlahDataSaatIni].namaBarang);

        // Input jumlahBarang
        cout << "Masukkan Jumlah Barang: ";
        // Pastikan input adalah integer yang valid
        while (!(cin >> inventaris[jumlahDataSaatIni].jumlahBarang) || inventaris[jumlahDataSaatIni].jumlahBarang < 0) {
            cout << "Input tidak valid. Masukkan angka positif untuk Jumlah Barang: ";
            cin.clear(); // Reset flag error
            cin.ignore(10000, '\n'); // Hapus input yang salah dari buffer
        }

        // Tambah jumlah data yang sudah terisi
        jumlahDataSaatIni++;
        cout << "\n>>> Data Barang Berhasil Ditambahkan! <<<" << endl;
    }
    else {
        cout << "!!! PERINGATAN: Kapasitas Penyimpanan Sudah Penuh (" << MAX_DATA << " data) !!!" << endl;
    }

    cout << "\nTekan ENTER untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}


// --- FUNGSI UNTUK MELIHAT DATA BARANG (Pilihan Menu 2) ---
void lihatDataBarang() {
    system("cls"); // Bersihkan layar
    cout << "## Daftar Inventaris Barang (" << jumlahDataSaatIni << " Data) ##" << endl;
    cout << "------------------------------------------------------------------" << endl;

    if (jumlahDataSaatIni == 0) {
        cout << "Belum ada data barang yang tersimpan." << endl;
    }
    else {
        // Header Tabel
        cout << left << setw(5) << "No."
            << left << setw(15) << "ID Barang"
            << left << setw(30) << "Nama Barang"
            << right << setw(10) << "Jumlah" << endl;
        cout << "------------------------------------------------------------------" << endl;

        // Tampilkan data menggunakan perulangan
        for (int i = 0; i < jumlahDataSaatIni; ++i) {
            cout << left << setw(5) << i + 1 << "."
                << left << setw(15) << inventaris[i].idBarang
                << left << setw(30) << inventaris[i].namaBarang
                << right << setw(10) << inventaris[i].jumlahBarang << endl;
        }
        cout << "------------------------------------------------------------------" << endl;
    }

    cout << "\nTekan ENTER untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}


// --- FUNGSI UTAMA (MAIN) ---
int main() {
    int pilihan;
    bool running = true;

    // Gunakan perulangan do-while agar menu tampil minimal satu kali
    do {
        system("cls"); // Bersihkan layar setiap kali menu tampil

        // Tampilan Menu
        cout << "========================================" << endl;
        cout << "=== PROGRAM INVENTARIS BARANG (MAX 50) ===" << endl;
        cout << "========================================" << endl;
        cout << "1. Input Data Barang" << endl;
        cout << "2. View Data Barang" << endl;
        cout << "3. Exit Program" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilih Menu (1/2/3): ";

        // Validasi input menu
        if (!(cin >> pilihan)) {
            cout << "\nInput tidak valid. Harap masukkan angka (1, 2, atau 3)." << endl;
            cin.clear(); // Reset flag error
            cin.ignore(10000, '\n'); // Hapus input yang salah dari buffer
            cout << "\nTekan ENTER untuk melanjutkan...";
            cin.get();
            continue; // Lanjut ke iterasi berikutnya
        }

        // Gunakan switch-case untuk menangani pilihan
        switch (pilihan) {
        case 1:
            inputDataBarang();
            break;
        case 2:
            lihatDataBarang();
            break;
        case 3:
            running = false; // Set flag untuk keluar dari perulangan
            break;
        default:
            cout << "\nPilihan tidak valid. Silakan pilih 1, 2, atau 3." << endl;
            cout << "\nTekan ENTER untuk melanjutkan...";
            cin.ignore();
            cin.get();
            break;
        }

    } while (running); // Program berjalan selama running masih true

    // Pesan Keluar
    system("cls");
    cout << "----------------------------------------" << endl;
    cout << "Anda telah memilih Exit. Program Selesai." << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}