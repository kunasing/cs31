//project 3

#include <iostream>
#include <cassert>
#include<cmath>
using namespace std;

bool isValidPollString(string pollData);
int countSeats(string pollData, char party, int& seatCount);
bool isValidNum();
bool isValidParty();
bool isValidUppercaseStateCode(string stateCode);
void capitalizer (string& toCap);
bool isValidStateForecast(string STforecast);


int main()
    {
        assert(isValidPollString("CT5D,NY9R16D1I,VT,ne3r00D"));
        assert(!isValidPollString("ZT5D,NY9R16D1I,VT,ne3r00D"));
        int seats;
        seats = -999;    // so we can detect whether countSeats sets seats
        assert(countSeats("CT5D,NY9R16D1I,VT,ne3r00D", 'd', seats) == 0  &&  seats == 21);
        seats = -999;    // so we can detect whether countSeats changes seats
        assert(countSeats("va369d", 'd', seats) == 0  &&  seats == 369);
        cerr << "All tests succeeded" << endl;
        
    }

bool isValidPollString(string pollData){
    
    if(pollData == "")
        return true;
    capitalizer(pollData);      //capitalizes all data
    pollData += ",";        //standardizes each states info to end with comma
    string stateSubstr;     //state substr will be created under this variable then tested
    while (pollData.length() > 0){
        for(int i = 0; i < pollData.length(); i++){
            if (pollData.at(i) == ','){
                stateSubstr = pollData.substr(0,i);     //finds state forecast and saves to stateSubstr
                pollData = pollData.substr(i+1, pollData.length() - 1);     //removes next state forecast from pollData
                cerr << stateSubstr + "\n";
                if(!isValidStateForecast(stateSubstr)){     //checks state forecast
                    return false;
                }
                break;
            }
        }
}
    return true;
}

bool isValidStateForecast(string forecast){
    if(forecast.length() < 2) //not long enough
        return false;
    if(!isValidUppercaseStateCode(forecast.substr(0,2)))
        return false;
    
    forecast = forecast.substr(2, forecast.length()-1); //removes state code from forecast
    if (forecast.length() == 0) //if forecast was just state code it's good
        return true;
        
    if(!isdigit(forecast.at(0)) || !isalpha(forecast.at(forecast.length() -1))) //must start with digit and end with alphabet
        return false;
    
    for (int i = 1; i < forecast.length(); i++){
        if(!isalpha(forecast.at(i)) && !isdigit(forecast.at(i)))    //all chars are digits or alphabets
            return false;
        if (isalpha(forecast.at(i)) && isalpha(forecast.at(i -1)))  //no two alphabets in a row
            return false;
    }
    
    return true;
}

int countSeats(string pollData, char party, int& seatCount){
    
    //leave if either poll data is not valid or party is not an alphabet
    party = toupper(party);
    capitalizer(pollData);
    if(!isValidPollString(pollData))
        return 1;
    if (!isalpha(party))
        return 2;
    
    cerr << "party: " << party << "    pollData: " << pollData << endl;
    seatCount = 0;      //if its a valid count seats then sets seatCount to 0
    for (int i = 1; i < pollData.length(); i++){
        if (pollData.at(i) == party && isdigit(pollData.at(i - 1))){    //finds where character is the letter is a party but only if there is a number before (rules out state codes)
            for (int j = 1; isdigit(pollData.at(i-j)); j++){
                seatCount += (pollData.at(i-j) - '0') * pow(10, j-1);       //for each digit it is before the party code multiply by one more power of 10, and add to seat count
                cerr << "seat count: " << seatCount << endl;
            }
        }
    }
    return 0;
}

bool isValidUppercaseStateCode(string stateCode)
{
    const string codes =
        "AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
        "LA.ME.MA.MD.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
        "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2  &&
            stateCode.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCode) != string::npos);  // match found
}

void capitalizer (string& toCap){
    for(int i = 0; i < toCap.length(); i++){
        toCap[i] = toupper(toCap[i]);
    }
}
