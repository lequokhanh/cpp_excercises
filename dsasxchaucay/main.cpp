#include <iostream>

using namespace std;
struct Point
{
    int x, y;
};

void Sort(Point *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].x > arr[j].x)
            {
                Point temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else if (arr[i].x == arr[j].x)
            {
                if (arr[i].y > arr[j].y)
                {
                    Point temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

void OutputArray(Point *arr, int n)
{
    cout << 1 << endl;
    int i = 0;
    for (; i < n; i++)
    {
        if (arr[i].x - 500 > arr[i - 1].x)
            break;
        cout << arr[i].x << " " << arr[i].y << endl;
    }
    if (i < n)
    {
        cout << 2 << endl;
        for (; i < n; i++)
        {
            cout << arr[i].x << " " << arr[i].y << endl;
        }
    }
}

int main()
{
    Point *x = new Point[99999];
    int i = 0;
    while (true)
    {
        cin >> x[i].x;
        if (x[i].x == 0)
            break;
        cin >> x[i].y;
        i++;
    }
    if (i != 0)
    {
        Sort(x, i);
        OutputArray(x, i);
    }
    return 0;
}