#pragma once

#include <vector>
#include <string>
#include <exception>
#include <algorithm>
#include <chrono>
#include "ofxGui.h"
#include "ofMain.h"
#include "Job.h"
#include "Info.h"


class ofApp : public ofBaseApp{
	std::set<std::string> jobNames;
	std::set<std::string> fieldNames;
	std::vector<Job> fieldInfo;
	std::string sortString;
	Info info;
	bool minChange;
	bool maxChange;


	int quickSortTime;
	int shellSortTime;

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

		void Median(std::vector<Job>& field);
		void perc10(std::vector<Job>& field);
		void perc25(std::vector<Job>& field);
		void perc75(std::vector<Job>& field);
		void perc90(std::vector<Job>& field);
		

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void onTextChange(std::string& text);

		void DrawBellCurve(std::vector<Job> curve);
		void DrawMenu();
		void SalMinChange(int& num);
		void SalMaxChange(int& num);
		void PercChange(std::string& str);

		void GetMedianMin(std::vector<Job> curve);
		void GetMedianMax(std::vector<Job> curve);
		void Get10Min(std::vector<Job> curve);
		void Get10Max(std::vector<Job> curve);
		void Get25Min(std::vector<Job> curve);
		void Get25Max(std::vector<Job> curve);
		void Get75Min(std::vector<Job> curve);
		void Get75Max(std::vector<Job> curve);
		void Get90Min(std::vector<Job> curve);
		void Get90Max(std::vector<Job> curve);

		void CountMedian(std::vector<float>& count, std::vector<Job>& curve, int gap, int numGaps);
		void Count10(std::vector<float>& count, std::vector<Job>& curve, int gap, int numGaps);
		void Count25(std::vector<float>& count, std::vector<Job>& curve, int gap, int numGaps);
		void Count75(std::vector<float>& count, std::vector<Job>& curve, int gap, int numGaps);
		void Count90(std::vector<float>& count, std::vector<Job>& curve, int gap, int numGaps);


		ofxPanel gui;

		int salMin;
		int salMax;
		int perMin;
		int perMax;

		ofParameterGroup _parameters;
		ofParameter<std::string> _textParameter;
		ofEventListener _textParameterListener;

		ofParameterGroup salaryInput;
		ofParameter<int> sal;
		ofEventListener salListener;

		ofParameterGroup salaryInput1;
		ofParameter<int> sal1;
		ofEventListener salListener1;

		ofParameterGroup percentileInput;
		ofParameter<std::string> perc;
		ofEventListener percListener;

		ofTrueTypeFont myFont;
		ofTrueTypeFont titleFont;

		int bellX;
		int menuY;
		int menuX;
		int bellMin;

		std::string title;
};
