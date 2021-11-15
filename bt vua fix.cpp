#include<iostream>
#include<iomanip>// can cinh do rong
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include <vector>
using namespace std;
class  NgaySinh{// diem lay cua nguoi
	protected:
		 int Ngay , Thang , Nam;
   public:
   	     NgaySinh();
   	     NgaySinh( int ngay, int thang , int nam);
   	    ~NgaySinh();
   	     void Nhap1();
   	     void Xuat1();
   	     bool KiemTra();
};
NgaySinh::NgaySinh(){
	this->Ngay=0;
	this->Thang=0;
	this->Nam=0;
	
}
NgaySinh::NgaySinh(int ngay ,int thang, int nam){
  	this->Ngay=0;
	this->Thang=0;
	this->Nam=0;
}
NgaySinh::~NgaySinh(){

}
void NgaySinh::Nhap1()
{ //Nhap ngay thang nam
    cout<<"\n\t\t\t Nhap Ngay sinh( 23/02/2002)"<<endl;
    do{
        cout<<"\t\tNgay: ";
        cin>>Ngay;
        cout<<"\t\tThang: ";
        cin>>Thang;
        if(KiemTra()==false){
            cout<<endl<<"\t\t Ngay Thang Sai !! Nhap lai ngay thang!!"<<endl;
            cout<<"\n\t\tNgay: ";
            cin>>Ngay;
            cout<<"\t\tThang: ";
            cin>>Thang;
        }
    }while(KiemTra()==false);
    do{
    cout<<"\t\tNam: ";
    cin>>Nam;
    if(Nam > 2021 || Nam <= 0){
        cout<<"\t\tNhap lai nam sinh!!";
        cout<<endl<<"\t\tNam: ";
        cin>>Nam;
    }
    }while(Nam > 2021 || Nam <= 0);
}
bool NgaySinh::KiemTra(){
{
    //ki?m tra ngày tháng
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
void NgaySinh::Xuat1(){
	cout<<Ngay<<"/"<<Thang<<"/"<<Nam;
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
    	string getTen();
};
Nguoi::	Nguoi():NgaySinh(){
	this->DiaChi="";
	this->Ten="";
}
Nguoi::Nguoi(string Ten,string DiaChi):NgaySinh(Ngay,Thang,Nam){
	this->DiaChi=DiaChi;
	this->Ten=Ten;
}
Nguoi::~Nguoi(){

}
void Nguoi:: Nhap2(){
	fflush(stdin);
	cout<<"\n\t\t Nhap ten :";
	getline(cin,Ten);
	cout<<"\n\t\t Nhap dia chi :";
    fflush(stdin);
    getline(cin,DiaChi);
    NgaySinh::Nhap1();
   NgaySinh::KiemTra();
} 
void Nguoi::Xuat2(){
	cout<<"\tTen     \t\t Dia CHi \t \t  Sinh"<<endl;
	cout<<"\t\t "<<Ten<<"     \t "<<DiaChi;
	NgaySinh::Xuat1();
}
string Nguoi:: getTen(){
	 return Ten;
}
class Diem: public Nguoi {
	protected:
		float Toan;
		float Ly;
		float Hoa;
		float Van;
		float Su;
		float Dia;
		float DTB;
	public:
		Diem();
		Diem(float Toan,float Ly,float Hoa ,float Van ,float Su,float Dia);
		~Diem();
	 	void Nhap3();
		void Xuat3();
		float getDTB();
	
};

Diem::Diem():Nguoi(){
	  Toan=0;
	  Ly=0;
	  Hoa=0;
	  Van=0;
	  Su=0;
	  Dia=0;
	  DTB=0;
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
     this->DTB=0;
}
void Diem::Nhap3() {
	Nguoi::Nhap2();
    fflush(stdin);
     cout<<setw(50)<<"\n\t\tNhap Diem  Cua Hoc Sinh : ";
    do {
        cout<<"\n\t\tNhap Diem Toan: ";
	    cin >> Toan;
        if (Toan < 0.0 || Toan >10.0){
            cout <<"\t\tNhap Lai Diem Toan: ";
            cin >> Toan;
        }
    }while( Toan < 0.0 ||  Toan >10.0);
    do {
        cout<<"\t\tNhap Diem Ly: ";
	     cin >>  Ly;
        if ( Toan < 0.0 ||  Ly >10.0){
            cout <<"\t\tNhap Lai Diem Ly: ";
             cin >>  Ly;
        }
    }while( Ly < 0.0 ||  Ly >10.0);
    do {
        cout<<"\t\tNhap Diem Hoa: ";
	     cin >>  Hoa;
        if ( Hoa < 0.0 ||  Hoa >10.0){
            cout <<"\t\tNhap Lai Diem Hoa: ";
             cin >>  Hoa;
        }
    }while( Hoa < 0.0 ||  Hoa >10.0);
    do {
        cout<<"\t\tNhap Diem Van: ";
	     cin >>  Van;
        if ( Van < 0.0 ||  Van >10.0){
            cout <<"\t\tNhap Lai Diem Van: ";
             cin >>  Van;
        }
    }while( Van < 0.0 ||  Van >10.0);
    do {
        cout<<"\t\tNhap Diem Su: ";
	     cin >>  Su;
        if ( Su < 0.0 ||  Su >10.0){
            cout <<"\t\tNhap Lai Diem Su: ";
             cin >>  Su;
        }
    }while( Su < 0.0 ||  Su >10.0);
    do {
        cout<<"\t\tNhap Diem Dia: ";
	     cin >>  Dia;
        if ( Dia < 0.0 ||  Dia >10.0){
            cout <<"\t\tNhap Lai Diem Dia: ";
             cin >>  Dia;
        }
    }while( Dia < 0.0 ||  Dia >10.0);
     DTB=(Toan+Ly+Hoa+Van+Su+Dia)/6;
   
}
float Diem::getDTB(){
	return DTB;
}
void Diem:: Xuat3(){
	Diem a;
    cout<<"\n\t\t\t\t\t  DIEM CUA HOC SINH: "<<endl;
	cout<<"\t\t\t"<<setw(10)<<" Toan"<<setw(10)<<"Ly "<<setw(10)<<"Hoa "<<setw(10)<<"Van "<<setw(10)<<" Su "<<setw(10)<<"Dia "<<setw(10)<<"Diem TB "<<endl;
	cout<<"\t\t\t"<<setfill('-');
    cout<<setw(68)<<"-"<<endl;
    cout<<setfill(' ');
	cout<<"\t\t\t"<<setw(10)<<Toan<<setw(10)<<Ly<<setw(10)<<Hoa<<setw(10)<<Van<<setw(10)<<Su <<setw(10)<<Dia<<setw(10)<<DTB<<endl;
	cout<<"\t"<<setfill('_');
    cout<<setw(100)<<"_"<<endl;
    cout<<setfill(' ')<<endl;
}
class HocSinh: public Diem{
	private:
	  string   Lop , MSHS;
	  static int STT;
    public:
    	HocSinh();
    	HocSinh( string Lop, string MSHS);
    	~HocSinh();
	    void Nhap4();
	    void Xuat4();
	    string getMSHS();
};
int HocSinh::STT=0;
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
    cout<<"\n\t\t\tNhap lop :";
    fflush(stdin);
    getline(cin,Lop);
    cout<<"\t\t\tNhap ma so hoc sinh : ";
    fflush(stdin);
    getline(cin,MSHS);
}


void HocSinh::Xuat4(){
	HocSinh A;
	STT++;
	// stt bang thuoc tinh tinh
	// ham setw no tu can do dong tu trai sang phai ghi ki tu tu phai sang trai
	cout<<"\t\t\t\t\t THONG TIN HOC SINH \n"<<endl;
   	cout<<"\t\t"<<setw(8)<<left<<"STT "<<setw(25)<<left<<"Ten"<<setw(15)<<left<<"Dia Chi"<<setw(10)<<left<<"MSHS"<<setw(25)<<left<<"Ngay Sinh"<<endl;
   	cout<<"\t\t"<<setfill('-');
    cout<<setw(70)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<"\t\t"<<setw(8)<<left<<A.STT<<setw(25)<<left<<Ten<<setw(15)<<left<<DiaChi<<setw(10)<<left<<MSHS<<left<<Ngay<<"/"<<Thang<<"/"<<Nam<<endl;
	Diem::Xuat3();
}
string HocSinh::getMSHS(){
	return MSHS;
}
class quanlyHS{
	  private:
	  	 vector<HocSinh *> HS;
       public:
          void NhapDS(int n);
		  void XuatDS();
		  void XoaHSID(string H);
		  void TimKiemID(string H);	
		  void ThemHS();
		  void SapXepDTB();
		  void SapXepName();
		  void XepLoaiHS();  
		 
};
 void quanlyHS::NhapDS(int n){
 	  HocSinh *hs;
  	 for(int i=0; i< n; i++){
        cout<<"\n\t\t\t\t Nhap Thong Tin Cua Hoc Sinh Thu  "<<i+1<<endl;
             hs= new HocSinh;
             hs->Nhap4();
             HS.push_back(hs);
    }
 }
void quanlyHS:: XuatDS(){
	for(int i = 0 ;i < this->HS.size();i++){
		cout<<"\n\t\t\t\tThong Tin hoc sinh thu  "<<i+1<<endl;
		this->HS.at(i)->Xuat4();
	}
} 
void quanlyHS::SapXepDTB(){
	for(int i = 0 ;i < this->HS.size()-1;i++){
		for(int j = i+1; j< this->HS.size();j++ ){
			if(HS.at(i)->getDTB() > HS.at(j)->getDTB()){
				HocSinh *t=HS.at(i);
				HS.at(i)=HS.at(j);
				HS.at(j)=t;
			}
		}
	
	}
 	
}
void quanlyHS::SapXepName(){
	for(int i = 0 ;i < this->HS.size()-1;i++){
		for(int j = i+1; j< this->HS.size();j++ ){
			if(HS.at(i)->getTen() > HS.at(j)->getTen()){
				HocSinh *t=HS.at(i);
				HS.at(i)=HS.at(j);
				HS.at(j)=t;
			}
		}
	
	}
 	
}
void quanlyHS::XoaHSID(string H){
	for(int i = 0 ;i < this->HS.size();i++){
		if(HS.at(i)->getMSHS()==H){
			  	HS.erase(HS.begin()+(i));
			
			}
	}
}
void quanlyHS::ThemHS(){
	 HocSinh *hs;
	for(int i = 0 ;i < this->HS.size();i++){
		cout<<endl;
		hs= new HocSinh;
        hs->Nhap4();
	    HS.push_back(hs);
		break;	
	}
}
void quanlyHS::TimKiemID(string H){
	for(int i = 0 ;i < this->HS.size();i++){
		if(HS.at(i)->getMSHS()==H){
			  HS.at(i)->Xuat4();
		}
	}
}
void menu(){
    int n;
    do{
		cout<<" Nhap So Luong Hoc Sinh : ";
		cin>>n;
	}while(n<=0);
	quanlyHS k;
	HocSinh h;
	char fileName[] = "employee.txt";
	int chon,b, flat = 1;
	bool daNhap = false ;
	while(flat){
	    system("cls");
        cout  <<"\t\t\t\t"<< "       CHUONG TRINH QUAN LY HOC SINH C/C++\n             ";
        cout  <<"\t\t"<< "*************************MENU******************************\n";
        cout  <<"\t\t\t"<< "**      1. Nhap thong tin hoc sinh                       **\n";
        cout  <<"\t\t\t"<< "**      2. Xuat thong tin hoc sinh.                      **\n";
        cout  <<"\t\t\t"<< "**      3. Xoa hoc sinh  boi ID.                         **\n";
        cout  <<"\t\t\t"<< "**      4. Tim kiem sinh vien theo ID.                   **\n";
        cout  <<"\t\t\t"<< "**      5. Them 1 hoc sinh .                             **\n";  
        cout  <<"\t\t\t"<< "**      6. Sap xep sinh vien theo diem trung binh .      **\n";
        cout  <<"\t\t\t"<< "**      7. Xep loai hoc sinh .                           **\n";  
        cout  <<"\t\t\t"<< "**      8. Sap xep sinh vien theo ten.                   **\n";
        cout  <<"\t\t\t"<< "**      9. Thong ke sinh vien theo tinh                  **\n";
        cout  <<"\t\t\t"<< "**      10. Ghi danh sach hoc sinh vao file.             **\n";
        cout  <<"\t\t\t"<< "**      0. Thoat                                         **\n";
        cout  <<"\t\t\t"<< "***********************************************************\n";
        cout  << "Nhap tuy chon: ";
        cin >> chon;
        switch(chon){
            case 1:
            		cout<<"\n Ban Da Chon Nhap Thong Tin  Hoc Sinh !";
			        k.NhapDS(n);
			        cout<<"\n\t\t\t\t\t Ban da nhap thanh cong !\n";
			        daNhap=true;
		         	cout<<"\n\t\t\t\tVui long nhap phim bat ki de tiep tuc !";
		        	getch();
		        	break;
                
            case 2: 
                     system("cls");
			        if(daNhap){
                       cout<<"\n Ban Da Chon Xuat Thong Tin  Hoc Sinh!";
                      k.XuatDS();
                    }
			         else{
                       cout<<"\\t\t\t\tnNhap DS nhan vien truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
                   
            case 3:
            	     system("cls");
			        if(daNhap){
                     cout<<"\n Ban  chon Xoa 1 Hoc Sinh !";
                     string h;
                     cout<<"\n Nhap Ma id can xoa : ";
                     fflush(stdin);
                     getline(cin,h);
                     
                     k.XoaHSID(h);
                     cout<<"\n\t\t\t\t\tTHONG TIN SAU KHI XOA LA  : "<<endl;
                     k.XuatDS();
                    }
			         else{
                       cout<<"\n\t\t\t\tnNhap DS nhan vien truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
                
            case 4:
            	     system("cls");
			         if(daNhap){
                     cout<<"\n Ban Chon tim hoc sinh bang id  !";
                     
                     string h;
                     cout<<"\n Nhap Ma id can tim : ";
                     fflush(stdin);
                     getline(cin,h);
                     k.TimKiemID(h);
                    //  cout<<"\n\t\t\t\t\tTHONG TIN SAU KHI XOA LA  : "<<endl;
                    //  k.XuatDS();
                    }
			         else{
                       cout<<"\\t\t\t\tnNhap DS nhan vien truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
               
            case 5:
            	    system("cls");
			        if(daNhap){
                       cout<<"\n\n Ban da chon them 1 Hoc Sinh ( vao cuoi danh sach): " ;                 
						k.ThemHS();
                        k.XuatDS();
                    }
			         else{
                       cout<<"\\t\t\t\tnNhap DS nhan vien truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
            	 
                
            case 6:
            	 if(daNhap){
                       cout<<"\n\t\t\t\t\tSap xep Diem TB  (Tang Dan) : ";
                        k.SapXepDTB();
                        k.XuatDS();
                    }
			         else{
                       cout<<"\\t\t\t\tnNhap DS nhan vien truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
                
            case 7:
                
                   
            case 8:
            	if(daNhap){
                       cout<<"\n\t\t\t\t\tSap xep Diem TB  (Tang Dan) : ";
                        k.SapXepName();
                        k.XuatDS();
                    }
			         else{
                       cout<<"\\t\t\t\tnNhap DS nhan vien truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
                
    
               
            case 0:
               
            default:
                cout << "\n\t\t\t\tKhong co chuc nang nay!";
                cout << "\n\t\t\t\tHay chon chuc nang trong hop menu.";
                break;
        }
    }
}
int main(){
	system("color B4");
	menu();
}
