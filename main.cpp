#include <PriorityQueue.h>
//#include "main.h"

class CustomClass {
private:
    string name;
    int age;

public:
    CustomClass(string name, int age) : name(name), age(age) {}
    string getName() { return name; }
    int getAge() { return age; }
};
void resizing_then_removing()
{
    PriorityQueue<int> intQueue;
    intQueue.insert(3, 1);
    intQueue.insert(5, 2);
    intQueue.insert(1, 3);
    intQueue.insert(1, 0);
    //for (int i = 0; i < 1; i++)
    //{
    //    intQueue.insert(i, i);
    //}
    int highestPriority = intQueue.remove(); // returns 1
    //cout << "Highest priority int: " << highestPriority << endl;
    //intQueue.insert(1, -1);

    //PriorityQueue<string> stringQueue;
    //stringQueue.insert("John", 10);
    //stringQueue.insert("Jane", 7);
    //stringQueue.insert("Bob", 15);
    //string highestPriorityString = stringQueue.remove(); // returns "Bob"
    //cout << "Highest priority string: " << highestPriorityString << endl;

    //PriorityQueue<CustomClass> customQueue;
    //customQueue.insert(CustomClass("John", 25), 10);
    //customQueue.insert(CustomClass("Jane", 30), 7);
    //customQueue.insert(CustomClass("Bob", 20), 15);
    //CustomClass highestPriorityCustom = customQueue.remove(); // returns CustomClass("Bob", 20)
    //cout << "Highest priority custom class: " << highestPriorityCustom.getName() << ", " << highestPriorityCustom.getAge() << endl;
}

int main() {
    resizing_then_removing();
    cout << "Memory Leaks: " << _CrtDumpMemoryLeaks() << endl;
    return 0;
}

