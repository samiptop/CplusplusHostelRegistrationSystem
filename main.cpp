#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <sstream>
using namespace std;

class Hostel {
    private:
     string Name;
     int Rent,Bed;

    public:
     Hostel(string name,int rent, int bed) {
        Name=name;
        Rent=rent;
        Bed=bed;
     } 
     string getName(){
     return Name;
     }
     int getRent(){
     return Rent;
     }
     int getBed(){
     return Bed;
     }

     void reserve(){
        ifstream in("D:\C++\Beginner Projects !\Hostel Accommodation System!\hostel.txt");
        ofstream out("D:\C++\Beginner Projects !\Hostel Accommodation System!\hostel temp.txt");
        string line;
        while(getline(in,line)){
          int pos = line.find("AStar");
          if(pos != string::npos) {
            int bed = Bed-1;
            Bed = bed;
            stringstream ss;
            ss<<bed;
            string strBed = ss.str();

            int bedPos = line.find_last_of(':');
            line.replace(bedPos+1,string::npos,strBed);


          }
          out<<line<<endl;
        }
        out.close();
        in.close();
        remove("D:\C++\Beginner Projects !\Hostel Accommodation System!\hostel.txt");
        rename("D:\C++\Beginner Projects !\Hostel Accommodation System!\hostel temp.txt","D:\C++\Beginner Projects !\Hostel Accommodation System!\hostel.txt");
        cout <<"\tBed Reserved Successfully" <<endl;
        
     }

};

class Student {
    private:
      string Name,RollNo,Address;
      
    public:  
    Student():Name(""),RollNo(""),Address("") {}

    void setName(string name) {
        Name=name;
    }
    void setRollNo(string rollNo) {
        RollNo=rollNo;
    }
    void setAddress(string address) {
        Address=address;
    }
    string getName(){
        return Name;
    }
    string getRollNo(){
        return RollNo;
    }
    string getAddress(){
        return Address;
    }
};

int main(){
    Hostel h("AStar",12000,30);
    ofstream out("D:\C++\Beginner Projects !\Hostel Accommodation System!\hostel.txt");
    out <<"\t"<<h.getName()<<" : "<<h.getRent()<<" : "<<h.getBed()<<endl<<endl;
    cout <<"Hostel Data Saved" <<endl;
    out.close();
    Student s;
    bool exit = false;

    while(!exit){
        system("cls");
        int val;
        cout<<"\tWelcome To Hostel Accommodation Platform"<<endl;
        cout<<"\t****************************************"<<endl;
        cout<<"\tPress 1 To Reserve A Bed"<<endl;
        cout<<"\tPress 2 To Exit"<<endl;
        cout<<"\tPlease Enter Your Choice :";
        cin >> val;

        if (val==1) {
            system("cls");
            string name,rollNo,address;
            cout << "\tEnter Name of Student:" <<endl;
            cin >> name;
            s.setName(name);
            cout << "\tEnter the Roll No of Student" <<endl;
            cin >> rollNo;
            s.setRollNo(rollNo);
            cout << "\tEnter the Address of the Student" <<endl;
            cin >> address;
            s.setAddress(address);

            if(h.getBed()>0) {
                h.reserve();
            }
             else if(h.getBed()==0) {
                cout << "\tSorry,No Bed Available" << endl;
             }

            ofstream outFile("D:\C++\Beginner Projects !\Hostel Accommodation System!\student.txt",ios::app);
            outFile<<"\t"<<s.getName()<<" : "<<s.getRollNo()<<" : "<<s.getAddress()<<endl<<endl;
            Sleep(5000); 
           }

        else if(val==2) {
            system("cls");
            exit = true;
            cout << " All the Best " <<endl;
            Sleep(3000);
            }
        
    }
}




