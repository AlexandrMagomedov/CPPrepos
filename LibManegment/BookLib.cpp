#include <iostream>
#include <string>
#include <fstream>

int main();

void Exit() { system("cls"); std::cout << "Завершение работы!"; }

void Viewing() {
    system("cls");
    // Код для просмотра списка книг
    std::cout << "Просмотр списка книг." << std::endl;
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
        std::cout << "Ошибка открытия файла";
    }
    BookInfo.close();

    std::cout << "Выберите функцию." << std::endl;
    std::cout << "1. Меню" << std::endl;
    std::cout << "2. Завершение работы" << std::endl;
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
    std::cout << "Сколько книг вы добавите?" << std::endl;
    std::cin >> index;

    // Очистка буфера ввода
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   
    std::ofstream BookLib;
    std::string Path = "BookLib.txt";
    BookLib.open(Path, std::ofstream::app);
    for (int i = 0; i < index; i++) {
        
        std::cout << "Введите имя автора: " << std::endl;
        std::getline(std::cin, AuthorName);

        std::cout << "Введите название книги" << std::endl;
        std::getline(std::cin, BookName);
        system("cls");

        BookLib << "Автор: " << AuthorName << " Название: " << BookName <<  std::endl;
    }
    BookLib.close();
    
    main();
}

int main() {
    setlocale(LC_ALL, "Ru");
    system("cls");
    int choice;

    std::cout << "Выберите функцию." << std::endl;
    std::cout << "1. Добавить книгу." << std::endl;
    std::cout << "2. Посмотреть список книг." << std::endl;
    std::cin >> choice;

    // Игнорируем оставшийся символ новой строки в буфере
    std::cin.ignore();

    if (choice == 1) {
        Add();
    }
    else if (choice == 2) {
        Viewing();
    }
    else {
        Error("Неверный выбор.");
    }

    return 0;
}
