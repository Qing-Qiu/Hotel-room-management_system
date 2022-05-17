#ifndef MENU_H
#define MENU_H
#include <iostream>
class Menu
{
public:
    void defaultMenu();
    void mainMenu();
    void bookMenu();
    void checkinMenu();
    void checkoutMenu();
    void loginMenu();
    void adminMenu();
};

void Menu::defaultMenu()
{
	system("cls");
    cout << string(40, '-') + "\n";
    cout << "\t��ӭʹ�ñ��ݿͷ�����ϵͳ\n";
    cout << "\t��������:\n";
    cout << "\t\t1.����\n";
    cout << "\t\t2.����Ա\n";
    cout << "\t0.�˳�ϵͳ\n";
    cout << string(40, '-') + "\n";
}

void Menu::mainMenu()
{
	system("cls");
    cout << string(40, '-') + "\n";
    cout << "\t���Ŀ�������,\n";
    cout << "\t��ѡ����Ҫ���еĲ���\n";
    cout << "\t\t1.Ԥ���ͷ�\n";
    cout << "\t\t2.��ס�Ǽ�\n";
    cout << "\t\t3.�˷�����\n";
    cout << "\t\t4.�ͷ���Ϣ���\n";
    cout << "\t\t0.����\n";
    cout << string(40, '-') + "\n";
}

void Menu::bookMenu()
{
	system("cls");
    cout << string(40, '-') + "\n";
    cout << "\t��ӭԤ���ﵶ����ݵķ���\n";
    cout << "\t��ѡ����Ҫ���еĲ���\n";
    cout << "\t\t1.��ҪԤ��\n";
    cout << "\t\t2.�޸���Ϣ\n";
    cout << "\t\t3.ȡ��Ԥ��\n";
    cout << "\t\t0.����\n";
    cout << string(40, '-') + "\n";
}

void Menu::checkinMenu()
{
	system("cls");
    cout << string(40, '-') + "\n";
    cout << "\t��ӭ��ס�ﵶ�����\n";
    cout << "\t��ѡ����Ҫ���еĲ���\n";
    cout << "\t\t1.��Ҫ��ס\n";
    cout << "\t\t2.�޸���Ϣ\n";
    cout << "\t\t3.ȡ����ס\n";
    cout << "\t\t0.����\n";
    cout << string(40, '-') + "\n";
}

void Menu::checkoutMenu()
{
	system("cls");
    cout << string(40, '-') + "\n";
    cout << "\t��ӭ�´ι����ﵶ�����\n";
    cout << "\t��ѡ����Ҫ���еĲ���\n";
    cout << "\t\t1.�˷�����\n";
    cout << "\t\t0.����\n";
    cout << string(40, '-') + "\n";
}

void Menu::loginMenu()
{
	system("cls");
    cout << string(40, '-') + "\n";
    cout << "\t����,ϵͳ����Ա!\n";
    cout << "\t�����������˺ź�����:\n";
    cout << string(40, '-') + "\n";
}

void Menu::adminMenu()
{
	system("cls");
    cout << "\t��ӭϵͳ����Ա!\n";
}
#endif
