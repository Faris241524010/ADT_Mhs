/*
	Name: Mahasiswa.c
	Copyright: 2025 JTK Polban
	Author: Faris Ichsan Alyawa
	Date: 17/03/25 00:02
	Description: 
*/

#include "Mahasiswa.h"

// Constructor: Membuat list kosong
void createList(List* list) {
    list->first = Nil;
}

// Destructor: Menghapus semua elemen dalam list
void destroyList(List* list) {
    address current = list->first;
    address temp;
    while (current != Nil) {
        temp = current;
        current = current->next;
        free(temp->nama); // Pastikan untuk membebaskan memori yang dialokasikan untuk 'nama'
        free(temp); // Bebaskan memori elemen
    }
    list->first = Nil;  // Mengubah 'first' menjadi Nil
}

// Validator: Mengecek apakah list kosong
int isEmpty(List* list) {
    return list->first == Nil;
}

// Set: Menambahkan Mahasiswa ke dalam list
void addMahasiswa(List* list, infochar nama, infotype nilai) {
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode == Nil) {
        printf("Gagal mengalokasikan memori!\n");
        return;
    }
    
    // Mengalokasikan memori untuk nama mahasiswa dan menyalin nama
    newNode->nama = (infochar)malloc(strlen(nama) + 1);
    if (newNode->nama == Nil) {
        printf("Gagal mengalokasikan memori untuk nama!\n");
        free(newNode);
        return;
    }
    strcpy(newNode->nama, nama);
    
    newNode->nilai = nilai;
    newNode->next = list->first;
    list->first = newNode;
}

// Get: Mencari Mahasiswa berdasarkan nilai
address getMahasiswa(List* list, infotype nilai) {
    address current = list->first;
    while (current != Nil) {
        if (current->nilai == nilai) {
            return current;
        }
        current = current->next;
    }
    return Nil; // Tidak ditemukan
}

// PrintObject: Menampilkan seluruh Mahasiswa dalam list
void printList(List* list) {
    address current = list->first;
    if (isEmpty(list)) {
        printf("Daftar mahasiswa kosong.\n");
        return;
    }

    printf("Daftar Mahasiswa:\n");
    while (current != Nil) {
        printf("Nama: %s, Nilai: %d\n", current->nama, current->nilai);
        current = current->next;
    }
}

// Fungsi untuk mengambil nama berdasarkan baris yang dipilih dari file
char* getNamaDariFile(int barisPilihan) {
    FILE *file = fopen("absen.txt", "r");
    if (file == NULL) return NULL;

    char* nama = (char*)malloc(100 * sizeof(char));  // Alokasi memori dinamis
    if (!nama) {
        fclose(file);  // Pastikan file ditutup jika malloc gagal
        return NULL;   // Jika malloc gagal
    }

    int baris = 1;
    while (fgets(nama, 100, file)) {
        if (baris == barisPilihan) {
            // Menghapus karakter newline atau spasi yang ada di akhir string
            size_t len = strlen(nama);
            if (len > 0) {
                // Menghapus newline jika ada
                if (nama[len - 1] == '\n') {
                    nama[len - 1] = '\0';
                    len--;  // Sesuaikan panjang setelah penghapusan newline
                }
                
                // Menghapus spasi di akhir jika ada
                while (len > 0 && nama[len - 1] == ' ') {
                    nama[len - 1] = '\0';
                    len--;
                }
            }
            fclose(file);
            return nama;
        }
        baris++;
    }

    // Jika baris yang diminta tidak ditemukan
    free(nama);
    fclose(file);
    return NULL;
}


/* Fungsi untuk menghitung jumlah elemen dalam list */
int HitungElemen(List* list) {
    int count = 0;
    address current = list->first;
    
    while (current != Nil) {
        count++;
        current = current->next;
    }
    
    return count;
}


