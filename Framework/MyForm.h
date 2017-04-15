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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputPic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->outputPic))->BeginInit();
			this->SuspendLayout();
			// 
			// open
			// 
			this->open->Location = System::Drawing::Point(141, 529);
			this->open->Name = L"open";
			this->open->Size = System::Drawing::Size(75, 23);
			this->open->TabIndex = 0;
			this->open->Text = L"Open Image";
			this->open->UseVisualStyleBackColor = true;
			this->open->Click += gcnew System::EventHandler(this, &MyForm::open_Click);
			// 
			// inputPic
			// 
			this->inputPic->Location = System::Drawing::Point(0, -2);
			this->inputPic->Name = L"inputPic";
			this->inputPic->Size = System::Drawing::Size(479, 525);
			this->inputPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->inputPic->TabIndex = 1;
			this->inputPic->TabStop = false;
			// 
			// outputPic
			// 
			this->outputPic->Location = System::Drawing::Point(568, -2);
			this->outputPic->Name = L"outputPic";
			this->outputPic->Size = System::Drawing::Size(488, 525);
			this->outputPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->outputPic->TabIndex = 2;
			this->outputPic->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(487, 87);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"histogram";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(487, 136);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1056, 564);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->outputPic);
			this->Controls->Add(this->inputPic);
			this->Controls->Add(this->open);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputPic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->outputPic))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void open_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "All Files| *.*";
		openFileDialog1->Title = "Select a Cursor File";
  
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			inputPic->Image = Image::FromFile(openFileDialog1->FileName);
			System::String^ xyz = openFileDialog1->FileName;
			std::string converted_xyz = msclr::interop::marshal_as< std::string >(xyz);
			Mat src = imread(converted_xyz);
			Mat dst;
			cvtColor(src, dst, COLOR_BGR2GRAY);
			outputPic->Image = Image::FromFile(openFileDialog1->FileName);
			/*Graphics^ graphics = outputPic->CreateGraphics();
			IntPtr ptr(src.ptr());
			Bitmap^ b = gcnew Bitmap(src.cols, src.rows, src.step,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			RectangleF rect(0, 0, 480, 520);
			graphics->DrawImage(b, rect);*/
			Mat bgr_planes[3];
			split(src, bgr_planes);
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
			namedWindow("calcHist Demo", WINDOW_AUTOSIZE);
			imshow("calcHist Demo", histImage);

			
		}
	}
	};
}
