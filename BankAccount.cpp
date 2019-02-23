//Farhan Azad 11/30/2018
#include<iostream>
#include <fstream>
#include<iomanip>
using namespace std;


int main()
{
    //int counter = 0;
    int num;
    int sen;
    float w;
    float d;
    float balance;
    char choice ;
    bool closed = false;
    string  prefix;
    string nameC;
    string name, name2;
    string p;
    ifstream inputFile;
    ofstream outputFile;
    cout<<"Enter a file name prefix: ";
    cin >> prefix;
    p = prefix;
    name = prefix.append(".old.txt");
    name2 = p.append(".new.txt");
    inputFile.open(name);
    while (!inputFile)
    {
        cout<<"Error opening file.\n";
        cout<<"Enter a file name prefix: ";
        cin >> prefix;
        p = prefix;
        name = prefix.append(".old.txt");
        name2 = p.append(".new.txt");
        inputFile.open(name);
    }
    outputFile.open(name2);
    cout << fixed << showpoint << setprecision(2);
    inputFile >> num;
    while (num != 999999)
    {
        //inputFile >> num;
        closed = false;
        cout<<num<<" ";
        inputFile >> balance;
        cout<<balance<<" ";
        getline(inputFile, nameC);
        cout<<nameC<<" \n";
        cout<<"(d)eposit, (w)ithdrawal, (c)lose, (a)dvance to next customer\n";
        cin>> choice;
        while(choice != 'd'&& choice != 'w' && choice != 'c' && choice != 'a')
        {
            cout<<"wrong inputs: ";
            cin>>choice;
        }
        while (choice != 'a')
        {
            if (choice == 'd')
            {
                cout<<"Amount: ";
                cin>>d;
                sen = balance + d;
                while (sen > 9999999.99)
                {
                    cout<<"Can not hold that much money\n";
                    cout<<"Amount: ";
                    cin>>d;
                    sen = balance + d;
                }
                balance +=d;
                    //outputFile<<balance;

            }
            else if (choice == 'w')
            {
                cout<<"Amount: ";
                cin>>w;
                sen = balance - w;
                while (sen < 0)
                {
                    cout<<"Can not hold that much money\n";
                    cout<<"Amount: ";
                    cin>>w;
                    sen = balance - w;
                }
                balance -= w;
                    //outputFile<<balance;
            }
            else if (choice == 'c')
            {
                if (balance == 0)
                {
                    closed = true;
                }
                else
                {
                    cout<<"can not remove\n";
                }
            }
            if (closed == true)
            {
                choice = 'a';
            }
            else
            {
                cout<<"(d)eposit, (w)ithdrawal, (c)lose, (a)dvance to next customer\n";
                cin>> choice;

            }

            while(choice != 'd'&& choice != 'w' && choice != 'c' && choice != 'a')
            {
                cout<<"wrong inputs: ";
                cin>>choice;


            }

        }
        if (choice == 'a')
        {
                        //cout << fixed << showpoint << setprecision(2);
            if(closed == true)
                cout<<"Account closed\n";
            else
            {
                outputFile << fixed << setprecision(2)<<num <<" ";
                outputFile << fixed << setprecision(2)<< balance<<" ";
                outputFile << fixed << setprecision(2)<< nameC <<" \n";
            }
            inputFile >> num;

        }
    }

    if(num == 999999)
    {
        outputFile << num;
            //rep++;
    }
    cout<<"End of file reached.";
    inputFile.close();
    outputFile.close();

    return 0;
}
