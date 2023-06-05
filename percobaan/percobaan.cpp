#include <iostream>
#include <vector>
#include <string>
using namespace std;

class pengarang;
class penerbit {
private:
    string nama_penerbit;
    vector<pengarang*> daftar_pengarang;
public:
    penerbit(const string& nama) : nama_penerbit(nama) {}
    void tambah_pengarang(pengarang* pengarang) {
        daftar_pengarang.push_back(pengarang);
    }
    void daftar_pengarang() {
        cout << "Daftar pengarang pada penerbit\"" << nama_penerbit << "\":" << endl;
        for (auto& pengarang : daftar_pengarang) {
            cout << pengarang->get_nama_pengarang() << endl;
        }
        cout << endl;
    }
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
    string nama_pengarang;
    vector<buku*> daftar_buku;
public:
    pengarang(const string& nama) : nama_pengarang(nama) {}
    void tambah_buku(buku* buku) {
        daftar_buku.push_back(buku);
    }
    string get_nama_pengarang() {
        return nama_pengarang;
    }
    void daftar_buku() {
        cout << "Daftar buku yang dikarang\"" << nama_pengarang << "\":" << endl;
        for (auto buku : daftar_buku) {
            cout << buku->get_judul_buku() << endl;
        }
        cout << endl;
    }
};


int main() {
    penerbit gama_press("Gama Press");
    penerbit intan_pariwara("Intan Pariwara");

    pengarang joko("Joko");
    pengarang lia("Lia");
    pengarang giga("Giga");
    pengarang asroni("Asroni");

    buku fisika("Fisika");
    buku algoritma("Algoritma");
    buku basisdata("Basisdata");
    buku dasar_pemrograman("Dasar Pemrograman");
    buku matematika("Matematika");
    buku multimedia_1("Multimedia 1");

    gama_press.tambah_pengarang(&joko);
    gama_press.tambah_pengarang(&lia);
    gama_press.tambah_pengarang(&giga);

    intan_pariwara.tambah_pengarang(&asroni);
    intan_pariwara.tambah_pengarang(&giga);

    joko.tambah_buku(&fisika);
    joko.tambah_buku(&algoritma);
    lia.tambah_buku(&basisdata);
    asroni.tambah_buku(&dasar_pemrograman);
}

