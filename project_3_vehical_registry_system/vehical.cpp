#include<iostream>
#include<cstring>
using namespace std;
class vehicle{
    protected: 
        int vehicleID;
        char* manufacturer;
        char* model;
        int year;
        static int totalVehicle;
    public:
        vehicle(){
            vehicleID=0;
            manufacturer = new char[1];
            strcpy(manufacturer,"");
            model = new char[1];
            strcpy(model,"");
            year=0;
            totalVehicle++;
        }
        vehicle(int id, const char* man, const char* m, int yr){
            vehicleID=id;
            manufacturer = new char[strlen(man)+1];
            strcpy(manufacturer,man);
            model = new char[strlen(m)+1];
            strcpy(model,m);
            year=yr;
            totalVehicle++;
        }
        ~vehicle(){
            delete[] manufacturer;
            delete[] model;
        }
        virtual void display(){
            cout << "ID: " << vehicleID 
                 << " | Manufacturer: " << manufacturer
                 << " | Model: " << model
                 << " | Year: " << year << endl;
        }
        //getters
        int getID(){ return vehicleID; }
        char* getMan(){ return manufacturer; }
        char* getModel(){ return model; }
        int getYear(){ return year; }
};
class car: virtual public vehicle{
    protected:
        char* fuelType;
    public:
        car(int id, const char* man, const char* m, int yr, const char* fuel): vehicle(id,man,m,yr){
            fuelType = new char[strlen(fuel)+1];
            strcpy(fuelType,fuel);
        }
        void setfuel(char* fuel){
            fuelType=fuel;
        }
        char* getfuel(){
            return fuelType;
        }
        ~car(){
            delete[] fuelType;
        }
        void displayCar(){

        }
         void display() override {
            cout<< "---- CAR DETAILS----"<< endl;
            cout << "[Car] ID: " << vehicleID 
                 << " | Manufacturer: " << manufacturer
                 << " | Model: " << model
                 << " | Year: " << year
                 << " | Fuel Type: " << fuelType << endl;
        }
};
class electricCar: public car{
    protected:
        int batteryCapacity;
    public:
        electricCar(int id, const char* man, const char* m, int yr, const char* fuel, int cap): car(id,man,m,yr,fuel){
            batteryCapacity=cap;
        }
        void setCap(int cap){
            batteryCapacity=cap;
        }
        int getCap(){
            return batteryCapacity;
        }
        void display() override {
            cout<< "---- ELECTRIC CAR DETAILS----"<< endl;
            cout << "[Electric Car] ID: " << vehicleID
                 << " | Manufacturer: " << manufacturer
                 << " | Model: " << model
                 << " | Year: " << year
                 << " | Fuel Type: " << fuelType
                 << " | Battery Capacity: " << batteryCapacity << endl;
        }
};
class Aircraft: virtual public vehicle{
    protected: 
        int flightRange;
    public:
        Aircraft(int id, const char* man, const char* m, int yr, int range ): vehicle(id,man,m,yr){
            flightRange=range;
        }
        void setRange(int range){
            flightRange=range;
        }
        int getRange(){
            return flightRange;
        }
        void display() override {
            cout<< "---- AIRCREAFT DETAILS----"<< endl;
            cout << "[Aircraft] ID: " << vehicleID
                 << " | Manufacturer: " << manufacturer
                 << " | Model: " << model
                 << " | Year: " << year
                 << " | Flight Range: " << flightRange << endl;
        }
};
class flyingCar: public car, public Aircraft {
    public:
    flyingCar(int id, const char* man, const char* m, int yr, int range, const char* fuel): Aircraft(id,man,m,yr,range), car(id,man,m,yr,fuel),vehicle(id, man, m, yr){
    }
    void display() override {
        cout<< "---- FLYING CAR DETAILS----"<< endl;
            cout << "[Flying Car] ID: " << vehicleID
                 << " | Manufacturer: " << manufacturer
                 << " | Model: " << model
                 << " | Year: " << year
                 << " | Fuel Type: " << fuelType
                 << " | Flight Range: " << flightRange << endl;
        }
};
class sportCar: public electricCar{
    protected:
        int topSpeed;
    public:
        sportCar(int id, const char* man, const char* m, int yr, const char* fuel, int cap, int top): electricCar(id,man,m,yr,fuel,cap){
            topSpeed=top;
        }
        void settop(int top){
            topSpeed=top;
        }
        int gettop(){
            return topSpeed;
        }
        void display() override {
            cout<< "---- SPORTS CAR DETAILS----"<< endl;
            cout << "[Sport Car] ID: " << vehicleID
                 << " | Manufacturer: " << manufacturer
                 << " | Model: " << model
                 << " | Year: " << year
                 << " | Fuel Type: " << fuelType
                 << " | Battery Capacity: " << batteryCapacity
                 << " | Top Speed: " << topSpeed << endl;
        }
};
class sedan: public car{
    public:
    sedan(int id, const char* man, const char* m, int yr, const char* fuel): car(id,man,m,yr,fuel){
    }
    void display() override {
        cout<< "---- SEDAN DETAILS----"<< endl;
            cout << "[Sedan] ID: " << vehicleID
                 << " | Manufacturer: " << manufacturer
                 << " | Model: " << model
                 << " | Year: " << year
                 << " | Fuel Type: " << fuelType << endl;
        }
};
class SUV: public car{
public:
    SUV(int id, const char* man, const char* m, int yr, const char* fuel):  car(id,man,m,yr,fuel){
    }
    void display() override {
            cout<< "---- SUV DETAILS----"<< endl;
            cout << "[SUV] ID: " << vehicleID
                 << " | Manufacturer: " << manufacturer
                 << " | Model: " << model
                 << " | Year: " << year
                 << " | Fuel Type: " << fuelType << endl;
        }
};
int vehicle::totalVehicle=0;
class vehicleRegistry{
    private:
        vehicle* v1[100];
        int count;
    public:
        vehicleRegistry(){
            count=0;
        }
        void addCar(int id, const char* man, const char* m, int yr, const char* fuel){
            v1[count] = new car(id,man,m,yr,fuel);
            count++;
        }
        void addElectricCar(int id, const char* man, const char* m, int yr, char* fuel, int cap){
            v1[count] = new electricCar(id,man,m,yr,fuel,cap);
            count++;
        }
        void addAircraft(int id, const char* man, const char* m, int yr, int range){
        v1[count] = new Aircraft(id, man, m, yr, range);
        count++;
    }
    void addFlyingCar(int id, const char* man, const char* m, int yr, int range, const char* fuel){
        v1[count] = new flyingCar(id, man, m, yr, range, fuel);
        count++;
    }
    void addSportCar(int id, const char* man, const char* m, int yr, const char* fuel, int cap, int top){
        v1[count] = new sportCar(id, man, m, yr, fuel, cap, top);
        count++;
    }
    void addSedan(int id, const char* man, const char* m, int yr, const char* fuel){
        v1[count] = new sedan(id, man, m, yr, fuel);
        count++;
    }
    void addSUV(int id, const char* man, const char* m, int yr, const char* fuel){
        v1[count] = new SUV(id, man, m, yr, fuel);
        count++;
    }
    void displayAll(){
        if(count==0){
            cout<<"----No data added-----"<< endl;
            return;
        }
        for(int i=0;i<count;i++){
            cout << "\n--- Vehicle " << i+1 << " ---" << endl;
            v1[i]->display();
        }
    }
    void searchbyID(int id){
        for(int i=0;i<count;i++)
            if(v1[i]->getID()==id){
                cout<<"Vehicle Found..."<<endl;
                v1[i]->display();
                return;
            }
    }
};
int main(){
    int choice;
    vehicleRegistry vr1;

    do{
        cout<< "1.Add a vehicle (of a different type) \n2. View all vehicles  \n3. Search by Id  \n4. Exit"<< endl;
        cout<< "Enter choice: ";
        cin>> choice;

        if(choice==1){
            int type;
            cout<<"1.Car \n2.Electric Car \n3.Aircraft \n4.Flying Car \n5.Sports Car \n6.Sedan \n7.SUV "<< endl;
            cout<< "Enter type of vehicle: ";
            cin>>type;
            switch(type){
                case 1: {
                    int id,yr; char man[50],m[50],fuel[50];
                    cout<<"Enter ID: ";
                    cin>>id;
                    cout<<"Enter Manufacturer: ";
                    cin>>man;
                    cout<<"Enter Model: ";
                    cin>>m;
                    cout<<"Enter year: ";
                    cin>>yr;
                    cout<<"Enter Fuel Type: ";
                    cin>>fuel;
                    vr1.addCar(id,man,m,yr,fuel);
                    break;
                }
                case 2: {
                    int id, yr, cap; char man[50], m[50], fuel[50];
                    cout << "Enter ID: "; cin >> id;
                    cout << "Enter Manufacturer: "; cin >> man;
                    cout << "Enter Model: "; cin >> m;
                    cout << "Enter Year: "; cin >> yr;
                    cout << "Enter Fuel Type: "; cin >> fuel;
                    cout << "Enter Battery Capacity: "; cin >> cap;
                    vr1.addElectricCar(id, man, m, yr, fuel, cap);
                    break;
                }
                case 3: {
                    int id, yr, range; char man[50], m[50];
                    cout << "Enter ID: "; cin >> id;
                    cout << "Enter Manufacturer: "; cin >> man;
                    cout << "Enter Model: "; cin >> m;
                    cout << "Enter Year: "; cin >> yr;
                    cout << "Enter Flight Range: "; cin >> range;
                    vr1.addAircraft(id, man, m, yr, range);
                    break;
                }
                case 4: {
                    int id, yr, range; char man[50], m[50], fuel[50];
                    cout << "Enter ID: "; cin >> id;
                    cout << "Enter Manufacturer: "; cin >> man;
                    cout << "Enter Model: "; cin >> m;
                    cout << "Enter Year: "; cin >> yr;
                    cout << "Enter Flight Range: "; cin >> range;
                    cout << "Enter Fuel Type: "; cin >> fuel;
                    vr1.addFlyingCar(id, man, m, yr, range, fuel);
                    break;
                }
                case 5: {
                    int id, yr, cap, top; char man[50], m[50], fuel[50];
                    cout << "Enter ID: "; cin >> id;
                    cout << "Enter Manufacturer: "; cin >> man;
                    cout << "Enter Model: "; cin >> m;
                    cout << "Enter Year: "; cin >> yr;
                    cout << "Enter Fuel Type: "; cin >> fuel;
                    cout << "Enter Battery Capacity: "; cin >> cap;
                    cout << "Enter Top Speed: "; cin >> top;
                    vr1.addSportCar(id, man, m, yr, fuel, cap, top);
                    break;
                }
                case 6: {
                    int id, yr; char man[50], m[50], fuel[50];
                    cout << "Enter ID: "; cin >> id;
                    cout << "Enter Manufacturer: "; cin >> man;
                    cout << "Enter Model: "; cin >> m;
                    cout << "Enter Year: "; cin >> yr;
                    cout << "Enter Fuel Type: "; cin >> fuel;
                    vr1.addSedan(id, man, m, yr, fuel);
                    break;
                }
                case 7: {
                    int id, yr; char man[50], m[50], fuel[50];
                    cout << "Enter ID: "; cin >> id;
                    cout << "Enter Manufacturer: "; cin >> man;
                    cout << "Enter Model: "; cin >> m;
                    cout << "Enter Year: "; cin >> yr;
                    cout << "Enter Fuel Type: "; cin >> fuel;
                    vr1.addSUV(id, man, m, yr, fuel);
                    break;
                }
                default:
                    cout << "Invalid vehicle type." << endl;
            }
        }
        else if(choice==2){
            cout<< "-------- VEHICLE DETAILS--------"<< endl;
            vr1.displayAll();
        }
        else if(choice==3){
            int id;
            cout<<"Enter ID of the vehicle: ";
            cin>>id;
            vr1.searchbyID(id);
        }

    }while(choice!=4);

    return 0;
}