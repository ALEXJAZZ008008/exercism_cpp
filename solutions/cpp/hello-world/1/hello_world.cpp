#include "hello_world.h"

using namespace std;

namespace hello_world
{
    string hello()
    {
        return "Hello, World!";
    }

    int main()
    {
        std::cout << hello();

        return 1;
    }
}  // namespace hello_world
