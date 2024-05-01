#include <iostream>

using namespace std;

void MenuTask()
{
    cout << "    Menu Task\n";
    cout << "    1.  Task 1\n";
    cout << "    2.  Task 2\n";
    cout << "    3.  Exit\n";
}

class VectorShort
{
private:
    short *data;
    int size;
    int value;
    int codeError;
    static int objectCount;

public:
    VectorShort() : size(1), codeError(0)
    {
        objectCount++;
        data = new short[size];
        if (data == nullptr)
        {
            codeError = OUT_OF_MEMORY;
            return;
        }
        data[0] = 0;
    }

    VectorShort(int s) : size(s), value(0), codeError(NONE)
    {
        objectCount++;
        data = new short[s];
        if (data == nullptr)
        {
            codeError = OUT_OF_MEMORY;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            data[i] = value;
        }
    }

    VectorShort(int s, short initValue) : size(s), value(value), codeError(NONE)
    {
        objectCount++;
        data = new short[s];
        if (data == nullptr)
        {
            codeError = OUT_OF_MEMORY;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            data[i] = initValue;
        }
    }

    VectorShort(const VectorShort &other) : size(other.size), codeError(NONE)
    {
        objectCount++;
        size = other.size;
        data = new short[size];
        if (data == nullptr)
        {
            codeError = OUT_OF_MEMORY;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    ~VectorShort()
    {
        objectCount--;
        delete[] data;
    }

    VectorShort &operator++()
    {
        for (int i = 0; i < size; i++)
        {
            ++data[i];
        }
        return *this;
    }

    VectorShort operator++(int)
    {
        VectorShort temp(*this);
        operator++();
        return temp;
    }

    VectorShort &operator--()
    {
        for (int i = 0; i < size; i++)
        {
            --data[i];
        }
        return *this;
    }

    VectorShort operator--(int)
    {
        VectorShort temp(*this);
        operator--();
        return temp;
    }

    bool operator!()
    {
        return size != 0;
    }

    VectorShort operator~()
    {
        VectorShort result(*this);
        for (int i = 0; i < size; i++)
        {
            result.data[i] = ~result.data[i];
        }
        return result;
    }

    VectorShort operator-()
    {
        VectorShort result(*this);
        for (int i = 0; i < size; i++)
        {
            result.data[i] = -result.data[i];
        }
        return result;
    }

    VectorShort &operator=(const VectorShort &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new short[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    VectorShort &operator+=(const VectorShort &other)
    {
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] += other.data[i];
            }
        }
        return *this;
    }

    VectorShort &operator-=(const VectorShort &other)
    {
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] -= other.data[i];
            }
        }
        return *this;
    }

    VectorShort &operator*=(int scalar)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] *= scalar;
        }
        return *this;
    }

    VectorShort &operator/=(int scalar)
    {
        if (scalar != 0)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] /= scalar;
            }
        }
        return *this;
    }

    VectorShort &operator%=(int scalar)
    {
        if (scalar != 0)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] %= scalar;
            }
        }
        return *this;
    }

    VectorShort &operator|=(const VectorShort &other)
    {
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] |= other.data[i];
            }
        }
        return *this;
    }

    VectorShort &operator^=(const VectorShort &other)
    {
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] ^= other.data[i];
            }
        }
        return *this;
    }

    VectorShort &operator&=(const VectorShort &other)
    {
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] &= other.data[i];
            }
        }
        return *this;
    }

    VectorShort operator+(const VectorShort &other) const
    {
        VectorShort result(*this);
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] += other.data[i];
            }
        }
        return result;
    }

    VectorShort operator-(const VectorShort &other) const
    {
        VectorShort result(*this);
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] -= other.data[i];
            }
        }
        return result;
    }

    VectorShort operator*(const VectorShort &other) const
    {
        VectorShort result(*this);
        for (int i = 0; i < size; i++)
        {
            result.data[i] *= other.data[i];
        }
        return result;
    }

    VectorShort operator/(const VectorShort &other) const
    {
        VectorShort result(*this);
        if (other.data != 0)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] /= other.data[i];
            }
        }
        return result;
    }

    VectorShort operator%(int scalar) const
    {
        VectorShort result(*this);
        if (scalar != 0)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] %= scalar;
            }
        }
        return result;
    }

    VectorShort operator|(const VectorShort &other) const
    {
        VectorShort result(*this);
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] |= other.data[i];
            }
        }
        return result;
    }

    VectorShort operator^(const VectorShort &other) const
    {
        VectorShort result(*this);
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] ^= other.data[i];
            }
        }
        return result;
    }

    VectorShort operator&(const VectorShort &other) const
    {
        VectorShort result(*this);
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] &= other.data[i];
            }
        }
        return result;
    }

    friend VectorShort operator>>(istream &is, VectorShort &vec)
    {
        for (int i = 0; i < vec.size; i++)
        {
            is >> vec.data[i];
        }
        return vec;
    }

    friend ostream &operator<<(ostream &os, const VectorShort &vec)
    {
        for (int i = 0; i < vec.size; i++)
        {
            os << vec.data[i] << " ";
        }
        return os;
    }

    VectorShort operator<<(int shift) const
    {
        VectorShort result(*this);
        for (int i = 0; i < size; i++)
        {
            result.data[i] <<= shift;
        }
        return result;
    }

    VectorShort operator>>(int shift) const
    {
        VectorShort result(*this);
        for (int i = 0; i < size; i++)
        {
            result.data[i] >>= shift;
        }
        return result;
    }

    bool operator==(const VectorShort &other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] != other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const VectorShort &other) const
    {
        return !(*this == other);
    }

    short &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            codeError = INDEX_OUT_OF_RANGE;
            return data[0];
        }
        return data[index];
    }

    void allocateMemory(int s)
    {
        size = s;
        data = new short[size];
    }

    void freeMemory()
    {
        delete[] data;
        size = 0;
    }

    void operator()()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    bool operator>(const VectorShort &other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] <= other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator>=(const VectorShort &other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] < other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator<(const VectorShort &other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] >= other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator<=(const VectorShort &other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] > other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    void Output()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "v [ " << i << " ] " << data[i] << endl;
        }
        cout << endl;
    }

    enum ErrorCodes
    {
        NONE = 0,
        OUT_OF_MEMORY,
        INDEX_OUT_OF_RANGE
    };

    static int ObjectCount()
    {
        return objectCount;
    }

    void ConsoleInput()
    {
        cout << "Size ";
        cin >> size;
        delete[] data;
        data = new short[size];
        cout << "Elements ";
        for (int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
    }
};

