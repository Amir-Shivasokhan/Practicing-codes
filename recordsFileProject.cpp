#include<iostream>
#include<fstream>
using namespace std;

struct infoStu {
    char name[50];
    char surname[50];
    float score_1;
    float score_2;
};

int main(){

    infoStu stu = {"Nick", "Johnson", 9, 10};

    fstream file;
    file.open("record.data", ios::out | ios::binary);
    if(file.is_open()){

        file.write(reinterpret_cast<char*>(&stu), sizeof(infoStu));
        file.close();
    }
    else 
        cout<<"\n ERRORE!!! ";
    
    
    infoStu newStu;

    file.open("record.data", ios::out | ios::binary);

    if(file.is_open()){
        file.read(reinterpret_cast <char*> (&newStu), sizeof(infoStu));
        file.close();
    }
    else{
        cout<<"\n ERROR!!!";
    }

    cout<<"\n The students information : " << endl; 
    cout<<"\n Name --> " << newStu.name;
    cout<<"\n Surname --> " << newStu.surname;
    cout<<"\n The first test score --> " << newStu.score_1;
    cout<<"\n The second test score --> " << newStu.score_2;


    cout<<endl;
    return 0;
}
