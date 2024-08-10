#include <iostream>
using namespace std;

struct DataUser {
    string nama, user, email, pass;
    double tagihan; 
    DataUser *prev;
    DataUser *next;
};

DataUser *kepala = NULL, *ekor = NULL, *cur = NULL, *nodeBaru = NULL, *nodeHapus = NULL;

void tambahAwal(string nama, string user, string email, string pass, double tagihan) {
    nodeBaru = new DataUser();
    nodeBaru->nama = nama;
    nodeBaru->user = user;
    nodeBaru->email = email;
    nodeBaru->pass = pass;
    nodeBaru->tagihan = tagihan;
    nodeBaru->prev = NULL;
    nodeBaru->next = kepala;
    if (kepala != NULL) {
        kepala->prev = nodeBaru;
    }
    kepala = nodeBaru;
    if (ekor == NULL) {
        ekor = kepala;
    }
}

void tambahTengah(string nama, string user, string email, string pass, double tagihan) {
    if (kepala == NULL) {
        tambahAwal(nama, user, email, pass, tagihan);
        return;
    }

    nodeBaru = new DataUser();
    nodeBaru->nama = nama;
    nodeBaru->user = user;
    nodeBaru->email = email;
    nodeBaru->pass = pass;
    nodeBaru->tagihan = tagihan;

    DataUser *cur = kepala;
    DataUser *itu = kepala;

    while (itu != NULL && itu->next != NULL) {
        cur = cur->next;
        itu = itu->next->next;
    }

    nodeBaru->next = cur;
    nodeBaru->prev = cur->prev;
    if (cur->prev != NULL) {
        cur->prev->next = nodeBaru;
    }
    cur->prev = nodeBaru;
    if (cur == kepala) {
        kepala = nodeBaru;
    }
}

void tambahAkhir(string nama, string user, string email, string pass, double tagihan) {
    nodeBaru = new DataUser();
    nodeBaru->nama = nama;
    nodeBaru->user = user;
    nodeBaru->email = email;
    nodeBaru->pass = pass;
    nodeBaru->tagihan = tagihan;
    nodeBaru->next = NULL;
    nodeBaru->prev = ekor;
    if (ekor != NULL) {
        ekor->next = nodeBaru;
    }
    ekor = nodeBaru;
    if (kepala == NULL) {
        kepala = ekor;
    }
}

void ubahAwal(string nama, string user, string email, string pass, double tagihan) {
    if (kepala != NULL) {
        kepala->nama = nama;
        kepala->user = user;
        kepala->email = email;
        kepala->pass = pass;
        kepala->tagihan = tagihan;
    } else {
        cout << "Linkedlist kosong, tidak bisa mengubah elemen pertama!" << endl;
    }
}

void ubahAkhir(string nama, string user, string email, string pass, double tagihan) {
    if (ekor != NULL) {
        ekor->nama = nama;
        ekor->user = user;
        ekor->email = email;
        ekor->pass = pass;
        ekor->tagihan = tagihan;
    } else {
        cout << "Linkedlist kosong, tidak bisa mengubah elemen terakhir!" << endl;
    }
}

void ubahTengah(string nama, string user, string email, string pass, double tagihan) {
    if (kepala == NULL) {
        cout << "Linkedlist kosong, tidak ada elemen tengah!" << endl;
        return;
    }
    DataUser *cur = kepala;
    DataUser *itu = kepala;
    while (itu != NULL && itu->next != NULL) {
        cur = cur->next;
        itu = itu->next->next;
    }
    cur->nama = nama;
    cur->user = user;
    cur->email = email;
    cur->pass = pass;
    cur->tagihan = tagihan;
}

int hitungLinkedlist() {
    cur = kepala;
    int jumlah = 0;
    while (cur != NULL) {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void cetakLinkedlist() {
    cout << "Jumlah elemen: " << hitungLinkedlist() << endl;
    cur = kepala;
    while (cur != NULL) {
        cout << "Nama: " << cur->nama << endl;
        cout << "User: " << cur->user << endl;
        cout << "Email: " << cur->email << endl;
        cout << "Pass: " << cur->pass << endl;
        cout << "Tagihan: " << cur->tagihan << endl;
        cout << "\n" << endl;
        cur = cur->next;
    }
}

void hapusAwal() {
    if (kepala != NULL) {
        nodeHapus = kepala;
        kepala = kepala->next;
        if (kepala != NULL) {
            kepala->prev = NULL;
        } else {
            ekor = NULL;
        }
        delete nodeHapus;
    } else {
        cout << "Linkedlist kosong, tidak bisa menghapus elemen pertama!" << endl;
    }
}

void hapusTengah() {
    if (cur!= NULL) {
        nodeHapus = kepala;
        cur= kepala->next;
        if (cur!= NULL) {
            kepala->prev = NULL;
        } else {
            ekor = NULL;
        }
        delete nodeHapus;
    } else {
        cout << "Linkedlist kosong, tidak bisa menghapus elemen pertama!" << endl;
    }
}

void hapusAkhir() {
    if (ekor != NULL) {
        nodeHapus = ekor;
        ekor = ekor->prev;
        if (ekor != NULL) {
            ekor->next = NULL;
        } else {
            cur= NULL;
        }
        delete nodeHapus;
    } else {
        cout << "Linkedlist kosong, tidak bisa menghapus elemen terakhir!" << endl;
    }
}

void hapusNode(string nama) {
    
    if (kepala == NULL) {
        cout << "Linkedlist kosong, tidak ada node yang dihapus!" << endl;
        return;
    }

    if (kepala->nama == nama) {
        hapusAwal();
        cout << "Node dengan nama " << nama << " berhasil dihapus!" << endl;
        return;
    }

    DataUser *temp = kepala;
    while (temp != NULL && temp->nama != nama) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node dengan nama " << nama << " tidak ditemukan dalam linked list!" << endl;
        return;
    }

    if (temp->next == NULL) {
        hapusAkhir();
        cout << "Node dengan nama " << nama << " berhasil dihapus!" << endl;
        return;
    }

   
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    cout << "Node dengan nama " << nama << " berhasil dihapus!" << endl;
}

int main() {
    tambahAwal("Yanto Kopling", "Yanto", "kopling@gmail.com", "GasBanterAe", 1500);
    tambahTengah("Raden Werkudoro", "Werkudoro", "Werkudoro@gmail.com", "GodoSakti", 3500);
    tambahAkhir("Cemek Keling", "Cemek", "keling@gmail.com", "ManganAe", 2000);
    
    // cetakLinkedlist();
    // cout << "\n";

    // ubahAwal("Uden Nganga", "Uden", "nganga@gmail.com", "KesuenMangap", 2500);
    // ubahTengah("Raden Arjuno", "Arjuno", "Arjuno@gmail.com", "PanahArjuno", 3000);
    // ubahAkhir("Raden Ontoseno", "Ontoseno", "Ontoseno@gmail.com", "OntosenoRojo", 1000);

    // hapusAwal();
    // cout << "\n";

    //  hapusTengah();
    // hapusAkhir();
    // hapusNode("Raden Werkudoro", "Werkudoro", "Werkudoro@gmail.com", "GodoSakti", 3500);
    // cout << "\n"
    cetakLinkedlist();


    return 0;
}