class Associative
{
    // Node structure for linked list
    struct Node
    {
        string email;
        string phone;
        Node *next;

        // Constructor to initialize Node
        Node(const string &e, const string &p) : email(e), phone(p), next(nullptr) {}
    };

    Node *head;
    int errorCode;

public:
    enum ErrorCodes
    {
        NONE = 0,
        EMAIL_NOT_FOUND
    };

    // Initialize Associative
    Associative() : head(nullptr), errorCode(NONE) {}

    // Clean up memory
    ~Associative()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Create associations
    void createAssociations(const string &email, const string &phone)
    {
        Node *newNode = new Node(email, phone);
        newNode->next = head;
        head = newNode;
    }

    // Retrieve phone number using email
    string operator[](const string &email)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->email == email)
            {
                errorCode = NONE;
                return current->phone;
            }
            current = current->next;
        }
        errorCode = EMAIL_NOT_FOUND;
        return 0;
    }

    // Search operator
    string operator()(const string &email)
    {
        return (*this)[email];
    }

    int getErrorCode() const
    {
        return errorCode;
    }

    // Friend function to overload the << operator for printing Associative objects
    friend ostream &operator<<(ostream &os, const Associative &assoc)
    {
        Node *current = assoc.head;
        while (current != nullptr)
        {
            os << current->email << ": " << current->phone << endl;
            current = current->next;
        }
        return os;
    }

    // Friend function to overload the >> operator for inputting Associative objects
    friend istream &operator>>(istream &is, Associative &assoc)
    {
        string email, phone;
        while (true)
        {
            cout << "Email and phone number (Q to quit) ";
            is >> email;
            if (email == "q")
                break;
            is >> phone;
            assoc.createAssociations(email, phone);
        }
        return is;
    }
};

int VectorShort::objectCount = 0;

int main()
{
    MenuTask();

    int choice;

    do
    {
        cout << "Choice ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Task 1
        {
            VectorShort v1;
            VectorShort v2;

            cout << "Vector 1" << endl;
            v1.ConsoleInput();
            cout << "Vector 2" << endl;
            v2.ConsoleInput();
            cout << endl;

            cout << "v1" << endl;
            v1.Output();
            cout << "v2" << endl;
            v2.Output();

            VectorShort sum = v1 + v2;
            VectorShort diff = v1 - v2;

            cout << "v1 += v2" << endl;
            sum.Output();
            cout << "v1 -= v2" << endl;
            diff.Output();

            cout << "v1 == v2 = " << (v1 == v2) << endl;
            cout << "v1 != v2 = " << (v1 != v2) << endl;
            cout << "v1 > v2 = " << (v1 > v2) << endl;
            cout << "v2 <= v1 = " << (v2 <= v1) << endl;
            cout << endl;

            VectorShort v3 = v1 * v2;
            VectorShort v4 = v1 / v2;

            cout << "v1 * v2" << endl;
            v3.Output();
            cout << "v1 / v2" << endl;
            v4.Output();

            VectorShort v5 = v1 ^ v2;
            VectorShort v6 = v1 | v2;

            cout << "v1 ^ v2" << endl;
            v5.Output();
            cout << "v1 | v2" << endl;
            v6.Output();

            cout << "Object count = " << VectorShort::ObjectCount() << endl;

            choice = 3;
            break;
        }
        case 2: // Task 2
        {
            Associative contacts;

            cin >> contacts;
            cout << endl;

            cout << "Associations " << endl;
            cout << contacts;

            string searchEmail;
            cout << "Email to search for its number ";
            cin >> searchEmail;

            string phoneNumber = contacts[searchEmail];
            if (contacts.getErrorCode() == Associative::EMAIL_NOT_FOUND)
            {
                cout << "Email not found" << endl;
            }
            else
            {
                cout << searchEmail << ": " << phoneNumber << endl;
            }
            choice = 3;
            break;
        }
        case 3: // Exit
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
