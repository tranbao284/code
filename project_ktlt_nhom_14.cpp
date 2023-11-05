//duong dan file danh sach: D:\\Code cpp\\danhsach.txt
//neu chua co file thi tao 1 file "danhsach.txt" trong folder "Code cpp" nam trong o dia D:

#include<bits/stdc++.h>

using namespace std;

void chuanhoaname(string &a){
	if(! a.empty() && a[0]==' '){
		a.erase(a.begin());
	}
}

typedef struct sv{
	int mssv,no;
	double CPA = 0;
	string lop, ns,gender,name;
	
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
		chuanhoaname(name);
		cout<<"Nhap ma so sinh vien: ";
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
}sv;
	
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
		if(msct== arr[i].mssv){
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
		if(loptim== arr[i].lop){
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
		if(arr[i].CPA>=3.2){
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
		if(arr[i].no>=24){
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
	vector<string> name1= chuanhoa(a.name);
	vector<string> name2= chuanhoa(b.name);
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
			getline(cin,arr[stt-1].name);
			chuanhoaname(arr[stt-1].name);
		}else if(option==2){
			cout<<"Nhap vao MSSV: ";
			cin>>arr[stt-1].mssv;
		}else if(option==3){
			cout<<"Nhap lop sv: ";
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			getline(cin,arr[stt-1].lop);
		}else if(option==4){
			cout<<"Nhap vao ngay sinh: ";
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cin>>arr[stt-1].ns;
		}else if(option==5){
			cout<<"Nhap vao gioi tinh: "; 
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		 	getline(cin,arr[stt-1].gender);
		}else if(option==6){
			cout<<"Nhap vao CPA: ";
			cin>>arr[stt-1].CPA;
		}else if(option==7){
			cout<<"Nhap vao so tin con no: ";
			cin>>arr[stt-1].no;
		}else {
			cout<<"Da thoat khoi chuc nang sua!"<<endl;
		}
	}
}

int main(){
	sv arr[1000];
	int sosv=0;
	ifstream tepdoc("D:\\Code cpp\\danhsach.txt");
	if(tepdoc.fail()){
		cout<<"Mo tep doc that bai!";
		return -1;
	}
	while(!tepdoc.eof()){
		getline(tepdoc,arr[sosv].name);
		tepdoc>>arr[sosv].mssv;
		tepdoc.ignore(numeric_limits<streamsize>::max(),'\n');
		getline(tepdoc,arr[sosv].lop);
		getline(tepdoc,arr[sosv].ns);
		getline(tepdoc,arr[sosv].gender);
		tepdoc>>arr[sosv].CPA;
		tepdoc.ignore(numeric_limits<streamsize>::max(),'\n');
		tepdoc>>arr[sosv].no;
		tepdoc.ignore(numeric_limits<streamsize>::max(),'\n');
		sosv++;
	}
	tepdoc.close();
	sosv--;
	int luachon;
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
		tepghi << arr[sosv].name <<endl;
		tepghi << arr[sosv].mssv <<endl;
		tepghi << arr[sosv].lop <<endl;
		tepghi << arr[sosv].ns <<endl;
		tepghi << arr[sosv].gender <<endl;
		tepghi << arr[sosv].CPA <<endl;
		tepghi << arr[sosv].no<<endl;
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
			tepghi << arr[i].name <<endl;
			tepghi << arr[i].mssv <<endl;
			tepghi << arr[i].lop <<endl;
			tepghi << arr[i].ns <<endl;
			tepghi << arr[i].gender <<endl;
			tepghi << arr[i].CPA <<endl;
			tepghi << arr[i].no<<endl;
		}
		tepghi.close();
		cout<<"\nSap xep thanh cong!\n"<<endl;
	}else if(luachon==6){
		cout<<"\nNhap MSSV cua sv muon xoa: ";
		int msxoa;
		cin>> msxoa ;
		for(int i=0;i<sosv;i++){
			if(msxoa==arr[i].mssv){
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
					tepghi << arr[i].name <<endl;
					tepghi << arr[i].mssv <<endl;
					tepghi << arr[i].lop <<endl;
					tepghi << arr[i].ns <<endl;
					tepghi << arr[i].gender <<endl;
					tepghi << arr[i].CPA <<endl;
					tepghi << arr[i].no<<endl;
				}
				tepghi.close();
				cout<<"\nXoa thanh cong!\n"<<endl;
			}else{
				cout<<"\nKhong tim thay sinh vien can xoa!\n"<<endl;
			}
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
			tepghi << arr[i].name <<endl;
			tepghi << arr[i].mssv <<endl;
			tepghi << arr[i].lop <<endl;
			tepghi << arr[i].ns <<endl;
			tepghi << arr[i].gender <<endl;
			tepghi << arr[i].CPA <<endl;
			tepghi << arr[i].no<<endl;
		}
		tepghi.close();
		cout<<"Hoan tat!"<<endl;
	}else if(luachon==10){
		system("cls");
	}
	cout<<"Danh sach co "<<sosv <<" sinh vien!"<<endl;
	}
	return 0;
}