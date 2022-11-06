/*
Abdul Rafay
22i-8762
SE-B
*/
#include <iostream>

using namespace std;

void startApplication();
string error(string error);
string getFileType();
string fileSaver();
string saveFile(string location, string filename);
void stopApplication();


bool IsConnected()
{
    bool wifi;
	cout<<"is WiFi Connected Yes[1] or No[0] : ";
    cin>>wifi;
    return wifi;
}

float availableBandwidth()
{
    float band;
	cout<<"Enter Bandwidth : ";
    cin>>band;
    return band;
}

void networkStartValidator()
{
    if (IsConnected() == 1 && availableBandwidth() > 20)
    {
        startApplication();
    }
    else if (IsConnected() != 1 && availableBandwidth() < 20)
    {
    	stopApplication();
        error("error");
    }
    
}


void stopApplication()
{
    cout<<"it stopped!!";
    abort();
}

string error(string error)
{
    cout<<error;
    return "error";
}


char type;
string filename;

string getFileType()
{
    
    if (type == 'T')
    {
        return ".txt";
    }
    else if (type == 'M')
    {
        return ".mp4";
    }
    else if (type == 'P')
    {
        return ".mp3";
    }
    else if (type == 'I')
    {
        error("error");
        return "invalid";
    }
}


string saveFile(string location, string filename)
{
    if (type == 'T')
    {
        location = "Text File";
    }
    else if(type == 'P')
    {
        location = "Sound Files";
    }
    else if(type == 'M')
    {
        location = "Video Files";
    }
    else if(type == 'I') 
    {
        error("error");
    }
    else
    {
        error("error");
    }

    return location;
}

string fileSaver()
{
    cout<<"Enter File name : ";
    cin>>filename;
    return filename;

}

string sendMessage()
{
	string msg;
	cout<<"Enter Message : ";
	cin>>msg;
	return msg;
}

void startApplication()
{
    cout<<"its running!!\n";
    fileSaver();
    cout<<"Enter File Type\nT=txt\nM=mp4\nP=mp3\nI=invalid\n";
    cin>>type;
    
    string msg = sendMessage();
    cout<<filename<<getFileType()<< " is saved in " << saveFile(" "," ");
	cout<<"\nMessage : \"" <<msg <<"\"  is sent to client!";
}


int main()
{
	networkStartValidator();
    
	return 0;
}