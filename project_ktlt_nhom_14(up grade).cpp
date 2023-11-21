//Dường dẫn file danh sach: "D:\\Code cpp\\danhsach.txt"
//Hướng dẫn sử dụng:
//Tạo 1 file "danhsach.txt" trong folder "Code cpp" nằm trong ổ D:
//Tạo thêm 1 file "taikhoan.txt" cùng vị trí với file "danhsach.txt"
//MSGV có dạng: 123.4566.7899 dùng để cài lại mật khẩu

#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

class sv{
	private:

	int mssv,no;
	double CPA = 0;
	string lop, ns,gender,name;

	public:
	void in(){//ham in ra sinh vien
		cout<<"____________________________________________________________________\n";
		cout<<"Ten sinh vien: "<<name<<endl;
		cout<<"MSSV: "<<mssv<<endl;
		cout<<"Lop: "<<lop<<endl;
		cout<<"Ngay sinh: "<<ns<<endl;
		cout<<"Gioi tinh: "<<gender<<endl;
		cout<<"CPA: "<<fixed<<setprecision(2)<<CPA<<endl;
		cout<<"So tin sv con no: "<<no<<endl;
		cout<<"____________________________________________________________________\n";
	}
	
	void nhap(){//ham nhap vao sinh vien
		cout<<"Nhap ho ten sinh vien : ";
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		getline(cin,name);
		chuanhoaname();
		cout<<"Nhap ma so sinh vien (so nguyen): ";
		cin>> mssv;
		cout<<"Nhap lop sv: ";
		cin.ignore();
		getline(cin,lop);
		cout<<"Nhap vao ngay sinh: ";
		getline(cin,ns);
		cout<<"Nhap vao gioi tinh: "; 
		getline(cin,gender);
		cout<<"Nhap vao CPA: "; cin>> CPA;
		cout<<"Nhap vao so tin no: "; cin>>no;
	}	

	void chuanhoaname(){
		if(! name.empty() && name[0]==' '){
			name.erase( name.begin());
		}
	}

	void setname(string str){
		name =str;
	}

	void setmssv(int a) {
		mssv = a;
	}

	void setlop(string str){
		lop =str;
	}

	void setns(string str){
		ns = str;
	}

	void setgender(string str){
		gender = str;
	}

	void setcpa(double a){
		CPA = a;
	}

	void setno(int a){
		no = a;
	}

	string getname(){
		return name;
	}

	int getmssv(){
		return mssv;
	}

	string getlop(){
		return lop;
	}

	string getns(){
		return ns;
	}

	string getgender(){
		return gender;
	}

	double getcpa(){
		return CPA;
	}

	int getno(){
		return no;
	}
};

class taikhoan{
	private:
	string tk, msgv, mk;

	public:
	void settk(string str){
		tk = str;
	}

	void setmsgv(string str){
		msgv = str;
	}

	void setmk(string str){
		mk = str;
	}

	string gettk(){
		return tk;
	}

	string getmk(){
		return mk;
	}

	string getmsgv(){
		return msgv;
	}
};
	
void inds(sv arr[],int n){//ham in toan bo danh sach
	cout<<"------------------------DANH SACH SINH VIEN-------------------------\n";	
	for(int i=0;i<n;i++){
		cout<<"\nSTT "<<i+1<<endl;
		arr[i].in();
	}
	cout<<"\n--------------------------------------------------------------------\n";
}

void timmssv(sv arr[], int n){//ham tim sv theo mssv
	int msct;
	cout<<"\nNhap ma so sinh vien can tim: "; 
	cin.ignore();
	cin>> msct;
	bool found=false;
	for(int i=0;i<n;i++){
		if(msct== arr[i].getmssv()){
			arr[i].in();
			found=true;
		}
	}
	if(found==false){
		cout<<"\nKhong tim thay!\n";
	}
}

