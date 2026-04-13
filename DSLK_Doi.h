#ifndef DSLK_DOI_H
#define DSLK_DOI_H

#include "HoaDon.h"
#include <string>
using namespace std;

struct NodeHoaDon {
    HoaDon data;
    NodeHoaDon* prev;
    NodeHoaDon* next;
};

class DSLK_Doi {
private:
    NodeHoaDon* head; 
    NodeHoaDon* tail; 

public:
    void init(); 
  
    void themDau(const HoaDon& hd);

    void themCuoi(const HoaDon& hd);

    void inDanhSach();

    void xoaNode(const string& maHD);

    void suaNode(const string& maHD);

    NodeHoaDon* timTheoMa(const string& maHD);

    void luuFile(const string& filename);

    void docFile(const string& filename);
};

#endif
