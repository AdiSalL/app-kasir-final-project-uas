#include <iostream>
#include <stdlib.h>
using namespace std;

int jumlah_total_menu;
string nama_menu[100];
int jumlah_porsi[100];
float harga_menu[100];
float sub_total[100];
float total_harga = 0;
float jumlah_bayar, kembalian;
char pilihan;

void inputMenu () {

    // Input data menu
    for (int i = 0; i < jumlah_total_menu; i++) {
        cout << "Menu ke-" << i + 1 << ":" << endl;

        // Input nama menu
        cout << "Masukkan nama menu: ";
        cin >> nama_menu[i];
		
		// Input harga 1 porsi
        cout << "Masukkan harga 1 porsi: ";
        cin >> harga_menu[i];

        // Input jumlah porsi
        cout << "Masukkan jumlah porsi: ";
        cin >> jumlah_porsi[i];


        // Hitung sub total untuk setiap menu
        sub_total[i] = jumlah_porsi[i] * harga_menu[i];
    }

}

int main() {
mulai:
    system("cls"); // Membersihkan layar
	cout << "*******************" << endl;
    cout << "=============== Program Kasir Warung Makan ==============" << endl;

    // Input jumlah total menu
           cout << "Masukkan jumlah total menu yang ingin dibeli: ";
    cin >> jumlah_total_menu;

    // Validasi jumlah total menu
    if (jumlah_total_menu < 1) {
        cout << "Menu tidak valid, apakah ingin mengulang? (y/n): ";
        cin >> pilihan;

        if (pilihan == 'y' || pilihan == 'Y') {
            goto mulai; // Ulangi proses dari awal
        } else {
            cout << "Program selesai. Terima kasih!" << endl;
            return 0; // Keluar program
        }
    }else {
        //masuk ke function input menu
        inputMenu();
    }
    // Tampilkan riwayat belanja
    cout << "---------------------------------------------------------" << endl;
    cout << "####-------------- Struk Warung Makan ---------------####" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "No.\tNama Menu\tHarga\tJumlah\t\tSubtotal" << endl;
    for (int i = 0; i < jumlah_total_menu; i++) {
        cout << i + 1 << "\t" 
             << nama_menu[i] << "\t" 
             << harga_menu[i] << "\t" 
             << jumlah_porsi[i] << "\t\t" 
             << sub_total[i] << endl;
        total_harga += sub_total[i];
    }

    // Tampilkan total harga
	cout << "*******************" << endl;
    cout << "=========================================================" << endl;
    cout << "Total Harga: " << total_harga << endl;

    // Input jumlah bayar
    do {
        cout << "Masukkan jumlah bayar: ";
        cin >> jumlah_bayar;

        // Validasi pembayaran
        if (jumlah_bayar < total_harga) {
            cout << "Uang tidak cukup. Harap ulangi pembayaran." << endl;
        }
    } while (jumlah_bayar < total_harga);

    // Hitung kembalian
    kembalian = jumlah_bayar - total_harga;
    cout << "Kembalian: " << kembalian << endl;

    // Tanya apakah ada pesanan lagi
    cout << "Apakah ada pesanan lagi? (y/n): ";
    cin >> pilihan;
    if (pilihan == 'y' || pilihan == 'Y') {
        goto mulai; // Ulang program
    }

    // Selesai
    cout << "==============Terima kasih telah berbelanja!=============" << endl;
	cout << "*******************" << endl;

}



// Final Project Algoritma Pemrograman Kelompok 7
