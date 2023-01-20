#include <PriorityQueue.h>

class CustomClass {
private:
    string name;
    int age;

public:
    CustomClass(string name, int age) : name(name), age(age) {}
    string getName() { return name; }
    int getAge() { return age; }
};

int main() {
    PriorityQueue<int> intQueue;
    intQueue.insert(3, 11);
    intQueue.insert(5, 12);
    intQueue.insert(1, 20);
    for (int i = 0; i < initial_capacity; i++)
    {
        intQueue.insert(i, i);
    }
    int highestPriority = intQueue.remove(); // returns 1
    cout << "Highest priority int: " << highestPriority << endl;

    PriorityQueue<string> stringQueue;
    stringQueue.insert("John", 10);
    stringQueue.insert("Jane", 7);
    stringQueue.insert("Bob", 15);
    string highestPriorityString = stringQueue.remove(); // returns "Bob"
    cout << "Highest priority string: " << highestPriorityString << endl;

    PriorityQueue<CustomClass> customQueue;
    customQueue.insert(CustomClass("John", 25), 10);
    customQueue.insert(CustomClass("Jane", 30), 7);
    customQueue.insert(CustomClass("Bob", 20), 15);
    CustomClass highestPriorityCustom = customQueue.remove(); // returns CustomClass("Bob", 20)
    cout << "Highest priority custom class: " << highestPriorityCustom.getName() << ", " << highestPriorityCustom.getAge() << endl;

    return 0;
}