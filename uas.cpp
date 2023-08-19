#include <iostream>
#include <conio.h>
#include <string>

char pilih, sub_pilih, pilih2;		//variable menu
int banyak_data_array,a[99],b[99][99],brs_array,klm_array; //variable array
int jml_search=0,bil_search[999],kiri,kanan,tengah,temp,search; //variable searching
bool ketemu;
int i,j,x,y,n,k;
int angka_1[100],angka_2[100],data_s,wadah;
//struktur stack

struct node{
	int bil_stack;
	struct node *next_stack;
};

struct stack{
	int jumlah_stack;
	struct node *top_stack;
};

//struktur linked list

struct simpul{
	char nama_li[20],huruf_li;
	int nim_li,tugas_li,uts_li,uas_li;
	float rata_li;
	simpul *next_li;
};
simpul *awal_ptr_li = NULL;
simpul *posisi_li;


//struktur menu 2

struct mahasiswa {
	char nama_s[100],tempat_s[100];
   int nim_s,tgl_s,bulan_s,thn_s;
};
int jml_s;
mahasiswa mhs[100];

//array

void masuk_array1(){
   cout<<"Masukan Banyak Data : ";
   cin>>banyak_data_array;
   for(i=0;i<banyak_data_array;i++){
   	cout<<"Masukan nilai ["<<i<<"] : ";
      cin>>a[i];
   }
	getch();
}


void cetak_array1(){
   for(i=0;i<banyak_data_array;i++){
   	cout<<"Nilai ["<<i<<"] : "<<a[i]<<endl;
   }
	getch();
}
void array1(){
	do{
		clrscr();
		cout<<"Menu Array 1 Dimensi"<<endl;
		cout<<"1. Masukan Data Array\n2. Cetak Data Array\n3. Kembali ke menu sebelumnya"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>pilih2;
		if(pilih2=='1'){
			masuk_array1();
		}
		if(pilih2=='2'){
			cetak_array1();
		}
	}while(pilih2!='3');

}
//array 2 dimensi
void array2(){
	do{
		clrscr();
		cout<<"Menu Array 2 Dimensi"<<endl;
		cout<<"1. Masukan Data Array\n2. Cetak Data Array\n3. Kembali ke menu sebelumnya"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>pilih2;

		if(pilih2=='1'){
      	cout<<"Masukan jumlah baris : ";
		   cin>>brs_array;
		   cout<<"Masukan jumlah kolom : ";
		   cin>>klm_array;
         for(i=0;i<brs_array;i++){
         	for(j=0;j<klm_array;j++){
		   		cout<<"Masukan nilai ["<<i<<"]["<<j<<"] : ";
	   		   cin>>b[i][j];
		      }
		   }
			getch();
		}
		if(pilih2=='2'){
			for(int i=0;i<brs_array;i++){
   		for(int j=0;j<klm_array;j++){
   			cout<<"Nilai["<<i<<"]["<<j<<"] : "<<b[i][j]<<endl;
	      }
   	}
		getch();
		}
	}while(pilih2!='3');
}

void array(){
	do{
		clrscr();
		cout<<"Menu Array"<<endl;
		cout<<"1. Array 1 Dimensi\n2. Array 2 Dimensi\n3. Kembali ke menu utama"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>sub_pilih;
								//array 1
		if(sub_pilih=='1'){
			array1();
		}
								//array 2
		if(sub_pilih=='2'){
			array2();
		}
	}while(sub_pilih!='3');
}

//struktur

void masuk_struktur(){
   clrscr();
   int z;
   z=1;
	cout<<"Berapa Jumlah Mahasiswa : ";
   cin>>jml_s;
   for(i=0; i<jml_s;i++){
   	clrscr();
		cout<<"Data ke "<<z<<endl;
      cout<<"----------------------"<<endl;
      cout<<"Masukan Nama			: ";
   	cin.ignore();cin.getline(mhs[i].nama_s,sizeof(mhs[i].nama_s));
      cout<<"Masukan nim			: ";
      cin>>mhs[i].nim_s;
      cout<<"Masukan tempat lahir		: ";
		cin.ignore();cin.getline(mhs[i].tempat_s,sizeof(mhs[i].tempat_s));
      cout<<"Masukan tanggal lahir		: ";
      cin>>mhs[i].tgl_s;
      cout<<"Masukan bulan lahir(angka)	: ";
      cin>>mhs[i].bulan_s;
      cout<<"Masukan tahun lahir		: ";
      cin>>mhs[i].thn_s;
      z++;
   }
	getch();
}

