#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

template<typename T>
void outputTempArray(vector<T> tempArr, int sizeArr) {
	for (int i = 0; i < sizeArr; ++i) {
		cout << tempArr[i] << " ";
	}
}

vector<string> deleteTab(vector<string> inputArr, int size) {
	for (int i = 0; i < size; ++i) {
		if (inputArr[i][0] == '\t') {
			inputArr[i].erase(0, 1);
		}
	}

	return inputArr;
}

vector<string> deleteSpace(vector<string> arrSpace, int sizeArrSpace) {
	for (int i = 0; i < sizeArrSpace; ++i) {
		if (arrSpace[i][0] == ' ') {
			arrSpace[i].erase(0, 1);
		}
	}

	return arrSpace;
}

vector<string> deleteLex(vector<string> arrLex, vector<int> indexLex, vector<int> valLex, int lenLex, int sizeArrLex, int sizeIndexLex) {
	for (int i = 0; i < sizeIndexLex; ++i) {
		if (valLex[i] == 0) {
			arrLex[indexLex[i]].erase(valLex[i], lenLex);
		}
		else {
			arrLex[indexLex[i]].erase(0, valLex[i]);
		}
	}

	arrLex = deleteSpace(arrLex, sizeArrLex);

	return arrLex;
}

vector<int> findBrack(vector<string> arrBrack, int numOfRow) {
	vector<int> indexOfBrack;

	int sizeArrBrack = arrBrack[numOfRow].size();

	for (int i = 0; i < sizeArrBrack; ++i) {
		if (arrBrack[numOfRow][i] == '(' || arrBrack[numOfRow][i] == ')') {
			indexOfBrack.push_back(i);
		}
	}

	return indexOfBrack;
}

vector<int> findComm(vector<string> arrComm, int indFirstComm, int indLastComm, int indOfRow) {
	vector<int> indexOfComm;
	for (int i = indFirstComm; i <= indLastComm; ++i) {
		if (arrComm[indOfRow][i] == ',') {
			indexOfComm.push_back(i);
		}
	}

	return indexOfComm;
}

vector<int> analyzeString(vector<string> complex, vector<int> brack, int numOfRow) {
	int brackSize = brack.size();

	bool var1;
	bool var2;

	vector<int>index;

	for (int i = 0; i < brackSize; i += 2) {
		int indOfComm = complex[numOfRow].find(',', brack[i]);

		if (complex[numOfRow][indOfComm - 1] != 'L' && complex[numOfRow][indOfComm - 1] != 'l') {

			if (complex[numOfRow][indOfComm - 1] != 'f' && complex[numOfRow][indOfComm - 1] != 'F') {

				int posOfRank = complex[numOfRow].find('e', brack[i]);
				int posOfDot = complex[numOfRow].find('.', brack[i]);

				if (posOfDot > brack[i] && posOfDot < indOfComm && posOfRank > brack[i] && posOfRank < indOfComm) {
					var1 = true;
				}
				else {
					var1 = false;
				}
			}
			else {
				var1 = false;
			}
		}
		else {
			var1 = false;
		}

		if (complex[numOfRow][brack[i + 1] - 1] != 'L' && complex[numOfRow][brack[i + 1] - 1] != 'l') {

			if (complex[numOfRow][brack[i + 1] - 1] != 'f' && complex[numOfRow][brack[i + 1] - 1] != 'F') {

				int posOfRank1 = complex[numOfRow].find('e', indOfComm);
				int posOfDot1 = complex[numOfRow].find('.', indOfComm);

				if ((posOfRank1 == -1 || posOfRank1 > brack[i + 1]) && posOfDot1 > indOfComm && posOfDot1 < brack[i + 1]) {
					var2 = true;
				}
				else {
					var2 = false;
				}
			}
			else {
				var2 = false;
			}
		}
		else {
			var2 = false;
		}

		if (var1 && var2) {
			index.push_back(i);

			index.push_back(i + 1);
		}
	}
	return index;
}

ofstream& generationObject(ofstream& out, vector<string> suitComplex, int ind1, int ind2, int numOfRow) {
	vector<char> object;


	for (int i = ind1; i <= ind2; ++i) {
		object.push_back(suitComplex[numOfRow][i]);
	}

	int sizeObj = object.size();
	for (int i = 0; i < sizeObj; ++i) {
		out << object[i];
	}

	out << endl;

	return out;

}

