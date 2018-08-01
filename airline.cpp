#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
int i=0;
struct airport
{ string location;
 string nation;
};
struct info
{ string country;
int total;	
};
struct record
{
string destination;
string airline;
string fromdate;
string todate;
int price;
string dealend;
int quota;
bool mark;
int order;	
};
void clearrecord(record R[])
{ for(int k=0;k<i;k++)
	{R[k].mark=false;
	R[k].order=0;
	}
}
void writetointermediate(record R[])
{ofstream fout;
	fout.open("intermediate.txt");
	for(int k=0;k<i;k++)
		fout<<R[k].destination<<","<<R[k].airline<<","<<R[k].fromdate<<","<<R[k].todate<<","<<R[k].price<<","<<R[k].dealend<<","<<R[k].quota<<","<<"\n";
fout.close();
}
void preferairline(string prefer,record R[])
{ int count=0;
	clearrecord(R);
	for(int k=0;k<i;k++)
		if(R[k].airline==prefer)
		{count++;
				R[k].mark=true;
				R[k].order=count;
				cout<<"["<<count<<"]"<<" "<<R[k].destination<<"-"<<R[k].airline<<"-"<<R[k].fromdate<<"-"<<R[k].todate<<" "<<"HKD "<<R[k].price<<", "<<"promotion expires "<<R[k].dealend<<", "<<R[k].quota<<" quota"<<R[k].mark<<" "<<R[k].order<<endl;		
		}

}
void searchdate(string yyyymmdd,record R[])
{ int count=0;
	clearrecord(R);
	for(int k=0;k<i;k++)
		if(R[k].fromdate<=yyyymmdd && yyyymmdd<=R[k].todate)
			{count++;
				R[k].mark=true;
				R[k].order=count;
				cout<<"["<<count<<"]"<<" "<<R[k].destination<<"-"<<R[k].airline<<"-"<<R[k].fromdate<<"-"<<R[k].todate<<" "<<"HKD "<<R[k].price<<", "<<"promotion expires "<<R[k].dealend<<", "<<R[k].quota<<" quota"<<R[k].mark<<" "<<R[k].order<<endl;
			}

}
void searchdest(string dest,record R[])
{int count=0;
 clearrecord(R);
	for(int k=0;k<i;k++)
		if(R[k].destination==dest)
			{count++;
				R[k].mark=true;
				R[k].order=count;
				cout<<"["<<count<<"]"<<" "<<R[k].destination<<"-"<<R[k].airline<<"-"<<R[k].fromdate<<"-"<<R[k].todate<<" "<<"HKD "<<R[k].price<<", "<<"promotion expires "<<R[k].dealend<<", "<<R[k].quota<<" quota"<<R[k].mark<<" "<<R[k].order<<endl;
			}
	

}

