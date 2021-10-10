#include<iostream>
#include<string>
using namespace std;
class HocSinh{
    private:
        string NgaySinh;
        string Ten,MSHS,Lop,DiaChi;
    public:
        friend istream& operator >>(istream &is, HocSinh &hs);
        friend ostream& operator <<(ostream &os, HocSinh hs);
};
class Diem{
    private:
        float Toan,Ly,Hoa,Van,Su,Dia;
    //  float DiemTB;
    public:
        friend istream& operator >>(istream &is, Diem &diem);
        friend ostream& operator <<(ostream &os, Diem diem);
};
istream& operator >>(istream &is, HocSinh &hs){
    fflush(stdin);
    cout<<"\nNhap MSHS: ";
    getline(is,hs.MSHS);
    fflush(stdin);
    cout<<"\nNhap Ho Ten: ";
    getline(is,hs.Ten);
    fflush(stdin);
    cout<<"\nNhap Ngay Thang Nam sinh(VD: 14/07/2002): ";
    getline(is,hs.NgaySinh);
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
    os<<"Ngay Thang Nam sinh: "<<hs.NgaySinh<<endl;
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
