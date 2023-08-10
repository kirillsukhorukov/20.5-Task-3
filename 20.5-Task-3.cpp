#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//функция добавления улова в корзину (запись в файл basket. txt)
void in_basket(ofstream &basket, string &fish)
{
    //Открываем файл для записи
    basket.open("basket.txt", ios::app);

    //Проверка открытия файла
    if (!basket.is_open()) cout << "File basket.txt is not open!\n" << endl;

    //Записываем в файл пойманную рыбу
    basket << fish << endl;

    basket.close();
}

//функция рыбалки (чтение из файла river.txt и сравнение с ловимой рыбой)
void fishing (string &curFish, ifstream &river, ofstream &basket, int &sum)
{
    river.open("river.txt");

    //Проверка открытия файла
    if (!river.is_open()) cout << "File river.txt is not open!\n" << endl;

    while (!river.eof())
        {
            //Чтение очередной рыбы из файла реки
            string fish;
            river >> fish;

            //Сравнение с ловимой рыбой
            if (fish == curFish) 
            {
                in_basket(basket,fish);
                sum++;
            }
        }

    river.close();
}

int main()
{
    cout <<"-----Fishing-----\n" << endl;

    int sumFish=0;
    
    //Поток чтения из файла с названиями рыб
    ifstream river;
    
    //Поток записи в корзину
    ofstream basket;
    
    //Запрос пользователя о том какую рыбу ловим
    string curFish;
    cout << "What kind of fish are we catching today? : ";
    cin >> curFish;

    fishing (curFish, river, basket, sumFish);

    //Вывод результатов рыбалки
    cout << sumFish << " fish were caught for fishing!\n" << endl;
}
