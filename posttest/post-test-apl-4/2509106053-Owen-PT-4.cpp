#include <iostream>
#include <string>
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

bool login(User &admin) {
    string input_nama, input_pw;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "=== LOGIN SYSTEM ===" << endl;
        cout << "Username: "; cin >> input_nama;
        cout << "Password: "; cin >> input_pw;

        if (input_nama == admin.username && input_pw == admin.password) {
            cout << "Login Berhasil!\n";
            return true;
        } else {
            percobaan++;
            cout << "Salah! Sisa percobaan: " << 3 - percobaan << "\n\n";
        }
    }
    return false;
}
void updateHarga(int *hargaPtr, int hargaBaru) {
    *hargaPtr = hargaBaru;
}

void tambah_buah(int &total) {
    if (total < MAX) {
        cout << "Masukkan Nama Buah : ";
        cin.ignore();
        getline(cin, daftarBuah[total].nama);
        cout << "Masukkan Harga     : ";
        cin >> daftarBuah[total].harga;
        cout << "Masukkan Stok (kg) : ";
        cin >> daftarBuah[total].stok;
        total++;
        cout << "Data berhasil ditambahkan!" << endl;
    } else {
        cout << "Kapasitas penuh!" << endl;
    }
}

void daftar_buah(int total) {
    if (total == 0) {
        cout << "Data masih kosong!" << endl;
    } else {
        cout << "\n--- Daftar Stok Buah ---" << endl;
        for (int i = 0; i < total; i++) {
            Buah *bPtr = &daftarBuah[i]; 
            cout << i + 1 << ". " << bPtr->nama
                << " | Harga: Rp" << bPtr->harga 
                << " | Stok: " << bPtr->stok << " kg" << endl;
        }
    }
}

void edit_buah(int total) {
    int index, hrgBaru;
    if (total == 0) {
        cout << "Tidak ada data." << endl;
        return;
    }
    daftar_buah(total);
    cout << "Nomor data yang ingin diubah harganya: ";
    cin >> index;

    if (index > 0 && index <= total) {
        cout << "Masukkan Harga Baru: ";
        cin >> hrgBaru;
        updateHarga(&daftarBuah[index - 1].harga, hrgBaru);
        cout << "Harga berhasil diperbarui!" << endl;
    } else {
        cout << "Nomor tidak valid." << endl;
    }
}

void hapus_buah(int &total) {
    if (total == 0) {
        cout << "Data kosong, tidak ada yang dihapus." << endl;
        return;
    }
    daftar_buah(total);
    int index;
    cout << "Nomor data yang ingin dihapus: ";
    cin >> index;
    if (index > 0 && index <= total) {
        for (int i = index - 1; i < total - 1; i++) {
            daftarBuah[i] = daftarBuah[i + 1];
        }
        total--;
        cout << "Data berhasil dihapus!" << endl;
    } else {
        cout << "Nomor tidak valid!" << endl;
    }
}

void menu() {
    cout << "\n=== MENU UTAMA TOKO BUAH ===" << endl;
    cout << "1. Tambah Data Buah" << endl;
    cout << "2. Lihat Daftar Buah" << endl;
    cout << "3. Ubah Harga Buah" << endl;
    cout << "4. Hapus Buah" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan: ";
}

int main() {
    User admin = {"Owen", "053"};
    if (!login(admin)) {
        cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    do {
        menu();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambah_buah(totalData);
                break;
            case 2:
                daftar_buah(totalData);
                break;
            case 3:
                edit_buah(totalData);
                break;
            case 4:
                hapus_buah(totalData);
                break;
            case 5:
                cout << "Terima kasih! Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        };
    } while (pilihan != 5);

    return 0;
}