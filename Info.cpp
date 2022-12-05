#include "Info.h"

void Info::ReadData(std::ifstream& theFile) {
    std::string oneRowOfData = "";

    std::string AREA = "";
    std::string AREA_TITLE = "";
    std::string AREA_TYPE = "";
    std::string PRIM_STATE = "";
    std::string NAICS = "";
    std::string NAICS_TITLE = "";
    std::string I_GROUP = "";
    std::string OWN_CODE = "";
    std::string OCC_CODE = "";
    std::string OCC_TITLE = "";
    std::string O_GROUP = "";
    std::string TOT_EMP = "";
    std::string EMP_PRSE = "";
    std::string JOBS_1000 = "";
    std::string LOC_QUOTIENT = "";
    std::string PCT_TOTAL = "";
    std::string PCT_RPT = "";
    std::string H_MEAN = "";
    std::string A_MEAN = "";
    std::string MEAN_PRSE = "";
    std::string H_PCT10 = "";
    std::string H_PCT25 = "";
    std::string H_MEDIAN = "";
    std::string H_PCT75 = "";
    std::string H_PCT90 = "";
    std::string A_PCT10 = "";
    std::string A_PCT25 = "";
    std::string A_MEDIAN = "";
    std::string A_PCT75 = "";
    std::string A_PCT90 = "";
    std::string ANNUAL = "";
    std::string HOURLY = "";

    if (!theFile.is_open()) {
        std::cout << "oops" << std::endl;
    }
    for (int i = -2777; i < 100000; i++) {
        if (i < 0) {
            std::getline(theFile, oneRowOfData);
            continue;
        }
        else if (i >= 0) {

            std::getline(theFile, AREA, ',');
            std::getline(theFile, AREA_TITLE, ',');
            std::getline(theFile, AREA_TYPE, ',');
            std::getline(theFile, PRIM_STATE, ',');
            std::getline(theFile, NAICS, ',');
            std::getline(theFile, NAICS_TITLE, ',');
            if (NAICS_TITLE.find('"') != std::string::npos) {
                NAICS_TITLE.erase(0, 1);
                NAICS_TITLE.append(",");

                std::string NAICS_TITLE2 = "";
                std::getline(theFile, NAICS_TITLE2, '"');
                NAICS_TITLE.append(NAICS_TITLE2);

                std::getline(theFile, NAICS_TITLE2, ',');
            }
            std::getline(theFile, I_GROUP, ',');
            if (I_GROUP.find('"') != std::string::npos) {
                I_GROUP.erase(0, 1);
                I_GROUP.append(",");

                std::string I_GROUP2 = "";
                std::getline(theFile, I_GROUP2, '"');
                I_GROUP.append(I_GROUP2);

                std::getline(theFile, I_GROUP2, ',');
            }
            std::getline(theFile, OWN_CODE, ',');
            std::getline(theFile, OCC_CODE, ',');

            std::getline(theFile, OCC_TITLE, ',');
            if (OCC_TITLE.find('"') != std::string::npos) {
                OCC_TITLE.erase(0, 1);
                OCC_TITLE.append(",");

                std::string OCC_TITLE2 = "";
                std::getline(theFile, OCC_TITLE2, '"');
                OCC_TITLE.append(OCC_TITLE2);

                std::getline(theFile, OCC_TITLE2, ',');
            }
            std::getline(theFile, O_GROUP, ',');
            std::getline(theFile, TOT_EMP, ',');
            if (TOT_EMP.find('"') != std::string::npos) {
                TOT_EMP.erase(0, 1);
                TOT_EMP.append(",");

                std::string TOT_EMP2 = "";
                std::getline(theFile, TOT_EMP2, '"');
                TOT_EMP.append(TOT_EMP2);

                std::getline(theFile, TOT_EMP2, ',');
            }
            std::getline(theFile, EMP_PRSE, ',');
            std::getline(theFile, JOBS_1000, ',');
            std::getline(theFile, LOC_QUOTIENT, ',');
            std::getline(theFile, PCT_TOTAL, ',');
            std::getline(theFile, PCT_RPT, ',');
            std::getline(theFile, H_MEAN, ',');
            std::getline(theFile, A_MEAN, ',');
            if (A_MEAN.find('"') != std::string::npos) {
                A_MEAN.erase(0, 1);
                A_MEAN.append(",");

                std::string A_MEAN2 = "";
                std::getline(theFile, A_MEAN2, '"');
                A_MEAN.append(A_MEAN2);

                std::getline(theFile, A_MEAN2, ',');
            }
            std::getline(theFile, MEAN_PRSE, ',');
            std::getline(theFile, H_PCT10, ',');
            std::getline(theFile, H_PCT25, ',');
            std::getline(theFile, H_MEDIAN, ',');
            std::getline(theFile, H_PCT75, ',');
            std::getline(theFile, H_PCT90, ',');
            std::getline(theFile, A_PCT10, ',');
            if (A_PCT10.find('"') != std::string::npos) {
                A_PCT10.erase(0, 1);
                std::string A_PCT102 = "";
                std::getline(theFile, A_PCT102, '"');
                A_PCT10.append(A_PCT102);

                std::getline(theFile, A_PCT102, ',');
            }
            std::getline(theFile, A_PCT25, ',');
            if (A_PCT25.find('"') != std::string::npos) {
                A_PCT25.erase(0, 1);
                std::string A_PCT252 = "";
                std::getline(theFile, A_PCT252, '"');
                A_PCT25.append(A_PCT252);

                std::getline(theFile, A_PCT252, ',');
            }
            std::getline(theFile, A_MEDIAN, ',');
            if (A_MEDIAN.find('"') != std::string::npos) {
                A_MEDIAN.erase(0, 1);
                std::string A_MEDIAN2 = "";
                std::getline(theFile, A_MEDIAN2, '"');
                A_MEDIAN.append(A_MEDIAN2);

                std::getline(theFile, A_MEDIAN2, ',');
            }

            std::getline(theFile, A_PCT75, ',');
            if (A_PCT75.find('"') != std::string::npos) {
                A_PCT75.erase(0, 1);
                std::string A_PCT752 = "";
                std::getline(theFile, A_PCT752, '"');
                A_PCT75.append(A_PCT752);

                std::getline(theFile, A_PCT752, ',');
            }
            std::getline(theFile, A_PCT90, ',');
            if (A_PCT90.find('"') != std::string::npos) {
                A_PCT90.erase(0, 1);
                std::string A_PCT902 = "";
                std::getline(theFile, A_PCT902, '"');
                A_PCT90.append(A_PCT902);

                std::getline(theFile, A_PCT902, ',');
            }
            std::getline(theFile, ANNUAL, ',');
            std::getline(theFile, HOURLY, ',');
            if (A_PCT10 == "#" || A_PCT10 == "*") {
                A_PCT10 = "0";
            }

            if (A_PCT25 == "#" || A_PCT25 == "*") {
                A_PCT25 = "0";
            }

            if (A_MEDIAN == "#" || A_MEDIAN == "*") {
                A_MEDIAN = "0";
            }

            if (A_PCT75 == "#" || A_PCT75 == "*") {
                A_PCT75 = "0";
            }

            if (A_PCT90 == "#" || A_PCT90 == "*") {
                A_PCT90 = "0";
            }


            Job oneJob = Job(NAICS_TITLE, OCC_TITLE, std::stoi(A_PCT10), std::stoi(A_PCT25), std::stoi(A_MEDIAN), std::stoi(A_PCT75), std::stoi(A_PCT90));

            try {
                jobs.push_back(oneJob);
                jobNames.insert(OCC_TITLE);
                fieldNames.insert(NAICS_TITLE);
            }
            catch (std::exception& e) {
                std::cout << "oops1" << std::endl;
            }

            std::string endOfLine = "";
            std::getline(theFile, endOfLine);
        }
    }
}

