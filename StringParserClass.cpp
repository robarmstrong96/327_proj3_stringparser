/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <string>
#include <string.h>
#include <iostream>
#include <cstring>
#include "../327_proj3_test/includes/StringParserClass.h"
#include "../327_proj3_test/includes/constants.h"

KP_StringParserClass::StringParserClass::StringParserClass(): pStartTag(0), pEndTag(0), areTagsSet(false) { }

KP_StringParserClass::StringParserClass::~StringParserClass() {
	cleanup();
}

int KP_StringParserClass::StringParserClass::setTags(const char *pStart, const char *pEnd) {
	if (pStart != NULL || pEnd != NULL) {
		pStartTag = (char*)pStart;
		pEndTag = (char*)pEnd;
		areTagsSet = true;
		return SUCCESS;
	}
	return ERROR_TAGS_NULL;
}

int KP_StringParserClass::StringParserClass::getDataBetweenTags(char *pDataToSearchThru, std::vector<std::string> &myVector) {
	if (pStartTag == NULL || pEndTag == NULL)
		return ERROR_TAGS_NULL;
	if (pDataToSearchThru == NULL)
		return ERROR_DATA_NULL;
 	myVector.clear();
 	std::string temp = std::string(pDataToSearchThru);
 	while (temp.find(pStartTag) != std::string::npos && temp.find(pEndTag) != std::string::npos) {
 		std::cout << "\tOriginal: " << temp << '\n';
 		int start = temp.find(pStartTag);
 		int end = temp.find(pEndTag);
 		myVector.push_back(temp.substr(start + (int)std::strlen(pStartTag), end - start - (int)std::strlen(pEndTag) + 1));
 		temp.erase(start, (end - start) + (int)strlen(pEndTag));
 		std::cout << "\tNew: " << myVector[0] << " \t Current String Left: " << temp << '\n';
 	}
 	for (int i = 0; i < myVector.size(); i++) {
 		std::cout << myVector[i] << std::endl;
 	}
 	free(pDataToSearchThru);
	return SUCCESS;
}

void KP_StringParserClass::StringParserClass::cleanup() {
	if(pStartTag) {
		delete [] pStartTag;
	}
	pStartTag = 0;
	if(pEndTag) {
		delete [] pEndTag;
	}
	pEndTag = 0;
	areTagsSet = false;
}

int KP_StringParserClass::StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd) {
	return SUCCESS;
}
