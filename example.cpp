#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <ctime>

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
    char slash; // gán để loại bỏ dấu gạch chéo
    stringstream ss(birth); // tách từng string 
    ss >> d >> slash >> m >> slash >> y; // lấy ngày tháng năm sinh ra gán kiểu int
    time_t now = time(0); // lấy time hiện tại
    tm *ltm = localtime(&now); // gọi 1 con trỏ có struct sẵn 

    int cur_day = ltm->tm_mday; //tm_mday là ngày trong tháng 
    int cur_moth = 1 + ltm->tm_mon; //tm_mon là tháng trong năm (mặc đinh là từ 0-11)
    int cur_year = 1900 + ltm->tm_year; //tm_year là năm từ 1900 đổ lên

    int age = cur_year - y;

    if(cur_moth < m || (cur_moth == m && cur_day < d)){
        age--; // chưa đủ tuổi thì trừ
    }

    return age;
}

bool cmp(const student &a,const student &b){
    if(a.age != b.age) return a.age > b.age; // sắp xếp theo độ tuổi lớn nhất
    return a.id < b.id; // sắp xếp theo id từ bé đến lớn
}

int main(){
    ios::sync_with_stdio(false); // loại bỏ liên kết giữa cin và scanf để cho code được chạy nhanh hơn
    cin.tie(nullptr); // khi cin , ko cần cout phải đợi 
    int n;
    cin >> n;
    cin.ignore(); // loại bỏ dấu \n ra khỏi bộ nhớ đệm
    vector<student> sv(n); // n vector sinh viên
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
