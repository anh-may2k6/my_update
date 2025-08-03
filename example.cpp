#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

struct student{
    string id;
    string name; 
    string birth;
    int age;
    string lop;
};

int calculate_age(const string &birth){
    int d,m,y;
    char slash;
    stringstream ss(birth);
    ss >> d >> slash >> m >> slash >> y;
    int current_year = 2025;
    return current_year-y;
}

bool cmp(const student &a,const student &b){
    if(a.age != b.age) return a.age > b.age;
    return a.id < b.id;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    vector<student> sv(n);
    for(int i=0;i<n;i++){
        getline(cin , sv[i].id);
        getline(cin , sv[i].name);
        getline(cin , sv[i].birth);
        getline(cin , sv[i].lop);

        sv[i].age = calculate_age(sv[i].birth);
    }
    sort(sv.begin(),sv.end(),cmp);
    cout << "Danh sach sau khi sap xep:" << endl;
    for(auto x : sv){
        cout << x.id << " | " << x.name << " | " << x.birth << " | " << x.age << " | " << x.lop << endl;
    }
    return 0;
}