void timlop(sv arr[], int n){//ham tim sv theo lop
	string loptim;
	cout<<"\nNhap lop can tim: "; 
	cin.ignore();
	getline(cin,loptim);
	bool found=false;
	for(int i=0;i<n;i++){
		if(loptim== arr[i].getlop()){
			arr[i].in();
			found=true;
		}
	}
	if(found==false){
		cout<<"\nKhong tim thay!\n";
	}
}

void lietkecpa(sv arr[],int n){//ham liet ke sv co cpa gioi tro len
	vector<sv> v;
	for(int i=0;i<n;i++){
		if(arr[i].getcpa()>=3.2){
			v.push_back(arr[i]);
		}
	}
	for(sv x: v){
		x.in();
	}
}

void lietkecc3(sv arr[],int n){//ham liet ke sv dang canh cao muc 3
	vector<sv> vcc3;
	for(int i=0;i<n;i++){
		if(arr[i].getno()>=24){
			vcc3.push_back(arr[i]);
		}
	}
	for(sv x: vcc3){
		x.in();
	}
}

vector<string> chuanhoa(string name){//loai bo space o ten va dua ten len dau de so sanh
	stringstream ss(name);
	vector<string> v;
	string word;
	while(getline(ss,word,' ')){
		v.push_back(word);
	}
	v.insert(v.begin(),word);
	return v;
}

bool cmp(sv a, sv b){//so sanh ten va tra ve ten a<b
	vector<string> name1= chuanhoa(a.getname());
	vector<string> name2= chuanhoa(b.getname());
	if(name1.back() != name2.back()){
		return name1.back()<name2.back();
	}
	int len1=name1.size(), len2=name2.size();
	for(int i=0; i< min(len1,len2);i++){
		if(name1[i] != name2[i]){
			return name1[i]<name2[i];
		}
	}
	return name1<name2;
}

void sapxep(sv arr[],int n){//sap xep dua tren ham co san
	sort(arr,arr+n,cmp);
}

void sua(sv arr[],int n){
    int stt,option;
    cout<<"Nhap vao stt cua sinh vien muon sua: ";
    cin>>stt;
	if(stt>n){
		cout<<"\nVuot qua so sinh vien trong dach sach\n"<<endl;
	}else{
		cout<<"\n1. Sua ten"<<endl;
		cout<<"2. Sua mssv"<<endl;
		cout<<"3. Sua lop sinh vien"<<endl;
		cout<<"4. Sua ngay sinh"<<endl;
		cout<<"5. Sua gioi tinh"<<endl;
		cout<<"6. Sua CPA"<<endl;
		cout<<"7. Sua so tin no"<<endl;
		cout<<"0. Thoat"<<endl;
		cout<<"\nNhap vao lua chon: ";
		cin>>option;
		if(option==1){
			cout<<"Nhap ho ten sinh vien : ";
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			string str;
			getline(cin, str);
			arr[stt-1].setname(str);
			arr[stt-1].chuanhoaname();
		}else if(option==2){
			cout<<"Nhap vao MSSV: ";
			int a;
			cin>> a;
			arr[stt-1].setmssv(a);
		}else if(option==3){
			cout<<"Nhap lop sv: ";
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			string str;
			getline(cin,str);
			arr[stt-1].setlop(str);
		}else if(option==4){
			cout<<"Nhap vao ngay sinh: ";
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			string str;
			getline(cin, str);
			arr[stt-1].setns(str);
		}else if(option==5){
			cout<<"Nhap vao gioi tinh: "; 
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			string str;
		 	getline(cin,str);
			arr[stt-1].setgender(str);
		}else if(option==6){
			cout<<"Nhap vao CPA: ";
			double a;
			cin>>a;
			arr[stt-1].setcpa(a);
		}else if(option==7){
			cout<<"Nhap vao so tin con no: ";
			int a;
			cin>>a;
			arr[stt-1].setno(a);
		}else {
			cout<<"Da thoat khoi chuc nang sua!"<<endl;
		}
	}
}

