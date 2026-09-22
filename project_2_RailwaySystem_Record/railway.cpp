#include<iostream>
#include<cstring>
using namespace std;
class train{
    private:
        int trainNumber;
        char trainName[50];
        char source[50];
        char destination[50];
        char trainTime[10];
        static int trainCount;
    public:
        train(){             // defualt constructor   
            trainNumber=0;
            strcpy(trainName,"");
            strcpy(source,"");
            strcpy(destination,"");
            strcpy(trainTime,"");
            trainCount++;
        } 
        train(int num, const char name[50], const char src[50], const char dest[50], const char time[50]){     // paramerterized constructor
            trainNumber=num;
            strcpy(trainName,name);
            strcpy(source,src);
            strcpy(destination,dest);
            strcpy(trainTime,time);
            trainCount++;
        }
        ~train(){
            trainCount--;
        }
        //getters
        int getNumber(){
            return trainNumber;
        }
        const char* getTrainName(){
            return trainName;
        }
        const char* getSource(){
            return source;
        }
        const char* getdestination(){
            return destination;
        }
        const char* getTraintime(){
            return trainTime;
        }
        //setters
        void setTraiNumber(int num){
            trainNumber=num;
        }
        void setTraiName(const char name[50]){
            strcpy(trainName,name);
        }
         void setSource(const char src[50]){
            strcpy(source,src);
        }
        void setDestination(const char dest[50]){
             strcpy(destination, dest);
        }
        void setTrainTime(const char time[10]){
             strcpy(trainTime, time);
        }
        // all input details which obtained from user
        void inputTrainDetails(){
            cout<<  "Enter Train number: ";
            cin>> trainNumber;
            cin.ignore();   
            cout<<"Enter train name: ";
            cin.getline(trainName,50);
            cout<<"Enter source: ";
            cin.getline(source,50);;
            cout<<"Enter destination: ";
            cin.getline(destination,50);
            cout<<"Enter train time: ";
            cin.getline(trainTime,10);

        }
        // display train records
        void displayTrainDetails(){
            cout<< "------Railway Reservation system------"<<endl;
            cout<<"Train number: "<< trainNumber 
                << " | Train name: "<< trainName
                << " | Source: "<< source
                << " | Destination: "<<destination
                << " | Time of the train: "<< trainTime<< endl;
        }
        int getTrainCount(){
            cout<< "Total number of trains: "<< trainCount<< endl;
            return trainCount; 
        }
       
};
int train::trainCount=0;
class railwaySystem{
    private:
        train Train[100];
        int totalTrains;
    public:
        railwaySystem(){
            totalTrains=0;
        }
         void addTrains(){
            if(totalTrains>100){
                cout<< "The system is full , You cannot add more. ";
            }

            Train[totalTrains].inputTrainDetails();
            totalTrains++;
        }
        void displayAllTrains(){
            if(totalTrains==0){
                cout<< "No data added before. ";
            }
            for(int i=0;i<totalTrains;i++){
                cout<< "-----Details of train "<< i+1<<"-----"<< endl;
                Train[i].displayTrainDetails();
            }
        }
        void searchByTrainNumber(){
            int num;
            cout << "Enter train number to search: ";
            cin >> num;                           

            for(int i=0;i<totalTrains;i++){
                Train[i].getNumber();
                if(Train[i].getNumber()==num){
                    cout<<"Train found...!"<<endl;
                    Train[i].displayTrainDetails();
                }
                else{
                    cout<<"Train not found"<<endl;
                }
            }
        }
};
int main(){
    railwaySystem obj;
        int num,choice;
        char name[50];
        char src[50];
        char dest[50];
        char time[10];

       do{
            cout<< "1. Add New Train Record"<<endl;
            cout<< "2. Display All Train Records"<<endl;
            cout<< "3. Search Train by Number"<<endl;
            cout<< "4. Exit"<<endl;
            cout<< "Enter your choice: ";
            cin>> choice;
         switch(choice){
            case 1:
                obj.addTrains(); 
                break;
            case 2: 
                obj.displayAllTrains();
                break;
            case 3: 
                obj.searchByTrainNumber();
                break;
            case 4:
                cout<<"---Compelete---"<<endl;
                break;
            default:
                cout<< "|| Invalid choice ||"<< endl;
                break;
        }
       }while(choice != 4);
    return 0; 
}