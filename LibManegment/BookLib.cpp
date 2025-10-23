#include <iostream>
#include <string>
#include <fstream>

int main();

void Exit() { system("cls"); std::cout << "���������� ������!"; }

void Viewing() {
    system("cls");
    // ��� ��� ��������� ������ ����
    std::cout << "�������� ������ ����." << std::endl;
    std::ifstream BookInfo;
    std::string Path = "BookLib.txt";
    BookInfo.open(Path);
    if (BookInfo.is_open()) 
    {
        std::string Stroka;
        std::cout << "\n";
        while (!BookInfo.eof()) 
        {
            
            std::getline(BookInfo, Stroka);
            std::cout << Stroka << std::endl;
        }
    }
    else 
    {
        std::cout << "������ �������� �����";
    }
    BookInfo.close();

    std::cout << "�������� �������." << std::endl;
    std::cout << "1. ����" << std::endl;
    std::cout << "2. ���������� ������" << std::endl;
    int choise;
    std::cin >> choise;
    switch (choise)
    {   
    case 1: main(); break;
    case 2: Exit(); break;
    default:
        break;
    }
}

void Error(const std::string& message) {
    std::cerr << message << std::endl;
}

void Add() {
    std::string BookName;
    std::string AuthorName;
    int index;
    std::cout << "������� ���� �� ��������?" << std::endl;
    std::cin >> index;

    // ������� ������ �����
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   
    std::ofstream BookLib;
    std::string Path = "BookLib.txt";
    BookLib.open(Path, std::ofstream::app);
    for (int i = 0; i < index; i++) {
        
        std::cout << "������� ��� ������: " << std::endl;
        std::getline(std::cin, AuthorName);

        std::cout << "������� �������� �����" << std::endl;
        std::getline(std::cin, BookName);
        system("cls");

        BookLib << "�����: " << AuthorName << " ��������: " << BookName <<  std::endl;
    }
    BookLib.close();
    
    main();
}

int main() {
    setlocale(LC_ALL, "Ru");
    system("cls");
    int choice;

    std::cout << "�������� �������." << std::endl;
    std::cout << "1. �������� �����." << std::endl;
    std::cout << "2. ���������� ������ ����." << std::endl;
    std::cin >> choice;

    // ���������� ���������� ������ ����� ������ � ������
    std::cin.ignore();

    if (choice == 1) {
        Add();
    }
    else if (choice == 2) {
        Viewing();
    }
    else {
        Error("�������� �����.");
    }

    return 0;
}
