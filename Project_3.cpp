#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Job.h"
#include "Info.h"
using namespace std;

void shellsortMEDIAN(vector<Job> &sort, int size){
    int gap = size/2;
    while (gap > 0){
        int i = gap;
        while (i < size){
            Job temp = sort[i];
            int j;
            for (j = i; j >= gap and sort[j - gap].Get_A_MEDIAN() > temp.Get_A_MEDIAN(); j -= gap)
                sort[j] = sort[j - gap];
            sort[j] = temp;
            i += 1;
        }
        gap /= 2;
    }
}

void shellsort10PERCENTILE(vector<Job> &sort, int size){
    int gap = size/2;
    while (gap > 0){
        int i = gap;
        while (i < size){
            Job temp = sort[i];
            int j;
            for (j = i; j >= gap and sort[j - gap].Get_A_PCT10() > temp.Get_A_PCT10(); j -= gap)
                sort[j] = sort[j - gap];
            sort[j] = temp;
            i += 1;
        }
        gap /= 2;
    }
}
void shellsort25PERCENTILE(vector<Job> &sort, int size){
    int gap = size/2;
    while (gap > 0){
        int i = gap;
        while (i < size){
            Job temp = sort[i];
            int j;
            for (j = i; j >= gap and sort[j - gap].Get_A_PCT25() > temp.Get_A_PCT25(); j -= gap)
                sort[j] = sort[j - gap];
            sort[j] = temp;
            i += 1;
        }
        gap /= 2;
    }
}
void shellsort75PERCENTILE(vector<Job> &sort, int size){
    int gap = size/2;
    while (gap > 0){
        int i = gap;
        while (i < size){
            Job temp = sort[i];
            int j;
            for (j = i; j >= gap and sort[j - gap].Get_A_PCT75() > temp.Get_A_PCT75(); j -= gap)
                sort[j] = sort[j - gap];
            sort[j] = temp;
            i += 1;
        }
        gap /= 2;
    }
}
void shellsort90PERCENTILE(vector<Job> &sort, int size){
    int gap = size/2;
    while (gap > 0){
        int i = gap;
        while (i < size){
            Job temp = sort[i];
            int j;
            for (j = i; j >= gap and sort[j - gap].Get_A_PCT90() > temp.Get_A_PCT90(); j -= gap)
                sort[j] = sort[j - gap];
            sort[j] = temp;
            i += 1;
        }
        gap /= 2;
    }
}

int quicksorthelperMEDIAN(vector<Job> &sort, int begin, int end){
    Job pivot = sort[begin];
    int counter = 0;
    int l = begin + 1;
    while (l <= end) {
        if (sort[l].Get_A_MEDIAN() <= pivot.Get_A_MEDIAN())
            counter++;
        l++;
    }
    int index = begin + counter;
    swap(sort[index], sort[begin]);
    int i = begin, j = end;
    while (i < index and j > index) {
        while (sort[j].Get_A_MEDIAN() > pivot.Get_A_MEDIAN()) {
            j-=1;
        }
        while (sort[i].Get_A_MEDIAN() <= pivot.Get_A_MEDIAN()) {
            i+=1;
        }
        if (i < index and j > index) {
            swap(sort[i++], sort[j--]);
        }
    }
    return index;
}

void quicksortMEDIAN(vector<Job> &sort, int begin, int end){
    if (begin >= end)
        return;
    int x;
    x = quicksorthelperMEDIAN(sort, begin, end);
    quicksortMEDIAN(sort, begin, x - 1);
    quicksortMEDIAN(sort, x + 1, end);
};

int quicksorthelper10PERCENT(vector<Job> &sort, int begin, int end){
    Job pivot = sort[begin];
    int counter = 0;
    int l = begin + 1;
    while (l <= end) {
        if (sort[l].Get_A_PCT10() <= pivot.Get_A_PCT10())
            counter++;
        l++;
    }
    int index = begin + counter;
    swap(sort[index], sort[begin]);
    int i = begin, j = end;
    while (i < index and j > index) {
        while (sort[j].Get_A_PCT10() > pivot.Get_A_PCT10()) {
            j-=1;
        }
        while (sort[i].Get_A_PCT10() <= pivot.Get_A_PCT10()) {
            i+=1;
        }
        if (i < index and j > index) {
            swap(sort[i++], sort[j--]);
        }
    }
    return index;
}

void quicksort10PERCENT(vector<Job> &sort, int begin, int end){
    if (begin >= end)
        return;
    int x;
    x = quicksorthelper10PERCENT(sort, begin, end);
    quicksort10PERCENT(sort, begin, x - 1);
    quicksort10PERCENT(sort, x + 1, end);
};

