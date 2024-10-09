#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char merk[50];
    char model[50];
    int tahun;
    double harga;
} Mobil;

typedef struct {
    Mobil *mobils;
    int ukuran;
    int kapasitas;
} PenjualanMobil;

PenjualanMobil* buatPenjualanMobil(int kapasitas) {
    PenjualanMobil *penjualan = (PenjualanMobil*)malloc(sizeof(PenjualanMobil));
    penjualan->mobils = (Mobil*)malloc(sizeof(Mobil) * kapasitas);
    penjualan->ukuran = 0;
    penjualan->kapasitas = kapasitas;
    return penjualan;
}

void tambahMobil(PenjualanMobil *penjualan, Mobil mobil) {
    if (penjualan->ukuran >= penjualan->kapasitas) {
        printf("Kapasitas penjualan mobil telah tercapai.\n");
        return;
    }
    penjualan->mobils[penjualan->ukuran++] = mobil;
}

void daftarMobil(PenjualanMobil *penjualan) {
    for (int i = 0; i < penjualan->ukuran; i++) {
        printf("%d. Merk: %s, Model: %s, Tahun: %d, Harga: Rp%.2f\n", 
            i + 1, penjualan->mobils[i].merk, penjualan->mobils[i].model, penjualan->mobils[i].tahun, penjualan->mobils[i].harga);
    }
}

Mobil* pilihMobil(PenjualanMobil *penjualan, int indeks) {
    if (indeks < 1 || indeks > penjualan->ukuran) {
        printf("Pilihan mobil tidak valid.\n");
        return NULL;
    }
    return &penjualan->mobils[indeks - 1];
}

void tampilkanMenu() {
    printf("1. Tambah Mobil\n");
    printf("2. Daftar Mobil\n");
    printf("3. Pilih Mobil untuk Beli\n");
    printf("4. Keluar\n");
    printf("Pilih opsi: ");
}

int main() {
    PenjualanMobil *penjualan = buatPenjualanMobil(10);
    int pilihan;

    do {
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: {
                Mobil mobil;
                printf("Masukkan merk: ");
                scanf("%s", mobil.merk);
                printf("Masukkan model: ");
                scanf("%s", mobil.model);
                printf("Masukkan tahun: ");
                scanf("%d", &mobil.tahun);
                printf("Masukkan harga: ");
                scanf("%lf", &mobil.harga);
                tambahMobil(penjualan, mobil);
                printf("Mobil berhasil ditambahkan.\n");
                break;
            }
            case 2:
                daftarMobil(penjualan);
                break;
            case 3: {
                int nomorMobil;
                printf("Pilih nomor mobil untuk dibeli: ");
                scanf("%d", &nomorMobil);
                Mobil *mobilTerpilih = pilihMobil(penjualan, nomorMobil);
                if (mobilTerpilih != NULL) {
                    printf("Anda memilih untuk membeli: Merk: %s, Model: %s, Tahun: %d, Harga: Rp%.2f\n", 
                        mobilTerpilih->merk, mobilTerpilih->model, mobilTerpilih->tahun, mobilTerpilih->harga);
                }
                break;
            }
            case 4:
                printf("Keluar...\n");
                break;
            default:
                printf("Opsi tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 4);

    free(penjualan->mobils);
    free(penjualan);

    return 0;
}
