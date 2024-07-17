#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Struktur node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk memasukkan node baru di awal linked list
void masukkan(Node** head, int data) {
    Node* node_baru = new Node();
    node_baru->data = data;
    node_baru->next = *head;
    *head = node_baru;
}

// Fungsi untuk melakukan insertion sort pada linked list
void insertionSort(Node** head) {
    Node* sorted = nullptr; // Inisialisasi linked list yang sudah diurutkan
    Node* current = *head; // Menelusuri linked list yang diberikan

    while (current != nullptr) {
        Node* next = current->next; // Menyimpan node berikutnya

        // Menyisipkan node saat ini ke dalam linked list yang diurutkan
        Node* temp = sorted;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data < current->data) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == nullptr) {
            current->next = sorted;
            sorted = current;
        } else {
            prev->next = current;
            current->next = temp;
        }

        current = next; // Pindah ke node berikutnya
    }

    *head = sorted; // Memperbarui head untuk menunjuk ke linked list yang sudah diurutkan
}

// Fungsi untuk mencetak linked list
void cetakList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Fungsi untuk memeriksa apakah tebakan benar
bool cekTebakan(Node* head, int tebakan) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == tebakan) {
            return true; // Tebakan benar
        }
        temp = temp->next;
    }
    return false; // Tebakan salah
}

// Fungsi utama
int main() {
    Node* head = nullptr; // Inisialisasi linked list kosong
    int tebakan;
    int angka[10];
    srand(time(0));

    // Menghasilkan angka acak dan memasukkan ke dalam linked list
    for (int i = 0; i < 10; i++) {
        angka[i] = rand() % 100 + 1;
        masukkan(&head, angka[i]);
    }

    cout << "Selamat datang di Permainan Tebak Angka!" << endl;
    cout << "Cobalah untuk menebak salah satu angka di dalam daftar." << endl;

    while (true) {
        cout << "Masukkan tebakan Anda (0 untuk keluar): ";
        cin >> tebakan;

        if (tebakan == 0) {
            break; // Keluar dari permainan
        }

        if (cekTebakan(head, tebakan)) {
            cout << "Selamat! Tebakan Anda benar." << endl;
        } else {
            cout << "Maaf, tebakan Anda salah. Coba lagi." << endl;
        }

        // Mengurutkan linked list dan mencetaknya
        insertionSort(&head);
        cout << "Angka yang sudah diurutkan: ";
        cetakList(head);
    }

    return 0;
}