void buy(record R[])
{ 	ifstream fin;
int f=0;
int k;
ifstream fin2;
info B[200];
fin2.open("secondintermediate.txt");
if(fin2.fail())
{fin.open("airportcode.txt");
ofstream fout;
fout.open("secondintermediate.txt");
 airport A[200];
 while(fin.good())
 	{getline(fin,A[f].location,',');
 	getline(fin,A[f].nation);
 	f++;
 	}
 	for(int z=0;z<f;z++)
 		cout<<A[z].location<<" "<<A[z].nation<<endl;
	B[0].country=A[0].nation;
	B[0].total=0;
	int j=0;
	 k=1;
	for(int g=1;g<f;g++)
	{ int flag=0;
	
	for(int h=0;h<k ;h++)
		{ if(B[h].country==A[g].nation)
			flag=1;
		}
		if(flag==0)
		{B[k].country=A[g].nation;
		B[k].total=0;
		k++;
		}	
	}
	for( int z=0;z<k;z++)
		fout<<B[z].country<<","<<B[z].total<<"\n";
	fin.close();
	fout.close();
}
else
{  k=0;
	string r;
	while(fin2.good())
	{getline(fin2,B[k].country,',');
	 fin2>>B[k].total;
	 getline(fin2,r);
	 k++;
	}
	for(int p=0;p<15;p++)
	cout<<B[p].country<<" "<<B[p].total<<endl;
fin2.close();
}

string r;
ofstream fout1;
fout1.open("secondintermediate.txt");
char dummy;
int number,n;
cin>>r>>dummy>>number>>n;
for(int j=0;j<i;j++)
	if(R[j].mark==true && R[j].order==number)
		if(R[j].quota>=n)
			{R[j].quota=R[j].quota-n;
				cout<<n<<" ticket(s) purchased"<<endl;
				int f=0;
				ifstream fin;
				airport A[200];
				fin.open("airportcode.txt");
				while(fin.good())
 			{getline(fin,A[f].location,',');
 			getline(fin,A[f].nation);
 			f++;
 			}
				int flag1=0;
			for(int x=0;x<f && flag1==0;x++)
				if(A[x].location==R[j].destination)
					{flag1=1;
						int flag2=0;
					for(int y=0;y<k && flag2==0;y++)
						{  flag2=0;
							if(A[x].nation==B[y].country)
							{flag2=1;
							B[y].total=B[i].total + R[j].price*.90*n;
							for(int z=0;z<k;z++)
							fout1<<B[z].country<<","<<B[z].total<<"\n";
							fout1.close();	
							}
						}
			}
		else
			cout<<"not enough tickets"<<endl;
writetointermediate(R);
for( int m=0;m<i;m++)
	cout<<R[m].destination<<"-"<<R[m].airline<<"-"<<R[m].fromdate<<"-"<<R[m].todate<<" "<<"HKD "<<R[m].price<<", "<<"promotion expires "<<R[m].dealend<<", "<<R[m].quota<<" quota"<<R[m].mark<<" "<<R[m].order<<endl;

}
for(int z=0;z<k;z++)
	cout<<B[z].country<<" "<<B[z].total<<endl;
}
void today(string end,record R[])
{	clearrecord(R);
	int k;
	int count=0;
	for(k=0;k<i;k++)
		if(R[k].dealend>end)
		{count++;
		R[k].mark=true;
		R[k].order=count;
		cout<<"["<<count<<"]"<<" "<<R[k].destination<<"-"<<R[k].airline<<"-"<<R[k].fromdate<<"-"<<R[k].todate<<" "<<"HKD "<<R[k].price<<", "<<"promotion expires "<<R[k].dealend<<", "<<R[k].quota<<" quota"<<R[k].mark<<" "<<R[k].order<<endl;
		}
}
int check(record R[],int quota,int i)
{	int flag=0;
	int j;
	for(j=0;j<i&&flag==0;j++)
		{ if(R[j].destination==R[i].destination&&R[j].airline==R[i].airline&&R[j].todate==R[i].todate&&R[j].fromdate==R[i].fromdate&&R[j].dealend==R[j].dealend&&R[i].price==R[j].price)
			{R[j].quota=R[j].quota+quota;
			flag=1;
			ofstream fout;
			fout.open("intermediate.txt");
			for(int k=0;k<=j;k++)
				{ fout<<R[k].destination<<","<<R[k].airline<<","<<R[k].fromdate<<","<<R[k].todate<<","<<R[k].price<<","<<R[k].dealend<<","<<R[k].quota<<","<<"\n";
				}
				fout.close();
			}

		}
		if(flag==0)
		{ofstream fout;
			fout.open("intermediate.txt",ios::app);
			fout<<R[i].destination<<","<<R[i].airline<<","<<R[i].fromdate<<","<<R[i].todate<<","<<R[i].price<<","<<R[i].dealend<<","<<R[i].quota<<","<<"\n";
			fout.close();
		}

}
string monthnum(string month)
{ if(month=="Jan")
	return "01";
  if(month=="Feb")
  	return "02";
  if(month=="Mar")
  	return "03";
  if(month=="Apr")
  	return "04";
  if(month=="May")
  	return "05";
  if(month=="Jun")
  	return "06";
  if(month=="Jul")
  	return "07";
  if(month=="Aug")
  	return "08";
  if(month=="Sep")
  	return "09";
  if(month=="Oct")
  	return "10";
  if(month=="Nov")
  	return"11";
  if(month=="Dec")
  	return"12";
}
void addpromo(string file,record R[])
{string x;
	file=file+".txt";
ifstream fin1;
fin1.open(file);
if(fin1.fail())
	{cout<<"Error";
	exit(1);
	}
getline(fin1,x,':');
 getline(fin1,R[i].airline);
 string line;
 string air;
 air=R[i].airline;
string deal;
while(fin1.good())
{
	getline(fin1,line);
	if(line=="#")
 	{
	R[i].destination="";
	R[i].fromdate="";
	R[i].todate="";
	}
	else
	{
	int count=0;
	int k;
	string p="";
	string q="";
	string month="";
	string day="";
	string year="";
	
 		for(k=0;k<line.length();k++)
 			if(line[k]==' ')
 				count++;
 		if(count==3)
 		{
 			year=year+line[10]+line[11]+line[12]+line[13];
 		month=month+line[15]+line[16]+line[17];
 		month=monthnum(month);
 			if(line[20]!=' ')
 				day=day+line[19]+line[20];
 			else
 				day=day+"0"+line[19];
		deal=year+month+day;
		}
	
		if(count==8)
		{R[i].destination="";
			int pos;
			pos=line.find(',');
			for(int e=0;e<pos;e++)
				R[i].destination=R[i].destination+line[e];
			year=year+line[4]+line[5]+line[6]+line[7];
	 	month=month+line[9]+line[10]+line[11];
	 	month=monthnum(month);	
	 		if(line[14]!=' ')
	 			day=day+line[13]+line[14];
	 		else
	 			day=day+"0"+line[13];
	 	R[i].fromdate=year+month+day;
	 	year="";
	 	month="";
	 	day="";
	 	if(line[14]!=' ')
	 		year=year+line[19]+line[20]+line[21]+line[22];
	 	else
	 		year=year+line[18]+line[19]+line[20]+line[21];
		if(line[14]!=' ')
			month=month+line[24]+line[25]+line[26];
		else
			month=month+line[23]+line[24]+line[25];
		if(line[14]!=' ')
			{if(line[29]==' ')
				day=day+line[28]+line[29];
			else
				day=day+"0"+line[28];
			}
		else
			{ if(line[28]!=',')
				day=day+line[27]+line[28];
				else
				day=day+"0"+line[27];
			}
		month=monthnum(month);
		R[i].todate=year+month+day;
		string word="";
		pos=line.find("HKD")+4;
		int pos1;
		pos1=line.find(',',pos);
		for(;pos<pos1;pos++)
			word=word+line[pos];
		stringstream temp1;
		temp1<<word;
		temp1>>R[i].price;
		
		pos=line.find("quota")+6;
		for(;pos<line.length();pos++)
			q=q+line[pos];
		
		stringstream temp3;
		temp3<<q;
		temp3>>R[i].quota;
		R[i].airline=air;
		string check1="";
		R[i].dealend=deal;
		R[i].mark=false;
		R[i].order=0;
		check(R,R[i].quota,i);
		i++;
		
	}//else
	}//if
}//while
for(int p=0;p<i;p++)
	cout<<R[p].destination<<","<<R[p].airline<<","<<R[p].fromdate<<","<<R[p].todate<<","<<R[p].price<<","<<R[p].dealend<<","<<R[p].quota<<","<<R[p].mark<<","<<R[p].order<<"\n";
}
int main()
{ record R[500];
char dummy;
string x;
ifstream fin;
ifstream fin1;
fin.open("mainDB_big.csv");
fin1.open("intermediate.txt");
if(fin1.fail())
	{ ofstream fout;
		fout.open("intermediate.txt");
		getline(fin,x);
		while(fin.good())
			{ getline (fin, R[i].destination, ',');
				fout<<R[i].destination<<",";
  			getline (fin, R[i].airline,',');
  			fout<<R[i].airline<<",";
  			getline(fin,R[i].fromdate,',');
  			fout<<R[i].fromdate<<",";
  			getline(fin,R[i].todate,',');
  			fout<<R[i].todate<<",";
  			fin>>R[i].price;
  			fout<<R[i].price<<",";
  			fin>>dummy;
  			getline(fin,R[i].dealend,',');
  			fout<<R[i].dealend<<",";
  			fin>>R[i].quota;
  			fout<<R[i].quota<<",";
  			getline(fin,x);
  			fout<<"\n";
  			R[i].mark=false;
  			R[i].order=0;
  			i++;
			}
		fin.close();
		fout.close();
			}
else
{		while(fin1.good())
			{ getline (fin1, R[i].destination, ',');
  			getline (fin1, R[i].airline,',');
  			getline(fin1,R[i].fromdate,',');
  			getline(fin1,R[i].todate,',');
  			fin1>>R[i].price;
  			fin1>>dummy;
  			getline(fin1,R[i].dealend,',');
  			fin1>>R[i].quota;
  			getline(fin1,x);
  			R[i].mark=false;
  			R[i].order=0;
  			i++;
			}
		fin1.close();
}

for(int j=0;j<i;j++)
	cout<<R[j].destination<<","<<R[j].airline<<","<<R[j].fromdate<<","<<R[j].todate<<","<<R[j].price<<","<<R[j].dealend<<","<<R[j].quota<<","<<R[j].mark<<","<<R[j].order<<"\n";

string text;
string file;
string random;
cin>>random>>random>>file;
cout<<file;
addpromo(file,R);
string checkdate;
cout<<"Enter date";
cin>>checkdate;
today(checkdate,R);
buy(R);
cout<<endl;
string dest;
cout<<"Enter destination";
cin>>dest;
searchdest(dest,R);
string yyyymmdd;
cout<<"Enter the date within travel period";
cin>>yyyymmdd;
searchdate(yyyymmdd,R);
string prefer;
cout<<"Enter Preferred AIrline";
cin>>prefer;
preferairline(prefer,R);
buy(R);
}
