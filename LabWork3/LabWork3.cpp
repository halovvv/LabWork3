#include <iostream>
#include <cstdlib>
#include <strstream> 
using namespace std;

class Vector
{
private:
	int size;
	int* arr = 0;
    int max, min;
public:
	Vector(int s) :
        size(s)
	{
		arr = new int[size]; 
	}

	~Vector()
	{
		delete[] arr;
	}

    void setsize(int newsize)
    {
        
        arr = new int[newsize];
        size = newsize;
    }
    void setarr(int newsize, int* newarr)
    {
       
        arr = new int[newsize];
        size = newsize;
        for (int i = 0; i < size; i++)
        {
            arr[i] = newarr[i];
        }
    }

    void getarr()
    {
        if ((size != 0) && (arr != 0))
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << "  ";
            }
        }
        cout << endl;
    }

    void FirstArr()
   {
        float sum= 0.00;
        int swch= 0;
        for (int i = 0; i < size; i++)
        {
            sum += static_cast<float>(arr[i]);
        }

        for (int i= 0; i< size;i ++)
        {
            for (int j = (size - 1); j >= i + 1; j--)
            {
                if (arr[j] > arr[j-1])
                {
                    swch = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = swch;
                }
            }
        }

        cout << "Max is " << arr[0] << endl;
        cout << "Min is " << arr[size-1] << endl;
        cout << "Average is " << sum/ 10 << endl;
   }

    int SecondArr()
    {
        max = min = abs(arr[0]);
        int max_index = 0, min_index = 0, mult = 1;
        for (int i = 0; i < 10; i++)
        {
            if (abs(arr[i]) > max)
            {
                max = abs(arr[i]);
                max_index = i;
            }
            if (abs(arr[i]) < min)
            {
                min = abs(arr[i]);
                min_index = i;
            }
        }
        if (max_index < min_index)
        {
            int i = max_index;
            max_index = min_index;
            min_index = i;
        }
        for (int i = min_index + 1; i < max_index; i++)

        {
            mult *= arr[i];
        }

        cout << "Multiplication = " << mult << endl;

        return mult;
    }
};

int main()
{
    int firstarr[] = { 5,7,3,-7,3,-7,8,0,2,1 };
    int seconarr[] = { -100,56,88,2,33,-4,8,0,11,-76 };

    int a;
    
    Vector first(10);
    Vector second(10);

    second.setarr(10, seconarr);
    first.setarr(10, firstarr);

    first.getarr();
    first.FirstArr();
    first.getarr();
     
    cout << endl;

    second.getarr();
    second.SecondArr();
    second.getarr();

    cin>> a;
}