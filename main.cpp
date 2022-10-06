#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <string.h>

using namespace std;

STARTUPINFO startInfo = {0};
PROCESS_INFORMATION processInfo = {0};

// function to convert text to speech
void speak(string phrase)
{
    string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
}

// function to wish user according to time

string wishUser()
{
    // current time and date based on our system timezone
    time_t now = time(0);
    tm *time = localtime(&now);
    if (time->tm_hour < 12)
    {
        cout << "Good Morning" << endl;
        return "Good Morning";
    }
    else if (time->tm_hour > 12 && time->tm_hour < 16)
    {
        cout << "Good AfterNoon" << endl;
        return "Good AfterNoon";
    }
    else
    {
        cout << "Good evening" << endl;
        return "Good evening";
    }
}



void displayDateTime()
{
    time_t now = time(0);
    char *dt = ctime(&now);

    speak("Curent date and time is ");
    speak(dt);
    cout << "Curent date and time is " << endl
         << dt << endl;
}

void openApp(string appName){
  string command ="start "+appName;
  const char *charCommand = command.c_str();
  system(charCommand);
 
}
void closeApp(string appPath){
  string command ="taskkill /im "+appPath;
  const char *charCommand = command.c_str();
  system(charCommand);
 
}


int main()
{
    system("cls");
    cout << "====================== W E L C O M E ====================================" << endl;
    cout << "====================== I AM A VIRTUAL ASSISTANT ====================================" << endl;

    speak("Hi I am a Vitual Assitant");
    char password[100]; // to take password
    char query[100];    // to take command from user

    do
    {
        cout << "=============================================" << endl;
        cout << "| ENTER YOUR PASSWORD | " << endl;
        speak("ENTER YOUR PASSWORD");

        ;
        cout << "=============================================" << endl;

        cout << "password : ";
        gets(password);

        if (strcmp(password, "shyam") == 0)
        {
            cout << "\n===============================================================" << endl;
            ;
            string wish = wishUser();
            speak(wish);
            //   speak("how can i help You ....");
            cout << "\n===============================================================" << endl;
            do
            {
                cout << "\n=============================================================" << endl;

                cout << "how can i help You ...." << endl;
                speak("how can i help You");
                cout << "Your query :";
                gets(query);

                cout << endl;
                //   cout<<"Here are some results for your query ..."<<endl;
                if (strcmp(query, "hi") == 0 || strcmp(query, "hello") == 0)
                {
                    speak("Hello My Name is SVA .How can I help you ...");
                    cout << "Hello My Name is SVA .How can I help you ..." << endl;
                    break;
                }
                else if (strcmp(query, "bye") == 0 || strcmp(query, "stop") == 0 || strcmp(query, "exit") == 0)
                {
                    speak("Good Bye Have a Nice day");
                    cout << "Good Bye Have a Nice day!!!" << endl;
                    exit(0);
                }
                else if (strcmp(query, "who are you") == 0 || strcmp(query, "tell me about yourself") == 0 || strcmp(query, "about") == 0)
                {
                    speak("I am your friend.The Virtual Assitant");
                    cout << "I am your friend.The Virtual Assitant" << endl;
                }
                else if (strcmp(query, "how are you") == 0 || strcmp(query, "whatsup") == 0 || strcmp(query, "how is our day") == 0)
                {
                    speak("I am Good Tell me how can I help");
                    cout << "I am Good Tell me how can I help" << endl;
                }
                else if (strcmp(query, "time") == 0 || strcmp(query, "date") == 0)
                {
                    // function to display date and time
                    displayDateTime();
                }
                else if (strcmp(query, "open notepad") == 0)
                {
                    cout << "opening notepad....." << endl;
                    speak("opening notepad.....");
                    openApp("notepad");
                     }
                 else if (strcmp(query, "close notepad") == 0)
                {
                    cout << "closing notepad....." << endl;
                    speak("closing notepad.....");
                    system("taskkill /im notepad.exe");}
                else if (strcmp(query, "open google") == 0)
                {
                    cout << "opening google....." << endl;
                    speak("opening google.....");
                    system("start https://www.google.com");
                }
                else if (strcmp(query, "open youtube") == 0)
                {
                    cout << "opening youtube....." << endl;
                    speak("opening youtube.....");
                    system("start https://www.youtube.com");
                }
                else if (strcmp(query, "open github") == 0)
                {
                    cout << "opening github....." << endl;
                    speak("opening github.....");
                    system("start https://www.github.com");
                }
                else if (strcmp(query, "play music") == 0 or strcmp(query, "play a song") == 0)
                {
                    cout << "playing music....." << endl;
                    speak("playing music.....");
                    system("start https://www.youtube.com/watch?v=tjXHcyQhzqI");
                }
                else if (strcmp(query, "open game editor") == 0)
                {
                    cout << "opening Game Editor.." << endl;
                    speak("opening Game Editor.....");
                }
                else
                {
                    speak("Sorry ...");
                    speak("Could'nt understand your query");
                    speak("please enter your query again");

                    cout << "Sorry could not understand your query" << endl;
                }

            } while (1);
        }

        else
        {
            speak("incorrect password");
            speak("please enter Password again...");

            cout << "incorrect password" << endl;
        }
    } while (1);

    return 0;
}
