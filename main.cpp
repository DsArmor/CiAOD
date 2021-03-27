#include "main.h"

int main() {
    system("CHCP 65001>null");
//    setlocale(LC_ALL, "Russian");
    cout << "Создание списка" << endl;
    cout << "Введите количество машин: ";
    Dnode *L = nullptr;
    int n;
    cin >> n;
    create_list(L, n);
    Tnode *L1 = nullptr;
    new_Dnode_with_model(L, L1);
    int num=1;
    string value;
    Dnode *q = nullptr;
    while (num!=0){
        menu();
        cin >> num;
        switch (num){
            case 1:
                insert_new_node(L);
                break;
            case 2:
                cout << "Введите марку: ";
                cin >> value;
                del_model(L, L1, value);
                break;
            case 3:
                q = find_by_value(L);
                cout << q->model << " " << q->country << " " << q->year;
                break;
            case 4:
                output_from_first_to_last(L);
                break;
            case 5:
                output_from_last_to_first(L);
                break;
            default:
                break;
        }
    }
}

void menu(){
    cout << "1 - Вставка нового узла" << endl;
    cout << "2 - Удаление информации обо всех автомобилях заданной марки" << endl;
    cout << "3 - Поиск узла с заданным значением" << endl;
    cout << "4 - Вывод списка в прямом направлении" << endl;
    cout << "5 - Вывод списка с конца" << endl;
    cout << "0 - Выход" << endl;
    cout << "Введите желаемое действие: ";
}

void create_list(Dnode *&L, int n) {
    Dnode *q, *q1;
    q = new Dnode;
    q->next = nullptr;
    q->prev = nullptr;
    cout << "Вводите модель, страну и год производства: " << endl;//год производства должен вводиться по возрастанию для каждой марки
    for (int i = 0; i < n; i++) {
        cin >> q->model >> q->country >> q->year;
        q1 = q;
        q = new Dnode;
        q->next = q1;
        q1->prev = q;
    }
    L = q;
}

void output_from_first_to_last(Dnode *&L) {
    Dnode *q = L;
    do {
        cout << q->model << " " << q->country << " " << q->year << endl;
        q = q->next;
    } while (q != nullptr);
}

void output_from_last_to_first(Dnode *&L) {
    Dnode *q = L;
    while (q->next != nullptr) {
        q = q->next;
    }
    do {
        cout << q->model << " " << q->country << " " << q->year << endl;
        q = q->prev;
    } while (q != nullptr);
}

Dnode *find_by_value(Dnode *&L) {
    string value;
    string value2;
    int year;
    cout << "Введите марку, страну и год: " << endl;
    cin >> value >> value2 >> year;
    Dnode *q = L;
    do {
        if (q->model == value && q->country==value2 && q->year==year) {
            return q;
        }
        q = q->next;
    } while (q != nullptr);
    return nullptr;
}

void insert_new_node(Dnode *&L) {
    Dnode *q = L;
    Dnode *q1 = new Dnode();
    cout << "Введите новую модель: ";
    cin >> q1->model >> q1->country >> q1->year;
    while ((q->next->model != q1->model) || q->next == nullptr) {
        q = q->next;
    }
    while (q->next->year > q1->year || q->next == nullptr) {
        q=q->next;
    }
    q1->prev = q;
    q1->next = q->next;
    q->next->prev = q1;
    q->next = q1;
}


void new_Dnode_with_model(Dnode *&L, Tnode *&L1) {
    Tnode *q, *q1;
    q = new Tnode;
    q->next = nullptr;
    Dnode *temp = L->next;
    string value;
    while (temp != nullptr) {
        if (temp->model != value) {
            q->model = temp->model;
            q->head = temp;
            q1 = q;
            q = new Tnode;
            q->next = q1;
            value = temp->model;
        }
        temp = temp->next;
    }
    L1 = q;
}

void del_model(Dnode *&L, Tnode *&q, string value) {
    Tnode *temp = q;
    while (temp->next->model != value) {
        temp = temp->next;
    }
    Dnode *q1 = temp->head;
    while (q1->prev->model == temp->next->model) {
        q1 = q1->prev;
    }
    temp->head->prev = q1->prev;
    temp->head->prev->next = temp->head;
}

