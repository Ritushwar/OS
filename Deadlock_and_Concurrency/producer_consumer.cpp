#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

using namespace std;

const int BUFFER_SIZE = 5;
queue<int> buffer;
mutex mtx;
condition_variable notFull, notEmpty;

int item = 0;

void producer(int id) {
    while (true) {
        unique_lock<mutex> lock(mtx);
        notFull.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });

        item++;
        buffer.push(item);
        cout << "Producer " << id << " produced item " << item << endl;

        lock.unlock();
        notEmpty.notify_one();

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void consumer(int id) {
    while (true) {
        unique_lock<mutex> lock(mtx);
        notEmpty.wait(lock, [] { return !buffer.empty(); });

        int consumed = buffer.front();
        buffer.pop();
        cout << "Consumer " << id << " consumed item " << consumed << endl;

        lock.unlock();
        notFull.notify_one();

        this_thread::sleep_for(chrono::milliseconds(800));
    }
}

int main() {
    thread p1(producer, 1);
    thread p2(producer, 2);
    thread c1(consumer, 1);
    thread c2(consumer, 2);

    p1.join();
    p2.join();
    c1.join();
    c2.join();

    return 0;
}
