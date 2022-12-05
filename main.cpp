#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Job.h"
#include "Info.h"
#include "ofMain.h"
#include "ofApp.h"

/* Code citations:
 *
 * Authors: GeeksforGeeks
 * Date: Last updated: October 24, 2022
 * Title : ShellSort
 * Code version: C++
 * Type: Code implementation for shell sort
 * Website: https://www.geeksforgeeks.org/shellsort/
 *
 *
 * Authors: GeeksforGeeks
 * Date: Last updated: February 6, 2022
 * Title : C++ Program for QuickSort
 * Code version: C++
 * Type: Code implementation for quick sort
 * Website: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
 *
 * Concepts about how to store, sort, and implement the front end design were all
 * discussed with Ansh Kalariya, Jason Guan and Spencer Walgren.
 */

int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

	return 0;
}
