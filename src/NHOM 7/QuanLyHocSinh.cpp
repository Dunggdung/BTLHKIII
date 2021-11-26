#include<iostream>
#include<iomanip>// can cinh do rong
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include <vector>
#include <fstream>
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
         int getNgay();
         int getThang();
         int getNam();
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
NgaySinh::~NgaySinh(){}
void NgaySinh::Nhap1()
{ //Nhap ngay thang nam
    cout<<"\n\t\t\tNhap Ngay, Thang, Nam Sinh: "<<endl;
    do{
        cout<<"\t\t\t\t\tNgay: ";
        cin>>Ngay;
        cout<<"\t\t\t\t\tThang: ";
        cin>>Thang;
        if(KiemTra()==false){
            cout<<endl<<"\t\t\t\tNgay Thang Khong Hop Le !! Nhap Lai Ngay Thang!!"<<endl;
            cout<<"\n\t\t\t\t\tNgay: ";
            cin>>Ngay;
            cout<<endl<<"\t\t\t\t\tThang: ";
            cin>>Thang;
        }
    }while(KiemTra()==false);
    do{
    cout<<"\t\t\t\t\tNam: ";
    cin>>Nam;
    if(Nam > 2015 || Nam <= 2003){
        cout<<"\t\t\t\tNhap lai nam sinh!!";
        cout<<endl<<"\t\t\t\t\tNam: ";
        cin>>Nam;
    }
    }while(Nam > 2015 || Nam <= 2003);
}
bool NgaySinh::KiemTra(){
{
    //ki?m tra ng�y th�ng
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
int NgaySinh::getNgay(){
    return Ngay;
}
int NgaySinh::getThang(){
    return Thang;
}
int NgaySinh::getNam(){
    return Nam;
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
    	string getDiaChi();
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
	cout<<"\n\t\t\tNhap Ten: ";
	getline(cin,Ten);
	cout<<"\n\t\t\tNhap Dia Chi: ";
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
string Nguoi::getDiaChi(){
	return DiaChi;
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
        float getToan();
        float getLy();
        float getHoa();
        float getVan();
        float getSu();
        float getDia();
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
     cout<<setw(50)<<"\n\t\t\tNhap Diem Cua Hoc Sinh : ";
    do {
        cout<<"\n\t\t\t\t\tNhap Diem Toan: ";
	    cin >> Toan;
        if (Toan < 0.0 || Toan >10.0){
            cout <<"\t\t\t\tNhap Lai Diem Toan: ";
            cin >> Toan;
        }
    }while( Toan < 0.0 ||  Toan >10.0);
    do {
        cout<<"\t\t\t\t\tNhap Diem Ly: ";
	     cin >>  Ly;
        if ( Toan < 0.0 ||  Ly >10.0){
            cout <<"\t\t\t\tNhap Lai Diem Ly: ";
             cin >>  Ly;
        }
    }while( Ly < 0.0 ||  Ly >10.0);
    do {
        cout<<"\t\t\t\t\tNhap Diem Hoa: ";
	     cin >>  Hoa;
        if ( Hoa < 0.0 ||  Hoa >10.0){
            cout <<"\t\t\t\tNhap Lai Diem Hoa: ";
             cin >>  Hoa;
        }
    }while( Hoa < 0.0 ||  Hoa >10.0);
    do {
        cout<<"\t\t\t\t\tNhap Diem Van: ";
	     cin >>  Van;
        if ( Van < 0.0 ||  Van >10.0){
            cout <<"\t\t\t\tNhap Lai Diem Van: ";
             cin >>  Van;
        }
    }while( Van < 0.0 ||  Van >10.0);
    do {
        cout<<"\t\t\t\t\tNhap Diem Su: ";
	     cin >>  Su;
        if ( Su < 0.0 ||  Su >10.0){
            cout <<"\t\t\t\tNhap Lai Diem Su: ";
             cin >>  Su;
        }
    }while( Su < 0.0 ||  Su >10.0);
    do {
        cout<<"\t\t\t\t\tNhap Diem Dia: ";
	     cin >>  Dia;
        if ( Dia < 0.0 ||  Dia >10.0){
            cout <<"\t\t\t\tNhap Lai Diem Dia: ";
             cin >>  Dia;
        }
    }while( Dia < 0.0 ||  Dia >10.0);
     DTB=(Toan+Ly+Hoa+Van+Su+Dia)/6;
   
}
float Diem::getDTB(){
	return DTB;
}
float Diem::getToan(){
    return Toan;
}
float Diem::getLy(){
    return Ly;
}
float Diem::getHoa(){
    return Hoa;
}
float Diem::getVan(){
    return Van;
}
float Diem::getSu(){
    return Su;
}
float Diem::getDia(){
    return Dia;
}
class HocSinh: public Diem{
	private:
	  string   Lop , MSHS;
	  int STT;
    public:
    	HocSinh();
    	HocSinh( string Lop, string MSHS);
    	~HocSinh();
	    void Nhap4();
	    void Xuat4();
        void Xuat5();
	    string getMSHS();
	    void setSTT(int STT);
        int getSTT();
};
// int HocSinh::STT=0;
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
void HocSinh::setSTT(int STT){
    this->STT=STT;
}
int HocSinh::getSTT(){
    return STT;
}
void HocSinh::Xuat4(){
	// HocSinh A;
    cout<<endl<<"\t\t\t\t"<<setw(5)<<left<<STT<<setw(30)<<left<<Ten<<setw(15)<<left<<DiaChi<<setw(15)<<left<<MSHS<<left<<Ngay<<"/"<<Thang<<"/"<<setw(12)<<left<<Nam<<setw(17)<<left<<Toan<<setw(15)<<left<<Ly<<setw(15)<<left<<Hoa<<setw(15)<<left<<Van<<setw(15)<<setw(15)<<left<<Su<<setw(15)<<left<<Dia<<setw(15)<<left<<DTB<<endl;
    cout<<"\t\t\t\t"<<setfill('-')<<setw(185)<<"-"<<endl;
    cout<<setfill(' ');
}
void HocSinh::Xuat5(){
	// HocSinh A;
    cout<<endl<<"\t\t\t\t"<<setw(5)<<left<<STT<<setw(30)<<left<<Ten<<setw(15)<<left<<DiaChi<<setw(15)<<left<<MSHS<<left<<Ngay<<"/"<<Thang<<"/"<<setw(12)<<left<<Nam<<setw(17)<<left<<Toan<<setw(15)<<left<<Ly<<setw(15)<<left<<Hoa<<setw(15)<<left<<Van<<setw(15)<<setw(15)<<left<<Su<<setw(15)<<left<<Dia<<setw(15)<<left<<DTB;
}
string HocSinh::getMSHS(){
	return MSHS;
}
class quanlyHS{
	  private:
	  	 vector<HocSinh *> HS;
       public:
            void NhapDS(int n);
            void XuatThongTinChung();
            void XuatThongTinChung2();
		    void XuatDS();
            void XoaHSID(string H);
            void TimKiemID(string &h);	
            void ThemHS();
            void SapXepDTB();
            void SapXepName();
            void XepLoaiHS(); 	
            void exportHS(ofstream &file); 
            bool check (string h);
};
bool quanlyHS::check (string h){
    for (int i=0; i< this->HS.size();i++){
        if (h == HS.at(i)->getMSHS())
         return true;
    }
    return false;
}
 void quanlyHS::NhapDS(int n){
 	  HocSinh *hs;
  	 for(int i=0; i< n; i++){
        cout<<"\n\t\tNhap Thong Tin Cua Hoc Sinh Thu "<<i+1<<endl;
             hs= new HocSinh;
             do {
                 hs->Nhap4();
                 if (check(hs->getMSHS())){
                     cout<<"Ma So Hoc Sinh Da Ton Tai !"<<endl;
                     cout <<"Vui Long Nhap Lai Thong Tin!"<<endl;
                 }
             }while (check(hs->getMSHS()));
             HS.push_back(hs);
             cout<<"\t\t"<<setw(70)<<setfill('-')<<"-"<<endl;
            cout<<setfill(' ');
    }	
 }
 void quanlyHS::XuatThongTinChung(){
        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\tTHONG TIN HOC SINH \n"<<endl;
   	    cout<<"\t\t\t\t"<<setw(5)<<left<<"STT "<<setw(30)<<left<<"Ten"<<setw(15)<<left<<"Dia Chi"<<setw(15)<<left<<"MSHS"<<setw(15)<<left<<"Ngay Sinh"<<setw(18)<<left<<"Toan "<<setw(15)<<left<<"Ly"<<setw(15)<<left<<"Hoa"<<setw(15)<<left<<"Van"<<setw(15)<<left<<"Su"<<setw(15)<<left<<"Dia"<<setw(15)<<"DTB"<<endl;
   	    cout<<"\t\t\t\t"<<setw(185)<<setfill('_')<<"_"<<endl;
        cout<<setfill(' ');
}    
 void quanlyHS::XuatThongTinChung2(){
        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\tTHONG TIN HOC SINH \n"<<endl;
   	    cout<<"\t\t\t\t"<<setw(5)<<left<<"STT "<<setw(30)<<left<<"Ten"<<setw(15)<<left<<"Dia Chi"<<setw(15)<<left<<"MSHS"<<setw(15)<<left<<"Ngay Sinh"<<setw(18)<<left<<"Toan "<<setw(15)<<left<<"Ly"<<setw(15)<<left<<"Hoa"<<setw(15)<<left<<"Van"<<setw(15)<<left<<"Su"<<setw(15)<<left<<"Dia"<<setw(15)<<"DTB"<<setw(15)<<left<<"Xep Loai"<<endl;
   	    cout<<"\t\t\t\t"<<setw(195)<<setfill('_')<<"_"<<endl;
        cout<<setfill(' ');
}    
void quanlyHS:: XuatDS(){
	 int stt = 1;
    XuatThongTinChung();
	for(int i = 0 ;i < this->HS.size();i++){
		this->HS.at(i)->setSTT(stt);
		this->HS.at(i)->Xuat4();
		 stt++;
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
                  break;
        }
        else {
            cout <<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tKHONG TIM THAY ID CAN XOA"<<endl;
        }
    }    
}
void quanlyHS::ThemHS(){
     HocSinh *hs;
    for(int i = 0 ;i < this->HS.size();i++){
        cout<<endl;
        hs= new HocSinh;
        do {
                 hs->Nhap4();
                 if (check(hs->getMSHS())){
                     cout<<"Ma So Hoc Sinh Da Ton Tai !"<<endl;
                     cout <<"Vui Long Nhap Lai Thong Tin!"<<endl;
                 }
        }while (check(hs->getMSHS()));
        hs->Nhap4();
        HS.push_back(hs);
        break;    
    }
}

     
void quanlyHS::XepLoaiHS(){
    XuatThongTinChung2();
	for(int i = 0 ;i < this->HS.size();i++){
		if(HS.at(i)->getDTB() >= 8){
			HS.at(i)->Xuat5(); cout<<setw(15)<<left<<"GIOI \n";
            cout<<"\t\t\t"<<setfill('-')<<setw(195)<<"-"<<endl;
            cout<<setfill(' ');
		}
		else if( HS.at(i)->getDTB()<8 && HS.at(i)->getDTB() >= 6.5 ){
			HS.at(i)->Xuat5(); cout<<setw(15)<<left<<"KHA \n";
            cout<<"\t\t\t"<<setfill('-')<<setw(195)<<"-"<<endl;
            cout<<setfill(' ');
		}   
		else if( HS.at(i)->getDTB() <6.5 && HS.at(i)->getDTB() >= 5){
			HS.at(i)->Xuat5(); cout<<setw(15)<<left<<"TRUNG BINH \n";
            cout<<"\t\t\t"<<setfill('-')<<setw(195)<<"-"<<endl;
            cout<<setfill(' ');
		}   
		
		else{
			HS.at(i)->Xuat5(); cout<<setw(15)<<left<<"YEU \n";
            cout<<"\t\t\t"<<setfill('-')<<setw(195)<<"-"<<endl;
            cout<<setfill(' ');
		}  
		
	}
}
void quanlyHS::TimKiemID(string &h){
    XuatThongTinChung();
     for(int i = 0 ;i < this->HS.size();i++){
		if(HS.at(i)->getMSHS()==h){
		   	HS.at(i)->Xuat4();
		   	break;
		}
	}
	 for(int i = 0 ;i < this->HS.size();i++){
		if(HS.at(i)->getMSHS()!=h){
		   	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tKHONG CO MSHS CAN TIM ";
		   	break;
		}
	}
}
void quanlyHS::exportHS(ofstream &file){
    int stt = 1;
    file<<endl<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTHONG TIN HOC SINH \n"<<endl;
   	file<<"\t\t\t\t"<<setw(5)<<left<<"STT "<<setw(30)<<left<<"Ten"<<setw(15)<<left<<"Dia Chi"<<setw(15)<<left<<"MSHS"<<setw(15)<<left<<"Ngay Sinh"<<setw(18)<<left<<"Toan "<<setw(15)<<left<<"Ly"<<setw(15)<<left<<"Hoa"<<setw(15)<<left<<"Van"<<setw(15)<<left<<"Su"<<setw(15)<<left<<"Dia"<<setw(15)<<"DTB"<<endl;
   	file<<"\t\t\t\t"<<setw(185)<<setfill('_')<<"_"<<endl;
    file<<setfill(' ');
	for(int i = 0 ;i < this->HS.size();i++){
		this->HS.at(i)->setSTT(stt);
		file<<endl<<"\t\t\t\t"<<setw(5)<<left<<HS.at(i)->getSTT()<<setw(30)<<left<<HS.at(i)->getTen()<<setw(15)<<left<<HS.at(i)->getDiaChi()<<setw(15)<<left<<HS.at(i)->getMSHS()<<left<<HS.at(i)->getNgay()<<"/"<<HS.at(i)->getThang()<<"/"<<setw(12)<<left<<HS.at(i)->getNam()<<setw(15)<<left<<HS.at(i)->getToan()<<setw(15)<<left<<HS.at(i)->getLy()<<setw(15)<<left<<HS.at(i)->getHoa()<<setw(15)<<left<<HS.at(i)->getVan()<<setw(15)<<setw(15)<<left<<HS.at(i)->getSu()<<setw(15)<<left<<HS.at(i)->getDia()<<setw(15)<<left<<HS.at(i)->getDTB()<<endl;
        file<<"\t\t\t\t"<<setfill('-')<<setw(185)<<"-"<<endl;
        file<<setfill(' ');
		stt++;
	}
    file.close();
}	
void menu(){
    int n;
    do{
		cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tNhap So Luong Hoc Sinh : ";
		cin>>n;
	}while(n<=0);
	quanlyHS k;
	HocSinh h;
    ofstream file("./data.txt");
	int chon,b, flat = 1;
	bool daNhap = false ;
	while(flat){
	    system("cls");
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t                   CHUONG TRINH QUAN LY HOC SINH C/C++\n";
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "*******************************MENU********************************\n";
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "**              1. Nhap thong tin hoc sinh                       **\n";
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "**              2. Xuat thong tin hoc sinh.                      **\n";
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "**              3. Xoa hoc sinh boi ID.                          **\n";
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "**              4. Tim kiem hoc sinh theo ID.                    **\n";
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "**              5. Them 1 hoc sinh.                              **\n";  
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "**              6. Sap xep hoc sinh theo diem trung binh.        **\n";
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "**              7. Xep loai hoc sinh.                            **\n";  
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "**              8. Sap xep hoc sinh theo ten.                    **\n";
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "**              9. Ghi danh sach hoc sinh vao file.              **\n";
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "**              0. Thoat.                                        **\n";
        cout  <<"\t\t\t\t\t\t\t\t\t\t\t"<< "*******************************************************************\n";
        cout  << "\t\t\t\t\t\t\t\t\t\t\t                         Nhap tuy chon: ";
        cin >> chon;
        switch(chon){
            case 1:
                    system("cls");
            		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBan Da Chon Nhap Thong Tin Hoc Sinh !";
			        k.NhapDS(n);
			        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBan da nhap thanh cong !\n";
			        daNhap=true;
		         	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBam phim bat ki de tiep tuc !";
		        	getch();
		        	break;
                
            case 2: 
                     system("cls");
			        if(daNhap){
                       cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBan Da Chon Xuat Thong Tin Hoc Sinh!";
                      k.XuatDS();
                    }
			         else{
                       cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tNhap danh sach hoc sinh truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
                   
            case 3:
            	     system("cls");
			        if(daNhap){
                     cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t     Ban  chon Xoa 1 Hoc Sinh !";
                     string h;
                     cout<<"\n\t\t\t\t Nhap Ma id can xoa ";
                     fflush(stdin);
                     getline(cin,h);
                     k.XoaHSID(h);
                     cout<<"\n\t\t\t\t THONG TIN CON LAI SAU KHI XOA LA  : "<<endl;
                     k.XuatDS();
                    }
			         else{
                       cout<<"\n\t\t\t\t\t\t\t\tNhap danh sach hoc sinh truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
                
            case 4:
            	     system("cls");
			         if(daNhap){
                     cout<<"\n\t\t\t\t Ban Chon tim hoc sinh bang id  :";
                     string x;
                     cout<<"\n\t\t\t\t Nhap ID can tim  : ";
                     fflush(stdin);
                     getline(cin,x);
                     k.TimKiemID(x);
                    }
			         else{
                       cout<<"\n\t\t\t\t\t\t\t\tNhap danh sach hoc sinh truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
                   
            case 5:
            	    system("cls");
			        if(daNhap){
                       cout<<"\n\n\t\t\t\t Ban Da Chon Them 1 Hoc Sinh ( vao cuoi danh sach): " ;                 
						k.ThemHS();
                        k.XuatDS();
                    }
			         else{
                       cout<<"\t\t\t\t\t\t\t\tNhap Danh Sach Hoc Sinh Truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBam Phim Bat Ky De Tiep Tuc!";
                      getch();
                      break;
            	 
                
            case 6:
            	 system("cls");
            	 if(daNhap){
                       cout<<"\n\t\t\t\tSap xep Diem TB  (Tang Dan) : ";
                        k.SapXepDTB();
                        k.XuatDS();
                    }
			         else{
                       cout<<"\t\t\t\t\t\t\t\tNhap danh sach hoc sinh truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
                
            case 7:
            	    system("cls");
			        if(daNhap){
                       cout<<"\n\n\t\t\t\t Ban da chon xep loai hoc sinh: " ;  
					   k.XepLoaiHS();               
				    }
			         else{
                       cout<<"\\t\t\t\t\t\t\t\tNhap danh sach hoc sinh truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
                
                   
            case 8:
            	 system("cls");
            	if(daNhap){
                       cout<<"\n\t\t\t\t\t\t\t\t\tSap xep theo Ten  (Tang Dan) : ";
                        k.SapXepName();
                        k.XuatDS();
                    }
			         else{
                       cout<<"\t\t\t\t\t\t\t\tNhap danh sach hoc sinh truoc!!!!";
                     }
                      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\tBam phim bat ky de tiep tuc!";
                      getch();
                      break;
            case 9:
             	system("cls");
                k.exportHS(file);
                break;
            case 0:
		            printf("\n\t\t\t\t\t\t\t\t\t BAN DA CHON THOAT CHUONG TRINH!");
		            flat = 0;
		            break;
               
            default:
                 cout << "\n\t\t\t\t\t\t\t\tKhong co chuc nang nay!";
                 cout << "\n\t\t\t\t\t\t\t\tHay chon chuc nang trong hop menu.";
                 break;
                 getch();
        }
    }
}
int main(){
	system("color B4");
	menu();
}
