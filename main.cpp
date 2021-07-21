#include "hamThemVao.h"
int main()
{
    nodeXe *head;
    docDuLieu(head);
    vector<thongKe> res;
    res.resize(0);
    thongKeXe(head, res);
    ghiFile(res);
    return 0;
}