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
        // merge specific word in your password

        outfile << "\n";
        outfile << passid << " : ";

        cout << "Do you want to include any specific word in auto generated password? Press y/n" << endl;
        char word_choice;
        cin >> word_choice;

        if (word_choice == 'y' || word_choice == 'Y')
        {
            cout << "Enter specific word upto " << n << " length: " << endl;
            string specific_word;
            cin >> specific_word;

            int len = specific_word.length();
            string store = "";

            if (len >= n)
            {
                specific_word = specific_word.substr(0, n);
            }

            srand(time(0));
            for (int i = 0; i < n - len; i++)
            {
                rpass = rand() % passlength + 1;
                // outfile << passelements[rpass];
                store += passelements[rpass];
            }

            // selecting random index for appending the specific word
            int random_index_for_word = rand() % (n - len + 1);
            store.insert(random_index_for_word, specific_word);
            outfile << store;

            cout << "Your Password for " << passid << " is created." << endl;

            cout << "Do you need more passwords? \nPress n to discontinue OR Press any key to continue: ";
            cin >> choice;
            if (choice == 'n' || choice == 'N')
            {
                conti = false;
            }
        }
        else
        {
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
    }

    return 0;
}
