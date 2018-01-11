#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>

void chgcolor(unsigned short color)
{
HANDLE sCon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(sCon,color);
}
using namespace std;
typedef struct Tnode
{
	string namapengirim;
	int no;
	Tnode *next;
}data;

typedef struct Pnode
{
	string namapenerima;
	string alamat;
	int berat;
	int harga;
	int total;
	Pnode *Pnext;
}Pdata;
int noan=1;
Pnode *Phead;
Tnode *head;
Tnode *bantu;

void init()
{
	head=NULL;
}

int IsEmpty()
{
	if(head==NULL)
	return 1;
	else
	return 0;
}

void insertbelakang(string n)
{
	int x=0;
	if(head==NULL && bantu!=NULL)
	{
		head=bantu;
		x=5;
	}



	Tnode *baru,*Tbantu;
	baru = new Tnode;
	baru->namapengirim = n;
	baru->next = NULL;
	if(IsEmpty()==1)
	{
		head=baru;
		head->no = 1;
		head->next = NULL;
	}else
	{
		Tbantu = head;
		while(Tbantu->next!=NULL)
		{
			Tbantu=Tbantu->next;
		}
		baru->no=Tbantu->no+1;
		Tbantu->next=baru;

	}
	cout<<"\n";
	cout<<"Terima kasih Data Telah Terisi";

	if(x==5)
	{
		head=Tbantu->next;
	}
}

int PsEmpty()
{
	if(Phead==NULL)
	return 1;
	else
	return 0;
}


void insertpesanan(string pes,string almt, int brt,int harga,int total)
{

	Pnode *Pbaru,*Pbantu;
	Pbaru = new Pnode;
	Pbaru->namapenerima = pes;
	Pbaru->alamat = almt;
	Pbaru->berat  = brt;
	Pbaru->harga  = harga;
	Pbaru->total  = total;

	Pbaru->Pnext = NULL;
	if(PsEmpty()==1)
	{
		Phead=Pbaru;
		Phead->Pnext = NULL;

	}else
	{
		Pbantu = Phead;
		while(Pbantu->Pnext!=NULL)
		{
			Pbantu=Pbantu->Pnext;
		}
		Pbantu->Pnext=Pbaru;

	}
	cout<<"Terimakasih Data telah Tersimpan";

}


void panggil()
{
	if(IsEmpty()==0)
	{
			cout<<"Silahkan Masukan Orderan dari antrian terdepan secara berurutan"<<endl;
	}else
			cout<<endl<<"Maaf Data Masih Kosong"<<endl;
}


void tampil()
{
	int no=noan;
	Tnode *cantu;
	cantu = head;
	if(IsEmpty()==0)
	{
		chgcolor(10);
		cout<<"\t+---------------------------------------+"<<endl;
		cout<<"\t|            DAFTAR ANTRIAN             |"<<endl;
	    cout<<"\t|---------------------------------------|"<<endl;
	    cout<<"\t| NOMOR ANTRIAN    |   NAMA PENGANTRI   |"<<endl;
	    cout<<"\t|---------------------------------------|"<<endl;
		while(cantu!=NULL)
		{
		    chgcolor(10);
		    cout<<"\t"<<setiosflags(ios::left)<<setw(7)<<"|";
		    chgcolor(15);
		    cout<<"\t"<<setiosflags(ios::left)<<setw(10)<<no;
		    cout<<"\t"<<setiosflags(ios::left)<<setw(10)<<cantu->namapengirim;
		    chgcolor(10);
		    cout<<"\t"<<setiosflags(ios::left)<<setw(7)<<"|";
			cantu=cantu->next;
			no++;
			cout<<endl;
		}
		chgcolor(10);
        cout<<"\t+---------------------------------------+"<<endl;
	}else
		cout<<endl<<"ANTRIAN KOSONG BOS"<<endl;
}



