#include<bits/stdc++.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, coord);
}

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void welcome()
{
    gotoxy(45,13);
    setColor(rand() % 16);
    cout << "WELCOME TO PASSWORD MANAGER";
    cout.flush();
    Sleep(1800);
    system("cls");
}

void showinterface()
{
    int i, j;
    char symbols[] = {'@', '#', '$', '*', '&', '!', '?', '|'};
    int num_symbols = sizeof(symbols) / sizeof(symbols[0]);

    // Print top border
    for (i = 0; i <= 119; i++)
    {
        for (j = 1; j <= 2; j++)
        {
            gotoxy(i, j);
            setColor(rand() % 16);
            cout << symbols[rand() % num_symbols];
            cout.flush();
            Sleep(1);
        }
    }
// Print left border
    for (i = 3; i <= 23; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            gotoxy(j, i);
            setColor(rand() % 16);
            cout << symbols[rand() % num_symbols];
            cout.flush();
            Sleep(1);
        }
    }

//print middle border
    for(i = 3; i<=23; i++)
    {
        for(j = 58; j<=60; j++)
        {
            gotoxy(j, i);
            setColor(rand() % 16);
            cout << symbols[rand() % num_symbols];
            cout.flush();
            Sleep(1);

        }
    }

    // Print right border
    for (i = 3; i <=23 ; i++)
    {
        for (j = 117; j <= 119; j++)
        {
            gotoxy(j, i);
            setColor(rand() % 16);
            cout << symbols[rand() % num_symbols];
            cout.flush();
            Sleep(1);
        }
    }

// Print bottom border
    for (i = 0; i <= 119; i++)
    {
        for (j = 24; j <= 25; j++)
        {
            gotoxy(i, j);
            setColor(rand() % 16);
            cout << symbols[rand() % num_symbols];
            cout.flush();
            Sleep(1);
        }
    }

}

void create(const string& username, const string& pass)
{
    ofstream outfile("reg_accounts.txt", ios::app); // Open file in append mode
    if (outfile.is_open())
    {
        outfile << username << endl;
        outfile << pass << endl;
        outfile.close();
    }
    else
    {
        cerr << "Unable to open file for writing.\n";
    }
}

bool verify_user(const string& username, const string& password)
{
    ifstream infile("reg_accounts.txt");
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            if (line == username)
            {
                // Read the next line which should be the password
                if (getline(infile, line) && line == password)
                {
                    return true; // Username and password match
                }
                else
                {
                    return false; // Username found but password does not match
                }
            }
            // Skip the next password line
            getline(infile, line);
        }
        infile.close();
    }
    else
    {
        cerr << "Unable to open file for reading.\n";
    }
    return false; // Username not found
}

void clearRightSide()
{
    for (int i = 63; i <=116; ++i)
    {
        for (int j = 3; j <= 23; ++j)
        {
            gotoxy(i, j);
            cout << " ";
        }
    }
}

void clearLeftSide()
{
    for (int i = 3; i <= 57; ++i)
    {
        for (int j = 3; j <= 23; ++j)
        {
            gotoxy(i, j);
            cout << " ";
        }
    }
}

///randompass

void randomPasswordGenerator(int length)
{
    const string characters = "abcdef!@#$%^&*()_+ghijklmnopqrstuvwxyzA!@#$%^&*()_+BCDEFGHIJKLMNOPQRS!@#$%^&*()_+TUVWXYZ0123456789!@#$%^&*()_+";
    string password;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < length; ++i)
    {
        password += characters[rand() % characters.length()];
    }

    gotoxy(63,15);
    cout << "Your Password is : ";
    gotoxy(63,16);
    cout << password <<endl;;
}

///randompasend
///mixer
void nameYearDateMixer(const string& fname, const string& lname, const string& byear)
{
    int flength = fname.length();
    int llength = lname.length();

    gotoxy(66,15);
    cout << "CHOOSE YOUR FAVOURITE ONE: " << endl;

    // First password
    gotoxy(66,16);
    cout << "# ";
    for (int i = 0; i < 3; i++) cout << fname[i];
    for (int i = llength - 3; i < llength; i++) cout << lname[i];
    cout << byear[2] << byear[3] << " #" << endl;

    // Second password
    gotoxy(66,17);
    cout << "# ";
    for (int i = 0; i < 3; i++) cout << fname[i];
    for (int i = 0; i < 3; i++) cout << lname[i];
    cout << byear[2] << byear[3] << " #" << endl;

    // Third password
    gotoxy(66,18);
    cout << "# ";
    for (int i = 0; i < 3; i++) cout << lname[i];
    for (int i = flength - 3; i < flength; i++) cout << fname[i];
    cout << byear[2] << byear[3] << " #" << endl;

    // Fourth password
    gotoxy(66,19);
    cout << "# ";
    for (int i = 0; i < 3; i++) cout << lname[i];
    for (int i = 0; i < 3; i++) cout << fname[i];
    cout << byear[2] << byear[3] << " #" << endl;
}

