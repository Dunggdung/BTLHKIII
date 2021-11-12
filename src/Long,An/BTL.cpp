#include<iostream>
#include<string.h>
#include <conio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
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
        float DiemTB();
		void Nhap1();
		void Xuat1();
};
class HocSinh: public Diem{
	protected:
	  string  NgaySinh, Ten , Lop , DiaChi, MSHS;
    public:
    	HocSinh();
    	HocSinh(string Ten, string Lop, string DiaChi, string NgaySinh, string MSHS);
    	~HocSinh();
        friend void sapXepTen(HocSinh s[], int n);
	    void Nhap();
	    void Xuat();
};
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
void Diem::Nhap1() {
    fflush(stdin);
    do {
        cout<<"Nhap Diem Toan: ";
	    cin >> Toan;
        if (Toan < 0.0 || Toan >10.0){
            cout <<"Nhap Lai Diem Toan: ";
            cin >> Toan;
        }
    }while( Toan < 0.0 ||  Toan >10.0);
    do {
        cout<<"Nhap Diem Ly: ";
	     cin >>  Ly;
        if ( Toan < 0.0 ||  Ly >10.0){
            cout <<"Nhap Lai Diem Ly: ";
             cin >>  Ly;
        }
    }while( Ly < 0.0 ||  Ly >10.0);
    do {
        cout<<"Nhap Diem Hoa: ";
	     cin >>  Hoa;
        if ( Hoa < 0.0 ||  Hoa >10.0){
            cout <<"Nhap Lai Diem Hoa: ";
             cin >>  Hoa;
        }
    }while( Hoa < 0.0 ||  Hoa >10.0);
    do {
        cout<<"Nhap Diem Van: ";
	     cin >>  Van;
        if ( Van < 0.0 ||  Van >10.0){
            cout <<"Nhap Lai Diem Van: ";
             cin >>  Van;
        }
    }while( Van < 0.0 ||  Van >10.0);
    do {
        cout<<"Nhap Diem Su: ";
	     cin >>  Su;
        if ( Su < 0.0 ||  Su >10.0){
            cout <<"Nhap Lai Diem Su: ";
             cin >>  Su;
        }
    }while( Su < 0.0 ||  Su >10.0);
    do {
        cout<<"Nhap Diem Dia: ";
	     cin >>  Dia;
        if ( Dia < 0.0 ||  Dia >10.0){
            cout <<"Nhap Lai Diem Dia: ";
             cin >>  Dia;
        }
    }while( Dia < 0.0 ||  Dia >10.0);
}
void Diem:: Xuat1(){
    cout<<"\n  Diem Cua Hoc Sinh : "<<endl;
    cout<<"\tToan : " <<Toan<<"  |\tVan : "<<Van<<" |\tSu : "<<Su  <<" |\tDia : " <<Dia<<"  |\tLy : "<<Ly << " |\tHoa: " <<Hoa<<endl;
}
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
 void HocSinh::Nhap(){
	fflush(stdin);
	cout<<"\n Nhap Ten :";
    getline(cin,Ten);
    cout<<"\n Nhap Lop :";
    fflush(stdin);
    getline(cin,Lop);
    cout<<"\n Nhap Dia Chi :";
    fflush(stdin);
    getline(cin,DiaChi);
    cout<<"\n Nhap Ngay Sinh (vd 23/02/2000):";
    fflush(stdin);
    getline(cin,NgaySinh);
    cout<<"\n Nhap Ma So Hoc Sinh : ";
    cin>>MSHS;
    Diem::Nhap1();
}
void HocSinh::Xuat(){
     cout<<"\tTen     \t\tLop     \t\tDia chi     \t\tMa hoc Sinh "<<endl;
	 cout<<"\t"<<Ten<<"     \t\t"<<Lop<<"    \t\t"<<DiaChi<<"     \t\t"<<MSHS<<endl;
	Diem::Xuat1();
}

void input(HocSinh s[], int n){
    for(int i=0; i<n; i++){
        cout<<"Thong Tin Hoc Sinh  "<<i+1<<endl;
         s[i].Nhap();
    }
}
void print(HocSinh s[], int n){
    for(int i=0; i<n; i++){
        cout<<" Thong Tin Hoc Sinh Thu   "<<i+1<<endl;
        s[i].Xuat();
       
    }
}
// sap xep theo ten
void sapXepTen(HocSinh s[], int n){
    HocSinh temp;
    for (int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (s[i].Ten > s[j].Ten){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
// sap xep theo diem
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
// xep loai
void xeploai (float a){
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
/*void menu();
    int choice ;
    char k,c ;
    do{
        cout << "       CHUONG TRINH QUAN LY HOC SINH C/C++\n             ";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Nhap Thong tin hoc sinh                       **\n";
        cout << "**  2. Xuat thong tin hoc sinh.                      **\n";
        cout << "**  3. Xoa sinh vien boi ID.                         **\n";
        cout << "**  4. Tim kiem sinh vien theo ID.                   **\n";
        cout << "**  5. Them 1 hoc sinh .                             **\n";  
        cout << "**  6. Sap xep sinh vien theo diem trung binh .      **\n";
        cout <<  "**   7. Xep loai hoc sinh .                          **\n";  
        cout << "**  8. Sap xep sinh vien theo ten.                   **\n";
        cout << "**  9. Thong ke sinh vien theo tinh                  **\n";
        cout << "**  10. Ghi danh sach hoc sinh vao file.             **\n";
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
    cout <<"\nDo You Want To Exit ?(esc)";
        k = getch();
        c = k;
    }while(c != 27);
}
*/
int main(){
	int n;
	cout<<"Nhap So Luong Hoc Sinh: "; 
    cin>>n;
	HocSinh a[n+1];
	//a.Nhap();
	//a.Xuat();
	input(a,n);
    print(a,n);
	//get(hs,b);
}