std::vector<Job> Info::GetJobs() {
    return jobs;
}

std::set<std::string> Info::GetJobNames() {
    return jobNames;
}

std::set<std::string> Info::GetFieldNames() {
    return fieldNames;
}

std::vector<Job> Info::GetFieldInfo(std::string name) {
    std::vector<Job> fieldData;

    if (name == "")
        return fieldData;

    for (int i = 0; i < jobs.size(); i++) {
        if (jobs.at(i).Get_NAICS_TITLE().find(name) != std::string::npos) {
            fieldData.push_back(jobs.at(i));
        }
    }

    return fieldData;
}

// s1.find(s2) != std::string::npos

/*====== SORTING =====*/
void Info::ShellSortMedian(std::vector<Job>& arr) {
    int gap = arr.size() / 2;
    int size = arr.size();
    while (gap > 0) {
        int i = gap;
        while (i < size) {
            Job temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].Get_A_MEDIAN() > temp.Get_A_MEDIAN(); j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
            i += 1;
        }
        gap /= 2;
    }
}

void Info::ShellSort10Percentile(std::vector<Job>& arr) {
    int size = arr.size();
    int gap = size / 2;
    while (gap > 0) {
        int i = gap;
        while (i < size) {
            Job temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].Get_A_PCT10() > temp.Get_A_PCT10(); j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
            i += 1;
        }
        gap /= 2;
    }
}

