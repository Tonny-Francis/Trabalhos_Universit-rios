#include <iostream>
using namespace std;
class gato 
{
    private:
    int pet = 0;

    public:
    friend int cat (gato pos);
    friend int dog (gato po);
};
int cat (gato pos)
{
    cout << pos.pet;
}
int dog (gato po)
{
    cat(po);

}
int main ()
{
    gato g;
    dog (g);
    return 0;
}