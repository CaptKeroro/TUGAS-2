//NAMA ANGGOTA KELOMPOK :
// - I PUTU EKA SURYA GEMPITA (220030429)
// - NI PUT DIAH RAHAYU ARIANI (220030372)
// - I KOMANG DWIKI WAHYU DANUARTA (220030376)


#include <iostream>
#define MAX 5
using namespace std;

struct Queue{
	int front, rear, nik[MAX];
	string nama[MAX], tanggal[MAX], status[MAX], pekerjaan[MAX];
}Q;

bool isFull() {
	return Q.rear == MAX;
}

//cek apakah antrian kosong
bool isEmpty(){
	return Q.rear == 0;
}

void printQueue(){
	if (isEmpty()) {
    cout << "Antrian kosong"<<endl;
	}
	else {
		for (int i = Q.front; i < Q.rear; i++){
			cout << "Data KTP "<< i + 13 <<" : "<<endl;
			cout << "NIK : " << Q.nik[i] << endl;
			cout << "Nama : " << Q.nama[i] << endl;
			cout << "Tanggal : " << Q.tanggal[i] << endl;
			cout << "Status : " << Q.status[i] << endl;
			cout << "Pekerjaan : " << Q.pekerjaan[i] << endl << endl;
		}
		cout << endl<<endl;
  }
}

void enqueue(){
	if (isFull()){
		cout << "Antrian penuh!" << endl;
	}
	else {
		cout << "Masukkan NIK : "; cin >> Q.nik[Q.rear];
		cout << "Masukkan Nama : "; cin >> Q.nama[Q.rear];
		cout << "Masukkan Tanggal : "; cin >> Q.tanggal[Q.rear];
		cout << "Masukkan Status : "; cin >> Q.status[Q.rear];
		cout << "Masukkan Pekerjaan : "; cin >> Q.pekerjaan[Q.rear];

		Q.rear++;
		cout << "Data ditambahkan\n";
	}
}

void dequeue(){
	if (isEmpty()){
		cout << "Antrian masih kosong" << endl;
	}
	else{
    cout << "Data Sudah Dihapus" << endl;
		Q.rear--;
	}
}

void deallqueue(){
    Q.front = 0;
    Q.rear = 0;
    cout << "Semua Data Terhapus" << endl;
}

int main(){
	int choose;
	do{
		//Tampilan menu
		cout << "-------------------\n"
			<< "   Menu Pilihan\n"
			<< "-------------------\n"
			<< " 1 Insert \n"
			<< " 2 Print\n"
			<< " 3 Delete\n"
			<< " 4 Delete All Data\n"
			<< " 5 Keluar \n\n"
			<< "-------------------\n"
			<< "Masukkan pilihan : "; cin >> choose;

		switch (choose){
		case 1:
			enqueue();
			break;
		case 2:
			printQueue();
			break;
		case 3:
			dequeue();
			break;
		case 4:
			deallqueue();
			break;
		default:
			cout << "Pilihan tidak tersedia";
			break;
		}
	} while (choose != 5);
	return 0;
}