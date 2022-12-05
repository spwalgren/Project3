#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <exception>
#include <set>
#include "Job.h"



class Info {
	std::vector<Job> jobs;
	std::set<std::string> jobNames;
	std::set<std::string> fieldNames;

public:
	void ReadData(std::ifstream& file);
	std::vector<Job> GetJobs();
	std::set<std::string> GetJobNames();
	std::set<std::string> GetFieldNames();

	std::vector<Job> GetFieldInfo(std::string name);

	/*====== SORTING =====*/
	void ShellSortMedian(std::vector<Job>& arr);
	void ShellSort10Percentile(std::vector<Job>& arr);
	void ShellSort25Percentile(std::vector<Job>& arr);
	void ShellSort75Percentile(std::vector<Job>& arr);
	void ShellSort90Percentile(std::vector<Job>& arr);
	void QuickSortMedian(std::vector<Job> &arr, int begin, int end);
	int QuickSortHelperMedian(std::vector<Job> &arr, int begin, int end);
	void QuickSort10Percentile(std::vector<Job> &arr, int begin, int end);
	int QuickSortHelper10Percent(std::vector<Job> &arr, int begin, int end);
	void QuickSort25Percentile(std::vector<Job> &arr, int begin, int end);
	int QuickSortHelper25Percent(std::vector<Job> &arr, int begin, int end);
	void QuickSort75Percentile(std::vector<Job> &arr, int begin, int end);
	int QuickSortHelper75Percent(std::vector<Job> &arr, int begin, int end);
	void QuickSort90Percentile(std::vector<Job> &arr, int begin, int end);
	int QuickSortHelper90Percent(std::vector<Job> &arr, int begin, int end);
};