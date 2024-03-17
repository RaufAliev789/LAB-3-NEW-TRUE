/*Реализовать функцию, формирующую
выходной массив нечетных чисел B на
основе входного целочисленного
массива A такой, что каждый элемент
выходного массива
- получен путем суммирования
наиближайших элементов входного
массива для получения нечетного
числа.
- равен элементу в той же позиции
входного массива, если он нечетный. Вход-8    2,1,4,7,6,11,5,6 . Выход -8     3,1,11,7,17,11,5,11
      */

#include <iostream>
#include <string>
#include <fstream>

int* FooNech(int arr[], const int SIZE) {

    int* result = new int[SIZE];

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 != 0)
            result[i] = arr[i];
        else
        {
            for (int j = 1; j < SIZE; j++) {
                if ((i + j) < SIZE) {
                    result[i] = arr[i] + arr[i + j];
                    if (result[i] % 2 != 0)
                        break;
                }
                if ((i - j) >= 0) { //[2,1,4,7,6,11,5,6] ---> [3,1,11,7,17,11,5,11]
                    result[i] = arr[i] + arr[i - j];
                    if (result[i] % 2 != 0)
                        break;
                }
            }
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    int SIZE;
    std::cout << "Введите размер массива: " << std::endl;
    std::cin >> SIZE;

    int* arr = new int[SIZE];

    std::cout << "Введите " << SIZE << " элементов(a): " << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cin >> arr[i];
    }

    int* result = FooNech(arr, SIZE);

    std::cout << "Выходной массив: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << result[i] << " ";
    }

    std::string nameVVOD = "VVOD.txt";
    std::ofstream fout;
    fout.open(nameVVOD);

    if (!fout.is_open())
        std::cout << "Ошибка открытия файла" << std::endl;
    else {
        fout << "Это размер входного массива и вводные элементы: " << SIZE << "---";
        for (int i = 0; i < SIZE; i++) {
            fout << arr[i] << " ";
        }
    }
    fout.close();

    std::string nameVIVOD = "VIVOD.txt";
    std::ofstream sout;
    sout.open(nameVIVOD);

    if (!sout.is_open())
        std::cout << "Ошибка открытия файла" << std::endl;
    else {
        sout << "Это размер выходного массива и выводные элементы: " << SIZE << "---";
        for (int i = 0; i < SIZE; i++) {
            sout << result[i] << " ";
        }
    }
    sout.close();

    delete[] arr;
    delete[] result;

    return 0;
}