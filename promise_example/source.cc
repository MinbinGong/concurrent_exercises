#include <iostream>
#include <thread>
#include <utility>
#include <future>
#include <vector>

int func(int x)
{
    return x + 2;
}

int main()
{
    std::packaged_task<int(int)> tsk(func);
    std::future<int> fut = tsk.get_future();

    std::thread(std::move(tsk), 2).detach();

    int value = fut.get();
    std::cout << "The result is " << value << ".\n";

    std::vector<std::shared_future<int>> v;
    auto f = std::async(std::launch::async, [](int a, int b) { return a + b; }, 2, 3);
    v.push_back(f);
    std::cout << "The shared_future result is " << v[0].get() << std::endl;

    return 0;
}