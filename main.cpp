#include <iostream>
#include "ll.h"


int main(int argc, char const *argv[]) {
    using namespace std;

    // MENU
    char choice;
    char filename[255];
    char element_data[10];
    bool active_list_exists = false;
    LL::LE* list = LL::create();

    cout << "____________________\n" 
            << "Виберіть пункт меню:\n"
            << "\t0. Вихід\n"
            << "\t1. Введення списку з консолі\n"
            << "\t2. Введення списку з файлу\n"
            << "\t3. Додати у кінець елемент\n"
            << "\t4. Підрахувати кількість елементів, що починаються і закінчуються однією і тією ж літерою\n" 
            << "\t5. Підрахувати кількість елементів, що починаються з тієї ж літери, що і наступне слово\n"
            << "\t6. Підрахувати кількість елементів, що збігаються з останнім словом\n"
            << "\t7. Зберегти список у файл\n";

    while (choice != '0') {
        if (active_list_exists) {
            cout << endl << "Список: ";
            LL::ll_to_stream(list, cout, '|');
        }
        
        cout << ">> ";
        cin >> choice;
        switch (choice) {
            case '1':
                cout << ":: Вводьте нові елементи з нового рядка. Для завершення вводу - введіть пустий рядок." << endl;
                list = LL::ll_from_stream(cin, false);

                active_list_exists = true;
                break;
            case '2':
                cout << ">> Введіть назву файла: ";
                cin >> filename;
                list = LL::ll_from_file(filename);

                active_list_exists = true;
                break;
            case '3':
                cout << ":: Вводьте нові елементи з нового рядка. Для завершення вводу - введіть пустий рядок." << endl;
                // cin.getline(element_data, 10);
                while(cin.getline(element_data, 10)) {
                    if (element_data[0] == '\0')
                        break;
                    LL::push_back(list, element_data);
                }

                break;
            case '4':
                cout << ":: Кількість елементів, що починаються та закінчуються однією і тією ж літерою - " << LL::count_same_begin_n_end(list) << endl;
                break;
            case '5':
                cout << ":: Кількість елементів, що починаються з тієї ж літери, що і наступне слово - " << LL::count_same_begin(list) << endl;
                break;
            case '6':
                cout << ":: Кількість елементів, що збігаються з останнім словом - " << LL::count_equals_last(list) << endl;
                break;
            case '7':
                cout << ">> Введіть назву файлу: ";
                cin >> filename;
                ll_to_file(list, filename);
                break;
            default:
                break;
        }
    }



    return 0;
}
