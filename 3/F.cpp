#include <iostream>
#include <vector>
#include <string>

using namespace std;

 const char* getMaxSubstring()
{
    char *maxSubstring=_strings[0];
    //long T=clock();
    for(int i=1; i < len; i++)
        maxSubstring=GetLargestCommonSubstring(maxSubstring, _strings[i]);
    //cout<<clock()-T<<endl;
    return maxSubstring;
}

char* GetLargestCommonSubstring( char* str1, char* str2 ) {

    int strLen2=strlen(str2);
    const int solution_size = strLen2+ 1;

    int *x=new int[solution_size]();
    int *y= new int[solution_size]();

    int **previous = &x;
    int **current = &y;

    int max_length = 0;
    int result_index = 0;

    int j;
    int length;
    int J=strLen2 - 1;

    for(int i = strlen(str1) - 1; i >= 0; i--)
    {
        for(j = J; j >= 0; j--) 
        {
            if(str1[i] != str2[j]) 
                (*current)[j] = 0;
            else 
            {
                length = 1 + (*previous)[j + 1];
                if (length > max_length)
                {
                    max_length = length;
                    result_index = i;
                }

                (*current)[j] = length;
            }
        }

        swap(previous, current);
    }
    str1[max_length+result_index]='\0';
    return &(str1[result_index]);
}

int main() {
  int n;
  cin >> n;
  vector<string> ss(n);
  for (int i = 0; i < n; i++) {
    cin >> ss[i];
  }
  string maxs = ss[i];

  cout<< getMaxSubstring();
  return 0;
}