int quicksorthelper25PERCENT(vector<Job> &sort, int begin, int end){
    Job pivot = sort[begin];
    int counter = 0;
    int l = begin + 1;
    while (l <= end) {
        if (sort[l].Get_A_PCT25() <= pivot.Get_A_PCT25())
            counter++;
        l++;
    }
    int index = begin + counter;
    swap(sort[index], sort[begin]);
    int i = begin, j = end;
    while (i < index and j > index) {
        while (sort[j].Get_A_PCT25() > pivot.Get_A_PCT25()) {
            j-=1;
        }
        while (sort[i].Get_A_PCT25() <= pivot.Get_A_PCT25()) {
            i+=1;
        }
        if (i < index and j > index) {
            swap(sort[i++], sort[j--]);
        }
    }
    return index;
}

void quicksort25PERCENT(vector<Job> &sort, int begin, int end){
    if (begin >= end)
        return;
    int x;
    x = quicksorthelper25PERCENT(sort, begin, end);
    quicksort25PERCENT(sort, begin, x - 1);
    quicksort25PERCENT(sort, x + 1, end);
};

int quicksorthelper75PERCENT(vector<Job> &sort, int begin, int end){
    Job pivot = sort[begin];
    int counter = 0;
    int l = begin + 1;
    while (l <= end) {
        if (sort[l].Get_A_PCT75() <= pivot.Get_A_PCT75())
            counter++;
        l++;
    }
    int index = begin + counter;
    swap(sort[index], sort[begin]);
    int i = begin, j = end;
    while (i < index and j > index) {
        while (sort[j].Get_A_PCT75() > pivot.Get_A_PCT75()) {
            j-=1;
        }
        while (sort[i].Get_A_PCT75() <= pivot.Get_A_PCT75()) {
            i+=1;
        }
        if (i < index and j > index) {
            swap(sort[i++], sort[j--]);
        }
    }
    return index;
}

void quicksort75PERCENT(vector<Job> &sort, int begin, int end){
    if (begin >= end)
        return;
    int x;
    x = quicksorthelper75PERCENT(sort, begin, end);
    quicksort75PERCENT(sort, begin, x - 1);
    quicksort75PERCENT(sort, x + 1, end);
};

int quicksorthelper90PERCENT(vector<Job> &sort, int begin, int end){
    Job pivot = sort[begin];
    int counter = 0;
    int l = begin + 1;
    while (l <= end) {
        if (sort[l].Get_A_PCT90() <= pivot.Get_A_PCT90())
            counter++;
        l++;
    }
    int index = begin + counter;
    swap(sort[index], sort[begin]);
    int i = begin, j = end;
    while (i < index and j > index) {
        while (sort[j].Get_A_PCT90() > pivot.Get_A_PCT90()) {
            j-=1;
        }
        while (sort[i].Get_A_PCT90() <= pivot.Get_A_PCT90()) {
            i+=1;
        }
        if (i < index and j > index) {
            swap(sort[i++], sort[j--]);
        }
    }
    return index;
}

