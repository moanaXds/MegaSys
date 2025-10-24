//Write your code here..................
#include<iostream>
#include <string>
using namespace std;

class RentalReservation {
private:
    string reservationID;
    string customerName;
    string customerLoyaltyTier;
    string carMakeModel;
    string carCategory;
    string pickupDate;
    string pickupLocation;
    string returnDate;
    string returnLocation;
    int rentalDuration;
    double baseRentalRate;
    double seasonalMultiplier;
    double locationSurcharge;
    double loyaltyDiscount;
    string insuranceOption;
    int additionalDrivers;
    double rentalTotal;
    bool isInsured;

public:
    // Constructor and Destructor
    RentalReservation(const string& id, const string& name ,string Loyalty, string Model,
                     string Category, string Date, string Location, string returnDat , 
                     string returnLocat, int Duration, double RentalRate, double Multiplier, 
                     double Surcharge, double Discount, string Option, int additional , 
                     double Total, bool Insured )
        {
             reservationID= id;
             customerName= name;
             customerLoyaltyTier= Loyalty;
             carMakeModel= Model;
             carCategory= Category;
             pickupDate= Date;
             pickupLocation= Location;
             returnDate= returnDat;
             returnLocation= returnLocat;
             rentalDuration= Duration;
             baseRentalRate= RentalRate;
             seasonalMultiplier= Multiplier;
             locationSurcharge= Surcharge;
             loyaltyDiscount= Discount;
             insuranceOption= Option;
             additionalDrivers= additional;
             rentalTotal= Total;
             isInsured= Insured;

             rentalTotal= (baseRentalRate* seasonalMultiplier* rentalDuration) + locationSurcharge;

             if (loyaltyDiscount>100.00)
            {
                rentalTotal=rentalTotal-(rentalTotal*(loyaltyDiscount/100.0));
            }
            else if (loyaltyDiscount<0.0)
            {
                rentalTotal=rentalTotal+(rentalTotal*(loyaltyDiscount/100.0));
            }
        }

    ~RentalReservation()
    {
        cout<<"reservation ID "<< reservationID<<endl;
        cout<<"customer Name "<< customerName<<endl;
        cout<<"car Model "<<carMakeModel <<endl;
        cout<<"car Category "<<carCategory <<endl;
        cout<<"rental Duration "<<rentalDuration <<endl;
        cout<<"pick up Date "<< pickupDate<<endl;
        cout<<"pick up Location "<<pickupLocation <<endl;
        cout<<"return Date "<< returnDate<<endl;
        cout<<"return Location "<<returnLocation <<endl;
        cout<<"rental Total "<<rentalTotal <<endl;
    }

    // Validation Methods
    bool validateReservationID() const
    {
        int character=reservationID.length();
        if(character!=8)return false;
        
        int special=0;
        int count=0;
        char  c;
        int sum=0;

        for(int i=0;i<character;i++)
        {
            c=reservationID[i];

            if(!(c>='A' && c<='Z' || c>='a' && c<='z'|| c>='0' && c<='9'))
            {
                special++;
            }
            
            if(c>='0' && c<='9')
            {
                sum=sum+ (c-'0');
                count++;
            }
        }
        if(count!=4 || special!=2 || sum>=18)return false;

        return true;
    }    

    bool validateCarMakeModel() const
    {
        string fleet[5]={"OD","swift","Mehran","Toyota","ROME"};

        for(int i=0;i<5;i++)
        {
            if(carMakeModel==fleet[i])return true;
        }
        return false;
    }

    bool validateDateRange() const
    {
        if(rentalDuration<0 || rentalDuration>=30)return false;

        if(pickupDate[0]>returnDate[0] ||pickupDate[3]>returnDate[3])
        {
            return false;
        }
        return true;
    }

    bool validateCustomerEligibility() const
    {
        if(carCategory=="5 door" && customerLoyaltyTier=="Silver")return true;

        else if(carCategory=="5 sitter" && customerLoyaltyTier=="Gold")return true;

        else if(carCategory=="Economy")return true;

        else if(carCategory=="Basic")return false;

        else 
        {
            return false;
        }
    }

