#include "../include/room.h"
#include "../include/guest.h"
#include "../include/list.h"
#include "../include/listnode.h"
#include "../include/iterator.h"
#include "../include/menu.h"
#include "../include/file.h"
#include "../include/admin.h"
#include <windows.h>
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    Menu menu;
    menu.defaultMenu();
    File file;
    Adminlist adminlist;
    adminlist = file.get_admin_data(); //��ȡ����Ա�˺�����
    Roomlist roomlist;
    roomlist = file.get_room_data(); //��ȡ�ͷ���Ϣ
    bool back2Main = false;          //����������
    bool back2Default = false;       //����Ĭ�Ͻ���
    while (1)                        //���Ƿ������������
    {
        string opt;
        cin >> opt;
        if (opt == "1") //�������
        {
            menu.mainMenu();
            Guest guest;
            string opt_;
            while (cin >> opt_)
            {
                if (opt_ == "1") //ѡ��Ԥ���ͷ�����
                {
                    menu.bookMenu();
                    string opt__;
                    while (cin >> opt__)
                    {
                        if (opt__ == "1") //����Ԥ���ͷ���Ϣ
                        {
                            guest.view(roomlist);
                            guest.book.add(roomlist);
                            back2Main = true;
                            break;
                        }
                        else if (opt__ == "2") //�޸�Ԥ���ͷ���Ϣ
                        {
                            guest.book.modify(roomlist);
                            guest.view(roomlist);
                            back2Main = true;
                            break;
                        }
                        else if (opt__ == "3") //ɾ��Ԥ��������Ϣ
                        {
                            guest.book.del(roomlist);
                            back2Main = true;
                            break;
                        }
                        else if (opt__ == "0") //������һ��
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue; //������Ч����������
                    }
                }
                else if (opt_ == "2") //ѡ����ס�Ǽǹ���
                {
                    guest.view(roomlist);
                    guest.checkin.add(roomlist);
                    back2Main = true;
                }
                else if (opt_ == "3") //ѡ���˷����㹦��
                {
                    guest.checkout.checkout(roomlist);
                    back2Main = true;
                }
                else if (opt_ == "4") //ѡ��ͷ���Ϣ�������
                {
                    guest.view(roomlist);
                    menu.viewMenu();
                    string s;
                    while (cin >> s)
                    {
                        if (s == "1") //���շ��������
                        {
                            guest.sort_by_num(roomlist);
                            system("pause");
                            back2Main = true;
                            break;
                        }
                        else if (s == "2") //������סʱ������
                        {
                            guest.sort_by_time(roomlist);
                            system("pause");
                            back2Main = true;
                            break;
                        }
                        else if (s == "0") //������һ��
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue;
                    }
                }
                else if (opt_ == "0") //���س�ʼĬ�Ͻ���
                {
                    back2Default = true;
                    break;
                }
                if (back2Main)
                {
                    menu.mainMenu();
                    back2Main = false;
                }
            }
        }
        else if (opt == "2")
        {
            menu.loginMenu();
            bool loginSuccess = false;
            string username, password;
            while (1)
            {
                cout << "�����������˺�:" << endl;
                cin >> username;
                cout << "��������������:" << endl;
                cin >> password;
                Iterator<Admin> it;
                Admin admin;
                for (int i = 1; i <= 10; i++)
                {
                    admin = adminlist[i];
                    if (username == admin.get_username() && password == admin.get_password())
                    {
                        loginSuccess = true;
                        break;
                    }
                }
                if (loginSuccess)
                {
                    menu.adminMenu();
                    string opt_;
                    while (cin >> opt_)
                    {
                        if (opt_ == "1") //�ͷ���Ϣ���
                        {
                            admin.view(roomlist); //����Ա�ܿ����������Ϣ
                            system("pause");
                            back2Default = true;
                            break;
                        }
                        else if (opt_ == "2") //�ͷ���Ϣ�޸�
                        {
                            admin.view(roomlist);
                            admin.checkin.modify(roomlist);
                            File file;
                            file.write(roomlist);
                            admin.view(roomlist);
                            system("pause");
                            back2Default = true;
                            break;
                        }
                        else if (opt_ == "3") //�ͷ���Ϣ��ʼ��
                        {
                            file.roomInit();
                            system("pause");
                            back2Default = true;
                            break;
                        }
                        else if (opt_ == "0") //������һ��
                        {
                            back2Default = true;
                            break;
                        }
                        else
                            continue;
                    }
                    break;
                }
                else
                {
                    system("cls");
                    cout << "��������Ƿ��������룿(Y/N)\n";
                    string s;
                    cin >> s;
                    if (s == "Y" || s == "y")
                        continue;
                    else if (s == "N" || s == "n")
                    {
                        cout << "�������س�ʼ���档" << endl;
                        system("pause");
                        back2Default = true;
                        break;
                    }
                    else
                    {
                        cout << "�벻Ҫ������Ч�ַ����������س�ʼ���档" << endl;
                        system("pause");
                        back2Default = true;
                        break;
                    }
                }
            }
        }
        else if (opt == "0")
        {
            system("pause");
            break;
        }
        else
            continue; //������Ч����������
        if (back2Default)
        {
            menu.defaultMenu();
            back2Default = false;
        }
    }
    return 0;
}
