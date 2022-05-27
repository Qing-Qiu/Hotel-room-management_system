#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"
#include "adminlist.h"
#include "file.h"
#include <string>
#include <iostream>
using namespace std;
class File;
class Admin : public Person
{
private:
    string username;
    string password;

public:
    virtual ~Admin() {}
    void view(Roomlist);
    void set_username(string);
    void set_password(string);
    string get_username();
    string get_password();
    class Checkin
    {
    public:
        void modify(Roomlist &);
    } checkin;
};

void Admin::view(Roomlist roomlist)
{
    system("cls");
    Iterator<Room> it;
    cout << "�����\t��������\t����۸�\t�Ƿ�Ԥ��\t�Ƿ���ס\t��������\t�������֤��\t�����ֻ�����\t����Ԥ��ʱ��\t������סʱ��" << endl;
    for (it = roomlist.begin(); it != roomlist.end(); ++it)
    {
        Room room;
        room = *it;
        cout << room.get_number() << '\t' << room.get_type() << '\t' << room.get_price() << '\t'
             << (room.get_isBooked() ? "Yes" : "No") << '\t' << (room.get_isChecked() ? "Yes" : "No") << '\t'
             << room.get_guestName() << '\t' << room.get_guestID() << '\t' << room.get_guestPhoneNum() << '\t'
             << room.get_bookTime() << '\t' << room.get_checkinTime() << endl;
    }
}

void Admin::Checkin::modify(Roomlist &roomlist)
{
    cout << "��������Ҫ�޸ĵķ���ţ�����0�˳�����" << endl;
    int num;
    int idx;
    while (cin >> num)
    {
        if (num == 0)
            return;
        idx = 0;
        bool flag = false;
        for (auto it = roomlist.begin(); it != roomlist.end(); it++)
        {
            Room room = *it;
            idx++;
            if (room.get_number() == num)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "���鷿����Ƿ���������" << endl;
            continue;
        }
    }
    cout << "��������Ҫ�޸ĵ���Ϣ��" << endl;
    cout << "\t1.����۸�" << endl;
    cout << "\t2.��������" << endl;
    cout << "\t3.�������֤��" << endl;
    cout << "\t4.�����ֻ���" << endl;
    cout << "\t5.ȡ���ñ�����ס" << endl;
    cout << "\t6.ȡ���ñ���Ԥ��" << endl;
    cout << "\t0.����" << endl;
    string name, id, phoneNum;
    char ch;
    while (cin >> ch)
    {
        if (ch == '1')
        {
            cout << "��������Ҫ�޸ĳɵķ���۸�" << endl;
            int p;
            cin >> p;
            try
            {
                if (p < 100 || p > 1000)
                    throw "�۸񳬳�������Χ��";
                roomlist[idx].set_price(p);
            }
            catch (const char *&e)
            {
                cout << e << endl;
                system("pause");
            }
            break;
        }
        else if (ch == '2')
        {
            cout << "��������Ҫ�޸ĳɵı���������" << endl;
            while (cin >> name)
            {
                roomlist[idx].set_guestName(name);
                break;
            }
            break;
        }
        else if (ch == '3')
        {
            cout << "��������Ҫ�޸ĳɵı������֤�ţ�" << endl;
            while (cin >> id)
            {
                roomlist[idx].set_guestID(id);
                break;
            }
            break;
        }
        else if (ch == '4')
        {
            cout << "��������Ҫ�޸ĳɵı����ֻ��ţ�" << endl;
            while (cin >> phoneNum)
            {
                roomlist[idx].set_guestPhoneNum(phoneNum);
                break;
            }
            break;
        }
        else if (ch == '5')
        {
            roomlist[idx].set_checkinTime("NULL");
            roomlist[idx].set_isChecked(false);
            break;
        }
        else if (ch == '6')
        {
            Room room;
            room = roomlist[idx];
            roomlist[idx].set_room(room.get_number(), room.get_type(), room.get_price(), false, false);
            break;
        }
        else if (ch == '0')
        {
            system("pause");
            return;
        }
        else
        {
            cout << "������������Ҫ�޸ĵ���Ϣ��" << endl;
            cout << "\t1.����" << endl;
            cout << "\t2.���֤��" << endl;
            cout << "\t3.�ֻ���" << endl;
            cout << "\t0.����" << endl;
            continue;
        }
    }
    //    File file;
    //    file.write(roomlist);
    //    system("pause");
}

void Admin::set_username(string user)
{
    username = user;
}

void Admin::set_password(string pwd)
{
    password = pwd;
}

string Admin::get_username()
{
    return username;
}

string Admin::get_password()
{
    return password;
}
#endif