void Info::ShellSort25Percentile(std::vector<Job>& arr) {
    int size = arr.size();
    int gap = size / 2;
    while (gap > 0) {
        int i = gap;
        while (i < size) {
            Job temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].Get_A_PCT25() > temp.Get_A_PCT25(); j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
            i += 1;
        }
        gap /= 2;
    }
}

void Info::ShellSort75Percentile(std::vector<Job>& arr) {
    int size = arr.size();
    int gap = size / 2;
    while (gap > 0) {
        int i = gap;
        while (i < size) {
            Job temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].Get_A_PCT75() > temp.Get_A_PCT75(); j -= gap)
                arr[j] =arr[j - gap];
            arr[j] = temp;
            i += 1;
        }
        gap /= 2;
    }
}

void Info::ShellSort90Percentile(std::vector<Job>& arr) {
    int size = arr.size();
    int gap = size / 2;
    while (gap > 0) {
        int i = gap;
        while (i < size) {
            Job temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].Get_A_PCT90() > temp.Get_A_PCT90(); j -= gap)
                arr[j] =arr[j - gap];
            arr[j] = temp;
            i += 1;
        }
        gap /= 2;
    }
}

int Info::QuickSortHelperMedian(std::vector<Job>& arr, int begin, int end) {
    Job pivot = arr[begin];
    int counter = 0;
    int l = begin + 1;
    while (l <= end) {
        if (arr[l].Get_A_MEDIAN() <= pivot.Get_A_MEDIAN())
            counter++;
        l++;
    }
    int index = begin + counter;
    std::swap(arr[index], arr[begin]);
    int i = begin, j = end;
    while (i < index && j > index) {
        while (arr[j].Get_A_MEDIAN() > pivot.Get_A_MEDIAN()) {
            j -= 1;
        }
        while (arr[i].Get_A_MEDIAN() <= pivot.Get_A_MEDIAN()) {
            i += 1;
        }
        if (i < index && j > index) {
            std::swap(arr[i++], arr[j--]);
        }
    }
    return index;
}

void Info::QuickSortMedian(std::vector<Job>& arr, int begin, int end) {
    if (begin >= end)
        return;
    int x;
    x = QuickSortHelperMedian(arr, begin, end);
    QuickSortMedian(arr, begin, x - 1);
    QuickSortMedian(arr, x + 1, end);
}

int Info::QuickSortHelper10Percent(std::vector<Job>& arr, int begin, int end) {
    Job pivot = arr[begin];
    int counter = 0;
    int l = begin + 1;
    while (l <= end) {
        if (arr[l].Get_A_PCT10() <= pivot.Get_A_PCT10())
            counter++;
        l++;
    }
    int index = begin + counter;
    std::swap(arr[index], arr[begin]);
    int i = begin, j = end;
    while (i < index && j > index) {
        while (arr[j].Get_A_PCT10() > pivot.Get_A_PCT10()) {
            j -= 1;
        }
        while (arr[i].Get_A_PCT10() <= pivot.Get_A_PCT10()) {
            i += 1;
        }
        if (i < index && j > index) {
            std::swap(arr[i++], arr[j--]);
        }
    }
    return index;
}

