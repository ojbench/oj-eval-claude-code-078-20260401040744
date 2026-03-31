#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
	int st, ed, val;
	int *data;

public:
    // Default constructor
    Evil() : st(0), ed(0), val(0) {
        data = new int[1];
        data[0] = 0;
    }

    // Constructor with parameters
    Evil(int _st, int _ed, int _val) : st(_st), ed(_ed), val(_val) {
        int size = ed - st + 1;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    // Copy constructor
    Evil(const Evil& other) : st(other.st), ed(other.ed), val(other.val) {
        int size = ed - st + 1;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~Evil() {
        delete[] data;
    }

    // Assignment operator overload
    Evil& operator=(const Evil& other) {
        if (this != &other) {
            delete[] data;
            st = other.st;
            ed = other.ed;
            val = other.val;
            int size = ed - st + 1;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Subscript operator overload (non-const version)
    int& operator[](int i) {
        if (i < st || i > ed) {
            return data[0];  // Return first element (st day)
        }
        return data[i - st];
    }

    // Subscript operator overload (const version)
    const int& operator[](int i) const {
        if (i < st || i > ed) {
            return data[0];  // Return first element (st day)
        }
        return data[i - st];
    }

    // Prefix ++ overload
    Evil& operator++() {
        val++;
        return *this;
    }

    // Postfix ++ overload
    Evil operator++(int) {
        Evil temp(*this);
        val++;
        return temp;
    }

    // Output operator overload
    friend ostream& operator<<(ostream& os, const Evil& e) {
        os << e.val << " ";
        for (int i = 0; i < e.ed - e.st + 1; i++) {
            os << e.data[i] << " ";
        }
        os << endl;
        return os;
    }

    void Print(){
	    cout << val << " ";
	    for(int i = 0;i < ed-st+1;++i)
	        cout << data[i] <<" ";
	    cout << endl;
	}
};

#endif//EVIL_HPP
