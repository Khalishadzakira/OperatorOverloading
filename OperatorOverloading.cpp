#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//void etc
void dataPersegiPanjang();
void tambahPersegiPanjang();
void OPplus(float xmin1, float xmin2, float xmax1, float xmax2, float ymin1, float ymin2, float ymax1, float ymax2, int idx1, int idx2);
void OPmin(float xmin1, float xmin2, float xmax1, float xmax2, float ymin1, float ymin2, float ymax1, float ymax2, int idx1, int idx2);
void OPdouble(float xmin, float xmax, float ymin, float ymax, float idx);
void OPhalf(float xmin, float xmax, float ymin, float ymax, float idx);
void OPproperti();
bool TestIrisan(double xmax1, double xmax2, double xmin1, double xmin2, double yamx1, double ymax2, double ymin1, double ymin2);

int PP1, PP2, sidx, fidx;

class PersegiPanjang
{
public:
    double xmin, xmax, ymin, ymax, xteng, yteng, panjang, lebar, luas;

    PersegiPanjang(double XMIN, double XMAX, double YMIN, double YMAX)
    {
        xmin = XMIN;
        xmax = XMAX;
        ymin = YMIN;
        ymax = YMAX;
        xteng = (XMAX - XMIN)/2;
        yteng = (YMAX - YMIN)/2;
        panjang = fabs(XMAX-XMIN);
        lebar = fabs(YMAX-YMIN);
        luas = panjang*lebar;
    }

    void operator+ (PersegiPanjang& PersegiPanjang)
    {
        OPplus(xmin, PersegiPanjang.xmin, xmax, PersegiPanjang.xmax, ymin, PersegiPanjang.ymin, ymax, PersegiPanjang.ymax, fidx, sidx);
    };

    void operator- (PersegiPanjang& PersegiPanjang)
    {
        OPmin(xmin, PersegiPanjang.xmin, xmax, PersegiPanjang.xmax, ymin, PersegiPanjang.ymin, ymax, PersegiPanjang.ymax, fidx, sidx);
    };

    void operator++ ()
    {
        OPdouble(xmin, xmax, ymin, ymax, fidx);
    };

    void operator-- ()
    {
        OPhalf(xmin, xmax, ymin, ymax, fidx);
    };

    void operator[] (PersegiPanjang& PersegiPanjang)
    {
        OPproperti();
    };

    bool operator== (PersegiPanjang& PersegiPanjang)
    {
        return TestIrisan(xmin, xmax, PersegiPanjang.xmin, PersegiPanjang.xmax, ymin, ymax, PersegiPanjang.ymin, PersegiPanjang.ymax);
    };
};

vector<PersegiPanjang> vecPersegiPanjang;