void cetak_struktur(){
	clrscr();
   int z;
   z=1;
	for(i=0; i<jml_s;i++){
   	cout<<"Data ke "<<z<<endl;
      cout<<"----------------------"<<endl;
      cout<<"Nama		: " <<mhs[i].nama_s<<endl;
      cout<<"Nim		: " <<mhs[i].nim_s<<endl;
      cout<<"Tempat lahir	: "<<mhs[i].tempat_s<<endl;
      cout<<"Tanggal lahir	: "<<mhs[i].tgl_s<<endl;
      cout<<"Bulan lahir	: "<<mhs[i].bulan_s<<endl;
      cout<<"Tahun lahir	: "<<mhs[i].thn_s<<endl;
      cout<<"----------------------"<<endl;
      z++;
   }
	getch();
}
void struktur(){
	do{
		clrscr();
		cout<<"Menu Struktur"<<endl;
		cout<<"1. Masukan Data\n2. Cetak Data\n3. Kembali ke menu sebelumnya"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>sub_pilih;
		if(sub_pilih=='1'){
			masuk_struktur();
		}
		if(sub_pilih=='2'){
			cetak_struktur();
		}
	}while(sub_pilih!='3');
}

//linked list
void tambah_awal_li(){
	simpul *baru_li;
	baru_li = new(simpul);
	cout << "Masukkan Nama : ";
	cin.ignore();cin.getline(baru_li->nama_li,sizeof(baru_li->nama_li));
	cout << "Masukkan Nim : ";
	cin >> baru_li->nim_li;
	cout << "Masukkan Nilai Tugas : ";
	cin >> baru_li->tugas_li;
	cout << "Masukkan Nilai UTS : ";
	cin >> baru_li->uts_li;
	cout << "Masukkan Nilai UAS : ";
	cin >> baru_li->uas_li;
	baru_li->rata_li=0.25*baru_li->tugas_li+0.25*baru_li->uts_li+0.5*baru_li->uas_li;
	if (baru_li->rata_li>=80){
   		baru_li->huruf_li='A';
	}
	else if (baru_li->rata_li>=70){
		baru_li->huruf_li='B';
	}
	else if (baru_li->rata_li>=60){
		baru_li->huruf_li='C';
	}
	else if (baru_li->rata_li>=50){
		baru_li->huruf_li='D';
	}
	else if (baru_li->rata_li<50){
		baru_li->huruf_li='E';
	}
	baru_li->next_li = NULL;
	if(awal_ptr_li == NULL){
		awal_ptr_li=baru_li;
		awal_ptr_li->next_li = NULL;
		posisi_li = awal_ptr_li;
	}
	else{
		baru_li->next_li = awal_ptr_li;
		awal_ptr_li = baru_li;
	}
}

void tambah_akhir_li(){
	simpul *temp, *temp2; // Temporary pointers
	temp = new(simpul);
	cout << "Masukkan Nama : ";
	cin.ignore();cin.getline(temp->nama_li,sizeof(temp->nama_li));
	cout << "Masukkan Nim : ";
	cin >> temp->nim_li;
	cout << "Masukkan Nilai Tugas : ";
	cin >> temp->tugas_li;
	cout << "Masukkan Nilai UTS : ";
	cin >> temp->uts_li;
	cout << "Masukkan Nilai UAS : ";
	cin >> temp->uas_li;
	temp->rata_li=0.25*temp->tugas_li+0.25*temp->uts_li+0.5*temp->uas_li;
	if (temp->rata_li>=80){
   		temp->huruf_li='A';
	}
	else if (temp->rata_li>=70){
		temp->huruf_li='B';
	}
	else if (temp->rata_li>=60){
		temp->huruf_li='C';
	}
	else if (temp->rata_li>=50){
		temp->huruf_li='D';
	}
	else if (temp->rata_li<50){
		temp->huruf_li='E';
	}
	temp->next_li = NULL;
	// Set up link pada node
	if (awal_ptr_li == NULL){
		awal_ptr_li = temp;
		posisi_li = awal_ptr_li;
	}
	else{
		temp2 = awal_ptr_li;
		// node tidak NULL - list tidak kosong
		while (temp2->next_li != NULL){
			temp2 = temp2->next_li;
			// Memindahkan pada next link dalam rantai
		}
	temp2->next_li = temp;
	}
}

