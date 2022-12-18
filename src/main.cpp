#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class AttendanceSystem {
private:
    unordered_map<string, bool> attendance;

public:
    AttendanceSystem() {
    }

    void mark_present(string name) {
        attendance[name] = true;
        cout << name << " ditandai hadir." << endl;
    }

    void mark_absent(string name) {
        attendance[name] = false;
        cout << name << " ditandai tidak hadir." << endl;
    }

    void check_attendance() {
        cout << "================ KEHADIRAN ================" << endl;
        for (auto& [name, present] : attendance) {
            cout << name << ": " << (present ? "hadir" : "tidak hadir") << endl;
        }
        cout << "===========================================" << endl;
    }
};

int main() {
    AttendanceSystem as;

    cout << "=============== APLIKASI ABSENSI EKSKUL ===============" << endl;

    bool exit = false;

    while (!exit) {
        cout << "1. Buat Absensi" << endl;
        cout << "2. Cek Absensi" << endl;
        cout << "3. Keluar Aplikasi" << endl;
        cout << "Masukan pilihan [1-3]: ";

        int action;
        cin >> action;

        switch (action) {
            case 1: {
                system("cls");
                cout << "Masukan nama siswa: ";
                string name;
                cin >> name;
                cout << "Apakah siswa hadir? (y/n)" << endl;
                char present;
                cin >> present;
                if (present == 'y') {
                    as.mark_present(name);
                } else {
                    as.mark_absent(name);
                }
                break;
            }
            case 2: {
                system("cls");
                as.check_attendance();
                break;
            }
            case 3: {
                system("cls");
                exit = true;
                break;
            }
            default: {
                system("cls");
                cout << "Invalid action." << endl;
                break;
            }
        }
    }

    return 0;
}