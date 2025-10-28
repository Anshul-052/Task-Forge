#include <iostream>

using namespace std;

struct phone
{
  string name;
  long long no;
};

int main()
{
  int temp = 0;
  phone arr[4];
  arr[0].name = "Anshul";
  arr[0].no = 9674330847;
  arr[1].name = "Aai";
  arr[1].no = 8459674438;
  arr[2].name = "Baba";
  arr[2].no = 8830054201;
  arr[3].name = "Tai";
  arr[3].no = 7415953452;

  string inp;
  cout << "Enter name to find number: ";
  cin >> inp;

  for (int i = 0; i < 4; i++)
  {
    if (arr[i].name == inp)
    {
      cout<<"Linear search"<<endl;
      cout << "No: " << arr[i].no << endl;
    }
    else
      continue;
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = i + 1; j < 3 - i; j++)
    {
      if (arr[j].name > arr[j + 1].name){
        string temp = arr[j].name;
      arr[j].name = arr[j + 1].name;
      arr[j + 1].name = temp;

      long long tempNo = arr[j].no;
      arr[j].no = arr[j + 1].no;
      arr[j + 1].no = tempNo;
      }
    }
  }

  int low = 0, high = 3;
  int b = -1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid].name == inp)
    {
      b = mid;
      break;
    }
    else if (arr[mid].name < inp)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  cout<<"Binary search"<<endl;
  cout << "No: " << arr[b].no;

  return 0;
}