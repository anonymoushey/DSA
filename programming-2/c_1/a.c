#include <stdio.h>
#include <string.h>
//Did not follow the lazy approach but the other approach
struct Calendar
{
    int year, month, day, minutes, seconds, hours;
    char weekDay[10] , timeZone[5];

};
void handleWeekDay(struct Calendar *present ) {
    char days[7][10]={
        "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"
    };
    int helper[]= {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int d = present->day ; 
    int m = present->month ; 
    int y = present->year ; 
    y-= m < 3;
    int weekDay  = ( y + y / 4 - y / 100 + y / 400 + helper[m - 1] + d) % 7;
    strcpy(present->weekDay , days[weekDay]);
}

int checkLeapYear(int year)
{
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

void handleDayChange(struct Calendar *present, int duration, char operation[]){
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d = present->day;
    int m = present->month;
    int y = present->year;
    if (strcmp(operation, "+") == 0)
    {
        for (int i = 0; i < duration; i++)
        {
            int daysInMonth;
            int daysInFeb;
            daysInFeb = checkLeapYear(y) ? 29 : 28;
            daysInMonth = m == 2 ? daysInFeb : monthDays[m - 1];
            if (d == daysInMonth){
                if (m == 12) {
                    d = 1;m = 1;y++;
                }
                else{
                    d = 1;m++;
                }
            }
            else{
                d++;
            }
        }
        present->day = d ; present->month = m ; present->year=y;
        
    }
    else if (!strcmp(operation,"-")){
        for(int i = duration;i>0;i--){
            int daysInFeb;
            daysInFeb = checkLeapYear(y) ? 29 : 28;
            int varToAvoidOverFlow  = m-2<0 ? 11: m-2 ;

            int resetDay = m ==3 ? daysInFeb : monthDays[varToAvoidOverFlow];
             if (d==1){
                d = resetDay;
                m = varToAvoidOverFlow == 11? m=12 : varToAvoidOverFlow+1;
                y = m==12? y-1 : y;
            }
            else{
                d--;
            }
    }
        present->day = d ; present->month = m ; present->year=y;


    }
    else{
        printf("Sir i can only add or subtract :'( ");
    }
    handleWeekDay(present);
}

void handleMonthChange(struct Calendar *present , int duration , char operation[]){
        int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int m = present->month;
        int y = present -> year;
    
        if (!strcmp(operation,"+")){
            int daysToAdd= 0 ;
            for(int i=0;i<duration;i++){
                int daysinFeb = checkLeapYear(y) ? 29 : 28 ;
                int daysinMonth = m==2 ? daysinFeb : monthDays[m-1];
                daysToAdd += daysinMonth; 
                if(m == 12) {
                    m=1;y++;
                }
                else{
                    m ++ ;
                } 
             }
             handleDayChange(present,daysToAdd,operation);

        }
        else if (!strcmp(operation,"-")){
            int daysToSubtract = 0 ;
            for(int i=0;i<duration;i++){
                int daysinFeb = checkLeapYear(y) ? 29 : 28 ;
                int daysinMonth = m==2 ? daysinFeb : monthDays[m-1];
                daysToSubtract +=daysinMonth ;
                if(m==1){
                    m=12;y--;
                }
                else{
                    m--;
                }
            }
            handleDayChange(present,daysToSubtract,operation);
}
    else{
        printf("I can only subtract or add :'( ");
    }
    handleWeekDay(present);
}

void handleYearChange(struct Calendar *present,int duration ,char operation[]){
    if (!strcmp(operation,"+")){
        int y = present->year ;
        int daysToAdd = 0;
        for (int i=0;i<duration;i++){
            daysToAdd = checkLeapYear(y) ? daysToAdd + 366 : daysToAdd+365;
            y ++;
        }
        handleDayChange(present,daysToAdd,operation);
    }
    else if (!strcmp(operation,"-")){
        int y = present->year ;
        int daysToSubtract = 0;
        for (int i=0;i<duration;i++){
            daysToSubtract = checkLeapYear(y) ? daysToSubtract + 366 : daysToSubtract +365;
            y --;
        }
        handleDayChange(present,daysToSubtract,operation);
    }
    else {
        printf("I can only subtract or add :'( ");
    }
    handleWeekDay(present);
}

void handleMinuteChange(struct Calendar *present,int duration ,char operation[]){
    int m = present->minutes;
    int h = present->hours;
    if (!strcmp(operation,"+")){
        for(int i=0 ; i<duration ; i++){
            if (m ==59){
                m = 0;
                if (h==23){
                    h= 0 ;
                    handleDayChange(present,1,operation);
                }
                else{
                    h++;
                }
            }
            else{
                m++;
            }
        }
        present->hours = h ; present->minutes = m ;
    }
    else if (!strcmp(operation,"-")){
        for(int i = 0 ; i<duration ; i++){
            if (m == 0){
                m=59;
                if (h==0){
                    h=23 ;
                    handleDayChange(present,1,operation);
                }
                else{
                    h--;
                }
            }
            else{
                m--;
            }
        }
    present->hours = h ; present->minutes = m;
    }
      else {
        printf("I can only subtract or add :'( ");
    }
    handleWeekDay(present);

 }
    
void handleHourChange(struct Calendar *present,int duration ,char operation[]){
    int h = present->hours ; 
    if (!strcmp(operation,"+")){
        for(int i = 0 ; i < duration ; i++){
            if (h == 23){
                h = 0 ;
                handleDayChange(present,1,operation);
            }
            else{
                h++;
            }
        }
        present->hours=h ;
    }
    else if(!strcmp(operation,"-")){
        for(int i=0 ; i < duration ; i++){
            if (h == 0){
                h = 23 ;
                handleDayChange(present,1,operation);
            }
            else{
                h -- ;
            }
        }
        present->hours=h;
    }
    else{
        printf("I can only subtract or add :'( ");
    }
    handleWeekDay(present);
}



void handlePrint(struct Calendar *present){
    char year[6],month[4],day[4],hours[4],minutes[4],seconds[4],weekDay[10],timeZone[4];
    strcpy(weekDay,present->weekDay);
    strcpy(timeZone,present->timeZone);
   
    sprintf(year,"%d",present->year);sprintf(month,"%d",present->month);sprintf(day,"%d",present->day);
    sprintf(hours,"%d",present->hours);sprintf(seconds,"%d",present->seconds);sprintf(minutes,"%d",present->minutes);
   
    char  output[50],p_year[10]="0",p_month[9]="0",p_day[8]="0",p_hours[7]="0",p_minutes[6]="0",p_seconds[5]="0";
   
    present->year<10 ? strcat(p_year,year) : strcpy(p_year,year);    
    present->month<10 ? strcat(p_month,month) : strcpy(p_month,month);
    present->day<10 ? strcat(p_day,day) : strcpy(p_day,day);
    present->hours<10 ? strcat(p_hours,hours) : strcpy(p_hours,hours);
    present->minutes<10 ? strcat(p_minutes,minutes) : strcpy(p_minutes,minutes);
    present->seconds<10 ? strcat(p_seconds,seconds) : strcpy(p_seconds,seconds);
    sprintf(output,"%s-%s-%s/%s/%s:%s:%s/%s",p_year,p_month,p_day,weekDay,p_hours,p_minutes,p_seconds,timeZone);
    printf("%s",output);

}

int main()
{
    char str[100];
    int year, day, month, hours, minutes, seconds, duration;
    char weekDay[10], timeZone[10], operation[2], units[3];
    scanf("%s%s%d%s", str, operation, &duration, units);
    sscanf(str, "%d-%d-%d/%[^/]/%d:%d:%d/%[^/]", &year, &month, &day, weekDay, &hours, &minutes, &seconds, timeZone);
    struct Calendar p;
    struct Calendar *present = &p;
    present->year = year; present->month = month; present->day = day; strcpy(present->weekDay , weekDay);
    strcpy(present->timeZone , timeZone); present->hours = hours; present->seconds = seconds; present->minutes = minutes;

    if (strcmp(units,"YR")==0){
        handleYearChange(present, duration, operation);
    } 
    else if (strcmp(units,"MT")==0){
        handleMonthChange(present, duration, operation);
    }  
    else if (strcmp(units,"DY")==0){
        handleDayChange(present, duration, operation);
    }
    else if (strcmp(units,"HR")==0){
        handleHourChange(present, duration, operation);
    }
    else if (strcmp(units,"MN")==0){
        handleMinuteChange(present, duration, operation);
    }    
    else {
        printf("Wrong Units.. :(");
    }
    

  //handleWeekDay(present);
   handlePrint(present);
   return 0;
}