void tambah_tengah_li(){
	simpul *baru_li, *bantu_li;
	int posisi_sisip_li;
	if(awal_ptr_li != NULL){
		cout<<"Akan disisip setelah Data Ke ? : ";
		cin>>posisi_sisip_li;
		bantu_li=awal_ptr_li;
		baru_li =new(simpul);
		for(i=1;i<posisi_sisip_li-1;i++){
			if(bantu_li->next_li != NULL)
				bantu_li=bantu_li->next_li;
			else
				break;
		}
		cout << "Masukkan Nama : ";
		cin.ignore();cin.getline(baru_li->nama_li,sizeof(baru_li->nama_li));
		cout << "Masukkan Nim : ";
		cin >> baru_li->nim_li;
		cout << "Masukkan Nilai Tugas : ";
		cin >> baru_li->tugas_li;
		cout << "Masukkan Nilai UTS : ";
		cin >> baru_li->uts_li;
		cout << "Masukkan Nilai UAS : ";
		cin >> baru_li->uas_li;
		baru_li->rata_li=0.25*baru_li->tugas_li+0.25*baru_li->uts_li+0.5*baru_li->uas_li;
		if (baru_li->rata_li>=80){
	   		baru_li->huruf_li='A';
		}
		else if (baru_li->rata_li>=70){
			baru_li->huruf_li='B';
		}
		else if (baru_li->rata_li>=60){
			baru_li->huruf_li='C';
		}
		else if (baru_li->rata_li>=50){
			baru_li->huruf_li='D';
		}
		else if (baru_li->rata_li<50){
			baru_li->huruf_li='E';
		}
		baru_li->next_li=bantu_li->next_li;
		bantu_li->next_li=baru_li;
	}
	else{
		cout<<"Belum ada data !! silahkan isi data dulu....";
		getch();
	}
}

void hapus_awal_li(){
	simpul *temp;
	temp = awal_ptr_li;
	if(temp == NULL){
		cout<<"List kosong"<<endl;
		getch();
	}
	else{
		awal_ptr_li = awal_ptr_li->next_li;
		delete temp;
	}
}

void hapus_akhir_li(){
	simpul *temp1, *temp2;
	if (awal_ptr_li == NULL){
		cout << "List kosong!" << endl;
		getch();
	}
	else{
		temp1 = awal_ptr_li;
		if (temp1->next_li == NULL){
			delete temp1;
			awal_ptr_li = NULL;
		}
		else{
			while (temp1->next_li != NULL){
			temp2 = temp1;
			temp1 = temp1->next_li;
			}
		delete temp1;
		temp2->next_li = NULL;
		}
	}
}

void hapus_tengah_li(){
	int banyakdata_li,posisi_hapus_li,poshapus_li;
	simpul *hapus_li, *bantu_li;
	if(awal_ptr_li != NULL){
		cout<<" Akan dihapus pada data ke : "; cin>>posisi_hapus_li;
		banyakdata_li=1;
		bantu_li=awal_ptr_li;
		while(bantu_li->next_li != NULL){
			bantu_li=bantu_li->next_li;
			banyakdata_li++;
		}
		if((posisi_hapus_li<1)||(posisi_hapus_li>banyakdata_li)){
			cout<<"Belum ada data !! masukkan Data dula aja...\n";
			getch();
		}
		else{
			bantu_li=awal_ptr_li;
			poshapus_li=1;
			while(poshapus_li<(posisi_hapus_li-1)){
				bantu_li=bantu_li->next_li;
				poshapus_li++;
			}
			hapus_li=bantu_li->next_li;
			bantu_li->next_li=hapus_li->next_li;
			delete hapus_li;
			}
			getch();
		}

	else{
		cout<<"Data Masih kosong, tidak bisa hapus data dari tengah!";
		getch();
	}

}

