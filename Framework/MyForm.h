#pragma once
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <msclr/marshal_cppstd.h>
#include <iostream>

namespace Framework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  open;
	private: System::Windows::Forms::PictureBox^  inputPic;
	private: System::Windows::Forms::PictureBox^  outputPic;
	private: System::Windows::Forms::Button^  histogram;

	private: System::Windows::Forms::Button^  grayHisto;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^  grayScale;

	private:
		Mat *src, *gray, *egalis, *leftPic, *rightPic, *blurPic, *sobelPic, *laplacianPic, *cannyPic, *medianPic, *gaussPic;
		bool test = false;
	private: System::Windows::Forms::Button^  saveAs;
	private: System::Windows::Forms::Button^  equalization;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox;
	private: System::Windows::Forms::RadioButton^  right;
	private: System::Windows::Forms::Button^  Clear;
	private: System::Windows::Forms::Button^  blur;
	private: System::Windows::Forms::Button^  medianB;
	private: System::Windows::Forms::Button^  gaussianB;


	private: System::Windows::Forms::Button^  sobel;
	private: System::Windows::Forms::Button^  canny;


	private: System::Windows::Forms::Button^  laplacian;

	private: System::Windows::Forms::RadioButton^  left;

			 
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->open = (gcnew System::Windows::Forms::Button());
			this->inputPic = (gcnew System::Windows::Forms::PictureBox());
			this->outputPic = (gcnew System::Windows::Forms::PictureBox());
			this->histogram = (gcnew System::Windows::Forms::Button());
			this->grayHisto = (gcnew System::Windows::Forms::Button());
			this->grayScale = (gcnew System::Windows::Forms::Button());
			this->saveAs = (gcnew System::Windows::Forms::Button());
			this->equalization = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->right = (gcnew System::Windows::Forms::RadioButton());
			this->left = (gcnew System::Windows::Forms::RadioButton());
			this->Clear = (gcnew System::Windows::Forms::Button());
			this->blur = (gcnew System::Windows::Forms::Button());
			this->medianB = (gcnew System::Windows::Forms::Button());
			this->gaussianB = (gcnew System::Windows::Forms::Button());
			this->sobel = (gcnew System::Windows::Forms::Button());
			this->canny = (gcnew System::Windows::Forms::Button());
			this->laplacian = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputPic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->outputPic))->BeginInit();
			this->groupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// open
			// 
			this->open->Location = System::Drawing::Point(149, 557);
			this->open->Name = L"open";
			this->open->Size = System::Drawing::Size(88, 31);
			this->open->TabIndex = 0;
			this->open->Text = L"Open Image";
			this->open->UseVisualStyleBackColor = true;
			this->open->Click += gcnew System::EventHandler(this, &MyForm::open_Click);
			// 
			// inputPic
			// 
			this->inputPic->Location = System::Drawing::Point(1, 0);
			this->inputPic->Name = L"inputPic";
			this->inputPic->Size = System::Drawing::Size(540, 553);
			this->inputPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->inputPic->TabIndex = 1;
			this->inputPic->TabStop = false;
			// 
			// outputPic
			// 
			this->outputPic->Location = System::Drawing::Point(684, -2);
			this->outputPic->Name = L"outputPic";
			this->outputPic->Size = System::Drawing::Size(534, 553);
			this->outputPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->outputPic->TabIndex = 2;
			this->outputPic->TabStop = false;
			// 
			// histogram
			// 
			this->histogram->Location = System::Drawing::Point(291, 559);
			this->histogram->Name = L"histogram";
			this->histogram->Size = System::Drawing::Size(89, 29);
			this->histogram->TabIndex = 3;
			this->histogram->Text = L"histogram";
			this->histogram->UseVisualStyleBackColor = true;
			this->histogram->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// grayHisto
			// 
			this->grayHisto->Location = System::Drawing::Point(893, 557);
			this->grayHisto->Name = L"grayHisto";
			this->grayHisto->Size = System::Drawing::Size(86, 31);
			this->grayHisto->TabIndex = 4;
			this->grayHisto->Text = L"histogram";
			this->grayHisto->UseVisualStyleBackColor = true;
			this->grayHisto->Click += gcnew System::EventHandler(this, &MyForm::grayHisto_Click);
			// 
			// grayScale
			// 
			this->grayScale->Location = System::Drawing::Point(563, 96);
			this->grayScale->Name = L"grayScale";
			this->grayScale->Size = System::Drawing::Size(101, 30);
			this->grayScale->TabIndex = 5;
			this->grayScale->Text = L"gray scale";
			this->grayScale->UseVisualStyleBackColor = true;
			this->grayScale->Click += gcnew System::EventHandler(this, &MyForm::grayScale_Click);
			// 
			// saveAs
			// 
			this->saveAs->Location = System::Drawing::Point(1030, 557);
			this->saveAs->Name = L"saveAs";
			this->saveAs->Size = System::Drawing::Size(83, 31);
			this->saveAs->TabIndex = 6;
			this->saveAs->Text = L"save as";
			this->saveAs->UseVisualStyleBackColor = true;
			this->saveAs->Click += gcnew System::EventHandler(this, &MyForm::saveAs_Click);
			// 
			// equalization
			// 
			this->equalization->Location = System::Drawing::Point(563, 147);
			this->equalization->Name = L"equalization";
			this->equalization->Size = System::Drawing::Size(101, 29);
			this->equalization->TabIndex = 7;
			this->equalization->Text = L"Equalization";
			this->equalization->UseVisualStyleBackColor = true;
			this->equalization->Click += gcnew System::EventHandler(this, &MyForm::equalization_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(563, 51);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 29);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Original Image";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// groupBox
			// 
			this->groupBox->Controls->Add(this->right);
			this->groupBox->Controls->Add(this->left);
			this->groupBox->Location = System::Drawing::Point(563, 12);
			this->groupBox->Name = L"groupBox";
			this->groupBox->Size = System::Drawing::Size(101, 33);
			this->groupBox->TabIndex = 9;
			this->groupBox->TabStop = false;
			// 
			// right
			// 
			this->right->AutoSize = true;
			this->right->Checked = true;
			this->right->Location = System::Drawing::Point(51, 10);
			this->right->Name = L"right";
			this->right->Size = System::Drawing::Size(50, 17);
			this->right->TabIndex = 1;
			this->right->TabStop = true;
			this->right->Text = L"Right";
			this->right->UseVisualStyleBackColor = true;
			// 
			// left
			// 
			this->left->AutoSize = true;
			this->left->Location = System::Drawing::Point(6, 10);
			this->left->Name = L"left";
			this->left->Size = System::Drawing::Size(43, 17);
			this->left->TabIndex = 0;
			this->left->Text = L"Left";
			this->left->UseVisualStyleBackColor = true;
			// 
			// Clear
			// 
			this->Clear->Location = System::Drawing::Point(563, 523);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(101, 28);
			this->Clear->TabIndex = 10;
			this->Clear->Text = L"Clear";
			this->Clear->UseVisualStyleBackColor = true;
			this->Clear->Click += gcnew System::EventHandler(this, &MyForm::Clear_Click);
			// 
			// blur
			// 
			this->blur->Location = System::Drawing::Point(563, 197);
			this->blur->Name = L"blur";
			this->blur->Size = System::Drawing::Size(101, 29);
			this->blur->TabIndex = 11;
			this->blur->Text = L"Blur";
			this->blur->UseVisualStyleBackColor = true;
			this->blur->Click += gcnew System::EventHandler(this, &MyForm::blur_Click);
			// 
			// medianB
			// 
			this->medianB->Location = System::Drawing::Point(563, 249);
			this->medianB->Name = L"medianB";
			this->medianB->Size = System::Drawing::Size(101, 29);
			this->medianB->TabIndex = 12;
			this->medianB->Text = L"Median Blur";
			this->medianB->UseVisualStyleBackColor = true;
			this->medianB->Click += gcnew System::EventHandler(this, &MyForm::medianB_Click);
			// 
			// gaussianB
			// 
			this->gaussianB->Location = System::Drawing::Point(563, 301);
			this->gaussianB->Name = L"gaussianB";
			this->gaussianB->Size = System::Drawing::Size(101, 29);
			this->gaussianB->TabIndex = 13;
			this->gaussianB->Text = L"Gaussian Blur";
			this->gaussianB->UseVisualStyleBackColor = true;
			this->gaussianB->Click += gcnew System::EventHandler(this, &MyForm::gaussianB_Click);
			// 
			// sobel
			// 
			this->sobel->Location = System::Drawing::Point(563, 351);
			this->sobel->Name = L"sobel";
			this->sobel->Size = System::Drawing::Size(101, 29);
			this->sobel->TabIndex = 14;
			this->sobel->Text = L"Sobel";
			this->sobel->UseVisualStyleBackColor = true;
			this->sobel->Click += gcnew System::EventHandler(this, &MyForm::sobel_Click);
			// 
			// canny
			// 
			this->canny->Location = System::Drawing::Point(563, 403);
			this->canny->Name = L"canny";
			this->canny->Size = System::Drawing::Size(101, 43);
			this->canny->TabIndex = 15;
			this->canny->Text = L"Canny Edge Detector";
			this->canny->UseVisualStyleBackColor = true;
			this->canny->Click += gcnew System::EventHandler(this, &MyForm::canny_Click);
			// 
			// laplacian
			// 
			this->laplacian->Location = System::Drawing::Point(563, 469);
			this->laplacian->Name = L"laplacian";
			this->laplacian->Size = System::Drawing::Size(101, 29);
			this->laplacian->TabIndex = 16;
			this->laplacian->Text = L"Laplacian";
			this->laplacian->UseVisualStyleBackColor = true;
			this->laplacian->Click += gcnew System::EventHandler(this, &MyForm::laplacian_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1213, 600);
			this->Controls->Add(this->laplacian);
			this->Controls->Add(this->canny);
			this->Controls->Add(this->sobel);
			this->Controls->Add(this->gaussianB);
			this->Controls->Add(this->medianB);
			this->Controls->Add(this->blur);
			this->Controls->Add(this->Clear);
			this->Controls->Add(this->groupBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->equalization);
			this->Controls->Add(this->saveAs);
			this->Controls->Add(this->grayScale);
			this->Controls->Add(this->grayHisto);
			this->Controls->Add(this->histogram);
			this->Controls->Add(this->outputPic);
			this->Controls->Add(this->inputPic);
			this->Controls->Add(this->open);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputPic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->outputPic))->EndInit();
			this->groupBox->ResumeLayout(false);
			this->groupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
			 // open image
	private: System::Void open_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "All Files| *.*";
		openFileDialog1->Title = "Select a Cursor File";
  
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			inputPic->Image = Image::FromFile(openFileDialog1->FileName);
			System::String^ xyz = openFileDialog1->FileName;
			std::string converted_xyz = msclr::interop::marshal_as< std::string >(xyz);
			
			src = new Mat(imread(converted_xyz));
			leftPic = new Mat((*src));
			
		}
	}
			 // left pic histogram
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		Mat bgr_planes[3];
		split((*leftPic), bgr_planes);
		int histSize = 256;
		float range[] = { 0, 256 };
		const float* histRange = { range };
		bool uniform = true; bool accumulate = false;
		Mat b_hist, g_hist, r_hist;
		calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
		calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
		calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
		// Draw the histograms for B, G and R
		int hist_w = 512; int hist_h = 400;
		int bin_w = cvRound((double)hist_w / histSize);
		Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
		normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		for (int i = 1; i < histSize; i++)
		{
			line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
				cv::Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
				Scalar(255, 0, 0), 2, 8, 0);
			line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
				cv::Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
				Scalar(0, 255, 0), 2, 8, 0);
			line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
				cv::Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
				Scalar(0, 0, 255), 2, 8, 0);
		}
		namedWindow("Left Histogram", WINDOW_AUTOSIZE);
		imshow("Left Histogram", histImage);
	}
			 // gray scale image
	private: System::Void grayScale_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ graphics;
		Mat temp;
		cv::cvtColor((*src), temp, COLOR_BGR2GRAY);
		gray = new Mat(temp);
		showGray(gray,1);
	}
			 // right image histogram
	private: System::Void grayHisto_Click(System::Object^  sender, System::EventArgs^  e) {
		Mat bgr_planes[3];
		split((*rightPic), bgr_planes);
		int histSize = 256;
		float range[] = { 0, 256 };
		const float* histRange = { range };
		bool uniform = true; bool accumulate = false;
		Mat b_hist, g_hist, r_hist;
		calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
		calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
		calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
		// Draw the histograms for B, G and R
		int hist_w = 512; int hist_h = 400;
		int bin_w = cvRound((double)hist_w / histSize);
		Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
		normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		for (int i = 1; i < histSize; i++)
		{
			line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
				cv::Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
				Scalar(255, 0, 0), 2, 8, 0);
			line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
				cv::Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
				Scalar(0, 255, 0), 2, 8, 0);
			line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
				cv::Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
				Scalar(0, 0, 255), 2, 8, 0);
		}
		namedWindow("Right Histogram", WINDOW_AUTOSIZE);
		imshow("Right Histogram", histImage);
	}
			 // save gray scale image as 
	private: System::Void saveAs_Click(System::Object^  sender, System::EventArgs^  e) {
		 
		SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter =
			"Bitmap Image|*.bmp|Png Image|*.png";
		saveFileDialog1->Title = "Save an Image File";
		saveFileDialog1->ShowDialog();
		// If the file name is not an empty string, open it for saving.  
		if (saveFileDialog1->FileName != "")
		{
			vector<int> compression_params;
			System::String^ xyz = saveFileDialog1->FileName;
			std::string converted_xyz = msclr::interop::marshal_as< std::string >(xyz);
 
			switch (saveFileDialog1->FilterIndex)
			{
			case 1:
				imwrite(converted_xyz , (*rightPic));
				break;
			case 2:
				compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
				compression_params.push_back(9);
				imwrite(converted_xyz, (*rightPic), compression_params);
				break;
			}
		}
	}

