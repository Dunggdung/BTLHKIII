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
        void XuatThongTinChung(){                                                         //Them xuat thong tin chung trong class danh sach
            cout<<"\t\t\t\t\t THONG TIN HOC SINH \n"<<endl;
   	    cout<<"\t\t"<<setw(15)<<left<<"STT "<<setw(15)<<left<<"Ten"<<setw(15)<<left<<"Dia Chi"<<setw(15)<<left<<"MSHS"<<setw(15)<<left<<"Ngay Sinh"<<setw(15)<<left<<"Toan "<<setw(15)<<left<<"Ly"<<setw(15)<<left<<"Van"<<setw(15)<<left<<"Su"<<setw(15)<<left<<"Dia"<<endl;
   	    cout<<"\t\t"<<setfill('-')<<setw(140)<<"-";
        getch();
        }       
        void Xuat(){
            void XuatThongTinChung();
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