///mixer

///advice
void passwordAdvice()
{

    const char* tips[] =
    {
        "1. Use at least 12 characters.",
        "2. Include both uppercase and lowercase letters.",
        "3. Include numbers and special symbols (!, @, #, etc.).",
        "4. Avoid using easily guessable information (e.g., names, birthdays).",
        "5. Do not reuse passwords across multiple sites.",
        "6. Consider using a passphrase (a sequence of words).",
        "7. Change your password regularly.",
        "8. Use a password manager to generate and store unique passwords.",
        "9. Avoid common passwords (e.g., '123456', 'password').",
        "10. Do not use keyboard patterns (e.g., 'qwerty', 'asdf')."
    };

    int x = 63;
    int y = 5;
    int max_x = 112;

    for (const char* tip : tips)
    {
        int tip_len = strlen(tip);
        int cur_x = x;

        for (int i = 0; i < tip_len; ++i)
        {
            if (cur_x > max_x)
            {
                cur_x = x;
                ++y;
                if (y > 22) break;
            }
            gotoxy(cur_x, y);
            cout << tip[i];
            ++cur_x;
        }

        ++y;
        if (y > 22) break; // Stop if we exceed the intended coordinates of y
    }
}

///Encryption system start

string caesarEncrypt(const string& plainText, int shift)
{
    string cipherText = plainText;
    for (size_t i = 0; i < plainText.size(); ++i)
    {
        cipherText[i] = static_cast<char>((static_cast<int>(plainText[i]) + shift) % 256);
    }
    return cipherText;
}

string caesarDecrypt(const string& cipherText, int shift)
{
    string plainText = cipherText;
    for (size_t i = 0; i < cipherText.size(); ++i)
    {
        plainText[i] = static_cast<char>((static_cast<int>(cipherText[i]) - shift + 256) % 256);
    }
    return plainText;
}


string encryptionSystem()
{
    clearRightSide();
    gotoxy(63, 11);
    cout << "Type a symbol or a specific word,";
    gotoxy(63, 12);
    cout << "(it will be added with your password,";
    gotoxy(63, 13);
    cout << " which you will know only) : ";
    string key;
    gotoxy(63, 14);
    cin >> key;
    return key;
}

string setkey()
{
    string k = encryptionSystem();
    return k;
}

///encryption system end;

///password related start

void saveNewPassword(const string& current_userr)
{
    clearRightSide();
    gotoxy(63, 8);
    string website, password, username, email;
    string filename = current_userr + ".txt";
    ofstream outfile(filename, ios::app);

    // Get the next serial number
    ifstream infile(filename);
    int serialNumber = 1;
    string line;
    while (getline(infile, line))
    {
        if (line.find("Serial Number:") == 0)
        {
            size_t pos = line.find(": ");
            if (pos != string::npos)
            {
                int currentSerial = stoi(line.substr(pos + 2));
                if (currentSerial >= serialNumber)
                {
                    serialNumber = currentSerial + 1;
                }
            }
        }
    }
    infile.close();

    gotoxy(63, 10);
    cout << "Website: ";
    cin >> website;
    gotoxy(63, 11);
    cout << "Username: ";
    cin >> username;
    gotoxy(63, 12);
    cout << "E-mail: ";
    cin >> email;
    gotoxy(63, 13);
    cout << "Password: ";
    cin >> password;

    int shift = 5;
    string encryptedPassword = caesarEncrypt(password, shift);

    if (outfile.is_open())
    {
        outfile << "------------------------" << endl;
        outfile << "Serial Number: " << serialNumber << endl;
        outfile << "Website: " << website << endl;
        outfile << "Username: " << username << endl;
        outfile << "Email: " << email << endl;
        outfile << "Password: " << encryptedPassword << endl;

        outfile.close();
        gotoxy(63, 16);
        cout << "Password saved successfully for user: " << current_userr << endl;
    }
    else
    {
        cerr << "Unable to open file " << filename << " for writing.\n";
    }
}

