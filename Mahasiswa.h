/*
	Name: Mahasiswa.h
	Copyright: 2025 JTK Polban
	Author: Faris Ichsan Alyawa
	Date: 17/03/25 00:02
	Description: 
*/

#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>    // Untuk fungsi time()

#ifndef Nil
#define Nil NULL
#endif

/* Definisi Node */

typedef char *infochar;     // Tipe untuk nama
typedef int infotype;     // Tipe untuk nilai UTS
typedef struct tElmtList *address;

typedef struct tElmtList {
    infochar nama;          // Nama mahasiswa
    infotype nilai;         // Nilai UTS
    address next;           // Pointer ke elemen berikutnya
} ElmtList;

/* Definisi list: */
typedef struct {
    address first;          // Elemen pertama
} List;

/* 5 Fungsi utama */
/* Constructor: Membuat list kosong */
void createList(List* list);

/* Destructor: Menghapus semua elemen dalam list */
void destroyList(List* list);

/* Validator: Mengecek apakah list kosong */
int isEmpty(List* list);

/* Get/Set: Mengambil/menambahkan mahasiswa dalam list */
address getMahasiswa(List* list, infotype nilai);
void addMahasiswa(List* list, infochar nama, infotype nilai);

/* PrintObject: Menampilkan seluruh mahasiswa dalam list */
void printList(List* list);

int HitungElemen(List* list);

void TampilkanAscending(List* list);
void TampilkanDescending(List* list);

char* getNamaDariFile(int barisPilihan);

void initRandom();
int randomJmlh();
int randomNilai();
int randomMhs();

void tampilkanMenu();

void DuplikasiList(List* list1, List* list2);
void HapusDuplikatNama(List* list);
#endif
