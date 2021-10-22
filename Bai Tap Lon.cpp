#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class Diem;

class HocSinh: public Diem{
	protected:
	  string  NgaySinh, Ten , Lop , DiaChi, MSHS;
	 
	
    public:
    	HocSinh();
    	HocSinh(string Ten, string Lop, string DiaChi, string NgaySinh, string MSHS);
    	~HocSinh();
        friend void sapXepTen(HocSinh s[], int n);
		friend istream& operator >> (istream &is, HocSinh &hs);
		friend ostream& operator << (ostream &os,const HocSinh &hs1);
		//friend void get(HocSinh a,Diem b);
};
class Diem {
	protected:
		float Toan;
		float Ly;
		float Hoa;
		float Van;
		float Su;
		float Dia;
	public:
		Diem();
		Diem(float Toan,float Ly,float Hoa ,float Van ,float Su,float Dia);
		~Diem();
        float DiemTB(int n);
		friend istream& operator >>(istream &is, Diem &hs);
		friend ostream& operator << (ostream &os,const Diem &b);
	//	friend void get(HocSinh a, Diem b);
};
HocSinh::HocSinh(){
	Ten ="";
	Lop ="";
	NgaySinh ="";
	DiaChi ="";
	MSHS="";
}
HocSinh::HocSinh(string Ten, string Lop, string DiaChi, string NgaySinh, string  MSHS){
	this->Ten=Ten;
	this->DiaChi=DiaChi;
	this->Lop=Lop;
	this->NgaySinh=NgaySinh;
	this->MSHS=MSHS;
}
HocSinh::~HocSinh(){
	this->Ten="";
	this->DiaChi="";
	this->Lop="";
	this->NgaySinh="";
	this->MSHS="";
}
void sapXepTen(HocSinh s[], int n){
    HocSinh temp;
    for (int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (strcmp(s[i].Ten,s[j].Ten) > 0){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
void sapXepDiemTB(HocSinh s[], int n){
    HocSinh temp ;
    for (int i = 0; i < n -1; i++){
        for(int j = i+1; j < n; j++){
            if (s[i].DiemTB() > s[i].DiemTB()){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
void xeploai (float a){
    // Xếp loại theo tiêu chí:
    //     - Giỏi (>= 8.0)
    //     - Khá (>= 7.0)
    //     - Trung bình (>= 5.0)
    //     - Yếu (< 5)
    if (a >= 8.0){
        cout <<"Gioi" << endl;
    }
    else if (a >=7.0 && a < 8.0){
        cout <<"Kha"<< endl;
    }
    else if (a >= 5.0 && a < 7.0){
        cout <<"Trung Binh"<< endl;
    }
    else {
        cout <<"Yeu"<< endl;
    }
}
Diem::Diem(){
	Toan=0;
	Ly=0;
	Hoa=0;
	Van=0;
	Su=0;
	Dia=0;
}
Diem::Diem(float Toan, float Ly, float Hoa, float Van,float Su, float Dia){
	this->Toan=Toan;
	this->Ly=Ly;
	this->Hoa=Hoa;
	this->Van=Van;
	this->Su=Su;
	this->Dia=Dia;
}
Diem::~Diem(){
	this->Toan=0;
	this->Ly=0;
	this->Hoa=0;
	this->Van=0;
	this->Su=0;
	this->Dia=0;
}
float Diem::DiemTB(){
    float diem;
    diem = (Toan+Ly+Hoa+Van+Su+Dia)/6;
    return diem;
}
istream& operator >>(istream &is, HocSinh &hs){
	fflush(stdin);
	cout<<"\n Nhap ten :";
    getline(cin,hs.Ten);
    cout<<"\n Nhap lop :";
    fflush(stdin);
    getline(cin,hs.Lop);
    cout<<"\n Nhap dia chi :";
    fflush(stdin);
    getline(cin,hs.DiaChi);
    cout<<"\n Nhap ngay sinh (vd 23/02/2000):";
    fflush(stdin);
    getline(cin,hs.NgaySinh);
    cout<<"\n Nhap ma so hoc sinh : "<<endl;
    is>>hs.MSHS;
    return is;
}
ostream& operator << (ostream& os, const HocSinh& hs) {
    // hs.STT ++;
    /*os <<endl<< "MSHS: " << hs.MSHS << endl;
    os << "Ho Va Ten: " << hs.Ten << endl;
    os << "Lop: " << hs.Lop << endl;
    os << "Ngay Sinh: " << hs.NgaySinh << endl;
    os << "Dia Chi: " << hs.DiaChi<< endl;
    return os;*/
    os<<"\tTen     \t\tLop     \t\tDia chi     \t\tMa hoc Sinh "<<endl;
	os<<"\t"<<hs.Ten<<"     \t\t"<<hs.Lop<<"     \t\t"<<hs.DiaChi<<"     \t\t"<<hs.MSHS<<endl;
    return os;
}
istream& operator >> (istream& is, Diem& diem){
    fflush(stdin);
    cout<<"\nNhap Diem Toan: ";
	is >> diem.Toan;
    cout<<"Nhap Diem Ly: " ;
	is >> diem.Ly;
    cout<<"Nhap Diem Hoa: " ;
	is >> diem.Hoa;
    cout<<"Nhap Diem Van: ";
	is >> diem.Van;
    cout<<"Nhap Diem Su: ";
	is >> diem.Su;
    cout<<"Nhap Diem Dia: ";
	is >> diem.Dia;
    return is;
}
ostream& operator << (ostream& os,const Diem& b){
    //os <<endl<< "Toan: " << diem.Toan << " Ly: " << diem.Ly <<" Hoa: "<< diem.Hoa <<" Van: "<<diem.Van<<" Su: "<<diem.Su<<"Dia: "<< diem.Dia<<endl;

     os<<"\tToan : " <<b.Toan<<"  |\tVan : "<<b.Van<<" |\tSu : "<<b.Su  <<" |\tDia : " <<b.Dia<<"  |\tLy : "<<b.Ly << " |\tHoa: " <<b.Hoa<<endl;
	  //os<<"\t"<<b.Toan<<"    \t"<<b.Van<<"    \t"<<b.Su<<"    \t"<<b.Dia<<"    \t"<<b.Ly<<"    \t\t"<<b.Hoa;
    return os;
}
/*void get(HocSinh a, Diem b){
	cout<<"\n THONG TIN SINH VIEN LA : "<<endl;
	cout<<"\tTen     \t\tLop     \t\tDia chi     \t\tMa hoc Sinh "<<endl;
	cout<<"\t"<<a.Ten<<"     \t"<<a.Lop<<"     \t\t"<<a.DiaChi<<"     \t\t"<<a.MSHS<<endl;
	cout<<" DIEM CUA SINH VIEN :"<<endl;
	cout<<"\tToan  \tVan  \tSu  \tDIA  \tLy  \tHoa "<<endl;
	cout<<"\t"<<b.Toan<<"  \t"<<b.Van<<"  \t"<<b.Su<<"  \t"<<b.Dia<<"  \t"<<b.Ly<<"  \t"<<b.Hoa;
	

}*/
void input(HocSinh s[], int n,Diem b[]){
    for(int i=0; i<n; i++){
        cout<<"thong tin sinh vien  "<<i+1<<endl;
        cin>>s[i];
        cin>>b[i];
    }
}
void print(HocSinh s[], int n,Diem b[]){
    for(int i=0; i<n; i++){
        cout<<" ThongTin hoc sinh thu   "<<i+1<<endl;
        cout<<s[i];
        cout<<b[i];
    }
}
/*void menu();
 cout << "CHUONG TRINH QUAN LY SINH VIEN C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them sinh vien.                               **\n";
        cout << "**  2. Cap nhat thong tin sinh vien boi ID.          **\n";
        cout << "**  3. Xoa sinh vien boi ID.                         **\n";
        cout << "**  4. Tim kiem sinh vien theo ten.                  **\n";
        cout << "**  5. Sap xep sinh vien theo diem trung binh (GPA). **\n";
        cout << "**  6. Sap xep sinh vien theo ten.                   **\n";
        cout << "**  7. Hien thi danh sach sinh vien.                 **\n";
        cout << "**  8. Ghi danh sach sinh vien vao file.             **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
                
            case 2:
                
            case 3:
                
            case 4:
               
            case 5:
                
            case 6:
                
            case 7:
                
                   
            case 8:
                if(soluongSV > 0){
               
            case 0:
               
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}
*/
int main(){
	int n;
	cout<<"Nhap  n: "; 
    cin>>n;
	HocSinh a[n+1];
	Diem b[n+1];
	input(a,n,b);
    print(a,n,b);
	//get(hs,b);
}