void tampilpesanan()
{
	int no=1;
	Tnode *antu;
	Pnode *Pbantu;

	Pbantu = Phead;
	antu=bantu;
	if(PsEmpty()==0)
	{
            chgcolor(10);
            cout<<"==========================================================================================================="<<endl;
            cout<<"||                               DATA PELANGGAN JASA PENGIRIMAN BARANG                                   ||"<<endl;
			cout<<"||  No    Nama Pengirim     Nama Penerima       Alamat       Berat per/KG     Harga Per/KG       TOTAL   ||"<<endl;
			cout<<"||=======================================================================================================||"<<endl;

		while(Pbantu!=NULL)
		{
		    chgcolor(10);
		    cout<<setiosflags(ios::left)<<setw(4)<<"||";
		    chgcolor(15);
            cout<<setiosflags(ios::left)<<setw(7)<<no;
			cout<<setiosflags(ios::left)<<setw(18)<<antu->namapengirim;
			cout<<setiosflags(ios::left)<<setw(19)<<Pbantu->namapenerima;
			cout<<setiosflags(ios::left)<<setw(20)<<Pbantu->alamat;
			cout<<setiosflags(ios::left)<<setw(15)<<Pbantu->berat;
			cout<<setiosflags(ios::left)<<setw(15)<<Pbantu->harga;
			cout<<setiosflags(ios::left)<<setw(7)<<Pbantu->total;
			chgcolor(10);
			cout<<setiosflags(ios::left)<<setw(5)<<"||";
			Pbantu=Pbantu->Pnext;
			antu=antu->next;
			no++; cout<<endl;
		}
		chgcolor(10);
		cout<<"==========================================================================================================="<<endl;
	}else
		cout<<endl<<"Masih Kosong"<<endl;
}

void hapusdepan()
{
	Tnode *hapus;
	string d;


	if(bantu==NULL)
	bantu = head;


	if(IsEmpty()==0)
	{
		if(head!=NULL)
		{
			noan=noan+1;
			hapus=head;
			d=hapus->namapengirim;
			head=hapus->next;
		}

	}else
	cout<<"\nMasih Kosong\n";
}

int main()
{
 int j,h,pil,x;
 char p;
 string n,z,y,a;
	do{
    chgcolor(10);
        cout<<"+=================================================+"<<endl;
		cout<<"|   JASA PENGIRIMAN BARANG KE SELURUH INDONESIA   |"<<endl;
        cout<<"|                 DARI YOGYAKARTA                 |"<<endl;
        cout<<"|-------------------------------------------------|"<<endl;
    chgcolor(10);
		cout<<"|MENU UTAMA                                       |"<<endl;
		cout<<"|  1.Silahkan Mengambil Nomor Antrian             |"<<endl;
		cout<<"|  2.Tampilkan Antrian                            |"<<endl;
		cout<<"|  3.Panggil Antrian                              |"<<endl;
		cout<<"|  4.Tampilkan Orderan                            |"<<endl;
		cout<<"|  5.Hapus Semua Data                             |"<<endl;
		cout<<"|  6.Keluar                                       |"<<endl;
		cout<<"+=================================================+"<<endl;
	chgcolor(15);	
		cout<<"Silahkan Masukkan Pilihan = ";
        cin>>pil;
		cout<<"\n\n";
		if (pil>=7){
            cout<<"\ttidak ada pilihan !!!"<<endl;
		}
		switch(pil)
		{
			case 1 :
			cout<<"Silahkan Masukan Identitas Anda Untuk Menggambil Nomer Antrian\n";
            cout<<"Nama Lengkap : "; cin>>n;
			IsEmpty();
			insertbelakang(n);

			break;

			case 2 :
			IsEmpty();
			tampil();
			break;

			case 3 :
			IsEmpty();

			panggil();
			if(IsEmpty()==0)
				{
						cout<<"\n----------MASUKAN IDENTITAS PENERIMA----------\n"<<endl;  
						cout<<"Nama Lengkap          : "; cin>>z;
						cout<<"Kota Tujuan           : "; cin>>a;
						cout<<"Berat Total           : "; cin>>j;
						cout<<"Harga per/KG          : "; cin>>h;
						x=j*h;
						insertpesanan(z,a,j,h,x);
						hapusdepan();
				}
			break;

			case 4 :
			PsEmpty();
			tampilpesanan();
			break;

			case 5 :
			head=NULL;
			Phead=NULL;
			cout<<"\n\nData Terhapus\n\n";
			break;

			case 6 :
			cout<<"Terimakasih"<<endl;
			break;
			default :
            break;

		}
		cout<<endl;
		chgcolor(15);
		cout<<"Lanjut";
		getch();
	system("cls");
	}while(pil!=6);
	for(int x=1;x<10;x++)

	return 0;
}

