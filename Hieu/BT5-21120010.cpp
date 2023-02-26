#include <iostream>

using namespace std;

struct PHANSO {
    int tu;
    int mau;
};

ostream& operator<< (ostream& cout, const PHANSO& a) {
    if(a.mau == 1 || a.tu == 0) cout << a.tu;
    else if(a.tu % a.mau == 0) cout << a.tu / a.mau;
    else cout << a.tu << "/" << a.mau;
    return cout;
}

istream& operator>> (istream& cin, PHANSO& a) {
    do {
        cout << "Nhap tu: "; cin >> a.tu;
        cout << "Nhap mau: "; cin >> a.mau;
    }while(a.mau == 0);
    return cin;
}

struct NODE{
    PHANSO data;
    NODE *next;
};

struct LIST {
    NODE *head;
    NODE *tail;
};

NODE* create_node(PHANSO ps) {
    NODE *p = new NODE;
    p -> data = ps;
    p -> next = nullptr;
    return p;
}

LIST create_list() {
    LIST list;
    list.head = list.tail = nullptr;
    return list;
}

void add_head(LIST &list, NODE *node) {
    if(list.head == nullptr) {
        list.head = list.tail = node;
        return ;
    }

    node -> next = list.head;
    list.head = node;
}

void add_tail(LIST &list, NODE *node) {
    if(list.head == nullptr) {
        list.head = list.tail = node;
        return ;
    }

    list.tail -> next = node;
    list.tail = node;
}

void remove_head(LIST &list) {
    if(list.head == nullptr) 
        return ;
    NODE *p = list.head;
    list.head = list.head -> next;
    delete p;
}


void print_list(LIST list) {
    cout << "Danh sach lien ket:\n";
    NODE *p = list.head;
    while(p != nullptr) {
        cout << p -> data << "\n";
        p = p -> next;
    }
}

void add_node_at_index(LIST &list, NODE *node, int index) {
    if(index < 0) {
        cout << "Vi tri khong phu hop\n";
        return ;
    }
    
    if(index == 0) {
        add_head(list, node);
        return ;
    }

    NODE *p = list.head;
    index--;

    while(p != nullptr && index--) {
        p = p->next;
    }

    if(index > 1) {
        cout << "Vi tri khong phu hop\n";
        return ;
    }

    if(index == 1) {
        add_tail(list, node);
    }
    
    node -> next = p -> next;
    p -> next = node;
}

void remove_node_at_index(LIST &list, int index) {
    NODE *p = list.head;
    NODE *prev = nullptr;

    if(index < 0) {
        cout << "Vi tri khong phu hop\n";
        return ;
    }

    if(index == 0) {
        remove_head(list);
        return;
    }

    while(p != nullptr && index--) {
        prev = p;
        p = p->next;
    }

    if(index > 0) {
        cout << "Vi tri khong phu hop\n";
        return ;
    }

    if(p == nullptr)
        return ;
    
    prev -> next = p -> next;
    delete p;
}

void remove_list(LIST &list) {
    NODE *p = list.head;
    while(p != nullptr) {
        NODE *temp = p;
        p = p -> next;
        delete temp;
    }
}

void input_list(LIST &list, int &n) {
    PHANSO ps;

    cout << "Nhap so luong phan so: \n";
    cin >> n;
    cout << "Nhap cac phan so:\n";

    for(int i = 0 ; i < n  ; i++) {
        cin >> ps; 
        add_tail(list, create_node(ps));
    } 
}

int main() {
    LIST list = create_list();
    int n, pos ;
    PHANSO ps;
    input_list(list, n);

    print_list(list);

    cout << "Them phan tu vao cuoi danh sach\n";
    cout << "Nhap phan so:\n";
    cin >> ps;

    add_tail(list, create_node(ps));
    print_list(list);

    cout << "Chen mot phan so vao vi tri:\n";
    cout << "Nhap phan so:\n";
    cin >> ps;
    cout << "Nhap vi tri: ";
    cin >> pos;
    add_node_at_index(list, create_node(ps), pos);
    
    print_list(list);

    cout << "Xoa phan tu tai vi tri:\n";
    cout << "Nhap vi tri: ";
    cin >> pos;
    remove_node_at_index(list,pos);

    print_list(list);

    cout << "Huy toan bo dan sach\n";
    remove_list(list);

    return 0;   
}   