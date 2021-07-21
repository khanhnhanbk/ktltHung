#include "hamThemVao.h"
nodeXe *taoMotNodeMoi(string s)
{
    if (count(s.begin(), s.end(), ';') != 3)
        return nullptr;
    nodeXe *node = new nodeXe;
    node->xeTiepTheo = nullptr;
    int pos = 0;
    int prePos = s.find(';');
    node->dongXe = s.substr(pos, prePos - pos);
    pos = prePos + 1;
    prePos = s.find(';', pos);
    node->hangXe = s.substr(pos, prePos - pos);
    pos = prePos + 1;
    prePos = s.find(';', pos);
    node->loi = s.substr(pos, prePos - pos);
    pos = prePos + 1;
    prePos = s.length();
    node->maSo = s.substr(pos, prePos - pos);
    return node;
}

void docDuLieu(nodeXe *&head)
{
    string s;
    head = nullptr;
    ifstream ifs("VehicleError.txt");
    if (ifs.is_open())
    {
        nodeXe *cur;
        while (not ifs.eof())
        {
            getline(ifs, s);
            if (!head)
            {
                head = taoMotNodeMoi(s);
                cur = head;
            }
            else
            {
                if (cur)
                {
                    cur->xeTiepTheo = taoMotNodeMoi(s);
                    cur = cur->xeTiepTheo;
                }
            }
        }
        ifs.close();
    }
}
void thongKeXe(nodeXe *head, vector<thongKe> &res)
{
    if (head == nullptr)
        return;
    bool daCoTrongDanhSach = false;
    for (int i = 0; i < res.size(); i++)
    {
        if (head->hangXe == res[i].hangXe && head->loi == res[i].loi)
        {
            daCoTrongDanhSach = true;
            res[i].soLuong++;
            break;
        }
    }
    if (!daCoTrongDanhSach)
    {
        thongKe moi;
        moi.hangXe = head->hangXe;
        moi.loi = head->loi;
        moi.soLuong = 1;
        res.push_back(moi);
    }
    thongKeXe(head->xeTiepTheo, res);
}
void ghiFile(vector<thongKe> res)
{
    ofstream ofs("Report.txt");
    if (ofs.is_open())
    {
        for (int i = 0; i < res.size(); i++)
        {
            ofs << res[i].hangXe << ": " << res[i].loi << ": " << res[i].soLuong << '\n';
        }
        ofs.close();
    }
}