#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// DATA INITIALIZATION
	try {
		info = Info();
		std::ifstream file("../src/data.csv");

		info.ReadData(file);
		std::vector<Job> test = info.GetJobs();

		jobNames = info.GetJobNames();
		fieldNames = info.GetFieldNames();
	}
	catch (std::exception& e) {
		std::cout << "oops2" << std::endl;
	}
	ofBackground(255, 255, 255);
	ofSetWindowShape(1200, 800);
	gui.setup();
	gui.setPosition(60, 150);

	sortString = "";
	minChange = false;
	maxChange = false;
	multiplier = 0;

	myFont.load("Swansea-q3pd.ttf", 12);
	titleFont.load("Swansea-q3pd.ttf", 30);
	ofxGuiSetFont("Swansea-q3pd.ttf", 12);

	// Adding job field
	_textParameter.addListener(this, &ofApp::onTextChange);
	_parameters.setName("Job Field");
	_parameters.add(_textParameter.set("", ""));
	gui.add(_parameters);

	sal.addListener(this, &ofApp::SalMinChange);
	salaryInput.setName("Salary Min");
	salaryInput.add(sal.set("Min", 0, 0, 200000));
	gui.add(salaryInput);

	sal1.addListener(this, &ofApp::SalMaxChange);
	salaryInput1.setName("Salary Max");
	salaryInput1.add(sal1.set("Max", 0, 0, 200000));
	gui.add(salaryInput1);

	perc.addListener(this, &ofApp::PercChange);
	percentileInput.setName("Sort By Percentile");
	percentileInput.add(perc.set("", ""));
	gui.add(percentileInput);

	mul.addListener(this, &ofApp::onMulChange);
	mulInput.setName("Multiplier");
	mulInput.add(mul.set("Mul", 600.0, 100.0, 5000.0));
	gui.add(mulInput);

	bellX = (950 + 500) / 2 - 50;
	menuY = 600;
	menuX = 350;
	bellMin = 500;

	title = "";
}

void ofApp::onMulChange(float& num) {
	multiplier = num;
}

void ofApp::onTextChange(std::string& text) {
	title = text;
	bellX = (975 + 500) / 2;
	bellX -= 10 * text.length();
	if (text == "All")
		fieldInfo = info.GetJobs();
	else 
		fieldInfo = info.GetFieldInfo(text);

	sal.set("Min", 0, 0, 200000);
	sal1.set("Max", 0, 0, 200000);

	if (sortString == "")
		Median(fieldInfo);
	else if (sortString == "10")
		perc10(fieldInfo);
	else if (sortString == "25")
		perc25(fieldInfo);
	else if (sortString == "Median")
		Median(fieldInfo);
	else if (sortString == "75")
		perc75(fieldInfo);
	else if (sortString == "90")
		perc90(fieldInfo);
}

void ofApp::Median(std::vector<Job>& field) {
	std::vector<Job> copy = field;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	info.QuickSortMedian(field, 0, field.size() - 1);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	quickSortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

	std::chrono::steady_clock::time_point b = std::chrono::steady_clock::now();
	info.ShellSortMedian(copy);
	std::chrono::steady_clock::time_point e = std::chrono::steady_clock::now();
	shellSortTime = std::chrono::duration_cast<std::chrono::microseconds>(e - b).count();

	minChange = false;
	maxChange = false;
}

void ofApp::perc10(std::vector<Job>& field) {
	std::vector<Job> copy = field;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	info.QuickSort10Percentile(field, 0, field.size() - 1);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	quickSortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

	std::chrono::steady_clock::time_point b = std::chrono::steady_clock::now();
	info.ShellSort10Percentile(copy);
	std::chrono::steady_clock::time_point e = std::chrono::steady_clock::now();
	shellSortTime = std::chrono::duration_cast<std::chrono::microseconds>(e - b).count();

	minChange = false;
	maxChange = false;
}
void ofApp::perc25(std::vector<Job>& field) {
	std::vector<Job> copy = field;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	info.QuickSort25Percentile(field, 0, field.size() - 1);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	quickSortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

	std::chrono::steady_clock::time_point b = std::chrono::steady_clock::now();
	info.ShellSort25Percentile(copy);
	std::chrono::steady_clock::time_point e = std::chrono::steady_clock::now();
	shellSortTime = std::chrono::duration_cast<std::chrono::microseconds>(e - b).count();

	minChange = false;
	maxChange = false;
}
void ofApp::perc75(std::vector<Job>& field) {
	std::vector<Job> copy = field;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	info.QuickSort75Percentile(field, 0, field.size() - 1);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	quickSortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

	std::chrono::steady_clock::time_point b = std::chrono::steady_clock::now();
	info.ShellSort75Percentile(copy);
	std::chrono::steady_clock::time_point e = std::chrono::steady_clock::now();
	shellSortTime = std::chrono::duration_cast<std::chrono::microseconds>(e - b).count();

	minChange = false;
	maxChange = false;
}
void ofApp::perc90(std::vector<Job>& field) {
	std::vector<Job> copy = field;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	info.QuickSort90Percentile(field, 0, field.size() - 1);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	quickSortTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

	std::chrono::steady_clock::time_point b = std::chrono::steady_clock::now();
	info.ShellSort90Percentile(copy);
	std::chrono::steady_clock::time_point e = std::chrono::steady_clock::now();
	shellSortTime = std::chrono::duration_cast<std::chrono::microseconds>(e - b).count();

	minChange = false;
	maxChange = false;
}

