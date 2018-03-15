#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string deal(string src){
	//find em
	int start=-1,end=-1;
	for(int i=0;i<src.size();i++){
		if(src[i]=='_'){
			if(start<0){
				start=i;
			}else{
				src=string(src.begin(),src.begin()+start)+"<em>"+string(src.begin()+start+1,src.begin()+i)+"</em>"+string(src.begin()+i+1,src.end());
				start=-1;
			}
		}
	}
	//tiaoshi
//	if(start<0){
//		cout<<"error------------------"<<endl;
//		break;
//	}
	//find link
	int midStart=-1,midEnd=-1,smallStart=-1,smallEnd=-1;
	for(int i=0;i<src.size();i++){
		if(src[i]=='['){
			midStart=i;
		}else if(src[i]==']'){
			midEnd=i;
		}else if(src[i]=='('){
			smallStart=i;
		}else if(src[i]==')'){
			smallEnd=i;
			src=string(src.begin(),src.begin()+midStart)+"<a href="+'"'+string(src.begin()+smallStart+1,src.begin()+smallEnd)+'"'+">"+string(src.begin()+midStart+1,src.begin()+midEnd)+"</a>"+string(src.begin()+smallEnd+1,src.end());
		}	
	}
	return src;
}
int main(){
	string line,pre_line="";
	int inPara=0,spaceLine=0,ulFlag=0;
	string sent=""; 
	while(getline(cin,line)){
		if(line[0]==0){
			//¥¶¿Ì   ulFLag  output </ul>
			//para  
			if(!spaceLine){
				if(ulFlag){
					cout<<"</ul>"<<endl;
					ulFlag=0;
				}
				if(inPara){
					cout<<"<p>"<<sent<<"</p>"<<endl;
					sent="";
					inPara=0;
				}
			}
			spaceLine=1;
		}else{
			if(inPara){
				sent=sent+"\n"+deal(line);
			}else{
				if(spaceLine)spaceLine=0;
				if(line[0]=='#'){
					int num=1;
					while(line[num]=='#')num++;
					if(line[num]!=' '){
						inPara=1;
						sent=deal(line);
					}else{
						int space=num;
						while(line[space]==' ')space++;
						cout<<"<h"<<num<<">"<<deal(string(line.begin()+space,line.end()))<<"</h"<<num<<">"<<endl;
					}
				}else if(line[0]=='*'){
					int num=1;
					while(line[num]==' ')num++;
					if(num==1){
						inPara=1;
						sent=deal(line);
					}else{
						if(!ulFlag)
							cout<<"<ul>"<<endl;
						ulFlag=1;
						cout<<"<li>"<<deal(string(line.begin()+num,line.end()))<<"</li>"<<endl;
					}
				}else{
					inPara=1;
					sent=deal(line);
				}
					
			}	
		}
		
		
		pre_line=line;
	}
	if(!spaceLine){
		if(ulFlag){
			cout<<"</ul>"<<endl;
			ulFlag=0;
		}
		if(inPara){
			cout<<"<p>"<<sent<<"</p>"<<endl;
			sent="";
			inPara=0;
		}
	}
	return 0;
}