void pindah_berikutnya_li(){
	if (awal_ptr_li==NULL){
	   cout<<"Data Masih kosong!";
   	getch();
	}
	else{
		if (posisi_li->next_li == NULL){
			cout << "Kamu berada pada akhir list." << endl;
			getch();
		}
		else
			posisi_li = posisi_li->next_li;
	}
}
void pindah_sebelumnya_li(){
	if (awal_ptr_li==NULL){
		cout<<"Data Masih kosong!";
      getch();
   }
	else{
		if (posisi_li == awal_ptr_li){
			cout << "Kamu berada pada awal list" << endl;
			getch();
		}
		else{
			simpul *previous; // deklarasi pointer
			previous = awal_ptr_li;
			while (previous->next_li != posisi_li){
				previous = previous->next_li;
			}
			posisi_li = previous;
		}
	}
}

void display_li(){
	simpul *temp;
	temp = awal_ptr_li;
	cout << endl;
	if (temp == NULL)
		cout << "List kosong!" << endl;
	else{
		while (temp != NULL){
			// Menampilkan detail data
			cout << "Nama	: " << temp->nama_li << " ";
			cout << "Nim	: " << temp->nim_li << " ";
			cout << "Nilai Tugas	: " << temp->tugas_li;
			cout << "Nilai UTS	: " << temp->uts_li;
			cout << "Nilai UAS	: " << temp->uas_li;
			cout << "Rata-Rata	: " << temp->rata_li;
			cout << "Nilai Huruf	: " << temp->huruf_li;
			if (temp == posisi_li)
				cout << " <<<< posisi node";
				cout << endl;
				temp = temp->next_li;
		}
		cout << "Akhir list!" << endl;
	}
}

void linked_list(){
	awal_ptr_li = NULL;
	do{
		clrscr();
		cout<<"data linked list"<<endl;
		cout<<"----------------"<<endl;
		display_li();
		cout<<"----------------"<<endl<<endl;
		cout<<"Menu Linked List"<<endl;
		cout<<"1. Tambah awal list\n2. Tambah akhir list\n3. Tambah tengah list\n4. Hapus awal list\n5. Hapus akhir list\n6. Hapus tengah list\n7. Pindah posisi pointer ke sebelumnya\n8. Pindah posisi pointer ke berikutnya\n9. Kembali ke menu sebelumnya"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>sub_pilih;
		if(sub_pilih=='1'){
			tambah_awal_li();
		}
		if(sub_pilih=='2'){
			tambah_akhir_li();
		}
		if(sub_pilih=='3'){
			tambah_tengah_li();
		}
		if(sub_pilih=='4'){
			hapus_awal_li();
		}
		if(sub_pilih=='5'){
			hapus_akhir_li();
		}
		if(sub_pilih=='6'){
			hapus_tengah_li();
		}
		if(sub_pilih=='7'){
			pindah_sebelumnya_li();
		}
		if(sub_pilih=='8'){
			pindah_berikutnya_li();
		}
	}while(sub_pilih!='9');
}

//stack


void push_stack(stack *stack){
	node *baru_stack;
	if(stack->jumlah_stack==5){
		cout<<"Stack Penuh"<<endl;
		getch();
	}
	else{
		baru_stack=new(node);
		cout<<"Masukan Nilai :";
		cin>>baru_stack->bil_stack;
		baru_stack->next_stack=stack->top_stack;
		stack->top_stack=baru_stack;
		stack->jumlah_stack++;
		cout<<"Proses Berhasil"<<endl;
		cout<<"----------------\n";
	}
}

