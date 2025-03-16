/*
	Name: menu.c
	Copyright: 2025 JTK Polban
	Author: Faris Ichsan Alyawa
	Date: 17/03/25 00:02
	Description: 
*/

#include "Mahasiswa.h"

void tampilkanMenu() {
    List list1, list2;
    createList(&list1);
    createList(&list2);

    while (1) {
        system("cls");
        int pilihan;
        printf("List L1 dan L2 berhasil dibuat\n");

        printf("===== Menu =====\n");
        printf("1. Isikan sejumlah elemen\n");
        printf("2. Tampilkan isi List\n");
        printf("3. Hitung Jumlah elemen\n");
        printf("4. Copy seluruh elemen\n");
        printf("5. Hapus duplikat\n");
        printf("6. Hapus List L1 dan L2\n");
        printf("7. Keluar\n");
        printf("================\n");
        printf("Pilih opsi (1-7): ");
        
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid. Silakan coba lagi.\n");
            while(getchar() != '\n'); // Clear the buffer
            continue;
        }

        switch (pilihan) {
            case 1: { // Submenu untuk Hitung Jumlah Elemen
                int subMenuChoice;
                while (1) {
                    system("cls");
                    printf("===== Menu isi Elemen List1=====\n");
                    printf("1. Isi elemen List1 secara otomatis acak\n");
                    printf("2. Isi elemen List1 secara manual\n");
                    printf("3. Kembali\n");
                    printf("=====================================\n");
                    printf("Pilih opsi (1-3): ");
                    
                    if (scanf("%d", &subMenuChoice) != 1) {
                        printf("Input tidak valid. Silakan coba lagi.\n");
                        while(getchar() != '\n'); // Clear the buffer
                        continue;
                    }

                    switch (subMenuChoice) {
                        case 1:
                            system("cls");
			                initRandom();
			                int jmlh; 
							jmlh = randomJmlh();
			                printf("Sejumlah elemen diisikan sebanyak %d elemen.\n", jmlh);
							while (jmlh > 0){
								addMahasiswa(&list1, getNamaDariFile(randomMhs()), randomNilai());
								jmlh--;
							}
			                Sleep(2000);
							break;
                        case 2:
                            system("cls");
                            char inputNama[100];
                            int inputNilai;
                            while (getchar() != '\n');
                            
                            printf("Masukkan nama mahasiswa:\n");
                            fgets(inputNama, sizeof(inputNama), stdin);
                            inputNama[strcspn(inputNama, "\n")] = 0;
                            
                            printf("Masukkan nilai UTS mahasiswa:\n");
                            scanf("%d", &inputNilai);
                            
                            addMahasiswa(&list1, inputNama, inputNilai);
                            getchar(); getchar();
							break;
                        case 3:
                            break; // Kembali ke menu utama
                        default:
                            printf("Pilihan tidak valid.\n");
                            break;
                    }
                    if (subMenuChoice == 3) {
                    	break;
					}
                }
                break;
            }

            case 2: { // Submenu untuk Tampilkan Isi List
                int subMenuChoice;
                while (1) {
                    system("cls");
                    printf("===== Menu Tampilkan List =====\n");
                    printf("1. Tampilkan isi List1\n");
                    printf("2. Tampilkan isi List2\n");
                    printf("3. Kembali\n");
                    printf("===============================\n");
                    printf("Pilih opsi (1-3): ");
                    
                    if (scanf("%d", &subMenuChoice) != 1) {
                        printf("Input tidak valid. Silakan coba lagi.\n");
                        while(getchar() != '\n'); // Clear the buffer
                        continue;
                    }

                    switch (subMenuChoice) {
                        case 1:{ // Submenu untuk Tampilkan Isi List
			                int subMenuChoice2;
			                while (1) {
			                    system("cls");
			                    printf("===== Menu Tampilkan List =====\n");
			                    printf("1. Tampilkan isi List1 (Ascending Nama)\n");
			                    printf("2. Tampilkan isi List1 (Descending Nilai)\n");
			                    printf("3. Kembali\n");
			                    printf("===============================\n");
			                    printf("Pilih opsi (1-3): ");
			                    
			                    if (scanf("%d", &subMenuChoice2) != 1) {
			                        printf("Input tidak valid. Silakan coba lagi.\n");
			                        while(getchar() != '\n'); // Clear the buffer
			                        continue;
			                    }
			
			                    switch (subMenuChoice2) {
			                        case 1:
			                            system("cls");
			                            TampilkanAscending(&list1);
			                            getchar(); getchar();
			                            break;
			                        case 2:
			                            system("cls");
			                            TampilkanDescending(&list1);
			                            getchar(); getchar();
			                            break;
			                        case 3:
			                            break; // Kembali ke menu utama
			                        default:
			                            printf("Pilihan tidak valid.\n");
			                            break;
			                    }
			                    if (subMenuChoice2 == 3) {
			                    	break;
								}
			                }
			                break;
			            }
                            break;
                        case 2:
                            system("cls");
                            printList(&list2); // Tampilkan isi List2
                            getchar(); getchar();
                            break;
                        case 3:
                            break; // Kembali ke menu utama
                        default:
                            printf("Pilihan tidak valid.\n");
                            break;
                    }
                    if (subMenuChoice == 3) {
                    	break;
					}
                }
                break;
            }

            case 3: { // Submenu untuk Hitung Jumlah Elemen
                int subMenuChoice;
                while (1) {
                    system("cls");
                    printf("===== Menu Hitung Jumlah Elemen =====\n");
                    printf("1. Hitung Jumlah elemen List1\n");
                    printf("2. Hitung Jumlah elemen List2\n");
                    printf("3. Kembali\n");
                    printf("=====================================\n");
                    printf("Pilih opsi (1-3): ");
                    
                    if (scanf("%d", &subMenuChoice) != 1) {
                        printf("Input tidak valid. Silakan coba lagi.\n");
                        while(getchar() != '\n'); // Clear the buffer
                        continue;
                    }

                    switch (subMenuChoice) {
                        case 1:
                            system("cls");
                            printf("Jumlah elemen List1: %d\n", HitungElemen(&list1)); // Fungsi hitung jumlah
                            getchar(); getchar();
							break;
                        case 2:
                            system("cls");
                            printf("Jumlah elemen List2: %d\n", HitungElemen(&list2)); // Fungsi hitung jumlah
                            getchar(); getchar();
							break;
                        case 3:
                            break; // Kembali ke menu utama
                        default:
                            printf("Pilihan tidak valid.\n");
                            break;
                    }
                    if (subMenuChoice == 3) {
                    	break;
					}
                }
                break;
            }

            case 4:
                system("cls");
                DuplikasiList(&list1, &list2);
                printf("Berhasil copy elemen list L1 ke list L2\n");
                Sleep(1000);
                break;

            case 5:
                system("cls");
                HapusDuplikatNama(&list2);
                printf("Nama duplikat berhasil dihapus\n");
                Sleep(1000);
                break;

            case 6:
                system("cls");
                destroyList(&list1);
                destroyList(&list2);
                printf("List L1 dan L2 berhasil dihapus\n");
                Sleep(1000); // Tunggu 1 detik
                break;

            case 7:
                system("cls");
                printf("Keluar dari program...\n");
                return; // Keluar dari menu
                break;

            default:
                printf("Pilihan tidak valid. Silakan pilih antara 1-7.\n");
        }
    }
}

