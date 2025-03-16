/*
	Name: randomNum.c
	Copyright: 2025 JTK Polban
	Author: Faris Ichsan Alyawa
	Date: 17/03/25 00:02
	Description: 
*/

#include "Mahasiswa.h"

void initRandom() {
    // Inisialisasi rand dengan waktu saat ini
    srand(time(NULL));
}

int randomNilai() {
    // Menghasilkan angka acak antara 1 dan 100
    return (rand() % 100) + 1;
}

int randomMhs() {
    // Menghasilkan angka acak antara 1 dan 31
    return (rand() % 31) + 1;
}

int randomJmlh() {
    // Menghasilkan angka acak antara 1 dan 20
    return (rand() % 20) + 1;
}
