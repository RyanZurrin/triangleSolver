#include "exceptionHandler.h"

/*
void ExceptionHandler::addErrorToList(int code, string s)
{
    error_codes[code] = s;
}
*/
ExceptionHandler::ExceptionHandler()
{
    //exceptionCode = 0;
    checkedFlag = false;
    //exceptionMessage = "No message.";
    //exceptionSource = "No source.";
   // cout << "in except default constructor" << endl;

}
/*
ExceptionHandler::ExceptionHandler(int T)
{
    exceptionCode = T;
    checkedFlag = false;
    exceptionMessage = error_codes.at(T);
    exceptionSource = "No source.";
}

void ExceptionHandler::checkErrorCode(int code) const
{
    cout << error_codes.at(code) << endl;
}
*/

double ExceptionHandler::zeroDivideFix(double num)
{
    double temp;
    if (checkedFlag == false && num == 0) {
        do {
            cout << "You cannot divide by zero, please enter a new number\n>:";
            cin >> temp;
            //num = temp;
            return temp;
            cin.ignore(100, '\n');
            cin.clear();
        } while (!cin || temp == 0);
    }
    return num;
}
/*
string ExceptionHandler::getExceptionSource(string s)
{
    exceptionSource = s;
    return exceptionSource;
}

string ExceptionHandler::getExceptionMessage(string s)
{
    exceptionMessage = s;
    return exceptionMessage;
}

int ExceptionHandler::getExceptionCode(int c)
{
    exceptionCode = c;
    return exceptionCode;
}
*/
/*
 bool ExceptionHandler::zeroDivisorCheck(double T)
{

     cout << "in first zDC b4 do" << endl;
    do {
        if (T != 0) {
            cout << "in zDC return 0" << endl;
            return 0;
        }

        else
        {
            cout << "in zDC else b4do" << endl;
            do
            {
                cout << "**ERROR** can't divide by 0, enter new number\n>";
                cin >> T;
                cin.clear();
                cin.ignore(100, '\n');
            } while (!cin || T == 0);
        }
        cout << "in zDC after else" << endl;
    } while (T != 0 && !cin == false);

    cout << "error: uncaught program exception, terminating program all data will be lost";
    return 1;
    //exit 0;

}
*/
/*
 bool ExceptionHandler::zeroDivisorCheck(double _X, double _Y, double _Z)
 {  
      ExceptionHandler checker;
      checker.zeroDivisorCheck(_X,_Y,_Z);
       //  do {
             if (_X == 0 && _Y == 0 && _Z == 0) {
                 cout << "in V3DzDC if 0" << endl;
                 do
                 {
                     cout << "**ERROR** can't divide by 0, enter new numbers x y z\n>";
                     cin >> _X >> _Y >> _Z;
                     cin.clear();
                     cin.ignore(100, '\n');
                 } while (!cin || _X == 0 && _Y == 0 && _Z == 0);
             }

             else
             {
                 cout << "in zDC return 0" << endl;
                 return 0;
             }
             cout << "in zDC after else" << endl;
        // } while (_X == 0 && _Y == 0 && _Z == 0 != 0 && !cin == false);
     
 }

 bool ExceptionHandler::negitiveNumberCheck(double num)
 {
     if (num < 0)
         return true;
     return false;
 }
  */


