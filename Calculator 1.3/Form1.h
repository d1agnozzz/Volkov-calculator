#pragma once
#include <math.h>
namespace Calculator13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	bool awaiting = 0;   // Индикатор ожидания ввода
	bool opCounter = 0;  // Счетчик операций 
	bool zeroErr = 0;
	int opCase = -1;     // Текущая операция
	double num1;          // Первое число
	double num2;          // Второе число
	bool was_equal = 0;  // Если вычисление было произведено, то ввод начинается сначала
	int comma = -1;      // Обозначает, что запятая была введена, нужно для коректной обработки ввода если запятая ставится после ввода операции

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnNeg;
	private: System::Windows::Forms::Button^  btn0;
	private: System::Windows::Forms::Button^  btnComma;
	private: System::Windows::Forms::Button^  btnEquals;
	private: System::Windows::Forms::Button^  btn1;

	protected: 

	protected: 




	private: System::Windows::Forms::Button^  btn2;

	private: System::Windows::Forms::Button^  btn3;

	private: System::Windows::Forms::Button^  btnPlus;
	private: System::Windows::Forms::Button^  btn4;
	private: System::Windows::Forms::Button^  btn5;
	private: System::Windows::Forms::Button^  btn7;




	private: System::Windows::Forms::Button^  btn6;
	private: System::Windows::Forms::Button^  btn8;
	private: System::Windows::Forms::Button^  btn9;
	private: System::Windows::Forms::Button^  btnMinus;
	private: System::Windows::Forms::Button^  btnMultiply;
	private: System::Windows::Forms::Button^  btnInv;






	private: System::Windows::Forms::Button^  btnSquare;

	private: System::Windows::Forms::Button^  btnSqrt;

	private: System::Windows::Forms::Button^  btnDivide;
	private: System::Windows::Forms::Button^  btnPerc;


	private: System::Windows::Forms::Button^  btnCE;

	private: System::Windows::Forms::Button^  btnC;

	private: System::Windows::Forms::Button^  btnBckSpc;
	private: System::Windows::Forms::Label^  lblBox;


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
			this->btnNeg = (gcnew System::Windows::Forms::Button());
			this->btn0 = (gcnew System::Windows::Forms::Button());
			this->btnComma = (gcnew System::Windows::Forms::Button());
			this->btnEquals = (gcnew System::Windows::Forms::Button());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btnPlus = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btnMinus = (gcnew System::Windows::Forms::Button());
			this->btnMultiply = (gcnew System::Windows::Forms::Button());
			this->btnInv = (gcnew System::Windows::Forms::Button());
			this->btnSquare = (gcnew System::Windows::Forms::Button());
			this->btnSqrt = (gcnew System::Windows::Forms::Button());
			this->btnDivide = (gcnew System::Windows::Forms::Button());
			this->btnPerc = (gcnew System::Windows::Forms::Button());
			this->btnCE = (gcnew System::Windows::Forms::Button());
			this->btnC = (gcnew System::Windows::Forms::Button());
			this->btnBckSpc = (gcnew System::Windows::Forms::Button());
			this->lblBox = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnNeg
			// 
			this->btnNeg->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnNeg->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnNeg->Location = System::Drawing::Point(0, 402);
			this->btnNeg->Name = L"btnNeg";
			this->btnNeg->Size = System::Drawing::Size(78, 50);
			this->btnNeg->TabIndex = 0;
			this->btnNeg->Text = L"+/-";
			this->btnNeg->UseVisualStyleBackColor = true;
			this->btnNeg->Click += gcnew System::EventHandler(this, &Form1::btnNeg_Click);
			// 
			// btn0
			// 
			this->btn0->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn0->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btn0->Location = System::Drawing::Point(77, 402);
			this->btn0->Name = L"btn0";
			this->btn0->Size = System::Drawing::Size(78, 50);
			this->btn0->TabIndex = 0;
			this->btn0->Text = L"0";
			this->btn0->UseVisualStyleBackColor = true;
			this->btn0->Click += gcnew System::EventHandler(this, &Form1::btn0_Click);
			// 
			// btnComma
			// 
			this->btnComma->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnComma->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnComma->Location = System::Drawing::Point(154, 402);
			this->btnComma->Name = L"btnComma";
			this->btnComma->Size = System::Drawing::Size(78, 50);
			this->btnComma->TabIndex = 0;
			this->btnComma->Text = L",";
			this->btnComma->UseVisualStyleBackColor = true;
			this->btnComma->Click += gcnew System::EventHandler(this, &Form1::btnComma_Click);
			// 
			// btnEquals
			// 
			this->btnEquals->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btnEquals->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnEquals->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnEquals->Location = System::Drawing::Point(231, 402);
			this->btnEquals->Name = L"btnEquals";
			this->btnEquals->Size = System::Drawing::Size(78, 50);
			this->btnEquals->TabIndex = 0;
			this->btnEquals->Text = L"=";
			this->btnEquals->UseVisualStyleBackColor = false;
			this->btnEquals->Click += gcnew System::EventHandler(this, &Form1::btnEquals_Click);
			// 
			// btn1
			// 
			this->btn1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btn1->Location = System::Drawing::Point(0, 353);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(78, 50);
			this->btn1->TabIndex = 0;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &Form1::btn1_Click);
			// 
			// btn2
			// 
			this->btn2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btn2->Location = System::Drawing::Point(77, 353);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(78, 50);
			this->btn2->TabIndex = 0;
			this->btn2->Text = L"2";
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &Form1::btn2_Click);
			// 
			// btn3
			// 
			this->btn3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btn3->Location = System::Drawing::Point(154, 353);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(78, 50);
			this->btn3->TabIndex = 0;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &Form1::btn3_Click);
			// 
			// btnPlus
			// 
			this->btnPlus->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btnPlus->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnPlus->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnPlus->Location = System::Drawing::Point(231, 353);
			this->btnPlus->Name = L"btnPlus";
			this->btnPlus->Size = System::Drawing::Size(78, 50);
			this->btnPlus->TabIndex = 0;
			this->btnPlus->Text = L"+";
			this->btnPlus->UseVisualStyleBackColor = false;
			this->btnPlus->Click += gcnew System::EventHandler(this, &Form1::btnPlus_Click);
			// 
			// btn4
			// 
			this->btn4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btn4->Location = System::Drawing::Point(0, 304);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(78, 50);
			this->btn4->TabIndex = 0;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &Form1::btn4_Click);
			// 
			// btn5
			// 
			this->btn5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btn5->Location = System::Drawing::Point(77, 304);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(78, 50);
			this->btn5->TabIndex = 0;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &Form1::btn5_Click);
			// 
			// btn7
			// 
			this->btn7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btn7->Location = System::Drawing::Point(0, 255);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(78, 50);
			this->btn7->TabIndex = 0;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &Form1::btn7_Click);
			// 
			// btn6
			// 
			this->btn6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btn6->Location = System::Drawing::Point(154, 304);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(78, 50);
			this->btn6->TabIndex = 0;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &Form1::btn6_Click);
			// 
			// btn8
			// 
			this->btn8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btn8->Location = System::Drawing::Point(77, 255);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(78, 50);
			this->btn8->TabIndex = 0;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &Form1::btn8_Click);
			// 
			// btn9
			// 
			this->btn9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn9->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btn9->Location = System::Drawing::Point(154, 255);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(78, 50);
			this->btn9->TabIndex = 0;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &Form1::btn9_Click);
			// 
			// btnMinus
			// 
			this->btnMinus->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btnMinus->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnMinus->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnMinus->Location = System::Drawing::Point(231, 304);
			this->btnMinus->Name = L"btnMinus";
			this->btnMinus->Size = System::Drawing::Size(78, 50);
			this->btnMinus->TabIndex = 0;
			this->btnMinus->Text = L"-";
			this->btnMinus->UseVisualStyleBackColor = false;
			this->btnMinus->Click += gcnew System::EventHandler(this, &Form1::btnMinus_Click);
			// 
			// btnMultiply
			// 
			this->btnMultiply->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btnMultiply->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnMultiply->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnMultiply->Location = System::Drawing::Point(231, 255);
			this->btnMultiply->Name = L"btnMultiply";
			this->btnMultiply->Size = System::Drawing::Size(78, 50);
			this->btnMultiply->TabIndex = 0;
			this->btnMultiply->Text = L"*";
			this->btnMultiply->UseVisualStyleBackColor = false;
			this->btnMultiply->Click += gcnew System::EventHandler(this, &Form1::btnMultiply_Click);
			// 
			// btnInv
			// 
			this->btnInv->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->btnInv->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnInv->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnInv->Location = System::Drawing::Point(0, 206);
			this->btnInv->Name = L"btnInv";
			this->btnInv->Size = System::Drawing::Size(78, 50);
			this->btnInv->TabIndex = 0;
			this->btnInv->Text = L"1/x";
			this->btnInv->UseVisualStyleBackColor = false;
			this->btnInv->Click += gcnew System::EventHandler(this, &Form1::btnInv_Click);
			// 
			// btnSquare
			// 
			this->btnSquare->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->btnSquare->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSquare->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnSquare->Location = System::Drawing::Point(77, 206);
			this->btnSquare->Name = L"btnSquare";
			this->btnSquare->Size = System::Drawing::Size(78, 50);
			this->btnSquare->TabIndex = 0;
			this->btnSquare->Text = L"x^2";
			this->btnSquare->UseVisualStyleBackColor = false;
			this->btnSquare->Click += gcnew System::EventHandler(this, &Form1::btnSquare_Click);
			// 
			// btnSqrt
			// 
			this->btnSqrt->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->btnSqrt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSqrt->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnSqrt->Location = System::Drawing::Point(154, 206);
			this->btnSqrt->Name = L"btnSqrt";
			this->btnSqrt->Size = System::Drawing::Size(78, 50);
			this->btnSqrt->TabIndex = 0;
			this->btnSqrt->Text = L"sqrt(x)";
			this->btnSqrt->UseVisualStyleBackColor = false;
			this->btnSqrt->Click += gcnew System::EventHandler(this, &Form1::btnSqrt_Click);
			// 
			// btnDivide
			// 
			this->btnDivide->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->btnDivide->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDivide->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnDivide->Location = System::Drawing::Point(231, 206);
			this->btnDivide->Name = L"btnDivide";
			this->btnDivide->Size = System::Drawing::Size(78, 50);
			this->btnDivide->TabIndex = 0;
			this->btnDivide->Text = L"/";
			this->btnDivide->UseVisualStyleBackColor = false;
			this->btnDivide->Click += gcnew System::EventHandler(this, &Form1::btnDivide_Click);
			// 
			// btnPerc
			// 
			this->btnPerc->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->btnPerc->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnPerc->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnPerc->Location = System::Drawing::Point(0, 157);
			this->btnPerc->Name = L"btnPerc";
			this->btnPerc->Size = System::Drawing::Size(78, 50);
			this->btnPerc->TabIndex = 0;
			this->btnPerc->Text = L"%";
			this->btnPerc->UseVisualStyleBackColor = false;
			this->btnPerc->Click += gcnew System::EventHandler(this, &Form1::btnPerc_Click);
			// 
			// btnCE
			// 
			this->btnCE->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->btnCE->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCE->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnCE->Location = System::Drawing::Point(77, 157);
			this->btnCE->Name = L"btnCE";
			this->btnCE->Size = System::Drawing::Size(78, 50);
			this->btnCE->TabIndex = 0;
			this->btnCE->Text = L"CE";
			this->btnCE->UseVisualStyleBackColor = false;
			this->btnCE->Click += gcnew System::EventHandler(this, &Form1::btnCE_Click);
			// 
			// btnC
			// 
			this->btnC->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->btnC->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnC->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnC->Location = System::Drawing::Point(154, 157);
			this->btnC->Name = L"btnC";
			this->btnC->Size = System::Drawing::Size(78, 50);
			this->btnC->TabIndex = 0;
			this->btnC->Text = L"C";
			this->btnC->UseVisualStyleBackColor = false;
			this->btnC->Click += gcnew System::EventHandler(this, &Form1::btnC_Click);
			// 
			// btnBckSpc
			// 
			this->btnBckSpc->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->btnBckSpc->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBckSpc->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnBckSpc->Location = System::Drawing::Point(231, 157);
			this->btnBckSpc->Name = L"btnBckSpc";
			this->btnBckSpc->Size = System::Drawing::Size(78, 50);
			this->btnBckSpc->TabIndex = 0;
			this->btnBckSpc->Text = L"<--";
			this->btnBckSpc->UseVisualStyleBackColor = false;
			this->btnBckSpc->Click += gcnew System::EventHandler(this, &Form1::btnBckSpc_Click);
			// 
			// lblBox
			// 
			this->lblBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lblBox->Location = System::Drawing::Point(0, 80);
			this->lblBox->Name = L"lblBox";
			this->lblBox->Size = System::Drawing::Size(309, 65);
			this->lblBox->TabIndex = 1;
			this->lblBox->Text = L"0";
			this->lblBox->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(309, 452);
			this->Controls->Add(this->lblBox);
			this->Controls->Add(this->btnBckSpc);
			this->Controls->Add(this->btnDivide);
			this->Controls->Add(this->btnMultiply);
			this->Controls->Add(this->btnPlus);
			this->Controls->Add(this->btnMinus);
			this->Controls->Add(this->btnC);
			this->Controls->Add(this->btnEquals);
			this->Controls->Add(this->btnCE);
			this->Controls->Add(this->btnSqrt);
			this->Controls->Add(this->btnSquare);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btnPerc);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btnInv);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->btnComma);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn0);
			this->Controls->Add(this->btnNeg);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Сложный калькулятор";
			this->ResumeLayout(false);

		}

