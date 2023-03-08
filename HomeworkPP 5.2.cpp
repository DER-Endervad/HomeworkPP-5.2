#include <iostream>
template<class T>
class table
{
private:
    class table_two;
    int row, col;
    table_two* arrint;
    class table_two
    {
    public:
        int* sarrint;
        table_two() {}
        table_two(int size)
        {
            sarrint = new int[size];
        }
        int& operator [] (int i)
        {
            return sarrint[i];
        }
    };

public:
    table(const int rows, const int cols)
    {
        rows < 1 ? row = 1 : row = rows;
        cols < 1 ? col = 1 : col = cols;
        arrint = new table_two[row];
        for (int i = 0; i < row; i++)
        {
            arrint[i] = table_two(col);
        }
    }
    table_two& operator [] (int i)
    {
        return arrint[i];
    }
    ~table()
    {
        for (int i = 0; i < row; i++)
        {
            if (arrint[i].sarrint != nullptr)
                delete[](arrint[i].sarrint);
        }
        if (arrint != nullptr)
            delete[] arrint;
    }
};
int main()
{
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl; // выводит 4
    system("Pause");
    return 0;
}
