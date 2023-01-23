#include <PriorityQueue.h>
#include <Array.h>
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

void simple_test() {
    PriorityQueue<int> intQueue;
    PriorityQueue<int> intQueue2;
    intQueue.insert(3, 1);
    PriorityQueue<int> arrayOfQueues[2] = { intQueue, intQueue2 };
}

void resizing_then_removing()
{
    PriorityQueue<int> intQueue;
    intQueue.insert(3, 1);
    intQueue.insert(5, 2);
    intQueue.insert(1, 3);
    intQueue.insert(1, 0);
    int highestPriority = intQueue.remove(); // returns 1
}

void removing_then_resizing()
{
    PriorityQueue<int> intQueue;
    intQueue.insert(3, 1);
    int highestPriority = intQueue.remove(); // returns 1
    intQueue.insert(5, 2);
    intQueue.insert(1, 3);
    intQueue.insert(1, 0);
    intQueue.insert(1, 2);
}

void resizing_only()
{
    PriorityQueue<int> intQueue;
    intQueue.insert(3, 1);
    intQueue.insert(5, 2);
    intQueue.insert(1, 3);
    intQueue.insert(1, 0);
}
PriorityQueue<int>& pass_by_ref(PriorityQueue<int>& intQueue)
{
    intQueue.insert(3, 1);
    intQueue.insert(5, 2);
    intQueue.insert(1, 3);
    intQueue.insert(1, 0);
    return intQueue;
}

void test_pass_ref() {
    PriorityQueue<int> intQueue;
    auto queue_copy = pass_by_ref(intQueue);
    queue_copy.insert(5, 30);
    int highestPriority = intQueue.remove(); // returns 1
    int highestPriorityOfCopy = queue_copy.remove(); // returns 5
}

void queue_of_Array() {
    PriorityQueue<Array<int>> arrayQueue;
    Array<int> array;
    Array<int> array2;
    array.fill_Array(4);
    array2.fill_Array(6);
    arrayQueue.insert(array, 1); //we need copy ctor
    arrayQueue.insert(array2, 2);
    auto top_array = arrayQueue.remove(); //should be array2
}

void Array_of_queses() {
    Array <PriorityQueue<int>> queue_array;
    queue_array[0].insert(3, 1); //we need copy ctor
    queue_array[0].insert(5, 2); 
    queue_array[1].insert(8, 1); //we need copy ctor
    queue_array[2].insert(7, 2); 
    //queue_array[1] = intQueue2;
}

void removing_at_max_capacity()
{
    PriorityQueue<int> intQueue;
    intQueue.insert(3, 1);
    intQueue.insert(5, 2);
    intQueue.insert(1, 3);
    int highestPriority = intQueue.remove(); // returns 1
}

int main() {
    resizing_then_removing(); //works
    removing_then_resizing();//works
    removing_at_max_capacity(); //works
    resizing_only();//works
    simple_test();//works

    test_pass_ref();

    queue_of_Array();
    Array_of_queses();
    cout << "Memory Leaks: " << _CrtDumpMemoryLeaks() << endl;
    return 0;
}

