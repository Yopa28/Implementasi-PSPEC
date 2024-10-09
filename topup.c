#include <stdio.h>

int main() {
    int pilihan_vp;
    int metode_pembayaran;
    float harga_vp, biaya_tambahan, total_harga;

    // Menampilkan daftar harga VP
    printf("=== Valorant Top Up ===\n");
    printf("Pilih jumlah Valorant Points (VP) yang ingin Anda beli:\n");
    printf("1. 475 VP - Rp 50,000\n");
    printf("2. 950 VP - Rp 100,000\n");
    printf("3. 1900 VP - Rp 200,000\n");
    printf("4. 3850 VP - Rp 400,000\n");
    printf("5. 7550 VP - Rp 800,000\n");
    printf("Masukkan pilihan Anda (1-5): ");
    scanf("%d", &pilihan_vp);

    // Menentukan harga berdasarkan pilihan pengguna
    switch(pilihan_vp) {
        case 1:
            harga_vp = 50000;
            break;
        case 2:
            harga_vp = 100000;
            break;
        case 3:
            harga_vp = 200000;
            break;
        case 4:
            harga_vp = 400000;
            break;
        case 5:
            harga_vp = 800000;
            break;
        default:
            printf("Pilihan tidak valid.\n");
            return 1;
    }

    // Menampilkan metode pembayaran
    printf("\nPilih metode pembayaran:\n");
    printf("1. Kartu Kredit (Biaya tambahan 2%%)\n");
    printf("2. Transfer Bank (Biaya tambahan 1.5%%)\n");
    printf("3. E-Wallet (Tanpa biaya tambahan)\n");
    printf("Masukkan pilihan Anda (1-3): ");
    scanf("%d", &metode_pembayaran);

    // Menghitung total harga berdasarkan metode pembayaran
    switch(metode_pembayaran) {
        case 1:
            biaya_tambahan = harga_vp * 0.02; // 2% biaya tambahan
            total_harga = harga_vp + biaya_tambahan;
            break;
        case 2:
            biaya_tambahan = harga_vp * 0.015; // 1.5% biaya tambahan
            total_harga = harga_vp + biaya_tambahan;
            break;
        case 3:
            biaya_tambahan = 0; // Tidak ada biaya tambahan
            total_harga = harga_vp;
            break;
        default:
            printf("Metode pembayaran tidak valid.\n");
            return 1;
    }

    // Menampilkan hasil
    printf("\n=== Ringkasan Pembelian ===\n");
    printf("Harga VP: Rp %.2f\n", harga_vp);
    printf("Biaya tambahan: Rp %.2f\n", biaya_tambahan);
    printf("Total yang harus dibayar: Rp %.2f\n", total_harga);
    printf("Terima kasih telah melakukan top up!\n");

    return 0;
}