void cetak_stack(stack *stack){
	node *bacaPtr;
	bacaPtr=stack->top_stack;
	if(stack->jumlah_stack==0){
		cout<<"\nstack kosong";
		getch();
	}
	else{
		cout<<"\nTOP\n";
		cout<<"---------\n";
		while(bacaPtr!=NULL)
		{
			cout<<"Nilai	: "<<bacaPtr->bil_stack<<endl;
			cout<<"---------"<<endl;
			bacaPtr=bacaPtr->next_stack;
		}
		getch();
	}
}

void pop_stack(stack *stack){
	node *hapusPtr;
	hapusPtr=stack->top_stack;
	if (stack->jumlah_stack==0){
		cout<<"Stack Kosong";
		getch();
	}
	else{
		stack->top_stack=stack->top_stack->next_stack;
		stack->jumlah_stack--;
		delete hapusPtr;
		cout<<"\nproses pop berhasil\n";
		cetak_stack(stack);
	}
}

void top_stack(stack *stack){
	if(stack->jumlah_stack==0){
		cout<<"\nstack kosong";
		getch();
	}
	else{
		cout<<"Top Stack : "<<stack->top_stack->bil_stack;
		getch();
	}
}

void kosong_stack(stack *stack){
	node *bantuHapus;
	bantuHapus=stack->top_stack;
	if(stack->jumlah_stack==0){
		cout<<"\nstack kosong";
		getch();
	}
	else{
		while(stack->top_stack!=NULL){
			bantuHapus=stack->top_stack;
			stack->top_stack=stack->top_stack->next_stack;
			delete bantuHapus;
		}
		stack->jumlah_stack=0;
		cout<<"\nStack Telah Kosong";
		getch();
	}
}

void stack_pointer(){
	stack stack;
	stack.jumlah_stack=0;
	stack.top_stack=NULL;
	do{
		clrscr();
		cout<<"Menu Stack (Maximal data = 5)"<<endl;
		cout<<"1. push\n2. pop\n3. cetak\n4. Lihat top stack\n5. Kosongkan stack\n6. Kembali ke menu sebelumnya"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>sub_pilih;
		if(sub_pilih=='1'){
			push_stack(&stack);
			cetak_stack(&stack);
		}
		if(sub_pilih=='2'){
			pop_stack(&stack);
		}
		if(sub_pilih=='3'){
			cetak_stack(&stack);
		}
		if(sub_pilih=='4'){
			top_stack(&stack);
		}
		if(sub_pilih=='5'){
			kosong_stack(&stack);
		}
	}while(sub_pilih!='6');
}

//sorting

void masuk_sorting(){
   clrscr();
	cout<<"Masukkan Banyaknya Data : ";
	cin>>data_s;
	cout<<endl;

	for (i=0; i<data_s; i++){
		cout<<"Masukkan Angka ["<<(i+1)<<"] = ";
		cin>>angka_1[i];
		angka_2[i]=angka_1[i];
	}
	getch();
}

void output_awal(){
	cout<<"Data Yang Dimasukkan : ";
   for (n=0; n<data_s; n++){
		angka_1[n]=angka_2[n];
		cout<<"["<<angka_1[n]<<"]";
	}
	cout<<endl;
}

void output(){
	for (int i=0; i<data_s; i++){
		cout<<"["<<angka_1[i]<<"]";
	}
	cout<<endl;
}
void ascending (){
	cout<<"\nProses Bubble Sort Ascending";
	output();
	cout<<endl;

	for (i=1; i<data_s; i++){
		for (k=0; k<data_s-1; k++){
			if (angka_1[k]>angka_1[k+1]){
				wadah=angka_1[k];
				angka_1[k]=angka_1[k+1];
				angka_1[k+1]=wadah;
			}
			output();
		}
		output();
		cout<<endl;
	}
	cout<<endl;
   cout<<"Data setelah di urutkan : ";
   output();
   getch();
}

