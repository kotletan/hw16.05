#include <iostream>
using namespace std;
//Створити структуру Fraction з полями
//чисельник та знаменник
//Зробити масив об'єктів структури у купі
//Розмір запитати у користувача
//Записати масив у бінарний файл (серіалізувати)
//І потім прочитати та вивести у консоль
struct Fraction
{
    int num;
    int den;
};
int main() {
    int n;
    cout<<"Enter size: ";
    cin>>n;
    Fraction* arr = new Fraction[n];
    for (int i = 0; i < n; i++) {
    cout <<"Enter numbers: " << i + 1;
    cin >> arr[i].num >> arr[i].den;
    }
    const char* path = "data.bin";
    const char* mode = "wb";
    FILE* fileWrite = fopen(path,mode);
        if (fileWrite != nullptr) {
            fwrite(arr, sizeof(Fraction),n, fileWrite);
            fclose(fileWrite);
        }
        else
        {
            cout << "ERROR" << endl;
        }
        delete[] arr;
        Fraction* readArr = new Fraction[n];
        FILE* fileRead = fopen(path, "rb");
        if (fileRead != nullptr)
        {
            fread(readArr, sizeof(Fraction), n, fileRead);
            fclose(fileRead);
        }
    for (int i = 0; i < n; i++) {
        cout <<readArr[i].num<<"/"<<readArr[i].den << endl;
    }
    delete[] readArr;
    return 0;
}
