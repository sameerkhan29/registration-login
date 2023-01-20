#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ios;
using std::ofstream;

string fs = "registrationlo.db";
string sf =  "registrationps.db";

int indexfinder(vector<string> a ,string word ){
    int k=0;

    for(string i : a){
        if(i == word){
            
            return k;
        }
        else{
            k++;
        }
    }
    return -1;
}
bool checking(string username, string password11){
    vector<string> usern;
    vector<string> password;
    ifstream file1;
    ifstream file2;
    file1.open(fs);
    file2.open(sf);
    string usps;
    while(getline(file1,usps)){
        usern.push_back(usps);

    }
    while(getline(file2,usps)){
        password.push_back(usps);

    }
    int indexofusername = indexfinder(usern,username);
    string passonidex;
    if(indexofusername == -1){ 
        passonidex = "";
    }
    else{
        passonidex = password[indexofusername] ;
    }
    
    if(passonidex == password11    ){
        
        return true;

    }
    else {
        cout<<"incorrect password"<<std::endl;
        return false;
    }
}

void passanduser(){
    string usr ;
    string pss;
    cout<<"username : ";
    cin>>usr;
    cout<<"password : ";
    cin>>pss;
    if (checking(usr,pss)){
        cout<<"login...sucessfull";

    }
    else{
        passanduser();
    }
}
int main(){
    
    passanduser();

}