#include<iostream>
#include<vector> 
#include<fstream> 
#include"testting 3.h"


using namespace std ; 
vector<vector<float> > luong_mua ; 
vector<int> year; 
int main ( )
{ 
    string file_name = "list.dat";
    LoadFile(file_name, year, luong_mua);
    int choose; 
    do
    { 
        cout << endl; 
        cout << " #### CHAO MUNG BAN DEN VOI CHUONG TRING QUAN LI LUONG MUA ####"<< endl; 
        cout << "      ##################################################      "<< endl; 
        cout << "                 ****    MUC LUC    ****                      "<< endl;
        cout << "             1. NHAP VAO THONG TIN LUONG MUA                  "<< endl; 
        cout << "             2. TIM KIEM THONG TIN LUONG MUA                  "<< endl; 
        cout << "             3. THOAT CHUONG TRINH                            "<< endl; 
        cout << "      ##################################################      "<< endl; 
        cout << "$ Luu y : Ngoai cac chuc nang tren thi khong con chuc nang khac $" << endl; 
        cout << "$ mong nguoi dung khong nhap sai chuc nang. Voi bat ki han dong $" << endl; 
        cout << "$ vo tinh hay co y. Chuong trinh se to dong tro ve menu chinh   $" << endl; 
        cout << "!!!!!!      Hay can nhac truoc khi dua ra quyet dinh       !!!!!!" << endl; 
        cout << endl ; 
        cout << "MOI BAN NHAP CHUC NANG : " ; 
        cin >> choose; 
        cout << endl;
        if ( choose == 1 ) 
        { 
           cout << "####        THONG BAO: BAN DA LUA CHON CHUC NANG 1        ####" << endl; 
           // INPUTDATA(map<int, int> quanli)
           NhapDuLieu(luong_mua, year) ; 
        }
        if ( choose == 2 ) 
        { 
           cout << "####        THONG BAO: BAN DA LUA CHON CHUC NANG 2        ####" << endl; 
           InRaDuLieu(luong_mua, year) ; 
        }
        if ( choose !=1 && choose != 2 && choose != 3 || choose <= 0 || typeid(choose) != typeid(int)) 
        { 
            int c = 0 ; 
            cout << endl; 
            cout << "!!!!!!!!     ERROR: CHUC NANG NAY KHONG TON TAI        !!!!!!!" << endl; 
            cout << "      ??? BAN CO MUON TIEP TUC SU SUNG CHUONG TRINH ???       " << endl; 
            cout << "                1. TIEP TUC CHUONG TRINH                      " << endl; 
            cout << "                2. THOAT CHUONG TRINH                         " << endl; 
            cout << "  $ WARNING : Neu ban tiep tuc nhap sai chuong trinh, chuong trinh se tu dong tat $ " << endl; 
            cout << " MOI BAN NHAP CHUC NANG : " ; 

            cin >> c ; 
            if ( c == 1 ) { 

                cout << "####      BAN DA CHO PHEP CHUONG TRINH TIEP TUC CHAY      ####" << endl; 
            }
            if ( c == 2 ) { 
                cout << endl; 
                cout << "####           BAN DA CHO CHUONG TRINH KET THUC           ####" << endl; 
                cout << "          =)) CAM ON BAN DA SU DUNG CHUONG TRINH =))          " << endl; 
                cout << endl; 
                break ; 
            } 
            if ( c != 1 && c != 2 || c < 0 ) 
            {  
                cout << "!!!!!       ERROR : BAN DA NHAP SAI CHUC NANG 2 LAN      !!!!!" << endl; 
                cout << "!!!!!             CHUONG TRINH SE TU DONG TAT            !!!!!" << endl; 
                cout << "           =(( CAM ON BAN DA SU DUNG CHUONG TRINH =((         " << endl; 
                cout << endl; 
                break; 
            }
        }
        if ( choose == 3 )
        { 
            cout << "####               CHUONG TRINH KET THUC                  ####" << endl; 
            cout << "        =)) CAM ON BAN DA SU DUNG CHUONG TRINH =))            " << endl; 
            cout << endl; 
        }
    }while ( choose != 3 ) ;
    SaveData(luong_mua, year, "list.dat");
    return 0 ; 
}