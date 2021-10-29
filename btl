#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class  NgaySinh{// diem lay cua nguoi
	protected:
		 string sinh;
   public:
   	     NgaySinh();
   	     NgaySinh( string sinh);
   	    ~NgaySinh();
   	     void Nhap1();
   	     void Xuat1();
};
NgaySinh::NgaySinh(){
	this->sinh="";
	
}
NgaySinh::NgaySinh( string sinh){
    this->sinh=sinh;
	
}
NgaySinh::~NgaySinh(){

}
void NgaySinh:: Nhap1(){
    cout<<"\n Nhap ngay sinh (vd 23/03/2002):";
    getline(cin,sinh);
    
     
}
void NgaySinh::Xuat1(){
	//cout<<"Ngay Sinh ";
	cout<<"\t\t "<<sinh;
}
class Nguoi: public NgaySinh{// hoc sinh lay cua nguoi
	protected:
		string Ten, DiaChi;
	public:
		Nguoi();
     	Nguoi(string Ten,string DiaChi);
    	~Nguoi();
    	void Nhap2();
    	void Xuat2();
};
Nguoi::	Nguoi():NgaySinh(){
	this->DiaChi="";
	this->Ten="";
}
Nguoi::Nguoi(string Ten,string DiaChi):NgaySinh(sinh){
	this->DiaChi=DiaChi;
	this->Ten=Ten;
}
Nguoi::~Nguoi(){

}
void Nguoi:: Nhap2(){
	fflush(stdin);
	cout<<"\n Nhap ten :";
	getline(cin,Ten);
	cout<<"\n Nhap dia chi :";
    fflush(stdin);
    getline(cin,DiaChi);
    NgaySinh::Nhap1();
} 
void Nguoi::Xuat2(){
	cout<<"\tTen     \t\t Dia CHi \t \t  Sinh"<<endl;
	cout<<"\t\t "<<Ten<<"     \t "<<DiaChi;
	NgaySinh::Xuat1();
}
class Diem: public Nguoi {
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
	 	void Nhap3();
		void Xuat3();
};

Diem::Diem():Nguoi(){
	Toan=0;
	Ly=0;
	Hoa=0;
	Van=0;
	Su=0;
	Dia=0;
}
Diem::Diem(float Toan, float Ly, float Hoa, float Van,float Su, float Dia):Nguoi(Ten,DiaChi){
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
void Diem::Nhap3() {
	Nguoi::Nhap2();
    fflush(stdin);
    cout<<"\nNhap Diem Toan: ";
	cin >> Toan;
    cout<<"Nhap Diem Ly: " ;
	cin >> Ly;
    cout<<"Nhap Diem Hoa: " ;
	cin >> Hoa;
    cout<<"Nhap Diem Van: ";
	cin >> Van;
    cout<<"Nhap Diem Su: ";
	cin >> Su;
    cout<<"Nhap Diem Dia: ";
	cin >>Dia;
   
}
void Diem:: Xuat3(){
	Nguoi::Xuat2();
    cout<<"\n  Diem Cua Hoc Sinh : "<<endl;
    cout<<"\tToan : " <<Toan<<"  |\tVan : "<<Van<<" |\tSu : "<<Su  <<" |\tDia : " <<Dia<<"  |\tLy : "<<Ly << " |\tHoa: " <<Hoa<<endl;
}
class HocSinh: public Diem{
	private:
	  string   Lop , MSHS;
    public:
    	HocSinh();
    	HocSinh( string Lop, string MSHS);
    	~HocSinh();
	    void Nhap4();
	    void Xuat4();
};
HocSinh::HocSinh():Diem(){
	Lop ="";
	MSHS="";
}
HocSinh::HocSinh( string Lop,  string  MSHS):Diem(Toan,Ly,Hoa,Van,Su,Dia){
	this->Lop=Lop;
	this->MSHS=MSHS;
}
HocSinh::~HocSinh(){
	this->Lop="";
	this->MSHS="";
}
 void HocSinh::Nhap4(){
 	Diem::Nhap3();
    cout<<"\n Nhap lop :";
    fflush(stdin);
    getline(cin,Lop);
    cout<<"\n Nhap ma so hoc sinh : "<<endl;
    fflush(stdin);
    getline(cin,MSHS);
    
   
}
void HocSinh::Xuat4(){
	cout<<"\n\t\t\t\t\t Thong Tin Hoc Sinh "<<endl;
	Diem::Xuat2();
	cout<<"     \t\tLop     \t\tMa hoc Sinh "<<endl;
	cout<<"     \t\t"<<Lop<<"    \t\t"<<MSHS<<endl;
	//Diem::Xuat3();
}
void input(HocSinh s[], int n){
    for(int i=0; i<n; i++){
        cout<<"thong tin hoc sinh  "<<i+1<<endl;
         s[i].Nhap4();
    }
}
void print(HocSinh s[], int n){
    for(int i=0; i<n; i++){
        cout<<" ThongTin hoc sinh thu   "<<i+1<<endl;
        s[i].Xuat4();
    }
}
// sap xep theo ten
/*void sapXepTen(HocSinh s[], int n){
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
}*//*
void menu();
      NV x;
	danhsach ds;
	//char fileName[] = "employee.txt";
	int chon,b, flat = 1;
	char c[20];
	bool daNhap = false ;
	do{
		printf("\n Nhap so luong nhan vien : ");
		scanf("%d",&ds.n);
	}while(ds.n<=0);
        cout << "       CHUONG TRINH QUAN LY HOC SINH C/C++\n             ";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Nhap Thong tin hoc sinh                       **\n";
        cout << "**  2. Xuat thong tin hoc sinh.                      **\n";
        cout << "**  3. Xoa sinh vien boi ID.                         **\n";
        cout << "**  4. Tim kiem sinh vien theo ID.                   **\n";
        cout << "**  5. Them 1 hoc sinh .                             **\n";  
        cout << "**  6. Sap xep sinh vien theo diem trung binh .      **\n";
        out <<  "**   7. Xep loai hoc sinh .                          **\n";  
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
}
*/
int main(){
	int n;
	cout<<"NHAP SO LUONG HOC SINH: "; 
     cin>>n;
	HocSinh a[n+1];
	input(a,n);
    print(a,n);
   // Nguoi a;
	//a.Nhap2() ;
	//a.Xuat2();

}
