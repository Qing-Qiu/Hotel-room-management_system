#ifndef GUEST_H
#define GUEST_H
#include "person.h"
#include <string>
#include "file.h"
using namespace std;
class Roomlist;
class Guest : public Person
{
private:
    string name;
    string id;
    int cost;

public:
    virtual ~Guest() {}
    void view(Roomlist);
    class Book
    {
    public:
        void add(Roomlist &);
        void modify(Roomlist &);
        void del(Roomlist &);
    } book;
    class Checkin
    {
    public:
        void add(Roomlist &);
    } checkin;
    class Checkout
    {
    public:
        void checkout(Roomlist &);
    } checkout;
};

void Guest::view(Roomlist roomlist)
{
    system("cls");
    Iterator<Room> it;
    cout << "�����\t��������\t����۸�\t�Ƿ�Ԥ��\t�Ƿ���ס\t" << endl;
    for (it = roomlist.begin(); it != roomlist.end(); ++it)
    {
        Room room;
        room = *it;
        cout << room.get_number() << '\t' << room.get_type() << '\t' << room.get_price() << '\t';
        cout << (room.get_isBooked() ? "Yes" : "No") << '\t' << (room.get_isChecked() ? "Yes" : "No") << endl;
    }
}

void Guest::Book::add(Roomlist &roomlist)
{
    cout << "��������Ҫѡ��Ԥ���ķ���ţ�����0�˳�����" << endl;
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
            if (room.get_number() == num && !room.get_isBooked())
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
    cout << "����ȷ�����������������֤�š��ֻ��ţ�" << endl;
    string name, id, phoneNum;
    cin >> name >> id >> phoneNum;
    roomlist[idx].set_isBooked(true);
    roomlist[idx].set_guestName(name);
    roomlist[idx].set_guestID(id);
    roomlist[idx].set_guestPhoneNum(phoneNum);
    roomlist[idx].set_bookTime(nowTime());
    File file;
    file.write(roomlist);
    cout << "Ԥ���ɹ���" << endl;
    system("pause");
}