void ofApp::SalMinChange(int& num) {
	salMin = num;
	minChange = true;
}

void ofApp::SalMaxChange(int& num) {
	salMax = num;
	maxChange = true;
}

void ofApp::PercChange(std::string& str) {
	sortString = str;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255, 255, 255);
	DrawMenu();
	ofSetColor(255, 255, 255);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWidth(), 580);
	gui.draw();
	ofSetColor(0, 0, 0);
	myFont.drawString("Enter what job field you'd like\n\n\n" 
					  "data for. Enter other specifying\n\n\n" 
					  "information then hit ENTER.", 50, 50);
	ofNoFill();
	ofDrawRectangle(40, 30, 240, 80);

	DrawBellCurve(fieldInfo);


	ofSetColor(0, 0, 0);
	titleFont.drawString(title, bellX, 250);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	menuY += ofGetPreviousMouseY() - y;

}

void ofApp::DrawBellCurve(std::vector<Job> curve) {
	ofSetLineWidth(2);
	if (curve.size() == 0)
		return;

	std::string quickString = "Quick Sort Time Elapsed: " + std::to_string(quickSortTime) + " microseconds";
	std::string shellString = "Shell Sort Time Elapsed: " + std::to_string(shellSortTime) + " microseconds";
	myFont.drawString(quickString, 800, 100);
	myFont.drawString(shellString, 800, 125);


	// Get min salary for the bell curve
	// Get max salary for the bell curve
	if (sortString == "" || sortString == "Median") {
		info.QuickSortMedian(curve, 0, curve.size() - 1);
		if (!minChange) {
			GetMedianMin(curve);
		}
		if (!maxChange)
			GetMedianMax(curve);
	}
	else if (sortString == "10") {
		info.QuickSort10Percentile(curve, 0, curve.size() - 1);
		if (!minChange) {
			Get10Min(curve);
		}
		if (!maxChange)
			Get10Max(curve);
	}
	else if (sortString == "25") {
		info.QuickSort25Percentile(curve, 0, curve.size() - 1);
		if (!minChange) {
			Get25Min(curve);
		}
		if (!maxChange)
			Get25Max(curve);
	}
	else if (sortString == "75") {
		info.QuickSort75Percentile(curve, 0, curve.size() - 1);
		if (!minChange) {
			Get75Min(curve);
		}
		if (!maxChange)
			Get75Max(curve);
	}
	else if (sortString == "90") {
		info.QuickSort90Percentile(curve, 0, curve.size() - 1);
		if (!minChange) {
			Get90Min(curve);
		}
		if (!maxChange)
			Get90Max(curve);
	}

	

	// Curve information
	int numGaps = 45;
	std::vector<float> count(numGaps, 0.0);
	int gap = (salMax - salMin) / numGaps;

	if (sortString == "" || sortString == "Median")
		CountMedian(count, curve, gap, numGaps);
	else if (sortString == "10")
		Count10(count, curve, gap, numGaps);
	else if (sortString == "25")
		Count25(count, curve, gap, numGaps);
	else if (sortString == "75")
		Count75(count, curve, gap, numGaps);
	else if (sortString == "90")
		Count90(count, curve, gap, numGaps);

	// normalizes the data so it doesn't get off the screen
	for (int i = 0; i < count.size(); i++) {
		count.at(i) /= curve.size();
		count.at(i) *= multiplier;
	}
	
	// draw the graph
	for (int i = 0; i < numGaps; i++) {
		ofDrawRectangle(500 + (i * 10), bellMin - count.at(i), 10, count.at(i));
	}
	
	// draw salary min
	string temp = "$" + std::to_string(salMin) + ".00";
	myFont.drawString(temp, 500, bellMin + 30);
	// draw salary max
	temp = "$" + std::to_string(salMax) + ".00";
	myFont.drawString(temp, 950, bellMin + 30);
}

