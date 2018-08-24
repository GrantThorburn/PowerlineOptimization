//Question 28
//Optimizing wire cost



#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void dataInput(double& riverWidth, double& distanceLand, double& cLand,
double& cWater);
void calculate(double riverWidth, double distanceLand, double cLand,
double cWater, long double& riverActual, long double& landActual, long double& totalCost);
void dataOutput(long double riverActual, long double landActual, long double totalCost);


int main(){
    double riverWidth, distanceLand, cLand, cWater;
    long double riverActual, landActual;
    long double totalCost;
    
    //Get the input data
    dataInput(riverWidth, distanceLand, cLand, cWater);
    calculate(riverWidth, distanceLand, cLand, cWater, riverActual, landActual, totalCost);
    dataOutput(riverActual, landActual, totalCost);
    
    return 0;
}


//Input variables to reference back to main 
void dataInput(double& riverWidth, double& distanceLand, double& cLand,
double& cWater){
    cout<<
    cout << "River Width (in miles): ";
    cin >> riverWidth;
    cout << "Distance of Factory (in miles): ";
    cin >> distanceLand;
    cout << "Cost over Land per ft: $"; 
    cin >> cLand;
    cout << "Cost under Water per ft: $";
    cin >> cWater;
}

void calculate(double riverWidth, double distanceLand, double cLand,
double cWater, long double& riverActual, long double& landActual, long double& totalCost){
    //create a land incremental variable to move the 
    //process from a backwards L (pythagorean theorem) toward meeting in middle, or 
    //until line is straight underwater. 
    long double costNew, underLine; //underLine is the line underwater. 
    int distIncrement = 0; //int, ft by ft increment
    
    //Increments by ft, need to convert to ft. 
    riverWidth *= 5280;
    distanceLand *= 5280;
    
    //start at 90 angle right triangle
    totalCost = ((riverWidth*cWater) + (distanceLand*cLand));
    do{
       distIncrement++; 
       underLine = sqrt(pow(riverWidth, 2.0) + pow(distIncrement, 2.0)); //first will be 0
       //in order to test costNew to totalCost of backwards L. 
       costNew = ((underLine*cWater)+((distanceLand-distIncrement)*cLand));
       
       if(costNew <= totalCost){ 
           totalCost = costNew; //sets up next rep. Failure will keep totalCost as min variable,
           //will keep testing variables to that min until the while is broken. 
           riverActual = underLine; //Only if value is min, protected variable.
           landActual = distanceLand - distIncrement; //Only if value is min, protected variable.
       }
    }
   while(distIncrement<=distanceLand); //runs until line is fully underwater. 
    //Will run once more when 8=8 miles to test. 
}

void dataOutput(long double riverActual, long double landActual, long double totalCost){
    cout << fixed << setprecision(2) << endl;
    cout << "\nTotal Optimized Cost: $" << totalCost << endl;
    cout << "Minimum feet underwater: " << riverActual << endl;
    cout << "Minimum feet overland: " << landActual << endl;
}



