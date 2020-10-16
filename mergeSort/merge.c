#include<stdio.h>
#include<stdlib.h>
#include"file.h"
// урьдчилан эрэмбэлэгдсэн a_l урт бүхий a хүснэгт болон b_l урт бүхий b хүснэгтийг эрэмбэлэн нийлүүлэж out хүснэгтэд хадгал 
void merge(int *out,int *a, int *b, int a_l, int b_l){
    
}
//a хүснэгтийн begin-ээс end завсарт орших элементүүдийг эрэмбэл
void merge_sort(int *a, int begin, int end){
    
}
int main(){
    int a_l=count_integers("unSortedInput.txt");
    int *a=read_integers("unSortedInput.txt",a_l);
    merge_sort(a,0,a_l-1);
    write_integers("sortedOut.txt", a, a_l);
    int b_l=count_integers("sortedInput1.txt");
    int *b=read_integers("sortedInput1.txt",b_l);
    int c_l=count_integers("sortedInput2.txt");
    int *c=read_integers("sortedInput2.txt",c_l);
    write_integers("mergedOut.txt", out, b_l+c_l);
    return 0;
}
