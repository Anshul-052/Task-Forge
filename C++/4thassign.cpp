#include <iostream>

using namespace std;

struct shop
{
    string Product;
    int price;
    int ratings;
};

int main()
{
    int n;
    int i = 0;

    cout << "Enter number of products: ";
    cin >> n;
    shop arr[n];

    while (i < n)
    {
        cout << "Enter product, price and ratings: ";
        cin >> arr[i].Product >> arr[i].price >> arr[i].ratings;
        i += 1;
    }

    int c;

    cout << "1.Sort based on price" << endl;
    cout << "2.Sort based on rating" << endl;

    cout << "Enter on what basis you want to sort";
    cin >> c;
    string tempproduct;
    int tempprice, temprate;
    if (c == 1)
    {
        cout << "Bubble sort" << endl;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j].price > arr[j + 1].price)
                {
                    tempproduct = arr[j].Product;
                    arr[j].Product = arr[j + 1].Product;

                    tempprice = arr[j].price;
                    arr[j].price = arr[j + 1].price;

                    temprate = arr[j].ratings;
                    arr[j].ratings = arr[j + 1].ratings;
                    arr[j + 1].Product = tempproduct;
                    arr[j + 1].price = tempprice;
                    arr[j + 1].ratings = temprate;
                }
            }
        }
        cout << "Sorted array: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i].Product << " " << endl;
        }
        cout << endl;

        cout << "Insertion sort" << endl;
        for (int i = 1; i < n; i++)
        {
            int key = arr[i].price;
            string key2 = arr[i].Product;
            int key3 = arr[i].ratings;
            int j = i - 1;

            while (j >= 0 && arr[j].price > key)
            {
                arr[j + 1].price = arr[j].price;
                arr[j + 1].Product = arr[j].Product;
                arr[j + 1].ratings = arr[j].ratings;
                j--;
            }
            arr[j + 1].price = key;
            arr[j + 1].Product = key2;
            arr[j + 1].ratings = key3;

            cout << "Sorted: " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << arr[i].Product << " ";
                cout << endl;
            }
        }
    }

    else
     {
        cout << "Bubble sort" << endl;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j].ratings > arr[j + 1].ratings)
                {
                    tempproduct = arr[j].Product;
                    arr[j].Product = arr[j + 1].Product;

                    tempprice = arr[j].price;
                    arr[j].price = arr[j + 1].price;

                    temprate = arr[j].ratings;
                    arr[j].ratings = arr[j + 1].ratings;
                    arr[j + 1].Product = tempproduct;
                    arr[j + 1].price = tempprice;
                    arr[j + 1].ratings = temprate;
                }
            }
        }
        cout << "Sorted array: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i].Product << " " << endl;
        }
        cout << endl;

        cout << "Insertion sort" << endl;
        for (int i = 1; i < n; i++)
        {
            int key = arr[i].ratings;
            string key2 = arr[i].Product;
            int key3 = arr[i].price;
            int j = i - 1;

            while (j >= 0 && arr[j].ratings > key)
            {
                arr[j + 1].ratings = arr[j].ratings;
                arr[j + 1].Product = arr[j].Product;
                arr[j + 1].price = arr[j].price;
                j--;
            }
            arr[j + 1].price = key;
            arr[j + 1].Product = key2;
            arr[j + 1].ratings = key3;

            cout << "Sorted: " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << arr[i].Product << " ";
                cout << endl;
            }
        }
    }


    return 0;
}