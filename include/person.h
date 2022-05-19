#ifndef PERSON_H
#define PERSON_H
#include "room.h"
#include "roomlist.h"
#include "list.h"
#include "iterator.h"
#include "const_iterator.h"
class Room;
class Roomlist;
class Person
{
public:
    void view(Roomlist);
    void sort_by_time(Roomlist);
    void sort_by_num(Roomlist);
};

void Person::view(Roomlist roomlist)
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

void Person::sort_by_time(Roomlist roomlist)
{
    int len = roomlist.size();
    auto beg = roomlist.begin();
    auto posi = beg, posj = beg, tmp = beg;
    for (int i = 1; i < len; i++)
    {
        posj = posi;
        tmp = posi;
        for (int j = i + 1; j <= len; j++)
        {
            posj++;
            Room room1 = *posi;
            Room room2 = *posj;
            if (1)  //to be written
            {
                tmp = posj;
            }
        }
        if (tmp != posi)
        {
            roomlist.swap(tmp, posi);
            posi = tmp;
        }
        posi++;
    }
    view(roomlist);
}

void Person::sort_by_num(Roomlist roomlist)
{
    int len = roomlist.size();
    auto beg = roomlist.begin();
    auto posi = beg, posj = beg, tmp = beg;
    for (int i = 1; i < len; i++)
    {
        posj = posi;
        tmp = posi;
        for (int j = i + 1; j <= len; j++)
        {
            posj++;
            Room room1 = *posi;
            Room room2 = *posj;
            if (room1.get_number() < room2.get_number())
            {
                tmp = posj;
            }
        }
        if (tmp != posi)
        {
            roomlist.swap(tmp, posi);
            posi = tmp;
        }
        posi++;
    }
    view(roomlist);
}
#endif
