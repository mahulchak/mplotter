#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	if((argc < 2) || (string(argv[1]) == "-h"))
	{
		cerr<<"Usage: "<<argv[0]<<" out.new.fplot out.new.rplot ticks.new.txt"<<endl;
		exit(EXIT_FAILURE);
	}
	ifstream finfor,finrev,fgp;
	finfor.open(argv[1]);
	finrev.open(argv[2]);
	
	ofstream fdot,fline,fxtics,fytics;
	fdot.open("dot.txt");
	fline.open("line.txt");	
	string line1,line2;
	int lineCount =0;
	size_t pos1,pos2; //pos1 stores position of first white space and pos2 records position of 2nd whitespace
	

	while((getline(finfor,line1) && getline(finfor,line2)))
	{
		++lineCount;
		if(lineCount % 2 ==0) //if the even number line
		{
			pos1 = line1.find(' ');
			pos2 = line1.find(' ',pos1+1);
			fline<<line1.substr(0,pos1)<<'\t'<<line1.substr(pos1+1,pos2-pos1-1)<<'\t';
			fdot<<line1.substr(0,pos1)<<'\t'<<line1.substr(pos1+1,pos2-pos1-1)<<'\t'<<'F'<<endl;
			pos1 = line2.find(' ');
			pos2 = line2.find(' ',pos1+1);
			fline<<line2.substr(0,pos1)<<'\t'<<line2.substr(pos1+1,pos2-pos1-1)<<'\t'<<'F'<<endl;
			fdot<<line2.substr(0,pos1)<<'\t'<<line2.substr(pos1+1,pos2-pos1-1)<<'\t'<<'F'<<endl;
		}
	}
	lineCount = 0;//reset lineCount
	while((getline(finrev,line1) && getline(finrev,line2)))	
	{
		++lineCount;
		if(lineCount % 2 ==0) //if the even number line
		{
			pos1 = line1.find(' ');
			pos2 = line1.find(' ',pos1+1);
			fline<<line1.substr(0,pos1)<<'\t'<<line1.substr(pos1+1,pos2-pos1-1)<<'\t';
			fdot<<line1.substr(0,pos1)<<'\t'<<line1.substr(pos1+1,pos2-pos1-1)<<'\t'<<'R'<<endl;
			pos1 = line2.find(' ');
			pos2 = line2.find(' ',pos1+1);
			fline<<line2.substr(0,pos1)<<'\t'<<line2.substr(pos1+1,pos2-pos1-1)<<'\t'<<'R'<<endl;
			fdot<<line2.substr(0,pos1)<<'\t'<<line2.substr(pos1+1,pos2-pos1-1)<<'\t'<<'R'<<endl;
		}
	}	
	finfor.close();
	finrev.close();
	fdot.close();
	fline.close();
	fgp.open(argv[3]);
	fxtics.open("xticks.txt");
	fytics.open("yticks.txt");
	fxtics<<"xname\txpos"<<endl;
	fytics<<"yname\typos"<<endl;
	while(getline(fgp,line1))
	{
		pos1 = line1.find('\t');
		if(line2 == "YES")
		{
			fytics<<line1.substr(0,pos1)<<'\t'<<line1.substr(pos1+1)<<endl;
		}
		if(line1 == "set\tytics")
		{
			line2 = "YES"; //flip the switch so that ytics can be recorded
		}
		if(line2 != "YES")//if y tics hasn't been read yet
		{
			fxtics<<line1.substr(0,pos1)<<'\t'<<line1.substr(pos1+1)<<endl;
		}
	}
	fgp.close();
	fytics.close();
	fxtics.close();
	return 0;
}

