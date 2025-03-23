#include<iostream>

using namespace std;

char a[] = "  bui minh hoa   ";
char *ptr;

int strln(char a[]) //Độ dài xâu
{
    int length = 0;
    const char* p = &a[0]; //chỉ thay đổi đ/c con trỏ p trỏ tới, ko thay đổi a

    while(*p != '\0')
    {
        length++;
        p++; // cộng 1, địa chỉ tăng 1 byte(char 1 byte)
    }
    return length;

}
//a
void reverse_char(char a[]) //Hàm đảo xâu
{
    int n = strln(a);
    for(char* p = &a[n-1]; p >= &a[0]; p--)
        cout << *p << endl;
}
//b
void delete_char(char a[], char c) //Hàm xóa ký tự trong xâu
{
    int n = strln(a);
    for(char* p = &a[0]; p <= &a[n-1]; p++)
        if(*p != c) cout << *p;
}
//c
void pad_right(char a[], int n) //Độn thêm ký tự vào cuối xâu để có độ dài n
{
    int size = strln(a);
    if(size >= n)
    {
        for(char* p = &a[0]; p <= &a[size-1]; p++)
            cout << *p;
    }
    else
    {
         char* p = a + size; // từ địa chỉ của a[0], cộng thêm size nhân 1 byte, để đến địa chỉ của a[n], tạo thêm 1 khoảng trắng cuối chuỗi
         while(size < n)
         {
             size++;
             *p = ' ';
             p++;
         }
         *p = '\0';
         for(char* p = &a[0]; p <= &a[n-1]; p++)
            cout << *p;
     }
}
//d
void pad_left(char a[], int n) //Độn trái
{
    int sz = strln(a);
    if(sz >= n)
    {
        for(char *p = &a[0]; p <= &a[sz-1]; p++)
                cout<< *p;
    }
    else
    {
       int add = n - sz;
       char* p = a + sz - 1;
       while(p >= a)  //Dịch các ký tự sang phải
       {
           *(p + add) = *p;
           p--;
       }
       p = a;
       for(int i = 0; i < add; i++)
            *(p + i) = ' ';
       a[n] = '\0';
       for(p = &a[0]; p <= &a[n-1]; p++)
            cout<<*p;
    }

}
//e
void truncate(char a[], int n) // Cắt đoạn cuối để có độ dài n
{
    int sz = strln(a);
    if(sz <= n)
    {
        for(char *p = &a[0]; p <= &a[n-1]; p++)
            cout<<*p;
    }
    else
    {
        for(char *p = &a[0]; p <= &a[n-1]; p++)
            cout<<*p;
    }

}
//f
bool is_palindrome(char a[]) // kiểm tra xâu đối xứng
{
    int n = strln(a);
    bool check = true;
    for(int i = 0; i < n/2; i++)
        if(*(ptr + i) != *(ptr + n - i - 1))
        {
            check = false;
            break;
        }
    return check;
}
//g
void trim_left(char a[]) // Xóa các ký tự trắng ở đầu xâu nếu có
{
    int n = strln(a);
    char* t = a;
    while(*t == ' ' && *t != '\0')
    {
        t++;
    }

    while(*t != '\0') // '\0' là ký tự kết thúc chuỗi
    {
        cout<<*t;
        t++;
    }

}
//h
void trim_right(char a[]) // Xóa ký tự trắng ở cuối xâu
{
     int n = strln(a);
     char *t;
     t = &a[n-1];
     while(t >= &a[0] && *t == ' ')
     {
         t--;
     }
     for(char *p = &a[0]; p <= t; p++)
        cout<<*p;
}


int main()
{
    char c = 'C';
    ptr = a;
    //trim_left(a)
    //reverse_char(a);
    //delete_char(a, c)
    //trim_right(a);
    cout<<is_palindrome(a);
    //truncate(a, 3);
    //pad_right(a, 25);
    //pad_left(a, 7);


}
