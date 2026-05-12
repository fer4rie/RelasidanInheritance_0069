#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class user
class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    User(string n, string e) : nama(n), email(e) {
        id = generateId();
        cout << "User \"" << nama << "\" dibuat\n";
    }

    virtual ~User() {
        cout << "User \"" << nama << "\" dihapus\n";
    }

    int generateId() {
        return ++globalId;
    }
};

int User::globalId = 0;

// class member (turunan)
class Member : public User {
private:
    bool status;

public:
    Member(string n, string e) : User(n, e), status(true) {
        cout << "Member \"" << nama << "\" dibuat\n";
    }

    ~Member() {
        cout << "Member \"" << nama << "\" dihapus\n";
    }

    void setStatus(bool s) { status = s; }
    bool getStatus() const { return status; }
    string getNama() const { return nama; }

    void showProfile() {
        cout << "ID: " << id << " | Nama: " << nama 
             << " | Email: " << email 
             << " | Status: " << (status ? "Aktif" : "Nonaktif") << endl;
    }
};

// class admin (turunan)
class Admin : public User {
public:
    Admin(string n, string e) : User(n, e) {
        cout << "Admin \"" << nama << "\" dibuat\n";
    }

    ~Admin() {
        cout << "Admin \"" << nama << "\" dihapus\n";
    }

    void showAllMember(vector<Member>& members) {
        cout << "\n--- Daftar Seluruh Member ---" << endl;
        for (auto& m : members) {
            m.showProfile();
        }
    }

    void toggleActivationMember(Member& m) {
        m.setStatus(!m.getStatus());
        cout << "Status " << m.getNama() << " berhasil diubah." << endl;
    }
};

// main
int main() {
    Admin admin1("Admin", "admin@mail.com");
    
    vector<Member> listMember;
    listMember.push_back(Member("Fira", "fira@mail.com"));
    listMember.push_back(Member("Tana", "tana@mail.com"));

    admin1.showAllMember(listMember);
    admin1.toggleActivationMember(listMember[0]);
    admin1.showAllMember(listMember);

    return 0;
}