int main(){
	sv arr[1000];
	taikhoan tkgv[20];
	int sotk=0;
	int quyen;
	int isgv;
	cout<<"Nhap vao lua chon"<<endl;
	cout<<"1: Sinh vien"<<endl;
	cout<<"2: Giang vien"<<endl;
	cout<<"0: Thoat"<<endl;
	cin>>quyen;

	if (quyen==1){
		isgv=0;

	}else if(quyen==2){
		ifstream doctk("D:\\Code cpp\\taikhoan.txt");
		if(doctk.fail()){
			cout<<"Mo tep tk that bai!"<<endl;
			return -2;
		}
		string str;
		while(!doctk.eof()){
			getline(doctk,str);
			tkgv[sotk].settk(str);
			getline(doctk,str);
			tkgv[sotk].setmsgv(str);
			getline(doctk,str);
			tkgv[sotk].setmk(str);
			sotk++;
		}
		doctk.close();
		sotk--;
		cout<<"Nhap vao lua chon"<<endl;
		cout<<"1. Dang nhap tai khoan giang vien"<<endl;
		cout<<"2. Dang ky tai khoan giang vien"<<endl;
		cout<<"3. Doi mat khau"<<endl;
		cout<<"4. Su dung voi quyen la sinh vien"<<endl;
		cout<<"0. Thoat"<<endl;
		int lctk;
		cin>>lctk;

		if(lctk==0){
			return 0;

		}else if(lctk==1){
			int kiemtra=0;
			string kttk, ktmk;
			while(kiemtra==0){
				cout<<"Nhap tai khoan: ";
				cin.ignore();
				getline(cin,kttk);
				cout<<"Nhap mat khau: ";

				while(1){
					char ch = _getch();
					if(ch==13){
						break;
					}else if(ch==8){
						if(!ktmk.empty()){
							cout<<"\b \b";
							ktmk.pop_back();
						}else{
							continue;
						}
					}else{
						cout<<"*";
						ktmk+=ch;
					}
				}

				for(int i=0; i<sotk; i++) {
					if((kttk==tkgv[i].gettk())&&(ktmk==tkgv[i].getmk())){
						kiemtra =1;
					}
				}

				if(kiemtra){
					isgv=1;
				}else{
					cout<<"\nTai khoan hoac mat khau khong dung."<<endl;
					int thoatdntk;
					cout<<"Nhap 0 de thoat, 1 de dang nhap lai"<<endl;
					cin>>thoatdntk;
					if(thoatdntk==0){
						return 0;
					}
				}
			}
		}else if(lctk==2){
			string dktk, dkmsgv, dkmk, xnmk;
			cout<<"Nhap tai khoan: ";
			cin.ignore();
			getline(cin,dktk);
			cout<<"Nhap ma so giang vien: ";

			while(1){
				char ch = _getch();
				if(ch==13){
					regex kiemtramsgv("[0-9]{3}\\.[0-9]{4}\\.[0-9]{4}");
					if(regex_match(dkmsgv, kiemtramsgv)){
						break;
					}else{
						cout<<"\nMa so giang vien khong hop le!";
						return 0;
					}
				}else if(ch==8){
					if(!dkmsgv.empty()){
						cout<<"\b \b";
						dkmsgv.pop_back();
					}else{
						continue;
					}
				}else{
					cout<<"*";
					dkmsgv+=ch;
				}
			}
			cout<<"\nNhap mat khau: ";

			while(1){
				char ch = _getch();
				if(ch==13){
					if(dkmk.length()>7){
						break;
					}else{
						cout<<"Mat khau qua yeu!"<<endl;
						cout<<"Tao tai khoan that bai"<<endl;
						return 0;
					}
				}else if(ch==8){
					if(!dkmk.empty()){
						cout<<"\b \b";
						dkmk.pop_back();
					}else{
						continue;
					}
				}else{
					cout<<"*";
					dkmk+=ch;
				}
			}
			cout<<"\nXac nhan mat khau: ";

			while(1){
				char ch = _getch();
				if(ch==13){
					if(dkmk==xnmk){
						break;
					}else{
						cout<<"Mat khau xac nhan khong chinh xac"<<endl;
						cout<<"Tao tai khoan that bai"<<endl;
						return 0;
					}
				}else if(ch==8){
					if(!xnmk.empty()){
						cout<<"\b \b";
						xnmk.pop_back();
					}else{
						continue;
					}
				}else{
					cout<<"*";
					xnmk+=ch;
				}
			}
			tkgv[sotk].settk(dktk);
			tkgv[sotk].setmsgv(dkmsgv);
			tkgv[sotk].setmk(dkmk);
			ofstream ghitk("D:\\Code cpp\\taikhoan.txt", ios::app);
			if(ghitk.fail()){
				cout<<"Mo file that bai!";
				return -1;
			}
			ghitk << tkgv[sotk].gettk()<<endl;
			ghitk << tkgv[sotk].getmsgv()<<endl;
			ghitk << tkgv[sotk].getmk()<<endl;
			ghitk.close();
			cout<<"Tao tai khoan thanh cong!"<<endl;
			sotk++;
			isgv=1;

		}else if(lctk==3){
			string tkdmk, msgvdmk;
			cout<<"Nhap vao tai khoan: ";
			cin.ignore();
			getline(cin,tkdmk);
			cout<<"Nhap vao ma so giang vien: ";
			getline(cin,msgvdmk);
			int checkdmk=0, shtk;

			for(int i=0; i< sotk; i++){
				if((tkdmk==tkgv[i].gettk())&&(msgvdmk==tkgv[i].getmsgv())){
					checkdmk=1;
					shtk=i;
					break;
				}
			}

			if(checkdmk){
				string dkmkm, xnmkm;
				cout<<"\nNhap mat khau moi: ";
				while(1){
					char ch = _getch();
					if(ch==13){
						if(dkmkm.length()>7){
							break;
						}else{
							cout<<"Mat khau qua yeu!"<<endl;
							cout<<"Tao tai khoan that bai"<<endl;
							return 0;
						}
					}else if(ch==8){
						if(!dkmkm.empty()){
							cout<<"\b \b";
							dkmkm.pop_back();
						}else{
							continue;
						}
					}else{
						cout<<"*";
						dkmkm+=ch;
					}
				}
				cout<<"\nXac nhan mat khau moi: ";

				while(1){
					char ch = _getch();
					if(ch==13){
						if(dkmkm==xnmkm){
							break;
						}else{
							cout<<"Mat khau xac nhan khong chinh xac"<<endl;
							cout<<"Tao tai khoan that bai"<<endl;
							return 0;
						}
					}else if(ch==8){
						if(!xnmkm.empty()){
							cout<<"\b \b";
							xnmkm.pop_back();
						}else{
							continue;
						}
					}else{
						cout<<"*";
						xnmkm+=ch;
					}
				}

				tkgv[shtk].setmk(dkmkm);
				ofstream ghitk("D:\\Code cpp\\taikhoan.txt");
				if(ghitk.fail()){
					cout<<"Mo tep tai khoan that bai"<<endl;
					return -1;
				}

				for(int i=0; i<sotk; i++){
					ghitk << tkgv[i].gettk() << endl;
					ghitk << tkgv[i].getmsgv() << endl;
					ghitk << tkgv[i].getmk() << endl;
				}
				ghitk.close();
				cout<<"\nDoi mat khau thanh cong."<<endl;
				cout<<"Chay lai de dang nhap"<<endl;
				return 0;

			}else{
				cout<<"Ma so giang vien hoac tai khoan khong chinh xac"<<endl;
				cout<<"Doi mat khau that bai"<<endl;
				return 0;
			}

		}else if(lctk==4){
			isgv=0;

		}else{
			return 0;
		}

	}else{
		return 0;
	}

	int sosv=0;
	ifstream tepdoc("D:\\Code cpp\\danhsach.txt");
	if(tepdoc.fail()){
		cout<<"Mo tep doc that bai!";
		return -1;
	}
	string str;
	int a;
	double b;
	while(!tepdoc.eof()){
		getline(tepdoc,str);
		arr[sosv].setname(str);
		tepdoc>>a;
		arr[sosv].setmssv(a);
		tepdoc.ignore(numeric_limits<streamsize>::max(),'\n');
		getline(tepdoc,str);
		arr[sosv].setlop(str);
		getline(tepdoc,str);
		arr[sosv].setns(str);
		getline(tepdoc,str);
		arr[sosv].setgender(str);
		tepdoc>>b;
		arr[sosv].setcpa(b);
		tepdoc.ignore(numeric_limits<streamsize>::max(),'\n');
		tepdoc>>a;
		arr[sosv].setno(a);
		tepdoc.ignore(numeric_limits<streamsize>::max(),'\n');
		sosv++;
	}
	tepdoc.close();
	sosv--;
	int luachon;
	system("cls");

	if(isgv){
		while(1){
			cout<<"=============================== MENU ==============================="<<endl;
			cout<<"1. In ra toan bo danh sach."<<endl;
			cout<<"2. Nhap them sinh vien vao danh sach."<<endl;
			cout<<"3. Tim sinh vien theo MSSV."<<endl;
			cout<<"4. Tim sinh vien theo lop."<<endl;
			cout<<"5. Sap xep danh sach theo bang chu cai."<<endl;
			cout<<"6. Xoa sinh vien."<<endl;
			cout<<"7. Liet ke sinh vien co CPA o muc gioi tro len (CPA >= 3.2)."<<endl;
			cout<<"8. Liet ke sinh vien dang bi canh cao hoc tap muc 3."<<endl;
			cout<<"9. Sua thong tin sinh vien."<<endl;
			cout<<"10. Clear screen."<<endl;
			cout<<"0. Thoat."<<endl;
			cout<<"\nNhap vao lua chon cua ban: "; cin>> luachon;

		if(luachon==0){
			break;

		}else if(luachon==1){
			inds(arr,sosv);

		}else if(luachon==2){
			ofstream tepghi("D:\\Code cpp\\danhsach.txt", ios::app);
			if(tepghi.fail()){
				cout<<"Mo file that bai!";
				return -1;
			}
			arr[sosv].nhap();
			tepghi << arr[sosv].getname() <<endl;
			tepghi << arr[sosv].getmssv() <<endl;
			tepghi << arr[sosv].getlop() <<endl;
			tepghi << arr[sosv].getns() <<endl;
			tepghi << arr[sosv].getgender() <<endl;
			tepghi << arr[sosv].getcpa() <<endl;
			tepghi << arr[sosv].getno() <<endl;
			tepghi.close();
			sosv++;

		}else if(luachon==3){
			timmssv(arr,sosv);

		}else if(luachon==4){
			timlop(arr, sosv);

		}else if(luachon==5){
			sapxep(arr,sosv);
			ofstream tepghi("D:\\Code cpp\\danhsach.txt");
			if(tepghi.fail()){
				cout<<"Mo file that bai!";
				return -1;
			}

			for(int i=0;i<sosv;i++){
				tepghi << arr[i].getname() <<endl;
				tepghi << arr[i].getmssv() <<endl;
				tepghi << arr[i].getlop() <<endl;
				tepghi << arr[i].getns() <<endl;
				tepghi << arr[i].getgender() <<endl;
				tepghi << arr[i].getcpa() <<endl;
				tepghi << arr[i].getno() <<endl;
			}
			tepghi.close();
			cout<<"\nSap xep thanh cong!\n"<<endl;

		}else if(luachon==6){
			cout<<"\nNhap MSSV cua sv muon xoa: ";
			int msxoa;
			cin>> msxoa ;
			int check=1;

			for(int i=0;i<sosv;i++){
				if(msxoa==arr[i].getmssv()){
					for(int j=i;j<sosv;j++){
						arr[j]=arr[j+1];
					}
					sosv--;
					ofstream tepghi("D:\\Code cpp\\danhsach.txt");
					if(tepghi.fail()){
						cout<<"Mo file that bai!";
						return -1;
					}
					for(int i=0;i<sosv;i++){
						tepghi << arr[i].getname() <<endl;
						tepghi << arr[i].getmssv() <<endl;
						tepghi << arr[i].getlop() <<endl;
						tepghi << arr[i].getns() <<endl;
						tepghi << arr[i].getgender() <<endl;
						tepghi << arr[i].getcpa() <<endl;
						tepghi << arr[i].getno() <<endl;
					}
					tepghi.close();
					cout<<"\nXoa thanh cong!\n"<<endl;
					check=0;
				}
			}
			if(check){
				cout<<"\nKhong tim thay sinh vien can xoa!\n"<<endl;
			}

		}else if(luachon==7){
			lietkecpa(arr,sosv);

		}else if(luachon==8){
			lietkecc3(arr,sosv);

		}else if(luachon==9){
			sua(arr,sosv);
			ofstream tepghi("D:\\Code cpp\\danhsach.txt");
			if(tepghi.fail()){
				cout<<"Mo file de sua that bai!";
				return -1;
			}
			for(int i=0;i<sosv;i++){
				tepghi << arr[i].getname() <<endl;
				tepghi << arr[i].getmssv() <<endl;
				tepghi << arr[i].getlop() <<endl;
				tepghi << arr[i].getns() <<endl;
				tepghi << arr[i].getgender() <<endl;
				tepghi << arr[i].getcpa() <<endl;
				tepghi << arr[i].getno() <<endl;
			}
			tepghi.close();
			cout<<"Hoan tat!"<<endl;

		}else if(luachon==10){
			system("cls");
		}
		cout<<"Danh sach co "<<sosv <<" sinh vien!"<<endl;
		}
		return 0;

	}else{

		while(1){
		cout<<"=============================== MENU ==============================="<<endl;
		cout<<"1. In ra toan bo danh sach."<<endl;
		cout<<"2. Tim sinh vien theo MSSV."<<endl;
		cout<<"3. Tim sinh vien theo lop."<<endl;
		cout<<"4. Sap xep danh sach theo bang chu cai."<<endl;
		cout<<"5. Liet ke sinh vien co CPA o muc gioi tro len (CPA >= 3.2)."<<endl;
		cout<<"6. Liet ke sinh vien dang bi canh cao hoc tap muc 3."<<endl;
		cout<<"7. Clear screen."<<endl;
		cout<<"0. Thoat."<<endl;
		cout<<"\nNhap vao lua chon cua ban: "; cin>> luachon;
		
	if(luachon==0){
		break;

	}else if(luachon==1){
		inds(arr,sosv);

	}else if(luachon==2){
		timmssv(arr,sosv);

	}else if(luachon==3){
		timlop(arr, sosv);

	}else if(luachon==4){
		sapxep(arr,sosv);
		ofstream tepghi("D:\\Code cpp\\danhsach.txt");
		if(tepghi.fail()){
			cout<<"Mo file that bai!";
			return -1;
		}
		for(int i=0;i<sosv;i++){
			tepghi << arr[i].getname() <<endl;
			tepghi << arr[i].getmssv() <<endl;
			tepghi << arr[i].getlop() <<endl;
			tepghi << arr[i].getns() <<endl;
			tepghi << arr[i].getgender() <<endl;
			tepghi << arr[i].getcpa() <<endl;
			tepghi << arr[i].getno() <<endl;
		}
		tepghi.close();
		cout<<"\nSap xep thanh cong!\n"<<endl;

	}else if(luachon==5){
		lietkecpa(arr,sosv);

	}else if(luachon==6){
		lietkecc3(arr,sosv);
		
	}else if(luachon==7){
		system("cls");
	}
	cout<<"Danh sach co "<<sosv <<" sinh vien!"<<endl;
	}
	return 0;
	}
}