void descending(){
	cout<<"Proses Bubble Sort Descending";
	output();
	cout<<endl;

	for (i=1; i<data_s; i++){
		for (k=0; k<data_s-1; k++){
			if (angka_1[k]<angka_1[k+1]){
				wadah=angka_1[k];
				angka_1[k]=angka_1[k+1];
				angka_1[k+1]=wadah;
			}
			output();
		}
		output();
		cout<<endl;
	}
	cout<<endl;
   cout<<"Data setelah di urutkan : ";
   output();
   getch();
}
void cetak_sorting(){
	do{
     clrscr();
     output_awal();
     cout<<"1. Ascending	(Kecil->Besar)\n2. Descending	(Besar->Kecil)\n3. Kembali ke menu sebelumnya"<<endl;
     cout<<"Masukan pilihan : ";
     cin>>pilih2;
     if(pilih2=='1'){
        ascending();
     }
     if(pilih2=='2'){
     	descending();
     }
   }while(pilih2!='3');
}

void sorting(){
	do{
		clrscr();
		cout<<"Menu Sorting BUBBLE SORT"<<endl;
		cout<<"1. Masukan Data\n2. Urutkan Data\n3. Kembali ke menu sebelumnya"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>sub_pilih;
		if(sub_pilih=='1'){
			masuk_sorting();
		}
		if(sub_pilih=='2'){
			cetak_sorting();
		}
	}while(sub_pilih!='3');
}

//searching

void masuk_searching(){
	int zz=1;
	cout<<"Masukan Banyak data : ";
   cin>>jml_search;
   for(x=0;x<jml_search;x++){
       cout<<"Data ke "<<zz<<" : ";
       cin>>bil_search[x];
       zz++;
   }
   for (x=0; x<jml_search; x++){
        for(y=0; y< jml_search-x-1; y++){
            if(bil_search [y] > bil_search [y+1]){
                temp=bil_search[y];
                bil_search [y]=bil_search[y+1];
                bil_search [y+1]=temp;
            }
        }
    }

	getch();
}

void cetak_searching(){
   if(jml_search==0){
   	cout<<"Data kosong!!!"<<endl;
   }
   else{
   	char cari_lagi;
		do{
      	clrscr();
			cout<<"Data yang telah diurutkan adalah : ";
		 	for(x=0; x<jml_search; x++){
		  		cout<<bil_search[x]<<" ";
			}
		 	cout<<endl;
		 	cout<<"Masukan angka yang dicari : ";
			cin>>search;

			kiri=0;
			kanan=jml_search-1;
			while(kiri<=kanan){
				tengah=(kiri + kanan)/2;
				if(search == bil_search[tengah]){
			   	ketemu=true;
			   	break;
				}
				else if (search < bil_search [tengah]){
		   		kanan = tengah -1;
				}
				else{
		   		kiri = tengah +1;
				}
		 	}
			if(ketemu == 1)
	   			cout<<"Data ada dalam index ke "<<(tengah+1)<<endl;
			else{
	   			cout<<"Data tidak ada!!!"<<endl;
	        	getch();
	  		}
    	}while(ketemu!=1);
	}
      getch();
}

void searching(){
	do{
		clrscr();
		cout<<"Menu Searching (Binary Search)"<<endl;
		cout<<"1. Masukan Data\n2. Cari Data\n3. Kembali ke menu sebelumnya"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>sub_pilih;
		if(sub_pilih=='1'){
			masuk_searching();
		}
		if(sub_pilih=='2'){
			cetak_searching();
		}
	}while(sub_pilih!='3');
}
int main(){
	do{
		clrscr();
		cout<<"Menu Utama Data Terstruktur";
		cout<<"\n1. Array\n2. Struktur\n3. Linked List\n4. Stack\n5. Sorting\n6. Searching\n7. Keluar"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>pilih;

		//menu array
		if(pilih=='1'){
			array();
		}

		//menu struktur
		if(pilih=='2'){
			struktur();
		}

		//menu linked list

		if(pilih=='3'){
			linked_list();
		}

		//stack
		if(pilih=='4'){
			stack_pointer();
		}

		//sorting
		if(pilih=='5'){
			sorting();
		}

		//searching
		if(pilih=='6'){
			searching();
		}
	}while(pilih!='7');
	getch();
}
