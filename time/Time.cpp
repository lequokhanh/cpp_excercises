#include <bits/stdc++.h>

using namespace std;

class Time{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) { }
    void setTime(int hour, int minute, int second) {
        this->hour = hour; 
        this->minute = minute; 
        this->second=second;
    }
    void setHour(int hour) { 
        this->hour = hour;
    }
    void setMinute(int minute) { 
        this->minute = minute; 
    }
    void setSecond(int second) { 
        this->second = second; 
    }
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }
    void nextSecond() { 
        if(second<59)
            second++;
        else if(second>=59){
            second = 0;
            minute++;
            if(minute==60) {
                minute = 0;
                hour++;
                if(hour==24)
                    hour=0;
            }
        }
    }
    void previousSecond(){
        if(second>=1)
            second--;
        else if(second<1){
            second=59;
            minute--;
            if(minute==-1){
                minute=59;
                hour--;
                if(hour==-1)
                    hour=23;
            }
        }
    }
    void display(){
        if(hour<10)
            cout<<0;
        cout<<hour<<":";
        if(minute<10)
            cout<<0;
        cout<<minute<<":";
        if(second<10)
            cout<<0;
        cout<<second<<"\n";
    }
};