void saveAllPasswords(const string& current_userr, const vector<map<string, string>>& passwords)
{
    string filename = current_userr + ".txt";
    ofstream outfile(filename);
    if (!outfile.is_open())
    {
        cerr << "Unable to open file " << filename << " for writing.\n";
        return;
    }

    int shift = 5;
    for (const auto& entry : passwords)
    {
        outfile << "------------------------" << endl;
        for (const auto& kv : entry)
        {
            if (kv.first == "Password")
            {
                outfile << kv.first << ": " << caesarEncrypt(kv.second, shift) << endl;
            }
            else
            {
                outfile << kv.first << ": " << kv.second << endl;
            }
        }
    }

    outfile.close();
}

vector<map<string, string>> parsePasswords(const string& current_userr)
{
    vector<map<string, string>> passwords;
    string filename = current_userr + ".txt";
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cerr << "Unable to open file " << filename << " for reading.\n";
        return passwords;
    }

    int shift = 5;
    map<string, string> entry;
    string line;
    while (getline(infile, line))
    {
        if (line == "------------------------")
        {
            if (!entry.empty())
            {
                if (entry.find("Password") != entry.end())
                {
                    entry["Password"] = caesarDecrypt(entry["Password"], shift);
                }
                passwords.push_back(entry);
                entry.clear();
            }
        }
        else
        {
            size_t pos = line.find(": ");
            if (pos != string::npos)
            {
                string key = line.substr(0, pos);
                string value = line.substr(pos + 2);
                entry[key] = value;
            }
        }
    }
    if (!entry.empty())
    {
        if (entry.find("Password") != entry.end())
        {
            entry["Password"] = caesarDecrypt(entry["Password"], shift);
        }
        passwords.push_back(entry);
    }

    infile.close();
    return passwords;
}

void updatePassword(const string& current_userr)
{
    clearRightSide();
    vector<map<string, string>> passwords = parsePasswords(current_userr);
    if (passwords.empty())
    {
        gotoxy(63, 9);
        cout << "No passwords found for user: " << current_userr << endl;
        return;
    }

    // Display passwords and let the user choose one to update by serial number
    int yPos = 4;
    for (const auto& entry : passwords)
    {
        gotoxy(63, yPos++);
        cout << "Serial Number: " << entry.at("Serial Number") << ", Website: " << entry.at("Website") << endl;
    }

    int serialNumber;
    gotoxy(63, yPos+=2);
    cout << "Enter the serial number of the password to update: ";
    cin >> serialNumber;

    int shift = 5;
    for (auto& entry : passwords)
    {
        if (stoi(entry["Serial Number"]) == serialNumber)
        {
            gotoxy(63, yPos+=2);
            cout << "Enter new password for " << entry["Website"] << ": ";
            string newPassword;
            cin >> newPassword;
            entry["Password"] = caesarEncrypt(newPassword, shift);

            saveAllPasswords(current_userr, passwords);
            gotoxy(63, yPos+=2);
            cout << "Password updated successfully." << endl;
            return;
        }
    }

    gotoxy(63, yPos++);
    cout << "Serial number not found." << endl;
}

void deleteRecord(const string& current_userr)
{
    clearRightSide();
    vector<map<string, string>> passwords = parsePasswords(current_userr);
    if (passwords.empty())
    {
        gotoxy(63, 9);
        cout << "No passwords found for user: " << current_userr << endl;
        return;
    }

    // Display passwords and let the user choose one to delete by serial number
    int yPos = 4;
    for (const auto& entry : passwords)
    {
        gotoxy(63, yPos++);
        cout << "Serial Number: " << entry.at("Serial Number") << ", Website: " << entry.at("Website") << endl;
    }

    int serialNumber;
    gotoxy(63, yPos + 2);
    cout << "Enter the serial number of the password to delete: ";
    cin >> serialNumber;

    // Find and delete the entry with the matching serial number
    for (auto it = passwords.begin(); it != passwords.end(); ++it)
    {
        if (stoi((*it)["Serial Number"]) == serialNumber)
        {
            passwords.erase(it);  // Remove the entry from the vector

            saveAllPasswords(current_userr, passwords);  // Save the updated passwords list
            gotoxy(63, yPos + 3);
            cout << "Record deleted successfully." << endl;
            return;
        }
    }

    gotoxy(63, yPos + 3);
    cout << "Serial number not found." << endl;
}

