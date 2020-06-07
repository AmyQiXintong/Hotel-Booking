// this program aims to stimulate a hotel booking system
// this program can handle up to 99 rooms on a single floor
 
#include <iostream>
 
using namespace std;
 
#define maxLen 10;
 
// functions to be used universally
// this function gets the numbers of a string
int getNum(char arr[]) {
    int sum = 0;
    int digit = 0;
    int i = 0;
    while (arr[i] != '\0')
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            digit = arr[i] - '0';
            sum = sum * 10 + digit;
        }
        i++;
    }
 
    return sum;
}
 
// implement a class that contains info about a room
class Hotel
{
public:
    Hotel();
    int findLen(char* s);
    void set(char* s1, char* s2, int i1, int i2, int num);
    void setStatus(int sta);
 
 
    void swap(Hotel* o1, Hotel* o2);
    int compare(Hotel o1, Hotel o2);
    int extract(Hotel obj);
    void sort(Hotel* ptr);
 
    char* returnRoom();
    char* returnFloor();
    int returnPrice();
    int returnStatus();
    void print(char* s1, char* s2, int i1, int i2);
 
private:
    char room[10];
    char floor[10];
    int price;
    int status;
    int number;
};
 
// constructor and setting up the values
Hotel::Hotel()
{
    room[6] = '0';
    floor[6] = '0';
    price = 0;
    status = 0;
}
 
int Hotel::findLen(char* s) {
    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }
    return length;
}
 
void Hotel::set(char* s1, char* s2, int i1, int i2, int num) {
    int len1 = findLen(s1);
    int len2 = findLen(s2);
    for (int i = 0; i < len1; i++)
    {
        room[i] = s1[i];
    }
    room[len1] = '\0';
    for (int i = 0; i < len2; i++)
    {
        floor[i] = s2[i];
    }
    floor[len2] = '\0';
    price = i1;
    status = i2;
    number = num;
}
 
void Hotel::setStatus(int sta) {
    status = sta;
}
 
// sort the array using bubble sort
void Hotel::swap(Hotel* o1, Hotel* o2) {
    Hotel tmp = *o1;
    *o1 = *o2;
    *o2 = tmp;
}
 
int Hotel::extract(Hotel obj) {
    int sum = getNum(obj.room);
 
    return sum;
}
 
int Hotel::compare(Hotel o1, Hotel o2) {
    //return 1 means that s1 is larger
    //return -1 means that s2 is larger or they are equal
    if (o1.price > o2.price)
    {
        return 1;
    }
    else if (o1.price == o2.price)
    {
        int extra1 = extract(o1);
        int extra2 = extract(o2);
        if (extra1 > extra2)
        {
            return 1;
        }
        else {
            return -1;
        }
    }
    else {
        return -1;
    }
}
 
void Hotel::sort(Hotel* ptr) {
    for (int i = 0; i < number - 1; i++)
    {
        for (int j = 0; j < number - i - 1; j++)
        {
            if (compare(ptr[j], ptr[j + 1]) > 0)
            {
                swap(&ptr[j], &ptr[j + 1]);
            }
        }
    }
}
 
// value returning and printing
char* Hotel::returnRoom() {
    return room;
}
 
char* Hotel::returnFloor() {
    return floor;
}
 
int Hotel::returnPrice() {
    return price;
}
 
int Hotel::returnStatus() {
    return status;
}
 
void Hotel::print(char* s1, char* s2, int i1, int i2) {
    cout << s1 << " " << s2 << " " << i1 << " " << i2 << endl;
}
 
 
int main()
{
    // get the amount of the room
    int num;
    cout << "Input the number of rooms:" << endl;
    cin >> num;
 
    // build the objects using dynamic memory allocation
    Hotel* ptr = NULL;
    ptr = new Hotel[num];
 
    // check whether allocation is successful
    char ro[10];
    char fl[10];
    int pr;
    int st; // used to get user input for details
    if (ptr == NULL)
    {
        cout << "Allocation of memory failed!" << endl;
    }
    else
    {
        cout << "Input the information of rooms (room number, floor, price, status):" << endl;
        for (int i = 0; i < num; i++)
        {
            cin >> ro;
            cin >> fl;
            cin >> pr >> st;
            ptr[i].set(ro, fl, pr, st, num);
        }
        ptr->sort(ptr);
        cout << endl;
        cout << "All rooms in the hotel:" << endl;
        for (int i = 0; i < num; i++)
        {
            ptr[i].print(ptr[i].returnRoom(), ptr[i].returnFloor(), ptr[i].returnPrice(), ptr[i].returnStatus());
        }
    }
 
    // user instructions
    bool notEnd = true; //used to end the loop
    int count = 0; //used to avoid duplicate getline() called
    char ins[20];
    while (notEnd)
    {
        cout << endl;
        cout << "Input the instruction:" << endl;
        cin >> ins;
        int roomNum = 0;
        if (ins[0] == 'L' || ins[0] == 'l')
        {
            cout << "See you again!" << endl;
            notEnd = false;
            break;
        }
        else if (ins[0] == 'b' || ins[0] == 'B') {
            cin >> ins;
            roomNum = getNum(ins);
            for (int i = 0; i < num; i++)
            {
                if (ptr[i].extract(ptr[i]) == roomNum && ptr[i].returnStatus() == 1) {
                    cout << "Succeed!" << endl;
                    st = 0;
                    ptr[i].setStatus(st);
                }
                else if (ptr[i].extract(ptr[i]) == roomNum && ptr[i].returnStatus() != 1)
                {
                    cout << "Sorry, the room is not available. Try again." << endl;
                }
                else {
                    continue;
                }
            }
        }
        else if (ins[0] == 'r' || ins[0] == 'R') {
            cin >> ins;
            roomNum = getNum(ins);
            for (int i = 0; i < num; i++)
            {
                if (ptr[i].extract(ptr[i]) == roomNum) {
                    cout << "Thanks for using our services!" << endl;
                    st = 1;
                    ptr[i].setStatus(st);
                }
                else {
                    continue;
                }
            }
        }
    }
 
    // free the block of memory
    delete[] ptr;
    ptr = NULL;
 
    return 0;
}
