#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void simpleVector() {
    vector<int> vect;
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.shrink_to_fit();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
}

void smarterVector() {
    vector<int> vect;
    vect.reserve(20);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.shrink_to_fit();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
}

void simpleVectorNoCout() {
    vector<int> vect;

    vect.push_back(1);

    vect.push_back(1);

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);

    vect.pop_back();

    vect.pop_back();

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();

    vect.shrink_to_fit();
}

void smarterVectorNoCout() {
    vector<int> vect;
    vect.reserve(20);

    vect.push_back(1);

    vect.push_back(1);

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);

    vect.pop_back();

    vect.pop_back();

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();

    vect.shrink_to_fit();
}
///////////////////////////////////////2//////////////////////////////////////////////
class Stop {
private:
    long id;
    string name;
    double latitude;
    double longitude;

public:
    Stop(long id, const string &name, double latitude, double longitude);
};

int main()
{
    simpleVector();

    cout << endl << endl;
    smarterVector();

    cout << endl << endl;
    auto start = chrono::steady_clock::now();
    for(int i =0; i < 1000; ++i)
        simpleVectorNoCout();
    auto end = chrono::steady_clock::now();

    auto start1 = chrono::steady_clock::now();
    for(int i =0; i < 1000; ++i)
        smarterVectorNoCout();
    auto end1 = chrono::steady_clock::now();

    cout << "Simple vector called 1000x time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
    cout << "Smarter vector called 1000x time: " << chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count() << endl;

    ///////////////////////////////////////////////////2///////////////////////////////////////////////
    vector<Stop> stopsList;

    stopsList.push_back(Stop(1, "Test", 5.1, 5.2));
    stopsList.emplace_back(1, "Test", 5.1, 5.2);

    return 0;
}
