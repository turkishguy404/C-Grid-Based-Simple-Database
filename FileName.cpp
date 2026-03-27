#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Database {
private:
    string data[100][100];
    bool filled[100][100];

public:
    Database() {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                filled[i][j] = false;
            }
        }
    }

    void add(int x, int y, string word) {
        if (x >= 0 && x < 100 && y >= 0 && y < 100) {
            data[x][y] = word;
            filled[x][y] = true;
            cout << "Eklendi!\n";
        }
        else {
            cout << "Gecersiz koordinat!\n";
        }
    }

    void search(string word) {
        int count = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (filled[i][j] && data[i][j] == word) {
                    cout << "[" << i << "][" << j << "] -> " << data[i][j] << "\n";
                    count++;
                }
            }
        }

        if (count == 0) {
            cout << "Bulunamadi!\n";
        }
        else {
            cout << "Toplam " << count << " sonuc.\n";
        }
    }

    void listAll() {
        int count = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (filled[i][j]) {
                    cout << count + 1 << ". [" << i << "][" << j << "] = " << data[i][j] << "\n";
                    count++;
                }
            }
        }
        cout << "Toplam: " << count << " kelime\n";
    }

    void saveToFile() {
        ofstream file("database.txt");
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (filled[i][j]) {
                    file << i << "," << j << "," << data[i][j] << "\n";
                }
            }
        }
        file.close();
        cout << "Dosyaya kaydedildi!\n";
    }

    void remove(int x, int y) {
        if (filled[x][y]) {
            filled[x][y] = false;
            data[x][y] = "";
            cout << "Silindi!\n";
        }
        else {
            cout << "Bu konumda kelime yok!\n";
        }
    }
};

int main() {
    Database db;
    int choice;

    while (true) {
        cout << "\n===========================\n";
        cout << "    DATABASE MENU\n";
        cout << "===========================\n";
        cout << "1. Kelime ekle\n";
        cout << "2. Kelime ara\n";
        cout << "3. Tum kelimeleri listele\n";
        cout << "4. Kelime sil\n";
        cout << "5. Dosyaya kaydet\n";
        cout << "0. Cikis\n";
        cout << "Seciminiz: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) {
            cout << "Cikiliyor...\n";
            break;
        }

        switch (choice) {
        case 1: {
            int x, y;
            string word;
            cout << "X: "; cin >> x;
            cout << "Y: "; cin >> y;
            cin.ignore();
            cout << "Kelime: "; getline(cin, word);
            db.add(x, y, word);
            break;
        }
        case 2: {
            string word;
            cout << "Ara: "; getline(cin, word);
            db.search(word);
            break;
        }
        case 3:
            db.listAll();
            break;
        case 4: {
            int x, y;
            cout << "X: "; cin >> x;
            cout << "Y: "; cin >> y;
            db.remove(x, y);
            break;
        }
        case 5:
            db.saveToFile();
            break;
        default:
            cout << "Hatali secim!\n";
        }
    }

    return 0;
}