void showAllPasswords(const string& current_userr)
{
    clearRightSide();
    vector<map<string, string>> passwords = parsePasswords(current_userr);

    if (passwords.empty())
    {
        gotoxy(63, 9);
        cout << "No passwords found for user: " << current_userr << endl;
        return;
    }

    int yPos = 8;
    int count = 0;

    // Display passwords two at a time
    for (size_t i = 0; i < passwords.size(); i += 2)
    {
        gotoxy(63, yPos++);
        cout << "Serial Number: " << passwords[i].at("Serial Number") << endl;
        gotoxy(63, yPos++);
        cout << "Website: " << passwords[i].at("Website") << endl;
        gotoxy(63, yPos++);
        cout << "Username: " << passwords[i].at("Username") << endl;
        gotoxy(63, yPos++);
        cout << "Email: " << passwords[i].at("Email") << endl;
        gotoxy(63, yPos++);
        cout << "Password: " << passwords[i].at("Password") << endl;
        gotoxy(63, yPos++);
        cout << "------------------------" << endl;

        if (i + 1 < passwords.size())
        {
            gotoxy(63, yPos++);
            cout << "Serial Number: " << passwords[i + 1].at("Serial Number") << endl;
            gotoxy(63, yPos++);
            cout << "Website: " << passwords[i + 1].at("Website") << endl;
            gotoxy(63, yPos++);
            cout << "Username: " << passwords[i + 1].at("Username") << endl;
            gotoxy(63, yPos++);
            cout << "Email: " << passwords[i + 1].at("Email") << endl;
            gotoxy(63, yPos++);
            cout << "Password: " << passwords[i + 1].at("Password") << endl;
            gotoxy(63, yPos++);
            cout << "------------------------" << endl;
        }

        Sleep(3000);

        // Clear the current entries
        for (int j = 0; j < 7; ++j)
        {
            gotoxy(63, yPos - 7 + j);
            cout << "                                       " << endl;
        }

        // Update yPos for the next set of passwords
        yPos = 8;
    }
}

void searchPassword(const string& current_userr)
{
    clearRightSide();
    gotoxy(63, 10);
    cout << "Enter the website to search for: ";
    string searchWebsite;
    cin >> searchWebsite;

    vector<map<string, string>> passwords = parsePasswords(current_userr);
    if (passwords.empty())
    {
        gotoxy(63, 12);
        cout << "No passwords found for user: " << current_userr << endl;
        return;
    }

    bool found = false;
    int yPos = 14;
    for (const auto& entry : passwords)
    {
        if (entry.at("Website") == searchWebsite)
        {
            found = true;
            gotoxy(63, yPos++);
            cout << "Serial Number: " << entry.at("Serial Number") << endl;
            gotoxy(63, yPos++);
            cout << "Website: " << entry.at("Website") << endl;
            gotoxy(63, yPos++);
            cout << "Username: " << entry.at("Username") << endl;
            gotoxy(63, yPos++);
            cout << "Email: " << entry.at("Email") << endl;
            gotoxy(63, yPos++);
            cout << "Password: " << entry.at("Password") << endl;
            gotoxy(63, yPos++);
            cout << "------------------------" << endl;
        }
    }

    if (!found)
    {
        gotoxy(63, 12);
        cout << "No matching website found." << endl;
    }
}

///end
void passwords_menu(string current_user)
{
pass:
    int queryyy;
    gotoxy(10,8);
    cout <<"Hello " <<current_user;
    gotoxy(10,11);
    cout << "1.Save New Password";

    gotoxy(10,12);
    cout << "2.Update Existing Password";

    gotoxy(10,13);
    cout << "3.Delete Record";

    gotoxy(10,14);
    cout << "4.Show list of All password";

    gotoxy(10,15);
    cout << "5.Search";

    gotoxy(10,16);
    cout << "6.back";
    gotoxy(10,17);
    cout << "Choose an Option: ";
    gotoxy(10,18);
    cin >> queryyy;

    switch (queryyy)
    {
    case 1:
        saveNewPassword(current_user);
        gotoxy(90,22);
        cout<<"PRESS 'a' for back";
        if (_getch() == 'a')
        {
            clearRightSide();
            goto pass;
        }

        break;
    case 2:
        updatePassword(current_user);
        gotoxy(90,22);
        cout<<"PRESS 'a' for back";
        if (_getch() == 'a')
        {
            clearRightSide();
            goto pass;
        }
        break;
    case 3:
        deleteRecord(current_user);
        gotoxy(90,22);
        cout<<"PRESS 'a' for back";
        if (_getch() == 'a')
        {
            clearRightSide();
            goto pass;
        }
        break;
    case 4:
        showAllPasswords(current_user);
        gotoxy(90,22);
        cout<<"PRESS 'a' for back";
        if (_getch() == 'a')
        {
            clearRightSide();
            goto pass;
        }
        break;
    case 5:
        searchPassword(current_user);
        gotoxy(90,22);
        cout<<"PRESS 'a' for back";
        if (_getch() == 'a')
        {
            clearRightSide();
            goto pass;
        }
        break;
    case 6:
        clearLeftSide();
        break;
    default:
        gotoxy(70,21);
        cout << "Invalid option. Please choose again." << endl;
        break;
    }

}

