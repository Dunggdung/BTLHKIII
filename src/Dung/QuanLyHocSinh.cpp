#include<iostream>
#include<iomanip>// can cinh do rong
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<vector>
#include<algorithm>// sort dùng quick sort kết hợp merge nên phải dùng thư viện này
using namespace std;
#include<iostream>
using namespace std;

class  NgaySinh{
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
NgaySinh::~NgaySinh(){}
void NgaySinh::Nhap1(){ //Nhap ngay thang nam
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
    //kiem tra ngay thang
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
};
Nguoi::	Nguoi():NgaySinh(){
	this->DiaChi="";
	this->Ten="";
}
Nguoi::Nguoi(string Ten,string DiaChi):NgaySinh(Ngay,Thang,Nam){
	this->DiaChi=DiaChi;
	this->Ten=Ten;
}
Nguoi::~Nguoi(){}
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
        float diemTB();
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
float Diem::diemTB(){
    float diem;
    diem = (Toan+Ly+Hoa+Van+Su+Dia)/6;
    return diem;
}
void Diem::Nhap3() {
	Nguoi::Nhap2();
    fflush(stdin);
    cout<<setw(50)<<endl<<"\t\tNhap Diem Cua Hoc Sinh : ";
    do {
        cout<<endl<<"\t\tNhap Diem Toan: ";
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
}
void Diem:: Xuat3(){
    cout<<"\n\t\t\t\t\t  DIEM CUA HOC SINH: "<<endl;
	cout<<"\t\t"<<setw(10)<<" Toan"<<setw(10)<<"Ly "<<setw(10)<<"Hoa "<<setw(10)<<"Van "<<setw(10)<<" Su "<<setw(10)<<"Dia "<<endl;
	cout<<"\t\t"<<setfill('-');
    cout<<setw(55)<<"-"<<endl;
    cout<<setfill(' ');
	cout<<"\t\t"<<setw(10)<<Toan<<setw(10)<<Ly<<setw(10)<<Hoa<<setw(10)<<Van<<setw(10)<<Su <<setw(10)<<Dia <<endl;
	cout<<"\t\t"<<setfill('_');
    cout<<setw(70)<<"_"<<endl;
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
        string getMSHS(){
            return this->MSHS;
        }
        string getTen(){
            return this->Ten;
        }
	    void Nhap4();
	    void Xuat4();
};
int HocSinh::STT=1;
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
// void input(HocSinh s[], int n){
//     for(int i=0; i<n; i++){
//         cout<<"\n\t\t\t\t Nhap Thong Tin Cua Hoc Sinh Thu  "<<i+1<<endl;
//          s[i].Nhap4();
//     }
// }
// void print(HocSinh s[], int n){
//     for(int i=0; i<n; i++){
//         cout<<"\n\t\t\t\tThong Tin hoc sinh thu  "<<i+1<<endl;
//         s[i].Xuat4();
//     }
// }
class sosanhTen{
    public:
        bool operator() (HocSinh first, HocSinh second) {
            return first.getTen() > second.getTen();
        }    
};
class sosanhDiem{
    public:
        bool operator() (HocSinh first, HocSinh second) {
            return first.diemTB() > second.diemTB();
        }   
};
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
class DanhSach{
    private:
        vector <HocSinh> HS;
        int count;
    public:
        DanhSach(){
            HS = vector<HocSinh>();
            int count = 0;
        }
        bool TonTai (string MSHS){
            bool tim = false;
            for(auto HocSinh = HS.begin(); HocSinh != HS.end(); ++HocSinh){
                if(HocSinh->getMSHS() == MSHS){
                    tim=true;
                    break;
                }
            }
            return tim;
        }
        void Them(HocSinh hocsinh){
            if(!this->TonTai(hocsinh.getMSHS())){
                this->HS.push_back(hocsinh);// NOTE: thêm 1 học sinh vào cuối vector
                count++;//NOTE: số lượng phần tử trong vector sẽ tăng lên 1
            }else{
                cout<<"MSHS da ton tai"<<endl;
            }
        }
        void Xoa(string MSHS){
            for(auto HocSinh = HS.begin(); HocSinh != HS.end(); ++HocSinh){
                if(HocSinh->getMSHS() == MSHS){
                    HS.erase(HocSinh);
                }
            }
        }
        void Xuat(){
            for (auto HocSinh = HS.begin(); HocSinh != HS.end(); ++HocSinh) {//NOTE: đi từ đầu đến cuối vector để in từng phần tử
                HocSinh->Xuat4();
                cout<<endl;
            }
        }
       // dùng quick sort kết hợp merge hàm sort là hàm có sẵn của vector
       void sapXepTen(){
           // duyệt từ học sinh đầu đến cuối nếu trùng điều kiện sắp xếp sẽ tự đông swap
            std::sort(HS.begin(),HS.end(),sosanhTen());
        }   
        void sapXepDiemTB(){
            std::sort(HS.begin(),HS.end(),sosanhDiem());
        }
        void xepLoai (){
            for (auto HocSinh = HS.begin();HocSinh != HS.end(); ++HocSinh){
                HocSinh->Xuat4();
                xeploai(HocSinh->diemTB());
            }
        }
        
};
// void menu(int n ){
// 	//char fileName[] = "employee.txt";
// 	int chon,b, flat = 1;
// 	bool daNhap = false ;
// 	while(flat){
// 	    system("cls");
//         cout  <<"\t\t\t\t"<< "       CHUONG TRINH QUAN LY HOC SINH C/C++\n             ";
//         cout  <<"\t\t"<< "*************************MENU******************************\n";
//         cout  <<"\t\t\t"<< "**      1. Nhap Thong tin hoc sinh                       **\n";
//         cout  <<"\t\t\t"<< "**      2. Xuat thong tin hoc sinh.                      **\n";
//         cout  <<"\t\t\t"<< "**      3. Xoa hoc sinh theo ID.                         **\n";
//         cout  <<"\t\t\t"<< "**      4. Tim kiem hoc sinh theo ID.                    **\n";
//         cout  <<"\t\t\t"<< "**      5. Them 1 hoc sinh .                             **\n";  
//         cout  <<"\t\t\t"<< "**      6. Sap xep hoc sinh theo diem trung binh .       **\n";
//         cout  <<"\t\t\t"<< "**      7. Xep loai hoc sinh .                           **\n";  
//         cout  <<"\t\t\t"<< "**      8. Sap xep hoc sinh theo ten.                    **\n";
//         cout  <<"\t\t\t"<< "**      9. Thong ke hoc sinh theo tinh                   **\n";
//         cout  <<"\t\t\t"<< "**      10. Ghi danh sach hoc sinh vao file.             **\n";
//         cout  <<"\t\t\t"<< "**      0. Thoat                                         **\n";
//         cout  <<"\t\t\t"<< "***********************************************************\n";
//         cout  << "Nhap tuy chon: ";
//         cin >> chon;
//         switch(chon){
//             case 1:
//             		cout<<"\n Ban Da Chon Nhap Thong Tin  Hoc Sinh !";
// 			        input(a,n);	
// 			        cout<<"\n\t\t\t\t\t Ban da nhap thanh cong !\n";
// 			        daNhap=true;
// 		         	cout<<"\n\t\t\t\tVui long nhap phim bat ki de tiep tuc !";
// 		        	getch();
// 		        	break;
                
//             case 2:
//                     system("cls");
// 			        if(daNhap){
//                        cout<<"\n Ban Da Chon Xuat Thong Tin  Hoc Sinh!";
//                        print(a,n);
//                     }
// 			         else{
//                        cout<<"\\t\t\t\tnNhap DS hoc sinh truoc!!!!";
//                      }
//                       cout<<"\n\t\t\t\t\tBam phim bat ky de tiep tuc!";
//                       getch();
//                       break;
                   
//             case 3:
                
//             case 4:
               
//             case 5:
                
//             case 6:
                
//             case 7:
                
                   
//             case 8:
    
               
//             case 0:
               
//             default:
//                 cout << "\n\t\t\t\tKhong co chuc nang nay!";
//                 cout << "\n\t\t\t\tHay chon chuc nang trong hop menu.";
//                 //pressAnyKey();
//                 break;
//         }
//     }
// }
int main(){
	system("color B4");
    HocSinh a;
    DanhSach b = DanhSach();
    for(int i = 0; i < 3; i++){
        a.Nhap4();
        b.Them(a);
    }
    b.Xuat();
    b.Xoa("001");
    b.Xuat();
    return 0;

	// menu(n);
}