void Guest::Book::modify(Roomlist &roomlist)
{
    cout << "��������Ԥ���ķ���ţ�����0�˳�����" << endl;
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
            if (room.get_number() == num && room.get_isBooked())
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
    cout << "\t1.����" << endl;
    cout << "\t2.���֤��" << endl;
    cout << "\t3.�ֻ���" << endl;
    cout << "\t0.����" << endl;
    string name, id, phoneNum;
    char ch;
    bool modifySuccess = false;
    while (cin >> ch)
    {
        if (ch == '1')
        {
            cout << "�������������֤�ź��ֻ��ţ�" << endl;
            while (cin >> id >> phoneNum)
            {
                if (roomlist[idx].get_guestID() == id && roomlist[idx].get_guestPhoneNum() == phoneNum)
                {
                    cout << "����������������" << endl;
                    cin >> name;
                    roomlist[idx].set_guestName(name);
                    cout << "�޸ĳɹ���" << endl;
                    modifySuccess = true;
                    break;
                }
                else
                {
                    cout << "�޸�ʧ�ܣ�" << endl;
                    break;
                }
            }
        }
        else if (ch == '2')
        {
            cout << "�����������������ֻ��ţ�" << endl;
            while (cin >> name >> phoneNum)
            {
                if (roomlist[idx].get_guestName() == name && roomlist[idx].get_guestPhoneNum() == phoneNum)
                {
                    cout << "�������������֤�ţ�" << endl;
                    cin >> id;
                    roomlist[idx].set_guestID(id);
                    cout << "�޸ĳɹ���" << endl;
                    modifySuccess = true;
                    break;
                }
                else
                {
                    cout << "�޸�ʧ�ܣ�" << endl;
                    break;
                }
            }
        }
        else if (ch == '3')
        {
            cout << "�������������������֤�ţ�" << endl;
            while (cin >> name >> id)
            {
                if (roomlist[idx].get_guestName() == name && roomlist[idx].get_guestID() == id)
                {
                    cout << "�����������ֻ��ţ�" << endl;
                    cin >> phoneNum;
                    roomlist[idx].set_guestPhoneNum(phoneNum);
                    cout << "�޸ĳɹ���" << endl;
                    modifySuccess = true;
                    break;
                }
                else
                {
                    cout << "�޸�ʧ�ܣ�" << endl;
                    break;
                }
            }
        }
        else if (ch == '0')
        {
            system("pause");
            return;
        }
        if (modifySuccess)
        {
            modifySuccess = false;
            break;
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
    File file;
    file.write(roomlist);
    system("pause");
}

void Guest::Book::del(Roomlist &roomlist)
{
    cout << "��������Ԥ���ķ���ţ�����0�˳�����" << endl;
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
            if (room.get_number() == num && room.get_isBooked())
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
    cout << "����ȷ�����������������֤�š��ֻ��ţ�" << endl;
    string name, id, phoneNum;
    while (cin >> name >> id >> phoneNum)
    {
        Room room = roomlist[idx];
        if (room.get_guestName() == name && room.get_guestID() == id && room.get_guestPhoneNum() == phoneNum)
        {
            roomlist[idx].set_room(room.get_number(), room.get_type(), room.get_price(), false, false);
            break;
        }
        else
        {
            cout << "����ȷ�����������������֤�š��ֻ��ţ�" << endl;
            continue;
        }
    }
    File file;
    file.write(roomlist);
    cout << "ɾ���ɹ���" << endl;
    system("pause");
}

void Guest::Checkin::add(Roomlist &roomlist)
{
    cout << "��������Ҫѡ����ס�ķ���ţ�����0�˳�����" << endl;
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
            if (room.get_number() == num && !room.get_isChecked() && room.get_isBooked())
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        else
        {
            cout << "���鷿����Ƿ��������󣬻�����Ԥ�����������ס��" << endl;
            continue;
        }
    }
    cout << "����ȷ�����������������֤�š��ֻ��ţ�" << endl;
    string name, id, phoneNum;
    while (cin >> name >> id >> phoneNum)
    {
        if (name == roomlist[idx].get_guestName() && id == roomlist[idx].get_guestID() && phoneNum == roomlist[idx].get_guestPhoneNum())
        {
            cout << "��ӭ��ס��" << endl;
            roomlist[idx].set_isChecked(true);
            roomlist[idx].set_guestName(name);
            roomlist[idx].set_guestID(id);
            roomlist[idx].set_checkinTime(nowTime());
            File file;
            file.write(roomlist);
            break;
        }
        else
        {
            cout << "��֤ʧ�ܣ�����������!" << endl;
            break;
        }
    }
    system("pause");
}

void Guest::Checkout::checkout(Roomlist &roomlist)
{
    cout << "����������ס�ķ���ţ�����0�˳�����" << endl;
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
            if (room.get_number() == num && room.get_isChecked())
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
    cout << "����ȷ�����������������֤�š��ֻ��ţ�" << endl;
    string name, id, phoneNum;
    cin >> name >> id >> phoneNum;
    roomlist[idx].set_checkoutTime(nowTime());
    Room room = roomlist[idx];
    if (room.get_guestName() == name && room.get_guestID() == id && room.get_guestPhoneNum() == phoneNum)
    {
        cout << "�˷��ɹ�����ӭ�´ι��٣�" << endl;
        cout << "����ţ�" << room.get_number() << endl;
        cout << "�������ͣ�" << room.get_type() << endl;
        cout << "����������" << room.get_guestName() << endl;
        cout << "�������֤�ţ�" << room.get_guestID() << endl;
        cout << "�����ֻ��ţ�" << room.get_guestPhoneNum() << endl;
        cout << "����Ԥ��ʱ�䣺" << room.get_bookTime() << endl;
        cout << "������סʱ�䣺" << room.get_checkoutTime() << endl;
        cout << "����Ԥ����" << 100 << endl;
        cout << "����ʵ����" << room.get_price() - 100 << endl;
        //�˷����������һ��log��־
        roomlist[idx].set_room(room.get_number(), room.get_type(), room.get_price(), false, false);
    }
    File file;
    file.write(roomlist);
    system("pause");
}

#endif
