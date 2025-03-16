/*
	Name: duplikasiManager.c
	Copyright: 2025 JTK Polban
	Author: Faris Ichsan Alyawa
	Date: 17/03/25 00:02
	Description: 
*/

#include "Mahasiswa.h"

void DuplikasiList(List* list1, List* list2) {
    address current = list1->first;
    
    while (current != Nil && current->nilai > 70) {
        addMahasiswa(list2, current->nama, current->nilai);
        current = current->next;
    }
}

void HapusDuplikatNama(List* list) {
    address current, prev, temp;
    current = list->first;

    while (current != Nil) {
        prev = current;
        address checker = current->next;

        while (checker != Nil) {
            if (strcmp(current->nama, checker->nama) == 0) {
                // Hapus elemen duplikat
                prev->next = checker->next;
                temp = checker;
                checker = checker->next;
                free(temp); // Bebaskan memori
            } else {
                prev = checker;
                checker = checker->next;
            }
        }
        current = current->next;
    }
}