#pragma endregion

int len() {
	return lblBox->Text->Length;
}

int ulen() {
	return unformat()->Length;
}


String ^unformat() {                            // Убрать пробелы из lblBox
	String ^x;
	x = lblBox->Text->Replace(" ", "");
	return x;
}

void formatText() {
	int len;
	lblBox->Text = unformat();   // Каждый раз убираем пробелы (для сохранения исходных индексов и работоспособности Insert() с циклом for) 
	//int len = lblBox->Text->Length;                  // Длина без пробелов

	if (lblBox->Text->IndexOf(",") == -1) {       //
		len = ulen();                             //
	}                                             // Для корректного форматирования строк с запятой
	else {                                        //
		len = lblBox->Text->IndexOf(",");         //
	}

	for (int x = 3; x < len;x+=3) {
		lblBox->Text = lblBox->Text->Insert(len-x, " "); // Вставляем пробел перед каждым 3м символом с конца
	}
	if (lblBox->Text->IndexOf("-") == 0) {
		lblBox->Text->Remove(1);
	}
	
}

void Clear() {                               // Очистить все
	lblBox->Text = "0";
	fontTune();
}

void ClearAll() {
	Clear();
	awaiting = 0;
	opCase = -1;
	opCounter = 0;
	num1 = 0;
	num2 = 0;
	zeroErr = 0;
	was_equal = 0;
}

