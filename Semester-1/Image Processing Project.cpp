#include<iostream> 
#include<fstream>
#include<string>
#include<cstdlib>
#include<math.h>
#include<vector>
bool Saved = false;
using namespace std;

#define MaxRows 500
#define MaxCols 500

struct grayImage {

	unsigned short setPixel(unsigned short value, int r, int c) {
		if (r >= Rows || c >= Cols || r < 0 || c < 0)
			return -1;
		Image[r][c] = value;
		return value;
	}
	int getPixel(int r, int c) {
		if (r >= Rows || c >= Cols || r < 0 || c < 0)
			return -1;
		return Image[r][c];
	}

	int setRows(int rows) {
		if (rows < 1 || rows > MaxRows)
			return -1;
		Rows = rows;
		return Rows;
	}
	int getRows() {
		return Rows;
	}
	int setCols(int cols) {
		if (cols < 1 || cols > MaxCols)
			return -1;
		Cols = cols;
		return Cols;
	}
	int getCols() {
		return Cols;
	}
	int Save(string File_Name) {
		if (!loaded)
			return -1;

		if (File_Name.substr(File_Name.find_last_of(".") + 1) != "pgm")
			return -2;

		ofstream OUTPUT(File_Name.c_str());
		if (!OUTPUT)
			return -3;

		OUTPUT << "P2" << endl;
		OUTPUT << "# created by ANAS" << endl;
		OUTPUT << Cols << " " << Rows << " " << endl;
		OUTPUT << Maximum << endl;

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++)
				OUTPUT << Image[i][j] << " ";
			OUTPUT << endl;
		}

		Saved = true;
		OUTPUT.close();
		return 0;
	}
	int load(string File_Name) {
		if (File_Name.substr(File_Name.find_last_of(".") + 1) != "pgm")
			return -1;

		ifstream IN(File_Name.c_str());

		if (!IN)
			return -2;

		string MagicNum;
		string Comment;

		getline(IN, MagicNum);

		if (MagicNum != "P2") {
			IN.close();
			return -3;
		}

		getline(IN, Comment);
		setRows(Rows);
		setCols(Cols);

		IN >> Cols >> Rows >> Maximum;

		for (int i = 0; i < Rows; i++)
			for (int j = 0; j < Cols; j++)
				IN >> Image[i][j];
		IN.close();
		loaded = true;
		return 0;
	}
	void combineSideBySide(grayImage& Two, int fillvalue = 0) {
		for (int i = 0; i < Two.Rows; i++)
			for (int j = 0; j < Two.Cols; j++) {
				if (Cols + j < MaxCols)
					Image[i][Cols + j] = Two.Image[i][j];
			}
		if (Rows < Two.Rows)
			Rows = Two.Rows;
		Cols += Two.Cols;
		if (Cols > MaxCols)
			Cols = MaxCols;
	}
	void combineTopToBottom(grayImage& Two, int fillvalue = 0) {
		for (int i = 0; i < Two.Rows; i++)
			for (int j = 0; j < Two.Cols; j++) {
				if (Rows + i < MaxRows)
					Image[Rows + i][j] = Two.Image[i][j];
			}
		if (Cols < Two.Cols)
			Cols = Two.Cols;
		Rows += Two.Rows;

		if (Rows > MaxRows)
			Rows = MaxRows;
	}
	void FadeIn(grayImage& Two, int Seconds, int Frames, string CC) {
		grayImage G;
		double Stepsize = 1.0 / (Frames * Seconds);
		int R = Rows;
		if (R < Two.Rows)
			R = Two.Rows;
		int C = Cols;
		if (C < Two.Cols)
			C = Two.Cols;
		G.Rows = R;
		G.Cols = C;

		G.loaded = true;
		G.Maximum = Maximum;
		if (Maximum < Two.Maximum)
			G.Maximum = Two.Maximum;
		int Counter = 0;
		for (double Alpha = 1; Alpha >= 0; Alpha -= Stepsize) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					G.Image[i][j] = Image[i][j] * Alpha + (1 - Alpha) * Two.Image[i][j];
				}
			}
			char N[10];
			itoa(Counter, N, 10);
			G.Save(CC + N + ".pgm");
			Counter++;
		}
	}
	void Nagative(grayImage) {
		for (int i = 0; i < Rows; i++)
			for (int j = 0; j < Cols; j++)
			{
				Image[i][j] = Maximum - Image[i][j];
			}
	}
	void Flip(int HorizontalOrVertical) {

		if (HorizontalOrVertical == 0)
			FilpHorizontal();
		else
		{
			FlipVerttical();
		}
	}
	void changeBrightness(int amount) {
		for (int i = 0; i < Rows; i++)
			for (int j = 0; j < Cols; j++)
			{
				if (amount + Image[i][j] < Maximum)
				{
					Image[i][j] = amount + Image[i][j];
				}
				else
				{
					Image[i][j] = Maximum;
				}
			}
	}
	void insertionSort(int A[], int n) {
		int i, x, j;
		for (i = 1; i < n; i++)
		{
			x = A[i];
			j = i - 1;
			while (j >= 0 && A[j] > x)
			{
				A[j + 1] = A[j];
				j = j - 1;
			}
			A[j + 1] = x;
		}
	}
	void medianFilter(grayImage, int filterSize = 3) {
		int Slwid[filterSize * filterSize];
		int x = filterSize * filterSize;
		for (int i = 1; i <= Rows; ++i) {
			for (int j = 1; j <= Cols; ++j)
			{
				Slwid[0] = Image[i - 1][j - 1];
				Slwid[1] = Image[i - 1][j];
				Slwid[2] = Image[i - 1][j + 1];
				Slwid[3] = Image[i][j - 1];
				Slwid[4] = Image[i][j];
				Slwid[5] = Image[i][j + 1];
				Slwid[6] = Image[i + 1][j - 1];
				Slwid[7] = Image[i + 1][j];
				Slwid[8] = Image[i + 1][j + 1];
				insertionSort(Slwid, x);
				Image[i][j] = Slwid[4];
			}
		}
	}
	void meanFilter(grayImage, int filterSize = 3) {
		int sum = 0;
		for (int i = 0; i < Cols; i++) {
			for (int j = 0; j < Rows; j++)
			{
				Image[i][j] = Image[i][j];
			}
		}
		for (int i = 1; i < (Cols - 1); i++) {
			for (int j = 1; j < (Rows - 1); j++)
			{
				for (int k = (i - 1); k <= (i + 1); k++) {
					for (int l = (j - 1); l < (j + 1); l++)
					{
						sum = sum + Image[k][l];
					}
				}
				Image[i][j] = sum / (filterSize * filterSize);
				sum = 0;
			}
		}
	}
	int Saver(string File_Name) {
		ofstream FOUT(File_Name.c_str());

		FOUT << "P2\n"
			<< "# The Optional Comment by Baig\n"
			<< Rows << " " << Cols << endl << Maximum << endl;

		for (int r = 0; r < Rows; r++) {
			for (int c = 0; c < Cols; c++)
				FOUT << (int)Image[r][c] << " ";
			FOUT << endl;
		}
		FOUT.close();
	}
	int loader(string File_Name) {

		char MagicNum[10];
		char Comment[200];

		ifstream IN;

		IN.open(File_Name.c_str());
		if (!IN.is_open())
		{
			cout << endl;
			cout << "---------------------------------------------------------------------" << endl;
			cout << "File not open- Kindly load Image with proper Name and extensiom !" << endl;
			cout << "----------------------------------------------------------------------" << endl;

			return 1;
		}
		else {

			cout << "*---------------------------------|" << endl;
			cout << "Image is Successfully Loaded " << endl;
			cout << "*---------------------------------|" << endl;
			return 1;
		}
		(File_Name.c_str());

		IN.getline(MagicNum, 10);
		IN.getline(Comment, 200);

		cout << MagicNum << endl;
		cout << Comment << endl;

		int cols, rows, MaxValue;

		IN >> cols >> rows >> MaxValue;

		cout << rows << "  " << cols << endl << MaxValue;

		setRows(rows);
		setCols(cols);
		Maximum = MaxValue;

		for (int r = 0; r < Rows; r++)
			for (int c = 0; c < Cols; c++) {
				unsigned int val;
				IN >> val;
				Image[r][c] = val;
			}
		IN.close();
	}
	void Rotate(grayImage& Res, double angle, int aboutx, int abouty)
	{
		int in = 0, jn = 0;
		angle = (3.141592 * angle) / 180.0;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				in = ((i - aboutx) * cos(angle) + (j - abouty) * sin(angle) + aboutx);
				jn = ((j - abouty) * sin(angle) - (i - aboutx) * cos(angle) + abouty);
				if (0 < in && in < Rows && jn < 0 && jn < Cols);
				{
					Res.Image[in][jn] = Image[i][j];
				}
			}
		}
		Res.Rows = Rows;
		Res.Cols = Cols;
		Res.Maximum = Maximum;
	}
	void Transform(grayImage& Two, double Matrix[3][3]) {

		for (int i = 0; i < Rows; i++) {

			for (int j = 0; j < Cols; j++) {
				double I = (i * Matrix[0][0]) + (j * Matrix[0][1]) + (Matrix[0][2]);
				double J = (i * Matrix[1][0]) + (j * Matrix[1][1]) + (Matrix[1][2]);
				double z = (i * Matrix[2][0]) + (j * Matrix[2][1]) + (Matrix[2][2]);
				if (z != 0) {
					int NewI = I / z;
					int NewJ = J / z;
					if (NewI >= 0 && NewI < MaxRows && NewJ >= 0 && NewJ < MaxCols)
						Two.Image[NewI][NewJ] = Image[i][j];
				}
			}
		}
		Two.Rows = Rows;
		Two.Cols = Cols;
		Two.Maximum = Maximum;
	}
	void quantize(grayImage, int level)
	{

		vector<int> Max(level);

		vector<int> Min(level);

		int section = Maximum / level;

		Max[0] = section - 1;

		Min[0] = 0;

		for (int i = 1; i < level; i++) {
			if ((level % 2 != 0) && (i = level - 1))
			{
				Max[i] = Max[i - 1] + (Maximum - 1 - Max[i - 1]);

				Min[i] = Min[i - 1] + section;

			}
			else {

				Max[i] = Max[i - 1] + section;

				Min[i] = Min[i - 1] + section;
			}

		}
		for (int w = 0; w < Rows; w++)
		{
			for (int h = 0; h < Cols; h++)
			{
				for (int i = 0; i < level; i++)
				{
					if (Image[w][h] <= Max[i] && Image[w][h] >= Min[i])
					{
						Image[w][h] = Min[i];
					}

				}

			}

		}
		return;
	}
	void Resize(grayImage& Result, int NewRows, int NewColumns) {
		double col = NewColumns;
		col /= Cols;
		double rw = NewRows;
		rw /= Rows;

		int in = 0, jn = 0;

		for (int i = 0; i < NewRows; i++)
			for (int j = 0; j < NewColumns; j++) {
				int I, J;
				I = i / rw;
				J = j / col;
				Result.Image[i][j] = Image[I][J];
			}
		Result.Rows = NewRows;
		Result.Cols = NewColumns;
		Result.Maximum = Maximum;
	}
	void Resize(grayImage& resul, double rati) {
		resul.Resize(resul, rati, rati);
		resul.Rows = Rows;
		resul.Cols = Cols;
		resul.Maximum = Maximum;
	}

	void Filter(grayImage, double Mask[3][3])
	{

		for (int i = 0; i < Rows - 1; i++)
			for (int j = 0; j < Cols - 1; j++)
				for (int m = 0; m < 3; m++)
					for (int k = 0; k < 3; k++)
						Image[i][j] = Mask[m][k] * Image[m + i][k + j];

	}
	void Derivative(grayImage& Result, double Mask[3][3], double Mask1[3][3])
	{

		for (int i = 0, k = 0, m = 0, a = 0, z = 0; i < 3 && k < 3 && m < 3 && a < 3 && z < 3; i++, k++, m++, a++, z++)
			for (int j = 0, l = 0, n = 0, b = 0, x = 0; j < 3 && l < 3 && n < 3 && b < 3 && x < 3; j++, l++, n++, b++, x++) {
				Mask[m][n] = Mask[i][j] * Mask[i][j];
				Mask1[a][b] = Mask1[i][j] * Mask1[i][j];
				Mask[k][l] = Mask[m][n] + Mask1[a][b];
				Mask[z][x] = sqrt((Mask[k][l]));
			}
		for (int i = 0; i < Rows - 1; i++)
			for (int j = 0; j < Cols - 1; j++) {
				for (int m = 0; m < 3; m++)
					for (int k = 0; k < 3; k++)
						Result.Image[i][j] = Mask[m][k] * Image[m + i][k + j];
			}
		Result.Rows = Rows;
		Result.Cols = Cols;
		Result.Maximum = Maximum;
	}
	void Crop(grayImage& Two, int T, int L, int R, int B)
	{
		int NewRows = Rows - T - B;
		int NewCols = Cols - L - R;
		for (int i = L; i < NewRows; i++)
			for (int j = T; j < NewCols; j++) {
				Two.Image[i][j] = Image[i][j];
			}
		Two.Rows = Rows;
		Two.Cols = Cols;
		Two.Maximum = Maximum;

	}
