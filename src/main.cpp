#include "../include/room.h"
#include "../include/guest.h"
#include "../include/list.h"
#include "../include/listnode.h"
#include "../include/iterator.h"
#include "../include/menu.h"
#include "../include/file.h"
#include "../include/admin.h"
#include <windows.h>
#include <time.h>
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
    while (1)
    {
        char opt;
        cin >> opt;
        if (opt == '1') //�������
        {
            menu.mainMenu();
            Guest guest;
            char opt_;
            while (cin >> opt_)
            {
                if (opt_ == '1') //ѡ��Ԥ���ͷ�����
                {
                    menu.bookMenu();
                    char opt__;
                    while (cin >> opt__)
                    {
                        if (opt__ == '1') //����Ԥ���ͷ���Ϣ
                        {
                            guest.view(roomlist);
                            guest.book.add(roomlist);
                        }
                        else if (opt__ == '2') //�޸�Ԥ���ͷ���Ϣ
                        {
                            guest.view(roomlist);
                            guest.book.modify(roomlist);
                        }
                        else if (opt__ == '3') //ɾ��Ԥ��������Ϣ
                        {
                            guest.view(roomlist);
                            guest.book.del(roomlist);
                        }
                        else if (opt__ == '0') //������һ��
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue; //������Ч����������
                    }
                }
                else if (opt_ == '2') //ѡ����ס�Ǽǹ���
                {
                    menu.checkinMenu();
                    char opt__;
                    while (cin >> opt__)
                    {
                        if (opt__ == '1') //��ס�Ǽ�
                        {
                            guest.view(roomlist);
                            guest.checkin.add(roomlist);
                        }
                        else if (opt__ == '2') //�޸���ס�Ǽ���Ϣ
                        {
                            guest.view(roomlist);
                            guest.checkin.modify(roomlist);
                        }
                        else if (opt__ == '3') //ɾ����ס�Ǽ���Ϣ
                        {
                            guest.view(roomlist);
                            guest.checkin.del(roomlist);
                        }
                        else if (opt__ == '0') //������һ��
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue; //������Ч����������
                    }
                }
                else if (opt_ == '3') //ѡ���˷����㹦��
                {
                    menu.checkoutMenu();
                    char opt__;
                    while (cin >> opt__)
                    {
                        if (opt__ == '1') //�˷�����
                        {
                            guest.view(roomlist);
                            guest.checkout.checkout(roomlist);
                        }
                        else if (opt__ == '0') //������һ��
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue; //������Ч����������
                    }
                }
                else if (opt_ == '4') //ѡ��ͷ���Ϣ�������
                {
                    guest.view(roomlist);
                    menu.viewMenu();
                    char ch;
                    while (cin >> ch)
                    {
                        if (ch == '1') //���շ��������
                        {
                            guest.sort_by_num(roomlist);
                        }
                        else if (ch == '2') //������סʱ������
                        {
                            guest.sort_by_time(roomlist);
                        }
                        else if (ch == '3') //��������
                        {
                        }
                        else if (ch == '0') //������һ��
                        {
                            back2Main = true;
                            break;
                        }
                        else
                            continue;
                    }
                }
                else if (opt_ == '0') //���س�ʼĬ�Ͻ���
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
        else if (opt == '2')
        {
            menu.loginMenu();
            bool loginSuccess = false;
            string username, password;
            while (1)
            {
                cout << "�����������˺�:";
                cin >> username;
                cout << "��������������:";
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
                    char opt_;
                    while (cin >> opt_)
                    {
                        if (opt_ == '1') //�ͷ���Ϣ���
                        {
                            admin.view(roomlist);
                        }
                        else if (opt_ == '2') //�ͷ���Ϣ�޸�
                        {
                            admin.view(roomlist);
                        }
                        else if (opt_ == '0') //������һ��
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
                    char ch;
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                        continue;
                    else if (ch == 'N' || ch == 'n')
                    {
                        back2Default = true;
                        break;
                    }
                    else
                    {
                        cout << "�벻Ҫ������Ч�ַ���";
                        cout << endl;
                        continue;
                    }
                }
            }
        }
        else if (opt == '0')
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