void fontTune() {                               // Настройка шрифта под количество отображаемых символов
	/*int len = unformat()->Length;   */            // Длина без пробелов
	if (ulen() < 9) {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 36);
	}
	else if (ulen() == 17) {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 20);
	}
	else if (ulen() == 16) {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 21);
	}
	else if (ulen() == 15) {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 23);
	}
	else if (ulen() == 14) {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 24);
	}
	else if (ulen() == 13) {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 26);
	}

	else if (ulen() == 12) {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 27);
	}
	else if (ulen() == 11) {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 28);
	}
	else if (ulen() == 10) {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 30);
	}
	else if (ulen() == 9) {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 33);
	}
	else {
		lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 15);
	}
}


void opAction(int x) {    // Действия при нажатии кнопок операций
	was_equal = 0;
			 if (opCounter == 0) {
				 num1 = Convert::ToDouble(unformat());
				 awaiting = 1;
				 opCounter++;
			 }

			 else {
				 if (awaiting == 0) {
					 num2 = Convert::ToDouble(unformat());
					 calculate(opCase);
					 awaiting = 1;
				 }
			 }
			 opCase = x;
}


void calculate(int opCase) {                      // Ф-я вычисление
	if (zeroErr != 1) {
		if (awaiting == 0) { // Инициализирует num2 если кнопки операций были нажаты всего один раз 
			num2 = Convert::ToDouble(unformat());
		}

		switch (opCase) {
		case 1:
			num1 += num2;
			break;
		case 2:
			num1 -= num2;
			break;
		case 3:
			num1 *= num2;
			break;
		case 4:
			if (num2 == 0) {
				lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 30);
				this->lblBox->Text = "Ошибка! Деление на ноль";
				zeroErr = 1;
				goto zeroErr;
				break;
			}
			else {
				num1 /= num2;
			}
			break;
		default:
			break;
		}

		lblBox->Text = Convert::ToString(num1);
		formatText();
	zeroErr:	awaiting = 1;
				fontTune();
	}
}



