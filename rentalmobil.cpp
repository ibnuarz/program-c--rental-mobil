#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iomanip>
#include <windows.h>
#include <string>
#include <limits>
#include <stack>
#include "class/welcome.cpp"
#include "class/welcome.h"
using namespace std;


int i,j,p,temp,byk,c,cariidsewa;
long total[100], subtotal,grandtotal,bayar;
void greet();
void menu();
void mobilheader();
int login();
void menu();
void backmenu();
void matic();
void manual();
void tampildetail();
void listresv();
void listsort();
void searchidsewa();
void sortidsewa();
void editresvmenu();
void editresv();
void doneresvmenu();
void doneresv();
void waitinglist();
void exitpro();
struct mobil{
	char kodemobil[4],
	namamobil[30],
	dtmobil[4];
	int ccmobil,transmobil;
	double hargamobil,lamasewa;
};
struct penyewa{
	int idsewa;
	char alamat[100],
	nama[100],
	admin[100],
	telp[100],nik[100];
	mobil detailmobil;
};
stack<penyewa> database;
stack<penyewa> list;
penyewa dtl[100];
penyewa arr[100];
int a = 0;
time_t now = time(0);
char* tglskrng = ctime(&now);
int main(){
	login();
	menu();
}
void greet(){
	welcome view;
	view.welcomeGreet();
}
void menu(){
	Detail: 
	system("cls");
	ifstream in2("text/menu.txt");
    if(!in2) {
    cout << "Cannot open input file.\n";
    }
    char str2[10000];
    while(in2) {
        in2.getline(str2, 10000); 
        cout << endl;
        if(in2) cout << str2 << endl;
    }
    in2.close();
    while(a !=-1 ){
    cout<<"\nMasukkan Pilihan Menu Anda :  "<<endl;
    cin>>a;
	switch(a)
    {
    	case 1:
    	system("CLS");
    	inputlist : 
    	cout<<"Banyak List Id Sewa Yang Akan Di Input kan : ";
    	cin>>byk;
    	for(i=0;i<byk;i++){
    	cout<<"input list id sewa ke "<<i+1<<" : ";
		cin>>dtl[i].idsewa;
		database.push(dtl[i]);
		cout<<"Id Sewa Berhasil Di-List"<<endl;
		cout<<endl;
		}
		cout<<endl;
		backmenu();
    	break;
    	case 2:
    	system("CLS");
    	for(i=0;i<byk;i++){
    	dtl[i] = database.top();
		database.pop();
		cout<<" id sewa : "<<dtl[i].idsewa<<endl;
		cout<<" Nama ADMIN   : ";
    	cin.clear();
		cin.sync();
		gets(dtl[i].admin);
		cout<<"-------------------------------------"<<endl;
		cout<<" ISI DATA DETAIL PENYEWA"<<endl;
  		cout<<" Nama    : ";
  		cin.clear();
		cin.sync();
		gets(dtl[i].nama);
		cout<<" NIK     : ";
		cin.clear();
		cin.sync();
		gets(dtl[i].nik);
		cout<<" No. Telp: ";
		cin.clear();
		cin.sync();
		gets(dtl[i].telp);
		cout<<" Alamat  : ";
		cin.clear();
		cin.sync();
		gets(dtl[i].alamat);
		cout<<endl;
		cout<<"1. Matic"<<endl;
		cout<<"2. Manual"<<endl;
		cout<<"Jenis Transmisi : ";
		cin.clear();
		cin.sync();
		cin>>dtl[i].detailmobil.transmobil;
		
		if(dtl[i].detailmobil.transmobil==1)
		{
			goto matic;
		} 
		if(dtl[i].detailmobil.transmobil==2)
		{
			goto manual;	
		}	
		
		matic :
		system("CLS");
		mobilheader();
		cout<<"1. TOYOTA All New Agya           \tAT   1200    \t\t\tRp. 250.000,-    \t\t[PO11]\n";
		cout<<"2. TOYOTA Avanza Facelift        \tAT   1500    \t\t\tRp. 300.000,-    \t\t[PO12]\n";
      	cout<<"3. HONDA All New Brio            \tAT   1200    \t\t\tRp. 300.000,-    \t\t[PO21]\n";
      	cout<<"4. HONDA BRV         			AT   1500    \t\t\tRp. 325.000,-    \t\t[PO22]\n";
      	cout<<"5. MITSHUBISHI XPANDER         	\tAT   1500    \t\t\tRp. 350.000,-   \t\t[PO31]\n";
		goto inputdata;
		
		manual : 
		system("CLS");
		mobilheader();
		cout<<"1. TOYOTA All New Agya           \tAT   1200    \t\t\tRp. 225.000,-    \t\t[PO11]\n";
		cout<<"2. TOYOTA Avanza Facelift        \tAT   1500    \t\t\tRp. 275.000,-    \t\t[PO12]\n";
      	cout<<"3. HONDA All New Brio            \tAT   1200    \t\t\tRp. 275.000,-    \t\t[PO21]\n";
      	cout<<"4. HONDA BRV         			AT   1500    \t\t\tRp. 300.000,-    \t\t[PO22]\n";
      	cout<<"5. MITSHUBISHI XPANDER         	\tAT   1500    \t\t\tRp. 325.000,-   \t\t[PO31]\n";
		goto inputdata;
		
		inputdata :
		cout<<endl;
		cout<<" ID Sewa        : "<<dtl[i].idsewa<<endl;
		cout<<" Kode mobil     : ";cin>>dtl[i].detailmobil.kodemobil;
		cout<<" Lama Sewa      : ";cin>>dtl[i].detailmobil.lamasewa;
		
		if(strcmp(dtl[i].detailmobil.kodemobil,"PO11")==0 || strcmp(dtl[i].detailmobil.kodemobil,"po11")==0 ){
			(strcpy(dtl[i].detailmobil.namamobil,"TOYOTA All New Agya"));
         	if (dtl[i].detailmobil.transmobil==1)
  				{
					dtl[i].detailmobil.ccmobil=1200;
					dtl[i].detailmobil.hargamobil=250000;
	 			}
				else
            	{
      				dtl[i].detailmobil.ccmobil=1200;
					dtl[i].detailmobil.hargamobil=225000;
            	}
		} 
		else if (strcmp(dtl[i].detailmobil.kodemobil,"PO12")==0 || strcmp(dtl[i].detailmobil.kodemobil,"po12")==0 ){
			(strcpy(dtl[i].detailmobil.namamobil,"TOYOTA Avanza Facelift"));
         	if (dtl[i].detailmobil.transmobil==1)
  				{
					dtl[i].detailmobil.ccmobil=1500;
					dtl[i].detailmobil.hargamobil=300000;
	 			}
				else
            	{
      				dtl[i].detailmobil.ccmobil=1500;
					dtl[i].detailmobil.hargamobil=275000;
            	}
		}	
		else if (strcmp(dtl[i].detailmobil.kodemobil,"PO21")==0 || strcmp(dtl[i].detailmobil.kodemobil,"po21")==0 ){
			(strcpy(dtl[i].detailmobil.namamobil,"HONDA All New Brio"));
         	if (dtl[i].detailmobil.transmobil==1)
  				{
					dtl[i].detailmobil.ccmobil=1200;
					dtl[i].detailmobil.hargamobil=300000;
	 			}
				else
            	{
      				dtl[i].detailmobil.ccmobil=1200;
					dtl[i].detailmobil.hargamobil=275000;
            	}
		}
		else if (strcmp(dtl[i].detailmobil.kodemobil,"PO22")==0 || strcmp(dtl[i].detailmobil.kodemobil,"po22")==0 ){
			(strcpy(dtl[i].detailmobil.namamobil,"HONDA BRV"));
         	if (dtl[i].detailmobil.transmobil==1)
  				{
					dtl[i].detailmobil.ccmobil=1500;
					dtl[i].detailmobil.hargamobil=325000;
	 			}
				else
            	{
      				dtl[i].detailmobil.ccmobil=1500;
					dtl[i].detailmobil.hargamobil=300000;
            	}
		}
		else if (strcmp(dtl[i].detailmobil.kodemobil,"PO31")==0 || strcmp(dtl[i].detailmobil.kodemobil,"po31")==0 ){
			(strcpy(dtl[i].detailmobil.namamobil,"MITSHUBISHI XPANDER"));
  			if (dtl[i].detailmobil.transmobil==1)
			  	{
					dtl[i].detailmobil.ccmobil=1500;
					dtl[i].detailmobil.hargamobil=350000;
	 			}
				else
            	{
      			dtl[i].detailmobil.ccmobil=1500;
				dtl[i].detailmobil.hargamobil=325000;
            	}
		}
		else {
			system("PAUSE");
		}
		total[i]=dtl[i].detailmobil.hargamobil*dtl[i].detailmobil.lamasewa;
		system("CLS"); 
		cout << "Loading Invoice";
        Sleep(2000);
		tampildetail();
		system("CLS");
		}
		backmenu();
    	break;
    	
    	case 3:
    	system("CLS");
    	waitinglist();
    	backmenu();
    	break;
    	
    	case 4:
    	system("CLS");
		listresv();
		backmenu();
    	break;
    	
    	case 5:
    	system("CLS");
    	searchidsewa();
		backmenu();
    	break;
    	
    	case 6:
		system("CLS");
		sortidsewa();
    	break;
    	
    	case 7:
    	editresvmenu();
    	break;
    	
    	case 8:
    	doneresvmenu();
    	break;
    	
		case 9:
		exitpro();
    	break;
    	
    	default:
    	system("CLS");
    	cout<<"Menu Pilihan Anda Tidak Ada"<<endl;
    	backmenu();
	}
	}

    
}
void backmenu(){
	int pil;
	cout<<"Ingin Kembali Kemenu ? (1.ya/2.tidak) : ";
	cin>>pil;
	if(pil==1){
		cout << "===================" << endl;
        cout << "Loading Menu...." << endl; 
        cout << "===================" << endl;
        Sleep(1000);
		menu();
	} else {
		cout << "===================" << endl;
        cout << "Menutup Program...." << endl; 
        cout << "===================" << endl;
        Sleep(1000); 
        system("cls"); 
        system("exit"); 
	}
}
int login(){
 	string pass ="";
    char ch;
    cout<<"\n\n\n\t\t\t\t        WELCOME TO POLA CAR RENTAL \n"; 
    cout<<"\n\t\t\t\t\t================================";
    cout<<"\n\t\t\t\t\t\t     LOGIN \n";
    cout<<"\t\t\t\t\t================================\n\n";	
    cout << "\t\t\t\t\tEnter Password: ";  
    ch = _getch();
    while(ch != 13){
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if(pass == "admin"){   
        cout << "\n\n\t\t\t\t\t==============================";
        cout << "\n\t\t\t\t\t\tPASSWORD BENAR";   
        cout << "\n\t\t\t\t\t==============================" << endl;
        system("PAUSE");
        system ("CLS");
        greet();
        
    }
    else{
        cout << "\n\n\t\t\t\t\t==============================";
        cout << "\n\t\t\t\t\t\tPASSWORD SALAH\n\t\t\t\t\t\tSilahkan Coba Lagi";  
        cout << "\n\t\t\t\t\t==============================" << endl;
        system("PAUSE");
        system("CLS");
        login(); 
    };
}
void mobilheader(){
    cout<<"==================="<<"\t\t\t ==========="<<"\t\t      ============"<<"\t		============"<<endl;
    cout<<"Daftar Mobil Rental"<<"\t\t\t Spesifikasi"<<"\t\t      Harga / 24 jam"<<"\t\t	Kode Mobil"<<endl;
    cout<<"==================="<<"\t\t\t ==========="<<"\t\t      ============"<<"\t		============"<<endl;
}
void tampildetail(){
		system("CLS");
		long totalall=dtl[i].detailmobil.hargamobil*dtl[i].detailmobil.lamasewa;
		cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
    	cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    	cout << "\t\t                         ADMIN PENANGGUNG JAWAB                         "<<endl;
    	cout << "\t\t	| Admin :"<<"------------------------|"<<setw(10) << dtl[i].admin <<" |"<<endl;
    	cout << "\t\t        ///////////////////////////////////////////////////////////"<<endl;
    	cout << "\t\t	| Invoice No. :"<<"------------------|"<<setw(10) << dtl[i].idsewa <<"                |"<<endl; 
    	cout << "\t\t	| Nama Penyewa:"<<"------------------|"<<setw(10) << dtl[i].nama <<"                |"<<endl;
		cout << "\t\t	| Telp Penyewa:"<<"------------------|"<<setw(10) << dtl[i].telp <<"                |"<<endl; 
    	cout << "\t\t	| Nama Mobil :"<<"-------------------|"<<setw(10) << dtl[i].detailmobil.namamobil << " |"<<endl; 
    	cout << "\t\t	| Lama peminjaman :"<<"--------------|"<<setw(10) << dtl[i].detailmobil.lamasewa <<"   		    |"<<endl;
    	cout << "\t\t	| Harga peminjaman mobil :"<<"-------|"<<setw(10) << dtl[i].detailmobil.hargamobil <<" 		    |"<<endl;
    	cout << "\t\t	 ________________________________________________________"<<endl;
    	cout << "\n";
    	subtotal = subtotal+total[i];
    	grandtotal = subtotal;
    	cout << "\t\t	| Total harga peminjaman mobil :"<<"-|"<<setw(10)<< totalall <<" |"<<endl; 
    	cout << "\t\t	 ________________________________________________________"<<endl;
    	cout << "\t\t	                      Terima kasih                       "<<endl;
   		cout <<" "<<endl;
    	cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    	cout << "\t\t	                     By POLAR Rental Car"<<endl;
    	cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    	cout << "\t\t                        TEKAN ENTER UNTUK MENYIMPAN DATA                        "<<endl;
    	system("PAUSE");
    	system ("CLS");	
		cout<<" Menyimpan data ......"<<endl;
    	ofstream file1;
    	file1.open("text/datareservasi.txt", ios::app);
    	file1 << "----------- DATA RESERVASI ----------"<<endl;
    	file1 << "STATUS            :" << "[ON Going]" <<tglskrng<< endl;
    	file1 << "Admin             :" << dtl[i].admin << endl;
    	file1 << "Invoice No        :" << dtl[i].idsewa << endl;
    	file1 << "Nama              :" << dtl[i].nama << endl;
    	file1 << "Nomor Telepon     :" << dtl[i].telp <<endl; 
    	file1 << "NIK               :" << dtl[i].nik << endl; 
    	file1 << "Alamat            :" << dtl[i].alamat << endl;
    	file1 << "Jenis Mobil       :" << dtl[i].detailmobil.namamobil << endl;
    	file1 << "Lama Peminjaman   :" << dtl[i].detailmobil.lamasewa << endl;
    	file1 << "Total Biaya       :" << totalall << endl << endl;
    	file1 << "-------------------------------------"<<endl;
    	file1.close(); 
    	Sleep(1000);
    	cout<<endl;
		cout<<" Berhasil Menyimpan Data ...."<<endl;
		cout<<"-----------------------------"<<endl;
		system("PAUSE");
}
void listresv(){
	string line;
    ifstream file2;
    file2.open("text/datareservasi.txt");
    while(!file2.eof()){
        getline(file2, line);
        cout << line << endl;
        }
    file2.close(); 
}
void listsort(){
	ifstream in4("text/menusort.txt");
    if(!in4) {
    cout << "Cannotopen input file.\n";
    }
    char str4[1000];
    while(in4) {
        in4.getline(str4, 1000);  
        cout << endl;
        if(in4) cout << str4 << endl;
    }
    in4.close();
}
void searchidsewa(){
	    	searchmenu : 
		for(i=0;i<byk;i++){
		temp=dtl[i].idsewa;
		j=i-1;
		
		while((temp<dtl[j].idsewa)&&(j>=0)){
			dtl[j+1].idsewa=dtl[j].idsewa;
			j=j-1;
		}
		dtl[j+1].idsewa=temp;
		}
		system("CLS");
		int cari;
		cout << "Input ID Sewa yang ingin dicari: ";
  		cin >> cari;
  		for (i=0;i<byk;i++){
    	if (dtl[i].idsewa == cari){
    	cout<<endl;
    	cout <<"------ID Sewa "<< cari << " Ditemukan------"<<endl;
    	cout<<endl;
	  	int dtlid;
	  	cout<<"Ingin Tampil Detail Data ? (1.ya/2.tidak)"<<endl;
	  	cin>>dtlid;
	  	if(dtlid==1){
	  	system("CLS");
	  	cout <<"======== DETAIL PENYEWA ========"<<endl;
      	cout <<"Nama Penyewa : "<<dtl[i].nama<<endl;
      	cout <<"ID Sewa      : "<<dtl[i].idsewa<<endl;
      	cout <<"NIK          : "<<dtl[i].nik<<endl;
      	cout <<"================================"<<endl;
      	cout <<endl;
      	backmenu();
		} else {
		system("CLS");
		backmenu();
		}
  		}
		}
		cout<<endl;	
}

void sortidsewa(){
	int by;
	listsort();
	cout<<"Piilihan Menu : ";
	cin>>by;
	if(by==1){
		for(i=0;i<byk;i++){
		temp=dtl[i].idsewa;
		j=i-1;
		
		while((temp<dtl[j].idsewa)&&(j>=0)){
			dtl[j+1].idsewa=dtl[j].idsewa;
			j=j-1;
		}
		dtl[j+1].idsewa=temp;
	}
	system("CLS");
	cout<<"Hasil Sort ID Sewa ASC"<<endl;
	for(i=0;i<byk;i++)
	{
		cout<<dtl[i].idsewa<<endl;
	}
	} else if (by==2){
		for(i=0;i<byk;i++){
		temp=dtl[i].idsewa;
		j=i-1;
		
		while((temp>dtl[j].idsewa)&&(j>=0)){
			dtl[j+1].idsewa=dtl[j].idsewa;
			j=j-1;
		}
		dtl[j+1].idsewa=temp;
	}
	system("CLS");
	cout<<"Hasil Sort ID Sewa DSC"<<endl;
	for(i=0;i<byk;i++)
	{
		cout<<dtl[i].idsewa<<endl;
	}
	}
	cout<<endl;
	backmenu();
}

void editresvmenu(){
	system("cls");
    cout << "==================================" << endl;
	cout << "Anda memilih Menu Edit Reservation" << endl;
	cout << "==================================" << endl;
    listresv();
    editresv();
}
void editresv(){
	ifstream read; 
    ofstream write;
    
    string edit;
    cout << "================================================="<<endl;
    cout << "Hanya bisa mengubah (NIK/Nama/NoTelp)" << endl;
    cout << "================================================="<<endl;
    cout << "Keyword untuk mengubah data reservasi: " << endl;
	cout << "Contoh 'Nama' untuk mengubah Nama "<<endl;
    cout << "================================================="<<endl;
    cout << "Input keyword data yang akan diedit: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, edit);
    if(edit == "Nama"){
    	read.open("text/datareservasi.txt", ios::in); 
        write.open("text/temp.txt", ios::app); 
        string old, New, addName, a; 
        cout << "Masukkan Nama yang akan diubah: "; 
        getline(cin, old); 
        cout << "Masukkan Nama baru: "; 
        getline(cin, New);

        while (!read.eof()) { 
            getline(read, a);
            addName = "Nama              :" + old; 
            if (a == addName) {  
                write << "Nama              :" << New << endl;
                cout << "Nama berhasil diubah" << endl;
            }
            else { 
                write << a << endl; 
            }
        }
        read.close(); 
        write.close(); 

        remove("text/datareservasi.txt"); 
        rename("text/temp.txt", "text/datareservasi.txt");
        system("PAUSE");
		system("CLS");
        backmenu(); 
    }
    else if (edit == "Nomor Telepon"){
    	read.open("text/datareservasi.txt", ios::in); 
        write.open("text/temp.txt", ios::app); 
        string old, New, addNoTelp, a; 
        cout << "Masukkan nomor telepon yang akan diubah: ";
        getline(cin, old);
        cout << "Masukkan nomor telepon yang baru: ";
        getline(cin, New);

        while (!read.eof()) {
            getline(read, a);
            addNoTelp = "Nomor Telepon     :" + old;
            if (a == addNoTelp) { 
                write << "Nomor Telepon     :" << New << endl;
                cout << "Nomor Telepon berhasil diubah" << endl;
            }
            else { 
                write << a << endl; 
            }
        }
        read.close();
        write.close();

        remove("text/datareservasi.txt");
        rename("text/temp.txt", "text/datareservasi.txt");
        system("PAUSE");
		system("CLS");
        backmenu();
	} 
	else if (edit == "Nik"){
		read.open("text/datareservasi.txt", ios::in);
        write.open("text/temp.txt", ios::app);
        string old, New, addNIK, a;
        cout << "Masukkan NIK yang akan diubah: ";
        getline(cin, old);
        cout << "Masukkan NIK yang baru: ";
        getline(cin, New);

        while (!read.eof()) {
            getline(read, a);
            addNIK = "NIK               :" + old;
            if (a == addNIK) { 
                write << "NIK               :" << New << endl; 
                cout << "NIK berhasil diubah" << endl;
            }
            else { 
                write << a << endl; 
            }
        }
        read.close();
        write.close();

        remove("text/datareservasi.txt");
        rename("text/temp.txt", "text/datareservasi.txt");
        system("PAUSE");
		system("CLS");
        backmenu();
	}
    else{
        system("CLS");
        cout << "Pilihan Keyword Tidak Ada / Salah " << endl;
        cout<<endl;
        backmenu();
    }
}
void doneresvmenu(){
	system("cls");
    cout << "==================================" << endl;
	cout << "Anda memilih Menu Done Reservation" << endl;
	cout << "==================================" << endl;
    listresv();
    doneresv();
}
void doneresv(){
	ifstream read; 
    ofstream write; 
    string oldName, New, a, addName; 

	read.open("text/datareservasi.txt", ios::in);
    write.open("text/temp.txt", ios::app);
    cout << "Input nama dari data Reservasi yang telah selesai: "; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, oldName); 
    while (!read.eof()) { 
        getline(read, a); 
        addName = "Nama              :" + oldName; 
        if (a == addName) { 
        
        	write << "STATUS UPDATE     :" << "[DONE] " <<tglskrng<< endl; 
            write << "Nama              :" << oldName<< endl; 
        }
        else {  
            write << a << endl; 
        }
    }
    read.close();
    write.close(); 
    remove("text/datareservasi.txt");
    rename("text/temp.txt", "text/datareservasi.txt"); 
    system("CLS");
    cout << "============================" << endl;
    cout << "Mengupdate Data ...." << endl; 
    cout << "============================" << endl;
    Sleep(1000);
    system("PAUSE"); 
    backmenu();
}
void waitinglist(){
			int n=0;
			while(!database.empty()){
				arr[n]=database.top();
				n++;
				database.pop();
			}
			cout<<"List Antiran"<<endl;
			cout<<"Id Sewa"<<endl;
			for(int i=0;i<n;i++){
				cout<<i+1<<". "<<arr[n-1-i].idsewa<<endl;
	}
}
void exitpro(){
	    system("CLS");
    	cout << "====================" << endl;
        cout << "Menutup Program....." << endl; 
        cout << "====================" << endl;
        Sleep(1000);
        system("CLS");
        cout << "====================" << endl;
        cout << "    TERIMA KASIH    "  << endl; 
        cout << "====================" << endl;
        exit(0);
}
