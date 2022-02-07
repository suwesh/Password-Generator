#include <bits/stdc++.h>
using namespace std;
const char passelements[] = "0123456789"
                            "!@#$%^&*"
                            "abcdefghijklmnopqrstuvwxyz"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "0123456789"
                            "!@#$%^&*";
int passlength = sizeof(passelements) - 1;

int main()
{
    int n, rpass;
    string passid;
    ofstream outfile;
    outfile.open("Password.txt", std::ios_base::app);
    int conti = true;
    int index = 0;
    char choice = 'y';
    char rchoice;
    while (conti)
    {
        cout << "Enter your desired password length: ";
        cin >> n;
        cin.ignore();
        cout << "This password is for: ";
        getline(cin, passid);
        outfile << "\n";
        outfile << passid << " : ";
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            rpass = rand() % passlength + 1;
            outfile << passelements[rpass];
        }
        cout << "Your Password for " << passid << " is created." << endl;

        cout << "Do you need more passwords? \nPress n to discontinue OR Press any key to continue: ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            conti = false;
        }
    }

    return 0;
}