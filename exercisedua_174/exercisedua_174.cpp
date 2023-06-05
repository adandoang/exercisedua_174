#include <iostream>
#include <vector>
#include<string>
using namespace std;

class pengarang;
class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	penerbit(string pNama) :nama(pNama) {
		cout << "";
	}
	~penerbit() {
		cout << "";
	}
	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

class buku {
private:
	string judul_buku;
public:
	buku(const string& judul) : judul_buku(judul) {}
	string get_judul_buku() {
		return judul_buku;
	}
};

class pengarang {
private:
	vector<buku*> daftar_buku;
public:
	string nama;
	vector<penerbit*> daftar_penerbit;

	pengarang(string pNama) :nama(pNama) {
		cout << "";
	}
	~pengarang() {
		cout << "";
	}

	void tambahPenerbit(penerbit*);
	void cetakPenerbit();
};

void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}

void penerbit::cetakPengarang() {
	cout << "Daftar buku yang dikarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void pengarang::tambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
	pPenerbit->tambahPengarang(this);
}
void pengarang::cetakPenerbit() {
	cout << "Daftar pengarang pada penerbit = \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}


int main() {
	pengarang* varPengarang1 = new pengarang("Gama press");
	pengarang* varPengarang2 = new pengarang("intan pariwara");
	penerbit* varPenerbit1 = new penerbit("joko");
	penerbit* varPenerbit2 = new penerbit("lia");
	penerbit* varPenerbit3 = new penerbit("giga");
	penerbit* varPenerbit4 = new penerbit("asroni");
	buku fisika("Fisika");
	buku algoritma("Algoritma");
	buku basisdata("Basisdata");
	buku dasar_pemrograman("Dasar Pemrograman");
	buku matematika("Matematika");
	buku multimedia_1("Multimedia 1");

	varPengarang1->tambahPenerbit(varPenerbit1);
	varPengarang1->tambahPenerbit(varPenerbit2);
	varPengarang2->tambahPenerbit(varPenerbit4);
	varPengarang1->tambahPenerbit(varPenerbit3);
	varPengarang2->tambahPenerbit(varPenerbit3);

	varPengarang1->cetakPenerbit();
	varPengarang2->cetakPenerbit();
	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();
	varPenerbit3->cetakPengarang();
	varPenerbit4->cetakPengarang();

	delete varPenerbit1;
	delete varPenerbit2;
	delete varPengarang1;
	delete varPengarang2;
	delete varPenerbit3;
	delete varPenerbit4;
	return 0;
}