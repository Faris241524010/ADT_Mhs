/*
	Name: Sorting.c
	Copyright: 2025 JTK Polban
	Author: Faris Ichsan Alyawa
	Date: 17/03/25 00:02
	Description: 
*/

#include "Mahasiswa.h"

void TampilkanAscending(List* list) {
    int jumlah = HitungElemen(list);
    if (jumlah == 0) {
        printf("List kosong.\n");
        return;
    }

    // Menyimpan elemen dalam array untuk diurutkan
    address current = list->first;
    ElmtList* tempArray[jumlah];
    int i = 0;

    while (current != Nil) {
        tempArray[i] = current;
        current = current->next;
        i++;
    }

    // Bubble Sort untuk mengurutkan berdasarkan nama
    for (int j = 0; j < jumlah - 1; j++) {
        for (int k = 0; k < jumlah - j - 1; k++) {
            if (strcmp(tempArray[k]->nama, tempArray[k + 1]->nama) > 0) {
                // Swap elemen
                ElmtList* temp = tempArray[k];
                tempArray[k] = tempArray[k + 1];
                tempArray[k + 1] = temp;
            }
        }
    }

    // Menampilkan hasil setelah diurutkan
    printf("List dalam urutan ascending berdasarkan nama:\n");
    for (i = 0; i < jumlah; i++) {
        printf("%s - %d\n", tempArray[i]->nama, tempArray[i]->nilai);
    }
}

void TampilkanDescending(List* list) {
    int jumlah = HitungElemen(list);
    if (jumlah == 0) {
        printf("List kosong.\n");
        return;
    }

    // Buat array sementara untuk menyimpan pointer ke elemen list
    address* arr = (address*)malloc(jumlah * sizeof(address));
    if (arr == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return;
    }

    // Simpan pointer setiap elemen ke dalam array
    address current = list->first;
    for (int i = 0; i < jumlah; i++) {
        arr[i] = current;
        current = current->next;
    }

    // Sorting array berdasarkan nilai (descending) menggunakan Bubble Sort
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (arr[j]->nilai < arr[j + 1]->nilai) {
                address temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Tampilkan hasil sorting
    printf("List dalam urutan descending berdasarkan nilai:\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%s - %d\n", arr[i]->nama, arr[i]->nilai);
    }

    // Bebaskan memori array sementara
    free(arr);
}