private: System::Void equalization_Click(System::Object^  sender, System::EventArgs^  e) {

	Graphics^ graphics;
	Mat temp;
	cv::cvtColor((*src), temp, COLOR_BGR2GRAY);
	gray = new Mat(temp);
	Mat grayImage24;
	equalizeHist((*gray), temp);
	egalis = new Mat(temp);
	showGray(egalis, 1);
}

		 // clear
private: System::Void Clear_Click(System::Object^  sender, System::EventArgs^  e) {
	if (right->Checked)
	{
		System::Drawing::Image^ img = outputPic->Image;
		outputPic->Image = nullptr;
		delete img;
	}
	else
	{
		System::Drawing::Image^ img = inputPic->Image;
		inputPic->Image = nullptr;
		delete img;
	}
}
		 // original pic
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		showGray(src, 2);
}
		 // blur
private: System::Void blur_Click(System::Object^  sender, System::EventArgs^  e) {
	
		Mat temp;
		cv::blur((*src), temp, cv::Size(3, 3));
		blurPic = new Mat(temp);
		showGray(blurPic, 2);

}
		
		 // sobel
private: System::Void sobel_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat  src_gray,gaussB;
	Mat grad;
	Graphics^ graphics;
	const char* window_name = "Sobel Demo - Simple Edge Detector";
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	GaussianBlur((*src), gaussB, cv::Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(gaussB, src_gray, COLOR_BGR2GRAY);
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	//Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
	Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	//Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
	Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	convertScaleAbs(grad_y, abs_grad_y);
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
	sobelPic = new Mat(grad);
	showGray(sobelPic,1);
}

