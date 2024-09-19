#include<iostream>
using namespace std;
int daysInMonth(int month, int year); 
bool isValidDate(int day, int month, int year){
    if(day<=0 || day> daysInMonth(month,year))
        return false;
    return true;
}

int daysInMonth(int month, int year){
    int days = 0;
    if(month == 4 || month ==6 || month ==9 || month ==11)
        days = 30;
    else if(month ==1 || month ==3 || month ==5 || month ==7
        || month ==8 || month ==10 || month ==12)
        days = 31;
    else if( month ==2 && year%4 ==0)
        days = 29;
    else
        days = 28;
    return days;
}

bool isGreater(int bDay, int bMonth, int bYear,int cDay,
 int cMonth, int cYear){
    if(cYear> bYear)
        return true;
    if(cYear<bYear)
        return false;

    if(cMonth> bMonth)
        return true;
    if(cMonth< bMonth)
        return false;
    
    if(cDay>= bDay)
        return true;
    
    return false;
}

void ageCalculator(int bDay, int bMonth, int bYear, 
                       int cDay, int cMonth, int cYear){

    int days, months, years;
    if(cDay<bDay){
        cDay +=daysInMonth(((cMonth-1)<0) ? 12: (cMonth-1),cYear);
        cMonth -=1;
    }
    days = cDay - bDay;
    if(cMonth<bMonth){
        cMonth +=12;
        cYear -=1;
    }
    months = cMonth - bMonth;
    years = cYear - bYear;

    cout<<years<< " years "<<months<<" months "<<days<<" days";

}

int main(){
    int dob,mob,yob,cd,cm,cy,day,month,year;
    do{
        cout<<"Date of birth (date month year): ";
        cin>>dob>>mob>>yob;

    }while(!isValidDate(dob,mob,yob));

    do{
        cout<<"Current date(day month year): ";
        cin>>cd>>cm>>cy;
    }while(!isValidDate(cd,cm,cy) || !isGreater(dob,mob,yob,cd,cm,cy));

    ageCalculator(dob,mob,yob,cd,cm,cy);
    return 0;
}