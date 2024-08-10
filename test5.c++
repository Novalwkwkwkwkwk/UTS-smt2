#include <iostream>
#include <string>
using namespace std;

struct Tagihan {
    string nama, nomor;
    double jumlah;
    Tagihan* next;
};

Tagihan* kepala,* ekor,* newNode,* cur, *dataBaru,* del;

void buatCircularSinglelist(string dataBaru[3]) {
    Tagihan* newNode = new Tagihan();
    newNode->nama = dataBaru[0];
    newNode->nomor = dataBaru[1];
    newNode->jumlah = stod(dataBaru[2]);
    newNode->next = newNode;
    kepala = newNode;
    ekor = newNode;
}

void tambahAwal(string dataBaru[3]) {
    Tagihan* nodeBaru = new Tagihan();
    nodeBaru->nama = dataBaru[0];
    nodeBaru->nomor = dataBaru[1];
    nodeBaru->jumlah = stod(dataBaru[2]);
    nodeBaru->next = kepala;
    ekor->next = nodeBaru;
    kepala = nodeBaru;
}

void tambahTengah(string dataBaru[3]) {
    if (kepala == NULL) {
        buatCircularSinglelist(dataBaru);
        return;
    }
    Tagihan* nodeBaru = new Tagihan();
    nodeBaru->nama = dataBaru[0];
    nodeBaru->nomor = dataBaru[1];
    nodeBaru->jumlah = stod(dataBaru[2]);

    Tagihan*cur = kepala;
    Tagihan* itu = kepala;
    while (itu->next != kepala && itu->next->next != kepala) {
       cur =cur->next;
        itu = itu->next->next;
    }

    nodeBaru->next =cur->next;
   cur->next = nodeBaru;
}

void tambahAkhir(string dataBaru[3]) {
    if (kepala == NULL) {
        buatCircularSinglelist(dataBaru);
        return;
    }
    Tagihan* nodeBaru = new Tagihan();
    nodeBaru->nama = dataBaru[0];
    nodeBaru->nomor = dataBaru[1];
    nodeBaru->jumlah = stod(dataBaru[2]);
    nodeBaru->next = kepala;
    ekor->next = nodeBaru;
    ekor = nodeBaru;
}

void hapusAwal() {
    if (kepala == NULL) return;

    if (kepala == ekor) {
        delete kepala;
        kepala = NULL;
        ekor = NULL;
    } else {
        Tagihan* del = kepala;
        kepala = kepala->next;
        ekor->next = kepala;
        delete del;
    }
}

void hapusTengah() {
    if (kepala == NULL || kepala == ekor) return;

    Tagihan* slow = kepala;
    Tagihan* fast = kepala;
    Tagihan* prev = NULL;

    while (fast->next != kepala && fast->next->next != kepala) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) {
        prev->next = slow->next;
        delete slow;
    }
}

void hapusAkhir() {
    if (kepala == NULL) return;

    if (kepala == ekor) {
        delete kepala;
        kepala = NULL;
        ekor = NULL;
    } else {
        Tagihan* del = kepala;
        while (del->next != ekor) {
            del = del->next;
        }
        del->next = kepala;
        delete ekor;
        ekor = del;
    }
}


void cetakCircularSingle() {
    cout << "Data Tagihan" << endl;
    cout << " -------------------------------------------------------" << endl;
    cout << "| Nama\t\t\t| Nomor\t\t| Tagihan\t|" << endl;
    cout << " -------------------------------------------------------" << endl;
    if (kepala == NULL) {
        cout << "List kosong." << endl;
        return;
    }
    Tagihan* cur = kepala;
    do {
        cout << "| " << cur->nama << "\t\t| " << cur->nomor << "\t\t| " << cur->jumlah << "\t\t|" << endl;
        cur = cur->next;
         cout << "\n" << endl;
    } while (cur != kepala);
}

int main() {
    string dataBaru1[3] = {"Rahwana", "01", "2000"};
    buatCircularSinglelist(dataBaru1);

    string dataBaru2[3] = {"Buto Cakil", "02", "2500"};
    tambahAwal(dataBaru2);

     string dataBaru4[3] = {"Gatotkaca", "03", "3500"}; 
    tambahTengah(dataBaru4);

    string dataBaru3[3] = {"Ontoseno", "04", "3000"}; 
    tambahAkhir(dataBaru3);

    hapusAwal();
    cout << "\nSetelah hapus awal:" << endl;
    

    cetakCircularSingle();
    return 0;
}