private: System::Void laplacian_Click(System::Object^  sender, System::EventArgs^  e) {
	Graphics^ graphics;
	Mat src_gray, dst,laplc;
	int kernel_size = 3;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	GaussianBlur((*src), laplc, cv::Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(laplc, src_gray, COLOR_BGR2GRAY); // Convert the image to grayscale
	Mat abs_dst;
	Laplacian(src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);
	laplacianPic = new Mat(abs_dst);
	showGray(laplacianPic,1);
}

		 private:
			 void showGray(Mat *pic,int a)
			 {
				 Graphics^ graphics;
				 Mat grayImage24;
				 if (a == 1)
				 {
					 cv::cvtColor((*pic), grayImage24, CV_GRAY2BGR);
				 }
				 else if(a==2)
				 {
					 pic->copyTo(grayImage24);
				 }

				 if (right->Checked)
				 {
					 graphics = outputPic->CreateGraphics();
					 rightPic = new Mat((*pic));
				 }
				 else
				 {
					 graphics = inputPic->CreateGraphics();
					 leftPic = new Mat((*pic));
				 }

				 IntPtr ptr(grayImage24.ptr());
				 Bitmap^ b = gcnew Bitmap(grayImage24.cols, grayImage24.rows, grayImage24.step,
					 System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
				 RectangleF rect(0, 0, 530, 550);
				 graphics->DrawImage(b, rect);
			 }

private: System::Void canny_Click(System::Object^  sender, System::EventArgs^  e) {

	Mat src_gray;
	Mat dst, detected_edges;
	int edgeThresh = 1;
	int lowThreshold;
	int const max_lowThreshold = 100;
	int ratio = 3;
	int kernel_size = 3;
	Graphics^ graphics;
	
		dst.create(src->size(), src->type());
		cvtColor((*src), src_gray, COLOR_BGR2GRAY);
		cv::blur(src_gray, detected_edges, cv::Size(3, 3));
		Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);
		dst = Scalar::all(0);
		src->copyTo(dst, detected_edges);
		cannyPic = new Mat(dst);
				if(right->Checked)
				{
					graphics = outputPic->CreateGraphics();
					rightPic = new Mat((*cannyPic));
				}
				 else
				 {
					 graphics = inputPic->CreateGraphics();
					 leftPic = new Mat((*cannyPic));
				 }

				 IntPtr ptr(cannyPic->ptr());
				 Bitmap^ b = gcnew Bitmap(cannyPic->cols, cannyPic->rows, cannyPic->step,
					 System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
				 RectangleF rect(0, 0, 530, 550);
				 graphics->DrawImage(b, rect);

}
private: System::Void medianB_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat temp;
	medianBlur((*src), temp, 31);
	medianPic = new Mat(temp);
	showGray(medianPic, 2);
}
private: System::Void gaussianB_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat temp;
	GaussianBlur((*src), temp, cv::Size(3, 3), 0, 0, BORDER_DEFAULT);
	gaussPic = new Mat(temp);
	showGray(gaussPic, 2);
}
};
}
