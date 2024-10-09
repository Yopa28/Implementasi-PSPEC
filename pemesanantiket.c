#include <stdio.h>
#include <string.h>

void daftar_maskapai() {
    printf("Daftar Maskapai:\n");
    printf("1. Garuda Indonesia\n");
    printf("2. Lion Air\n");
    printf("3. Citilink\n");
    printf("4. AirAsia\n");
}

void daftar_bandara() {
    printf("Daftar Bandara Tujuan:\n");
    printf("1. Soekarno-Hatta (Jakarta)\n");
    printf("2. Ahmad Yani (Semarang)\n");
    printf("3. Juanda (Surabaya)\n");
    printf("4. Sultan Hasanuddin (Makassar)\n");
}

int harga_tiket(int pilihan_maskapai) {
    switch (pilihan_maskapai) {
        case 1:
            return 1500000; // Harga Garuda Indonesia
        case 2:
            return 900000;  // Harga Lion Air
        case 3:
            return 1000000; // Harga Citilink
        case 4:
            return 800000;  // Harga AirAsia
        default:
            return 0;
    }
}

int main() {
    int pilihan_maskapai, pilihan_bandara, jumlah_tiket;
    char nama_penumpang[100];

    printf("Selamat datang di biro tiket pesawat reza\n");
    printf("Masukkan nama penumpang: ");
    fgets(nama_penumpang, sizeof(nama_penumpang), stdin);
    // Menghapus newline yang mungkin tersimpan dalam input nama penumpang
    nama_penumpang[strcspn(nama_penumpang, "\n")] = 0;

    daftar_maskapai();
    printf("Pilih maskapai yang diinginkan (1-4): ");
    scanf("%d", &pilihan_maskapai);

    if (pilihan_maskapai < 1 || pilihan_maskapai > 4) {
        printf("Pilihan maskapai tidak valid!\n");
        return 1;
    }

    daftar_bandara();
    printf("Pilih tujuan bandara (1-4): ");
    scanf("%d", &pilihan_bandara);

    if (pilihan_bandara < 1 || pilihan_bandara > 4) {
        printf("Pilihan bandara tidak valid!\n");
        return 1;
    }

    printf("Masukkan jumlah tiket yang ingin dibeli: ");
    scanf("%d", &jumlah_tiket);

    int harga = harga_tiket(pilihan_maskapai);
    int total_harga = harga * jumlah_tiket;

    printf("\n=== Detail Pemesanan ===\n");
    printf("Nama Penumpang: %s\n", nama_penumpang);

    switch (pilihan_maskapai) {
        case 1:
            printf("Maskapai: Garuda Indonesia\n");
            break;
        case 2:
            printf("Maskapai: Lion Air\n");
            break;
        case 3:
            printf("Maskapai: Citilink\n");
            break;
        case 4:
            printf("Maskapai: AirAsia\n");
            break;
    }

    switch (pilihan_bandara) {
        case 1:
            printf("Tujuan: Soekarno-Hatta (Jakarta)\n");
            break;
        case 2:
            printf("Tujuan: Ahmad Yani (Semarang)\n");
            break;
        case 3:
            printf("Tujuan: Juanda (Surabaya)\n");
            break;
        case 4:
            printf("Tujuan: Sultan Hasanuddin (Makassar)\n");
            break;
    }

    printf("Jumlah tiket: %d\n", jumlah_tiket);
    printf("Harga per tiket: Rp %d\n", harga);
    printf("Total harga: Rp %d\n", total_harga);

    printf("\nTerima kasih sudah memesan tiket!\n");

    return 0;
}
