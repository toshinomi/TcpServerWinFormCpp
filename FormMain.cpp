#include "FormMain.h"

using namespace TcpServerWinFormCpp;

/// <summary>
/// ������
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
/// �X�^�[�g�{�^���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
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
/// �f�[�^���X�i�[
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
/// �X�e�[�^�X�\���̃e�L�X�g�{�b�N�X�ݒ�
/// </summary>
/// <param name="_strText">�\��������</param>
void FormMain::SetTextStatus(String^ _strText)
{
    textBoxStatus->Text = _strText->ToString();

    return;
}

/// <summary>
/// �f�[�^��M�\���̃e�L�X�g�{�b�N�X�ݒ�
/// </summary>
/// <param name="_strText">�\��������</param>
void FormMain::SetTextRcvData(String^ _strText)
{
    textBoxRcvData->Text = _strText->ToString() + "\n";

    return;
}

/// <summary>
/// �N���A�{�^���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnBtnClickClear(Object^ sender, EventArgs^ e)
{
    textBoxRcvData->Text = "";

    return;
}

/// <summary>
/// �X�g�b�v�{�^���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnBtnClickStop(Object^ sender, EventArgs^ e)
{
    m_bEnd = true;
    m_tcpListener->Stop();

    return;
}