private:
	unsigned short Image[MaxRows][MaxCols];
	int Rows, Cols, Maximum;
	bool loaded;
	void FilpHorizontal() {

		int tmp;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols / 2; j++)
			{
				tmp = Image[i][j];
				Image[i][j] = Image[i][Cols - 1 - j];
				Image[i][Cols - 1 - j] = tmp;
			}
		}
	}
	void FlipVerttical() {
		int tmp;
		for (int i = 0; i < Rows / 2; i++) {
			for (int j = 0; j < Cols; j++)
			{
				tmp = Image[i][j];
				Image[i][j] = Image[Rows - 1 - i][j];
				Image[Rows - 1 - i][j] = tmp;
			}
		}
	}
};
int main() {
	grayImage Image;
	grayImage GM;
	grayImage New;
	double Mask[3][3] = { {-1,0,1},{-1,0,1},{-1,0,1} };
	double Mask1[3][3] = { {-1,-1,-1},{0,0,0},{1,1,1} };
	double TMask[3][3] = { {1,2,3},{2,3,0},{0,0,1} };


	string Nam;
	string Nam1;
	cout << "*-----------------------------------------------------------------------------------------|" << endl;
	cout << "\t\t\t\tWELCOME TO IMAGE PROCESSING SOFTWARE V1.0 : " << endl;
	cout << "*-----------------------------------------------------------------------------------------|" << endl << endl << endl;
	cout << "Note:- For First Time Run Kindly Load the Image First Before using any function by Pressing 1 key" <<endl;
	while (1)
	{
		int n;
		cout <<endl<< "\t\t\t   Please Enter a Number to perform Specific Operation\n" << endl << endl;
		cout << "  1.  Load Image" << endl;
		cout << "  2.  Save Image" << endl;
		cout << "  3.  Combine Two Images Side by Side" << endl;
		cout << "  4.  Combine Two Images Top to Bottom" << endl;
		cout << "  5.  Negative of a Image" << endl;
		cout << "  6.  Change the brightness of the Image" << endl;
		cout << "  7.  Apply Median Filter" << endl;
		cout << "  8.  Fade In Image" << endl;
		cout << "  9.  Apply Mean Filter" << endl;
		cout << "  10. Rotate Image to certain Angle " << endl;
		cout << "  11. Apply a Filter Mask " << endl;
		cout << "  12. Resize of Image " << endl;
		cout << "  13. Derivative of an Image " << endl;
		cout << "  14. Quantize the Image " << endl;
		cout << "  15. Flip Image Vertically " << endl;
		cout << "  16. Flip Image Horizontally " << endl;
		cout << "  17. Transform The Image     " << endl;
		cout << "  18. Crop the Image " << endl;
		cout << "  19. Exit the program" << endl << endl;
		cin >> n;

		cout << endl << endl;
		switch (n)
		{
		case 1:
		{
			cout << "Please Enter Image Name with .pgm extension that you want to load " << endl << endl;
			cin >> Nam;
			GM.loader(Nam);
			break;
		}
		case 2:
		{
			GM.Save("SAVED.pgm");
			cout << "*---------------------------------|" << endl;
			cout << "Image is Successfully Saved " << endl;
			cout << "*---------------------------------|" << endl;
			break;
		}
		case 3:
		{

			GM.load(Nam);
			cout << "Please Enter 2nd Image Name with .pgm extension: " << endl;
			cin >> Nam1;
			New.load(Nam1);
			GM.combineSideBySide(New);
			GM.Save("CombinedImagesH.pgm");
			cout << "*----------------------------------------------|" << endl;
			cout << "Image is Successfully Combined Side by Side " << endl;
			cout << "*----------------------------------------------|" << endl;
			break;
		}
		case 4:
		{

			GM.load(Nam);
			cout << "Please Enter 2nd Image Name with .pgm extension: " << endl;
			cin >> Nam1;
			New.load(Nam1);
			GM.combineTopToBottom(New);
			GM.Save("CombinedImagesT.pgm");
			cout << "*----------------------------------------------|" << endl;
			cout << "Image is Successfully Combined Top to Bottom" << endl;
			cout << "*----------------------------------------------|" << endl;
			break;
		}
		case 5:
		{
			GM.load(Nam);
			GM.Nagative(GM);
			GM.Save("Negative.pgm");
			cout << "*--------------------------------------------|" << endl;
			cout << "Negative of Image is Successfully Created " << endl;
			cout << "*--------------------------------------------|" << endl;

			break;
		}
		case 6:
		{
			int x;
			GM.load(Nam);
			cout << "Enter brightness Value: " << endl;
			cin >> x;
			GM.changeBrightness(x);
			GM.Save("Brightness.pgm");
			cout << "*-------------------------------|" << endl;
			cout << "Image is Successfully Brightened " << endl;
			cout << "*-------------------------------|" << endl;

			break;
		}
		case 7:
		{
			GM.load(Nam);
			GM.medianFilter(GM);
			GM.Save("MedianFilter.pgm");
			cout << "*--------------------------------------|" << endl;
			cout << "Median Filter is Successfully Applied " << endl;
			cout << "*--------------------------------------|" << endl;
			break;

		}
		case 8:
		{
			string N;
			GM.load(Nam);
			cout << "Before load 2nd image please create a folder Named Fade where image would be stored \n\nPlease Enter 2nd Image Name with .pgm extension  " << endl;
			cin >> Nam1;
			New.load(Nam1);
			New.FadeIn(GM, 10, 24, "Fade\\"); //Please Make a folder Named "Fade" where programe is Saved and images  would store there.
			cout << "*-------------------------------|" << endl;
			cout << "Image is Successfully FadeIN " << endl;
			cout << "*-------------------------------|" << endl;

			break;
		}
		case 9:
		{


			GM.load(Nam);
			GM.meanFilter(GM);
			GM.Save("MeanFilter.pgm");
			cout << "*---------------------------------------|" << endl;
			cout << "Mean Filter is Successfully Applied " << endl;
			cout << "*---------------------------------------|" << endl;

			break;
		}
		case 10:
		{
			int angle, aboutx, abouty;
			GM.loader(Nam);
			cout << endl << endl;
			cout << "Please Enter Degree to Rotate : " << endl;
			cin >> angle;
			cout << "Please enter value to rotate about x axis" << endl;
			cin >> aboutx;
			cout << "Please enter value to rotate about y axis" << endl;
			cin >> abouty;

			GM.Rotate(New, angle, aboutx, abouty);
			New.Saver("Rotate.pgm");
			cout << "*-------------------------------|" << endl;
			cout << "Image is Successfully Rotated " << endl;
			cout << "*-------------------------------|" << endl;

			break;
		}
		case 11:
		{

			GM.load(Nam);
			GM.Filter(GM, Mask);
			GM.Save("Filter.pgm");
			cout << "*-------------------------------|" << endl;
			cout << "Filter is Successfully Applied " << endl;
			cout << "*-------------------------------|" << endl;

			break;

		}
		case 12:
		{
			int r, c;
			GM.loader(Nam);
			cout << "Please Enter New Rows" << endl;
			cin >> r;
			cout << "Please Enter New Columns" << endl;
			cin >> c;
			GM.Resize(New, r, c);
			GM.Saver("Resize.pgm");
			cout << endl;
			cout << "*-------------------------------|" << endl;
			cout << "Image is Successfully Resized " << endl;
			cout << "*-------------------------------|" << endl;

			break;
		}
		case 13:
		{
			GM.loader(Nam);
			GM.Derivative(New, Mask, Mask1);
			New.Saver("Darivated.pgm");
			cout << endl;
			cout << "*--------------------------------------------|" << endl;
			cout << "Derivation of Image is Successfully Created " << endl;
			cout << "*--------------------------------------------|" << endl;

			break;
		}
		case 14:
		{

			GM.loader(Nam);
			GM.quantize(GM, 10);
			GM.Saver("quantized.pgm");
			cout << endl;
			cout << "*-------------------------------|" << endl;
			cout << "Image is Successfully Quantized " << endl;
			cout << "*-------------------------------|" << endl;

			break;
		}

		case 15:
		{

			GM.loader(Nam);
			GM.Flip(1);
			GM.Saver("FlipV.pgm");
			cout << endl;
			cout << "*-----------------------------------------|" << endl;
			cout << "Image is Successfully Flipped Vertically " << endl;
			cout << "*-----------------------------------------|" << endl;

			break;
		}
		case 16:
		{

			GM.loader(Nam);
			GM.Flip(0);
			GM.Saver("FlipH.pgm");
			cout << endl;
			cout << "*--------------------------------------------|" << endl;
			cout << "Image is Successfully Flipped Horizontally " << endl;
			cout << "*--------------------------------------------|" << endl;

			break;
		}
		case 17:
		{

			GM.loader(Nam);
			GM.Transform(New, TMask);
			New.Saver("Transformed.pgm");
			cout << endl;
			cout << "*----------------------------------|" << endl;
			cout << "Image is Successfully Transformed " << endl;
			cout << "*----------------------------------|" << endl;

			break;
		}
		case 18:
		{
			int T, L, R, B;
			GM.loader(Nam);
			cout << endl;
			cout << "Please Enter TOP value to Crop: " << endl;
			cin >> T;
			cout << "Please Enter Left value to Crop: " << endl;
			cin >> L;
			cout << "Please Enter Right value to Crop: " << endl;
			cin >> R;
			cout << "Please Enter Bottom value to Crop: " << endl;
			cin >> B;
			GM.Crop(New, T, L, R, B);
			New.Saver("Cropped.pgm");
			cout << endl;
			cout << "*----------------------------------|" << endl;
			cout << "Image is Successfully Cropped " << endl;
			cout << "*----------------------------------|" << endl;
			break;
		}
		case 19:
		{
			cout << endl;
			cout << "Thank you for using this Software" << endl;
			return 0;
		}
		case 20:
		{
			GM.loader(Nam);
			GM.Resize(New, 5.4);
			New.Saver("DoubleRati.pgm");
			break;
		}


		}
	}

}