void input(double x) {                              // Ввод с циферок
	if (zeroErr != 1) {                                // Деление на ноль парализует

		if (awaiting == 1) {                           // Если ожидался ввод, то нужно очистить предыдущее значение из lblBox
			Clear();
		}

		if (was_equal == 1) {
			ClearAll();
		}

		was_equal = 0;

		if (unformat()->Length < 13){                      // Запрещаем ввод больше 13 цифр
			if (x != -1) {
				if (lblBox->Text == "0") {
					lblBox->Text = Convert::ToString(x);       // Первичная инициализация (Замена нуля вводимым числом)
				}
				else {
					lblBox->Text += x;                         // Вторичная инициализация (Припиcывание вводимого числа к строке)

				}
			}
			else {
				lblBox->Text = "0,";
				comma = 0;
			}

			fontTune();                                    // Настройка размера шрифта
			formatText();                                  // Простановка пробелов каждые 3и разряда
		}

		awaiting = 0;
	}
}





private: System::Void btn0_Click(System::Object^  sender, System::EventArgs^  e) {
			 input(0);
		 }
private: System::Void btn1_Click(System::Object^  sender, System::EventArgs^  e) {
			 input(1);
		 }
private: System::Void btn2_Click(System::Object^  sender, System::EventArgs^  e) {
			 input(2);
		 }
