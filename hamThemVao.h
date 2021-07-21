#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
struct nodeXe
{
    string dongXe;
    string hangXe;
    string loi;
    string maSo;
    nodeXe *xeTiepTheo;
};

struct thongKe
{
    string hangXe;
    string loi;
    int soLuong;
};
nodeXe *taoMotNodeMoi(string s);
void docDuLieu(nodeXe *&head);
void thongKeXe(nodeXe *head, vector<thongKe> &res);
void ghiFile(vector<thongKe> res);