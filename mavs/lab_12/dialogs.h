#ifndef _DIALOGS_H
#define _DIALOGS_H

#include <iostream>
#include <gtkmm.h>

using namespace std;

class Dialogs {
  public:

    static string input(string msg, string title = "Input", string default_text = "", 
    string cancel_text = "CANCEL");
    static void message(string msg, string title = "Info");
    static void image(string filename, string title = "Image", string msg = "");

};
#endif
