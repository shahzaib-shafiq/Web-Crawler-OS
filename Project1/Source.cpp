#include<iostream>
#include<thread>
#include<fstream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<semaphore.h>
#include<time.h>
#include <mutex> 
using namespace std;

void fetchhttps();
void fetch_https();
void download_links(string website);
void deletfile();
void routine(string website);
void crawl();
bool headache = true;
mutex mtx;
static int k = 0;
int main()
{
    string website;
    cout << "Enter a website to proceed with web crawler: ";
    cin >> website;
    string command = "wget -q -O index.html " + website;
    system((const char*)command.c_str());
    fetch_https();
    deletfile();
    crawl();
    thread myThreads[k];
    ifstream read("websithttps.txt");
    read.open("websitehttps.txt");
    string que;
    for (int i = 0; read >> que && i < k; i++)
    {
        myThreads[i] = thread(routine, que);
    }
    for (int i = 0; i < k; i++) {
        myThreads[i].join();
    }

    return 0;
}
void routine(string que)
{
    mtx.lock();
    download_links(que);
    fetchhttps();
    deletfile();
    mtx.unlock();
}
void fetchhttps()
{
    cout << "\n\nTHREAD 2 WORKING!\n\n";
    string file;
    bool check = true;
    if (file != "website.txt")
    {
        ofstream out("websitehttps.txt");
        out.close();
        check = false;
    }
    cout << "New Site Crawling....." << endl;
    ifstream in("index.html");
    while (in >> file)
    {

        char ch;
        string https = "";
        while (!in.eof())
        {
            in >> ch;
            if (!in.eof())
            {
                https = "";
                if (ch == '"')
                {
                    in >> ch;
                    if (ch == 'h')
                    {
                        https += ch;
                        in >> ch;
                        if (ch == 't')
                        {
                            https += ch;
                            in >> ch;
                            if (ch == 't')
                            {
                                https += ch;
                                in >> ch;
                                if (ch == 'p')
                                {
                                    https += ch;
                                    in >> ch;
                                    if (ch == 's')
                                    {
                                        https += ch;
                                        while (ch != '"' && !in.eof())
                                        {

                                            in >> ch;
                                            if (ch == '"')
                                                break;
                                            https += ch;
                                        }
                                        if (!check)
                                        {
                                            cout << https << endl;
                                        }


                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    in.close();
}
void fetch_https()
{
    cout << "\n\nTHREAD 2 WORKING!\n\n";
    string file;
    bool check = true;
    if (file != "website.txt")
    {
        ofstream out("websitehttps.txt");
        out.close();
        check = false;
    }
    cout << "New Site Crawling....." << endl;
    ifstream in("index.html");
    while (in >> file)
    {

        char ch;
        string https = "";
        while (!in.eof())
        {
            in >> ch;
            if (!in.eof())
            {
                https = "";
                if (ch == '"')
                {
                    in >> ch;
                    if (ch == 'h')
                    {
                        https += ch;
                        in >> ch;
                        if (ch == 't')
                        {
                            https += ch;
                            in >> ch;
                            if (ch == 't')
                            {
                                https += ch;
                                in >> ch;
                                if (ch == 'p')
                                {
                                    https += ch;
                                    in >> ch;
                                    if (ch == 's')
                                    {
                                        https += ch;
                                        while (ch != '"' && !in.eof())
                                        {

                                            in >> ch;
                                            if (ch == '"')
                                                break;
                                            https += ch;
                                        }
                                        if (!check)
                                        {
                                            cout << https << endl;
                                            ofstream out("websitehttps.txt", ios::app);
                                            out << https << endl;
                                        }
                                        else cout << "ERROR! LINKS WERE NOT COPIED TO THE FILE!" << endl;

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    in.close();
}

void crawl()
{
    cout << "\n\nHERE WE GO AGAIN\n\n";
    string link, que;
    ifstream read("websithttps.txt");
    read.open("websitehttps.txt");
    while (read >> que)
        k++;


}

void download_links(string website)
{
    cout << "\n\nTHREAD 1 WORKING!\n\n";
    string command = "wget -q -O index.html " + website;
    system((const char*)command.c_str());
}

void deletfile()
{
    cout << "\n\nTHREAD 3 WORKING!\n\n";
    int status;
    char fileName[20] = "index.html";

    status = remove(fileName);
    if (status == 0)
        cout << "\nFile Deleted Successfully!";
    else
        cout << "\nError Occurred!";
    cout << endl;
}