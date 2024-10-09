#include <stdio.h>

// Struktur untuk menyimpan informasi motor
struct Motor {
    char nama[50];
    int harga;
    int jumlah_terjual;
};

int main() {
    int i, n;
    int total_penjualan = 0;

    // Meminta input jumlah jenis motor yang dijual
    printf("Masukkan jumlah jenis motor: ");
    scanf("%d", &n);

    // Deklarasi array motor
    struct Motor motor[n];

    // Input data penjualan motor
    for (i = 0; i < n; i++) {
        printf("\nMasukkan nama motor ke-%d: ", i + 1);
        scanf("%s", motor[i].nama);

        printf("Masukkan harga motor %s: ", motor[i].nama);
        scanf("%d", &motor[i].harga);

        printf("Masukkan jumlah terjual motor %s: ", motor[i].nama);
        scanf("%d", &motor[i].jumlah_terjual);
    }

    // Menampilkan laporan dan menghitung total penjualan
    printf("\nLaporan Penjualan Motor:\n");
    printf("-------------------------------\n");
    printf("Nama Motor | Harga | Jumlah Terjual | Total Penjualan\n");
    printf("-------------------------------\n");

    for (i = 0; i < n; i++) {
        int total_motor = motor[i].harga * motor[i].jumlah_terjual;
        printf("%s | %d | %d | %d\n", motor[i].nama, motor[i].harga, motor[i].jumlah_terjual, total_motor);
        total_penjualan += total_motor;
    }

    printf("-------------------------------\n");
    printf("Total Penjualan Semua Motor: %d\n", total_penjualan);

    return 0;
}
