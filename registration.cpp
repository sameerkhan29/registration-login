#include<iostream>
#include<vector>
#include<fstream>
using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::vector;
string fs = "registrationlo.db";
string sf = "registrationps.db";
void check_file(string a){
    ifstream file1;
    file1.open(a);
    if(file1){
        file1.close();
    }
    else  {
        ofstream file2;
        file2.open(a);
        file2.close();
    }
}

bool check_username(string usernames){
    ifstream file;
    file.open(fs);
    std::vector<string> username ;
    string sa;

    while(getline(file,sa)){
        username.push_back(sa);

    }
    file.close();
    for(string i : username){
        if(i == usernames){
            cout<<"Username already exist ";
            return true ;

        }
        else {

        }
    }
    return false ;


}
void add_username(string user1){
    ofstream file;
    file.open(fs,std::ios::app);
    file<<user1<<std::endl;
    file.close();

}
void username_create(){
    check_file(fs);
    string userid;

    cout<<"username : ";
    cin>>userid;

    if(check_username(userid)){
        username_create();
    }
    else {
        add_username(userid);
    }
}
bool password_check(string passs){
    int length = passs.length();
    if(length < 8){
        cout<<"password length is small";
        return true ;
    }
    else {
        return false ;

    }
}
void password_add(string passss){
    ofstream file;
    file.open(sf,std::ios::app);
    file<<passss<<std::endl;
    file.close();
}
bool password_create(){
    check_file(sf);
    string a ;
    cout<<"password : ";
    cin>>a;

    if(password_check(a)){
        password_create();

    }
    else{
        password_add(a);
    }

}
int main(){
    username_create();
    password_create();

}