private: System::Void btn3_Click(System::Object^  sender, System::EventArgs^  e) {
			 input(3);
		 }
private: System::Void btn4_Click(System::Object^  sender, System::EventArgs^  e) {
			 input(4);
		 }
private: System::Void btn5_Click(System::Object^  sender, System::EventArgs^  e) {
			 input(5);
		 }
private: System::Void btn6_Click(System::Object^  sender, System::EventArgs^  e) {
			 input(6);
		 }
private: System::Void btn7_Click(System::Object^  sender, System::EventArgs^  e) {
			 input(7);
		 }
private: System::Void btn8_Click(System::Object^  sender, System::EventArgs^  e) {
			 input(8);
		 }
private: System::Void btn9_Click(System::Object^  sender, System::EventArgs^  e) {
			 input(9);
		 }


private: System::Void btnPlus_Click(System::Object^  sender, System::EventArgs^  e) {
			 //was_equal = 0;
			 //if (opCounter == 0 && awaiting == 0) {
				// num1 = Convert::ToDouble(unformat());
				// awaiting = 1;
				// opCounter++;
			 //}

			 //else {
				// if (awaiting == 0) {
				//	 num2 = Convert::ToDouble(unformat());
				//	 calculate(opCase);
				//	 awaiting = 1;
				// }
			 //}
			 //opCase = 1;
			 opAction(1);
			 
		 }
