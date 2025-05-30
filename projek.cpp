#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

//struktur data untuk menyimpan inforamasi tiket
struct Item {
    string nama;
    double harga;
    string seat;
};

//struktur linked list untuk menyimpan order pembelian tiket
struct Order {
    string nama;
    double total_harga;
    string seatplan;
    Order* next;
};

//fungsi login dengan 3 kali percobaan dan validasi membership
void login() {
    system("cls");
    string username, password, membership;
    int percobaan = 0;
    const int batas_percobaan = 3;

    while (percobaan < batas_percobaan) {
        system("cls");
        cout << "\n=== 2025 RIIZE FAN-CON RIIZING DAY in JAKARTA ===\n";
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "zizi" && password == "12345") {
            cout << "\nMasukkan Nomor Membership Anda: ";
            cin >> membership;

            if (membership == "124240") {
                cout << "\nLogin berhasil! Welcome Briize, " << username << ".\n";
                cout << "Nomor Membership: " << membership << "\n";
                system("pause");
                return;
            } else {
                cout << "\nNomor membership tidak valid. Silakan coba lagi.\n";
                system("pause");
                return login(); //coba lagi
            }
        } else {
            percobaan++;
            cout << "\nLogin gagal! Percobaan ke-" << percobaan << " dari " << batas_percobaan << ".\n";
            system("pause");
        }
    }

    cout << "\nAnda telah gagal login lebih dari " << batas_percobaan << " kali.\n";
    cout << "Akses ditolak. Program akan keluar.\n";
    exit(0);
}

void ketentuanUmum() {
    system("cls");
    cout << "\n=== Ketentuan Umum 2025 RIIZE FAN-CON RIIZING DAY in JAKARTA ===\n\n";
    cout << "1. Tiket hanya sah jika dibeli sesuai prosedur resmi dari penyelenggara.\n\n";
    cout << "2. E-voucher bersifat rahasia dan tidak boleh dibagikan.\n\n";
    cout << "3. Hanya pembeli sah yang akan menerima e-voucher dari promotor resmi.\n\n";
    cout << "4. Promotor tidak bertanggung jawab atas pemalsuan atau perpindahan e-voucher.\n\n";
    cout << "5. Pemilik tiket CAT 1 & CAT 3–4 mendapat nomor antrian sesuai kategori.\n\n";
    cout << "6. Pemilik tiket CAT 2 mendapat nomor kursi.\n\n";
    cout << "7. Nomor antrian/kursi diberikan otomatis berdasarkan waktu pembelian.\n\n";
    cout << "8. Nomor akan diperbarui di e-voucher, maksimal H-7 konser.\n\n";
    cout << "9. Satu e-voucher hanya berlaku untuk satu orang dan tidak bisa digandakan.\n\n";
    cout << "10. Pembelian tiket menyetujui penggunaan data pribadi untuk acara.\n\n";
    cout << "11. E-voucher wajib ditukar dengan wristband saat penukaran.\n\n";
    system("pause");
}

//menampilkan daftar semua tiket
void daftarTiket(const Item tiket[], int jumlah_tiket, string seatlist) {
    system("cls");
    cout << "\n=== " << seatlist << " ===\n";
    cout << left << setw(6) << "No"
         << setw(30) << "Seatplan"
         << setw(15) << "Harga (Rp)"
         << setw(20) << "Keterangan " << endl;
    cout << setfill('-') << setw(71) << "-" << endl;
    cout << setfill(' ');

    //menampilkan tabel tiket
    for (int i = 0; i < jumlah_tiket; i++) {
        cout << setw(6) << i + 1
             << setw(30) << tiket[i].nama
             << setw(15) << fixed << setprecision(0) << tiket[i].harga
             << setw(20) << tiket[i].seat << endl;
    }
}

