#pragma once

namespace TcpServerWinFormCpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Net;
	using namespace System::Net::Sockets;

	/// <summary>
	/// FormMain の概要
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		FormMain(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			Init();
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnClear;
	protected:
	private: System::Windows::Forms::TextBox^ textBoxRcvData;
	private: System::Windows::Forms::Label^ labelRcvData;
	private: System::Windows::Forms::TextBox^ textBoxStatus;
	private: System::Windows::Forms::Label^ labelStatus;
	private: System::Windows::Forms::Button^ btnStop;
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::TextBox^ textBoxPort;
	private: System::Windows::Forms::TextBox^ textBoxIpAddress;
	private: System::Windows::Forms::Label^ lblPort;
	private: System::Windows::Forms::Label^ lblIpAddress;

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->textBoxRcvData = (gcnew System::Windows::Forms::TextBox());
			this->labelRcvData = (gcnew System::Windows::Forms::Label());
			this->textBoxStatus = (gcnew System::Windows::Forms::TextBox());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->textBoxPort = (gcnew System::Windows::Forms::TextBox());
			this->textBoxIpAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblPort = (gcnew System::Windows::Forms::Label());
			this->lblIpAddress = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::White;
			this->btnClear->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnClear->ForeColor = System::Drawing::Color::Black;
			this->btnClear->Location = System::Drawing::Point(169, 196);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 21;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = false;
			// 
			// textBoxRcvData
			// 
			this->textBoxRcvData->Location = System::Drawing::Point(68, 222);
			this->textBoxRcvData->Multiline = true;
			this->textBoxRcvData->Name = L"textBoxRcvData";
			this->textBoxRcvData->ReadOnly = true;
			this->textBoxRcvData->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBoxRcvData->Size = System::Drawing::Size(619, 181);
			this->textBoxRcvData->TabIndex = 20;
			// 
			// labelRcvData
			// 
			this->labelRcvData->Location = System::Drawing::Point(38, 196);
			this->labelRcvData->Name = L"labelRcvData";
			this->labelRcvData->Size = System::Drawing::Size(104, 23);
			this->labelRcvData->TabIndex = 19;
			this->labelRcvData->Text = L"Recieve Data";
			this->labelRcvData->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// textBoxStatus
			// 
			this->textBoxStatus->Location = System::Drawing::Point(169, 148);
			this->textBoxStatus->Name = L"textBoxStatus";
			this->textBoxStatus->ReadOnly = true;
			this->textBoxStatus->Size = System::Drawing::Size(235, 19);
			this->textBoxStatus->TabIndex = 18;
			// 
			// labelStatus
			// 
			this->labelStatus->Location = System::Drawing::Point(38, 146);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(104, 23);
			this->labelStatus->TabIndex = 17;
			this->labelStatus->Text = L"Status";
			this->labelStatus->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// btnStop
			// 
			this->btnStop->BackColor = System::Drawing::Color::White;
			this->btnStop->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnStop->ForeColor = System::Drawing::Color::Black;
			this->btnStop->Location = System::Drawing::Point(261, 106);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(75, 23);
			this->btnStop->TabIndex = 16;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = false;
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::White;
			this->btnStart->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnStart->ForeColor = System::Drawing::Color::Black;
			this->btnStart->Location = System::Drawing::Point(169, 106);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 15;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = false;
			// 
			// textBoxPort
			// 
			this->textBoxPort->Location = System::Drawing::Point(169, 67);
			this->textBoxPort->Name = L"textBoxPort";
			this->textBoxPort->Size = System::Drawing::Size(235, 19);
			this->textBoxPort->TabIndex = 14;
			// 
			// textBoxIpAddress
			// 
			this->textBoxIpAddress->Location = System::Drawing::Point(169, 26);
			this->textBoxIpAddress->Name = L"textBoxIpAddress";
			this->textBoxIpAddress->Size = System::Drawing::Size(235, 19);
			this->textBoxIpAddress->TabIndex = 13;
			// 
			// lblPort
			// 
			this->lblPort->Location = System::Drawing::Point(38, 65);
			this->lblPort->Name = L"lblPort";
			this->lblPort->Size = System::Drawing::Size(104, 23);
			this->lblPort->TabIndex = 12;
			this->lblPort->Text = L"Port";
			this->lblPort->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblIpAddress
			// 
			this->lblIpAddress->Location = System::Drawing::Point(38, 24);
			this->lblIpAddress->Name = L"lblIpAddress";
			this->lblIpAddress->Size = System::Drawing::Size(104, 23);
			this->lblIpAddress->TabIndex = 11;
			this->lblIpAddress->Text = L"IP Address";
			this->lblIpAddress->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(725, 426);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->textBoxRcvData);
			this->Controls->Add(this->labelRcvData);
			this->Controls->Add(this->textBoxStatus);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->textBoxPort);
			this->Controls->Add(this->textBoxIpAddress);
			this->Controls->Add(this->lblPort);
			this->Controls->Add(this->lblIpAddress);
			this->Name = L"FormMain";
			this->Text = L"TCP Server";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Thread^			m_thread;
		TcpListener^		m_tcpListener;
		String^			m_strIpAddress;
		int				m_nPort;
		bool				m_bEnd;
	public:
		/// <summary>
		/// 初期化
		/// </summary>
		void Init(void);

		/// <summary>
		/// スタートボタンのクリックイベント
		/// </summary>
		/// <param name="sender">オブジェクト</param>
		/// <param name="e">イベントのデータ</param>
		void OnBtnClickStart(Object^ sender, EventArgs^ e);

		/// <summary>
		/// データリスナー
		/// </summary>
		void DataListener();

		/// <summary>
		/// ステータス表示のテキストボックス設定
		/// </summary>
		/// <param name="_strText">表示文字列</param>
		void SetTextStatus(String^ _strText);

		/// <summary>
		/// データ受信表示のテキストボックス設定
		/// </summary>
		/// <param name="_strText">表示文字列</param>
		void SetTextRcvData(String^ _strText);

		/// <summary>
		/// クリアボタンのクリックイベント
		/// </summary>
		/// <param name="sender">オブジェクト</param>
		/// <param name="e">イベントのデータ</param>
		void OnBtnClickClear(Object^ sender, EventArgs^ e);

		/// <summary>
		/// ストップボタンのクリックイベント
		/// </summary>
		/// <param name="sender">オブジェクト</param>
		/// <param name="e">イベントのデータ</param>
		void OnBtnClickStop(Object^ sender, EventArgs^ e);
	};
}
