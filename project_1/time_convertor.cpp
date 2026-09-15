#include<iostream>
using namespace std;
class Time_convertor{
    int sec,min,hr,total_sec;
    public:
        void sec_hr(int sec){
            hr=sec/3600;
            sec=sec%3600;
            min=sec/60;
            sec=sec%60;
            cout<< "Seconds to HH:MM:SS: "<< hr << ":" << min << ":" << sec<< endl;
        }
        void hr_sec(int hr,int min, int sec){
            total_sec=hr*3600+min*60+sec;
            cout<< "HH:MM:SS to second: "<< total_sec<< endl;
        }
};
int main(){
    int choice,sec,min,hr ;
    cout<< "For seconds to HH:MM:SS => 1 "<< endl;
    cout<< "For HH:MM:SS to seconds => 2 "<<endl;
    cout<<"Enter your choice: ";
    cin>> choice;

    switch(choice){
        case 1:
            cout<< "Enter total seconds: ";
            cin>> sec;   
            Time_convertor t1;
                t1.sec_hr(sec);
            break;
        case 2:
            cout<< "Enter hour: ";
            cin>> hr;  
            cout<< "Enter minutes: ";
            cin>> min;  
            cout<< "Enter seconds: ";
            cin>> sec;  
            Time_convertor t2;
                t2.hr_sec(hr,min,sec);
            break;
        default:
            cout << "Invalid choice!";
    }
    return 0;
}