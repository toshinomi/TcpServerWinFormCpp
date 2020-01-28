#include "FormMain.h"

using namespace TcpServerWinFormCpp;

/// <summary>
/// 初期化
/// </summary>
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

/// <summary>
/// スタートボタンのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnBtnClickStart(Object^ sender, EventArgs^ e)
{
    m_strIpAddress = textBoxIpAddress->Text->ToString();
    m_nPort = int::Parse(textBoxPort->Text->ToString());

    ThreadStart^ start = gcnew ThreadStart(this, &FormMain::DataListener);
    m_thread = gcnew Thread(start);
    m_thread->Start();

    return;
}

/// <summary>
/// データリスナー
/// </summary>
void FormMain::DataListener()
{
    try
    {
        m_tcpListener = gcnew TcpListener(IPAddress::Parse(m_strIpAddress), m_nPort);
        m_tcpListener->Start();
    }
    catch (Exception^)
    {

    }
}

/// <summary>
/// ステータス表示のテキストボックス設定
/// </summary>
/// <param name="_strText">表示文字列</param>
void FormMain::SetTextStatus(String^ _strText)
{
    textBoxStatus->Text = _strText->ToString();

    return;
}

/// <summary>
/// データ受信表示のテキストボックス設定
/// </summary>
/// <param name="_strText">表示文字列</param>
void FormMain::SetTextRcvData(String^ _strText)
{
    textBoxRcvData->Text = _strText->ToString() + "\n";

    return;
}

/// <summary>
/// クリアボタンのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnBtnClickClear(Object^ sender, EventArgs^ e)
{
    textBoxRcvData->Text = "";

    return;
}

/// <summary>
/// ストップボタンのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnBtnClickStop(Object^ sender, EventArgs^ e)
{
    m_bEnd = true;
    m_tcpListener->Stop();

    return;
}