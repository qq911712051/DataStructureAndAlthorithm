#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//   0  单个时间 
//	 1   所有时间 
//   2   other 
struct Task{
	int minute[65];
	int hour[30];
	int day[40];
	int month[15];
	int week[10];
	char command[100];
};
struct Time{
	int year,month,day,hour,minute;

};

Task tasks[30];
int WeekList[30],MonthList[30],DayList[30],HourList[30],MinuteList[30];
int n;
Time start,end;
void find_week(Time time,int cur_week){
	vector<int> weekVec;
	for(int i=0;i<n;i++)if(tasks[i].week[cur_week])weekVec.push_back(i);
	int week_size=weekVec.size();
	vector<int> monthVec;
	for(int i=0;i<week_size;i++)if(tasks[weekVec[i]].month[time.month])monthVec.push_back(i);
	
}
int main(){
	// read parameter
	memset(tasks,0,sizeof(tasks));
	scanf("%d",&n);
	char hehe[100];
	cin>>hehe;
	int size=strlen(hehe);
	for(int i=0;i<size;i++)hehe[i]-='0';
	start.year=hehe[0]*1000+hehe[1]*100+hehe[2]*10+hehe[3];
	start.month=hehe[4]*10+hehe[5];
	start.day=hehe[6]*10+hehe[7];
	start.hour=hehe[8]*10+hehe[9];
	start.minute=hehe[10]*10+hehe[11];
	cin>>hehe;
	size=strlen(hehe);
	for(int i=0;i<size;i++)hehe[i]-='0';
	end.year=hehe[0]*1000+hehe[1]*100+hehe[2]*10+hehe[3];
	end.month=hehe[4]*10+hehe[5];
	end.day=hehe[6]*10+hehe[7];
	end.hour=hehe[8]*10+hehe[9];
	end.minute=hehe[10]*10+hehe[11];
	for(int i=0;i<n;i++){
		cin>>hehe;plot(hehe,tasks[i].minute);
		cin>>hehe;plot(hehe,tasks[i].hour);
		cin>>hehe;plot(hehe,tasks[i].day);
		cin>>hehe;plot(hehe,tasks[i].month);
		cin>>hehe;plot(hehe,tasks[i].week);
	}
	int cur_week=cal_week(start);
	while(start<=end){
		find_week();
		//week
		for(int i=0;i<n;i++)if(tasks[i].week[cur_week])weekVec.push_back(i);
		//month
		
	}
	
	
	return 0;
}
