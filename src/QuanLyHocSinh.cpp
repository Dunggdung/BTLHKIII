#include<iostream>
#include<string>
using namespace std;
class HocSinh{
    private:
        int Ngay, Thang, Nam;
        string Ten,MSHS,Lop,DiaChi;
    public:
        void NhapNS();
        bool KiemTra();
        friend istream& operator >>(istream &is, HocSinh &hs);
        friend ostream& operator <<(ostream &os, HocSinh hs);
};
class Diem{
    private:
        float Toan,Ly,Hoa,Van,Su,Dia;
    public:
        friend istream& operator >>(istream &is, Diem &diem);
        friend ostream& operator <<(ostream &os, Diem diem);
};

void HocSinh::NhapNS()
{ //Nhap ngay thang nam
    do{
        cout<<"\nNgay: ";
        cin>>Ngay;
        cout<<"Thang: ";
        cin>>Thang;
        if(KiemTra()==false){
            cout<<endl<<"Nhap lai ngay thang!!"<<endl;
            cout<<"\nNgay: ";
            cin>>Ngay;
            cout<<"Thang: ";
            cin>>Thang;
        }
    }while(KiemTra()==false);
    do{
    cout<<"Nam: ";
    cin>>Nam;
    if(Nam > 2021 || Nam <= 0){
        cout<<"Nhap lai nam sinh!!";
        cout<<endl<<"Nam: ";
        cin>>Nam;
    }
    }while(Nam > 2021 || Nam <= 0);
}
bool HocSinh::KiemTra(){
{
    //kiểm tra ngày tháng
    bool KiemTra = true;
    if (Thang < 0 || Thang > 12)
    {
        KiemTra = false;
    }
    else
    {
        switch (Thang)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (Ngay < 1 || Ngay > 31)
            {
                KiemTra = false;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (Ngay < 1 || Ngay > 30)
            {
                KiemTra = false;
            }
            break;
        case 2:
            if (Nam % 4 == 0 && Ngay < 1 || Ngay > 29)
            {
                KiemTra = false;
            }
            break;
        }
    }
    return KiemTra;
}
}
istream& operator >>(istream &is, HocSinh &hs){
    fflush(stdin);
    cout<<"\nNhap MSHS: ";
    getline(is,hs.MSHS);
    fflush(stdin);
    cout<<"\nNhap Ho Ten: ";
    getline(is,hs.Ten);
    fflush(stdin);
    cout<<"\nNhap Ngay Thang Nam sinh(VD: 14/07/2002): "<<endl;
    hs.NhapNS();
    hs.KiemTra();
    fflush(stdin);
    cout<<"\nNhap Lop hoc: ";
    getline(is,hs.Lop);
    fflush(stdin);
    cout<<"\nNhap Dia Chi: ";
    getline(is,hs.DiaChi);
    return is;
}
ostream& operator <<(ostream &os, HocSinh hs){
    os<<endl<<"MSHS: "<<hs.MSHS<<endl;
    os<<"Ho Ten: "<<hs.Ten<<endl;
    os<<"Ngay Thang Nam sinh: "<<hs.Ngay<<"/"<<hs.Thang<<"/"<<hs.Nam<<endl;
    os<<"Lop: "<<hs.Lop<<endl;
    os<<"Dia Chi: "<<hs.DiaChi<<endl;
    return os;
}
istream& operator >>(istream &is, Diem &diem){
    cout<<endl<<"Nhap Diem Toan: ";
    is>>diem.Toan;
    cout<<endl<<"Nhap Diem Ly: ";
    is>>diem.Ly;
    cout<<endl<<"Nhap Diem Hoa: ";
    is>>diem.Hoa;
    cout<<endl<<"Nhap Diem Van: ";
    is>>diem.Van;
    cout<<endl<<"Nhap Diem Su: ";
    is>>diem.Su;
    cout<<endl<<"Nhap Diem Dia: ";
    is>>diem.Dia;
    return is;
} 
ostream& operator <<(ostream &os, Diem diem){
    os<<endl<<"Diem Toan: "<<diem.Toan<<endl;
    os<<"Diem Ly: "<<diem.Ly<<endl;
    os<<"Diem Hoa: "<<diem.Hoa<<endl;
    os<<"Diem Van: "<<diem.Van<<endl;
    os<<"Diem Su: "<<diem.Su<<endl;
    os<<"Diem Dia: "<<diem.Dia<<endl;
    return os;
}
int main(){
    HocSinh hs1;
    Diem diem1;
    cout<<endl<<"Nhap thong tin hoc sinh: "<<endl;
    cin>>hs1;
    cin>>diem1;
    system("cls");
    cout<<"Thong tin hoc sinh: "<<endl;
    cout<<hs1;
    cout<<diem1;
}
