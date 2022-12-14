#include <iostream>

using namespace std;

double average(int a[], int students)
{  int Total = 0,i;
   double avg;
   for (i= 0;i<students; i++)
       Total += a[i];
   avg=(double)Total/students;
   return avg;
}

void sort(int a[], int students)
{ int i,j,t;
  for(i=0;i<students-1;i++)
     {
      for(j=i;j<students;j++)
        {
         if(a[i]>a[j])
            {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            }
        }
     }
}

double median(int *num, int student)
{  int nn1,nn2;
   if (student%2==0)
  {
         nn2=(student/2)-1;
         nn1=student/2;
         return((*(num+nn1)+*(num+nn1))/2.00);
     }
   else
   {
   return *(num+(student/2));
   }
}


int main()
{ 
    int Student,i;       
    float Mode,Range,Average;
    
    int *PointerArray;   

    cout << "Enter Students : ";
    cin >> Student;

    PointerArray =  new int[Student];

   for (int i= 0;i<Student;i++)
   {
         cout<<"Movies student "<<(i+1)<< " see : ";
         cin >> PointerArray[i];
   }

   sort(PointerArray, Student);

   cout<<"\nThe array is:\n";
   for(i=0;i<Student;i++)
   {
      cout<<"student "<<i+1<<" saw "<<PointerArray[i]<<" movies.\n";
   }

   cout << "\nthe median is "<<median(PointerArray, Student) << endl;
   cout << "the average is "<<average(PointerArray, Student) << endl;
   delete [] PointerArray;
   return 0;
}
