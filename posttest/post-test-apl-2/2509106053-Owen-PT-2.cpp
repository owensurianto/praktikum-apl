#include <iostream>
using namespace std;

struct User {
    string username;
    string password;
};
struct Buah {
    string nama;
    int harga;
    int stok;
};

#define MAX 100
Buah daftarBuah[MAX];
int totalData = 0;

int main() {
    User admin = {"Owen", "053"};
    string input_nama, input_pw;
    int percobaan = 0;
    bool login_berhasil = false;

    while (percobaan < 3) {
        cout << "=== SISTEM LOGIN ===" << endl;
        cout << "Masukkan Nama: ";
        cin >> input_nama;
        cout << "Masukkan Password: ";
        cin >> input_pw;
        if (input_nama == admin.username && input_pw == admin.password) {
            login_berhasil = true;
            cout << "Login Berhasil! Selamat datang, " << input_nama << "." << endl;
            break;
        } else {
            percobaan++;
            cout << "Nama atau Password salah! Sisa percobaan: " << 3 - percobaan << endl << endl;
        }
    }
    if (!login_berhasil) {
        cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    int pilihan, index;
    do {
        cout << "\n=== MENU UTAMA TOKO BUAH ===" << endl;
        cout << "1. Tambah Data Buah" << endl;
        cout << "2. Lihat Daftar Buah" << endl;
        cout << "3. Ubah Data Buah" << endl;
        cout << "4. Hapus Data Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (totalData < MAX) {
                    cout << "Masukkan Nama Buah : ";
                    cin.ignore();
                    getline(cin, daftarBuah[totalData].nama);
                    cout << "Masukkan Harga     : ";
                    cin >> daftarBuah[totalData].harga;
                    cout << "Masukkan Stok (kg) : ";
                    cin >> daftarBuah[totalData].stok;
                    totalData++;
                    cout << "Data berhasil ditambahkan!" << endl;
                } 
                else {
                    cout << "Kapasitas penuh!" << endl;
                }
                break;

            case 2:
                if (totalData == 0) {
                    cout << "Data masih kosong!" << endl;
                }
                else {
                    cout << "\n--- Daftar Stok Buah ---" << endl;
                    for (int i = 0; i < totalData; i++) {
                        cout << i + 1 << ". " << daftarBuah[i].nama 
                            << " | Harga: Rp" << daftarBuah[i].harga 
                            << " | Stok: " << daftarBuah[i].stok << " kg" << endl;
                    }
                }
                break;

            case 3:
                if (totalData == 0) {
                    cout << "Tidak ada data untuk diubah." << endl;
                } 
                else {
                    cout << "\n--- Daftar Stok Buah ---" << endl;
                    for (int i = 0; i < totalData; i++) {
                        cout << i + 1 << ". " << daftarBuah[i].nama 
                            << " | Harga: Rp" << daftarBuah[i].harga 
                            << " | Stok: " << daftarBuah[i].stok << " kg" << endl;
                        }
                    cout << "Masukkan nomor data yang ingin diubah: ";
                    cin >> index;
                    if (index > 0 && index <= totalData) {
                        cout << "Masukkan Nama Baru : ";
                        cin.ignore();
                        getline(cin, daftarBuah[index - 1].nama);
                        cout << "Masukkan Harga Baru: ";
                        cin >> daftarBuah[index - 1].harga;
                        cout << "Masukkan Stok Baru : ";
                        cin >> daftarBuah[index - 1].stok;
                        cout << "Data berhasil diperbarui!" << endl;
                    }
                    else {
                        cout << "Nomor tidak valid!" << endl;
                    }
                }
                break;

            case 4:
                if (totalData == 0) {
                    cout << "Tidak ada data untuk dihapus." << endl;
                } else {
                    cout << "\n--- Daftar Stok Buah ---" << endl;
                    for (int i = 0; i < totalData; i++) {
                        cout << i + 1 << ". " << daftarBuah[i].nama 
                            << " | Harga: Rp" << daftarBuah[i].harga 
                            << " | Stok: " << daftarBuah[i].stok << " kg" << endl;
                    }
                    cout << "Masukkan nomor data yang ingin dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= totalData) {
                        for (int i = index - 1; i < totalData - 1; i++) {
                            daftarBuah[i] = daftarBuah[i + 1];
                        }
                        totalData--;
                        cout << "Data berhasil dihapus!" << endl;
                    } else {
                        cout << "Nomor tidak ada!" << endl;
                    }
                }
                break;

            case 5: 
                cout << "Terima kasih! Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}