int main() {
	ifstream in("input.txt");

	vector<string> inputStringArray;
	string mes;

	const string LEX = "complex";
	const int LEX_SIZE = LEX.length();

	while (!in.eof()) {
		getline(in, mes);
		inputStringArray.push_back(mes);
	}

	int sizeInputArr = inputStringArray.size();

	inputStringArray = deleteTab(inputStringArray, sizeInputArr); 
	inputStringArray = deleteSpace(inputStringArray, sizeInputArr); 

	

	vector<int> indexOfLex; 
	vector<int> valueOfLex; 

	int value;
	for (int i = 0; i < sizeInputArr; ++i) {
		value = inputStringArray[i].find(LEX, 0);
		if (value != -1) {
			indexOfLex.push_back(i); 
			valueOfLex.push_back(value);
		}
	}
	
	int sizeIndexLex = indexOfLex.size();

	inputStringArray = deleteLex(inputStringArray, indexOfLex, valueOfLex, LEX_SIZE, sizeInputArr, sizeIndexLex); 
	
	ofstream out("result.txt");

	for (int i = 0; i < sizeIndexLex; ++i) {
		vector<int> indBrack = findBrack(inputStringArray, indexOfLex[i]); 
		vector<int> suitBrack = analyzeString(inputStringArray, indBrack, indexOfLex[i]); 

		int sizeSuit = suitBrack.size() / 2;

		if (sizeSuit == 0) {
			continue;
		}
		else {
			int t = indBrack[suitBrack[0]];

			bool log = false;

			for (int k = 0; k < t; ++k) {
				if (inputStringArray[indexOfLex[i]][k] == ',') {
					log = true;
					break;
				}
			}

			if (!log) {
				if (sizeSuit == 1) {
					generationObject(out, inputStringArray, 0, indBrack[suitBrack[1]], indexOfLex[i]);
				}
				else {

					generationObject(out, inputStringArray, 0, indBrack[suitBrack[1]], indexOfLex[i]);

					vector<int> commas;

					for (int it = 3; it < sizeSuit * 2; it += 2) {
						int newInd;

						commas = findComm(inputStringArray, indBrack[suitBrack[it] - 2] + 3, indBrack[suitBrack[it]], indexOfLex[i]);

						int sizeCommas = commas.size();

						if (sizeCommas == 1) {
							newInd = indBrack[suitBrack[it] - 2] + 3;
						}
						else {
							newInd = commas[sizeCommas - 2] + 2;
						}

						generationObject(out, inputStringArray, newInd, indBrack[suitBrack[it]], indexOfLex[i]);
					}
				}
			}
			else {
				if (sizeSuit == 1) {
					vector<int> commas = findComm(inputStringArray, 0, indBrack[suitBrack[0]], indexOfLex[i]);

					int sizeCommas = commas.size();

					int newInd = commas[sizeCommas - 1] + 2;

					generationObject(out, inputStringArray, newInd, indBrack[suitBrack[1]], indexOfLex[i]);
					
				}
				else {
					vector<int> commas;

					commas = findComm(inputStringArray, 0, indBrack[suitBrack[0]], indexOfLex[i]);

					int sizeCommas = commas.size();

					generationObject(out, inputStringArray, commas[sizeCommas - 1] + 2, indBrack[suitBrack[1]], indexOfLex[i]);

					for (int it = 3; it < sizeSuit * 2; it += 2) {
						commas = findComm(inputStringArray, indBrack[suitBrack[it] - 2] + 3, indBrack[suitBrack[it]], indexOfLex[i]);

						int newInd;
						int sizeComm = commas.size();
						
						if (sizeComm == 1) {
							newInd = indBrack[suitBrack[it] - 2] + 3;
						}
						else {
							newInd = commas[sizeComm  - 2] + 2;
						}

						generationObject(out, inputStringArray, newInd, indBrack[suitBrack[it]], indexOfLex[i]);
					}
					
				}
			}

		}
	}

	system("pause");
	return 0;
}