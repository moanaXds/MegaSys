#include <iostream>
#include <string>
using namespace std;

class Flight {
private:
    // Flight details
    string airline;
    string source;
    string sourceName;
    string destination;
    string destinationName;
    string departureDateTime;
    string arrivalDateTime;
    double duration;
    string stopovers;
    string aircraftType;
    string travelClass;
    string bookingSource;
    double baseFare;
    double taxSurcharge;
    double totalFare;
    string seasonality;
    int daysBeforeDeparture;

public:
    // Default Constructor
    Flight()
    {
        airline="";
        source="";
        sourceName="";
        destination="";
        destinationName=""; 
        departureDateTime="";
        arrivalDateTime="";
        duration=0.0;
        stopovers="";
        aircraftType="";
        travelClass="";
        bookingSource="";
        baseFare=0.0;
        taxSurcharge=0.0;
        totalFare=0.0;
        seasonality="";
        daysBeforeDeparture=0;
    }
    
    // Parameterized Constructor to initialize all flight details
    Flight(string airline, string source, string sourceName, string destination, string destinationName,
           string departureDateTime, string arrivalDateTime, double duration, string stopovers,
           string aircraftType, string travelClass, string bookingSource, double baseFare,
           double taxSurcharge, double totalFare, string seasonality, int daysBeforeDeparture)
           {
            this->airline=airline;
            this->source=source;
            this->sourceName=sourceName;
            this->destination=destination;
            this->destinationName=destinationName; 
            this->departureDateTime=departureDateTime;
            this->arrivalDateTime=arrivalDateTime;
            this->duration=duration;
            this->stopovers=stopovers;
            this->aircraftType=aircraftType;
            this->travelClass=travelClass;
            this->bookingSource=bookingSource;
            this->baseFare=baseFare;
            this->taxSurcharge=taxSurcharge;
            this->totalFare=totalFare;
            this->seasonality=seasonality;
            this->daysBeforeDeparture=daysBeforeDeparture; 
           }
    
    // Function to combine details of 2 flights
    // Add numeric values like duration, fares, etc., and keep text fields from first flight
    Flight combineFlight(const Flight& other) const
    {
        Flight f3( this->airline, this->source,  this->sourceName,  this->destination, this->destinationName,
            this->departureDateTime,  this->arrivalDateTime,  this->duration+ other.duration, this->stopovers,
            this->aircraftType, this->travelClass,  this->bookingSource,  this->baseFare+ other.baseFare, 
            this->taxSurcharge+ other.taxSurcharge, this->totalFare + other.totalFare,  this->seasonality,
            this->daysBeforeDeparture+ other.daysBeforeDeparture );    
        return f3;
    }

    // Function to add numeric values from another flight to this flight
    void addFlightValues(const Flight& other)    
    {
        this->duration= + other.duration;
        this->baseFare= + other.baseFare;
        this->taxSurcharge= + other.taxSurcharge;
        this->totalFare= + other.totalFare;
        this->daysBeforeDeparture= + other.daysBeforeDeparture;   
    }
    
    // Function to calculate fare difference between two flights
    double calculateFareDifference(const Flight& other) const
    {
        double diff=this->totalFare - other.totalFare;
        return diff;
    }

    // Function to subtract numeric values from this flight
    void subtractFlightValues(const Flight& other)
    {
        cout<<this->duration- other.duration;
        cout<<this->baseFare- other.baseFare;
        cout<<this->taxSurcharge- other.taxSurcharge;
        cout<<this->totalFare - other.totalFare;
        cout<<this->daysBeforeDeparture- other.daysBeforeDeparture;   
    }

    // Function to check if two flights are identical
    bool areFlightsEqual(const Flight& other) const
    {
        if(this->duration== other.duration && this->baseFare == other.baseFare && this->taxSurcharge== other.taxSurcharge &&
           this->totalFare ==  other.totalFare && this->daysBeforeDeparture ==  other.daysBeforeDeparture)
        {
            return true;
        }
        return false;
    }
    
    // Function to check if this flight has higher fare than another flight
    bool hasHigherFare(const Flight& other) const
    {
       return this->totalFare > other.totalFare;
    } 
    
    // Function to check if this flight has lower fare than another flight
    bool hasLowerFare(const Flight& other) const
    {
        return this->totalFare < other.totalFare;
    }

   // Function to check if this flight has higher or equal fare
   bool hasHigherOrEqualFare(const Flight& other) const
   {
        return this->totalFare >= other.totalFare;
   }

    // Function to check if this flight has lower or equal fare
    bool hasLowerOrEqualFare(const Flight& other) const
    {
        return this->totalFare <= other.totalFare;
    }

    // Function to check if flights are different
    bool areFlightsDifferent(const Flight& other) const
    {
        if(this->duration!= other.duration && this->baseFare != other.baseFare && this->taxSurcharge!= other.taxSurcharge &&
            this->totalFare !=  other.totalFare && this->daysBeforeDeparture !=  other.daysBeforeDeparture)
        {
            return true;
        }
        return false;          
    }    

