#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;
int main()
{
    string filename = "test.cpp";
    string filename_exe = "prog.exe";
    fstream file;
    char user, user_2;
    char switch_on;
    uint32_t counter = 0;
    file.open(filename, ios::out | ios::app);
    cout << "\t[continue = 0 | compile = 1]" << endl<<endl;

    if (file.is_open())
    {
        string line;
        do
        {
            cout << '\t' << counter << "\t| _>";
            getline(cin, line);
            file << line << endl;
            char switch_on = _getch();
            switch (switch_on)
            {
            case '0':
            {
                counter++;
                continue;
            }break;
            case '1':
            {
                file.close();
                string command = "g++ -o " + filename_exe + " " + filename;
                system(command.c_str());
                command = "start " + filename_exe;
                system(command.c_str());
                cout << "[continue = 0 | exit = 1]" << endl;
                switch_on = _getch();
                if (switch_on == '1')
                {
                    exit(0);
                }
            }break;
            }
        } while (true);
    }
    else
    {
        cout << "Error!" << endl;

    }
    
   /* file.open(filename, ios::out | ios::ate);
    if (file.is_open())
    {
        file << "#include <iostream>" << endl;
        file << "using namespace std;" << endl << endl;
        file << "int main()" << endl;
        file << "{" << endl;
        file << "\tcout << \"Hello world!\" << endl;" << endl;
        file << "\tsystem(\"pause\");" << endl;
        file << "\treturn 0;" << endl;
        file << "}" << endl;
        file.close();
        string command = "g++ -o " + filename_exe + " "+ filename;
        system(command.c_str());
        command = "start " + filename_exe;
        system(command.c_str());
    }
    else
    {
        cout << "Error! File not opened!" << endl;
    }*/
    return 0;
}