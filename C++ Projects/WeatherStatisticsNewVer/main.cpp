#include <iostream>
#include <iomanip>
/* Name: Karen Works
Date: 09/04/2019
Section: (Your section)
Assignment: Prob 4 page 659 Weather Statistics
Due Date:
About this project:
Assumptions:
All work below was performed by Karen Works */

using namespace std;
//stores monthly recorded weather data
struct WeatherData
{
    float TotalRainfall;
    float HighTemp;
    float LowTemp;
    float AvgTep;
};

enum months {JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER};

//get valid amount rainfall data from user
float InputValidAmtRainfallData(string);

//get valid temp data from user
float InputValidTempData(string);

//allow user to enter in Weather data
void InputValidWeatherData(WeatherData &);

//computes and returns the total rainfall for the year
float ComputeYearTotalRainfall(WeatherData [12]);

//compute and display the highest monthly temp and the month it occurs in
void ComputeAndDisplayHighestTemp(WeatherData [12]);

//compute and display the lowest monthly temp and the month it occurs in
void ComputeAndDisplayLowestTemp(WeatherData [12]);

//computes and returns the average for all average temps for the year
float ComputeYearAvgAvgTemp(WeatherData [12]);

int main() {
    //weather data for a year
    WeatherData MonthlyWeatherData[12];

    //welcome
    cout << "Weather Statistics" << endl;

    //get weather data
    for (months i = JANUARY;i<=DECEMBER;i = static_cast<months>(i+1))
    {
        cout<<"Month "<<i+1<<endl;
        InputValidWeatherData(MonthlyWeatherData[i]);
    }

    cout<<fixed<<setprecision(2);

    //total yearly rainfall
    float TotalRainfall = ComputeYearTotalRainfall(MonthlyWeatherData);
    cout<<"The total yearly rainfall is:"<<TotalRainfall<<endl;

    //average yearly rainfall
    cout<<"The average yearly rainfall is:"<<(TotalRainfall/12)<<endl;

    //compute highest monthly temp
    ComputeAndDisplayHighestTemp(MonthlyWeatherData);

    //compute lowest monthly temp
    ComputeAndDisplayLowestTemp(MonthlyWeatherData);

    //compute and display avg avg temps
    cout<<"The average of the average monthly temps is :"<<ComputeYearAvgAvgTemp(MonthlyWeatherData);

    return 0;
}

/*
 * InputValidTempData
 *
 * Description: allows the user to enter in and validates temp data
 * Programmed by: Karen Works
 */
float InputValidTempData(string type)
{
    float temp;
    //prompt user
    cout<<"Please enter in a valid "<<type<<" temperature (-100 to 140)...";
    cin>>temp;
    //input validation loop
    while ((temp<-100)||(temp>140))
    {
        //reprompt user
        cout<<"Please enter in a valid "<<type<<" temperature (-100 to 140)...";
        cin>>temp;
    }
    return temp;
}
/*
 * InputValidAmtRainfall
 *
 * Description: allows the user to enter in and validates rainfall data
 * Programmed by: Karen Works
 */
float InputValidAmtRainfallData()
{
    float rainfallAmt;
    //prompt user
    cout<<"Please enter in a valid rainfall amount (>=0)...";
    cin>>rainfallAmt;
    //input validation loop
    while (rainfallAmt<0)
    {
        //reprompt user
        cout<<"Please enter in a valid rainfall amount (>=0)...";
        cin>>rainfallAmt;
    }
    return rainfallAmt;
}


/*
 * InputValidWeatherData
 *
Description: allow user to enter in Weather data

 Programmed by : Karen Works
 */
void InputValidWeatherData(WeatherData &wd)
{
    //TotalRainfall;
    cout<<"Please enter in the total rainfall...";
    wd.TotalRainfall = InputValidAmtRainfallData();

    //HighTemp;
    wd.HighTemp = InputValidTempData("high");

    //LowTemp;
    wd.LowTemp = InputValidTempData("low");

    //AvgTep;
    wd.AvgTep = (wd.HighTemp+wd.LowTemp)/2;
}
/*
 * ComputeYearTotalRainfall
 *
 * Description: computes and returns the total rainfall for the year
 *
 * programmed by Karen Works
 */

float ComputeYearTotalRainfall(WeatherData MonthlyData[12])
{
    //computed total rainfall
    float TotalRainfall=0;
    //compute cummulative sum of total rainfall
    for (months i = JANUARY;i<=DECEMBER;i= static_cast<months>(i+1))
        TotalRainfall+=MonthlyData[i].TotalRainfall;
    return TotalRainfall;
}

/*
 * ComputeAndDisplayHighestTemp
 *
 * Description: compute and display the highest monthly temp and the month it occurs in
 *
 * programmed by Karen Works
 */
void ComputeAndDisplayHighestTemp(WeatherData MonthlyData[12])
{
    //current month with highest temp
    int MonthHighestTemp = 0;

    //loop through each month
    for (months i = FEBRUARY;i<=DECEMBER;i = static_cast<months>(i+1))
    {
        //current element or i has the highest monthly temp
        if ((MonthlyData[i].HighTemp>MonthlyData[MonthHighestTemp].HighTemp))
        {
            MonthHighestTemp = i;
        }
    }
    cout<<"The month with the highest temp is "<<MonthHighestTemp+1<<endl;
    cout<<"The highest temp was "<<MonthlyData[MonthHighestTemp].HighTemp<<endl;

}

/*
 * ComputeAndDisplayLowestTemp
 *
 * Description: compute and display the lowest monthly temp and the month it occurs in
 *
 * programmed by Karen Works
 */
void ComputeAndDisplayLowestTemp(WeatherData MonthlyData[12])
{
    //current month with Lowest temp
    int MonthLowestTemp = 0;

    //loop through each month
    for (months i = FEBRUARY;i<=DECEMBER;i= static_cast<months>(i+1))
    {
        //current element or i has the lowest monthly temp
        if ((MonthlyData[i].LowTemp<MonthlyData[MonthLowestTemp].LowTemp))
        {
            MonthLowestTemp = i;
        }
    }
    cout<<"The month with the lowest temp is "<<MonthLowestTemp+1<<endl;
    cout<<"The lowest temp was "<<MonthlyData[MonthLowestTemp].LowTemp<<endl;

}

/*
 * ComputeYearAvgAvgTemp
 *
 * Description: computes and returns the average for all average temps for the year
 *
 * programmed by Karen Works
 */
float ComputeYearAvgAvgTemp(WeatherData MonthlyData[12])
{
    //total of yearly avg temps
    float totalAvgTemps=0;
    //cumulative total of avgtemp
    for (months i = JANUARY;i<=DECEMBER;i= static_cast<months>(i+1))
    {
        totalAvgTemps+=MonthlyData[i].AvgTep;
    }
    //return the average
    return totalAvgTemps/12;
}
