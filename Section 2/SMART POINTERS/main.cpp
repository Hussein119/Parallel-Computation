#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Entity
{
public:
    Entity()
    {
        cout << "Create Entity" << endl;
    }

    ~Entity()
    {
        cout << "Destroyed Entity" << endl;
    }

    void print()
    {
        cout << "Print \n";
    }
};

int main()
{
    // unique_ptr<Entity> entity(new Entity());
    // unique_ptr<Entity> entity = make_unique<Entity>();
    // entity->print();

    // unique_ptr<int> ptr1 = make_unique<int>(20);

    // cout << &ptr1 << endl;
    // cout << *ptr1 << endl;

    shared_ptr<Entity> sharedEntity = make_shared<Entity>();

    // number of owners for this shared pointer
    cout << "Shared count: " << sharedEntity.use_count() << endl;

    shared_ptr<Entity> sharedEntity2 = sharedEntity;

    cout << "Shared count after: " << sharedEntity.use_count() << endl;

    weak_ptr<int> wePtr1;

    {
        shared_ptr<int> shPtr1 = make_shared<int>(25);
        wePtr1 = shPtr1;
    }

    cin.get();
}