void Info::QuickSort10Percentile(std::vector<Job>& arr, int begin, int end) {
    if (begin >= end)
        return;
    int x = QuickSortHelper10Percent(arr, begin, end);
    QuickSort10Percentile(arr, begin, x - 1);
    QuickSort10Percentile(arr, x + 1, end);
}

int Info::QuickSortHelper25Percent(std::vector<Job>& arr, int begin, int end) {
    Job pivot = arr[begin];
    int counter = 0;
    int l = begin + 1;
    while (l <= end) {
        if (arr[l].Get_A_PCT25() <= pivot.Get_A_PCT25())
            counter++;
        l++;
    }
    int index = begin + counter;
    std::swap(arr[index], arr[begin]);
    int i = begin, j = end;
    while (i < index && j > index) {
        while (arr[j].Get_A_PCT25() > pivot.Get_A_PCT25()) {
            j -= 1;
        }
        while (arr[i].Get_A_PCT25() <= pivot.Get_A_PCT25()) {
            i += 1;
        }
        if (i < index && j > index) {
            std::swap(arr[i++], arr[j--]);
        }
    }
    return index;
}

void Info::QuickSort25Percentile(std::vector<Job>& arr, int begin, int end) {
    if (begin >= end)
        return;
    int x = QuickSortHelper25Percent(arr, begin, end);
    QuickSort25Percentile(arr, begin, x - 1);
    QuickSort25Percentile(arr, x + 1, end);
}

int Info::QuickSortHelper75Percent(std::vector<Job>& arr, int begin, int end) {
    Job pivot = arr[begin];
    int counter = 0;
    int l = begin + 1;
    while (l <= end) {
        if (arr[l].Get_A_PCT75() <= pivot.Get_A_PCT75())
            counter++;
        l++;
    }
    int index = begin + counter;
    std::swap(arr[index], arr[begin]);
    int i = begin, j = end;
    while (i < index && j > index) {
        while (arr[j].Get_A_PCT75() > pivot.Get_A_PCT75()) {
            j -= 1;
        }
        while (arr[i].Get_A_PCT75() <= pivot.Get_A_PCT75()) {
            i += 1;
        }
        if (i < index && j > index) {
            std::swap(arr[i++], arr[j--]);
        }
    }
    return index;
}

void Info::QuickSort75Percentile(std::vector<Job>& arr, int begin, int end) {
    if (begin >= end)
        return;
    int x = QuickSortHelper75Percent(arr, begin, end);
    QuickSort75Percentile(arr, begin, x - 1);
    QuickSort75Percentile(arr, x + 1, end);
}

int Info::QuickSortHelper90Percent(std::vector<Job>& arr, int begin, int end) {
    Job pivot = arr[begin];
    int counter = 0;
    int l = begin + 1;
    while (l <= end) {
        if (arr[l].Get_A_PCT90() <= pivot.Get_A_PCT90())
            counter++;
        l++;
    }
    int index = begin + counter;
    std::swap(arr[index], arr[begin]);
    int i = begin, j = end;
    while (i < index && j > index) {
        while (arr[j].Get_A_PCT90() > pivot.Get_A_PCT90()) {
            j -= 1;
        }
        while (arr[i].Get_A_PCT90() <= pivot.Get_A_PCT90()) {
            i += 1;
        }
        if (i < index && j > index) {
            std::swap(arr[i++], arr[j--]);
        }
    }
    return index;
}

void Info::QuickSort90Percentile(std::vector<Job>& arr, int begin, int end) {
    if (begin >= end)
        return;
    int x = QuickSortHelper90Percent(arr, begin, end);
    QuickSort90Percentile(arr, begin, x - 1);
    QuickSort90Percentile(arr, x + 1, end);
}