#include <iostream>
using namespace std;

int main() {
    string nama, password;
    string nama_benar = "Owen";
    string pass_benar = "053";
    int jum_percobaan = 0;
    bool login_berhasil = false;

    while (jum_percobaan < 3) {
        cout << "===Login Sistem===" << endl;
        cout << "Nama: ";
        cin >> nama;
        cout << "Password: ";
        cin >> password;

        if (nama == nama_benar && password == pass_benar) {
            login_berhasil = true;
            cout << "Login Berhasil!" << endl;
            break;
        } else {
            jum_percobaan++;
            cout << "Nama atau Password salah! Gagal login." << endl;
            cout << "Sisa percobaan anda: " << (3 - jum_percobaan) << endl << endl;
        }
    }

    if (!login_berhasil) {
        cout << "Percobaan anda habis. Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    double jam;

    do {
        cout << "--- Menu Utama Konversi Waktu ---" << endl;
        cout << "1. Jam -> Menit dan Detik" << endl;
        cout << "2. Menit -> Jam dan Detik" << endl;
        cout << "3. Detik -> Jam dan Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan nilai Jam: ";
            cin >> jam;
            cout << "Hasil: " << jam * 60 << " Menit dan " << jam * 3600 << " Detik" << endl;
        } 
        else if (pilihan == 2) {
            cout << "Masukkan nilai Menit: ";
            cin >> jam;
            cout << "Hasil: " << jam / 60 << " Jam dan " << jam * 60 << " Detik" << endl;
        } 
        else if (pilihan == 3) {
            cout << "Masukkan nilai Detik: ";
            cin >> jam;
            cout << "Hasil: " << jam / 3600 << " Jam dan " << jam / 60 << " Menit" << endl;
        } 
        else if (pilihan == 4) {
            cout << "Keluar dari program. Logout berhasil!" << endl;
        } 
        else {
            cout << "Pilihan tidak ada." << endl;
        }
        cout << endl;

    } while (pilihan != 4);

    return 0;
}
