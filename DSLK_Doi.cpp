#include "DSLK_Doi.h"
#include <iostream>
#include <fstream>
using namespace std;

void DSLK_Doi::init() {
    head = nullptr;
    tail = nullptr;
}

void DSLK_Doi::themDau(const HoaDon& hd) {
    NodeHoaDon* p = new NodeHoaDon;
    p->data = hd;
    p->prev = nullptr;
    p->next = head;

    if (head == nullptr) {
        head = tail = p;
    } else {
        head->prev = p;
        head = p;
    }
}

void DSLK_Doi::themCuoi(const HoaDon& hd) {
    NodeHoaDon* p = new NodeHoaDon;
    p->data = hd;
    p->next = nullptr;
    p->prev = tail;

    if (tail == nullptr) {
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
}

void DSLK_Doi::inDanhSach() {
    if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    }

    NodeHoaDon* p = head;
    while (p != nullptr) {
        cout << "Ma HD: " << p->data.maHD << endl;
        cout << "Ma SV: " << p->data.maSV << endl;
        cout << "Ngay lap: " << p->data.ngayLap << endl;
        cout << "So tien: " << p->data.soTien << endl;
        cout << "--------------------------\n";
        p = p->next;
    }
}

NodeHoaDon* DSLK_Doi::timTheoMa(const string& maHD) {
    NodeHoaDon* p = head;
    while (p != nullptr) {
        if (p->data.maHD == maHD) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void DSLK_Doi::xoaNode(const string& maHD) {
    NodeHoaDon* p = timTheoMa(maHD);

    if (p == nullptr) {
        cout << "Khong tim thay hoa don co ma " << maHD << endl;
        return;
    }


    if (p == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
    }
  
    else if (p == tail) {
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
    }
    
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    delete p;
    cout << "Da xoa hoa don co ma " << maHD << endl;
}

void DSLK_Doi::suaNode(const string& maHD) {
    NodeHoaDon* p = timTheoMa(maHD);

    if (p == nullptr) {
        cout << "Khong tim thay hoa don co ma " << maHD << endl;
        return;
    }

    cout << "Nhap lai thong tin hoa don:\n";
    cout << "Nhap ma SV moi: ";
    cin >> p->data.maSV;
    cout << "Nhap ngay lap moi: ";
    cin >> p->data.ngayLap;
    cout << "Nhap so tien moi: ";
    cin >> p->data.soTien;

    cout << "Da cap nhat hoa don co ma " << maHD << endl;
}

void DSLK_Doi::luuFile(const string& filename) {
    ofstream fout(filename);

    if (!fout) {
        cout << "Khong mo duoc file de ghi!\n";
        return;
    }

    NodeHoaDon* p = head;
    while (p != nullptr) {
        fout << p->data.maHD << endl;
        fout << p->data.maSV << endl;
        fout << p->data.ngayLap << endl;
        fout << p->data.soTien << endl;
        p = p->next;
    }

    fout.close();
    cout << "Da luu danh sach vao file " << filename << endl;
}

void DSLK_Doi::docFile(const string& filename) {
    ifstream fin(filename);

    if (!fin) {
        cout << "Khong mo duoc file de doc!\n";
        return;
    }

    init(); 

    HoaDon hd;
    while (getline(fin, hd.maHD)) {
        getline(fin, hd.maSV);
        getline(fin, hd.ngayLap);
        fin >> hd.soTien;
        fin.ignore();

        hd.prev = nullptr;
        hd.next = nullptr;

        themCuoi(hd);
    }

    fin.close();
    cout << "Da doc danh sach tu file " << filename << endl;
}