private: System::Void btnMinus_Click(System::Object^  sender, System::EventArgs^  e) {
			 opAction(2);
		 }
private: System::Void btnMultiply_Click(System::Object^  sender, System::EventArgs^  e) {
			 opAction(3);
		 }
private: System::Void btnDivide_Click(System::Object^  sender, System::EventArgs^  e) {
			 opAction(4);
		 }
private: System::Void btnEquals_Click(System::Object^  sender, System::EventArgs^  e) {
			 calculate(opCase);
			 was_equal = 1;
		 }
private: System::Void btnBckSpc_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (zeroErr !=1) {
				lblBox->Text = lblBox->Text->Remove(len()-1, 1);
				formatText();
				fontTune();
			 }
		 }
private: System::Void btnC_Click(System::Object^  sender, System::EventArgs^  e) {
			 ClearAll();
			 
		 }
private: System::Void btnCE_Click(System::Object^  sender, System::EventArgs^  e) {
			 Clear();
		 }


private: System::Void btnComma_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (zeroErr != 1) {
			 if (lblBox->Text->IndexOf(",") == -1) {
				 lblBox->Text += ",";
			 }
			 
			 if (awaiting == 1) {
				 input(-1);
			 }
			 }
		 }
private: System::Void btnNeg_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (zeroErr != 1) {
			 double tmp;
			 tmp = -1 * Convert::ToDouble(unformat());
			 lblBox->Text = Convert::ToString(tmp);
			 formatText();
			 fontTune();
			 was_equal = 0;
			 }
		 }
private: System::Void btnInv_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (zeroErr != 1) {
			 if (Convert::ToDouble(unformat()) !=0) {
			 double tmp;
			 tmp = 1 / Convert::ToDouble(unformat());
			 lblBox->Text = Convert::ToString(tmp);
			 formatText();
			 }

			 else {
				 lblBox->Text = "Ошибка! Деление на ноль";
				 zeroErr = 1;
			 }
			 fontTune();
			 was_equal = 0;
			 }
		 }
private: System::Void btnSquare_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (zeroErr !=1) {
				 double tmp;
				 tmp = Convert::ToDouble(unformat());
				 tmp *= tmp;
				 lblBox->Text = Convert::ToString(tmp);
				 formatText();
				 fontTune();
				 was_equal = 0;
			 }
		 }
private: System::Void btnSqrt_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (zeroErr != 1) {
				 double tmp;
				 tmp = Convert::ToDouble(unformat());
				 if (tmp >= 0) {
					 tmp = sqrt(tmp);
				 }
				 else {
					 lblBox->Font = gcnew System::Drawing::Font(lblBox->Font->FontFamily, 25);
					 this->lblBox->Text = "Корень из отрицательного числа";
					 zeroErr = 1;
					 goto negSqrt;
				 }
				 lblBox->Text = Convert::ToString(tmp);
				 formatText();
				 was_equal = 0;
	negSqrt:			 fontTune();
				 awaiting = 1;
		 }
		 }
private: System::Void btnPerc_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (zeroErr != 1) {
			 if (opCase == 1 || opCase == 2) {
				 lblBox->Text = Convert::ToString(num1 * Convert::ToDouble(lblBox->Text) / 100);

			 }
			 if (opCase == 3 || opCase == 4) {
				 lblBox->Text = Convert::ToString(Convert::ToDouble(lblBox->Text) / 100);
			 }
			 }
 		 }
};
}

