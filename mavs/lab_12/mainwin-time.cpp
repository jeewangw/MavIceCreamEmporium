#include<ctime>
#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "dialogs.h"
#include <sstream>


void Mainwin::display_time() {


	time_t curr_time;
	curr_time = time(NULL);

	tm *tm_local = localtime(&curr_time);

	cout << "Current local time : " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec;

string result;
string s1 = "Current Local Time : ";

// Changing integer to string
int n2 = tm_local->tm_hour;
string s2;
ostringstream convert;
convert << n2;
s2 = convert.str();

string s3 = ":";

// Changing integer to string
int n4 = tm_local->tm_min;
string s4;
ostringstream convert1;
convert1 << n4;
s4 = convert1.str();

string s5 = ":";

// Changing integer to string
int n6 = tm_local->tm_sec;
string s6;
ostringstream convert2;
convert2 << n6;
s6 = convert2.str();

result = s1 + s2 + s3 + s4 + s5 + s6;

       // s collects the status message
    Glib::ustring s = result;
// Display the collected status on the status bar
    msg->set_markup(s);


//Dialogs::message(result,"Time");

 
}