// main menu
int main ()
{
    int mainmenu;

    menu:
    cout << " " << endl;
    cout << "======================================" << endl;
    cout << "OPERATOR OVERLOADING : PERSEGI PANJANG" << endl;
    cout << "======================================" << endl;
    cout << " " << endl;
    cout << "pilihlah salah satu menu dibawah ini :" << endl;
    cout << "(1) tambah data persegi panjang" << endl;
    cout << "(2) data persegi panjang" << endl;
    cout << "(3) operator+  : penggabungan dua persegi panjang" << endl;
    cout << "(4) operator-  : irisan dua persegi panjang" << endl;
    cout << "(5) operator++ : menambah luasan persegi panjang menjadi dua kali lilipat" << endl;
    cout << "(6) operator-- : mengurangi luasan persegi panjang menjadi setengah" << endl;
    cout << "(7) operator[] : data properti persegi panjang" << endl;
    cout << "(8) operator== : periksa apakah dua persegi panjang beririsan" << endl;
    cout << "(0) tutup program" << endl;
    cout << " " << endl;
    cout << "pilihan menu: ";
    cin >> mainmenu;
    cout << endl;

    switch (mainmenu)
    {
        case 0:
            cout << "=======================================" << endl;
            cout << "terima kasih telah menggunakan program!" << endl;
            cout << "=======================================" << endl;
            cout << " " << endl;
            return 0;
            break;

        case 1: //tambah pp
            tambahPersegiPanjang();
            cout << endl;
            goto menu;
            break;
        
        case 2: //data pp
            if (vecPersegiPanjang.empty() == true)
            {
                cout << "masukkan data persegi panjang terlebih dahulu" << endl;
            } 
            else {dataPersegiPanjang();}
            cout << endl;
            goto menu;
            break;

        case 3: //gabung pp
            if (vecPersegiPanjang.size() < 2)
            {   
                cout << "data persegi panjang yang dibutuhkan masih kurang" << endl;
            }else
            {
                cout << "persegi ke-... dari data keseluruhan : ";
                cin >> PP1;
                cout << "persegi ke-... dari data keseluruhan : ";
                cin >> PP2;

                fidx = PP1 - 1;
                sidx = PP2 - 1;

                if (vecPersegiPanjang[fidx] == vecPersegiPanjang[sidx]){
                vecPersegiPanjang[fidx] + vecPersegiPanjang[sidx];
                } else {
                    cout << endl;
                    cout << "persegi panjang tidak beririsan" << endl;
                };
            }
            cout << endl;
            goto menu;
            break;

        case 4: //irisan pp
            if (vecPersegiPanjang.size() < 2)
            {
                cout << "data persegi panjang yang dibutuhkan masih kurang" << endl;
            }else
            {
                cout << "persegi ke-... dari data keseluruhan : ";
                cin >> PP1;
                cout << "persegi ke-... dari data keseluruhan : ";
                cin >> PP2;

                fidx = PP1 - 1;
                sidx = PP2 - 1;

                if (vecPersegiPanjang[fidx] == vecPersegiPanjang[sidx]){
                    vecPersegiPanjang[fidx] + vecPersegiPanjang[sidx];
                } else {
                    cout << endl;
                    cout << "persegi panjang tidak beririsan" << endl;
                };
            }
            cout << endl;
            goto menu;
            break;

        case 5: //double pp
            cout << "persegi ke-... dari data keseluruhan : ";
            cin >> PP1;
            
            fidx = PP1 - 1;
            
            ++vecPersegiPanjang[fidx];

            cout << endl;
            goto menu;
            break;

        case 6: //setengah pp
            cout << "persegi ke-... dari data keseluruhan : ";
            cin >> PP1;
            
            fidx = PP1 - 1;
            
            --vecPersegiPanjang[fidx];

            cout << endl;
            goto menu;
            break;
        
        case 7: //properti pp
            if (vecPersegiPanjang.empty() == true)
            {
                cout << "masukkan data persegi panjang terlebih dahulu" << endl;
            } 
            else {OPproperti();}
            cout << endl;
            goto menu;
            break;

        case 8: //test irisan
            if (vecPersegiPanjang.size() < 2)
            {
                cout << "data persegi panjang yang dibutuhkan masih kurang" << endl;
            } else
            {
                cout << "persegi ke-... dari data keseluruhan : ";
                    cin >> PP1;
                    cout << "persegi ke-... dari data keseluruhan : ";
                    cin >> PP2;

                    fidx = PP1 - 1;
                    sidx = PP2 - 1;

                    cout << endl;
                    if (vecPersegiPanjang[fidx] == vecPersegiPanjang[sidx])
                    {
                        cout << "kedua persegi panjang beririsan!" << endl;
                    }
                    else 
                    {
                        cout << "kedua persegi panjang TIDAK beririsan!" << endl;
                    };
            }

            cout << endl;
            goto menu;
            break;

        default:
            cout << "error!" << endl;
            goto menu;
            break;
    };
};

//tambah persegi
void tambahPersegiPanjang()
{
    float xmin, xmax, ymin, ymax;
    tambahpp:
    cout << "===============================" << endl;
    cout << "PENAMBAHAN DATA PERSEGI PANJANG" << endl;
    cout << "===============================" << endl;
    cout << "x-min persegi panjang : ";
    cin >> xmin;
    cout << "x-max persegi panjang : ";
    cin >> xmax;
    cout << "y-min persegi panjang : ";
    cin >> ymin;
    cout << "y-max persegi panjang : ";
    cin >> ymax;

    if (xmax < xmin){swap(xmin, xmax);};
    if (ymax < ymin){swap(ymin,ymax);};
    if (xmax == xmin){cout << "invalid data!" << endl; goto tambahpp;};
    if (ymax == ymin){cout << "invalid data!" << endl; goto tambahpp;};

    PersegiPanjang newPersegiPanjang(xmin, xmax, ymin, ymax);
    vecPersegiPanjang.push_back(newPersegiPanjang);

    cout << " " << endl;
    cout << "persegi panjang telah tersimpan pada data" << endl;
};

//data persegi
void dataPersegiPanjang()
{
    cout << "====================" << endl;
    cout << "DATA PERSEGI PANJANG" << endl;
    cout << "====================" << endl;
    cout << "  " << endl;
    for (long unsigned int i = 0; i < vecPersegiPanjang.size(); i++){
        cout << "data persegi panjang ke-" << i+1 << ": " << endl;
        cout << "x-min	    : " << vecPersegiPanjang[i].xmin << endl;
        cout << "x-max	    : " << vecPersegiPanjang[i].xmax << endl;
        cout << "y-min	    : " << vecPersegiPanjang[i].ymin << endl;
        cout << "y-max	    : " << vecPersegiPanjang[i].ymax << endl;
        cout << "y-tengah    : " << vecPersegiPanjang[i].yteng << endl;
        cout << "x-tengah    : " << vecPersegiPanjang[i].xteng << endl;
        cout << "panjang     : " << vecPersegiPanjang[i].panjang << endl;
        cout << "lebar       : " << vecPersegiPanjang[i].lebar << endl;
        cout << "luas        : " << vecPersegiPanjang[i].luas << endl;
        cout << endl;
    }
    cout << endl;
};

