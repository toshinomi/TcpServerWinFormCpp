#include "FormMain.h"

using namespace TcpServerWinFormCpp;

void FormMain::Init(void)
{
    m_thread = nullptr;
    m_tcpListener = nullptr;
    m_strIpAddress = "127.0.0.1";
    m_nPort = 9999;
    m_bEnd = false;

    textBoxIpAddress->Text = m_strIpAddress;
    textBoxPort->Text = m_nPort.ToString();
}

void FormMain::OnBtnClickStart(Object^ sender, EventArgs^ e)
{
    m_strIpAddress = textBoxIpAddress->Text->ToString();
    m_nPort = int::Parse(textBoxPort->Text->ToString());

    ThreadStart^ start = gcnew ThreadStart(this, &FormMain::DataListener);
    m_thread = gcnew Thread(start);
    m_thread->Start();
}

void FormMain::DataListener()
{
}

void FormMain::SetTextStatus(String^ _strText)
{
}

void FormMain::SetTextRcvData(String^ _strText)
{
}

void FormMain::OnBtnClickClear(Object^ sender, EventArgs^ e)
{
}

void FormMain::OnBtnClickStop(Object^ sender, EventArgs^ e)
{
}