void ofApp::GetMedianMin(std::vector<Job> curve) {
	for (int i = 0; i < curve.size(); i++) {
		if (curve.at(i).Get_A_MEDIAN() != 0) {
			salMin = curve.at(i).Get_A_MEDIAN();
			break;
		}
	}
}

void ofApp::GetMedianMax(std::vector<Job> curve) {
	salMax = curve.at(curve.size() - 1).Get_A_MEDIAN();
}

void ofApp::Get10Min(std::vector<Job> curve) {
	for (int i = 0; i < curve.size(); i++) {
		if (curve.at(i).Get_A_PCT10() != 0) {
			salMin = curve.at(i).Get_A_PCT10();
			break;
		}
	}
}

void ofApp::Get10Max(std::vector<Job> curve) {
	salMax = curve.at(curve.size() - 1).Get_A_PCT10();
}

void ofApp::Get25Min(std::vector<Job> curve) {
	for (int i = 0; i < curve.size(); i++) {
		if (curve.at(i).Get_A_PCT25() != 0) {
			salMin = curve.at(i).Get_A_PCT25();
			break;
		}
	}
}

void ofApp::Get25Max(std::vector<Job> curve) {
	salMax = curve.at(curve.size() - 1).Get_A_PCT25();
}

void ofApp::Get75Min(std::vector<Job> curve) {
	for (int i = 0; i < curve.size(); i++) {
		if (curve.at(i).Get_A_PCT75() != 0) {
			salMin = curve.at(i).Get_A_PCT75();
			break;
		}
	}
}

void ofApp::Get75Max(std::vector<Job> curve) {
	salMax = curve.at(curve.size() - 1).Get_A_PCT75();
}

void ofApp::Get90Min(std::vector<Job> curve) {
	for (int i = 0; i < curve.size(); i++) {
		if (curve.at(i).Get_A_PCT90() != 0) {
			salMin = curve.at(i).Get_A_PCT90();
			break;
		}
	}
}

void ofApp::Get90Max(std::vector<Job> curve) {
	salMax = curve.at(curve.size() - 1).Get_A_PCT90();
	}


void ofApp::CountMedian(std::vector<float>& count, std::vector<Job>& curve, int gap, int numGaps) {
	for (auto element : curve) {
		for (int i = 0; i < numGaps; i++) {
			if (element.Get_A_MEDIAN() > salMin + i * gap && element.Get_A_MEDIAN() < salMin + (i + 1) * gap) {
				count.at(i) += 1.0;
			}
		}
	}
}

void ofApp::Count10(std::vector<float>& count, std::vector<Job>& curve, int gap, int numGaps) {
	for (auto element : curve) {
		for (int i = 0; i < numGaps; i++) {
			if (element.Get_A_PCT10() > salMin + i * gap && element.Get_A_PCT10() < salMin + (i + 1) * gap) {
				count.at(i) += 1.0;
			}
		}
	}
}

void ofApp::Count25(std::vector<float>& count, std::vector<Job>& curve, int gap, int numGaps) {
	for (auto element : curve) {
		for (int i = 0; i < numGaps; i++) {
			if (element.Get_A_PCT25() > salMin + i * gap && element.Get_A_PCT25() < salMin + (i + 1) * gap) {
				count.at(i) += 1.0;
			}
		}
	}
}

void ofApp::Count75(std::vector<float>& count, std::vector<Job>& curve, int gap, int numGaps) {
	for (auto element : curve) {
		for (int i = 0; i < numGaps; i++) {
			if (element.Get_A_PCT75() > salMin + i * gap && element.Get_A_PCT75() < salMin + (i + 1) * gap) {
				count.at(i) += 1.0;
			}
		}
	}
}

void ofApp::Count90(std::vector<float>& count, std::vector<Job>& curve, int gap, int numGaps) {
	for (auto element : curve) {
		for (int i = 0; i < numGaps; i++) {
			if (element.Get_A_PCT90() > salMin + i * gap && element.Get_A_PCT90() < salMin + (i + 1) * gap) {
				count.at(i) += 1.0;
			}
		}
	}
}

void ofApp::DrawMenu() {
	int i = 0;
	int j = 0;
	int h = 0;
	for (auto name : fieldNames) {
		name = name.substr(0, 35);
		myFont.drawString(name, 30 + j * menuX, menuY + h * 20);
		i++;
		j = i % 3;
		h = i / 3;
	}
}
