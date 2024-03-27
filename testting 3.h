#include<iostream> 
#include<vector> 
#include<fstream>
using namespace std ; 

void LoadFile ( string file_name , vector<int> &year, vector<vector<float> > &luong_mua ) 
{ 
    ifstream infile ; 
    infile.open ( file_name ) ; 

    int y ; 
    float l ; 
    while ( infile >> y ) 
    { 
        year.push_back(y) ;
        vector<float> temp ; 
        for ( int j = 0 ; j < 12 ; j ++ ) 
        { 
            infile >> l ; 
            temp.push_back(l) ; 
        }
        luong_mua.push_back(temp) ; 
    }
}


void NhapDuLieu (vector<vector<float> > &luong_mua , vector<int> &year )
{ 
    int m , y ; 
    float l_m ; 
    bool flag = false ; 
    cout << "MOI BAN NHAP VAO NAM : " ; 
    cin >> y ; 
    if ( y < 0 || y > 2024 ) { 
        int c = 0 ; 
        cout << endl; 
        cout << "#### CHAO MUNG BAN DEN VOI CHUONG TRING QUAN LI LUONG MUA ####"<< endl; 
    
        cout << "!!!!!     WARNING: NAM DUOC NHAP CHUA DUOC DINH DANG     !!!!! " << endl; 
        cout << "           ???? BAN CO MUON NHAP LAI NAM KHONG ????            " << endl; 
        cout << "                    1. NHAP LAI NAM                            " << endl; 
        cout << "                    2. KHONG NHAP LAI NAM                      " << endl; 
        cout << " MOI BAN NHAP CHUC NANG : " ; 
        cin >> c ; 
        cout << endl;    
        if ( c == 1 ) 
        { 
            cout << "####        THONG BAO: BAN DA LUA CHON CHUC NANG 1        ####" << endl; 
            cout << endl; 
            cout << " MOI BAN NHAP LAI NAM : " ; 
            cin >> y ; 
            if ( y < 0 || y > 2024) 
            { 
                cout << "!!!!!     WARNING: NAM DUOC NHAP CHUA DUOC DINH DANG     !!!!!" << endl; 
                cout << "               BAN TIEP TUC NHAP SAI SO LIEU                  " << endl; 
                cout << "!!!!!          CHUONG TRINH SE THOAT DEN MENU            !!!!!" << endl; 
                return ; 
            }
        }
        if ( c == 2 )
        { 
            cout << "     ####          BAN DA CHON CHUC NANG 2            ####     " << endl; 
            cout << "####            CHUONG TRINH SE BAT LAI TU DAU            ####  " << endl; 
            return ; 
        }
    }
    cout << "MOI BAN NHAP VAO THANG : " ;
    cin >> m ; 
    if ( m < 0 || m > 12 ) 
    {  
        int c ; 
        cout << "!!!!!     WARNING: KHONG TON TAI THANG NAY TRONG NAM     !!!!!" << endl; 
        cout << "          ???? BAN CO MUON NHAP LAI THANG KHONG ????          " << endl; 
        cout << "                     1. NHAP LAI THANG                        " << endl; 
        cout << "                     2. KHONG NHAP LAI THANG                  " << endl; 
        cout << " MOI BAN NHAP CHUC NANG : " ; 
        cin >> c ; 
        cout << endl;    
        if ( c == 1 ) 
        { 
            cout << " #### BAN DA LUA CHON CHUC NANG NHAP LAI ####" << endl; 
            cout << endl; 
            cout << " MOI BAN NHAP LAI THANG : " ; 
            cin >> m ; 
            if ( m < 0 || m > 12) 
            { 
                cout << "!!!!! WARNING: KHONG TON TAI THANG NAY TRONG NAM !!!!! " << endl; 
                cout << "            BAN TIEP TUC NHAP SAI SO LIEU              " << endl; 
                cout << "!!!!!       CHUONG TRINH SE THOAT DEN MENU       !!!!! " << endl; 
                return ; 
            }
        }
        if ( c == 2 )
        { 
            cout << "     ####          BAN DA CHON CHUC NANG 2            ####     " << endl; 
            cout << "####            CHUONG TRINH SE BAT LAI TU DAU            ####  " << endl; 
            return ; 
        }
    }
    int index = 0 ; 
    for (int i = 0 ; i < year.size() ; i ++ ) 
    { 
        if ( y == year[i])
        { 
            flag = true ; 
            index = i ; 
            if (luong_mua[i][m-1] != 0 ) 
            { 
                int c ;
                float l ;
                cout << "####         DU LIEU DANG TON TAI TRONG DANH SACH         ####" << endl;
                cout << "         ???? BAN CO MUON THAY DOI DU LIEU KHONG ????         " << endl;  
                cout << "                     1. DONG Y THAY DOI                       " << endl; 
                cout << "                     2. KHONG DONG Y THAY DOI                 " << endl; 
                cout << endl ; 
                cout << " MOI BAN NHAP CHUC NANG : " ; 
                cin >> c ; 

                if ( c == 1 )
                { 
                    cout << "####      THONG BAO: BAN DA LUA CHON THAY DOI DU LIEU     ####" << endl; 
                    cout << " MOI NHAP VAO LUONG MUA THAY DOI : " ;
                    cin >> l ;
                    luong_mua[i][m-1] = l ; 
                    cout << endl; 
                    cout << "**** THONG BAO:DU LIEU CUA BAN DA DUOC CAP NHAT ****" << endl; 
                    cout << "####        CHUONG TRINH SE BAT DAU LAI         ####" << endl; 
                    cout << endl; 
                    return ; 
                }
                if ( c == 2 )
                { 
                    cout << "    ####    BAN DA LUA CHON KHONG THAY DOI DU LIEU    ####      " << endl;
                    cout << "####            CHUONG TRINH SE BAT LAI TU DAU            ####  " << endl; 
                    cout << endl; 
                    return ; 
                }
            }
        }
    }
    if (flag == false ) 
    { 
        float l ; 
        vector<float> a(12 , 0) ;

        year.push_back(y) ;

        luong_mua.push_back(a) ; 

        cout << " MOI BAN NHAP VAO LUONG MUA : " ; 
        cin >> l ; 
        luong_mua[year.size()-1][m-1] = l ; 
        cout << endl; 
        cout << "    ####        BAN DA NHAP DU LIEU THANH CONG        ####      " << endl;
        cout << "####            CHUONG TRINH SE BAT LAI TU DAU            ####  " << endl;  
        return ; 
    } 
    if ( flag == true ) 
    { 
        float l ; 
        
        cout << " MOI BAN NHAP VAO LUONG MUA : " ; 
        cin >> l ; 
        luong_mua[index][m-1] = l ; 
        cout << endl; 
        cout << "    ####        BAN DA NHAP DU LIEU THANH CONG        ####      " << endl;
        cout << "####            CHUONG TRINH SE BAT LAI TU DAU            ####  " << endl;  
        return ; 
    }

}
void InRaDuLieu ( vector<vector<float> > &luong_mua, vector<int> &year) 
{ 
    int y ; 
    int index = 0 ; 
    float sum = 0 ; 
    bool flag = false ; 
    cout << endl; 
    cout << "####    BAN DA LUA CHON CHUC NANG 2 TU MENU    ####" << endl ; 
    cout << " MOI BAN NHAP VAO NAM MUON TIM: " ; 
    cin >> y ; 

    vector <int> month_no_data ; 
    for ( int i = 0 ; i < year.size() ; i++) 
    { 
        if (y == year[i])
        { 
            index = i ; 
            flag = true ; 
        }
    }
    if ( flag == true ) 
    { 
        for ( int j = 0 ; j < 12 ; j ++ ) 
        { 
            sum += luong_mua[index][j] ; 
            if (luong_mua[index][j] == 0 ) 
            { 
                month_no_data.push_back(j+1) ; 
            }
        }
        cout << "* LUONG MUA TRUNG BINH NAM " << y << " LA  : " << sum/(12-month_no_data.size()) << endl ; 
        cout << "* TONG LUONG MUA CUA NAM " << y << " LA : " << sum << endl; 
        cout << "* NHUNG THANG KHONG CO DU LIEU LA : " ; 
        for ( int j = 0 ; j < month_no_data.size() ; j ++) 
        { 
            cout << month_no_data[j] << " , " ; 
        }
        cout << endl; 
    }
    if ( flag ==false ) 
    { 
        int c ; 
        cout << endl; 
        cout << "####    THONG BAO: DU LIEU CUA NAM NAY KHONG TON TAI      ####" << endl;  
        cout << "   ????  BAN CO MUON NHAP DU LIEU CHO NAM NAY KHONG  ????     " << endl; 
        cout << "               1. NHAP DU LIEU CHO NAM MOI                    " << endl; 
        cout << "               2. KHONG NHAP DU LIEU                          " << endl; 
        cout << endl; 
        cout << " MOI BAN NHAP CHUC NANG : " ; 
        cin >> c ; 
        cout << endl; 
        if ( c == 1 ) { 
            cout << "####   LOI_KHUYEN: HAY CHON PHIM CHUC NANG 1 TREN MENU    ####"  << endl; 
            return ; 
        } 
        if ( c == 2 ) 
        { 
            cout << "####   LOI_KHUYEN: HAY CHON PHIM CHUC NANG 3 TREN MENU    ####" << endl; 
            return ; 
        }
    }   
}    

void SaveData ( vector<vector<float> >&luong_mua ,vector<int> &year, string file_name ) 
{ 
    ofstream outfile; 
    outfile.open("list.dat") ; 

    for ( int i = 0 ; i < year.size(); i ++ ) 
    { 
        outfile << year[i]  ; 
        for ( int j = 0 ; j < 12 ; j ++ ) 
        { 
            outfile << " " ; 
            outfile << luong_mua[i][j] ; 
        }
        outfile << endl; 
    }
        outfile.close() ; 
}
void ShowData (string file_name , int lenght) 
{ 
    ifstream infile ; 
    infile.open(file_name) ; 
    float data ; 
    
    for ( int i = 0 ; i < lenght  ; i ++ ) 
    { 
        for ( int j = 0 ; j < 13 ; j ++ ) 
        { 
            infile >> data ; 
            cout << data ; 
        } 
        cout << endl; 
    }
}