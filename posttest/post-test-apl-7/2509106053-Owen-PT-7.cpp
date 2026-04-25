#include <iostream>
using namespace std;

struct User {
    string username;
    string password;
};

struct Buah {
    int id;
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

void tambah_buah(int &total) {
    try {
        if (total >= MAX) throw length_error("Kapasitas penuh!");

        cout << "Masukkan ID Buah   : ";
        cin >> daftarBuah[total].id;
        if (cin.fail()) throw invalid_argument("ID harus angka!");

        cout << "Masukkan Nama Buah : ";
        cin.ignore();
        getline(cin, daftarBuah[total].nama);

        cout << "Masukkan Harga     : ";
        cin >> daftarBuah[total].harga;
        if (cin.fail()) throw invalid_argument("Harga harus angka!");

        cout << "Masukkan Stok (kg) : ";
        cin >> daftarBuah[total].stok;
        if (cin.fail()) throw invalid_argument("Stok harus angka!");

        total++;
        cout << "Data berhasil ditambahkan!\n";
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void daftar_buah(int total) {
    if (total == 0) {
        cout << "Data masih kosong!\n";
    } else {
        cout << "\n--- Daftar Stok Buah ---\n";
        for (int i = 0; i < total; i++) {
            cout << i + 1
                << ". ID: " << daftarBuah[i].id
                << " | " << daftarBuah[i].nama
                << " | Harga: Rp" << daftarBuah[i].harga
                << " | Stok: " << daftarBuah[i].stok << " kg\n";
        }
    }
}

void updateHarga(int *hargaPtr, int hargaBaru) {
    *hargaPtr = hargaBaru;
}

void edit_buah(int total) {
    try {
        if (total == 0) throw runtime_error("Tidak ada data.");

        int index, hrgBaru;

        daftar_buah(total);
        cout << "Nomor data yang ingin diubah harganya: ";
        cin >> index;

        if (index <= 0 || index > total) throw out_of_range("Nomor tidak valid!");

        cout << "Masukkan Harga Baru: ";
        cin >> hrgBaru;
        if (cin.fail()) throw invalid_argument("Harga harus angka!");

        updateHarga(&daftarBuah[index - 1].harga, hrgBaru);
        cout << "Harga berhasil diperbarui!\n";
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void hapus_buah(int &total) {
    try {
        if (total == 0) throw runtime_error("Data kosong.");

        daftar_buah(total);
        int index;
        cout << "Nomor data yang ingin dihapus: ";
        cin >> index;

        if (index <= 0 || index > total) throw out_of_range("Nomor tidak valid!");

        for (int i = index - 1; i < total - 1; i++) {
            daftarBuah[i] = daftarBuah[i + 1];
        }
        total--;
        cout << "Data berhasil dihapus!\n";
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void namaAZ(int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (daftarBuah[j].nama > daftarBuah[j + 1].nama) {
                swap(daftarBuah[j], daftarBuah[j + 1]);
            }
        }
    }
    cout << "Sorting nama (A-Z) berhasil!\n";
}

void urutHarga(int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (daftarBuah[j].harga < daftarBuah[j + 1].harga) {
                swap(daftarBuah[j], daftarBuah[j + 1]);
            }
        }
    }
    cout << "Sorting harga (tertinggi) berhasil!\n";
}

void stokTerbanyak(int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (daftarBuah[j].stok < daftarBuah[j + 1].stok) {
                swap(daftarBuah[j], daftarBuah[j + 1]);
            }
        }
    }
    cout << "Sorting stok terbanyak berhasil!\n";
}

void sortID(int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (daftarBuah[j].id > daftarBuah[j + 1].id) {
                swap(daftarBuah[j], daftarBuah[j + 1]);
            }
        }
    }
}

void cariBuah(int total) {
    try {
        string cari;
        cout << "Masukkan nama buah: ";
        cin.ignore();
        getline(cin, cari);

        bool found = false;

        for (int i = 0; i < total; i++) {
            if (daftarBuah[i].nama == cari) {
                cout << "Data ditemukan:\n";
                cout << "ID: " << daftarBuah[i].id
                    << " | Nama: " << daftarBuah[i].nama
                    << " | Harga: Rp" << daftarBuah[i].harga
                    << " | Stok: " << daftarBuah[i].stok << " kg\n";
                found = true;
                break;
            }
        }

        if (!found) throw runtime_error("Buah tidak ditemukan.");
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void cariID(int total) {
    try {
        int target;
        cout << "Masukkan ID yang dicari: ";
        cin >> target;
        if (cin.fail()) throw invalid_argument("ID harus angka!");

        sortID(total);

        int low = 0, high = total - 1;
        bool found = false;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (daftarBuah[mid].id == target) {
                cout<< "Data ditemukan:\n";
                cout<< "ID: " << daftarBuah[mid].id
                    << " | Nama: " << daftarBuah[mid].nama
                    << " | Harga: Rp" << daftarBuah[mid].harga
                    << " | Stok: " << daftarBuah[mid].stok << " kg\n";
                found = true;
                break;
            } else if (daftarBuah[mid].id < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (!found) throw runtime_error("ID tidak ditemukan.");
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void menu() {
    cout << "\n=== MENU TOKO BUAH ===\n";
    cout << "1. Tambah Buah\n";
    cout << "2. Tampilkan Buah\n";
    cout << "3. Ubah Harga Buah\n";
    cout << "4. Hapus Data Buah\n";
    cout << "5. Urutkan Buah\n";
    cout << "6. Urutkan Harga\n";
    cout << "7. Urutkan Stok\n";
    cout << "8. Cari Buah\n";
    cout << "9. Cari ID Buah\n";
    cout << "10. Keluar\n";
    cout << "Pilih: ";
}

int main() {
    User admin = {"Owen", "053"};

    if (!login(admin)) {
        cout << "Gagal login 3x. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    do {
        menu();
        cin >> pilihan;

        try {
            if (cin.fail()) throw invalid_argument("Menu harus angka!");

            switch (pilihan) {
                case 1: tambah_buah(totalData);
                break;
                case 2: daftar_buah(totalData);
                break;
                case 3: edit_buah(totalData);
                break;
                case 4: hapus_buah(totalData);
                break;
                case 5: namaAZ(totalData);daftar_buah(totalData);
                break;
                case 6: urutHarga(totalData);daftar_buah(totalData); 
                break;
                case 7: stokTerbanyak(totalData);daftar_buah(totalData);
                break;
                case 8: cariBuah(totalData);
                break;
                case 9: cariID(totalData);
                break;
                case 10: cout << "Program selesai.\n";
                break;
                default: throw out_of_range("Pilihan tidak valid!");
            }
        }
        catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (pilihan != 10);

    return 0;
}