    // Calculation Methods
    double calculateRentalRate() const
    {
        double base=0.00;
        if(carCategory=="5 door")base=base+100.0;

        else if(carCategory=="5 sitter")base=base+200.0;

        else
        {
            base=base+50.0;
        }    

        if(carMakeModel=="swift")base=base+500.0;

        else if(carMakeModel=="ROME")base=base+700.0;

        else
        {
            base=base+50.0;
        }    

        double total =(base* rentalDuration *seasonalMultiplier)+ locationSurcharge;

        return total;
    }  
    
    double calculateSeasonalAdjustment() const
    {
        if(pickupDate[0]<15)
        {
            return 1.0;
        }
        else if(pickupDate[0]>15)
        {
            return 10.0;
        }
        else if(pickupDate[3]<6)
        {
            return 1.0;
        }
        else if(pickupDate[3]>6)
        {
            return 10.0;
        }
        else
        {
            return 5.0;
        }
    }

    double calculateLocationSurcharge() const
    {
        double addition=0.0;

        if(pickupLocation=="Tokyo" || returnLocation=="Tokyo")addition=200.0;
        else if(pickupLocation=="Bihar" || returnLocation=="Tokyo")addition=200.0;
        else if(pickupLocation=="Tokyo" || returnLocation=="Khana pull")addition=200.0;
        else{addition=100.0;}

        return addition;
    }

    double calculateLoyaltyDiscount() const
    {
        double discount =0.0;
        if(customerLoyaltyTier=="Silver")discount =100.0;

        else if(customerLoyaltyTier=="Gold")discount =200.0;

        else{discount =0.0;}

        return discount;
    }

    double calculateInsuranceCost() const
    {
        if(insuranceOption=="Basic")return 10.0;

        else if(insuranceOption=="Normal")return 30.0;

        else if(insuranceOption=="Premiem")return 50.0;

        else{return 5.0;}
    }


    double calculateRentalTotal() const
    {
        return rentalTotal;
    }

    // Reservation Management
    void updateReservation(const string& field, const string& value)
    {

    }
    void addInsurance(const string& option);
    void addAdditionalDriver(int count);
    void applyPromotionCode(const string& code);
    string getReservationDetails() const;

    // Advanced Features
    double calculateCancellationFee(const string& cancellationDate) const;
    string* getSimilarVehicleOptions() const;
    double calculateUpgradePrice(const string& newCarModel) const;
    bool isEligibleForFreeUpgrade() const;
};

int main()
{
    RentalReservation R1("wa@24*25","Hunain","Gold","ROME","5 sitter", "3/7/24","Tokyo","3/1/24","Tokyo",
                          3, 2300.0, 3400.0, 300.0, 1000.0, "Basic", 0.0, 0, false);

    cout<<endl<<"------------"<<endl;

    cout<<"Is validate ID : "<< R1.validateReservationID();

    cout<<endl<<"------------"<<endl;

    cout<<"validation of Model : "<< R1.validateCarMakeModel();

    cout<<endl<<"------------"<<endl;

    cout<<"validation of Date : "<< R1.validateDateRange();

    cout<<endl<<"------------"<<endl; 

    cout<<"validation of Customer Eligibility : "<< R1.validateCustomerEligibility();

    cout<<endl<<"------------"<<endl;

    cout<<"Calculate Rental Rate : "<< R1.calculateRentalRate();

    cout<<endl<<"------------"<<endl; 

    cout<<"Calculate Seasonal Adjustment : "<< R1.calculateSeasonalAdjustment();

    cout<<endl<<"------------"<<endl; 

    cout<<"Calculate Location Surcharge : "<< R1.calculateLocationSurcharge();

    cout<<endl<<"------------"<<endl;  

    cout<<"Calculate Loyalty Discount : "<< R1.calculateLoyaltyDiscount();

    cout<<endl<<"------------"<<endl;

    cout<<"Calculate Insurance Cost : "<< R1.calculateInsuranceCost();

    cout<<endl<<"------------"<<endl; 

    cout<<"Calculate Rental Total : "<< R1.calculateRentalTotal();

    cout<<endl<<"------------"<<endl;
}


    
    


    
    
    
    