//gabung persegi
void OPplus(float xmin1, float xmin2, float xmax1, float xmax2, float ymin1, float ymin2, float ymax1, float ymax2, int idx1, int idx2)
{
    float kiri, kanan, bawah, atas;

    if (xmin1 <= xmin2)
    {
        kiri = xmin1;
    } 
    else if (xmin1 >= xmin2)
    {
        kiri = xmin2;
    }

    if (xmax1 <= xmax2)
    {
        kanan = xmax2;
    }
    else if (xmax1 >= xmax2)
    {
        kanan = xmax1;
    }

    if (ymin1 <= ymin2)
    {
        bawah = ymin1;
    }
    else if (ymin1 >= ymin2)
    {
        bawah = ymin2;
    }

    if (ymax1 <= ymax2)
    {
        atas = ymax2;
    }
    else if (ymax1 >= ymax2)
    {
        atas = ymax1;
    }

    PersegiPanjang replacePersegiPanjang(kiri, kanan, bawah, atas);
    vecPersegiPanjang[idx1] = replacePersegiPanjang;
    vecPersegiPanjang.erase(vecPersegiPanjang.begin()+idx2);

    cout << "persegi telah digabungkan dan telah tersimpan pada data" << endl;
}

//irisan persegi
void OPmin(float xmin1, float xmin2, float xmax1, float xmax2, float ymin1, float ymin2, float ymax1, float ymax2, int idx1, int idx2)
{
    float kiri, kanan, atas, bawah;

    if (xmin2 > xmin1 and xmin2 < xmax1)
    {
        kiri = xmin2;
        kanan = xmax1;
    }
    else if (xmin1 > xmin2 and xmin1 < xmax2)
    {
        kiri = xmin1;
        kanan = xmax2;
    }

    if (ymin2 > ymin1 and ymin2 < ymax1)
    {
        bawah = ymin2;
        atas = ymax1;
    }
    else if (ymin1 > ymin2 and ymin1 < ymax2)
    {
        bawah = ymin1;
        atas = ymax2;
    }

    PersegiPanjang replacePersegiPanjang(kiri, kanan, bawah, atas);
    vecPersegiPanjang[idx1] = replacePersegiPanjang;
    vecPersegiPanjang.erase(vecPersegiPanjang.begin()+idx2);

    cout << "persegi telah diiriskan dan telah tersimpan pada data" << endl;
};

//double persegi
void OPdouble(float xmin, float xmax, float ymin, float ymax, float idx)
{
    xmax = ((xmax-xmin) * sqrt(2)) + xmin;
    ymax = ((ymax-ymin) * sqrt(2)) + ymin;

    PersegiPanjang replacePersegiPanjang(xmin, xmax, ymin, ymax);
    vecPersegiPanjang[idx] = replacePersegiPanjang;

    cout << "luas persegi telah dikali dua dan telah tersimpan pada data" << endl;    
};

//bagi persegi
void OPhalf(float xmin, float xmax, float ymin, float ymax, float idx)
{
    xmax = ((xmax-xmin) / sqrt(2)) + xmin;
    ymax = ((ymax-ymin) / sqrt(2)) + ymin;

    PersegiPanjang replacePersegiPanjang(xmin, xmax, ymin, ymax);
    vecPersegiPanjang[idx] = replacePersegiPanjang;

    cout << "luas persegi telah dibagi dua dan telah tersimpan pada data" << endl;     
};

//properti
void OPproperti()
{
    cout << "========================" << endl;
    cout << "PROPERTI PERSEGI PANJANG" << endl;
    cout << "========================" << endl;
    cout << "  " << endl;
    for (long unsigned int i = 0; i < vecPersegiPanjang.size(); i++){
        cout << "properti persegi panjang ke-" << i+1 << ": " << endl;
        cout << "x-min	    : " << vecPersegiPanjang[i].xmin << endl;
        cout << "x-max	    : " << vecPersegiPanjang[i].xmax << endl;
        cout << "y-min	    : " << vecPersegiPanjang[i].ymin << endl;
        cout << "y-max	    : " << vecPersegiPanjang[i].ymax << endl;
        cout << endl;
    }
    cout << endl;
}

//testing irisan
bool TestIrisan(double xmax1, double xmax2, double xmin1, double xmin2, double ymax1, double ymax2, double ymin1, double ymin2)
{
    bool xsinggung;
    bool ysinggung;

    if(((xmax1 < xmax2 and xmax1>xmin2) or (xmin2 < xmax1 and xmin2 > xmin1) or (xmin1 > xmin2 and xmin1 < xmax2) or (xmax2 < xmax1 and xmax2 > xmin1)))
    {
        xsinggung = true;

    }else{xsinggung = false;};

    if(((ymax1 < ymax2 and ymax1>ymin2) or (ymin2 < ymax1 and ymin2 > ymin1) or (ymin1 > ymin2 and ymin1 < ymax2) or (ymax2 < ymax1 and ymax2 > ymin1)))
    {
        ysinggung = true;

    }else{ysinggung = false;};

    if (xsinggung == true and ysinggung == true)
    {
        return true;

    }else{return false;};
};