//mencari tiket berdasarkan kategori seat
void cariTiket(const Item tiket[], int jumlah_tiket, const string& kategori) {
    system("cls");
    bool ditemukan = false;
    cout << "\nHasil pencarian untuk kategori: " << kategori << "\n";
    for (int i = 0; i < jumlah_tiket; i++) {
        if (tiket[i].seat == kategori) {
            cout << "- " << tiket[i].nama << " (Rp " << fixed << setprecision(0) << tiket[i].harga << ")\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Tidak ditemukan tiket dengan kategori tersebut.\n";
    }
    system("pause");
}

//menampilkan tiket secara urut berdasarkan tingkat kepadatan
void urutkanTiket(const Item tiket[], int jumlah_tiket, bool dariLimited = true) {
    system("cls");
    cout << "\n=== Tiket Berdasarkan Kepadatan ===\n";
    cout << "(Urutan: " << (dariLimited ? "Limited Slot ke Reguler" : "Reguler ke Limited Slot") << ")\n";

    if (dariLimited) { //dari limited ke reguler
        for (int i = 0; i < jumlah_tiket; i++) {
            if (tiket[i].nama == "CAT 1A Soundcheck" || tiket[i].nama == "CAT 1B Soundcheck" ||
                tiket[i].nama == "CAT 1C" || tiket[i].nama == "CAT 1D") {
                cout << "[LIMITED SLOT]  " << tiket[i].nama << " (" << tiket[i].seat << ", Rp " 
                     << fixed << setprecision(0) << tiket[i].harga << ")\n";
            }
        }
        for (int i = 0; i < jumlah_tiket; i++) {
            if (!(tiket[i].nama == "CAT 1A Soundcheck" || tiket[i].nama == "CAT 1B Soundcheck" ||
                  tiket[i].nama == "CAT 1C" || tiket[i].nama == "CAT 1D")) {
                cout << "[REGULER]       " << tiket[i].nama << " (" << tiket[i].seat << ", Rp " 
                     << fixed << setprecision(0) << tiket[i].harga << ")\n";
            }
        }
    } else {
        for (int i = 0; i < jumlah_tiket; i++) { //dari reguler ke limited
            if (!(tiket[i].nama == "CAT 1A Soundcheck" || tiket[i].nama == "CAT 1B Soundcheck" ||
                  tiket[i].nama == "CAT 1C" || tiket[i].nama == "CAT 1D")) {
                cout << "[REGULER]       " << tiket[i].nama << " (" << tiket[i].seat << ", Rp " 
                     << fixed << setprecision(0) << tiket[i].harga << ")\n";
            }
        }
        for (int i = 0; i < jumlah_tiket; i++) {
            if (tiket[i].nama == "CAT 1A Soundcheck" || tiket[i].nama == "CAT 1B Soundcheck" ||
                tiket[i].nama == "CAT 1C" || tiket[i].nama == "CAT 1D") {
                cout << "[LIMITED SLOT]  " << tiket[i].nama << " (" << tiket[i].seat << ", Rp " 
                     << fixed << setprecision(0) << tiket[i].harga << ")\n";
            }
        }
    }
    cout << endl;
    system("pause");
}

//menambah tiket ke daftar  order (linked list) 
Order* tambahOrder(Order* head, Item tiket) {
    double pajak = tiket.harga * 0.1;
    double total = tiket.harga + pajak;

    Order* baru = new Order{tiket.nama, total, tiket.seat, nullptr};
    if (!head) return baru; //jika belum ada order

    Order* current = head;
    while (current->next) current = current->next;
    current->next = baru;
    return head;
}

//membeli tiket input nomor tiket lalu tambah ke order
Order* beliTiket(const Item tiket[], int jumlah_tiket, Order* head, string seatlist) {
    daftarTiket(tiket, jumlah_tiket, seatlist);
    int pilihan;
    cout << "\nMasukkan nomor tiket (0 untuk batal): ";
    cin >> pilihan;

    if (pilihan >= 1 && pilihan <= jumlah_tiket) {
        head = tambahOrder(head, tiket[pilihan - 1]);
        cout << "\nTiket berhasil dibeli!\n";
        // menampilkan rincian tiket yang sudah dibeli
        double pajak = tiket[pilihan - 1].harga * 0.1;
        double total = tiket[pilihan - 1].harga + pajak;
        cout << "-----------------------------\n";
        cout << "Nama Tiket : " << tiket[pilihan - 1].nama << endl;
        cout << "Seatplan   : " << tiket[pilihan - 1].seat << endl;
        cout << "Harga      : Rp " << fixed << setprecision(0) << tiket[pilihan - 1].harga << endl;
        cout << "Pajak (10%): Rp " << pajak << endl;
        cout << "Total Bayar: Rp " << total << endl;
        cout << "-----------------------------\n";
    } else if (pilihan != 0) {
        cout << "Pilihan tidak valid!\n";
    }
    system("pause");
    return head;
}

//mwnampilkan semua order yang sudah dibeli
void tampilkanOrder(Order* head) {
    system("cls");
    if (!head) {
        cout << "\nBelum ada order yang dibuat!.\n";
    } else {
        cout << "\n=== Daftar Order ===\n";
        int no = 1;
        while (head) {
            cout << no++ << ". " << head->nama << " - Rp " << fixed << setprecision(0) 
                 << head->total_harga << " (" << head->seatplan << ")\n";
            head = head->next;
        }
    }
    system("pause");
}
// Menghapus order pertama dalam linked list
Order* hapusOrder(Order* head) {
    system("cls");
    if (!head) {
        cout << "\nBelum ada order yang bisa dihapus.\n";
        system("pause");
        return nullptr;
    }
    Order* temp = head;
    head = head->next;
    delete temp;
    cout << "\nOrder paling awal berhasil dihapus.\n";
    system("pause");
    return head;
}
// Menyimpan data harga ke file dummy
void simpanHargaKeFileDummy(const Item tiket[], int jumlah) {
    FILE* file = fopen("harga.txt", "w");
    if (!file) {
        cout << "Gagal membuka file harga.txt!\n";
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        fprintf(file, "%s;%.0f\n", tiket[i].nama.c_str(), tiket[i].harga);
    }
    fclose(file);
    cout << "Data harga berhasil disimpan ke harga.txt\n";
}
// Membaca data harga dari file dummy
void bacaHargaDariFileDummy(Item tiket[], int &jumlah) {
    FILE* file = fopen("harga.txt", "r");
    if (!file) {
        cout << "File harga.txt tidak ditemukan!\n";
        return;
    }
    jumlah = 0;
    char nama[100];
    double harga;
    while (fscanf(file, "%99[^;];%lf\n", nama, &harga) == 2) {
        tiket[jumlah].nama = nama;
        tiket[jumlah].harga = harga;
        tiket[jumlah].seat = "-";
        jumlah++;
    }
    fclose(file);
    cout << "Data harga berhasil dibaca dari harga.txt\n";
}

int main() { // Fungsi utama program
    // Inisialisasi array tiket
    Item tiket[] = {
        {"CAT 1A Soundcheck", 2700000, "standing"},
        {"CAT 1B Soundcheck", 2700000, "standing"},
        {"CAT 1C", 2300000, "standing"},
        {"CAT 1D", 2300000, "standing"},
        {"CAT 2", 2200000, "seated"},
        {"CAT 3A", 1700000, "standing"},
        {"CAT 3B", 1700000, "standing"},
        {"CAT 4A", 1200000, "standing"},
        {"CAT 4B", 1200000, "standing"},
    };

    int jumlah_tiket = sizeof(tiket) / sizeof(tiket[0]);
    Order* head = nullptr;

    login(); // Login dulu sebelum lanjut

    int pilihan;
    do {
        system("cls");
        cout << "\n=== Sistem POS Tiket Konser ===\n";
        cout << "1. Keterangan Umum\n";
        cout << "2. Cari Tiket Berdasarkan Seatplan\n";
        cout << "3. Urutkan Tiket Berdasarkan Kepadatan\n";
        cout << "4. Beli Tiket\n";
        cout << "5. Tampilkan Order\n";
        cout << "6. Hapus Order\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        // Menu switch untuk pilihan pengguna
        switch (pilihan) {
            case 1:
                ketentuanUmum();
                break;
            case 2: {
                string cari;
                cout << "Masukkan jenis seatplan (standing/seated): ";
                cin >> cari;
                cariTiket(tiket, jumlah_tiket, cari);
                break;
            }
            case 3: {
                int mode;
                cout << "\nUrutkan berdasarkan:\n";
                cout << "1. Limited Slot ke Reguler\n";
                cout << "2. Reguler ke Limited Slot\n";
                cout << "Pilihan: ";
                cin >> mode;
                urutkanTiket(tiket, jumlah_tiket, mode == 1);
                break;
            }
            case 4:
                head = beliTiket(tiket, jumlah_tiket, head, "Daftar Tiket");
                break;
            case 5:
                tampilkanOrder(head);
                break;
            case 6:
                head = hapusOrder(head);
                break;
            case 0:
                cout << "Thank You Briize, Enjoy The Show!.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
                break;
        }
    } while (pilihan != 0);

    return 0;

}
