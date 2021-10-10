/*
Phạm Nguyễn Thùy Dung
6151071003
tạo dựng 4 class 
 + tên, lớp , ngày sinh, địa chỉ , MSHS
 + điểm toán ,lý hóa, văn sử địa, (điểm trung bình)
 +liên quan đến tính kế thừa
 +danh sách liên kết
*/ 
#include <iostream>
using namespace std;
class HocSinh {
    private:
        string Ten,Lop,NgaySinh,DiaChi,MSHS;
    public:
    friend istream& operator >> (istream& is, HocSinh& hs);
    friend ostream& operator << (ostream& os,const HocSinh& hs);
};
class Diem {
    private:
    float Toan,Ly,Hoa,Van,Su,Dia;
    public:
    friend istream& operator >> (istream& is, Diem& diem);
    friend ostream& operator << (ostream& os,const Diem& diem);
};
istream& operator >> (istream& is, HocSinh& hs){
    fflush(stdin);
    cout <<"Nhap Ma So Hoc Sinh: ";
	getline(is, hs.MSHS);
    fflush(stdin);
	cout <<"Nhap Ho Ten: ";
	getline(is, hs.Ten);
    fflush(stdin);
    cout <<"Nhap Lop: ";
	getline(is, hs.Lop);
    fflush(stdin);
    cout <<"Nhap Ngay Sinh vd(02/03/2002): ";
	getline(is, hs.NgaySinh);
    fflush(stdin);
    cout <<"Nhap Dia Chi: ";
	getline(is, hs.DiaChi);
    return is;
}
ostream& operator << (ostream& os, const HocSinh& hs) {
    // hs.STT ++;
    os <<endl<< "MSHS: " << hs.MSHS << endl;
    os << "Ho Va Ten: " << hs.Ten << endl;
    os << "Lop: " << hs.Lop << endl;
    os << "Ngay Sinh: " << hs.NgaySinh << endl;
    os << "Dia Chi: " << hs.DiaChi<< endl;
    return os;
}
istream& operator >> (istream& is, Diem& diem){
    fflush(stdin);
    cout<<"Nhap Diem Toan: ";
	is >> diem.Toan;
    cout<<"Nhap Diem Ly: ";
	is >> diem.Ly;
    cout<<"Nhap Diem Hoa: ";
	is >> diem.Hoa;
    cout<<"Nhap Diem Van: ";
	is >> diem.Van;
    cout<<"Nhap Diem Su: ";
	is >> diem.Su;
    cout<<"Nhap Diem Dia: ";
	is >> diem.Dia;
    return is;
}
ostream& operator << (ostream& os,const Diem& diem){
    os <<endl<< "Toan: " << diem.Toan << " |Ly: " << diem.Ly <<" |Hoa: "<< diem.Hoa <<" |Van: "<<diem.Van<<" |Su: "<<diem.Su<<" |Dia: "<< diem.Dia<<endl;
}
int main (){
    HocSinh a;
    Diem b ;
    cout<<"Nhap Sinh Vien a: "<<endl;
    cin >> a;
    cout <<a;
    cout<<"Nhap Diem b: "<<endl;
    cin >> b;
    cout <<b;
    return 0;
}