void quicksort90PERCENT(vector<Job> &sort, int begin, int end){
    if (begin >= end)
        return;
    int x;
    x = quicksorthelper90PERCENT(sort, begin, end);
    quicksort90PERCENT(sort, begin, x - 1);
    quicksort90PERCENT(sort, x + 1, end);
};
//
//int main()
//{
//    Info info;
//    std::ifstream file("data.csv");
//    if (!file.is_open)
//        return 12;
//
//    info.ReadData(file);
//
//    int choice;
//    cout << "SHELL SORT OPTIONS" << endl;
//    cout << "Enter 1 to sort MEDIAN by shell sort" << endl;
//    cout << "Enter 2 to sort ANNUAL 10th PERCENTILE by shell sort" << endl;
//    cout << "Enter 3 to sort ANNUAL 25th PERCENTILE by shell sort" << endl;
//    cout << "Enter 4 to sort ANNUAL 75th PERCENTILE by shell sort" << endl;
//    cout << "Enter 5 to sort ANNUAL 90th PERCENTILE by shell sort" << endl;
//    cout << "---------------------------------------------" << endl;
//    cout << "QUICK SORT OPTIONS" << endl;
//    cout << "Enter 6 to sort MEDIAN by quick sort" << endl;
//    cout << "Enter 7 to sort ANNUAL 10th PERCENTILE by quick sort" << endl;
//    cout << "Enter 8 to sort ANNUAL 25th PERCENTILE by quick sort" << endl;
//    cout << "Enter 9 to sort ANNUAL 75th PERCENTILE by quick sort" << endl;
//    cout << "Enter 10 to sort ANNUAL 90th PERCENTILE by quick sort" << endl;
//
//    cin >> choice;
//    if(choice == 1){
//        shellsortMEDIAN(arr, arr.size());
//        for(int i = 0; i < arr.size(); i++){
//            std::cout << arr[i].Get_NAICS_TITLE() << " " << arr[i].Get_OCC_TITLE() << " " << arr[i].Get_A_PCT10() << " " << arr[i].Get_A_PCT25() << " " << arr[i].Get_A_MEDIAN() << " " << arr[i].Get_A_PCT75() << " " << arr[i].Get_A_PCT90() << std::endl;
//        }
//    }
//    if(choice == 2){
//        shellsort10PERCENTILE(arr, arr.size());
//        for(int i = 0; i < arr.size(); i++){
//            std::cout << arr[i].Get_NAICS_TITLE() << " " << arr[i].Get_OCC_TITLE() << " " << arr[i].Get_A_PCT10() << " " << arr[i].Get_A_PCT25() << " " << arr[i].Get_A_MEDIAN() << " " << arr[i].Get_A_PCT75() << " " << arr[i].Get_A_PCT90() << std::endl;
//        }
//    }
//    if(choice == 3){
//        shellsort25PERCENTILE(arr, arr.size());
//        for(int i = 0; i < arr.size(); i++){
//            std::cout << arr[i].Get_NAICS_TITLE() << " " << arr[i].Get_OCC_TITLE() << " " << arr[i].Get_A_PCT10() << " " << arr[i].Get_A_PCT25() << " " << arr[i].Get_A_MEDIAN() << " " << arr[i].Get_A_PCT75() << " " << arr[i].Get_A_PCT90() << std::endl;
//        }
//    }
//    if(choice == 4){
//        shellsort75PERCENTILE(arr, arr.size());
//        for(int i = 0; i < arr.size(); i++){
//            std::cout << arr[i].Get_NAICS_TITLE() << " " << arr[i].Get_OCC_TITLE() << " " << arr[i].Get_A_PCT10() << " " << arr[i].Get_A_PCT25() << " " << arr[i].Get_A_MEDIAN() << " " << arr[i].Get_A_PCT75() << " " << arr[i].Get_A_PCT90() << std::endl;
//        }
//    }
//    if(choice == 5){
//        shellsort90PERCENTILE(arr, arr.size());
//        for(int i = 0; i < arr.size(); i++){
//            std::cout << arr[i].Get_NAICS_TITLE() << " " << arr[i].Get_OCC_TITLE() << " " << arr[i].Get_A_PCT10() << " " << arr[i].Get_A_PCT25() << " " << arr[i].Get_A_MEDIAN() << " " << arr[i].Get_A_PCT75() << " " << arr[i].Get_A_PCT90() << std::endl;
//        }
//    }
//    if(choice == 6){
//        quicksortMEDIAN(arr, 0, arr.size());
//        for(int i = 0; i < arr.size(); i++){
//            std::cout << arr[i].Get_NAICS_TITLE() << " " << arr[i].Get_OCC_TITLE() << " " << arr[i].Get_A_PCT10() << " " << arr[i].Get_A_PCT25() << " " << arr[i].Get_A_MEDIAN() << " " << arr[i].Get_A_PCT75() << " " << arr[i].Get_A_PCT90() << std::endl;
//        }
//    }
//    if(choice == 7){
//        quicksort10PERCENT(arr, 0, arr.size());
//        for(int i = 0; i < arr.size(); i++){
//            std::cout << arr[i].Get_NAICS_TITLE() << " " << arr[i].Get_OCC_TITLE() << " " << arr[i].Get_A_PCT10() << " " << arr[i].Get_A_PCT25() << " " << arr[i].Get_A_MEDIAN() << " " << arr[i].Get_A_PCT75() << " " << arr[i].Get_A_PCT90() << std::endl;
//        }
//    }
//    if(choice == 8){
//        quicksort25PERCENT(arr, 0, arr.size());
//        for(int i = 0; i < arr.size(); i++){
//            std::cout << arr[i].Get_NAICS_TITLE() << " " << arr[i].Get_OCC_TITLE() << " " << arr[i].Get_A_PCT10() << " " << arr[i].Get_A_PCT25() << " " << arr[i].Get_A_MEDIAN() << " " << arr[i].Get_A_PCT75() << " " << arr[i].Get_A_PCT90() << std::endl;
//        }
//    }
//    if(choice == 9){
//        quicksort75PERCENT(arr, 0, arr.size());
//        for(int i = 0; i < arr.size(); i++){
//            std::cout << arr[i].Get_NAICS_TITLE() << " " << arr[i].Get_OCC_TITLE() << " " << arr[i].Get_A_PCT10() << " " << arr[i].Get_A_PCT25() << " " << arr[i].Get_A_MEDIAN() << " " << arr[i].Get_A_PCT75() << " " << arr[i].Get_A_PCT90() << std::endl;
//        }
//    }
//    if(choice == 10){
//        quicksort90PERCENT(arr, 0, arr.size());
//        for(int i = 0; i < arr.size(); i++){
//            std::cout << arr[i].Get_NAICS_TITLE() << " " << arr[i].Get_OCC_TITLE() << " " << arr[i].Get_A_PCT10() << " " << arr[i].Get_A_PCT25() << " " << arr[i].Get_A_MEDIAN() << " " << arr[i].Get_A_PCT75() << " " << arr[i].Get_A_PCT90() << std::endl;
//        }
//    }
//    else{
//        cout << "Invalid option.";
//    }
//
//}