void callcall();

void user_features(string cur_user)
{
menu:
    clearLeftSide();
    gotoxy(10,8);
    cout << "Hello " << cur_user;
    int queryy;
    string fname,lname,byear;
    int len;
    gotoxy(10,11);
    cout << "1.Encryption System";

    gotoxy(10,12);
    cout << "2.Passwords";

    gotoxy(10,13);
    cout << "3.Random Password Generator";

    gotoxy(10,14);
    cout << "4.Name-year-Date Mixer";

    gotoxy(10,15);
    cout << "5.Advice for a better passwords";
    gotoxy(10,16);
    cout << "6.logout";
    gotoxy(10,18);
    cout << "Choose an Option:";
    gotoxy(10,19);
    cin >> queryy;

    switch (queryy)
    {
    case 1:
        setkey();
        gotoxy(63,18);
        cout << "Key saved successfully";
        gotoxy(90,22);
        cout<<"PRESS 'a' for back";
        if (_getch() == 'a')
        {
            clearRightSide();
            goto menu;
        }
        break;
    case 2:
        clearLeftSide();
        gotoxy(10,9);
        passwords_menu(cur_user);
        gotoxy(90,22);
        cout<<"PRESS 'a' for back";
        if (_getch() == 'a')
        {
            clearRightSide();
            goto menu;
        }
        break;
    case 3:
        clearRightSide();
        gotoxy(63,11);
        cout << "write the length of your desired password: ";
        gotoxy(63,12);
        cin >> len;
        randomPasswordGenerator(len);
        gotoxy(90,22);
        cout<<"PRESS 'a' for back";
        if (_getch() == 'a')
        {
            clearRightSide();
            goto menu;
        }
        break;
    case 4:
        clearRightSide();
        while (true)
        {
            gotoxy(63,11);
            cout << "Enter a name : ";
            cin >>fname;
            gotoxy(63,12);
            cout << "Enter another name : ";
            cin >> lname;
            gotoxy(63,13);
            cout << "Enter any number: ";
            cin >> byear;

            nameYearDateMixer(fname, lname, byear);
            gotoxy(63,20);
            cout << "Press 'a' to generate another set of ";
            gotoxy(63,21);
            cout << " passwords or any other key to exit.";
            if (_getch() != 'a')
            {
                clearRightSide();
                goto menu;
            }
            clearRightSide();
        }
        break;
    case 5:
        clearRightSide();
        passwordAdvice();
        gotoxy(90,22);
        cout<<"PRESS 'a' for back";
        if (_getch() == 'a')
        {
            clearRightSide();
            goto menu;
        }
        break;
    case 6:
        clearLeftSide();
        callcall();
        break;
    default:
        gotoxy(70,21);
        cout << "Invalid option. Please choose again." << endl;
        break;
    }
}

void log_reg_interface()
{
start:
    gotoxy(10,11);
    cout <<"Password Made Easy and Secure:";
    gotoxy(10,12);
    cout << "1.Login" <<endl;
    gotoxy(10,13);
    cout << "2.Register" <<endl;
    gotoxy(10,14);
    cout << "3.end";

    int  query;
    string user_name,pass;
    gotoxy(10,16);
    cout <<"Enter your choice:" <<endl;
    gotoxy(10,17);
    cin >> query;

    if(query==1)
    {
        gotoxy(63,12);
        cout << "Enter Your User name:"<<endl;
        gotoxy(63,13);
        cin >> user_name;
        gotoxy(63,14);
        cout << "Enter your Password: ";
        gotoxy(63,15);
        cin >> pass;
        if(verify_user(user_name,pass))
        {
            clearRightSide();
            user_features(user_name);

        }
        else
        {

            clearRightSide();
            gotoxy(63,12);
            cout << "user name or password didn't matched";
            gotoxy(63,14);
            cout << "Please Register or Try login again";
            Sleep(2000);
            clearRightSide();
            clearLeftSide();
            goto start;

        }


    }
    if(query==2)
    {
registration:
        gotoxy(63,12);
        cout << "Enter Your desired User name: ";
        gotoxy(63,13);
        cin >> user_name;
        gotoxy(63,14);
        cout << "Enter Password: ";
        gotoxy(63,15);
        cin >>pass;
        create(user_name,pass);
    }
    if(query == 3)
    {
        system("cls");
        gotoxy(40,12);
        system("pause");
    }
}

void callcall()
{
    log_reg_interface();
}

///password related end;


int main()
{
    welcome();
    showinterface();
    log_reg_interface();
    return 0;
}