    // Function to display flight details
    void displayFlight() const
    {
        cout<<airline<<endl;
        cout<<source<<endl;
        cout<<sourceName<<endl;
        cout<<destination<<endl;
        cout<<destinationName<<endl; 
        cout<<departureDateTime<<endl;
        cout<<arrivalDateTime<<endl;
        cout<<duration<<endl;
        cout<<stopovers<<endl;
        cout<<aircraftType<<endl;
        cout<<travelClass<<endl;
        cout<<bookingSource<<endl;
        cout<<baseFare<<endl;
        cout<<taxSurcharge<<endl;
        cout<<totalFare<<endl;
        cout<<seasonality<<endl;
        cout<<daysBeforeDeparture<<endl;
    } 
    
    // Function to input flight details from user
    void inputFlightDetails()
    {
        cin>>airline;
        cin>>source;
        cin>>sourceName;
        cin>>destination;
        cin>>destinationName; 
        cin>>departureDateTime;
        cin>>arrivalDateTime;
        cin>>duration;
        cin>>stopovers;
        cin>>aircraftType;
        cin>>travelClass;
        cin>>bookingSource;
        cin>>baseFare;
        cin>>taxSurcharge;
        cin>>totalFare;
        cin>>seasonality;
        cin>>daysBeforeDeparture;
    }   

    // Function to make all numeric values positive
    Flight makeValuesPositive() const
    {
        Flight f=*this;
        if(f.duration <0)f.duration=-f.duration ;
        if(f.baseFare <0)f.baseFare=-f.baseFare ;
        if(f.taxSurcharge <0)f.taxSurcharge=-f.taxSurcharge ;   
        if(f.totalFare <0)f.totalFare=-f.totalFare ;
        if(f.daysBeforeDeparture <0)f.daysBeforeDeparture=-f.daysBeforeDeparture ;

        return f;
    }
        
    // Function to make all numeric values negative
    Flight makeValuesNegative() const
    {
        Flight f=*this;
        if(f.duration >0)f.duration=-f.duration ;
        if(f.baseFare >0)f.baseFare=-f.baseFare ;
        if(f.taxSurcharge >0)f.taxSurcharge=-f.taxSurcharge ;  
        if(f.totalFare >0)f.totalFare=-f.totalFare ;
        if(f.daysBeforeDeparture >0)f.daysBeforeDeparture=-f.daysBeforeDeparture ;

        return f;
    }
};

/*
// Function to read flights from CSV file and return a dynamic array
Flight* readFlightsFromCSV(const string& filename, int& size)
{
    ifstream inputFile("Flight_Price_Dataset_of_Bangladesh.csv");

    if (!inputFile.is_open()) {
        cout << "Failed to open file!" << endl;
        return 1;
    }
    string line;
    int row = 0;
    while (getline(inputFile, line)) {
        stringstream lineStream(line);
        string cell;
        while (getline(lineStream, cell, ',')) 
		{
        	cout<<cell<<" ";
        }
        cout<<endl;
    }
    inputFile.close();
    return ;
}    
*/


int main()
{
    // Test your class here
    Flight f1(" United", "LAXIC0", "Angeles", "SFO", "Francisco",
              "12/02/24", "22/02/24", 22.0, "None",
              "wirbus", "Economy", "website", 101.0, 210.0, 1.0,
              "Spring", 3);

    Flight f2("Biman", "DAC", "Dhaka", "LHR", "London",
              "2025-04-01", "2/02/24", 9.0, "non-stop",
              "F 17", "Economy", "Traveloka", 40.0, 51.0, 50.0,
              "Spring", 415);

    cout << "Flight 1st : "<<endl;
    f1.displayFlight();

    cout <<endl<<"------------"<<endl;

    cout << "Flight 2nd : "<<endl;
    f2.displayFlight();

    cout <<endl<<"------------"<<endl;

    cout << "Both Combined : ";
    Flight f3=f1.combineFlight(f2);
    f3.displayFlight();

    cout <<endl<<"------------"<<endl;

    cout << "Fare difference: ";
    cout << f1.calculateFareDifference(f2);

    cout <<endl<<"------------"<<endl;

    cout << " 1st Flight equall or more expensive ? ";
    cout << (f1.hasHigherOrEqualFare(f2)?"Yes":"No");

    cout <<endl<<"------------"<<endl;

    cout << " 1st Flight less or equally expensive ? ";
    cout << (f1.hasLowerOrEqualFare(f2)?"Yes":"No");

    cout <<endl<<"------------"<<endl;

    cout << "Flight 1 less expensive ? ";
    cout << (f1.hasLowerFare(f2)?"Yes":"No");

    cout <<endl<<"------------"<<endl;
 
    cout << "Flights equal ? ";
    cout << (f1.areFlightsEqual(f2)?"Yes":"No");

    cout <<endl<<"------------"<<endl;
    
    cout << "Flights Different ? ";
    cout << (f1.areFlightsDifferent(f2)?"Yes":"No");

    cout <<endl<<"------------"<<endl;

    cout << "Make Values +ve :"<<endl;
    Flight p = f1.makeValuesPositive();
    p.displayFlight();

    cout <<endl<<"------------"<<endl;

    cout << "Make Values -ne :"<<endl;
    Flight n = f1.makeValuesNegative();
    n.displayFlight();

    cout <<endl<<"------------"<<endl;

    cout << "Input New Flight :"<<endl;
    Flight f4;
    cout << "Enter flight details :"<<endl;
    f4.inputFlightDetails();

    cout <<endl<<"------------"<<endl;

    cout << "New flight :"<<endl;
    f4.displayFlight();
    cout <<endl<<"------------"<<endl;

    return 0;
}


    




    

 
    



    

    


